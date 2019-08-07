#ifndef __NETCLIENT_H__
#define __NETCLIENT_H__

#include "NetStructDef.h"

/**
*  @brief ȫ�ֳ�ʼ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @note �����нӿڵ���֮ǰ����
*  @ingroup group_global
*/
SZ_LPRC_API int  __stdcall SzLPRClient_Setup();

/**
*  @brief  ��־����ر�
*  @param  [IN] bOpen TRUE �򿪣�FALSE �ر�
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @note ������־��¼����
*  @ingroup group_global
*/
SZ_LPRC_API int  __stdcall SzLPRClient_OpenLog(bool bOpen);

/**
*  @brief ȫ���ͷ�
*  @note �ڳ������ʱ���ã��ͷ�SDK����Դ
*  @ingroup group_global
*/
SZ_LPRC_API void __stdcall SzLPRClient_Cleanup();


/**
*  @brief  ��ȡ�豸SDK�İ汾��
*  @param  [IN] Version ������Ϣ�ĵ�ַ
*  @param  [IN] nlen  Version������Ϣ�Ĵ�С
*  @return �ɹ����� 1
*  @return ʧ�ܷ��� 0
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_ReadSDKVersion(char * Version, int nlen);

/**
*  @brief ��һ���豸
*  @param  [IN] pStrIP �豸��IP��ַ
*  @param  [IN] wPort �豸�Ķ˿ں�
*  @param  [IN] pStrUserName �����豸�����û���
*  @param  [IN] pStrPassword �����豸��������
*  @return �����豸�Ĳ������������ʧ��ʱ(-1 �û�������,�û�������Ϊ��;  -2 �û������벻ƥ��,���벻��Ϊ��; -3 ��½�߹���,����3����
*  @return δ����,Ӧ���Ƚ��е�¼ -4����Ȩ��Ч���ѹ�,ֻ�ܽ��л������� -5 �� ��֤ʧ��,�û�ID����-6�� ��֤ʧ��,������û�ID��ƥ��-7)
*  @return �ɹ����ش���0
*  @ingroup group_device
*/
SZ_LPRC_API SzLPRClientHandle __stdcall SzLPRClient_OpenEx(const char *pStrIP, WORD wPort, const char *pStrUserName, const char *pStrPassword);


/**
*  @brief  �ر��豸
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @note   ֹͣ�����Ժ󣬸ò��ž����ʧЧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_Stop(SzLPRClientHandle handle);


/**
*  @brief ����ʵʱ��Ƶ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] hWnd ���ڵľ��
*  @return �ɹ�����1��ʧ�ܷ���0
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_StartRealPlay(SzLPRClientHandle handle, HWND hWnd);


/**
*  @brief ����ʵʱ��Ƶ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] hWnd ���ڵľ��
*  @return �ɹ�����1��ʧ�ܷ���0
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetDisPlayWnd(SzLPRClientHandle handle, HWND hWnd);

/**
*  @brief  ������Ƶ�����ͼ�Ļص�����
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] pDrawFun ��Ƶ�����ͼ�ص�����
*  @lpDrawFunData  [IN] lpDrawFunData �û��Զ���Ĳ�����һ��ִ�л�ͼ�������
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetDrawFunCallBack(SzLPRClientHandle handle, DrawFunCallBack pDrawFun, void* lpDrawFunData);

/**
*  @brief  �µ�������Ƶ�����ͼ�Ļص�����
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] pDrawFun �µ���Ƶ�����ͼ�ص�����
*  @lpDrawFunData  [IN] lpDrawFunData �û��Զ���Ĳ�����һ��ִ�л�ͼ�������
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetSDKDrawFunCallBack_NEW(SzLPRClientHandle handle, SDKDrawCallBack pDrawFun, void* lpDrawFunData);

/**
*  @brief ����ʶ�����Ļص�����
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] func ʶ�����ص����������ΪNULL�����ʾ�رոûص������Ĺ���
*  @param  [IN] pUserData �ص������е�������
*  @param  [IN] bEnableImage ָ��ʶ�����Ļص��Ƿ���Ҫ������ͼ��Ϣ��1Ϊ��Ҫ��0Ϊ����Ҫ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetPlateInfoCallBack(SzLPRClientHandle handle, LprcInfoCallBack func, void *pUserData, int bEnableImage);

/**
*  @brief ��������״̬�Ļص�����
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] func �豸��Ϣ�ص�����
*  @param  [IN] pUserData �ص������е�������
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetMsgCallBack(SzLPRClientHandle handle, MessageCallBack func, void *pUserData);

/**
*  @brief  ��ȡ��ǰ��֡��
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @return  ���ػ�ȡ���Ľ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetRealFR(SzLPRClientHandle handle);


/**
*  @brief ��ʼ�����豸
*  @param  [IN] func �ҵ����豸ͨ���ûص���������
*  @param  [IN] pUserData �ص������е�������
*  @return �ɹ�����0�����ز����豸�ľ�� �� 0��ʾʧ��
*  @ingroup group_global
*/
SZ_LPRC_API SzLPRClientHandle __stdcall SzLPRClient_StartFindDevice(FindDeviceCallback func, void *pUserData);

