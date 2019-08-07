#ifndef __NETCLIENT_H__
#define __NETCLIENT_H__

#include "NetStructDef.h"

/**
*  @brief 全局初始化
*  @return 1表示成功，0表示失败
*  @note 在所有接口调用之前调用
*  @ingroup group_global
*/
SZ_LPRC_API int  __stdcall SzLPRClient_Setup();

/**
*  @brief  日志打开与关闭
*  @param  [IN] bOpen TRUE 打开，FALSE 关闭
*  @return 1表示成功，0表示失败
*  @note 开启日志记录功能
*  @ingroup group_global
*/
SZ_LPRC_API int  __stdcall SzLPRClient_OpenLog(bool bOpen);

/**
*  @brief 全局释放
*  @note 在程序结束时调用，释放SDK的资源
*  @ingroup group_global
*/
SZ_LPRC_API void __stdcall SzLPRClient_Cleanup();


/**
*  @brief  获取设备SDK的版本号
*  @param  [IN] Version 保存信息的地址
*  @param  [IN] nlen  Version保存信息的大小
*  @return 成功返回 1
*  @return 失败返回 0
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_ReadSDKVersion(char * Version, int nlen);

/**
*  @brief 打开一个设备
*  @param  [IN] pStrIP 设备的IP地址
*  @param  [IN] wPort 设备的端口号
*  @param  [IN] pStrUserName 访问设备所需用户名
*  @param  [IN] pStrPassword 访问设备所需密码
*  @return 返回设备的操作句柄，当打开失败时(-1 用户不存在,用户名不能为空;  -2 用户和密码不匹配,密码不能为空; -3 登陆者过多,超过3个，
*  @return 未登入,应该先进行登录 -4，授权有效期已过,只能进行基本操作 -5 ， 认证失败,用户ID错误-6， 认证失败,密码和用户ID不匹配-7)
*  @return 成功返回大于0
*  @ingroup group_device
*/
SZ_LPRC_API SzLPRClientHandle __stdcall SzLPRClient_OpenEx(const char *pStrIP, WORD wPort, const char *pStrUserName, const char *pStrPassword);


/**
*  @brief  关闭设备
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @return 1表示成功，0表示失败
*  @note   停止播放以后，该播放句柄就失效了
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_Stop(SzLPRClientHandle handle);


/**
*  @brief 播放实时视频
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] hWnd 窗口的句柄
*  @return 成功返回1，失败返回0
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_StartRealPlay(SzLPRClientHandle handle, HWND hWnd);


/**
*  @brief 播放实时视频
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] hWnd 窗口的句柄
*  @return 成功返回1，失败返回0
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetDisPlayWnd(SzLPRClientHandle handle, HWND hWnd);

/**
*  @brief  设置视频画面绘图的回调函数
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] pDrawFun 视频画面绘图回调函数
*  @lpDrawFunData  [IN] lpDrawFunData 用户自定义的参数，一般执行绘图的类对象
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetDrawFunCallBack(SzLPRClientHandle handle, DrawFunCallBack pDrawFun, void* lpDrawFunData);

/**
*  @brief  新的设置视频画面绘图的回调函数
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] pDrawFun 新的视频画面绘图回调函数
*  @lpDrawFunData  [IN] lpDrawFunData 用户自定义的参数，一般执行绘图的类对象
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetSDKDrawFunCallBack_NEW(SzLPRClientHandle handle, SDKDrawCallBack pDrawFun, void* lpDrawFunData);

/**
*  @brief 设置识别结果的回调函数
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] func 识别结果回调函数，如果为NULL，则表示关闭该回调函数的功能
*  @param  [IN] pUserData 回调函数中的上下文
*  @param  [IN] bEnableImage 指定识别结果的回调是否需要包含截图信息：1为需要，0为不需要
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetPlateInfoCallBack(SzLPRClientHandle handle, LprcInfoCallBack func, void *pUserData, int bEnableImage);

/**
*  @brief 设置连接状态的回调函数
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] func 设备消息回调函数
*  @param  [IN] pUserData 回调函数中的上下文
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetMsgCallBack(SzLPRClientHandle handle, MessageCallBack func, void *pUserData);

/**
*  @brief  获取当前的帧率
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @return  返回获取到的结果
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetRealFR(SzLPRClientHandle handle);


/**
*  @brief 开始查找设备
*  @param  [IN] func 找到的设备通过该回调函数返回
*  @param  [IN] pUserData 回调函数中的上下文
*  @return 成功大于0，返回查找设备的句柄 。 0表示失败
*  @ingroup group_global
*/
SZ_LPRC_API SzLPRClientHandle __stdcall SzLPRClient_StartFindDevice(FindDeviceCallback func, void *pUserData);

