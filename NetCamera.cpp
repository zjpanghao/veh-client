#include "NetCamera.h"
#include <iostream>
namespace wheat {
int NetCamera::GetReportCBEx(DCHANDLE tHandle, unsigned char ucType, void *ptMessage,void *pUserData) {
  return 0;
}

void NetCamera::UserState(DCHANDLE tHandle,unsigned char connState, void* pUser) {
  std::cout << "state is :" << connState << std::endl;

}

NetCamera::NetCamera(const std::string &addr) : addr_(addr) {

}

NetCamera::~NetCamera() {
  std::cout << "release camera";
}

bool NetCamera::init() {
  if (caId_ != -1) {
    Net_DisConnCamera(caId_);
    Net_DelCamera(caId_);
  }
  char tmp[64];
  strncpy(tmp, addr_.c_str(), 64);
  int caId = Net_AddCamera(tmp);
  int rc = 0;
  bool flag = false;
  if (caId == -1) {
    return false;
  }
  do {
    if(DC_NO_ERROR != (rc =Net_SetControlCallBackEx(caId, UserState, this))) {
      if (rc != 0) {
        std::cout << "error register mess cb" << rc;
        break;
      }
    }
    rc = Net_RegReportMessEx(caId, GetReportCBEx, this);
    if (DC_NO_ERROR != (rc = Net_ConnCamera(caId, 30000, 5))) {
      std::cout << "error connect camera: rc:" << rc;
      break;
    }
    flag = true;
    caId_ = caId;
  } while(0);
  
  if (!flag) {
    Net_DisConnCamera(caId);
    Net_DelCamera(caId);
  }
  return flag;
}

std::shared_ptr<T_VehResult> NetCamera::getVehResult() {
  return vehResult_;
}


} // namespace wheat
