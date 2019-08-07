#ifndef INCLUDE_NET_LOG_H
#define INCLUDE_NET_LOG_H
#include <string>
#include <thread>
#include <mutex>
namespace wheat {
class NetLog {
 public:
   enum Status {
     CONNECT,
     DOWN
   };
   int sendMess(const std::string &mess);
   NetLog(const std::string &server, int port);
   int init();

 private:
   int connectServer();
   void heartBeatTask();
   const std::string server_;
   const int port_{0};
   int timeoutCnt_{0};
   volatile Status  status_{DOWN};
   int sock_{0};
   std::thread  *thd_;
   std::mutex lock_;
};

} // namespace wheat
#endif
