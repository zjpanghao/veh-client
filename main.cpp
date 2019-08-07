#include <windows.h>
#include <windef.h>
#include <stdio.h>
#include <memory>
#include <map>
#include <sstream>
#include <iostream>
#include <Net_Interface.h>
#include "NetCamera.h"
#include "NetLog.h"
#include <thread>

void findAllDevice(std::map<std::string, std::shared_ptr<wheat::NetCamera>> &cameras);

int main(int argc, const char *argv[]) {
	int rc = Net_Init();
	unsigned char szVersion[MAX_PATH] = {0};
	unsigned int nLen = MAX_PATH;
	Net_GetSdkVersion(szVersion, &nLen);
  if (argc != 3) {
    std::cout << "veh <ip> <port> " << std::endl;
    return -1;
  }
  //wheat::NetCamera camera("123456");
  //rc = camera.init();
  std::cout << "rc:" << rc;
  std::stringstream ss;
  ss << argv[2];
  int port;
  ss >> port;
  wheat::NetLog log(argv[1], port);
  if (log.init() < 0) {
    std::cout << "init log error" << std::endl;
  }
  std::map<std::string, std::shared_ptr<wheat::NetCamera>> cameras;
  findAllDevice(cameras);
  while (true) {
    ss.clear();
    ss.str("");
    ss << "辽A56789" <<"_" <<  time(NULL);
    log.sendMess(ss.str());
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
  }
  
	return 0;
}

void  net_find_device_ip_callback(const char *strFindDeviceIp, void *pUserData) {
  std::map<std::string, std::shared_ptr<wheat::NetCamera>> *cameras =
    (std::map<std::string, std::shared_ptr<wheat::NetCamera>> *)pUserData;
  std::cout << "find ip :" << strFindDeviceIp << std::endl;
  std::shared_ptr<wheat::NetCamera> camera = std::make_shared<wheat::NetCamera>(strFindDeviceIp);
  int rc = camera->init();
  if (rc == 0) {
    cameras->insert(std::make_pair(strFindDeviceIp, camera));
  }
}

void findAllDevice(std::map<std::string, std::shared_ptr<wheat::NetCamera>> &cameras) {
  Net_FindDeviceIp(net_find_device_ip_callback, &cameras);
}