/**
*  @brief 停止查找设备
*  @param  [IN] handle SzLPRClient_StartFindDevice 返回的句柄
*  @return 成功大于0，返回查找设备的句柄， 0表示失败
*  @ingroup group_global
*/
SZ_LPRC_API int __stdcall SzLPRClient_StopFindDevice(SzLPRClientHandle handle);


/**
*  @brief 修改网络参数
*  @param  [IN] netCfg 修改的网络信息
*  @note 可以用来实现跨网段修改IP的功能  
*  @return 1表示成功，-1表示失败 ,2 设备IP跟网关不在同一网段失败
*  @ingroup group_global
*/
SZ_LPRC_API int __stdcall SzLPRClient_UpdateNetworkParam(SZ_LPRC_NETCFG *netCfg);

/**
*  @brief  用于设置获取图像的回调函数
*  @param  [IN] handle SzLPRClient_StartFindDevice 返回的句柄
*  @param  [IN] drawVLOOP  返回图像的回调函数
*  @return 1表示成功，0表示失败
*  @ingroup group_global
*/
SZ_LPRC_API void __stdcall SzLPRClient_DrawVLoopsCallback(SzLPRClientHandle handle, DrawVLoopsCallback drawVLOOP);


/**
*  @brief  用于设置获取bmp图像的回调函数
*  @param  [IN] handle SzLPRClient_StartFindDevice 返回的句柄
*  @param  [IN] drawVLOOP  返回图像的回调函数
*  @return 1表示成功，0表示失败
*  @ingroup group_global
*/
SZ_LPRC_API void __stdcall SzLPRClient_BMP(SzLPRClientHandle handle, GetBMPCallback bmp);

/**
*  @brief  用于设置是否显示识别框
*  @param  [IN] handle SzLPRClient_StartFindDevice 返回的句柄
*  @param  [IN] bShowStaticVLoop  FALSE 不显示，TRUE为显示
*  @return FALSE 设置失败，TRUE为设置成功
*  @ingroup group_global
*/
SZ_LPRC_API BOOL __stdcall SzLPRClient_ShowStaticVLoops(SzLPRClientHandle handle, BOOL bShowStaticVLoop);

/**
*  @brief 控制镜头电机动作,变倍变焦
*  @param  [IN] handle SzLPRClient_StartFindDevice 返回的句柄
*  @param  [IN] pLensAction 镜头执行动作结构体
*  @return 1表示成功，0表示失败
*  @ingroup group_global
*/
SZ_LPRC_API void __stdcall SzLPRClient_LensAction(SzLPRClientHandle handle, const TagNetLensAction* pLensAction);