/**
*  @brief ֹͣ�����豸
*  @param  [IN] handle SzLPRClient_StartFindDevice ���صľ��
*  @return �ɹ�����0�����ز����豸�ľ���� 0��ʾʧ��
*  @ingroup group_global
*/
SZ_LPRC_API int __stdcall SzLPRClient_StopFindDevice(SzLPRClientHandle handle);


/**
*  @brief �޸��������
*  @param  [IN] netCfg �޸ĵ�������Ϣ
*  @note ��������ʵ�ֿ������޸�IP�Ĺ���  
*  @return 1��ʾ�ɹ���-1��ʾʧ�� ,2 �豸IP�����ز���ͬһ����ʧ��
*  @ingroup group_global
*/
SZ_LPRC_API int __stdcall SzLPRClient_UpdateNetworkParam(SZ_LPRC_NETCFG *netCfg);

/**
*  @brief  �������û�ȡͼ��Ļص�����
*  @param  [IN] handle SzLPRClient_StartFindDevice ���صľ��
*  @param  [IN] drawVLOOP  ����ͼ��Ļص�����
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_global
*/
SZ_LPRC_API void __stdcall SzLPRClient_DrawVLoopsCallback(SzLPRClientHandle handle, DrawVLoopsCallback drawVLOOP);


/**
*  @brief  �������û�ȡbmpͼ��Ļص�����
*  @param  [IN] handle SzLPRClient_StartFindDevice ���صľ��
*  @param  [IN] drawVLOOP  ����ͼ��Ļص�����
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_global
*/
SZ_LPRC_API void __stdcall SzLPRClient_BMP(SzLPRClientHandle handle, GetBMPCallback bmp);

/**
*  @brief  ���������Ƿ���ʾʶ���
*  @param  [IN] handle SzLPRClient_StartFindDevice ���صľ��
*  @param  [IN] bShowStaticVLoop  FALSE ����ʾ��TRUEΪ��ʾ
*  @return FALSE ����ʧ�ܣ�TRUEΪ���óɹ�
*  @ingroup group_global
*/
SZ_LPRC_API BOOL __stdcall SzLPRClient_ShowStaticVLoops(SzLPRClientHandle handle, BOOL bShowStaticVLoop);

/**
*  @brief ���ƾ�ͷ�������,�䱶�佹
*  @param  [IN] handle SzLPRClient_StartFindDevice ���صľ��
*  @param  [IN] pLensAction ��ͷִ�ж����ṹ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_global
*/
SZ_LPRC_API void __stdcall SzLPRClient_LensAction(SzLPRClientHandle handle, const TagNetLensAction* pLensAction);

