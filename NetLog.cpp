#include "NetLog.h"
#include <winsock2.h>
#include <iostream>
#include <sstream>
namespace wheat {
void NetLog::heartBeatTask() {
  while (true) {
    int rc = sendMess("aaaa");
    if (rc < 0) {
      timeoutCnt_++;
      std::cout << "send heart error:" << rc <<  "  cnt is:" << timeoutCnt_ <<"  " <<  std::endl;
      if (timeoutCnt_ > 3) {
        timeoutCnt_ = 0;
        std::cout << "connect to server:" << server_ << std::endl;
        connectServer();
      }
    } else {
      timeoutCnt_ = 0;
    }
    std::this_thread::sleep_for(std::chrono::seconds(10));
  }
}

NetLog::NetLog(const std::string &server, int port) : server_(server), port_(port){
  WSADATA wsaData;
  WSAStartup( MAKEWORD(2, 2), &wsaData);
  status_ = DOWN;
}

int NetLog::connectServer() {
  std::lock_guard<std::mutex> guard(lock_);
  status_ = DOWN;
  SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  sockaddr_in sockAddr;
  memset(&sockAddr, 0, sizeof(sockAddr));  //每个字节都用0填充
  sockAddr.sin_family = PF_INET;
  sockAddr.sin_addr.s_addr = inet_addr(server_.c_str());
  sockAddr.sin_port = htons(port_);
  int rc = connect(sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
  if (rc < 0) {
    std::cout << "connect failed:" << rc;
    return -1;
  }
  sock_ = sock;
  status_ = CONNECT;
  return 0;
}

int NetLog::init() {
  if (-1 == connectServer()) {
    return -1;
  }
  thd_ = new std::thread(&NetLog::heartBeatTask, this);
  return 0;
}

int NetLog::sendMess(const std::string &mess) {
  std::lock_guard<std::mutex> guard(lock_);
  if (status_ == DOWN) {
    return -1;
  }
  std::string head = "kunyan123";
  std::string end = "";
  std::stringstream ss;
  ss << mess.length();
  std::string len = ss.str();
  while(len.length() < 4) {
    len.insert(0, "0");
  }
  
  std::string full = head + len + mess + end;
  int rc = 0;
  do {
    rc = send(sock_, full.c_str(), full.length(), 0);
  } while (rc < 0 && WSAGetLastError() == WSAEWOULDBLOCK);
  return rc;
}

} // namespace wheat