/**
*  @brief 设置LED控制模式
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param [IN] pledCtrl 控制LED开关模式
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetLedLightControl(SzLPRClientHandle handle, const TagNetLedPara* pledCtrl);

/**
*  @brief 获取LED控制模式
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param [IN] pledCtrl 控制LED开关模式
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetLedLightControl(SzLPRClientHandle handle, TagNetLedPara* pledCtrl);

/**
*  @brief 设置风扇开与关
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param [IN] bool TRUE 为常开，否则为常并
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetFanSanControl(SzLPRClientHandle handle, bool value);

/**
*  @brief 获取风扇控制信息
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param [IN] FanSanCtrl 为风扇控制开关信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetFanSanControl(SzLPRClientHandle handle, TNetFanPara *FanSanCtrl);

/**
*  @brief 获取网络参数信息
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param [IN] netcfg 保存网络参数的指针 
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetNetConfig(SzLPRClientHandle handle, TNetWiredPara* netcfg);

/**
*  @brief 设置设备网络参数
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param [IN] netcfg 网络参数的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetNetConfig(SzLPRClientHandle handle, TNetWiredPara* netcfg);


/**
*  @brief 获取增益控制信息
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param [IN] ispExpParams 用于保存增益控制信息的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetExpGain(SzLPRClientHandle handle, TNetExpGain* ispExpParams);

/**
*  @brief 设置增益控制信息
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param [IN] ispExpParams 用于参数增益控制信息的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetExpGain(SzLPRClientHandle handle, const TNetExpGain* ispExpParams);

/**
*  @brief 获取图像基本参数
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param [IN] imgEnhanceParams 保存设置的图像基本参数的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetImgBase(SzLPRClientHandle handle, TNetImageBasePara* imgEnhanceParams);

/**
*  @brief 设置图像基本参数
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param [IN] imgEnhanceParams 用于保存设置的图像基本参数的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetImgBase(SzLPRClientHandle handle, const TNetImageBasePara* imgEnhanceParams);



/**
*  @brief 发送软件触发信号，强制处理当前时刻的数据并输出结果
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @return 1表示成功，0表示失败
*  @note   车牌识别结果通过回调函数的方式返回，如果当前视频画面中无车牌，则回调函数不会被调用
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_ForceTrigger(SzLPRClientHandle handle);

/**
*  @brief 获取视频OSD参数；
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param [IN] pParam 用于保存OSD参数的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetOsdParam(SzLPRClientHandle handle, TNetOSDPara* pParam);

/**
*  @brief 设置视频OSD参数；
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param [IN] pParam 设置OSD参数的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetOsdParam(SzLPRClientHandle handle, const TNetOSDPara* pParam);


/**
*  @brief 获取已设置的预设省份
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param [IN] pProvInfo 预设省份信息指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetSupportedProvinces(SzLPRClientHandle handle, TagNetLprDefProvince* pProvInfo);

/**
*  @brief 获取已设置的预设省份
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param [IN] pProvInfo 预设省份信息指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetSupportedProvinces_EX(SzLPRClientHandle handle, TNetLprDefProvinceEx* pProvInfo);

/**
*  @brief 设置已设置的预设省份
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param [IN] pProvInfo 设置省份信息的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetSupportedProvinces(SzLPRClientHandle handle, const TagNetLprDefProvince* pProvInfo);

/**
*  @brief 设置已设置的预设省份
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param [IN] pProvInfo 设置省份信息的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetSupportedProvinces_EX(SzLPRClientHandle handle, const TNetLprDefProvinceEx* pProvInfo);

/**
*  @brief 获取设备端车牌识别类型参数
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param [IN] pProvInfo 设置保存类型的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetSupportedLprcPlateType(SzLPRClientHandle handle, TNetLprcPlateType *pLprcPlateType);

/**
*  @brief 设置设备端车牌识别类型参数
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param [IN] pProvInfo 识别类型的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetSupportedLprcPlateType(SzLPRClientHandle handle, const TNetLprcPlateType *pLprcPlateType);

/**
*  @brief 新的设置设备端车牌识别类型参数
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param [IN] Info 新的识别类型的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetSupportedLprcPlateType_New(SzLPRClientHandle handle, TNetLprcPlateTypeNew *Info);

/**
*  @brief 新的获取设备端车牌识别类型参数
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param [IN] Info 新的识别类型的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetSupportedLprcPlateType_New(SzLPRClientHandle handle, TNetLprcPlateTypeNew *Info);

/**
*  @brief 设置车牌识别与虚拟线圈的触发规则
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param [IN] pVirtualLoop 保存触发规则的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetTriggerLoopEx(SzLPRClientHandle handle, const TagNetLprcTriggerPara* pVirtualLoop);

/**
*  @brief 获取车牌识别与虚拟线圈的触发规则
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param [IN] pVirtualLoop 保存触发规则的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetTriggerLoopEx(SzLPRClientHandle handle, TagNetLprcTriggerPara* pVirtualLoop);

/**
*  @brief 设置车牌识别最大与最小车牌尺寸
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param [IN] pMaxPlateSize 车牌识别最大与最小车牌信息的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetLprsMaxPlateSize(SzLPRClientHandle handle, const TagNetLprcMaxPlateSize *pMaxPlateSize);

/**
*  @brief 获取车牌识别最大与最小车牌尺寸
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param [IN] pMaxPlateSize 保存车牌识别最大与最小车牌信息的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetLprsMaxPlateSize(SzLPRClientHandle handle, TagNetLprcMaxPlateSize *pMaxPlateSize);


/**
*  @brief 将图像保存为JPEG到指定路径，可指定图像尺寸的模式
*  @param  [IN] pImgInfo 图像结构体，目前只支持默认的格式，即ImageFormatRGB
*  @param  [IN] pFullPathName 设带绝对路径和JPG后缀名的文件名字符串
*  @param  [IN] nQuality JPEG压缩的质量，取值范围1~100；
*  @param  [IN] mode     图像大小的模式；
*  @return 1表示成功，0表示失败
*  @note   给定的文件名中的路径需要存在
*/
SZ_LPRC_API int __stdcall SzLPRClient_ImageSaveToJpegEx(const SZ_LPRC_IMAGE_INFO *pImgInfo, const char *pFullPathName, int nQuality, IMG_SIZE_MODE mode);