/**
*  @brief ����LED����ģʽ
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param [IN] pledCtrl ����LED����ģʽ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetLedLightControl(SzLPRClientHandle handle, const TagNetLedPara* pledCtrl);

/**
*  @brief ��ȡLED����ģʽ
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param [IN] pledCtrl ����LED����ģʽ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetLedLightControl(SzLPRClientHandle handle, TagNetLedPara* pledCtrl);

/**
*  @brief ���÷��ȿ����
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param [IN] bool TRUE Ϊ����������Ϊ����
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetFanSanControl(SzLPRClientHandle handle, bool value);

/**
*  @brief ��ȡ���ȿ�����Ϣ
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param [IN] FanSanCtrl Ϊ���ȿ��ƿ�����Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetFanSanControl(SzLPRClientHandle handle, TNetFanPara *FanSanCtrl);

/**
*  @brief ��ȡ���������Ϣ
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param [IN] netcfg �������������ָ�� 
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetNetConfig(SzLPRClientHandle handle, TNetWiredPara* netcfg);

/**
*  @brief �����豸�������
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param [IN] netcfg ���������ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetNetConfig(SzLPRClientHandle handle, TNetWiredPara* netcfg);


/**
*  @brief ��ȡ���������Ϣ
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param [IN] ispExpParams ���ڱ������������Ϣ��ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetExpGain(SzLPRClientHandle handle, TNetExpGain* ispExpParams);

/**
*  @brief �������������Ϣ
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param [IN] ispExpParams ���ڲ������������Ϣ��ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetExpGain(SzLPRClientHandle handle, const TNetExpGain* ispExpParams);

/**
*  @brief ��ȡͼ���������
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param [IN] imgEnhanceParams �������õ�ͼ�����������ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetImgBase(SzLPRClientHandle handle, TNetImageBasePara* imgEnhanceParams);

/**
*  @brief ����ͼ���������
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param [IN] imgEnhanceParams ���ڱ������õ�ͼ�����������ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetImgBase(SzLPRClientHandle handle, const TNetImageBasePara* imgEnhanceParams);



/**
*  @brief ������������źţ�ǿ�ƴ���ǰʱ�̵����ݲ�������
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @note   ����ʶ����ͨ���ص������ķ�ʽ���أ������ǰ��Ƶ�������޳��ƣ���ص��������ᱻ����
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_ForceTrigger(SzLPRClientHandle handle);

/**
*  @brief ��ȡ��ƵOSD������
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param [IN] pParam ���ڱ���OSD������ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetOsdParam(SzLPRClientHandle handle, TNetOSDPara* pParam);

/**
*  @brief ������ƵOSD������
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param [IN] pParam ����OSD������ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetOsdParam(SzLPRClientHandle handle, const TNetOSDPara* pParam);


/**
*  @brief ��ȡ�����õ�Ԥ��ʡ��
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param [IN] pProvInfo Ԥ��ʡ����Ϣָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetSupportedProvinces(SzLPRClientHandle handle, TagNetLprDefProvince* pProvInfo);

/**
*  @brief ��ȡ�����õ�Ԥ��ʡ��
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param [IN] pProvInfo Ԥ��ʡ����Ϣָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetSupportedProvinces_EX(SzLPRClientHandle handle, TNetLprDefProvinceEx* pProvInfo);

/**
*  @brief ���������õ�Ԥ��ʡ��
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param [IN] pProvInfo ����ʡ����Ϣ��ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetSupportedProvinces(SzLPRClientHandle handle, const TagNetLprDefProvince* pProvInfo);

/**
*  @brief ���������õ�Ԥ��ʡ��
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param [IN] pProvInfo ����ʡ����Ϣ��ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetSupportedProvinces_EX(SzLPRClientHandle handle, const TNetLprDefProvinceEx* pProvInfo);

/**
*  @brief ��ȡ�豸�˳���ʶ�����Ͳ���
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param [IN] pProvInfo ���ñ������͵�ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetSupportedLprcPlateType(SzLPRClientHandle handle, TNetLprcPlateType *pLprcPlateType);

/**
*  @brief �����豸�˳���ʶ�����Ͳ���
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param [IN] pProvInfo ʶ�����͵�ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetSupportedLprcPlateType(SzLPRClientHandle handle, const TNetLprcPlateType *pLprcPlateType);

/**
*  @brief �µ������豸�˳���ʶ�����Ͳ���
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param [IN] Info �µ�ʶ�����͵�ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetSupportedLprcPlateType_New(SzLPRClientHandle handle, TNetLprcPlateTypeNew *Info);

/**
*  @brief �µĻ�ȡ�豸�˳���ʶ�����Ͳ���
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param [IN] Info �µ�ʶ�����͵�ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetSupportedLprcPlateType_New(SzLPRClientHandle handle, TNetLprcPlateTypeNew *Info);

/**
*  @brief ���ó���ʶ����������Ȧ�Ĵ�������
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param [IN] pVirtualLoop ���津�������ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetTriggerLoopEx(SzLPRClientHandle handle, const TagNetLprcTriggerPara* pVirtualLoop);

/**
*  @brief ��ȡ����ʶ����������Ȧ�Ĵ�������
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param [IN] pVirtualLoop ���津�������ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetTriggerLoopEx(SzLPRClientHandle handle, TagNetLprcTriggerPara* pVirtualLoop);

/**
*  @brief ���ó���ʶ���������С���Ƴߴ�
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param [IN] pMaxPlateSize ����ʶ���������С������Ϣ��ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetLprsMaxPlateSize(SzLPRClientHandle handle, const TagNetLprcMaxPlateSize *pMaxPlateSize);

/**
*  @brief ��ȡ����ʶ���������С���Ƴߴ�
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param [IN] pMaxPlateSize ���泵��ʶ���������С������Ϣ��ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetLprsMaxPlateSize(SzLPRClientHandle handle, TagNetLprcMaxPlateSize *pMaxPlateSize);


/**
*  @brief ��ͼ�񱣴�ΪJPEG��ָ��·������ָ��ͼ��ߴ��ģʽ
*  @param  [IN] pImgInfo ͼ��ṹ�壬Ŀǰֻ֧��Ĭ�ϵĸ�ʽ����ImageFormatRGB
*  @param  [IN] pFullPathName �������·����JPG��׺�����ļ����ַ���
*  @param  [IN] nQuality JPEGѹ����������ȡֵ��Χ1~100��
*  @param  [IN] mode     ͼ���С��ģʽ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @note   �������ļ����е�·����Ҫ����
*/
SZ_LPRC_API int __stdcall SzLPRClient_ImageSaveToJpegEx(const SZ_LPRC_IMAGE_INFO *pImgInfo, const char *pFullPathName, int nQuality, IMG_SIZE_MODE mode);

