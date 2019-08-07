/**************************************************************************
* 版    权： 	Copyright (c) 2015 
* 文件名称：	Net_Setup.h
* 文件标识： 
* 内容摘要：    摄像机网络开发SDK,处理配置消息
* 其它说明： 
* 当前版本：	V1.0
* 作    者	
* 完成日期：	2013年08月28日
**************************************************************************/
#ifndef __DCNETSETUP_H
#define __DCNETSETUP_H

#ifdef     NET_API
#else
   #define NET_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C"
{
#endif

typedef int DCHANDLE;

#define HANDLE_INVALID -1

/**************************************************************************
 *                         数据类型                                    *
 **************************************************************************/

#define VERSION_NAME_LEN	 	64
#define MAX_SERVER_NAME_LEN		64
#define MAX_USER_PWD_LEN		32
#define MAX_FILE_NAME_LEN		256
#define MAX_TIMEBUCKET			4
#define MAX_HOST_LEN			16
#define ONE_DIRECTION_LANES		(5)
#define EVENT_CAP_TIMEBUCEKT_CNT 4
#define MAX_PARTITION_COUNT     10
#define MSG_PARAM_LEN			1424
#define MAX_LED_COUNT           5
#define MAX_LED_CONTENT         64
#define MAX_WEL_CONTENT			32
#define  AVE_REG_NUM       8       //设置区域数目

#define MAX_ASS_SEARCH		32
#define NET_MAX_MAC_LEN     32

/* 状态码常量定义*/
typedef enum
{
	DC_NO_ERROR			      = 0,   //正常
	DC_HANDLE_INVALID		  = 1,   //无效的句柄
	DC_CONN_FAIL			  = 2,   //连接失败
	DC_OBJ_BUSY				  = 3,   //对象忙
	DC_OBJ_UNEXIST			  = 4,   //对象不存在
	DC_CMD_INVALID			  = 5,   //命令无效
	DC_PARA_INVALID			  = 6,   //参数无效
	DC_REQ_TIMEOUT			  = 7,   //请求超时
	DC_MEMORY_LACK 			  = 8,   //内存申请失败
	DC_SEND_FAIL 			  = 9,   //数据发送失败
	DC_RECV_FAIL			  = 10,  //数据接收失败
	DC_OPT_FAIL				  = 11,  //操作失败
	DC_NOT_CONN 			  = 12,  //没有触发连接
	DC_BEYOND_MAX_CLIENT      = 13,  //超出相机最大连接数量
	DC_CONNECT_AUTH           = 18,  //连接鉴权
	DC_USER_NOT_EXIST		  = 19,  //用户不存在
	DC_PASSWD_ERROR			  = 20,  //密码错误
	DC_TF_NOT_EXIST			  = 21,  //TF卡不存在
	DC_TF_IO_ERROR			  = 22,  //TF卡读写错误
	DC_ENCPYPTION_ERR		  = 23,  //二次加密数据校验失败

	DC_UNDEFINED_ERROR		  = -1,

	//登录连接错误码
	DC_CONN_PORT_NEGO_FAIL	  = 1000, //发送端口协商失败
	DC_CONN_RXQUE_CREATE_FAIL = 1001, //创建接收队列失败
	DC_CONN_TXQUE_CREATE_FAIL = 1002, //创建发送队列失败
	DC_CONN_REQUE_CREATE_FAIL = 1003, //创建消息上报队列失败
	DC_CONN_30000_CONTROL_TSK_CREATE_FAIL = 1004, //创建30000控制线程失败
	DC_CONN_40000_CONTROL_TSK_CREATE_FAIL = 1005, //创建图片上报线程失败
	DC_CONN_SERVER_ERROR				  = 1006, //服务器内部错误
	DC_CONN_RESPONSE_CODE_AUTHORITY_LIMIT = 1007, //权限受限

	//白名单错误码
	DC_WHITE_LIST_FILE_OPEN_FAIL = 1100, //白名单文件打开失败
	DC_WHITE_LIST_FILE_EMPTY = 1101, //白名单文件为空
	DC_WHITE_LIST_FILE_MAPPING_FAIL = 1102, //白名单文件映射失败
	DC_WHITE_LIST_FILE_MAPPING_OPEN_FAIL = 1103, //白名单文件打开映射失败
	DC_WHITE_LIST_MEMORY_LACK_FAIL = 1104, //白名单内存申请失败
	DC_WHITE_LIST_FILE_SIZE_MORE = 1105, //白名单文件大于1M
	DC_WHITE_LIST_FORMAT_ERROR = 1106, //白名单格式不正确
	DC_WHITE_LIST_CREATE_NEW_FILE_FAIL = 1107, //创建新的白名单失败
	DC_WHITE_LIST_WRITE_NEW_FILE_FAIL = 1108, //写白名单文件失败
	DC_WHITE_LIST_WRITE_NEW_FILE_LENGTH_ERROR = 1109, //写白名单长度不对
	DC_WHITE_LIST_MEMORY_LACK_FAIL_OLD = 1110, //白名单内存申请失败
	DC_WHITE_LIST_CREATE_THREAD_FAIL = 1111, //白名单创建线程失败
	DC_WHITE_LIST_PLATE_EMPTY = 1112, //白名单车牌号为空
	DC_WHITE_LIST_PLATE_LENGTH_ERROR = 1113, //白名单车牌长度错误
	DC_WHITE_LIST_PLATE_SPECIAL_CHAR = 1114, //白名单车牌包含特殊字符
	DC_WHITE_LIST_TIME_YEAR_ERROR = 1115, //白名单时间年份不对
	DC_WHITE_LIST_TIME_MONTH_ERROR = 1117, //白名单时间月份不对
	DC_WHITE_LIST_TIME_BIG_MONTH_DAY_ERROR = 1118, //白名单时间大月日期不对
	DC_WHITE_LIST_TIME_SMALL_MONTH_DAY_ERROR = 1119, //白名单时间小月日期不对
	DC_WHITE_LIST_TIME_LEAP_YEAR_DAY_ERROR = 1120, //白名单时间闰年二月日期不对
	DC_WHITE_LIST_TIME_NO_LEAP_YEAR_DAY_ERROR = 1121, //白名单时间非闰年二月日期不对
	DC_WHITE_LIST_TIME_HOUR_ERROR = 1122, //白名单时间小时不对
	DC_WHITE_LIST_TIME_MINUTE_ERROR = 1123, //白名单时间分钟不对
	DC_WHITE_LIST_TIME_SECOND_ERROR = 1124, //白名单时间秒数不对
	DC_WHITE_LIST_TIME_START_THAN_END = 1125, //白名单时间开始时间大于结束时间
	DC_WHITE_LIST_EXPORT_CSV_READ_FAIL = 1126, //白名单导出CSV格式读失败
	DC_WHITE_LIST_EXPORT_CSV_WRITE_FAIL = 1127, //白名单导出CSV格式写失败

	//上传
	DC_UPLOAD_DATA_SERVER_ALLOC_FAIL = 1200, //上传服务创建失败
	DC_UPLOAD_UNABLE_TO_OPEN_FILE = 1201, //上传文件不能访问
	DC_UPLOAD_SOCKET_CREATE_FAIL = 1202, //上传服务创建socket失败
	DC_UPLOAD_CONNECT_CAMERA_FAIL = 1203, //上传服务连接相机失败
	DC_UPLOAD_READ_FILE_FAIL = 1204, //上传文件读取失败
	DC_UPLOAD_SEND_FILE_NO_ALL = 1205, //上传文件发送不完整

	DC_UPLOAD_DATA_SERVER_ALLOC_FAIL_OLD = 1220, //上传服务创建失败
	DC_UPLOAD_DATA_CREATE_THREAD_FAIL_OLD = 1221, //上传服务创建线程失败

	//下载
	DC_DOWNLOAD_DATA_SERVER_ALLOC_FAIL = 1250, //下载服务创建失败
	DC_DOWNLOAD_SOCKET_CREATE_FAIL = 1251, //下载服务创建socket失败
	DC_DOWNLOAD_CONNECT_CAMERA_FAIL = 1252, //下载服务连接相机失败
	DC_DOWNLOAD_CREATE_FILE_FAIL = 1253, //下载服务创建文件失败
	DC_DOWNLOAD_RECV_DATA_FAIL = 1254, //下载服务接收数据失败

	//获取本地端口
	DC_GET_PORT_SOCKET_ERROR = 1300, //获取本地端口socket错误
	DC_GET_PORT_GET_LOCAL_IP_FAIL = 1301, //获取本地端口获取本地IP失败
	DC_GET_PORT_FAIL = 1302, //获取本地端口失败

	//升级
	DC_UPDATE_FILE_TYPE_ERROR = 1400, //升级文件类型不对
	
}E_ReturnCode;


typedef struct 
{
	unsigned short usFileType;
	unsigned short usServerPort;
	char aucServerIp[32];
	char aucFileName[128];
	unsigned int  uiFileSize;
}T_FileUpdateSetup;

typedef struct 
{

	unsigned char ucLprMode;  /* 0：黑名单；1：白名单*/
	unsigned char ucReseved;
	unsigned short usServerPort;
	char aucServerIp[32];
}T_ExportBlackWhiteList;

typedef enum 
{
	WHITE_LIST_NEW_SEND,//重新发送
	WHITE_LIST_ADD_SEND,//续传
	WHITE_LIST_DEL_SEND,//删除
	WHITE_LIST_MAX
}E_WhiteListSendMode;

typedef enum
{
	BLACK_LIST,//白名单
	WHITE_LIST//黑名单
}E_ListMode;
typedef enum
{
	CODE_IN_UTF8,//UTF-8编码
	CODE_IN_GB2312//GB2312编码
}E_CodeMode;

typedef struct 
{
	unsigned char ucLprMode;  /* E_ListMode*/
	unsigned char ucLprCode;      /* E_CodeMode*/
	unsigned short usServerPort;
	unsigned char ucLprnew; /*E_WhiteListSendMode；*/
	unsigned char aucReseved[3];
	char aucServerIp[32];
	char aucFileName[128];
	unsigned int  uiFileSize;
}T_ImportBlackWhiteList;


/* 磁盘分区显示*/
typedef struct
{
	unsigned int	uiSizeM;							/* 分区大小，以MByte为单位*/
	unsigned int	uiUsedM;							/* 已使用大小，以MByte为单位*/
}T_PartitionInfo;

typedef struct
{
	unsigned char		ucPartitionCnt;
	unsigned char		aucReserved[3];
	T_PartitionInfo atPartition[MAX_PARTITION_COUNT];
}T_HardDiskInfo;

typedef enum
{
	LED_SCREEN_I = 0,
	LED_SCREEN_II,
	LED_SCREEN_OFFLINE_I,      
	LED_SCREEN_OFFLINE_II,   
	LED_SCREEN_III,             
	LED_SCREEN_OFFLINE_III,
	LED_SCREEN_IV,
	LED_SCREEN_V,
	LED_SCREEN_VI,
	LED_SCREEN_VII,
	LED_SCREEN_VIII,
	LED_SCREEN_IX,
	LED_SCREEN_X,
	LED_SCREEN_XI,
	LED_SCREEN_XII,
	LED_SCREEN_XIII,
	LED_SCREEN_XIV, 
	LED_SCREEN_XV, 
	LED_SCREEN_XVI, 
	LED_SCREEN_XVII, 
	LED_SCREEN_XVIII, 
	LED_SCREEN_XIX, 
	LED_SCREEN_XX,
	LED_SCREEN_XXI,
	LED_SCREEN_XXII,
	LED_SCREEN_XXIII,
	LED_SCREEN_XXIV,
	LED_SCREEN_XXV,
	LED_SCREEN_26,
	LED_SCREEN_27,
	LED_SCREEN_28,
	LED_SCREEN_29,
	LED_SCREEN_30,
	LED_SCREEN_31,
	LED_SCREEN_32,
	LED_SCREEN_33,
	LED_SCREEN_34,
	LED_SCREEN_35,
	LED_SCREEN_36,
	LED_SCREEN_37,
	LED_SCREEN_38,
	LED_SCREEN_39,
	LED_SCREEN_40,
	LED_SCREEN_MAX
}E_LedScreenType;
typedef enum 
{ 
	LS_MODE_UNKNOW = 0, 
	LS_MODE_OFFLINE,	 /*脱机使能*/ 
	LS_MODE_ENABLE,	 /*使能，不分区联机、脱机*/ 
	LS_MODE_DISABLE,	 /*不使能*/ 
	LS_MODE_MAX 
}E_LedScreenMode; 
typedef struct
{
	unsigned int	uiInterval;//抬闸脉冲时长ms	
	unsigned char   ucLed;//E_LedScreenType
	unsigned char   ucLedScreenMode;//E_LedScreenMode
	unsigned short	usDownInterval;//落闸脉冲时长ms
}T_ParkSetup;
typedef struct
{
	unsigned char		ucPartitionNum;
}T_HardDiskNum;/*格式化硬盘选择分区*/

typedef struct
{
	unsigned char ucTransProt;	/* E_TransmitProtocol*/
	unsigned char szReserved[3];
}T_TransProt;

/*日志级别*/
typedef enum
{
	LOG_LEVEL_INFO_MAX = 0,
	LOG_LEVEL_INFO_MID,
	LOG_LEVEL_INFO_MIN,
}E_LogLevelInfo;

typedef enum 
{ 
	WEEK_DAY_EACH =0, /*每天*/ 
	WEEK_DAY_ZERO,  /*星期天*/
	WEEK_DAY_ONE,   /*星期一*/
	WEEK_DAY_TWO, 
	WEEK_DAY_THREE, 
	WEEK_DAY_FOUR, 
	WEEK_DAY_FIVE, 
	WEEK_DAY_SIX, 
	WEEK_DAY_ALL, 
}E_WeekDay; 

/*定时重启*/ 
typedef struct 
{ 
	unsigned char ucLogLevel; /*E_LogLevelInfo*/ 
	unsigned char ucAutoRebootEn; 
	unsigned char ucDayOfWeek; /*E_WeekDay*/ 
	unsigned char ucReserved; 
	unsigned int uiAutoRebootTime; 
}T_TimeReboot;

typedef struct
{
	unsigned short usFileType;//业务是0；内核是2；文件系统是3；详见E_UpgradeType
	char aucFilePath[256];
}T_UpdateSetup;

typedef struct
{
	char aucFilePath[256];
}T_ImportConfigSetup;

typedef struct
{
	char aucFilePath[256];
}T_ExportConfigSetup;

typedef struct 
{
	char  szFileName[256];
}T_FileName;

/* 软件升级类型*/
typedef enum
{
	UPGRADE_TYPE_APP = 0,
	UPGRADE_TYPE_APP_FORCE = 1,  /* 应用软件强制升级*/
	UPGRADE_TYPE_KERNEL = 2,
	UPGRADE_TYPE_FS = 3,
	UPGRADE_TYPE_WEB = 4,
	UPGRADE_TYPE_DSP = 5,
	UPGRADE_TYPE_LOGO = 6,
	UPGRADE_TYPE_CONFIG = 7, /* 导入配置文件*/
	UPGRADE_TYPE_LPR = 8, /* 导入白名单*/
	UPGRADE_TYPE_PRESENT_VEH = 9,
	UPGRADE_TYPE_OFFLINE_DATA = 10, /* 无图脱机数据*/
	UPGRADE_TYPE_OFFLINE_PAY = 11,  /* 无图脱机收费数据*/
	UPGRADE_TYPE_RE_PLATE = 12,  /* 车牌后处理规则*/
	UPGRADE_TYPE_IPC_LOGFILE = 13,  /* log日志*/
	UPGRADE_TYPE_ALL
}E_UpgradeType;

typedef struct 
{
	unsigned short usFileType;
	unsigned short usServerPort;
	char aucServerIp[32];
	char aucFileName[256];
	unsigned int  uiFileSize;
	unsigned char acFileMd5[16];
	unsigned char ucFileCode;/* 0：utf-8字符编码；1：gb2312字符编码*/
	unsigned char ucFileOpt; /*0： 全新内容；1：续传内容；2:删除内容；*/
	unsigned char aucReserved[14];  
}T_FileServerSetup;

typedef struct 
{
	unsigned short usFileType;
	unsigned short usServerPort;
	char aucServerIp[32];
	char aucFileName[128];
	unsigned int  uiFileSize;
	unsigned char acFileMd5[16];
	unsigned char ucFileCode;/* 0：utf-8字符编码；1：gb2312字符编码*/
	unsigned char ucFileOpt; /*0： 全新内容；1：续传内容；2:删除内容；*/
	unsigned char aucReserved[14];  
}T_FileServerSetupCam;

#ifndef _T_NetSetup
#define _T_NetSetup
typedef struct
{
	unsigned char	ucEth;				/* 以太网口编号,目前只支持0*/
	unsigned char	aucReserved[3];
	unsigned int	uiIPAddress;		/*192.168.0.148 对应16进制 0xc0a80094*/
	unsigned int	uiMaskAddress;
	unsigned int	uiGatewayAddress;
	unsigned int	uiDNS1;
	unsigned int	uiDNS2;
	char	szHostName[MAX_HOST_LEN];
}T_NetSetup;
#endif	
/* 组播配置*/
typedef struct
{
	unsigned char	ucEnabled;
	unsigned char	aucReserved;
	unsigned short	usOfflinePort;
	unsigned int	uiIP;
	unsigned short	usMainVidPort;
	unsigned short	usViceVidPort;
	unsigned short	usMainAudPort;
	unsigned short	usViceAudPort;
}T_MulticastSetup;

/* MAC地址配置*/
#ifndef _T_MACSETUP
#define _T_MACSETUP
typedef struct
{
	unsigned char	ucEth;				/* 以太网口编号,目前只支持0*/
	unsigned char	aucReserved[3];
	unsigned char	aucMACAddresss[6];
}T_MACSetup;
#endif

typedef struct
{
	 unsigned char   ucEnable;
	 unsigned char   ucReserved;  
	 unsigned short  usPort;
	 char			 szIpAddr[16];
}T_AssistantIpnc;  /*辅助相机配置*/

typedef struct
{
	unsigned char	ucEnable;
	unsigned char	ucCharCode;
	unsigned short 	usPort;
	char			szIpAddr[16];
}T_Messenger;

typedef struct 
{ 
	unsigned char ucCusNo; /*客户编号，0表示未知*/ 
	unsigned char aucReserved[3]; 
}T_CustomerNo;

typedef struct
{
	unsigned char	ucEnable;      /*定时使能*/
	unsigned char	ucTimeLen;   /*执行时长，单位:秒*/
	unsigned char	aucReserved[2];
	unsigned int	uiAutoStartTime; /*雨刷定时启动时间0x00HHMMSS 低字节为秒*/
}T_WiperTiming;

typedef  struct  
{
	unsigned short x1;                         //矩形左上角x坐标
	unsigned short y1;                         //矩形左上角y坐标
	unsigned short x2;			       //矩形右下角x坐标
	unsigned short y2;                         //矩形右下角y坐标
}T_Ave_Rect;

//标示物形状，距离
typedef  struct  
{
	unsigned short	uwDist;                  //预设标示物距离摄像机水平距离
	unsigned short	uwResrved;
	T_Ave_Rect		tAveRect;                //预设标示物矩形坐标
}T_Ave_Par;

//能见度配置信息
typedef  struct  
{
	unsigned char   ucBlureTh;             //模糊度阈值范围【0,100】,越大越模糊
	unsigned char	ucRegNum;		  //预设标示物数目-最多8个
	unsigned short	uwResrved;
	T_Ave_Par      tAvePar[AVE_REG_NUM];  //预设标示物矩形坐标
}T_Ave_Config;

typedef struct
{
	unsigned short	   uwDistVmet;//单位：米
	unsigned short	   uwResrved;
}T_Ave_Result;

typedef enum
{
	PARK_OFFLINE_STATE,//脱机状态
	PARK_ONLINE_STATE,//联机状态
	PARK_MAX_STATE
}E_ParkState;
typedef struct
{
	unsigned char	ucState;
	unsigned char	aucReserved[3];
}T_ParkRealTimeState;//相机与岗亭连接的实时状态，是联机还是脱机

typedef struct 
{
	unsigned char  	ucState; /*0:关1:开*/
	unsigned char	aucReserved[3]; 
}T_WiperManual;  /*雨刷手动控制*/

typedef struct
{
	unsigned short usSigCtrlSerPort;
	unsigned char  aucReserved[2];
}T_SigControlPort;

 /* 服务端口配置 */
typedef struct
{
	unsigned short	usHttpPort;
	unsigned short	usRtspPort;
}T_ServicePortSetup;

 /* 图像编码参数 */
typedef struct
{
	unsigned char	ucMode;			/* 编码模式，目前仅支持JPEG；*/
	unsigned char	ucFmt;			/* 编码格式，分辨率相关 0 1080p(1920*1080)  1 720p(1280*720) 2 4cif(720*576) 3 cif(352*288)*/
	unsigned char	ucQuality;		/* 编码质量*/
	unsigned char	ucPeriod;		/* 编码周期，1～7秒/张*/
}T_ImageCodec;

/* 操作模式*/
typedef enum
{
	OPERATE_MODE_MANUAL = 1, 				/* 手动模式*/
	OPERATE_MODE_AUTO,	            /* 自动模式*/
	OPERATE_MODE_ALL
}E_OperateMode;


/* 视频编码参数*/
typedef struct
{
	unsigned char	ucMode;			/* 编码模式，目前仅支持H264；*/
	unsigned char	ucFmt;			/* 编码格式，分辨率相关*/
	unsigned char	ucFps;			/* 帧频， PAL制1～25可选；NTSC制，当分辨率为1080P时，1～25可选，其它情况1～30可选；*/
	unsigned char	ucRateControl; 	/* 码率控制，0->VBR(可变码率)，1->CBR(固定码率)*/
	unsigned int	uiRate;			/* 码率，384000～16000000 bps*/
	unsigned char	ucIFPeriod;		/* I帧间隔，1～5 秒；*/
	unsigned char	ucEnabled;		/*编码是否启动，辅视频生效*/
	unsigned char   ucIncSnapFrame; /*包含抓拍帧使能*/      
	unsigned char	ucReserved;
}T_VideoCodec;

typedef enum
{
	BAUD_RATE_1200,
	BAUD_RATE_2400,
	BAUD_RATE_4800,
	BAUD_RATE_9600,
	BAUD_RATE_19200,
	BAUD_RATE_38400,
	BAUD_RATE_57600,
	BAUD_RATE_115200,
	BAUD_RATE_ALL
}E_BaudRate;

typedef enum
{
	RS485_FUNCTION_PASS = 0,
	RS485_FUNCTION_SCREEN,
	RS485_FUNCTION_MAX,
}E_RS485Function;
typedef enum
{
	CHECK_TYPE_NONE,	/* 无校验*/
	CHECK_TYPE_ODD,		/* 奇校验*/
	CHECK_TYPE_EVEN,	/* 偶校验*/
	CHECK_TYPE_FLAG,	/* 标志校验*/
	CHECK_TYPE_EMPTY,	/* 空校验*/
	CHECK_TYPE_ALL
}E_CheckType;
/* RS485配置*/
typedef struct
{
	unsigned char   ucIndex;
	unsigned char   ucFunction;         /*E_RS485Function*/
	unsigned char	ucBaudRate;			/* E_BaudRate*/
	unsigned char	ucDataBits;			/* 数据位，5～8；*/
	unsigned char	ucStopBits;			/* 停止位，0～2；*/
	unsigned char	ucCheckOut;			/* E_CheckType*/
	unsigned char   ucType;             /* 0:自动,1:485,2:232 */
	unsigned char   ucReserved;
}T_RS485Setup;

 /*背光补偿*/
typedef struct
{
	unsigned char ucEnable;
	unsigned char aucReservel[3];
}T_ImageEv; 

typedef enum
{
	KAKOU = 0,          /*卡口*/
	RUN_REDLIGHT,   	/*闯红灯*/
	OVER_SPEED,     	/*超速*/
	REVERSE,        	/*逆行*/
	TRAFFIC_BAN,    	/*禁行，卡口使用*/
	CROSS_LINE,     	/*越线*/
	ILLEGAL_STOP,    	/*违停*/
	ILLEGAL_OCCUP,   	/*专用道*/
	ILLEGAL_PRESS_LINE, /*压线*/
	ILLEGAL_NOLANE_RUN, /*不按导向行驶*/
	SNAPSHOT_TYPE_ALL,  /*有效类型*/
	ILLEGAL_PREDICT,  	/*违法预言*/
	NET_SNAP = 0xFF,
}E_SnapshotType;

typedef enum
{
	MERGE_TYPE_NONE,
	MERGE_TYPE_H,					/* 横向合并*/
	MERGE_TYPE_V,					/* 纵向合并*/
	MERGE_TYPE_H_ADAPT,				/* 数码+视频(上下布局)*/
	MERGE_TYPE_V_ADAPT,				/* 数码+视频(左右布局)*/
	MERGE_TYPE_FOUR,				/* 田字形*/
	MERGE_TYPE_SIX,					/* 田字形，6张*/
	MERGE_TYPE_H_SMALL,				/* 横向合并缩放*/
	MERGE_TYPE_V_SMALL,				/* 纵向合并缩放*/
	MERGE_TYPE_FOUR_SMALL,			/* 田字形缩放*/
	MERGE_TYPE_ALL
}E_ImageMergType;


/* 事件抓拍参数*/
typedef struct
{
	unsigned char	ucEventCaptureType;   /* 事件抓拍类型 E_SnapshotType 0(卡口抓拍)1（闯红灯抓拍）3(逆行)4（禁行抓拍）5（越线抓拍）6（违停抓拍）8（压线抓拍）9(不按导向行驶抓拍)*/
	unsigned char	ucPicSnapshotNum;     /*抓拍张数*/
	unsigned char	szReserver[2];
	/* -1：进线圈1，-2：进线圈2：-3：出线圈1，-4：出线圈2，
		-5：进检测线 对于视频检测，表示车头碰到检测线了；若为雷达检测，车辆进入雷达检测域，被雷达设备发现
		-6：出检测线 对于视频检测，表示车尾离开检测线了；若为雷达检测，这个选项无效，
		其它大于0的值，表示延时抓拍，该值表示延时时间， 0～300ms
	*/
	int	aiGetPicPosition[3];
	unsigned char	ucPicMergeType;				/* 图片合成类型，0：不合成，1：横向合成，2：纵向合成，3：视频+数码（上下布局），4：视频+数码（左右布局），5：田字风格*/
	unsigned char	ucMainPicItem;				/* 大图序号，当图片类型为3、4时有效；*/
	unsigned char	ucRecordEnable;				/* 是否支持违法录像*/
	unsigned char	ucRecordTime;				/* 录像时长，4～7秒*/
	unsigned char 	ucPreRecordTime;			/*预录时长，0～3秒，默认为2s*/
	unsigned char 	ucReserved;					/*保留字段*/
	unsigned short  usIllegalCode;				/*国标违章代码*/
}T_EventCapturePara;

/*时段*/
typedef struct
{
	unsigned char ucStartHour;
	unsigned char ucStartMinute;
	unsigned char ucEndHour;
	unsigned char ucEndMinute; 	
}T_TimeBucket;

typedef struct
{
	unsigned char	ucEnabled;
	unsigned char	aucReserved[3];
	T_TimeBucket	tTimeBucket;
}T_EnableTimeBucket;


/* 闪光灯配置参数*/
typedef struct
{
	unsigned char		ucFlashLightMode;		/* 单灯、多灯模式，0:单灯*/
	unsigned char		ucNormalWorkMode;		/*正常工作模式E_LightWorkMode*/
	unsigned char		ucIllegalWorkMode;		/*违法工作模式E_LightWorkMode*/
	unsigned char		ucOpenBrightnessTH;		/* 自动模式下，闪光灯开启的亮度阈值；*/
	T_EnableTimeBucket	atFourceFlashTime[2];	/*强制闪光时段*/
}T_FlashLightSetup;

/* 频闪灯配置参数*/
typedef struct
{
	unsigned char	ucNormalWorkMode;			/* 正常补光模式E_LightWorkMode*/
	unsigned char	ucCombinationalWorkMode;	/* 组合补光模式，是指在闪光灯开启的情况下的补光模式E_LightWorkMode*/
	unsigned char	ucOpenBrightnessTH;			/* 自动模式下，频闪灯开启的亮度阈值；*/
	unsigned char	ucReserved;
}T_LedLightBasicSetup;


typedef enum
{
	STRAIGHT_LANE = 0,
	LEFT_TURN_LANE,
	RIGHT_TURN_LANE,
	LEFT_STRAIGHT_LANE,
	RIGHT_STRAIGHT_LANE,
	LEFT_RIGHT_LANE,
	LEFT_STRAIGHT_RIGHT_LANE,  /*20140311 add by zhuby*/
	LANE_TYPE_ALL,
}E_LaneType;

typedef enum
{
	FT_PICTURE_KK = 0,   /*卡口图片*/
	FT_PICTURE_CHD,      /*闯红灯*/
	FT_PICTURE_CS,       /*超速*/
	FT_PICTURE_NX,       /*逆行*/
	FT_PICTURE_JX,       /*禁行*/
	FT_PICTURE_YX,       /*越线*/
	FT_PICTURE_WT,       /*违停*/
	FT_PICTURE_ZD,       /*占道*/
	FT_PICTURE_PL,       /*压线*/
	FT_PICTURE_NRW,      /*不按车道行驶*/
	FT_EVENT_STAT,       /*交通事件统计*/
	FT_LOG_FILE,		 /*报警*/
	FT_AUTO_UPGRADE,     /*自动升级*/
	FT_ALL,
}E_FileType;

typedef struct
{	
	unsigned char	ucEnabled;   		/*时间分段启用*/
	unsigned char	ucWorkDayEnable;	/*工作日启用*/
	unsigned char	ucWeekEndEnable;	/*周末启用*/
	unsigned char	ucReserved1;
	T_TimeBucket	tTimeBucket;
	unsigned char	ucRunRedLightSnap;  /*闯红灯抓拍*/
	unsigned char	ucKaKouSnap;        /*卡口抓拍*/    
	unsigned char	ucReverseSnap;      /*逆行抓拍*/
	unsigned char	ucCrossLineSnap;    /*越线抓拍*/
	unsigned char	ucOverSpeedSnap;	/* 超速抓拍启用*/
	unsigned char	aucReserved2[3];
}T_EventCapTimeBasicSetup;

typedef enum
{
	PLATE_DIRECTION_TAIL = 0,  /*车尾车牌*/
	PLATE_DIRECTION_HEAD,      /*车头车牌*/
	PLATE_DIRECTION_ALL,
}E_PlateDirection;

typedef struct
{
	unsigned char ucEnabled;			/**/
	unsigned char ucLaneNo;				/*车道号*/
	unsigned char ucLaneIndex;
	unsigned char ucLaneType;			/*车道类型E_LaneType*/
	unsigned char ucRedLightSnapTestEn;	/*闯红灯抓拍测试启用*/
	unsigned char ucTimeSegEnable;  	/*分时段*/
	
	unsigned char ucLaneDir; 			/*E_PlateDirection*/
	
	/*最高限速*/
	unsigned char ucMaxSpeed;			/*单位：KM/H 电子警察内部使用，与web交互作为保留字段*/
	
	T_EventCapTimeBasicSetup atCaptureTime[MAX_TIMEBUCKET];/*抓拍时段*/
}T_RoadLaneBasicSetup;

typedef struct
{	
	unsigned char ucEnabled;   		  /*时间分段启用*/
    unsigned char ucWorkDayEnable;    /*工作日启用*/
	unsigned char ucWeekEndEnable;	  /*周末启用*/
	unsigned char uacReserved1;
	T_TimeBucket  tTimeBucket;
	unsigned char ucPressLineSnap;    /*压线抓拍*/
	unsigned char ucNoAccordRoadWay;  /*不按车道行驶*/
	unsigned char ucTrafficBanSnap;   /*禁行抓拍*/ 
	unsigned char ucIllegeStopSnap;   /*违停抓拍*/ 
	unsigned char ucSpecialRoadSnap;  /*专用道抓拍*/
	unsigned char aucReserved[3];
}T_EventCapTimeExtendSetup;

/* 车道扩展参数配置*/
typedef struct
{
	unsigned char	ucLaneIndex;
	unsigned char	ucTrafficStaEn;			/*是否启用交通事件统计*/
	unsigned char	ucOccupRatioEventEn;	/*是否启用占有率报警*/
	unsigned char	ucVehicleStopEventEn;	/*是否启用停驶报警*/
	unsigned char	ucTrafficJamEventEn;	/*是否启用交通拥堵报警*/
	unsigned char	ucSpecialRoadType;
	unsigned char	ucTimeSegEnable;
	unsigned char	ucVehStatTime;			/*交通流量统计周期，单位为分钟*/
	T_EventCapTimeExtendSetup  atCaptureTime[EVENT_CAP_TIMEBUCEKT_CNT];/*抓拍时段*/
}T_RoadLaneExtendSetup;

/* 限速参数配置*/
typedef struct
{
	unsigned char	ucLaneIndex;
	char			cLoopDefaultSpeedRatio;		/*线圈默认速度校正*/
	char			cLoopHightSpeedRatio;		/*线圈高速速度校正*/
	unsigned char	ucLoopHightSpeedCaliLimit;	/*线圈高速校正速度值*/
	char			cRadarDefaultSpeedRatio;	/*雷达默认速度校正*/
	char			cRadarHightSpeedRatio;		/*雷达高速速度校正*/
	unsigned char	ucRadarHightSpeedCaliLimit;	/*雷达高速校正速度值*/
	char			cVideoDefaultSpeedRatio;	/*视频默认速度校正*/
	char			cVideoHightSpeedRatio;		/*视频高速速度校正*/
	unsigned char	ucVideoHightSpeedCaliLimit;	/*视频高速校正速度值*/
	unsigned char	ucHighSpeedLimit;			/*限制最高速度*/
	unsigned char	ucLowSpeedLimit;			/*限制最低速度*/
	unsigned char	ucSpeedLimitClassifyEn;		/*按车型限速启用*/
	unsigned char	ucCarHighSpeedLimit;		/*小型车最高速度*/
	unsigned char	ucCarLowSpeedLimit;			/*小型车最低速度*/
	unsigned char	ucTruckHighSpeedLimit;		/*大型车最高速度*/
	unsigned char	ucTruckLowSpeedLimit;		/*大型车最低速度*/
	unsigned char	szReserved[3];
}T_SpeedCorrAndLimitSetup;

typedef struct
{
	unsigned char	ucPlateRealTimeShowEn;	    /* modify by zhuby 20160712:显示实时车牌，默认关闭*/
	unsigned char	ucRecRegShowEn;			    /* modify by zhuby 20160712:显示车牌识别区域，默认打开*/
	unsigned char	ucArmyLprPrior;			    /* 军牌优先*/
	unsigned char	ucNoPlateVehicleSnapEn;		/* 无牌车抓拍标识，0：不抓拍 1：表示抓拍*/
	unsigned char	ucCpHightTI;				/* 同一辆车抓拍间隔高字节*/
	unsigned char	ucLocalCity; 				/*车牌的第二个字符，'A'~'Z'*/
	unsigned char	ucPlateDirection;           /*车牌方向E_PlateDirection*/   
	unsigned char	ucCpTimeInterval;           // 同一辆车抓拍间隔  低字节
	unsigned int	uiPlateDefaultWord;			/* 默认省份，采用UTF-8编码*/

	unsigned short	usMinPlateW;				/*车牌识别最小宽度,单位:像素*/
	unsigned short	usMaxPlateW;				/*车牌识别最大宽度，单位:像素*/
	unsigned char	ucInvalidLprLevel;			/*伪车牌处理等级*/
	unsigned char	ucVehicleInterval;			/*前后车抓拍间隔，单位:秒*/
	unsigned char	ucPolicePlate;				/*武警车牌汉字输出，0: 不输出1:输出*/
	unsigned char	ucPlateFeature;				/*车牌特写*/
}T_VehicleVAFunSetup;

typedef struct
{
	unsigned char	ucPlateRealTimeShowEn;				/* modify by zhuby 20160712:显示实时车牌，默认关闭*/
	unsigned char	ucRecRegShowEn;						/* modify by zhuby 20160712:显示车牌识别区域，默认打开*/
	unsigned char	ucVehicleColorRecogEn;		/* 车身颜色识别使能*/
	unsigned char	ucNoPlateVehicleSnapEn;		/* 无牌车抓拍标识，0：不抓拍 1：表示抓拍*/
	unsigned char	ucCpHightTI;				/* 同一辆车抓拍间隔高字节*/
	unsigned char	ucLocalCity; 					/*车牌的第二个字符，'A'~'Z'*/
	unsigned char	ucPlateDirection;           		/*车牌方向E_PlateDirection*/   
	unsigned char	ucCpTimeInterval;           		// 同一辆车抓拍间隔  低字节
	unsigned int	uiPlateDefaultWord;			/* 默认省份，采用UTF-8编码*/
	unsigned short	usMinPlateW;				/*车牌识别最小宽度,单位:像素*/
	unsigned short	usMaxPlateW;				/*车牌识别最大宽度，单位:像素*/
	unsigned char	ucDoubleYellowPlate;			/*双层黄牌识别，1：识别 0：不识别*/
	unsigned char	ucVehicleInterval;			/*前后车抓拍间隔，单位:秒*/
	unsigned char	ucPolicePlate;				/*武警车牌汉字输出，0: 不输出1:输出*/
	unsigned char	ucPlateFeature;				/*车牌特写*/

	unsigned char	ucLprHead;				/* 识别模式,TRUE车头模式,FALSE车尾模式(车头模式:单、双层黄牌均识别，车尾模式:只是别双层黄牌)*/
	unsigned char	ucZoomSlop;				/* 缩放图像是否进行倾斜纠正*/
	unsigned char	ucCpMode;				/* 抓拍模式 0 : 碰触发线抓拍  1: 进入线圈,锁定抓拍*/
	unsigned char	aucReserved[29];
}T_VehicleVAFunSetupEX;


typedef enum
{
	INVALID_LPR_LEVEL1 = 1, /* 车牌号码全为7,Z,2,1,T,L且同一字符数大于等于4*/
	INVALID_LPR_LEVEL2, /* 黄牌分数小于88*/
	INVALID_LPR_LEVEL3, /* 首汉字小于50分且车牌分数小于88*/
	INVALID_LPR_MAX,
}E_INVALID_LPR_LEVEL;

typedef enum
{
	INVALID_LPR_WHITE = 0x01, /*白牌*/
	INVALID_LPR_BLUE = 0x02,   /*蓝牌*/
	INVALID_LPR_YELLOW = 0x04, /*黄牌*/
	INVALID_LPR_BLACK = 0x08, /*黑牌*/     	
}E_INVALID_LPR_COLOR;

typedef struct
{
	unsigned char	ucLevel; // E_INVALID_LPR_LEVEL 处理等级
	unsigned short	usColorBit;//针对处理的车牌颜色E_INVALID_LPR_COLOR
	unsigned char Reserved[13]; //保留位
}T_InvalidLprLevel;

typedef struct
{
	unsigned char ucTime;
	unsigned char ucAddress;
	unsigned char ucDevNo;
	unsigned char ucRecordNo;		/*备案号*/
	unsigned char ucIllegalCode;
	unsigned char ucPicType;
	unsigned char ucRoadNo;
	unsigned char ucVehiclePlate;
	unsigned char ucVehicleSize;
	unsigned char ucVehicleSpeed;
	unsigned char ucVehicleFace;
	unsigned char ucWaterMark;
	unsigned char ucOverlayType;	/* 图片的字幕叠加风格，0：单行叠加，1：多行叠加*/
	unsigned char ucVehicleColor;
	unsigned char ucPlateRealPixel;  /* 是否叠加车牌实际像素*/
	unsigned char ucReserved; 
}T_PicOsdSetup;

typedef enum
{
	DIR_STRUCT_DEV_DATE,			/* 按设备编号+日期+时间组织目录*/
	DIR_STRUCT_DEV_DIR_LANE_DATE,	/* 按设备编号+方向+车道号+日期+时间组织目录*/
	DIR_STRUCT_ALL
}E_DirStruct;

/* SD卡存储策略配置*/
typedef enum
{
	SD_WRITE_TYPE_ROLL,
	SD_WRITE_TYPE_STOP,
	SD_WRITE_TYPE_ALL
}E_FULL_WRITE_TYPE;

/* 存储配置*/
typedef struct
{
	unsigned char	ucEnable;					/* 本地存储使能*/
	unsigned char	ucDirStuct;					/* 目录结构，E_DirStruct*/
	unsigned char	ucWritePolicy;				/* 磁盘满时的处理策略，E_FULL_WRITE_TYPE*/
	unsigned char	ucBackupPolicyNormal;		/* 卡口图片的备份策略，0：不备份，1：备份*/
	unsigned char	ucBackupPolicyIllegal;		/* 违法图片的备份策略，0：不备份，1：备份*/
	unsigned char	ucBackupPolicyIRecord;		/* 违法录像是否保存0:不备份，1:备份*/
	unsigned char	ucIllegalRecordEn;			/* 违法录像使能标志*/
	unsigned char	ucIllegalRecordTime;		/* 违法录像录制时长*/
	unsigned char	ucIllegalRecordReadyTime; 	/* 预录时长*/

	unsigned char	ucRealTimeRecordEn;			/* 实时录像是否启动*/
	unsigned char	ucRealTimeRecordDuration;	/* 实时录像时长,分钟(1~120)*/
	unsigned char	ucReserved;
}T_StorageSetup;

typedef struct
{
	unsigned char	ucEnable;
	unsigned char	ucMode;			/* 演示模式，0: 流媒体演示, 1:本地文件演示*/
	unsigned char	aucReserved[2];
	char			szUrl[256];
}T_DemoSetup;
 

typedef enum
{
	SUBDIR_TYPE_ROOT,   					/*使用跟目录*/
	SUBDIR_TYPE_DATE,						/*使用日期分目录*/
	SUBDIR_TYPE_DEVNUM,						/*设备编号分目录*/
	SUBDIR_TYPE_DEVNUM_DATE,				/*设备编号+ 日期目录*/
	SUBDIR_TYPE_DEVNUM_DATE_HOUR,			/*设备编号+ 日期+ 小时目录*/
	SUBDIR_TYPE_DEVNUM_ROAD_DATE_HOUR,		/*设备编号+车道+日期+小时目录*/
	SUBDIR_TYPE_DEVNUM_DIR_ROAD_DATE_HOUR,	/*设备编号+ 方向+ 车道+ 日期+小时目录*/
	SUBDIR_TYPE_ALL
}E_SubDirType;

/* FTP配置*/
typedef struct
{
	unsigned char	ucEnabled;
	unsigned char	ucSubDirCreateType;   /* 子目录创建方式E_SubDirType*/
	unsigned short	usServerPort;
	char			szServerName[MAX_SERVER_NAME_LEN];
	char			szUser[MAX_USER_PWD_LEN];
	char			szPwd[MAX_USER_PWD_LEN]; 
	unsigned char	ucTransMode; 		/* passive or not 0:passive 1:active*/
	unsigned char	ucTransFileType; 	/*  whick kind of file we want to transfer. E_FileType*/
	unsigned char	ucKeepBackup; 		/*  whether to keep the file in local after it has been upload.*/
	unsigned char	ucTransPeriod;		/*  unit is minute*/
	unsigned char	ucCharacterSet; 	/*E_CharSet*/
	unsigned char	ucReserved;
	char			szFTPRootPath[MAX_FILE_NAME_LEN];
}T_FTPSetup;

/* 设备信息配置*/
typedef struct
{
	char			szDistrictNumber[16];	/* 地区编号*/
	char			szProjectName[64];		/* 项目名称*/
	char			szDevNumber[16];		/* 设备号，用户定义；*/
	char			szRoadName[64];			/* 出入口名称*/
	char			szRoadNumber[16];		/* 出入口编号*/
	unsigned char	ucDirection;			/* 方向:1入口，2：出口*/
	unsigned char	aucReserved[3];		  	/* 保留字段*/
	char			szLicenseNum[64];  		/* license号*/
	char			szRecordNum[32];        /*备案号*/
}T_DevSetup;

typedef enum
{
	SIMPLE_LIGHT,
	LANE_LIGHT,
	COMPLEX_LIGHT
}E_SignalLightType;

typedef enum
{
	NONE_MODE,
	ALL_RED_MODE,
	LEFT_WAIT_MODE
}E_SignalLightMode;

/*信号灯检测源*/
typedef enum
{
	CHECK_MODE_RS485 = 0,
	CHECK_MODE_VIDEO,
}E_SignalLightCheckMode;

/*信号灯参数配置*/
typedef struct 
{
	unsigned char ucCheckSrc;   /*信号灯检测源 E_SignalLightCheckMode*/
	unsigned char ucRedShine;	/*是否红灯闪烁*/
	unsigned char ucMode;		/*0-无/1-全红模式/2-左转待停*/
	unsigned char ucBanRt;		/*红灯是否禁止右转*/

	unsigned char ucType;		/*信号灯类型E_SignalLightType*/
	unsigned char ucLeftDelay;	/*左转延时*/
	unsigned char ucRightDelay;	/*右转延时*/
	unsigned char ucGoStraightDelay;/*直行延时*/
	T_EnableTimeBucket atInvalidTimeBucket[MAX_TIMEBUCKET];/*失效时段*/	
}T_SignalLightSetup;

typedef struct
{
	unsigned short	uwIndex;//小灯序号
	unsigned short	uwX;//
	unsigned short	uwY;//
	unsigned short	uwReserved;
	unsigned char	ucRed;//红
	unsigned char	ucYellow;//黄
	unsigned char	ucGreen;//绿
	unsigned char	ucCountdown;//倒计时
	unsigned char	ucLeft;//左
	unsigned char	ucStraight;//直
	unsigned char	ucRight;//右
	unsigned char	ucSwing;//掉头
} T_LightParm;

typedef struct 
{
	unsigned char	ucRadius;//半径				  单位：像素；		
	unsigned char	ucTrack;//是否跟踪			  1是/0否
	unsigned char	ucBanRight;//是否禁右         1是/0否
	unsigned char	ucBanYellow;//是否抓拍闯黄灯  1是/0否
	unsigned short	uwLightNum;//小灯个数
	unsigned short	uwReserved;
	T_LightParm	tLightParm[9];//小灯信息
}T_SigLightParm;

typedef struct
{
	unsigned short	usYear;
	unsigned char	ucMonth;
	unsigned char	ucDay;
	unsigned char	ucHour;
	unsigned char	ucMinute;
	unsigned char	ucSecond;
	unsigned char	ucDayFmt;
	unsigned char	ucTimeFmt;
	unsigned char	ucTimeZone;
	unsigned char	aucReserved[2];
}T_DCTimeSetup;

/* SNTP配置*/
typedef struct
{
	unsigned char	ucEnabled;
	unsigned char	ucReserved[3];
	 char	szSNTPServer[64];
	unsigned short	usPort;
}T_SNTPSetup;

typedef struct
{
	unsigned char ucEnable;
	unsigned char ucOffset;
	unsigned char szReserved[2];
}T_ACSyncSetup;

/*交流电同步*/
typedef struct
{
	unsigned char ucEnable;
	unsigned char ucOffset;
	unsigned char szReserved[2];
}T_DCAcSyncSetup;

typedef struct
{
	unsigned char	ucIndex;	/* 字幕序号（0-4）；第0路为时间字幕，只需设置是否叠加； */                      
	unsigned char	ucEnabled;		/* 使能标志；*/                                                                 
	unsigned char	ucFontSize;		/* 字体大小；*/                                             
	unsigned char	ucWeekEnabled;	/*星期显示*/                                             
	unsigned int	uiForeColor;		/* 前景色，格式为0x00RRGGBB，*/                             
	unsigned int	uiBackColor;		/* 背景色，格式为0xXXRRGGBB，如果XX不为0，表示不需要背景色；*/
	unsigned short	usPosX;			/* X坐标  */                                                                    
	unsigned short	usPosY;			/* Y坐标  */                                                                    
	unsigned short	ausContent[33];   /* 字幕内容，UNICODE16格式，以0结尾；    */
	unsigned char   ucShowPlrflag;	 /*是否叠加识别车牌结果*/	
	unsigned char   ucReserved;
}T_Subtitle;

typedef struct
{ 
	unsigned char	ucGroupId;                   /* 组ID */
	unsigned char	ucShutterMode;               /* 快门模式 */
	unsigned char	ucGainMode;                  /* 增益模式 */
	unsigned char	ucReserved;					 /*保留字段*/
	unsigned int	uiShutterValue;              /* 快门值 */
	unsigned short	usGainValue;                 /* 增益 */
	unsigned short	usBrightnessTH;              /* 亮度阀值*/
}T_DCSnapParaSetup;

typedef struct 
{
	unsigned char	ucLaneNo;			/*车道编号*/
	unsigned char   ucReserved;
	unsigned short  usReverseCount;  /*反相交通流量*/
	unsigned int	uiDate;
	unsigned int	uiTime;
	unsigned int	uiVehicleNum;		/*车流量*/
	unsigned int	uiAveSpeed;			/*平均车速*/
	unsigned int	uiTimeOccupyRate;	/*时间占有率*/
}T_DCTraStatReport;


typedef struct
{ 
	unsigned char ucShutterMode;                /* 快门模式 */
	unsigned char ucGainMode;                   /* 增益模式 */
	unsigned char szReserved[2]; 				/*保留字段*/
	unsigned int uiShutterValue;				/* 快门值 */
	unsigned short usGainValue;                 /* 增益 */
	unsigned short usBrightnessTH;              /* 亮度的标准参考值 */
}T_VideoParaSetup;

typedef struct
{
	unsigned char	ucMode;			/* 编码模式，目前仅支持H264；*/
	unsigned char	ucFmt;			/* 编码格式，分辨率相关*/
	unsigned char	ucFps;			/* 帧频1<<25*/
	unsigned char	ucRateControl; 	/* 码率控制，0->VBR(可变码率)，1->CBR(固定码率)*/
	unsigned int	uiRate;			/* 码率，384000～16000000 bps*/
	unsigned char	ucIFPeriod;		/* I帧间隔，1～5 秒；*/
	unsigned char	ucEnabled;		/*编码是否启动，辅视频生效*/
	unsigned char   ucIncSnapFrame; /*包含抓拍帧使能*/      
	unsigned char	ucquality;     //ucReserved;//编码质量 0 低  1 中  2 高
}T_VideoCodeSetup;

/*动态视频编码结构体*/
typedef struct
{
	unsigned char   ucEnabled;
	unsigned char   ucReserved;
	unsigned short  usTime;
	unsigned int	uiRate;
}T_DynamicCode;

typedef struct
{
	unsigned short  usHigh;
    unsigned short  usWidth;
	unsigned int	uiVideoFormat;//视频支持的格式，用位值来表示，不同位的值表示如下：0->无效，1->CIF，2->4CIF，3->SXGA，4->720P，5->UXGA，6->1080P，7～30保留，31->全分辨率，根据最大宽度和高度的值得出；
	float   ucMaxFs;
}T_DCSpec;

typedef enum
{
	FILE_DOWNLOAD_TFTP = 0,
	FILE_DOWNLOAD_FTP,
	FILE_DOWNLOAD_ALL,
}E_FileDownloadType;


/*上报版本号*/
typedef struct
{
	char		szKernelVersion[VERSION_NAME_LEN];
	char		szFileSystemVersion[VERSION_NAME_LEN];
	char		szAppVersion[VERSION_NAME_LEN];
	char		szWebVersion[16];
	char		szProtocolVersion[16];
	char		aucReserved[32];
	char		szHardwareVersion[VERSION_NAME_LEN];
	char		szDevType[64];		/* 设备类型描述，出厂时设定；*/
	char		szSerialNum[64];    	/*产品序列号*/
	unsigned int uiDateOfExpiry;		/*产品有效期*/
	char		szDSPVersion[VERSION_NAME_LEN];
}T_QueVersionRsp;

/* 系统状态上报*/
typedef struct
{
	unsigned char	ucLoopStatus;		/* 线圈检测器状态，0：正常，其它异常*/
	unsigned char	ucRadarStatus;		/* 雷达检测器状态，0：正常，其它异常*/
	unsigned char	ucVAStatus;			/* 智能分析模块状态，0：正常，其它异常*/
	unsigned char	ucSSDStatus;		/* 硬盘状态，0：正常，其它异常*/
	unsigned int	uiSSDSize;			/* 硬盘容量，单位GB*/
	unsigned int	uiSSDReserved;		/* 剩余容量，单位GB*/
}T_SysState;

typedef enum
{
	LOOP_DETECT = 0,	/*线圈检测*/
	RADAR_DETECT,		/*雷达检测*/
	VIDEO_DETECT,		/*视频检测*/
	LOOP_VIDEO_DETECT,	/*线圈+视频检测*/
	RADAR_VIDEO_DETECT, /*雷达+视频检测*/
	ALL_DETECT_METHOD
}E_DetectMethod;

/* 检测模式设置*/
typedef struct
{
	unsigned char ucDetectMode;	   /*检测模式E_DetectMethod*/
	unsigned char szReserved[3];   /*保留字段*/
}T_DetectModeSetup;

/* 线圈检测输出信息*/
typedef enum
{
	LEAVE_LOOP, /*出线圈*/
	ENTER_LOOP, /*进线圈*/
}E_LoopInfo;

/*线圈参数配置*/
typedef struct
{
	unsigned char	ucLaneIndex;     /* 该组线圈对应的车道索引号 */
	unsigned char  ucLoopLaneIndex; /*车检器上对应的车道索引，从0开始编号*/
	unsigned char   ucMode;
	unsigned char   szReserved;
	//unsigned char  szReserved[2];    /*保留字段*/
	unsigned short	usLoopWidth;     /*线圈宽度*/
	unsigned short	usLoopInterval;  /*线圈间隔*/
}T_LoopParamSetup;


/*雷达参数配置*/
typedef struct
{
	unsigned char	ucLaneIndex;		/*该组线圈对应的车道索引号*/
    unsigned char  ucRadarLaneIndex;	/*雷达车道索引,从0开始编号*/
	unsigned char  szReserved[2];       /*保留字段*/
	unsigned short	usPoleHeight;    /* 立杆高度 */
	unsigned short	usPoleToCenter;  /* 立杆到雷达照射中心区距离 */
}T_RadarParamSetup;

/* 点*/
typedef struct
{
	short sX;
	short sY;
}T_Point;

/* 线*/
typedef struct
{
	T_Point tStartPoint;
	T_Point tEndPoint;
}T_Line;

/* 区域*/
typedef struct
{
	T_Point tLefTop;
	T_Point tRightBottom;
}T_Rect;

typedef struct
{
	unsigned char ucDashedLine;
	unsigned char ucReserved;
	T_Line tLine;
}T_DivisionLine;

/*视频检测区域参数配置*/
typedef struct
{
	unsigned char		ucLanes;	   /* 车道数  */
	unsigned char		ucSnapAutoBike;/* 摩托车抓拍1:抓拍0:不抓拍*/
	unsigned char 		ucMinScore;    /* 抓拍灵敏度  高 时  抓拍阀值分数(0-100)*//* UINT16 usBanTime; /*违停时长阀值，单位:秒； ucMinScore，ucReserved由usBanTime拆分而来*/
	unsigned char		ucReserved;
	unsigned char		ucCpMode;	/* 抓拍模式 0 : 碰触发线抓拍  1: 进入线圈,锁定抓拍 2 捕获优先(对应抓拍灵敏度  0 低  1 中  高)*/
	unsigned char		ucWidthFlag;/* 可识别车牌宽度标志位: 0识别范围80-200, 1识别范围80-400, 2 识别范围160-400 */
	unsigned char		ucLprHead;	/* 识别模式,TRUE车头模式,FALSE车尾模式(车头模式:单、双层黄牌均识别，车尾模式:只是别双层黄牌)*/
	unsigned char		ucZoomSlop;	/* 缩放图像是否进行倾斜纠正*/

	T_Point		atPlateRegion[4];      /*车牌识别区域*/
	T_Line		aStopLine;              /*卡口:触发线 电子警察:停止线*/
	T_Point		atSpeedRegion[4];/*测速区域  */
	T_Line		atOccupCheckLine[2];/*占有率检测线   */
	T_DivisionLine	atDivisionLine[ONE_DIRECTION_LANES+1];/*车道分割线*/
	T_Line		tPrefixLine;  /*电警前置线*/
	T_Line		tLeftBorderLine;  /*电警左边界线*/
	T_Line		tRightBorderLine;  /*电警右边界线*/
	T_Point		atVirLoop[ONE_DIRECTION_LANES][4]; /*虚拟线圈*/

	/*非法停车区*/
	T_Point		atBanRegion[4];   /*非法禁停区*/

	unsigned short		usCameraHeight;        /* 相机安装高度 */
	unsigned short		usRectLength;          /*路面矩形长度(厘米)*/
	unsigned short		usRectWidth;           /*路面矩形宽度(厘米)*/
	unsigned short		usTotalDis;            /*矩形坐上角到摄像机垂直投影的距离(厘米)*/
}T_VideoDetectParamSetup;


typedef struct 
{
	unsigned char		ucLanes;		/*车道数  */
	unsigned char		ucSnapAutoBike; /*摩托车抓拍1:抓拍0:不抓拍*/
	unsigned short		usBanTime;   /*违停时长阀值，单位:秒*/
	unsigned char		ucVirLoopNum; /*虚拟线圈，抓拍摩托车使用*/
	/*违法灵敏度配置*/
	unsigned char 		ucRunRedLight;   /*闯红灯E_IllegalSensitive*/
	unsigned char             ucNobyLane;        /*不按车道*/
	unsigned char             ucCrossLine;        /*压线*/
	T_Point		atPlateRegion[4];      /*车牌识别区域*/
	T_Line		aStopLine;              /*卡口:触发线 电子警察:停止线*/
	T_Point		atSpeedRegion[4];/*测速区域  */
	T_Line		atOccupCheckLine[2];/*占有率检测线   */
	T_DivisionLine	atDivisionLine[ONE_DIRECTION_LANES+1];/*车道分割线*/
	T_Line		tPrefixLine;  /*电警前置线*/
	T_Line		tLeftBorderLine;  /*电警左边界线*/
	T_Line		tRightBorderLine;  /*电警右边界线*/
	T_Point		atVirLoop[ONE_DIRECTION_LANES][4]; /*虚拟线圈*/

	/*非法停车区*/
	T_Point		atBanRegion[4];   /*非法禁停区*/

	unsigned short		usCameraHeight;        /* 相机安装高度 */
	unsigned short		usRectLength;          /*路面矩形长度(厘米)*/
	unsigned short		usRectWidth;           /*路面矩形宽度(厘米)*/
	unsigned short		usTotalDis;              /*矩形坐上角到摄像机垂直投影的距离(厘米)*/
	unsigned char 	       ucReverseRun;        /*逆行*/
	unsigned char   	       ucIllegalStop;         /*违停*/
	unsigned char		aucReserved[2];
}T_DJVideoDetectParamSetup;

typedef  struct
{
	unsigned  char		ucIndex;
	unsigned  char		ucFunction;
	unsigned  char		ucBaudRate;
	unsigned  char		ucDataBits;
	unsigned  char		ucStopBits;
	unsigned  char		ucCheckOut;
	unsigned  char		ucReserved[2];
}T_ParkRS485Setup;

/*文件类型定义*/
typedef enum
{
	FILE_TYPE_LOG = 0,
	FILE_TYPE_RECORD,
	FILE_TYPE_IMAGE,
	FILE_TYPE_ALL,
}E_FILE_TYPE;

/* 文件数目查询结构*/
typedef struct 
{
	unsigned  char  ucType;   //E_FILE_TYPE
	unsigned  char  aucReserved[3];
	unsigned  int	uiStartDate; 		/*0～7表示日，8～15表示月，16～31位表示年*/
	unsigned  int	uiStartTime; 		/*0～7位表示秒，8～15位表示分，16～23位表示时*/
	unsigned  int	uiEndDate;		
	unsigned  int	uiEndTime;		
}T_QueryFileBase;

/* 文件信息查询结构*/
typedef struct
{
	T_QueryFileBase tBase;
	unsigned  int uiItem;
}T_QueryFileItem;

/* 文件数目上报*/
typedef struct
{
	T_QueryFileBase tQueFileInfo;
	unsigned  int uiCount;
}T_FileCountRsp;

 /* 文件信息上报*/
typedef struct
{
	T_QueryFileItem tQueryItem;
	unsigned  char   szFileName[256];
	unsigned  int uiCreateDate;
	unsigned  int uiCreateTime;
	unsigned  int uiDuration;
}T_FileInfoRsp;

typedef struct
{
	unsigned  char	ucState; // 1:短按,2:长按
	unsigned  char	aucReserved[3];
}T_ResetKeyPressState;//相机复位键按下的状态，短按或长按

typedef struct
{
	unsigned  char 	ucEnable;    /*是否使能*/
	unsigned  char 	ucLevel;      /*LED亮度等级1~7*/ 
	unsigned  char  	aucReserved[2];
	unsigned  short  usStartTime;  /*开始时间单位:分钟*/
	unsigned  short  usEndTime;   /*结束时间单位:分钟*/
}T_ParkLedManualItem;

typedef struct
{
	T_ParkLedManualItem atParkLedMan[3];
}T_ParkLedManual; /*LED强制开控制*/

typedef struct 
{ 
	unsigned  char	ucEnable;
	unsigned  char	aucReserved[3]; 
}T_3GSetup;

typedef struct
{
	unsigned  char  ucEnable;
	unsigned  char	aucReserved[3]; 
	char			ssid[64]; 
	char			pwd[64]; 
	unsigned  int	uiIPAddress; 
	unsigned  int	uiMaskAddress; 
	unsigned  int	uiGatewayAddress; 
}T_WirelessSetup; 

typedef enum 
{ 
	LED_SCREEN_SUB_SINGLE = 0, /*单层屏*/ 
	LED_SCREEN_SUB_TOW,		   /*双层屏*/ 
	LED_SCREEN_SUB_FOUR,	  /*四层屏*/
	LED_SCREEN_XW_WHOLE,     /*西沃一体机屏*/
	LED_SCREEN_SUB_MAX 
}E_LedScreenSubType;

typedef struct
{
	unsigned  char   ucLedSubType;  //E_LedScreenSubType
	unsigned  char   ucLedNum;      //1~255
	unsigned  char	 ucReserved[2]; 
}T_ScreenSetup;

typedef struct
{
	unsigned  char LprResult[16];/*车牌号码；单条消息最多10条车牌号码；其它分多条消息发送*/
	unsigned  char TotalNum;   // 用户总车位数
	unsigned  char IdleNum;   // 用户剩余车位数
	char	  szEndTime[16]; //结束日期
	unsigned  int Id;        //账户id
	unsigned  char Auth[10]; //10字节字符串，通过十六进制的字符串表示40个标识位
	unsigned  char VehType; //0：临时车1：会员车
	unsigned  char MemberValid; //会员车是否有效；0：表示无效，1：表示有效
	unsigned  char Reserved[2]; //保留位
}T_VehResult;


typedef struct
{
	unsigned short Start; //分钟为单位,08:20表示8*60+20=500
	unsigned short End;   //分钟为单位,08:20表示8*60+20=500
}T_Section;

typedef struct
{
	unsigned  char	ucSync; // 0:不同步到其他相机,1:同步到其他相机
	unsigned  char	aucReserved[3];
	T_Section tTable[16];
}T_SectionTable;

typedef struct
{
	unsigned  int  Id;        // 账户id
	unsigned  char TotalNum;  // 用户总车位数
	unsigned  char IdleNum;   // 用户剩余车位数
}T_UserParkInfo;

typedef struct
{
	char	  szPlate[16];		/*车牌号码，GB2312*/
	char	  szStartTime[16];  /*开始时间YYYYMMDDhhmmss*/
	char	  szEndTime[16];    /*结束YYYYMMDDhhmmss*/
	unsigned  int Id;           //账户id
	unsigned  char TotalNum;    //用户总车位数
	unsigned  char IdleNum;     //用户剩余车位数
	unsigned  char Auth[12];    //10字节字符串，通过十六进制的字符串表示40个标识位
	unsigned  char Section[6];  //24小时时段,4个十六进制的字符串表示形式存储16个时段的标识信息
}T_LprInfo;

typedef struct 
{
	unsigned  char ucType;         //见E_SendLprMode
	unsigned  char ucConut;        //本次传输的车牌个数
	unsigned  char aucReserved[2]; //保留位
	T_LprInfo	  atLprResult[10]; //车牌信息
}T_SendLprByMessEx;

typedef struct  
{
	unsigned  char ucResult; //查询的结果，0为未找到该车牌，1为成功找到该车牌
	unsigned  char aucReserved[3];
	T_LprInfo	  tLprResult;
}T_RspLprResultEx;

typedef enum
{
	PARK_BLUE_PLATE = 0x01,   /*蓝牌*/
	PARK_YELLOW_PLATE = 0x02, /*黄牌*/
	PARK_BLACK_PLATE = 0x04, /*黑牌*/
	PARK_JIAOLIAN_PLATE = 0x08,/*教练牌*/
	PARK_JINGCHE_PLATE = 0x10, /*警牌*/
	PARK_WUJING_PLATE = 0x20, /*武警牌*/
	PARK_JUNCHE_PLATE = 0x40, /*军牌*/
	PARK_GANGAO_PLATE = 0x80, /*港澳牌*/
	PARK_SHIGUAN_PLATE = 0x100, /*使馆牌*/
	PARK_NEWENERGY_PLATE = 0x200, /*新能源牌*/
	PARK_MINHANG_PLATE = 0x400, /*民航牌*/
	PARK_MOTOR_PLATE = 0x800, /*摩托车牌*/
}E_DetectPlateType;

typedef struct
{
	unsigned short usTypeBit;
}T_DetectPlateType;

typedef struct
{
	unsigned char	ucEnable; //辅相机使能; 0:不使能 1:使能
	unsigned char   ucBLCEnable;//顺逆光背光补偿      0:不使能 1:使能
	unsigned char	ucType;//辅相机类型  0:外协厂相机  1:标准相机
	unsigned char	ucFusetime;//融合时间 单位ms;
	char    ncMacAddr[NET_MAX_MAC_LEN];
	unsigned int	uiIpAddr;//辅相机ip地址，小端字节序；0表示无效值；
}T_AssCameraSetup;

typedef struct
{
	unsigned char  ucStatus;//0 表示中断 1 连接正常
	unsigned char  ucReserved[3];
}T_AssCameraStatus;

typedef struct
{
	unsigned int  uiIPAddress;//辅相机ip地址，小端字节序；0表示无效值；
	unsigned int  uiMaskAddress;
	unsigned int  uiGatewayAddress;
	char    ncMacAddr[NET_MAX_MAC_LEN];
}T_AssCameraIpModify;

typedef struct
{
	T_Point  tPoint[4];
}T_AssDistrict;

typedef struct
{
	unsigned int  uiNum;
	unsigned int  uiIpAddr[MAX_ASS_SEARCH];//辅相机ip地址，小端字节序；0表示无效值；
	char    ncMacAddr[MAX_ASS_SEARCH][NET_MAX_MAC_LEN];
}T_AssCameraIpSearch;

typedef struct
{
	int  level;    //曝光等级 [0,8]
	unsigned int  leastTime;//自动曝光时间下限或手动曝光时间，单位微秒
	unsigned int  mostTime;//自动曝光时间上限，单位微秒
}T_XMExposureCfg;

typedef struct
{
	int  gain;//自动增益上限(自动增益启用)或固定增益值
	int  autoGain;//自动增益是否启用，0:不开启  1:开启
}T_XMGainCfg;

typedef struct
{
	unsigned char  ucBright;
	unsigned char  ucNight_nfLevel;
	unsigned char  ucDay_nfLevel;
	unsigned char  ucDayNightColor;
	unsigned int   uiDebugCmd; //SDK 设置 2
	T_XMExposureCfg xmExposureCfg;
	T_XMGainCfg     xmGainCfg;
}T_AssCameraParam;

typedef struct
{
	char  acDate[12]; /* 年月日YYYYMMDD ,如果为"00000000"表示无日期限制 */
}T_ExpDate;

typedef struct
{
	unsigned char ucEncId;   /* 如果为0则为不加密,如果为其它的则为加密*/
	unsigned char aucReserved[3]; 
	char acSignatrue[20];     /*接口签名字符串*/
}T_UserSignatrue;

typedef struct
{
	char acOldPwd[32]; /*AES 128位算法使用主密码,加密接口签名字符串,再base64*/
	char acNewPwd[32]; /*AES 128位算法使用主密码,加密新密码字符串,再base64*/
}T_ModifyEncPwd;

typedef struct
{
	unsigned char ucEncId;   /* 如果为0则为不加密,如果为其它的则为加密*/
	unsigned char aucReserved[3]; 
	char acPwd[32];  /*AES 128位算法使用密码,加密接口签名字符串,再base64*/
}T_EncEnable;

typedef struct
{
	unsigned int iId;
	unsigned char szFilePath[256];
}T_GetImageById;

typedef enum
{
	BIT_MOD_VEH_PLATE = 0x01,/*车牌显示*/
	BIT_MOD_VEH_WELCOME = 0x02,/*欢迎语显示*/
	BIT_MOD_VEH_PAY = 0x04,  /*停车付费显示*/
	BIT_MOD_VEH_TIME = 0x08, /*停车时间显示*/
	BIT_MOD_VEH_PERIOD = 0x10, /*月租有效期显示*/
	BIT_MOD_TIME = 0x20,/*时间显示，格式:XXXX年XX月XX时XX分*/
	BIT_MOD_VEH_LEFT = 0x40,/*剩余停车位显示*/
	BIT_MOD_CUSTOM = 0x80,  /*自定义内容显示*/
	BIT_MOD_VEH_USERTYPE = 0x100,  /*停车用户类型*/
	BIT_MOD_MAX,
}E_LedModeBit;

typedef struct
{
	unsigned char		ucEnable;
	unsigned char		ucInterval;//时间间隔  s秒
	unsigned char		ucLedLine;//双行屏，上行1；下行2;
	unsigned char   	ucLedcolor;//E_LED_COLOR
	unsigned short  	usModeBit;//(按上面的位定义)
	unsigned char  		ucReserved[2];
	char				acContent[32]; //GB2312，自定义模式有效
}T_LedLineSetup;

typedef enum 
{ 
	LED_SCREEN_HORIZONTAL = 0, /*横屏*/ 
	LED_SCREEN_VERTICAL,	 /*竖屏*/ 
	LED_SCREEN_STYLE_MAX 
}E_LedScreenStyle;

typedef struct
{
	unsigned char    ucAudioEnable;   /*语音是否使能*/
	unsigned char    ucScreenStyle;   /* 显示屏类型横或竖屏E_LedScreenStyle*/
	unsigned char    ucLedSubType;  //E_LedScreenSubType			
	unsigned char    ucReserved;
	T_LedLineSetup   atSubLedInIdle[MAX_LED_COUNT];//入口空闲
	T_LedLineSetup   atSubLedInBusy[MAX_LED_COUNT];//入口忙  
	T_LedLineSetup   atSubLedOutIdle[MAX_LED_COUNT];//出口空闲
	T_LedLineSetup   atSubLedOutBusy[MAX_LED_COUNT];//出口忙
}T_SLedSetup;

typedef struct
{
	unsigned char	   ucmode;   //0:两行，1:四行，2:竖屏
	unsigned char 	   uc_tmp_in;//临时车入场：0 欢迎光临  1 祝您健康  语音
	unsigned char      uc_tmp_out;// 临时车出场：0 一路顺风  1 一路平安
	unsigned char 	   uc_vip_in;//月租车入场：0 欢迎光临  1 欢迎回家
	unsigned char      uc_vip_out;//月租车出场：0 一路顺风  1 出入平安
	unsigned char 	   ucSleeptimes;// 红绿灯延迟 0-255秒
	unsigned char	   ucvolume;//音量大小 0 - 8 由小到大
	unsigned char      ucReserved[5];
}T_SLedSetup_tfg;

typedef struct{	
	unsigned short	usdaytime;		//白天起点时间	
	unsigned short	usnighttime;	//晚上起点时间	
	unsigned char	ucdayvolume;	//白天音量(0-9)
	unsigned char	ucnightvolume;	//晚上音量(0-9)	
	unsigned char   ucReserved[2];
}T_LedVocieSetup;

typedef struct{	
	unsigned char  ucColortype;  //每行显示的颜色（红 1/绿 2/黄 3） 
	unsigned char  ucReserved[3];
}T_LedLineextSetup;

typedef struct
{
	unsigned char	  InswitchOvertime;//设置开闸时绿灯超时转红灯时间（5-20S） 默认 10S
	unsigned char	  OutswitchOvertime;//设置开闸时绿灯超时转红灯时间（5-20S） 默认 10S
	unsigned char     ucReserved[2];
	T_LedLineextSetup Inatlineext[MAX_LED_COUNT];
	T_LedLineextSetup Outatlineext[MAX_LED_COUNT];
	T_LedVocieSetup  InatVolumeInfo;//音量设置
	T_LedVocieSetup  OutatVolumeInfo;//音量设置
}T_SLedSetupExt;

typedef struct
{
	unsigned char ucnotin;//0 所有车允许   1  所有车禁止
	char uaReserved[7];
}T_XWCarinParam; 

typedef enum
{
	E_T4G_NoYJ = 0,//无4G模组
	E_T4G_NoPPPoe,//未拨号成功
	E_T4G_PPPoeOk,//拨号成成功，未联网
	E_T4G_InternetOk//拨号成功并联网成功 
}E_T4G_StatuList;

typedef struct
{
	unsigned char ucStatus;//4G拨号状态 详见 E_T4G_StatuList
	unsigned char ucSignalLevel;//信号强度 0 无 1-5  信号1-5格
	char uaReserved[14];
}T_T4GInfoParam;

//GB28181配置
#define SIP_MAX_ID_LEN 	32
#define MAX_NAME_LEN 	32
#define RESERVED_LEN 	128

typedef struct
{
	char    szSIPdomain[SIP_MAX_ID_LEN];//中心域
	char  	szSIPserverId[SIP_MAX_ID_LEN];//服务器sip id
	char  	szSIPdeviceId[SIP_MAX_ID_LEN];//设备sip id
	char  	szSIPalarmId[SIP_MAX_ID_LEN];//报警id
	char  	szDeviceName[MAX_NAME_LEN];//设备名字型号
	char  	szServerIPAddress[16];	//服务器ip
	char	usServerPort[16];//服务器端口
	char	usDevicePort[16];//设备端口
	unsigned int 	usRegExpiration;//注册过期时间
	unsigned int 	usHeartBeatInterval;//心跳间隔时间
	char 	szAuthName[MAX_NAME_LEN];//认证用户名
	char 	szAuthPwd[MAX_NAME_LEN];//认证密码
	//char		szReserved[RESERVED_LEN];//扩展保留
}T_GB28181_sipSetup;

typedef struct
{
	char		ncEncodeFormat;//编码格式1：MPEG～4；2：H．264；3：SVAC；4：3GP。
	char		ncResolution;//分辨率1：QCIF；2：CIF；3：4CIF；4：D1；5：720P；6：1080P／1。
	char		ncFps;//帧率o～99
	char		ncRateType;//码率类型1：固定码率(CBR)；2：可变码率(VBR)。
	int			ncRate;//码率：o～100000(如1表示1 kbps)
	//char		szReserved[8];//扩展保留

}T_GB28181_MediaSetup;

typedef struct 
{
	unsigned char 	ucEnabled;//gb28181模块使能
	unsigned char   ucReserved[3];
	char 	szDeviceIP[16];//本机IP
	T_GB28181_sipSetup tSipPara;
	T_GB28181_MediaSetup tMediaPara;
}T_GB28181Priv;

typedef struct
{
	unsigned char	factoryId;
	unsigned char	optId;
	unsigned char	acReserved[2];
	char			acDate[64]; /* YYYYMMDD HH:MM:SS */
}T_ProduceDate;

typedef struct
{
	char 	szPlatePwd[32];
	char		szPMod[32];/* 设置产品型号*/
}T_ProduceMod;


typedef struct
{
	unsigned char   ucIndex;
	unsigned char   ucOpt;         /*1 打开,0 关闭*/
	unsigned char   ucReserved[2];
}T_RS485Opt;

typedef struct
{
	unsigned char   ucMerge;
	unsigned char   ucReserved[3];
}T_AssMerge;


typedef enum
{
	PS_TYPE_GENERAL = 0,  /*普通车位*/
	PS_TYPE_SPECIAL, 	  /*特殊车位*/
	PS_TYPE_MAX,
}E_PSType;

typedef struct 
{ 
	unsigned char ucEnable; /*是否使能*/ 
	unsigned char ucPSType; /*车位类型:0：普通车位 1：特殊车位*/ 
	unsigned char uclampIndex; /*0:内置灯，1:外置灯1    2:外置灯2    3:外置灯3*/
	unsigned char aucReserved;
	unsigned char acPSNo[16]; /*车位编号*/ 
	T_Point tPsRect[4]; /*车位区域*/ 
}T_PSAttrItem;  

typedef struct
{
	unsigned char 	ucPsNum;   /*停车位数*/
	unsigned char   ucSnaptype;/*车位上无车状态变为有车状态时 抓图类型0:抓拍全景图 1:抓拍局部图*/
	unsigned char	aucReserved[2];  
	T_PSAttrItem atPsAttr[3]; 
}T_ParkSpaceAttr;

typedef enum
{
	PS_STATUS_NOCAR = 0, /*无车*/
	PS_STATUS_HAVECAR,   /*有车*/
	PS_STATUS_PRESSLINE, /*压线*/
	PS_STATUS_SPECIAL,   /*特殊车位*/
	PS_STATUS_MAX,
}E_PSStatus;

typedef enum
{
	LAMP_COLOR_OFF = 0,		//灭
	LAMP_COLOR_RED,			//红	
	LAMP_COLOR_GREEN,		//绿
	LAMP_COLOR_YELLOW,		//黄
	LAMP_COLOR_BLUE,		//蓝
	LAMP_COLOR_MAGENTA,		//品红
	LAMP_COLOR_DARKGREEN,	//青
	LAMP_COLOR_WHITE, 		//白色
	LAMP_COLOR_MAX,
}E_LampColor;

typedef enum
{
	LC_MODE_INTERNAL = 0,
	LC_MODE_EXTERNAL,
	LC_MODE_MAX,
}E_LampControlMode;

typedef struct
{
	unsigned char ucEnable;
	unsigned char ucFlicker;	//0:不闪烁1:闪烁
	unsigned char ucLampColor;	//E_LampColor
	unsigned char ucReserved;
}T_LampControlPara;

typedef struct
{
	unsigned char ucLCMode;  /*灯控模式*/
	unsigned char aucReserved[3];
	T_LampControlPara atInternalPara[PS_STATUS_MAX];    /*内置灯控制*/
	T_LampControlPara atExternalPara[3][PS_STATUS_MAX]; /*外置灯控制*/
}T_LampControl;

typedef struct 
{ 
	unsigned char    ucEnable; 
	unsigned char    ucFlicker;	//0:不闪烁1:闪烁 
	unsigned char    ucLampColor;//E_LampColor 
	unsigned char    ucIndex; /*0:内置灯，1:外置灯1 2:外置灯2 3:外置灯3*/ 
}T_NetLampControl;

typedef struct
{
	unsigned char   ucMirror;  /*镜像 0：关 1：开*/
	unsigned char  	ucFlip;    /*翻转 0：关 1：开*/
	unsigned char 	aucReserved[2];
}T_ImageAdjust;


typedef struct
{
	unsigned char	spaceState;             /*当前车位的状态:0:无车   1:有车  */
	unsigned char   auReserverd[3];
	char            szLprResult[16];     //车牌号码
}T_PResetInfo;

typedef struct
{
	unsigned char 	ucNum;   /*停车位数*/
	unsigned char         ucILampValue;/*内置灯颜色*/
	unsigned char        auReserverd[2];
	T_PResetInfo pInfo[3];
}T_RspParkingInfo;

typedef enum
{
	FILE_SEND_SUCC = 0, /* 文件发送成功*/
	FILE_MD5_FAILED = 1, /* 文件md5校验失败*/
	FILE_VERSION_LOW,   /* 文件版本过低*/
	FILE_ACCESS_FAILED, /* 文件不可以访问*/
	FILE_HW_NO_MATCH,   /* 硬件版本不匹配*/
	FILE_TYPE_NO_MATCH, /*文件类型不匹配*/
	CMD_INVALID_PARAM,   /*命令无效参数 */
}E_FileRecvState;

typedef struct
{
	unsigned char 	ucState;  /* E_FileRecvState*/
	unsigned char	acReserved[3];
}T_FileRecvResult;

typedef struct
{
	char aucIp[32];  //目标控制器IP
	unsigned short usPort;  // 目标控制器端口
	unsigned char ucDevNo;  // 目标控制器号
	unsigned char ucParkNo; // 停车场UID
	unsigned char ucCamNo; // 相机UID
	unsigned char ucEnable; /* 1 启用0 不启用*/
	unsigned char ucAck;   /* 0 不验证 1 验证*/
	unsigned char ucReserved;
}T_PushTargetSetup;

typedef struct
{
	unsigned char	ucEnable;  // 功能是否开启
	unsigned char	ucSSLEnable;  // ssl 是否开启
	unsigned short	usPort;    // 服务器端口
	char			szIpAddr[16];  // 服务器IP
	unsigned short	usSSLPort;  // ssl 端口
	unsigned short	usTimeout;  //超时设置
	unsigned char	ucDevReg;  // 设备注册
	char			szRegAddr[127];  //  设备注册地址
	unsigned char	ucPlatePush; // 推送车牌识别结果
	char			szPPushAddr[127]; // 推送车牌识别结果地址
	unsigned char	ucBigPic;  //  发送图片
	unsigned char	ucSmallPic; //  发送小图
	unsigned char	ucGpioPush; // 推送端口触发信息
	char			szGPushAddr[129]; // 推送端口触发信息地址
	unsigned char	ucSerialPush;  // 推送串口数据
	char			szSPushAddr[63];  // 推送串口数据地址
	char			szWebaddr[64];  // WEB服务器IP 或者 域名
}T_HttpPushSetup;

typedef struct
{
	unsigned char	ucEnable;  // 功能是否开启
	unsigned char	ucBigPic;  //  多次发送时发送大图片
	unsigned char	ucSmallPic; //  多次发送时发送小图
	unsigned char	Reserverd[5]; 
	unsigned int	uiInterval;//多次发送时间隔时间 S
	unsigned int	uiMaxtime;//多次发送的最大时间 S
}T_HttpSetupExt;

typedef struct
{
	unsigned int	uiIpAddr;/* IP地址*/
	unsigned short	uwPort;
	char			acReserved[18];
}T_QyTInfo;

typedef struct
{
	T_QyTInfo info[5];
}T_TcpClientInfo;

typedef struct
{
	unsigned int uiRuntime;   /*系统运行时间,单位小时*/
}T_DevRunTime;

//typedef struct
//{
//	unsigned char 	ucEnable;    /*是否使能0:disable 1:enable*/
//	unsigned char 	ucLevel;      /*LED亮度等级1~7*/
//	unsigned char  	aucReserve[2];
//	unsigned short  	usStartTime;  /*开始时间单位:分钟0~1440*/
//	unsigned short  	usEndTime;   /*结束时间单位:分钟0~1440*/
//}T_ParkLedManualItem;

typedef struct
{
	T_ParkLedManualItem atParkOpenMan[3];
}T_ParkOpenManual; /*强制开闸控制*/

/**********************************************************************
* 函数名称：Net_RebootCamera
* 功能描述：重启相机，断开与相机之间的连接
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_RebootCamera(DCHANDLE tHandle);


/**********************************************************************
* 函数名称：Net_TimeSetup
* 功能描述：设置相机的时间
* 输入参数：tHandle 相机句柄
*			ptTimeSetup 时间配置指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_TimeSetup(DCHANDLE tHandle,  T_DCTimeSetup *ptTimeSetup);

/**********************************************************************
* 函数名称：Net_QueryTimeSetup
* 功能描述：查询相机时间
* 输入参数：tHandle 相机句柄
* 输出参数：ptTimeSetup 时间配置结果
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryTimeSetup(DCHANDLE tHandle,  T_DCTimeSetup *ptTimeSetup);

/**********************************************************************
* 函数名称：Net_SntpSetup
* 功能描述：设置指定相机的sntp信息
* 输入参数：tHandle 相机句柄
*           ptSntpSetup sntp配置指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SntpSetup(DCHANDLE tHandle,  T_SNTPSetup *ptSntpSetup);

/**********************************************************************
* 函数名称：Net_QuerySntpSetup
* 功能描述：查询相机的sntp信息
* 输入参数：tHandle 相机句柄
* 输出参数：ptSntpSetup sntp配置结果
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QuerySntpSetup(DCHANDLE tHandle,  T_SNTPSetup *ptSntpSetup);

/**********************************************************************
* 函数名称：Net_NETSetup
* 功能描述：设置相机的网络信息
* 输入参数：tHandle 相机句柄
*			ptNetSetup 设备信息配置指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_NETSetup(DCHANDLE tHandle,  T_NetSetup *ptNetSetup);

/**********************************************************************
* 函数名称：Net_QueryNETSetup
* 功能描述：查询相机的网络信息
* 输入参数：tHandle 相机句柄
* 输出参数：ptNetSetup 设备信息结果
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryNETSetup(DCHANDLE tHandle,  T_NetSetup *ptNetSetup);

/**********************************************************************
* 函数名称：Net_QueryMACSetup
* 功能描述：查询相机MAC地址
* 输入参数：tHandle 相机句柄
* 输出参数：ptMacSetup 设备信息配置结果
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryMACSetup(DCHANDLE tHandle,  T_MACSetup *ptMacSetup);

/**********************************************************************
* 函数名称：Net_AcSyncSetup
* 功能描述：设置指定相机的交流同步信息
* 输入参数：tHandle 相机句柄
*           ptAcSyncSetup 交流电同步配置指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_AcSyncSetup(DCHANDLE tHandle,  T_DCAcSyncSetup *ptAcSyncSetup);

/**********************************************************************
* 函数名称：Net_QueryAcSyncSetup
* 功能描述：查询相机的交流同步信息
* 输入参数：tHandle 相机句柄
* 输出参数：ptAcSyncSetup 交流电同步配置指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryAcSyncSetup(DCHANDLE tHandle, T_DCAcSyncSetup *ptAcSyncSetup);

/**********************************************************************
* 函数名称：Net_ImageQualitySetup
* 功能描述：设置指定相机的图像质量信息
* 输入参数：tHandle 相机句柄
*           ptImageCodec 图像质量，1～100
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ImageQualitySetup(DCHANDLE tHandle,T_ImageCodec *ptImageCodec);

/**********************************************************************
* 函数名称：Net_QueryImageQualitySetup
* 功能描述：查询相机的图像质量信息
* 输入参数：tHandle 相机句柄   
* 输出参数：ptImageCodec  图像质量结果
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryImageQualitySetup(DCHANDLE tHandle, T_ImageCodec *ptImageCodec);

/**********************************************************************
* 函数名称：Net_VideoSubtitleSetup
* 功能描述：设置指定相机的视频字幕信息
* 输入参数：tHandle 相机句柄
*           ptSubtitle 视频字幕信息指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_VideoSubtitleSetup(DCHANDLE tHandle, T_Subtitle *ptSubtitle);

/**********************************************************************
* 函数名称：Net_QueryVideoSubtitleSetup
* 功能描述：查询相机的视频字幕信息
* 输入参数：tHandle 相机句柄
*			ptSubtitle->ucIndex 视频字幕索引编号
* 输出参数：ptSubtitle 视频字幕信息指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryVideoSubtitleSetup(DCHANDLE tHandle, T_Subtitle *ptSubtitle);

/**********************************************************************
* 函数名称：Net_QueryImageById
* 功能描述：根据图片ID获取图片FTP路径
* 输入参数：tHandle 相机句柄
*			ptGetImageById->iId 图片ID
* 输出参数：ptGetImageById 图片信息
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryImageById(DCHANDLE tHandle, T_GetImageById *ptGetImageById);

/**********************************************************************
* 函数名称：Net_SaveImageById
* 功能描述：根据图片ID获取图片并保存到本地
* 输入参数：tHandle 相机句柄
*			iId 图片ID
*			szFileSavePath 图片保存路径
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SaveImageById(DCHANDLE tHandle, int iId, char *szFileSavePath);

/**********************************************************************
* 函数名称：Net_SnapParaSetup
* 功能描述：设置指定相机的抓拍参数
* 输入参数：tHandle 相机句柄
*           ptSnapParaSetup 抓拍参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SnapParaSetup(DCHANDLE tHandle, T_DCSnapParaSetup *ptSnapParaSetup);

/**********************************************************************
* 函数名称：Net_QuerySnapParaSetup
* 功能描述：查询相机的抓拍参数
* 输入参数：tHandle 相机句柄
*           ptSnapParaSetup->ucGroupId 指定组ID
* 输出参数：ptSnapParaSetup 抓拍参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QuerySnapParaSetup(DCHANDLE tHandle,T_DCSnapParaSetup *ptSnapParaSetup);

/**********************************************************************
* 函数名称：Net_VideoParaSetup
* 功能描述：设置指定相机的视频参数
* 输入参数：tHandle 相机句柄
*           ptVideoParaSetup视频参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_VideoParaSetup(DCHANDLE tHandle, T_VideoParaSetup *ptVideoParaSetup);

/**********************************************************************
* 函数名称：Net_QueryVideoParaSetup
* 功能描述：查询指定相机的抓拍参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptVideoParaSetup 视频参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryVideoParaSetup(DCHANDLE tHandle, T_VideoParaSetup *ptVideoParaSetup);

/**********************************************************************
* 函数名称：Net_AssVideoParaSetup
* 功能描述：设置辅相机的视频参数
* 输入参数：tHandle 相机句柄
*           ptVideoParaSetup视频参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_AssVideoParaSetup(DCHANDLE tHandle, T_VideoParaSetup *ptVideoParaSetup);

/**********************************************************************
* 函数名称：Net_QueryAssVideoParaSetup
* 功能描述：查询辅相机的视频参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptVideoParaSetup 视频参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryAssVideoParaSetup(DCHANDLE tHandle, T_VideoParaSetup *ptVideoParaSetup);

/**********************************************************************
* 函数名称：Net_ViceVideoCodeSetup
* 功能描述：设置相机辅视频编码参数
* 输入参数：tHandle 相机句柄
*           ptVideoCodeSetup 视频编码指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ViceVideoCodeSetup(DCHANDLE tHandle, T_VideoCodeSetup *ptVideoCodeSetup);

/**********************************************************************
* 函数名称：Net_QueryViceVideoCodeSetup
* 功能描述：查询相机辅视频编码参数
* 输入参数： tHandle 相机句柄
* 输出参数： ptVideoCodeSetup 视频编码指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryViceVideoCodeSetup(DCHANDLE tHandle, T_VideoCodeSetup *ptVideoCodeSetup);

/**********************************************************************
* 函数名称：Net_DynamicCodeSetup
* 功能描述：设置指定相机的动态视频编码
* 输入参数：tHandle 相机句柄
*           ptDynamicCode 动态视频编码指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_DynamicCodeSetup(DCHANDLE tHandle, T_DynamicCode *ptDynamicCode);

/**********************************************************************
* 函数名称：Net_QueryDynamicCodeSetup
* 功能描述：查询指定相机的动态视频编码
* 输入参数： tHandle 相机句柄
* 输出参数： ptDynamicCode 动态视频编码指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryDynamicCodeSetup(DCHANDLE tHandle, T_DynamicCode *ptDynamicCode);

/**********************************************************************
* 函数名称：Net_QueryCameraSpec
* 功能描述：查询相机规格
* 输入参数：tHandle 相机句柄
* 输出参数：ptSpec 相机规格配置指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryCameraSpec(DCHANDLE tHandle, T_DCSpec  *ptSpec);

/**********************************************************************
* 函数名称：Net_DevInfoSetup
* 功能描述：设置相机设备信息
* 输入参数：tHandle 相机句柄
*           ptDevSetup 相机设备信息指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_DevInfoSetup(DCHANDLE tHandle,  T_DevSetup *ptDevSetup);

/**********************************************************************
* 函数名称：Net_QueryDevSetup
* 功能描述：查询相机设备信息
* 输入参数：tHandle 相机句柄
* 输出参数：ptDevSetup 相机设备信息指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryDevSetup(DCHANDLE tHandle, T_DevSetup *ptDevSetup);

/**********************************************************************
* 函数名称：Net_FTPSetup
* 功能描述：设置相机FTP信息
* 输入参数：tHandle 相机句柄
*           ptFtpSetup 相机FTP信息指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_FTPSetup(DCHANDLE tHandle,  T_FTPSetup *ptFtpSetup);

/**********************************************************************
* 函数名称：Net_QueryFTPSetup
* 功能描述：查询相机FTP信息
* 输入参数：tHandle 相机句柄
* 输出参数：ptFtpSetup 相机FTP信息指针
* 返 回 值：状态码
***********************************************************************/
NET_API  E_ReturnCode _stdcall Net_QueryFTPSetup(DCHANDLE tHandle,T_FTPSetup *ptFtpSetup);

/**********************************************************************
* 函数名称：Net_AssistantIpncSetup
* 功能描述：设置辅助相机配置信息
* 输入参数：tHandle 相机句柄
*           ptAssistantIpnc 辅助相机配置信息指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_AssistantIpncSetup(DCHANDLE tHandle,  T_AssistantIpnc *ptAssistantIpnc);

/**********************************************************************
* 函数名称：Net_QueryAssistantIpncSetup
* 功能描述：查询辅助相机配置信息
* 输入参数：tHandle 相机句柄
* 输出参数：ptAssistantIpnc 辅助相机配置信息指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryAssistantIpncSetup(DCHANDLE tHandle,  T_AssistantIpnc *ptAssistantIpnc);

/**********************************************************************
* 函数名称：Net_MessegerSetup
* 功能描述：设置后台通讯配置参数
* 输入参数：tHandle 相机句柄
*           ptMessenger 后台通信配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_MessegerSetup(DCHANDLE tHandle,  T_Messenger *ptMessenger);

/**********************************************************************
* 函数名称：Net_QueryMessegerSetup
* 功能描述：查询后台通讯配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptMessenger 后台通信配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryMessegerSetup(DCHANDLE tHandle,  T_Messenger *ptMessenger);

/**********************************************************************
* 函数名称：Net_SigControlPortSetup
* 功能描述：设置信号控制通信端口参数
* 输入参数：tHandle 相机句柄
*           ptSigControlPort 信号机控制端口参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SigControlPortSetup(DCHANDLE tHandle,  T_SigControlPort *ptSigControlPort);

/**********************************************************************
* 函数名称：Net_QuerySigControlPortSetup
* 功能描述：查询信号控制通信端口参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptSigControlPort 信号机控制端口参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QuerySigControlPortSetup(DCHANDLE tHandle,  T_SigControlPort *ptSigControlPort);

/**********************************************************************
* 函数名称：Net_CaptureSetup
* 功能描述：设置事件抓拍参数
* 输入参数：tHandle 相机句柄
*           ptEventCapturePara 抓拍位置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_CaptureSetup(DCHANDLE tHandle,  T_EventCapturePara *ptEventCapturePara);

/**********************************************************************
* 函数名称：Net_QueryCaptureSetup
* 功能描述：查询事件抓拍参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptEventCapturePara 抓拍位置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryCaptureSetup(DCHANDLE tHandle,T_EventCapturePara *ptEventCapturePara);

/**********************************************************************
* 函数名称：Net_RoadLaneBasicSetup
* 功能描述：设置基本车道配置参数
* 输入参数：tHandle 相机句柄
*           ptRoadLaneBasicSetup 车道配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_RoadLaneBasicSetup(DCHANDLE tHandle,  T_RoadLaneBasicSetup *ptRoadLaneBasicSetup);

/**********************************************************************
* 函数名称：Net_QueryRoadLaneBasicSetup
* 功能描述：查询基本车道配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptRoadLaneBasicSetup 车道配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryRoadLaneBasicSetup(DCHANDLE tHandle,T_RoadLaneBasicSetup *ptRoadLaneBasicSetup);

/**********************************************************************
* 函数名称：Net_RoadLaneExternSetup
* 功能描述：设置扩展车道配置参数
* 输入参数：tHandle 相机句柄
*           ptRoadLaneExtendSetup 扩展车道配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_RoadLaneExternSetup(DCHANDLE tHandle,  T_RoadLaneExtendSetup *ptRoadLaneExtendSetup);

/**********************************************************************
* 函数名称：Net_QueryRoadLaneExternSetup
* 功能描述：查询扩展车道配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptRoadLaneExtendSetup 扩展车道配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryRoadLaneExternSetup(DCHANDLE tHandle, T_RoadLaneExtendSetup *ptRoadLaneExtendSetup);

/**********************************************************************
* 函数名称：Net_VideoCodeSetup
* 功能描述：设置视频编码参数
* 输入参数：tHandle 相机句柄
*           ptVideoCodec 视频编码参数指针
* 输出参数：无 
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_VideoCodeSetup(DCHANDLE tHandle, T_VideoCodeSetup *ptVideoCodeSetup);

/**********************************************************************
* 函数名称：Net_QueryVideoCodeSetup
* 功能描述：查询视频编码参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptVideoCodec 视频编码参数指针 
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryVideoCodeSetup(DCHANDLE tHandle, T_VideoCodeSetup *ptVideoCodeSetup);

/**********************************************************************
* 函数名称：Net_QueryRS485Setup
* 功能描述：设置RS485配置参数
* 输入参数：tHandle 相机句柄
*           ptRs485Setup RS485配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_RS485Setup(DCHANDLE tHandle,  T_RS485Setup *ptRs485Setup);

/**********************************************************************
* 函数名称：Net_QueryRS485Setup
* 功能描述：查询RS485配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptRs485Setup RS485配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryRS485Setup(DCHANDLE tHandle,  T_RS485Setup *ptRs485Setup);

/**********************************************************************
* 函数名称：Net_ParkRS485Setup
* 功能描述：设置停车场RS485配置参数
* 输入参数：tHandle 相机句柄
*           ptRs485Setup 停车场RS485配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ParkRS485Setup(DCHANDLE tHandle,  T_ParkRS485Setup *ptRs485Setup);

/**********************************************************************
* 函数名称：Net_QueryParkRS485Setup
* 功能描述：查询停车场RS485配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptRs485Setup 停车场RS485配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryParkRS485Setup(DCHANDLE tHandle,  T_ParkRS485Setup *ptRs485Setup);

/**********************************************************************
* 函数名称：Net_VehicleVAFunSetup
* 功能描述：设置车牌识别配置参数
* 输入参数：tHandle 相机句柄
*           ptVehicleVAFunSetup	车牌识别配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_VehicleVAFunSetup(DCHANDLE tHandle,  T_VehicleVAFunSetup *ptVehicleVAFunSetup);

/**********************************************************************
* 函数名称：Net_QueryVehicleVAFunSetup
* 功能描述：查询车牌识别配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptVehicleVAFunSetup	车牌识别配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryVehicleVAFunSetup(DCHANDLE tHandle,  T_VehicleVAFunSetup *ptVehicleVAFunSetup);

/**********************************************************************
* 函数名称：Net_VehicleVAFunSetupEX
* 功能描述：设置车牌识别配置扩展参数
* 输入参数：tHandle 相机句柄
*           ptVehicleVAFunSetupEX	车牌识别配置扩展参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_VehicleVAFunSetupEX(DCHANDLE tHandle,  T_VehicleVAFunSetupEX *ptVehicleVAFunSetupEX);

/**********************************************************************
* 函数名称：Net_QueryVehicleVAFunSetupEX
* 功能描述：查询车牌识别配置扩展参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptVehicleVAFunSetupEX	车牌识别配置扩展参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryVehicleVAFunSetupEX(DCHANDLE tHandle,  T_VehicleVAFunSetupEX *ptVehicleVAFunSetupEX);

/**********************************************************************
* 函数名称：Net_InvalidLprLevelSetup
* 功能描述：设置伪车牌处理等级参数
* 输入参数：tHandle 相机句柄
*           ptInvalidLprLevel	伪车牌处理等级参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_InvalidLprLevelSetup(DCHANDLE tHandle,  T_InvalidLprLevel *ptInvalidLprLevel);

/**********************************************************************
* 函数名称：Net_QueryInvalidLprLevelSetup
* 功能描述：查询伪车牌处理等级参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptInvalidLprLevel	伪车牌处理等级参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryInvalidLprLevelSetup(DCHANDLE tHandle,  T_InvalidLprLevel *ptInvalidLprLevel);

/**********************************************************************
* 函数名称：Net_PicOsdSetup
* 功能描述：设置车图片字幕配置参数
* 输入参数：tHandle 相机句柄
*           ptPicOsdSetup 车图片字幕配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_PicOsdSetup(DCHANDLE tHandle,  T_PicOsdSetup *ptPicOsdSetup);

/**********************************************************************
* 函数名称：Net_QueryPicOsdSetup
* 功能描述：查询车图片字幕配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptPicOsdSetup 车图片字幕配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryPicOsdSetup(DCHANDLE tHandle,  T_PicOsdSetup *ptPicOsdSetup);

/**********************************************************************
* 函数名称：Net_StorageSetup
* 功能描述：设置储存信息配置参数
* 输入参数：tHandle 相机句柄
*           ptStorageSetup 储存信息配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode  _stdcall Net_StorageSetup(DCHANDLE tHandle,  T_StorageSetup *ptStorageSetup);

/**********************************************************************
* 函数名称：Net_QueryStorageSetup
* 功能描述：查询储存信息配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptStorageSetup 储存信息配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryStorageSetup(DCHANDLE tHandle,  T_StorageSetup *ptStorageSetup);
/**********************************************************************
* 函数名称：Net_DemoSetup
* 功能描述：演示模式配置参数
* 输入参数：tHandle 相机句柄
*           ptDemoSetup	   演示模式配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_DemoSetup(DCHANDLE tHandle,  T_DemoSetup *ptDemoSetup);

/**********************************************************************
* 函数名称：Net_QueryDemoSetup
* 功能描述：查询演示模式配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptSetup  演示模式配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryDemoSetup(DCHANDLE tHandle,  T_DemoSetup *ptSetup);

/**********************************************************************
* 函数名称：Net_ImageEvSetup
* 功能描述：设置顺光逆光配置参数
* 输入参数：tHandle 相机句柄
*           ptImageEv 宽动态配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ImageEvSetup(DCHANDLE tHandle,  T_ImageEv *ptImageEv);

/**********************************************************************
* 函数名称：Net_QueryImageEvSetup
* 功能描述：查询顺光逆光配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptImageEv 宽动态配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryImageEvSetup(DCHANDLE tHandle,  T_ImageEv *ptImageEv);

/**********************************************************************
* 函数名称：Net_ServicePortSetup
* 功能描述：设置RTSP/HTTP服务端口参数
* 输入参数：tHandle 相机句柄
*           ptServicePortSetup	服务端口参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ServicePortSetup(DCHANDLE tHandle,  T_ServicePortSetup *ptServicePortSetup);

/**********************************************************************
* 函数名称：Net_QueryServicePortSetup
* 功能描述：设置RTSP/HTTP服务端口参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptServicePortSetup	服务端口参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode  _stdcall Net_QueryServicePortSetup(DCHANDLE tHandle,  T_ServicePortSetup *ptServicePortSetup);

/**********************************************************************
* 函数名称：Net_ImageCodecSetup
* 功能描述：设置图像编码参数
* 输入参数：tHandle 相机句柄
*           ptImageCodec 图像编码参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ImageCodecSetup(DCHANDLE tHandle,  T_ImageCodec *ptImageCodec);

/**********************************************************************
* 函数名称：Net_QueryImageCodecSetup
* 功能描述：查询图像编码参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptImageCodec 图像编码参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryImageCodecSetup(DCHANDLE tHandle,  T_ImageCodec *ptImageCodec);

/**********************************************************************
* 函数名称：Net_FlashLightSetup
* 功能描述：设置闪光灯配置参数
* 输入参数：tHandle 相机句柄
*           ptFlashLightSetup 闪光灯配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_FlashLightSetup(DCHANDLE tHandle,  T_FlashLightSetup *ptFlashLightSetup);

/**********************************************************************
* 函数名称：Net_QueryFlashLightSetup
* 功能描述：查询闪光灯配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptFlashLightSetup 闪光灯配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryFlashLightSetup(DCHANDLE tHandle,  T_FlashLightSetup *ptFlashLightSetup);

/**********************************************************************
* 函数名称：Net_SignalLightSetup
* 功能描述：设置信号灯配置参数
* 输入参数：tHandle 相机句柄
*           ptSignalLightSetup 信号灯配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SignalLightSetup(DCHANDLE tHandle,  T_SignalLightSetup *ptSignalLightSetup);

/**********************************************************************
* 函数名称：Net_QuerySignalLightSetup
* 功能描述：查询信号灯配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptSignalLightSetup 信号灯配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QuerySignalLightSetup(DCHANDLE tHandle,  T_SignalLightSetup *ptSignalLightSetup);

/**********************************************************************
* 函数名称：Net_SetSigLightParm
* 功能描述：设置信号灯配置
* 输入参数：tHandle 相机句柄
			ptSigLightParm  指向信号灯设置的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SigLightParmSetup(DCHANDLE tHandle,T_SigLightParm *ptSigLightParm);

/**********************************************************************
* 函数名称：Net_QuerySigLightParm
* 功能描述：查询信号灯配置
* 输入参数：tHandle 相机句柄
			ptSigLightParm  指向信号灯设置的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QuerySigLightParmSetup(DCHANDLE tHandle,T_SigLightParm *ptSigLightParm);

/**********************************************************************
* 函数名称：Net_LedLightBasicSetup
* 功能描述：设置信号灯配置参数
* 输入参数：tHandle 相机句柄
*           ptLedLightBasicSetup 信号灯配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_LedLightBasicSetup(DCHANDLE tHandle,  T_LedLightBasicSetup *ptLedLightBasicSetup);

/**********************************************************************
* 函数名称：Net_QueryLedLightBasicSetup
* 功能描述：查询信号灯配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptLedLightBasicSetup 信号灯配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryLedLightBasicSetup(DCHANDLE tHandle,  T_LedLightBasicSetup *ptLedLightBasicSetup);

/**********************************************************************
* 函数名称：Net_FileUpdate
* 功能描述：系统升级
* 输入参数：tHandle 相机句柄
*			ptUpdateSetup 系统升级参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_FileUpdate(DCHANDLE tHandle,  T_UpdateSetup *ptUpdateSetup);

/**********************************************************************
* 函数名称：Net_RegFileUpdateProgress
* 功能描述：注册系统升级文件发送状态
* 输入参数：tHandle 相机句柄
*			pFileSendProgress 回调函数参数指针
*			pUser	用户私有数据指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
typedef void (CALLBACK *NET_FileSendProgress) (DCHANDLE tHandle, int nProgress, void* pUser);
NET_API E_ReturnCode _stdcall Net_RegFileUpdateProgress(DCHANDLE tHandle,  NET_FileSendProgress pFileSendProgress, void* pUser);

/**********************************************************************
* 函数名称：Net_DetectModeSetup
* 功能描述：设置相机的检测模式
* 输入参数：tHandle 相机句柄
*			ptDetectModeSetup 相机检测模式参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_DetectModeSetup(DCHANDLE tHandle,  T_DetectModeSetup *ptDetectModeSetup);

/**********************************************************************
* 函数名称：Net_QueryDetectModeSetup
* 功能描述：查询相机的检测模式
* 输入参数：tHandle 相机句柄
* 输出参数：ptDetectModeSetup 相机检测模式参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryDetectModeSetup(DCHANDLE tHandle,  T_DetectModeSetup *ptDetectModeSetup);

/**********************************************************************
* 函数名称：Net_LoopDetectSetup
* 功能描述：设置线圈检测模式参数
* 输入参数：tHandle 相机句柄
*			ptLoopParamSetup 线圈检测模式参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_LoopDetectSetup(DCHANDLE tHandle,  T_LoopParamSetup *ptLoopParamSetup);

/**********************************************************************
* 函数名称：Net_QueryLoopDetectSetup
* 功能描述：查询线圈检测模式参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptLoopParamSetup 线圈检测模式参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryLoopDetectSetup(DCHANDLE tHandle,  T_LoopParamSetup *ptLoopParamSetup);

/**********************************************************************
* 函数名称：Net_VideoDetectSetup
* 功能描述：设置视频检测区域参数
* 输入参数：tHandle 相机句柄
*			ptVideoDetectParamSetup 视频检测区域参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_VideoDetectSetup(DCHANDLE tHandle,  T_VideoDetectParamSetup *ptVideoDetectParamSetup);

/**********************************************************************
* 函数名称：Net_QueryVideoDetectSetup
* 功能描述：查询视频检测区域参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptVideoDetectParamSetup 视频检测区域参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryVideoDetectSetup(DCHANDLE tHandle,  T_VideoDetectParamSetup *ptVideoDetectParamSetup);

/**********************************************************************
* 函数名称：Net_VideoDetectSetup
* 功能描述：设置视频检测区域参数
* 输入参数：tHandle 相机句柄
*			ptVideoDetectParamSetup 视频检测区域参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_DJVideoDetectSetup(DCHANDLE tHandle,  T_DJVideoDetectParamSetup *ptVideoDetectParamSetup);

/**********************************************************************
* 函数名称：Net_QueryVideoDetectSetup
* 功能描述：查询视频检测区域参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptVideoDetectParamSetup 视频检测区域参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryDJVideoDetectSetup(DCHANDLE tHandle,  T_DJVideoDetectParamSetup *ptVideoDetectParamSetup);


/**********************************************************************
* 函数名称：Net_RadarParamSetup
* 功能描述：设置雷达检测参数
* 输入参数：tHandle 相机句柄
*			ptRadarParamSetup 雷达检测参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_RadarParamSetup(DCHANDLE tHandle,  T_RadarParamSetup *ptRadarParamSetup);

/**********************************************************************
* 函数名称：Net_QueryVideoDetectSetup
* 功能描述：查询雷达检测参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptRadarParamSetup 雷达检测参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryRadarParamSetup(DCHANDLE tHandle,  T_RadarParamSetup *ptRadarParamSetup);

/**********************************************************************
* 函数名称：Net_SetupRestore
* 功能描述：恢复出厂设置
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SetupRestore(DCHANDLE tHandle);

/**********************************************************************
* 函数名称：Net_StoreConfig
* 功能描述：保存当前设置
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_StoreConfig(DCHANDLE tHandle);

/**********************************************************************
* 函数名称：Net_ReStoreConfig
* 功能描述：恢复相机最后一次设置
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ReStoreConfig(DCHANDLE tHandle);

/**********************************************************************
* 函数名称：Net_OneKeyFocus
* 功能描述：一键聚焦
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_OneKeyFocus(DCHANDLE tHandle);

/**********************************************************************
* 函数名称：Net_GetSysState
* 功能描述：查询系统状态参数
* 输入参数：tHandle 相机句柄
*			ptSysState 系统状态参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_GetSysState(DCHANDLE tHandle, T_SysState *ptSysState);

/**********************************************************************
* 函数名称：Net_ImportConfig
* 功能描述：导入配置
* 输入参数：tHandle 相机句柄
*			ptImportConfigSetup 配置导入参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ImportConfig(DCHANDLE tHandle, T_ImportConfigSetup *ptImportConfigSetup);

/**********************************************************************
* 函数名称：Net_ExportConfig
* 功能描述：导出配置
* 输入参数：tHandle 相机句柄
*			ptExportConfigSetup 配置导出参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ExportConfig(DCHANDLE tHandle, T_ExportConfigSetup *ptExportConfigSetup);

NET_API E_ReturnCode _stdcall Net_ExportOfflineData(DCHANDLE tHandle, T_FileName *ptFileName);

NET_API E_ReturnCode _stdcall Net_ExportOfflinePay(DCHANDLE tHandle, T_FileName *ptFileName);

/**********************************************************************
* 函数名称：Net_ExportLog
* 功能描述：导出日志
* 输入参数：tHandle 相机句柄
*			szLogFilePath 日志文件路径
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ExportLog(DCHANDLE tHandle, char *szLogFilePath);

NET_API E_ReturnCode _stdcall Net_ExportLogEx(DCHANDLE tHandle, char *szLogFilePath);

/**********************************************************************
* 函数名称：Net_RebootTimeSetup
* 功能描述：设置定时重启系统参数
* 输入参数：tHandle 相机句柄
*			ptTimeReboot 定时重启系统参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_RebootTimeSetup(DCHANDLE tHandle, T_TimeReboot *ptTimeReboot);

/**********************************************************************
* 函数名称：Net_QueryRebootTimeSetup
* 功能描述：查询定时重启系统参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptTimeReboot 定时重启系统参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryRebootTimeSetup(DCHANDLE tHandle, T_TimeReboot *ptTimeReboot);

/**********************************************************************
* 函数名称：Net_QuerySysVersion
* 功能描述：查询相机系统版本
* 输入参数：tHandle 相机句柄	
* 输出参数：ptQueVersionRsp 系统版本参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QuerySysVersion(DCHANDLE tHandle, T_QueVersionRsp *ptQueVersionRsp);

/**********************************************************************
* 函数名称：Net_SpeedLimitSetup
* 功能描述：设置车道限速参数
* 输入参数：tHandle 相机句柄
*			ptSpeedCorrAndLimitSetup 限速参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SpeedLimitSetup(DCHANDLE tHandle,  T_SpeedCorrAndLimitSetup *ptSpeedCorrAndLimitSetup);

/**********************************************************************
* 函数名称：Net_QuerySpeedLimitSetup
* 功能描述：查询车道限速参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptSpeedCorrAndLimitSetup 限速参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QuerySpeedLimitSetup(DCHANDLE tHandle,  T_SpeedCorrAndLimitSetup *ptSpeedCorrAndLimitSetup);

/**********************************************************************
* 函数名称：Net_PicTransPortSetup
* 功能描述：设置图片传输协议
* 输入参数：tHandle 相机句柄
*           ptTransPort 图片传输协议参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_PicTransPortSetup(DCHANDLE tHandle, T_TransProt *ptTransPort);

/**********************************************************************
* 函数名称：Net_QueryPicTransPortSetup
* 功能描述：查询图片传输协议
* 输入参数：tHandle 相机句柄
* 输出参数：ptTransPort 图片传输协议参数指针
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryPicTransPortSetup(DCHANDLE tHandle, T_TransProt *ptTransPort);

/**********************************************************************
* 函数名称：Net_MulticastSetup
* 功能描述：设置组播配置参数
* 输入参数：tHandle 相机句柄
*           ptMulticastSetup 组播配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_MulticastSetup(DCHANDLE tHandle, T_MulticastSetup *ptMulticastSetup);

/**********************************************************************
* 函数名称：Net_QueryMulticastSetup
* 功能描述：查询组播配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptMulticastSetup 组播配置参数指针
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryMulticastSetup(DCHANDLE tHandle, T_MulticastSetup *ptMulticastSetup);

/**********************************************************************
* 函数名称：Net_QueryHardInfo
* 功能描述：查询相机硬盘信息
* 输入参数：tHandle 相机句柄
* 输出参数：ptHardDiskInfo 相机硬盘信息指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryHardInfo(DCHANDLE tHandle, T_HardDiskInfo *ptHardDiskInfo);

/**********************************************************************
* 函数名称：Net_DiskFomat
* 功能描述：格式化SSD
* 输入参数：tHandle 相机句柄
			ptHardDiskNum 分区选择
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_DiskFomat(DCHANDLE tHandle, T_HardDiskNum *ptHardDiskNum);

/**********************************************************************
* 函数名称：Net_DiskFomatTF
* 功能描述：格式化TF卡
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_DiskFomatTF(DCHANDLE tHandle);

/**********************************************************************
* 函数名称：Net_TestTF
* 功能描述：测试TF卡读写功能
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_TestTF(DCHANDLE tHandle);

/**********************************************************************
* 函数名称：Net_TestUSB
* 功能描述：测试USB读写功能
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_TestUSB(DCHANDLE tHandle);

/**********************************************************************
* 函数名称：Net_QueryLogCount
* 功能描述：查询日志文件数量
* 输入参数：tHandle 相机句柄
			ptLogCount 日志文件数目查询结构指针
* 输出参数：ptLogCountRsp 日志文件数量指针
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryLogCount(DCHANDLE tHandle, T_QueryFileBase *ptLogCount,T_FileCountRsp *ptLogCountRsp);

/**********************************************************************
* 函数名称：Net_QueryLogInfo
* 功能描述：查询日志文件信息
* 输入参数：tHandle 相机句柄
			ptLogInfo 日志文件信息查询结构指针
* 输出参数：ptLogInfoRsp 日志文件信息指针
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryLogInfo(DCHANDLE tHandle, T_QueryFileItem *ptLogInfo,T_FileInfoRsp *ptLogInfoRsp);

/**********************************************************************
* 函数名称：Net_ParkGatePulseSetup
* 功能描述：设置停车场闸机脉冲时长
* 输入参数：tHandle 相机句柄
*			ptGatePulse 相机闸机脉冲时长指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ParkGatePulseSetup(DCHANDLE tHandle, T_ParkSetup *ptGatePulse);

/**********************************************************************
* 函数名称：Net_QueryParkGatePulse
* 功能描述：查询停车场闸机脉冲时长
* 输入参数：tHandle 相机句柄
* 输出参数：ptGatePulse 相机闸机脉冲时长指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryParkGatePulse(DCHANDLE tHandle, T_ParkSetup *ptGatePulse);

/**********************************************************************
* 函数名称：Net_BackMessagerSetup
* 功能描述：设置备用服务器的端口配置
* 输入参数：tHandle 相机句柄
*			ptMessenger 备用服务器端口配置指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_BackMessagerSetup(DCHANDLE tHandle,T_Messenger *ptMessenger);

/**********************************************************************
* 函数名称：Net_BackMessagerSetup
* 功能描述：设置备用服务器的端口配置
* 输入参数：tHandle 相机句柄
*			ptMessenger 备用服务器端口配置指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryBackMessagerSetup(DCHANDLE tHandle,T_Messenger *ptMessenger);

/**********************************************************************
* 函数名称：Net_SetWiperTime
* 功能描述：设置雨刷定时时间
* 输入参数：tHandle 相机句柄
			ptWiperTimeing  指向定时雨刷设置的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetWiperTime(DCHANDLE tHandle,T_WiperTiming *ptWiperTimeing);

/**********************************************************************
* 函数名称：Net_QueryWiperTime
* 功能描述：查询雨刷定时时间
* 输入参数：tHandle 相机句柄
			ptWiperTimeing  指向定时雨刷设置的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryWiperTime(DCHANDLE tHandle,T_WiperTiming *ptWiperTimeing);

/**********************************************************************
* 函数名称：Net_SetVideoAve
* 功能描述：设置能见度配置
* 输入参数：tHandle 相机句柄
			ptAveConfig  指向能见度设置的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetVideoAve(DCHANDLE tHandle,T_Ave_Config *ptAveConfig);

/**********************************************************************
* 函数名称：Net_QueryVideoAve
* 功能描述：查询能见度配置
* 输入参数：tHandle 相机句柄
			ptAveConfig  指向能见度设置的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryVideoAve(DCHANDLE tHandle,T_Ave_Config *ptAveConfig);

/**********************************************************************
* 函数名称：Net_SetParkLedManual
* 功能描述：设置LED强制开控制参数
* 输入参数：tHandle 相机句柄
			ptParkLedManual  指向LED强制开控制参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetParkLedManual(DCHANDLE tHandle,T_ParkLedManual *ptParkLedManual);

/**********************************************************************
* 函数名称：Net_QueryParkLedManual
* 功能描述：查询LED强制开控制参数
* 输入参数：tHandle 相机句柄
			ptParkLedManual  指向LED强制开控制参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryParkLedManual(DCHANDLE tHandle,T_ParkLedManual *ptParkLedManual);


/**********************************************************************
* 函数名称：Net_SetWirelessSetup
* 功能描述：设置热点配置参数
* 输入参数：tHandle 相机句柄
			ptWirelessSetup  指向热点配置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetWirelessSetup(DCHANDLE tHandle,T_WirelessSetup *ptWirelessSetup);

/**********************************************************************
* 函数名称：Net_QueryWirelessSetup
* 功能描述：查询热点配置参数
* 输入参数：tHandle 相机句柄
			ptWirelessSetup  指向热点配置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryWirelessSetup(DCHANDLE tHandle,T_WirelessSetup *ptWirelessSetup);

/**********************************************************************
* 函数名称：Net_Set3GSetup
* 功能描述：设置3G配置参数
* 输入参数：tHandle 相机句柄
			pt3GSetup  指向3G配置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_Set3GSetup(DCHANDLE tHandle,T_3GSetup *pt3GSetup);

/**********************************************************************
* 函数名称：Net_Query3GSetup
* 功能描述：查询3G配置参数
* 输入参数：tHandle 相机句柄
			pt3GSetup  指向3G配置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_Query3GSetup(DCHANDLE tHandle,T_3GSetup *pt3GSetup);

/**********************************************************************
* 函数名称：Net_SetScreenSetup
* 功能描述：设置屏显配置参数
* 输入参数：tHandle 相机句柄
			ptScreenSetup  指向屏显配置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetScreenSetup(DCHANDLE tHandle,T_ScreenSetup *ptScreenSetup);

/**********************************************************************
* 函数名称：Net_QueryScreenSetup
* 功能描述：查询屏显配置参数
* 输入参数：tHandle 相机句柄
			ptScreenSetup  指向屏显配置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryScreenSetup(DCHANDLE tHandle,T_ScreenSetup *ptScreenSetup);

/**********************************************************************
* 函数名称：Net_SetSection
* 功能描述：设置时段表参数
* 输入参数：tHandle 相机句柄
			ptSectionTable  指向时段表配置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetSectionTable(DCHANDLE tHandle,T_SectionTable *ptSectionTable);

/**********************************************************************
* 函数名称：Net_QuerySection
* 功能描述：查询时段表参数
* 输入参数：tHandle 相机句柄
			ptSectionTable  指向时段表配置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QuerySectionTable(DCHANDLE tHandle,T_SectionTable *ptSectionTable);

/**********************************************************************
* 函数名称：Net_SetUserParkInfo
* 功能描述：设置用户车位数信息参数
* 输入参数：tHandle 相机句柄
			ptUserParkInfo  指向用户车位数信息配置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetUserParkInfo(DCHANDLE tHandle,T_UserParkInfo *ptUserParkInfo);

/**********************************************************************
* 函数名称：Net_QueryUserParkInfo
* 功能描述：查询用户车位数信息参数
* 输入参数：tHandle 相机句柄
			ptUserParkInfo  指向用户车位数信息配置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryUserParkInfo(DCHANDLE tHandle,T_UserParkInfo *ptUserParkInfo);

/**********************************************************************
* 函数名称：Net_SetDetectPlateType
* 功能描述：设置车牌识别类型信息参数
* 输入参数：tHandle 相机句柄
			ptDetectPlateType  指向车牌识别类型信息参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetDetectPlateType(DCHANDLE tHandle,T_DetectPlateType *ptDetectPlateType);

/**********************************************************************
* 函数名称：Net_QueryDetectPlateType
* 功能描述：查询车牌识别类型信息参数
* 输入参数：tHandle 相机句柄
			ptDetectPlateType  指向车牌识别类型信息参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryDetectPlateType(DCHANDLE tHandle,T_DetectPlateType *ptDetectPlateType);

/**********************************************************************
* 函数名称：Net_SetExpDate
* 功能描述：设置相机有效期
* 输入参数：tHandle 相机句柄
			ptExpDate  指向相机有效期信息参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetExpDate(DCHANDLE tHandle,T_ExpDate *ptExpDate);

/**********************************************************************
* 函数名称：Net_QueryExpDate
* 功能描述：查询相机有效期
* 输入参数：tHandle 相机句柄
			ptExpDate  指向相机有效期信息参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryExpDate(DCHANDLE tHandle,T_ExpDate *ptExpDate);

/**********************************************************************
* 函数名称：Net_SetGB28181Priv
* 功能描述：设置GB28181配置
* 输入参数：tHandle 相机句柄
			ptGB28181Priv  指向GB28181信息参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetGB28181Priv(DCHANDLE tHandle,T_GB28181Priv *ptGB28181Priv);

/**********************************************************************
* 函数名称：Net_QueryGB28181Priv
* 功能描述：查询GB28181配置
* 输入参数：tHandle 相机句柄
			ptGB28181Priv  指向GB28181信息参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryGB28181Priv(DCHANDLE tHandle,T_GB28181Priv *ptGB28181Priv);

/**********************************************************************
* 函数名称：Net_QueryProduceDate
* 功能描述：查询生产日期
* 输入参数：tHandle 相机句柄
			ptProduceDate  指向生产日期信息参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryProduceDate(DCHANDLE tHandle,T_ProduceDate *ptProduceDate);

/**********************************************************************
* 函数名称：Net_SetProduceMod
* 功能描述：设置产品型号
* 输入参数：tHandle 相机句柄
			ptProduceMod  指向产品型号信息参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetProduceMod(DCHANDLE tHandle,T_ProduceMod *ptProduceMod);

/**********************************************************************
* 函数名称：Net_QueryProduceMod
* 功能描述：查询产品型号
* 输入参数：tHandle 相机句柄
			ptProduceMod  指向产品型号信息参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryProduceMod(DCHANDLE tHandle,T_ProduceMod *ptProduceMod);

/**********************************************************************
* 函数名称：Net_SetAssCamera
* 功能描述：设置辅相机IP配置
* 输入参数：tHandle 相机句柄
			ptAssCameraSetup  指向辅相机IP配置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetAssCamera(DCHANDLE tHandle, T_AssCameraSetup *ptAssCameraSetup);

/**********************************************************************
* 函数名称：Net_SetAssCameraAsyn
* 功能描述：设置辅相机IP配置,指示消息
* 输入参数：tHandle 相机句柄
			ptAssCameraSetup  指向辅相机IP配置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SetAssCameraAsyn(DCHANDLE tHandle, T_AssCameraSetup *ptAssCameraSetup);

/**********************************************************************
* 函数名称：Net_QueryAssCamera
* 功能描述：查询辅相机IP配置
* 输入参数：tHandle 相机句柄
			ptAssCameraSetup  指向辅相机IP配置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryAssCamera(DCHANDLE tHandle, T_AssCameraSetup *ptAssCameraSetup);

/**********************************************************************
* 函数名称：Net_SetAssDistrict
* 功能描述：设置辅相机识别区
* 输入参数：tHandle 相机句柄
			ptAssDistrict  指向辅相机识别区配置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetAssDistrict(DCHANDLE tHandle, T_AssDistrict *ptAssDistrict);

/**********************************************************************
* 函数名称：Net_QueryAssDistrict
* 功能描述：查询辅相机识别区
* 输入参数：tHandle 相机句柄
			ptAssDistrict  指向辅相机识别区配置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryAssDistrict(DCHANDLE tHandle, T_AssDistrict *ptAssDistrict);

/**********************************************************************
* 函数名称：Net_SetAssMerge
* 功能描述：设置辅相机融合使能
* 输入参数：tHandle 相机句柄
			ptAssMerge  指向辅相机融合使能参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetAssMerge(DCHANDLE tHandle, T_AssMerge *ptAssMerge);

/**********************************************************************
* 函数名称：Net_QueryAssMerge
* 功能描述：查询辅相机融合使能
* 输入参数：tHandle 相机句柄
			ptAssMerge  指向辅相机融合使能参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryAssMerge(DCHANDLE tHandle, T_AssMerge *ptAssMerge);

/**********************************************************************
* 函数名称：Net_QueryAssCameraStatus
* 功能描述：查询辅相机连接状态
* 输入参数：tHandle 相机句柄
			ptAssCameraStatus  指向辅相机连接状态参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryAssCameraStatus(DCHANDLE tHandle, T_AssCameraStatus *ptAssCameraStatus);

/**********************************************************************
* 函数名称：Net_AssCameraIpModify
* 功能描述：修改辅相机IP地址
* 输入参数：tHandle 相机句柄
			ptAssCameraIpModify  指向辅相机IP地址参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_AssCameraIpModify(DCHANDLE tHandle, T_AssCameraIpModify *ptAssCameraIpModify);

/**********************************************************************
* 函数名称：Net_AssCameraIpSearch
* 功能描述：辅相机IP搜索触发消息
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_AssCameraIpSearch(DCHANDLE tHandle);

/**********************************************************************
* 函数名称：Net_SendBlackWhiteListByMessEx
* 功能描述：通过消息导入白名单
* 输入参数：tHandle 相机句柄
			ptSendLprByMessEx  指向白名单信息配置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SendBlackWhiteListByMessEx(DCHANDLE tHandle,T_SendLprByMessEx *ptSendLprByMessEx);

/**********************************************************************
* 函数名称：Net_QueryWhiteListByPlateEx
* 功能描述：通过车牌查询白名单内该车牌信息，车牌字符必须为GB2312编码
* 输入参数：tHandle 相机句柄
*			pPlateInfo 车牌号码
			ptRspLprResultEx 指向查询到的车牌信息
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryWhiteListByPlateEx(DCHANDLE tHandle, const char *pPlateInfo,T_RspLprResultEx *ptRspLprResultEx);

/**********************************************************************
* 函数名称：Net_QueryVideoAve
* 功能描述：主动查询当前相机与岗亭连接状态，消息通过NET_ParkStateCallBack回调上报
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryParkState(DCHANDLE tHandle);

/**********************************************************************
* 函数名称：Net_QuerySignatrue
* 功能描述：查询签名字符串
* 输入参数：tHandle 相机句柄
* 输入参数：ucEncId     加密使能缓冲区
*			szSignatrue 签名字符串缓冲区
*		    ptLen		缓冲区大小
* 输出参数：ucEncId     加密使能信息,如果为0则为不加密,如果为其它的则为加密
*			szSignatrue 签名字符串信息
*           ptLen		签名字符串真实长度
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QuerySignatrue(DCHANDLE tHandle, unsigned char *ucEncId, char *szSignatrue, int *ptLen);

/**********************************************************************
* 函数名称：Net_ResetEncPwd
* 功能描述：重置车牌解密密码
* 输入参数：tHandle 相机句柄
* 输入参数：szMainPwd 相机主密码
*		    szNewPwd 车牌解密新密码
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ResetEncPwd(DCHANDLE tHandle, char *szMainPwd, char *szNewPwd);

/**********************************************************************
* 函数名称：Net_ResetTwoEncpyption
* 功能描述：重置二次加密密码
* 输入参数：tHandle 相机句柄
* 输入参数：szMainPwd 相机主密码
*		    szNewPwd 二次加密新密码
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ResetTwoEncpyption(DCHANDLE tHandle, char *szMainPwd, char *szNewPwd);

/**********************************************************************
* 函数名称：Net_ModifyEncPwd
* 功能描述：修改车牌解密密码
* 输入参数：tHandle 相机句柄
* 输入参数：szOldPwd 车牌解密旧密码
*		    szNewPwd 车牌解密新密码
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ModifyEncPwd(DCHANDLE tHandle, char *szOldPwd, char *szNewPwd);

/**********************************************************************
* 函数名称：Net_ModifyEncPwd
* 功能描述：开启是否加密
* 输入参数：tHandle 相机句柄
* 输入参数：ucEncId 如果为0则为不加密,如果为其它的则为加密,此时需要调用Net_SetDecPwd设置密码来解密车牌
*		    szPwd 车牌解密密码
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_EnableEnc(DCHANDLE tHandle, unsigned char ucEncId, char *szPwd);

/**********************************************************************
* 函数名称：Net_SetEncPwd
* 功能描述：设置车牌解密密码
* 输入参数：tHandle 相机句柄
*		    szPwd 车牌解密密码
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetDecPwd(DCHANDLE tHandle, char *szPwd);

/**********************************************************************
* 函数名称：Net_SetParkSpaceAttr
* 功能描述：设置车位属性
* 输入参数：tHandle 相机句柄
			ptParkSpaceAttr  指向车位属性参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetParkSpaceAttr(DCHANDLE tHandle, T_ParkSpaceAttr *ptParkSpaceAttr);

/**********************************************************************
* 函数名称：Net_QueryParkSpaceAttr
* 功能描述：查询车位属性
* 输入参数：tHandle 相机句柄
			ptParkSpaceAttr  指向车位属性参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryParkSpaceAttr(DCHANDLE tHandle, T_ParkSpaceAttr *ptParkSpaceAttr);

/**********************************************************************
* 函数名称：Net_SetLampControl
* 功能描述：设置车位led灯控参数
* 输入参数：tHandle 相机句柄
			ptLampControl  指向车位led灯控参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetLampControl(DCHANDLE tHandle, T_LampControl *ptLampControl);

/**********************************************************************
* 函数名称：Net_QueryLampControl
* 功能描述：查询车位车位led灯控参数
* 输入参数：tHandle 相机句柄
			ptLampControl  指向车位led灯控参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryLampControl(DCHANDLE tHandle, T_LampControl *ptLampControl);

/**********************************************************************
* 函数名称：Net_SetNetLampControl
* 功能描述：设置车位网络控灯参数
* 输入参数：tHandle 相机句柄
			ptNetLampControl  指向车位网络控灯参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetNetLampControl(DCHANDLE tHandle, T_NetLampControl *ptNetLampControl);

/**********************************************************************
* 函数名称：Net_QueryNetLampControl
* 功能描述：查询车位车位网络控灯参数
* 输入参数：tHandle 相机句柄
			ptNetLampControl  指向车位网络控灯参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryNetLampControl(DCHANDLE tHandle, T_NetLampControl *ptNetLampControl);

/**********************************************************************
* 函数名称：Net_SetImageAdjust
* 功能描述：设置视频镜像翻转
* 输入参数：tHandle 相机句柄
			ptImageAdjust  指向镜像翻转参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetImageAdjust(DCHANDLE tHandle, T_ImageAdjust *ptImageAdjust);

/**********************************************************************
* 函数名称：Net_QueryImageAdjust
* 功能描述：查询视频镜像翻转
* 输入参数：tHandle 相机句柄
			ptImageAdjust  指向镜像翻转参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryImageAdjust(DCHANDLE tHandle, T_ImageAdjust *ptImageAdjust);

/**********************************************************************
* 函数名称：Net_SetPushTargetSetup
* 功能描述：设置识别结果推送配置
* 输入参数：tHandle 相机句柄
			ptPushTargetSetup  指向识别结果推送配置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetPushTargetSetup(DCHANDLE tHandle, T_PushTargetSetup *ptPushTargetSetup);

/**********************************************************************
* 函数名称：Net_QueryPushTargetSetup
* 功能描述：查询识别结果推送配置
* 输入参数：tHandle 相机句柄
			ptPushTargetSetup  指向识别结果推送配置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryPushTargetSetup(DCHANDLE tHandle, T_PushTargetSetup *ptPushTargetSetup);

/**********************************************************************
* 函数名称：Net_SetHttpPushSetup
* 功能描述：设置HTTP推送配置
* 输入参数：tHandle 相机句柄
			ptHttpPushSetup  指向HTTP推送配置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetHttpPushSetup(DCHANDLE tHandle, T_HttpPushSetup *ptHttpPushSetup);

/**********************************************************************
* 函数名称：Net_QueryHttpPushSetup
* 功能描述：查询HTTP推送配置
* 输入参数：tHandle 相机句柄
			ptPushTargetSetup  指向HTTP推送配置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryHttpPushSetup(DCHANDLE tHandle, T_HttpPushSetup *ptHttpPushSetup);

/**********************************************************************
* 函数名称：Net_SetHttpSetupExt
* 功能描述：设置HTTP车牌识别结果多次推送设置
* 输入参数：tHandle 相机句柄
			ptHttpSetupExt  指向车牌识别结果多次推送设置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetHttpSetupExt(DCHANDLE tHandle, T_HttpSetupExt *ptHttpSetupExt);

/**********************************************************************
* 函数名称：Net_QueryHttpSetupExt
* 功能描述：查询HTTP车牌识别结果多次推送设置
* 输入参数：tHandle 相机句柄
			ptHttpSetupExt  指向车牌识别结果多次推送设置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryHttpSetupExt(DCHANDLE tHandle, T_HttpSetupExt *ptHttpSetupExt);

/**********************************************************************
* 函数名称：Net_SetParkOpenManual
* 功能描述：强制开闸控制
* 输入参数：tHandle 相机句柄
			ptParkOpenManual  指向强制开闸控制参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetParkOpenManual(DCHANDLE tHandle, T_ParkOpenManual *ptParkOpenManual);

/**********************************************************************
* 函数名称：Net_QueryParkOpenManual
* 功能描述：强制开闸控制
* 输入参数：tHandle 相机句柄
			ptParkOpenManual  指向强制开闸控制参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryParkOpenManual(DCHANDLE tHandle, T_ParkOpenManual *ptParkOpenManual);

/**********************************************************************
* 函数名称：Net_QueryTcpClientInfo
* 功能描述：查询TCP连接信息
* 输入参数：tHandle 相机句柄
			ptTcpClientInfo  指向TCP连接信息参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryTcpClientInfo(DCHANDLE tHandle, T_TcpClientInfo *ptTcpClientInfo);

/**********************************************************************
* 函数名称：Net_QueryDevRunTime
* 功能描述：查询系统运行时间
* 输入参数：tHandle 相机句柄
			ptDevRunTime  指向系统运行时间参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 

NET_API E_ReturnCode _stdcall Net_QueryDevRunTime(DCHANDLE tHandle, T_DevRunTime *ptDevRunTime);
/**********************************************************************
* 函数名称：Net_QueryXWCarinParam
* 功能描述：查询17号屏显协议0余位入场规则
* 输入参数：tHandle 相机句柄
			ptXWCarinParam  指向参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryXWCarinParam(DCHANDLE tHandle, T_XWCarinParam *ptXWCarinParam);

/**********************************************************************
* 函数名称：Net_SetXWCarinParam
* 功能描述：设置17号屏显协议0余位入场规则
* 输入参数：tHandle 相机句柄
			ptXWCarinParam  指向设置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetXWCarinParam(DCHANDLE tHandle, T_XWCarinParam *ptXWCarinParam);

/**********************************************************************
* 函数名称：Net_QueryT4GInfoParam
* 功能描述：查询4G状态参数
* 输入参数：tHandle 相机句柄
			ptT4GInfoParam  指向参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryT4GInfoParam(DCHANDLE tHandle, T_T4GInfoParam *ptT4GInfoParam);

#ifdef __cplusplus
}
#endif
#endif