/**
*  @brief 保存正在播放的视频的当前帧的截图到指定路径
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] pFullPathName 设带绝对路径和JPG后缀名的文件名字符串
*  @param  [IN] nQuality JPEG压缩的质量，取值范围1~100；
*  @return 1表示成功，0表示失败
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetSnapShootToJpeg(SzLPRClientHandle handle, const char *pFullPathName, int nQuality);

/**
*  @brief 获取设备时间
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] datetimecfg 保存获取时间的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetDevDateTime(SzLPRClientHandle handle, TNetDateTime* datetimecfg);

/**
*  @brief 设置设备时间
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] datetimecfg 设置时间参数的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetDevDateTime(SzLPRClientHandle handle, const TNetDateTime* datetimecfg);

/**
*  @brief 获取设备时间同步参数
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] timeSrccfg 保存时间同步参数的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetDevNtpParam(SzLPRClientHandle handle, TNetNtpPara* timeSrccfg);

/**
*  @brief 设置设备时间同步参数
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] timeSrccfg 设置时间同步参数的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetDevNtpParam(SzLPRClientHandle handle, const TNetNtpPara* timeSrccfg);


/**
*  @brief 获取设备TF卡信息
*  @param [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] pTfCardInfo 保存TF卡信息的结构体
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetTFCardInfo(SzLPRClientHandle handle, TNetTFCardInfo* pTfCardInfo);

/**
*  @brief  格式化TF卡
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] pTfCardInfo 保存TF卡信息的结构体
*  @return 0表示成功，1表示正在格式化，其它值表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_FormatTFCard(SzLPRClientHandle handle);

/**
*  @brief  获取设备信息
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] pDeviceInfo 保存设备信息的结构体指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetDeviceInfo(SzLPRClientHandle handle, TagNetDeviceInfo* pDeviceInfo);

/**
*  @brief  恢复出厂设置
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] pResetSetting 参数恢复等级
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_ResetSettingDev(SzLPRClientHandle handle, const TagNetResetSetting* pResetSetting); 


/**
*  @brief  清空脱机程序的数据库信息
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_ClearDB(SzLPRClientHandle handle);


/**
*  @brief  重启设备
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] pResetSetting 重启设备时的延时间隔
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_RebootDevice(SzLPRClientHandle handle, const TagNetRebootDevice* pResetSetting);

/**
*  @brief  设置JPEG编码质量
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] pParameter 重启设备时的延时间隔
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetJpegQuality(SzLPRClientHandle handle, const TNetJpegQuality *pParameter);

/**
*  @brief  获取设置的JPEG编码质量
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] pParameter 保存JPEG编码质量参数的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetJpegQuality(SzLPRClientHandle handle, TNetJpegQuality *pParameter);

/**
*  @brief  设置串口参数
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] pSerialPara 设置串口参数的结构体指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetSerialParameter(SzLPRClientHandle handle, const TNetSerialPara *pSerialPara);

/**
*  @brief  获取串口参数
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] nSerialPort 指定的串口号
*  @param  [IN] pSerialPara 保存串口参数的结构体指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetSerialParameter(SzLPRClientHandle handle, int nSerialPort, TNetSerialPara *pSerialPara);

/**
*  @brief  设备升级
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] pFullPathName 设备升级的文件名
*  @return 0表示成功， 1 系统繁忙,不能升级，2 升级数据校验错误， 3 No Found TF Card 
		   4 内存不够， 5  硬件版本不匹配， 6 文件过大 7 升级文件格式异常 8 读取文件异常
		   9 安装文件不匹配，不是我们的安装包 10 安装文件版本过低，低于现在使用的版本  11 升级失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_UpgradeRequest(SzLPRClientHandle handle, char *pFullPathName);


/**
*  @brief  设置设备升级的回调函数
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] pUpdateStatusFun 设备升级时升级状态的回调函数
*  @param  [IN] pUserData 用户自定义的参数，一般为更新状态的类对象
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_UpgradeStatusCallBack(SzLPRClientHandle handle, UpdateStatusFunCallBack pUpdateStatusFun, void* pUserData);


/**
*  @brief  同步本地电脑时间
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SyncLocalPcTime(SzLPRClientHandle handle);

/**
*  @brief  用于设置显示实时车牌信息
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] Res 用于设置的参数
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetSaveChePaiResult(SzLPRClientHandle handle, TNetLprcDrawRealTimeResualt *Res);

/**
*  @brief  用于获取显示实时车牌信息
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] Res 用于保存获取的结果
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetChePaiResult(SzLPRClientHandle handle, TNetLprcDrawRealTimeResualt* Res);

/**
*  @brief  用于设置显示实时车牌信息
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] Res  设置的参数信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetSaveChePaiFrame(SzLPRClientHandle handle, TNetLprcDrawPlateRect *PlateRect);

/**
*  @brief  用于设置是否显示车牌框
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] PlateRect 保存设置的结果
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetChePaiFrame(SzLPRClientHandle handle, TNetLprcDrawPlateRect* PlateRect); 

/**
*  @brief  设置设备的继电器控制参数
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] value 设置的继电器参数
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetRelay_Action(SzLPRClientHandle handle, TNetRelayAction* value);

/**
*  @brief  导出设备中的参数到文件中
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] Path 保存参数的文件
*  @return 1表示成功，0表示失败, -1 文件打开失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_Export_Config(SzLPRClientHandle handle, char *Path);

/**
*  @brief  将文件的参数导入到文件设备中
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] Path 保存参数的文件
*  @return 1表示成功，0表示失败,-1 文件打开失败,-2文件发送失败，-3文件接收失败，-4导入的配置文件和相机当前软件版本不匹配，-5 导入的配置文件不完整或被损坏
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_Import_Config(SzLPRClientHandle handle, char *Path);

/**
*  @brief  设置是否对有车辆进行有车牌与无车牌的检测
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] value  设置的参数
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetCheckChePaiExist(SzLPRClientHandle handle, TNetLprcSnapNoPlate *value);

/**
*  @brief  获取对车辆进行有车牌与无车牌的检测设置
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] value  设置的参数
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetCheckChePaiExist(SzLPRClientHandle handle, TNetLprcSnapNoPlate *value);


/**
*  @brief  获取特殊车牌的设置信息
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [OUT] Info  特殊车牌的设置信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetSpecialPlate(SzLPRClientHandle handle, TNetSpecialPlateSet *Info);

/**
*  @brief  设置特殊车牌信息
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [OUT] Info  特殊车牌的设置信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetSpecialPlate(SzLPRClientHandle handle, TNetSpecialPlateSet *Info);

/**
*  @brief  透明通道输出
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [OUT] Info  透明通道输出的内容
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SerialTransferOut(SzLPRClientHandle handle, TagNetSerialTransferOut *Info);

/**
*  @brief  获取透明通道输入的内容
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] inValue  透明通道的相关的通道信息
*  @param  [OUT] retValue  返回的内容
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SerialTransferIn(SzLPRClientHandle handle, TagNetSerialTransferIn *inValue, TagNetSerialTransferIn_Ret *retValue);

/**
*  @brief  设置RS485接收数据的回调函数
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] func  RS485接收数据的回调函数
*  @param  [IN] pUserData  接收数据的对像
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_RS485CallBack(SzLPRClientHandle handle, RS485CallBack func, void *pUserData);


/**
*  @brief  获取网络信号强度的回调函数
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] func  网络信息强度的回调函数
*  @param  [IN] pUserData  接收数据的对像
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_NetSigCallBack(SzLPRClientHandle handle, NetSigCallback func, void *pUserData);

/**
*  @brief  获取图像编码参数
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] info  保存参数的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetEncodeParameter(SzLPRClientHandle handle, TNetEncPara *info);

/**
*  @brief  设置图像编码参数
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] info  图像编码参数指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetEncodeParameter(SzLPRClientHandle handle, TNetEncPara *info);

/**
*  @brief  获取Led爆闪控制的参数
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] info  保存爆闪参数指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetLedStrobe(SzLPRClientHandle handle, TagNetFlashLEDControl *info);

/**
*  @brief  设置Led爆闪的参数
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] info  设置爆闪参数指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetLedStrobe(SzLPRClientHandle handle, TagNetFlashLEDControl *info);


/**
*  @brief  获取用户名密码信息
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] info  保存用户名密码信息的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetUserLoadInfo(SzLPRClientHandle handle, TNetUserInfo *info);


/**
*  @brief  设置用户名密码信息
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] info  保存用户名密码信息的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetUserLoadInfo(SzLPRClientHandle handle, TNetUserInfo *info);

/**
*  @brief  获取脱机的照片信息
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] value  设置的参数
*  @param  [OUT] info  保存文件的路径
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetPickupPhoto(SzLPRClientHandle handle, TNetPickupPhotoClient *value, TagNetPickupPhoto_ret* info);


/**
*  @brief  获取图片目录信息
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] value  设置的参数
*  @param  [OUT] info  目录信息结果
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetPictureDir(SzLPRClientHandle handle, TNetGetPicture *value, TNetGetPictureDirInfo_Ret* info);

/**
*  @brief  根据图片目录信息，获取图片数据
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] value  设置的参数
*  @param  [OUT] info  图片数据信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetPictureDate(SzLPRClientHandle handle, TNetGetPicture *value, TNetGetPictureInfo_Ret* info);


/**
*  @brief  根据目录下载设备中保存的图片
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] DeviceDir  设备的目录
*  @param  [IN] PcDir  保存在本地的目录
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_DownloadPicDir(SzLPRClientHandle handle, TNetDownloadPicDir *DeviceDir, char *PcDir);


SZ_LPRC_API int __stdcall SzLPRClient_BMP_DATE(unsigned char *OutBuf, int *outLen, unsigned char *InBuf, int nWidth, int nHeight);

/**
*  @brief  获取设备的ID
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] info  保存用户名密码信息的指针
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetID(SzLPRClientHandle handle, BYTE *nMasterID, BYTE *nSlaveID);


/**
*  @brief  获取背光补偿,强光抑制
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN OUT] info  背光补偿,强光抑制的信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetBLCPara(SzLPRClientHandle handle, TNetBLCPara *info);

/**
*  @brief  设置背光补偿,强光抑制
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN OUT] info  用于设置的信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetBLCPara(SzLPRClientHandle handle, TNetBLCPara *info);


/**
*  @brief  获取车牌映射信息
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN OUT] info  用于保存车牌映射结果
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetPlatereMap(SzLPRClientHandle handle, TNetLprPlateMap *info);

/**
*  @brief  设置车牌映射结果
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN OUT] info  用于设置的车牌映射结果
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetPlatereMap(SzLPRClientHandle handle, TNetLprPlateMap *info);

/**
*  @brief  获取车牌过滤结果
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN OUT] info  用于保存车牌过滤结果
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetPlateFilter(SzLPRClientHandle handle, TNetLprcPlateFilter *info);

/**
*  @brief  设置车牌过滤结果
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN OUT] info  用于保存车牌过滤结果
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetPlateFilter(SzLPRClientHandle handle, TNetLprcPlateFilter *info);


/**
*  @brief  获取车队通过模式
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN OUT] info  用于保存车队通过模式设置结果
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetCheDuiMode(SzLPRClientHandle handle, TNetCheDuiMode *info);

/**
*  @brief  设置车队通过模式
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN OUT] info  用于保存车队通过模式设置
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetCheDuiMode(SzLPRClientHandle handle, TNetCheDuiMode *info);


/**
*  @brief  获取稳定结果输出设置
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN OUT] info  用于保存稳定结果输出
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetStableOutput(SzLPRClientHandle handle, TNetStableOutput *info);

/**
*  @brief  设置稳定结果输出
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN OUT] info  用于设置稳定结果输出
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetStableOutput(SzLPRClientHandle handle, TNetStableOutput *info);


/**
*  @brief  获取唯一网络标识符
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN OUT] info  http推送的配置信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetNetUniqueID(SzLPRClientHandle handle, TagNetUniqueID *info);


/**
*  @brief  获取设备描述信息
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN OUT] info  设备描述信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetDevDescription(SzLPRClientHandle handle, TagDevDescription *info);


/**
*  @brief  设置设备描述信息
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN OUT] info  设备描述信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetDevDescription(SzLPRClientHandle handle, TagDevDescription *info);

/**
*  @brief  获取设备默认促发线圈
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN OUT] info  促发线圈信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetDeftrigger(SzLPRClientHandle handle, TNetLprcDefTrigAreaPara *info);

/**
*  @brief  获取P2P设置信息
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN OUT] info 获取的p2p信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetP2PInfo(SzLPRClientHandle handle, TNetPeergineLive *info);

/**
*  @brief  设置P2P配置信息
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN OUT] info 设置的p2p信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetP2PInfo(SzLPRClientHandle handle, TNetPeergineLive *info);


/**
*  @brief  设备重启时间
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN OUT] info 设备重启时间
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetRebootTime(SzLPRClientHandle handle, TNetRebootTime *info);

/**
*  @brief  获取重启时间
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN OUT] info 获取重启时间
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetRebootTime(SzLPRClientHandle handle, TNetRebootTime *info);

/**
*  @brief  设备主从像机参数
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN OUT] info 设备重启时间
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetMasterSlavePara(SzLPRClientHandle handle, TNetMasterSlavePara *info);

/**
*  @brief  获取主从像机参数
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN OUT] info 返回像机的主从配置参数
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetMasterSlavePara(SzLPRClientHandle handle, TNetMasterSlavePara *info);


/**
*  @brief  获取脱机程序的版本信息
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN OUT] info 脱机程序的版本信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetTuojiVersion(SzLPRClientHandle handle, TNetTuojiVersion *info);

/**
*  @brief  获取伪车牌过滤
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN OUT] info 返回的伪车牌过滤结果
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetFilterPlate(SzLPRClientHandle handle, TNetFilterPlate *info);

/**
*  @brief  设置伪车牌过滤
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] info 伪车牌过滤信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetFilterPlate(SzLPRClientHandle handle, TNetFilterPlate *info);

/*
*  @brief  添加一条白名单
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] value  添加的白名单信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_AddOneWhite(SzLPRClientHandle handle, TWhiteListInfo *value);

/*
*  @brief  批量添加黑白名单
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] value  添加的白名单信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_AddWhiteList(SzLPRClientHandle handle, TNetAddWhiteLists *value);


/**
*  @brief  删除一条黑白名单记录
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] value  删除的索引号
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_DeleteOneWhite(SzLPRClientHandle handle, TNetDelWhiteList *value);

/**
*  @brief  删除所有黑白名单记录
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_ClearWhiteList(SzLPRClientHandle handle);

/**
*  @brief  修改黑白名单
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] value  修改的白名单参数
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_ModifyWhiteList(SzLPRClientHandle handle, TNetUpdateWhiteList *value);

/**
*  @brief  根据车牌查询相应的白名单信息
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] value  查询的信息
*  @param  [OUT] Info  返回的白名单信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_QueryByChePai(SzLPRClientHandle handle, TNetQueryWhiteList *value, TWhiteListInfo* Info);

/**
*  @brief  根据页查询相应的白名单信息
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] value  查询的信息
*  @param  [OUT] Info  返回的白名单信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_QueryByPage(SzLPRClientHandle handle, TNetQueryWhiteLists* value, TNetQueryWhiteLists_Ret *Info);


/**
*  @brief  设置脱机程序使能
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] Info  脱机程序信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetNetEnableTuoji(SzLPRClientHandle handle, TNetEnableTuoji *Info);

/**
*  @brief  获取脱机程序使能
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [OUT] Info  脱机程序信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetNetEnableTuoji(SzLPRClientHandle handle, TNetEnableTuoji *Info);


/**
*  @brief  设置按装位置信息
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] Info  位置信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetIMGZOOM(SzLPRClientHandle handle, TNetImgZoomPara *info);

/**
*  @brief  获取按装位置信息
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [OUT] Info  位置信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetIMGZOOM(SzLPRClientHandle handle, TNetImgZoomPara *info);


/**
*  @brief  设置抓拍图片的像素
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] info  像素信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetIMGPixel(SzLPRClientHandle handle, TagNetImgPixel *info);


/**
*  @brief  升级ISP固件
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] Path  ISP文件
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_UpGradeISP(SzLPRClientHandle handle, char *Path);

/**
*  @brief  显示帧率
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [IN] num  值分别为1，2，3，4，5，6。 1表示正常显示，每2帧显示一帧， 每3帧显示1帧，每4帧显示1帧，每5帧显示1帧，每6帧显示1帧
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_DisplayFrameRate(SzLPRClientHandle handle, int num);

/**
*  @brief  设备给上位机发送数据的通用回调函数
*  @param  [IN] handle 由SzLPRClient_ConnectDevice函数返回的句柄
*  @param  [IN] func 识别结果回调函数，如果为NULL，则表示关闭该回调函数的功能
*  @param  [IN] pUserData 回调函数中的上下文
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetRecognitionCallBack(SzLPRClientHandle handle, RecognitionCallBack func, void *pUserData);

/**
*  @brief  设置设备端给PC端发送消息的回调函数--函数要在SzLPRClient_SetRecognitionCallBack之后调用
*  @param  [IN] handle 由SzLPRClient_ConnectDevice函数返回的句柄
*  @param  [IN] func 识别结果回调函数，如果为NULL，则表示关闭该回调函数的功能
*  @param  [IN] pUserData 回调函数中的上下文
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetDeviceSendMsgToPcCallBack(SzLPRClientHandle handle, DeviceSendMsgToPc func, void *pUserData);

/**
*  @brief   设置开闸延时时间
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [OUT] Info  设置的时间信息
*  @return 1表示成功，0表示失败, -1表示数据不在有效范围内
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetDoorOpenDelay(SzLPRClientHandle handle, TNetRelayDelayTime *info);


/**
*  @brief  获取开闸延时时间
*  @param  [IN] handle 由SzLPRClient_OpenEx函数返回的句柄
*  @param  [OUT] Info  返回的时间信息
*  @return 1表示成功，0表示失败
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetDoorOpenDelay(SzLPRClientHandle handle, TNetRelayDelayTime *info);

#endif