/**
*  @brief �������ڲ��ŵ���Ƶ�ĵ�ǰ֡�Ľ�ͼ��ָ��·��
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] pFullPathName �������·����JPG��׺�����ļ����ַ���
*  @param  [IN] nQuality JPEGѹ����������ȡֵ��Χ1~100��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetSnapShootToJpeg(SzLPRClientHandle handle, const char *pFullPathName, int nQuality);

/**
*  @brief ��ȡ�豸ʱ��
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] datetimecfg �����ȡʱ���ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetDevDateTime(SzLPRClientHandle handle, TNetDateTime* datetimecfg);

/**
*  @brief �����豸ʱ��
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] datetimecfg ����ʱ�������ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetDevDateTime(SzLPRClientHandle handle, const TNetDateTime* datetimecfg);

/**
*  @brief ��ȡ�豸ʱ��ͬ������
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] timeSrccfg ����ʱ��ͬ��������ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetDevNtpParam(SzLPRClientHandle handle, TNetNtpPara* timeSrccfg);

/**
*  @brief �����豸ʱ��ͬ������
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] timeSrccfg ����ʱ��ͬ��������ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetDevNtpParam(SzLPRClientHandle handle, const TNetNtpPara* timeSrccfg);


/**
*  @brief ��ȡ�豸TF����Ϣ
*  @param [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] pTfCardInfo ����TF����Ϣ�Ľṹ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetTFCardInfo(SzLPRClientHandle handle, TNetTFCardInfo* pTfCardInfo);

/**
*  @brief  ��ʽ��TF��
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] pTfCardInfo ����TF����Ϣ�Ľṹ��
*  @return 0��ʾ�ɹ���1��ʾ���ڸ�ʽ��������ֵ��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_FormatTFCard(SzLPRClientHandle handle);

/**
*  @brief  ��ȡ�豸��Ϣ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] pDeviceInfo �����豸��Ϣ�Ľṹ��ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetDeviceInfo(SzLPRClientHandle handle, TagNetDeviceInfo* pDeviceInfo);

/**
*  @brief  �ָ���������
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] pResetSetting �����ָ��ȼ�
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_ResetSettingDev(SzLPRClientHandle handle, const TagNetResetSetting* pResetSetting); 


/**
*  @brief  ����ѻ���������ݿ���Ϣ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_ClearDB(SzLPRClientHandle handle);


/**
*  @brief  �����豸
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] pResetSetting �����豸ʱ����ʱ���
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_RebootDevice(SzLPRClientHandle handle, const TagNetRebootDevice* pResetSetting);

/**
*  @brief  ����JPEG��������
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] pParameter �����豸ʱ����ʱ���
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetJpegQuality(SzLPRClientHandle handle, const TNetJpegQuality *pParameter);

/**
*  @brief  ��ȡ���õ�JPEG��������
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] pParameter ����JPEG��������������ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetJpegQuality(SzLPRClientHandle handle, TNetJpegQuality *pParameter);

/**
*  @brief  ���ô��ڲ���
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] pSerialPara ���ô��ڲ����Ľṹ��ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetSerialParameter(SzLPRClientHandle handle, const TNetSerialPara *pSerialPara);

/**
*  @brief  ��ȡ���ڲ���
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] nSerialPort ָ���Ĵ��ں�
*  @param  [IN] pSerialPara ���洮�ڲ����Ľṹ��ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetSerialParameter(SzLPRClientHandle handle, int nSerialPort, TNetSerialPara *pSerialPara);

/**
*  @brief  �豸����
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] pFullPathName �豸�������ļ���
*  @return 0��ʾ�ɹ��� 1 ϵͳ��æ,����������2 ��������У����� 3 No Found TF Card 
		   4 �ڴ治���� 5  Ӳ���汾��ƥ�䣬 6 �ļ����� 7 �����ļ���ʽ�쳣 8 ��ȡ�ļ��쳣
		   9 ��װ�ļ���ƥ�䣬�������ǵİ�װ�� 10 ��װ�ļ��汾���ͣ���������ʹ�õİ汾  11 ����ʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_UpgradeRequest(SzLPRClientHandle handle, char *pFullPathName);


/**
*  @brief  �����豸�����Ļص�����
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] pUpdateStatusFun �豸����ʱ����״̬�Ļص�����
*  @param  [IN] pUserData �û��Զ���Ĳ�����һ��Ϊ����״̬�������
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_UpgradeStatusCallBack(SzLPRClientHandle handle, UpdateStatusFunCallBack pUpdateStatusFun, void* pUserData);


/**
*  @brief  ͬ�����ص���ʱ��
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SyncLocalPcTime(SzLPRClientHandle handle);

/**
*  @brief  ����������ʾʵʱ������Ϣ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] Res �������õĲ���
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetSaveChePaiResult(SzLPRClientHandle handle, TNetLprcDrawRealTimeResualt *Res);

/**
*  @brief  ���ڻ�ȡ��ʾʵʱ������Ϣ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] Res ���ڱ����ȡ�Ľ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetChePaiResult(SzLPRClientHandle handle, TNetLprcDrawRealTimeResualt* Res);

/**
*  @brief  ����������ʾʵʱ������Ϣ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] Res  ���õĲ�����Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetSaveChePaiFrame(SzLPRClientHandle handle, TNetLprcDrawPlateRect *PlateRect);

/**
*  @brief  ���������Ƿ���ʾ���ƿ�
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] PlateRect �������õĽ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetChePaiFrame(SzLPRClientHandle handle, TNetLprcDrawPlateRect* PlateRect); 

/**
*  @brief  �����豸�ļ̵������Ʋ���
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] value ���õļ̵�������
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetRelay_Action(SzLPRClientHandle handle, TNetRelayAction* value);

/**
*  @brief  �����豸�еĲ������ļ���
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] Path ����������ļ�
*  @return 1��ʾ�ɹ���0��ʾʧ��, -1 �ļ���ʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_Export_Config(SzLPRClientHandle handle, char *Path);

/**
*  @brief  ���ļ��Ĳ������뵽�ļ��豸��
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] Path ����������ļ�
*  @return 1��ʾ�ɹ���0��ʾʧ��,-1 �ļ���ʧ��,-2�ļ�����ʧ�ܣ�-3�ļ�����ʧ�ܣ�-4����������ļ��������ǰ����汾��ƥ�䣬-5 ����������ļ�����������
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_Import_Config(SzLPRClientHandle handle, char *Path);

/**
*  @brief  �����Ƿ���г��������г������޳��Ƶļ��
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] value  ���õĲ���
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetCheckChePaiExist(SzLPRClientHandle handle, TNetLprcSnapNoPlate *value);

/**
*  @brief  ��ȡ�Գ��������г������޳��Ƶļ������
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] value  ���õĲ���
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetCheckChePaiExist(SzLPRClientHandle handle, TNetLprcSnapNoPlate *value);


/**
*  @brief  ��ȡ���⳵�Ƶ�������Ϣ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [OUT] Info  ���⳵�Ƶ�������Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetSpecialPlate(SzLPRClientHandle handle, TNetSpecialPlateSet *Info);

/**
*  @brief  �������⳵����Ϣ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [OUT] Info  ���⳵�Ƶ�������Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetSpecialPlate(SzLPRClientHandle handle, TNetSpecialPlateSet *Info);

/**
*  @brief  ͸��ͨ�����
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [OUT] Info  ͸��ͨ�����������
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SerialTransferOut(SzLPRClientHandle handle, TagNetSerialTransferOut *Info);

/**
*  @brief  ��ȡ͸��ͨ�����������
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] inValue  ͸��ͨ������ص�ͨ����Ϣ
*  @param  [OUT] retValue  ���ص�����
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SerialTransferIn(SzLPRClientHandle handle, TagNetSerialTransferIn *inValue, TagNetSerialTransferIn_Ret *retValue);

/**
*  @brief  ����RS485�������ݵĻص�����
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] func  RS485�������ݵĻص�����
*  @param  [IN] pUserData  �������ݵĶ���
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_RS485CallBack(SzLPRClientHandle handle, RS485CallBack func, void *pUserData);


/**
*  @brief  ��ȡ�����ź�ǿ�ȵĻص�����
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] func  ������Ϣǿ�ȵĻص�����
*  @param  [IN] pUserData  �������ݵĶ���
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_NetSigCallBack(SzLPRClientHandle handle, NetSigCallback func, void *pUserData);

/**
*  @brief  ��ȡͼ��������
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] info  ���������ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetEncodeParameter(SzLPRClientHandle handle, TNetEncPara *info);

/**
*  @brief  ����ͼ��������
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] info  ͼ��������ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetEncodeParameter(SzLPRClientHandle handle, TNetEncPara *info);

/**
*  @brief  ��ȡLed�������ƵĲ���
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] info  ���汬������ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetLedStrobe(SzLPRClientHandle handle, TagNetFlashLEDControl *info);

/**
*  @brief  ����Led�����Ĳ���
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] info  ���ñ�������ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetLedStrobe(SzLPRClientHandle handle, TagNetFlashLEDControl *info);


/**
*  @brief  ��ȡ�û���������Ϣ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] info  �����û���������Ϣ��ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetUserLoadInfo(SzLPRClientHandle handle, TNetUserInfo *info);


/**
*  @brief  �����û���������Ϣ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] info  �����û���������Ϣ��ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetUserLoadInfo(SzLPRClientHandle handle, TNetUserInfo *info);

/**
*  @brief  ��ȡ�ѻ�����Ƭ��Ϣ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] value  ���õĲ���
*  @param  [OUT] info  �����ļ���·��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetPickupPhoto(SzLPRClientHandle handle, TNetPickupPhotoClient *value, TagNetPickupPhoto_ret* info);


/**
*  @brief  ��ȡͼƬĿ¼��Ϣ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] value  ���õĲ���
*  @param  [OUT] info  Ŀ¼��Ϣ���
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetPictureDir(SzLPRClientHandle handle, TNetGetPicture *value, TNetGetPictureDirInfo_Ret* info);

/**
*  @brief  ����ͼƬĿ¼��Ϣ����ȡͼƬ����
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] value  ���õĲ���
*  @param  [OUT] info  ͼƬ������Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetPictureDate(SzLPRClientHandle handle, TNetGetPicture *value, TNetGetPictureInfo_Ret* info);


/**
*  @brief  ����Ŀ¼�����豸�б����ͼƬ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] DeviceDir  �豸��Ŀ¼
*  @param  [IN] PcDir  �����ڱ��ص�Ŀ¼
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_DownloadPicDir(SzLPRClientHandle handle, TNetDownloadPicDir *DeviceDir, char *PcDir);


SZ_LPRC_API int __stdcall SzLPRClient_BMP_DATE(unsigned char *OutBuf, int *outLen, unsigned char *InBuf, int nWidth, int nHeight);

/**
*  @brief  ��ȡ�豸��ID
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] info  �����û���������Ϣ��ָ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetID(SzLPRClientHandle handle, BYTE *nMasterID, BYTE *nSlaveID);


/**
*  @brief  ��ȡ���ⲹ��,ǿ������
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN OUT] info  ���ⲹ��,ǿ�����Ƶ���Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetBLCPara(SzLPRClientHandle handle, TNetBLCPara *info);

/**
*  @brief  ���ñ��ⲹ��,ǿ������
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN OUT] info  �������õ���Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetBLCPara(SzLPRClientHandle handle, TNetBLCPara *info);


/**
*  @brief  ��ȡ����ӳ����Ϣ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN OUT] info  ���ڱ��泵��ӳ����
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetPlatereMap(SzLPRClientHandle handle, TNetLprPlateMap *info);

/**
*  @brief  ���ó���ӳ����
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN OUT] info  �������õĳ���ӳ����
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetPlatereMap(SzLPRClientHandle handle, TNetLprPlateMap *info);

/**
*  @brief  ��ȡ���ƹ��˽��
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN OUT] info  ���ڱ��泵�ƹ��˽��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetPlateFilter(SzLPRClientHandle handle, TNetLprcPlateFilter *info);

/**
*  @brief  ���ó��ƹ��˽��
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN OUT] info  ���ڱ��泵�ƹ��˽��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetPlateFilter(SzLPRClientHandle handle, TNetLprcPlateFilter *info);


/**
*  @brief  ��ȡ����ͨ��ģʽ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN OUT] info  ���ڱ��泵��ͨ��ģʽ���ý��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetCheDuiMode(SzLPRClientHandle handle, TNetCheDuiMode *info);

/**
*  @brief  ���ó���ͨ��ģʽ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN OUT] info  ���ڱ��泵��ͨ��ģʽ����
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetCheDuiMode(SzLPRClientHandle handle, TNetCheDuiMode *info);


/**
*  @brief  ��ȡ�ȶ�����������
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN OUT] info  ���ڱ����ȶ�������
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetStableOutput(SzLPRClientHandle handle, TNetStableOutput *info);

/**
*  @brief  �����ȶ�������
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN OUT] info  ���������ȶ�������
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetStableOutput(SzLPRClientHandle handle, TNetStableOutput *info);


/**
*  @brief  ��ȡΨһ�����ʶ��
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN OUT] info  http���͵�������Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetNetUniqueID(SzLPRClientHandle handle, TagNetUniqueID *info);


/**
*  @brief  ��ȡ�豸������Ϣ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN OUT] info  �豸������Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetDevDescription(SzLPRClientHandle handle, TagDevDescription *info);


/**
*  @brief  �����豸������Ϣ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN OUT] info  �豸������Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetDevDescription(SzLPRClientHandle handle, TagDevDescription *info);

/**
*  @brief  ��ȡ�豸Ĭ�ϴٷ���Ȧ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN OUT] info  �ٷ���Ȧ��Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetDeftrigger(SzLPRClientHandle handle, TNetLprcDefTrigAreaPara *info);

/**
*  @brief  ��ȡP2P������Ϣ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN OUT] info ��ȡ��p2p��Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetP2PInfo(SzLPRClientHandle handle, TNetPeergineLive *info);

/**
*  @brief  ����P2P������Ϣ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN OUT] info ���õ�p2p��Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetP2PInfo(SzLPRClientHandle handle, TNetPeergineLive *info);


/**
*  @brief  �豸����ʱ��
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN OUT] info �豸����ʱ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetRebootTime(SzLPRClientHandle handle, TNetRebootTime *info);

/**
*  @brief  ��ȡ����ʱ��
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN OUT] info ��ȡ����ʱ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetRebootTime(SzLPRClientHandle handle, TNetRebootTime *info);

/**
*  @brief  �豸�����������
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN OUT] info �豸����ʱ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetMasterSlavePara(SzLPRClientHandle handle, TNetMasterSlavePara *info);

/**
*  @brief  ��ȡ�����������
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN OUT] info ����������������ò���
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetMasterSlavePara(SzLPRClientHandle handle, TNetMasterSlavePara *info);


/**
*  @brief  ��ȡ�ѻ�����İ汾��Ϣ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN OUT] info �ѻ�����İ汾��Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetTuojiVersion(SzLPRClientHandle handle, TNetTuojiVersion *info);

/**
*  @brief  ��ȡα���ƹ���
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN OUT] info ���ص�α���ƹ��˽��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetFilterPlate(SzLPRClientHandle handle, TNetFilterPlate *info);

/**
*  @brief  ����α���ƹ���
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] info α���ƹ�����Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetFilterPlate(SzLPRClientHandle handle, TNetFilterPlate *info);

/*
*  @brief  ���һ��������
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] value  ��ӵİ�������Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_AddOneWhite(SzLPRClientHandle handle, TWhiteListInfo *value);

/*
*  @brief  ������Ӻڰ�����
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] value  ��ӵİ�������Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_AddWhiteList(SzLPRClientHandle handle, TNetAddWhiteLists *value);


/**
*  @brief  ɾ��һ���ڰ�������¼
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] value  ɾ����������
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_DeleteOneWhite(SzLPRClientHandle handle, TNetDelWhiteList *value);

/**
*  @brief  ɾ�����кڰ�������¼
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_ClearWhiteList(SzLPRClientHandle handle);

/**
*  @brief  �޸ĺڰ�����
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] value  �޸ĵİ���������
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_ModifyWhiteList(SzLPRClientHandle handle, TNetUpdateWhiteList *value);

/**
*  @brief  ���ݳ��Ʋ�ѯ��Ӧ�İ�������Ϣ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] value  ��ѯ����Ϣ
*  @param  [OUT] Info  ���صİ�������Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_QueryByChePai(SzLPRClientHandle handle, TNetQueryWhiteList *value, TWhiteListInfo* Info);

/**
*  @brief  ����ҳ��ѯ��Ӧ�İ�������Ϣ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] value  ��ѯ����Ϣ
*  @param  [OUT] Info  ���صİ�������Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_QueryByPage(SzLPRClientHandle handle, TNetQueryWhiteLists* value, TNetQueryWhiteLists_Ret *Info);


/**
*  @brief  �����ѻ�����ʹ��
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] Info  �ѻ�������Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetNetEnableTuoji(SzLPRClientHandle handle, TNetEnableTuoji *Info);

/**
*  @brief  ��ȡ�ѻ�����ʹ��
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [OUT] Info  �ѻ�������Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetNetEnableTuoji(SzLPRClientHandle handle, TNetEnableTuoji *Info);


/**
*  @brief  ���ð�װλ����Ϣ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] Info  λ����Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetIMGZOOM(SzLPRClientHandle handle, TNetImgZoomPara *info);

/**
*  @brief  ��ȡ��װλ����Ϣ
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [OUT] Info  λ����Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetIMGZOOM(SzLPRClientHandle handle, TNetImgZoomPara *info);


/**
*  @brief  ����ץ��ͼƬ������
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] info  ������Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetIMGPixel(SzLPRClientHandle handle, TagNetImgPixel *info);


/**
*  @brief  ����ISP�̼�
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] Path  ISP�ļ�
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_UpGradeISP(SzLPRClientHandle handle, char *Path);

/**
*  @brief  ��ʾ֡��
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [IN] num  ֵ�ֱ�Ϊ1��2��3��4��5��6�� 1��ʾ������ʾ��ÿ2֡��ʾһ֡�� ÿ3֡��ʾ1֡��ÿ4֡��ʾ1֡��ÿ5֡��ʾ1֡��ÿ6֡��ʾ1֡
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_DisplayFrameRate(SzLPRClientHandle handle, int num);

/**
*  @brief  �豸����λ���������ݵ�ͨ�ûص�����
*  @param  [IN] handle ��SzLPRClient_ConnectDevice�������صľ��
*  @param  [IN] func ʶ�����ص����������ΪNULL�����ʾ�رոûص������Ĺ���
*  @param  [IN] pUserData �ص������е�������
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetRecognitionCallBack(SzLPRClientHandle handle, RecognitionCallBack func, void *pUserData);

/**
*  @brief  �����豸�˸�PC�˷�����Ϣ�Ļص�����--����Ҫ��SzLPRClient_SetRecognitionCallBack֮�����
*  @param  [IN] handle ��SzLPRClient_ConnectDevice�������صľ��
*  @param  [IN] func ʶ�����ص����������ΪNULL�����ʾ�رոûص������Ĺ���
*  @param  [IN] pUserData �ص������е�������
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetDeviceSendMsgToPcCallBack(SzLPRClientHandle handle, DeviceSendMsgToPc func, void *pUserData);

/**
*  @brief   ���ÿ�բ��ʱʱ��
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [OUT] Info  ���õ�ʱ����Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��, -1��ʾ���ݲ�����Ч��Χ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_SetDoorOpenDelay(SzLPRClientHandle handle, TNetRelayDelayTime *info);


/**
*  @brief  ��ȡ��բ��ʱʱ��
*  @param  [IN] handle ��SzLPRClient_OpenEx�������صľ��
*  @param  [OUT] Info  ���ص�ʱ����Ϣ
*  @return 1��ʾ�ɹ���0��ʾʧ��
*  @ingroup group_device
*/
SZ_LPRC_API int __stdcall SzLPRClient_GetDoorOpenDelay(SzLPRClientHandle handle, TNetRelayDelayTime *info);

#endif

