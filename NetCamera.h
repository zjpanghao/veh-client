#ifndef INCLUDE_NETCAMERA_H
#define INCLUDE_NETCAMERA_H
#include <windows.h>
#include <windef.h>
#include <memory>
#include <mutex>
#include <string>
#include "Net_Interface.h"

namespace wheat {
class NetCamera  {
  public:
    NetCamera(const std::string &addr);
    bool init();
    ~NetCamera();
    std::shared_ptr<T_VehResult> getVehResult();
    int caId() {return caId_;}

	private:
    static int GetReportCBEx(DCHANDLE tHandle, unsigned char ucType, void *ptMessage,void *pUserData);
    static void  UserState(DCHANDLE tHandle,unsigned char connState, void* pUser);
    int caId_ {-1};
		const std::string addr_;
    std::shared_ptr<T_VehResult> vehResult_;
};

} // namespace wheat
#endif
