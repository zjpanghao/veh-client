#ifndef __NETSTRUCTDEF_H__
#define __NETSTRUCTDEF_H__

// #define SzLPRClientHandle LONG
// 
// #define SZ_LPRC_API extern "C" 

#ifndef SZ_LPRC_API
#define SZ_LPRC_API extern "C" 
#endif

#ifndef SzLPRClientHandle
#define SzLPRClientHandle LONG
#endif

#define MAX_HOST_LEN				128
#define MAX_SERVER_NAME_LEN			32
#define MAX_USER_NAME_LEN			32
#define MAX_PASSWORD_LEN			32
#define MAX_FILENAME_LEN			255

enum PROTOCOL
{
	PROTOCOL_RTSP_UDP = 0,
	PROTOCOL_RTSP_TCP = 1,
	PROTOCOL_RTSP_MCAST = 2,
};

typedef struct _STREAM_INFO
{
	unsigned short	videoCoder;		//视频编码方式
	unsigned short	audioCoder;		//音频编码方式
	unsigned short	frameRate;		//帧率
	unsigned short	bitRate;		//比特率
	unsigned short	nWidth;			//视频宽
	unsigned short	nHeight;		//视频高
	unsigned short	frameType;		//H264帧类型 见下面定义
	unsigned short  isKeyFrame;		//是否为关键帧
	unsigned short	type;			//数据类型，0 视频， 1 音频  2码流头信息
	unsigned short	res;
	long			nStamp;			//时标信息，单位毫秒
}STREAM_INFO;

typedef enum _IMG_SIZE_MODE{
	IMG_MODE_NONE = 0,
	IMG_MODE_CIF,
	IMG_MODE_D1,
	IMG_MODE_720P,
	IMG_MODE_1080P
}IMG_SIZE_MODE;

/**图像信息*/
typedef struct
{
	unsigned		uWidth;			/**<宽度*/
	unsigned		uHeight;		/**<高度*/
	unsigned		uPitch;			/**<图像宽度的一行像素所占内存字节数*/
	unsigned		uPixFmt;		/**<图像像素格式，参考枚举定义图像格式（ImageFormatXXX）*/
	unsigned		uSize;
	unsigned char	*pJpegBuf;		/**<图像内存的首地址*/
	unsigned char	*pBuffer;		/**<图像内存的首地址*/
}
SZ_LPRC_IMAGE_INFO;

/**图像信息*/
typedef struct
{
	unsigned int	nsize;
	unsigned char *pBuffer;		/**<图像内存的首地址*/
}
BMP_IMAGE_INFO;

//FRAME_INFO.avType
enum Stream_Type
{
	STREAM_VIDEO = 0,
	STREAM_AUDIO,
	STREAM_HEADER,
};

const int nPostionFirst[4] = {680, -25, 750, -5};
const int nPostionSecond[4] = { 680, -45, 750, -25 };


/*************************** 消息 ********************************/
//状态消息
enum MSG_TYPE
{
	//连接状态 void*lpStruct = NULL
	MSG_LINK_OK = 0,					//成功
	MSG_LINK_CONNECTING = 1,			//正在连接(中间状态)
	MSG_LINK_RECONNECT = 2,				//重连
	MSG_LINK_FAILED = 3,				//重连失败
	MSG_LINK_DISCONNECT = 4,			//最终失败,放弃重连,需要断开连接释放资源
	MSG_LINK_UNAUTHORIZED = 5,			//用户或密码错误

	//录像状态void*lpStruct = char*filename
	MSG_RECORD_BEGIN = 0x100,			//第一帧数据写入时回调产生此消息
	MSG_RECORD_WRITE_ERROR,				//录像异常错误,写文件失败
	MSG_RECORD_FORMAT_CHANGED,			//音视频格式,分辨率,帧率发生改变,内部已经停止录像,如果仍需要录像则需要重新调用开始录像, 一般此消息在视频重连后发生
	MSG_RECORD_PACKET_FINISH,			//录象打包完成,内部已经调用停止录像,外部直接再调用开始录像即可

	//另外一份录像文件,可用于专门录制报警录像
	MSG_RECORD_BEGIN_ANOTHER,			//同上
	MSG_RECORD_WRITE_ERROR_ANOTHER,		//同上
	MSG_RECORD_FORMAT_CHANGED_ANOTHER,	//同上
	MSG_RECORD_PACKET_FINISH_ANOTHER,	//同上

	//报警,消息
	MSG_MOTION_DETECT = 0x200,			//视频移动报警 void*lpStruct = MOTION_DETECT_INFO*pMDInfo
	MSG_MOTION_DETECT_END,				//移动侦测延时消息,默认5秒,报警触发后5秒内无触发则发送此消息
	MSG_VIDEO_LOST,						//视频丢失报警
	MSG_ALARM_IN,						//探头报警 void *lpstruct = int* index

	//抓拍使用	void *lpstruct = (char*)filename
	MSG_SHOT_FINISHED = 0X300,			//抓拍完成,
	MSG_SHOT_FAILED,					//抓拍文件, 文件打开失败,或者系统内存不够

	//播放使用
	MSG_REPLAY_FINISHED = 0X400,		//文件回放结束

	MSG_LIVEVIEW_FAILED = 0X410,

	MSG_SOUND_FAILED = 0X420,

	//设备升级回调消息
	MSG_UPGRADE_POS = 0X500,

	MSG_LOGON_OK = 0X600,
	MSG_LOGON_FAILED = 0X601,
	MSG_LOGON_RECONNECT = 0X602,
	//从设备返回的消息
	MSG_NOTIFY_LINELOOPCHANGED = 0x00001001  //线框改变

};

#define LPRC_IPLEN				24

#define NET_MAX_USER				(3)
#define NET_USERNAME_MINLEN			(4)
#define NET_USERNAME_MAXLEN		    (32)
#define NET_USERPASSWD_MINLEN		(4)
#define NET_USERPASSWD_MAXLEN		(32)

typedef struct TagNetUser
{
	char name[NET_USERNAME_MAXLEN + 1];
	char passwd[NET_USERPASSWD_MAXLEN + 1];
}TNetUser;

typedef struct TagNetUserInfo
{
	char adminPasswd[NET_USERNAME_MAXLEN + 1]; // admin的密码
	TNetUser user[NET_MAX_USER]; // 普通用户的用户名和密码
}TNetUserInfo;

typedef struct SZ_LPRC_NETCFG
{
	int dhcp_enable;
	char ipaddr[LPRC_IPLEN];
	char netmask[LPRC_IPLEN];
	char gateway[LPRC_IPLEN];
	char dns[LPRC_IPLEN];
	char mac[LPRC_IPLEN];
	char des[128];//设备描述

	char expiretime[LPRC_IPLEN];
	char userId[LPRC_IPLEN];
	int  http_port;
}SZ_LPRC_NETCFG;

typedef struct GLOBAL_ENV_PARAMS
{
	SzLPRClientHandle m_handle;
	SzLPRClientHandle m_subhandle;
	SZ_LPRC_NETCFG m_DevNetInfo;
	int deviceType;
	char strType[64];
}GLOBAL_ENV_PARAMS;

/* 命令通用返回 */
typedef enum{
	NET_COMMON_RET_OK = 0, // 正常
	NET_COMMON_RET_ERR, // 错误
	NET_COMMON_RET_MAX
}NET_COMMON_RET;


typedef struct TagNetUserInfo_Ret
{
	NET_COMMON_RET ret;
}TNetUserInfo_Ret;

/*获取设备信息 NET_CMDID_GETDEVICEINFO*/
typedef enum{
	NET_ACTIVESTATUS_OK = 0, // 已经激活
	NET_ACTIVESTATUS_ERR, // 未激活
	NET_ACTIVESTATUS_MAX
}NET_ACTIVESTATUS;

enum Net_Quality
{
	Very_Good = 1,
	Good = 2,
	Common = 3,
	NoCmmon = 4,
	Bad = 5,
	DisConnect = 6,
	NET_Quality_MAX
};

typedef struct TagNetDeviceInfo
{
	char devicetype[32]; // 设备型号
	char phymac[18];	// Device MAC Addr,字符串的方式传递,"11-22-33-44-55-66"
	NET_ACTIVESTATUS activestatus; // 激活状态
	char sn[32]; // 序列号
	char hwversion[32]; // 硬件版本
	char swversion[32]; // 软件版本
	char lpralgversion[32];	// 车牌识别算法版本
}TNetDeviceInfo;

typedef struct TagNetUniqueID{
	char devicetype[16]; // 网络标识符
}TNetUniqueID;

typedef struct TagNetUniqueID_Ret{
	NET_COMMON_RET ret;
}TNetUniqueID_Ret;

typedef struct TagDevDescription
{
	char description[128]; // 设备描述
}TDevDescription;

typedef struct TagDevDescription_Ret{
	NET_COMMON_RET ret;
}TDevDescription_Ret;

/*重启设备 NET_CMDID_REBOOTDEVICE*/
typedef struct TagNetRebootDevice{
	unsigned int delaysec; // 接收到该命令开始计时,等待delaysec后执行重启操作,为0表示立即重启
}TNetRebootDevice;

/*恢复出厂设置 NET_CMDID_RESETSETTING*/
typedef enum{
	NET_RESETSETTING_LEVEL_LIGHT = 0, // 轻量级参数恢复
	NET_RESETSETTING_LEVEL_WEIGHT, // 重量级参数恢复,保留网络参数、用户名密码、序列号
	NET_RESETSETTING_LEVEL_MAX
} NET_RESETSETTING;

typedef struct TagNetResetSetting
{
	NET_RESETSETTING level; // 参数恢复等级
}TNetResetSetting;

typedef enum{
	NET_RESETSETTING_RET_OK = 0, // 参数恢复成功
	NET_RESETSETTING_RET_ERR = 0, // 参数恢复失败
	NET_RESETSETTING_RET_MAX
} NET_RESETSETTING_RET;

typedef struct TagNetResetSetting_Ret{
	NET_RESETSETTING_RET status;
}TNetResetSetting_Ret;


/*升级请求 NET_CMDID_UPGRADE_REQUEST*/
/*升级传输数据 NET_CMDID_UPGRADE_UPLOADDATA*/
typedef struct TagNetUpgradeData{
	char *pUpgradeData;
}TNetUpgradeData;

typedef enum{
	NET_UPGRADE_RET_OK = 0,
	NET_UPGRADE_RET_ERR_BUSY,			// 系统繁忙,不能升级
	NET_UPGRADE_RET_ERR_BADDATA,		// 升级数据校验错误
	NET_UPGRADE_RET_ERR_NOTFCARD,		// No Found TF Card
	NET_UPGRADE_RET_ERR_NOMEMORY,		// 内存不够
	NET_UPGRADE_RET_ERR_HWVER_MISMATCH,	// 硬件版本不匹配
	NET_UPGRADE_RET_ERR_FILETOOLARGE,	// *文件过大
	NET_UPGRADE_RET_ERR_FILEERR,		// *升级文件格式异常
	NET_UPGRADE_RET_ERR_READFILE,		// *读取文件异常
	NET_UPGRADE_RET_ERR_NOMATCH,		// *安装文件不匹配，不是我们的安装包
	NET_UPGRADE_RET_ERR_VERSION_TOOLOW,	// *安装文件版本过低，低于现在使用的版本
	NET_UPGRADE_RET_ERROR,	// *升级失败
	NET_UPGRADE_RET_MAX
}NET_UPGRADE_RET;

typedef struct TagNetUpgrade_Ret
{
	NET_UPGRADE_RET retstatus;
}TNetUpgrade_Ret;

/* 导出导入参数 NET_CMDID_EXPORT_CONFIGPARA*/
#define NET_CONFIGPARA_MAXLEN	(8*10*1024-4) // 配置参数的缓冲最大为8*10*1024-4字节

typedef struct TagNetConfigPara
{
	unsigned int lenght;
	char xmlbuf[NET_CONFIGPARA_MAXLEN];
}TNetConfigPara;

typedef enum
{
	NET_IMPORT_RET_OK = 0,
	NET_IMPORT_RET_ERR_VERSION, // 导入的配置文件和相机当前软件版本不匹配
	NET_IMPORT_RET_ERR_DAMAGE, // 导入的配置文件不完整或被损坏
	NET_IMPORT_RET_MAX
}NET_IMPORT_RET;

typedef struct TagNetImport_Ret
{
	NET_IMPORT_RET ret;
}TNetImport_Ret;


/*获取、设置有线网络参数 NET_CMDID_NET_GETWIREDPARA*/
typedef enum
{
	NET_DHCP_DISABLE = 0,
	NET_DHCP_ENABLE,
	NET_DHCP_MAX
}NET_DHCP;

typedef struct TagNetWiredPara{
	NET_DHCP dhcpenable;
	char ipaddr[16];
	char netmask[16];
	char gateway[16];
	char dns[16];
	unsigned short http_port;
}TNetWiredPara;

typedef struct TagNetWiredPara_Ret{
	NET_COMMON_RET ret;
}TNetWiredPara_Ret;

/*设置获取设备当前系统时间 NET_CMDID_DATETIME_GET*/
typedef struct TagDATE_PARAM{
	unsigned int	year; // 已经偏置了1900
	unsigned int	month; // 1-12
	unsigned int	day;
}DATE_PARAM;

typedef struct TagTIME_PARAM{
	unsigned int	hour;// 对于24小时制0-23,对于12小时制0-11
	unsigned int	min;// 0-59
	unsigned int	sec;// 0-59
}TIME_PARAM;

typedef struct TagNetDateTime{
	DATE_PARAM p_date_param;
	TIME_PARAM p_time_param;
}TNetDateTime;

typedef struct TagNetDateTime_Ret{
	NET_COMMON_RET ret;
}TNetDateTime_Ret;

/*设置获取时间同步参数 NET_CMDID_DATETIME_GETSYNCPARA*/
#define NET_NTPSERVER_LEN  	(64)

typedef enum{
	NET_NTPENABLE_OFF = 0, // 关闭
	NET_NTPENABLE_ON,  // 同步使能
	NET_NTPENABLE_MAX
}NET_NTPENABLE;

typedef struct TagNetNtpPara{
	NET_NTPENABLE ntp_enable; // 默认关闭
	char ntp_server[NET_NTPSERVER_LEN]; // ntp服务器地址 默认为"time.windows.com"
	unsigned int refreshInterval; // 同步时间间隔（单位：秒）默认为 300
}TNetNtpPara;

typedef struct TagNetNtpPara_Ret{
	NET_COMMON_RET ret;
}TNetNtpPara_Ret;

/*设置获取图像快门和增益 NET_CMDID_IMG_GETEXPGAIN*/
typedef enum{
	NET_EXPGAIN_MODE_AUTO = 0, // 自动
	NET_EXPGAIN_MODE_MENU, // 手动
	NET_EXPGAIN_MODE_MAX
}NET_EXPGAIN_MODE;

typedef struct TagNetExpGain{
	NET_EXPGAIN_MODE nGainCtrlMode; // 增益控制模式,默认自动
	unsigned int nMaxGainAuto; // 增益范围0-100,默认20
	unsigned int nFixGainManu; // 默认20
	NET_EXPGAIN_MODE nShutrCtrlMode; // 快门控制模式,默认自动
	unsigned int nMaxShutrAuto;	// 快门范围100-40000,默认5000,单位为毫秒
	unsigned int nFixShutrManu; // 默认5000,单位为毫秒
}TNetExpGain;

typedef struct TNetExpGain_Ret{
	NET_COMMON_RET ret;
}TNetExpGain_Ret;

/*设置获取图像基本参数 NET_CMDID_IMG_GETBASE*/
typedef struct TagNetImageBasePara{
	unsigned int nBrightness; // 亮度取值范围1-100,默认50
	unsigned int nContrast; // 对比度取值范围1-100,默认50
	unsigned int nSaturation; // 饱和度取值范围1-100,默认50
	unsigned int nSharpness; // 锐度取值范围1-100,默认50
}TNetImageBasePara;

typedef struct TagNetImageBasePara_Ret{
	NET_COMMON_RET ret;
}TNetImageBasePara_Ret;

/*设置获取JPEG编码质量 NET_CMDID_GETJPEGQUALITY*/
typedef enum{
	NET_JPEGQUALITY_100 = 0,
	NET_JPEGQUALITY_90,
	NET_JPEGQUALITY_80,
	NET_JPEGQUALITY_70,
	NET_JPEGQUALITY_60,
	NET_JPEGQUALITY_50,
	NET_JPEGQUALITY_40,
	NET_JPEGQUALITY_30,
	NET_JPEGQUALITY_20,
	NET_JPEGQUALITY_10,
	NET_JPEGQUALITY_MAX
}NET_JPEGQUALITY;
typedef struct TagNetJpegQuality{
	NET_JPEGQUALITY quality;
}TNetJpegQuality;
typedef struct TagNetJpegQuality_Ret{
	NET_COMMON_RET ret;
}TNetJpegQuality_Ret;

/*设置获取字幕叠加信息参数 NET_CMDID_OSD_GETPARA*/
#define NET_OSDTEXTLEN	(60)
typedef enum{
	NET_OSD_ENABLE_OFF = 0, // 关闭
	NET_OSD_ENABLE_ON, // 使能	
	NET_OSD_ENABLE_MAX
}NET_OSD_ENABLE;

typedef enum{
	NET_OSD_TYPEDATE_YMD = 0, // YYYY/MM/DD
	NET_OSD_TYPEDATE_MDY, // MM/DD/YYYY
	NET_OSD_TYPEDATE_DMY, // DD/MM/YYYY
	NET_OSD_TYPEDATE_MAX
}NET_OSD_TYPEDATE;

typedef enum{
	NET_OSD_TYPETIME_12H = 0, // 12小时制
	NET_OSD_TYPETIME_24H, // 24小时制
	NET_OSD_TYPETIME_MAX
}NET_OSD_TYPETIME;

typedef struct TagNetOSDPara{
	NET_OSD_ENABLE		dstampenable; // 默认使能
	NET_OSD_TYPEDATE	dateFormat; // 默认 YYYY/MM/DD
	unsigned int		datePosX; // 默认20
	unsigned int		datePosY; // 默认20
	NET_OSD_ENABLE		tstampenable; // 默认使能
	NET_OSD_TYPETIME	timeFormat; // 默认24小时制
	unsigned int		timePosX; // 默认820
	unsigned int		timePosY; // 默认20
	NET_OSD_ENABLE		nTextEnable; // 默认不使能
	unsigned int		nTextPositionX;// 默认0
	unsigned int		nTextPositionY; // 默认0
	char				overlaytext[NET_OSDTEXTLEN]; //默认为空
}TNetOSDPara;

typedef struct TagNetOSDPara_Ret
{
	NET_COMMON_RET ret;
}TNetOSDPara_Ret;

/* 设置获取背光补偿,强光抑制 NET_CMDID_IMG_GETBLC */
typedef enum
{
	NET_BLC_ENABLE_OFF = 0, // 关闭
	NET_BLC_ENABLE_ON, // 使能
	NET_BLC_ENABLE_MAX
}NET_BLC_ENABLE;

typedef struct TagNetBLCPara
{
	NET_BLC_ENABLE	enblc; // 默认关闭
}TNetBLCPara;

typedef struct TagNetBLCPara_Ret
{
	NET_COMMON_RET ret;
}TNetBLCPara_Ret;

/*设置获取补光灯控制模式参数 NET_CMDID_LED_GETPARA*/
typedef enum{
	NET_LED_CTRLMODE_AUTO = 0, // 自动
	NET_LED_CTRLMODE_OPEN, // 常开
	NET_LED_CTRLMODE_CLOSE, // 常闭
	NET_LED_CTRLMODE_MAX
}NET_LED_CTRLMODE;

typedef struct TagNetLedPara{
	NET_LED_CTRLMODE mode;// 默认自动
	unsigned int level; // 亮度等级1-7,默认为1
	unsigned int maxlevel; // 支持最高级别（客户端只读）
}TNetLedPara;

typedef struct TagNetLedPara_Ret{
	NET_COMMON_RET ret;
}TNetLedPara_Ret;

/*设置获取风扇控制参数 NET_CMDID_FAN_GETPARA*/
typedef enum
{
	NET_FAN_CTRLMODE_AUTO = 0, // 自动
	NET_FAN_CTRLMODE_OPEN, // 常开
	NET_FAN_CTRLMODE_CLOSE, // 常闭
	NET_FAN_CTRLMODE_MAX
}NET_FAN_CTRLMODE;

typedef struct TagNetFanPara
{
	NET_FAN_CTRLMODE mode;// 默认自动
}TNetFanPara;

typedef struct TagNetFanPara_Ret
{
	NET_COMMON_RET ret;
}TNetFanPara_Ret;

/* 镜头继电器动作 NET_CMDID_RELAY_DOACTION*/
typedef enum
{
	NET_RELAY_ACTION_OPEN1_AUTOCLOSE = 0,// 开闸OUT1,打开继电器,打开后1.5秒自动关闭
	NET_RELAY_ACTION_OPEN2_AUTOCLOSE, // 开闸OUT2,打开继电器,打开后1.5秒自动关闭
	NET_RELAY_ACTION_OPEN1,// 开闸OUT1,打开继电器,一直都打开
	NET_RELAY_ACTION_OPEN2, // 开闸OUT2,打开继电器,一直都打开
	NET_RELAY_ACTION_CLOSE1,//关闸OUT1,立刻关闭
	NET_RELAY_ACTION_CLOSE2,//关闸OUT2,立刻关闭
	NET_RELAY_ACTION_MAX
}NET_RELAY_ACTION;

typedef struct TagNetRelayAction
{
	NET_RELAY_ACTION action;
}TNetRelayAction;

typedef struct TagNetRelayAction_Ret
{
	NET_COMMON_RET ret;
}TNetRelayAction_Ret;


/* 设置获取串口参数 NET_CMDID_SERIAL_GETPARA*/
typedef enum{
	NET_SERIAL_PORT_1 = 0, 	// Port 1
	NET_SERIAL_PORT_2, 		// Port 2
	NET_SERIAL_PORT_MAX
}NET_SERIAL_PORT;
typedef enum{
	NET_BAUDRATE_300 = 0, 	// 300
	NET_BAUDRATE_600, 		// 600
	NET_BAUDRATE_1200, 		// 1200
	NET_BAUDRATE_2400,		// 2400
	NET_BAUDRATE_4800,		// 4800
	NET_BAUDRATE_9600,		// 9600
	NET_BAUDRATE_MAX
}NET_SERIAL_BAUDRATE;
typedef enum{
	NET_PARITY_NONE = 0, 	// none
	NET_PARITY_ODD, 		// odd
	NET_PARITY_EVEN, 		// even
	NET_PARITY_MAX
}NET_SERIAL_PARITY;
typedef enum{
	NET_DATABIT_7 = 0, 		// 7 bit
	NET_DATABIT_8, 			// 8 bit
	NET_DATABIT_MAX
}NET_SERIAL_DATABIT;
typedef enum{
	NET_STOPBIT_1 = 0, 		// 1 bit
	NET_STOPBIT_2, 			// 2 bit
	NET_STOPBIT_MAX
}NET_SERIAL_STOPBIT;

typedef enum{
	NET_SERIAL_CTRLMODE_SOFT = 0,
	NET_SERIAL_CTRLMODE_CAMERA,
	NET_SERIAL_CTRLMODE_MAX
}NET_SERIAL_CTRLMODE;
typedef struct TagNetSerialPara{
	NET_SERIAL_PORT uPort;					// 端口号
	NET_SERIAL_BAUDRATE uBaudRate;	// 波特率 300，600，1200，2400，4800，9600
	NET_SERIAL_PARITY uParity;			// 校验值 none(0)，odd(1)，even(2)
	NET_SERIAL_DATABIT uDataBits;		// 数据位 7，8
	NET_SERIAL_STOPBIT uStopBit;		// 停止位 1，2
	NET_SERIAL_CTRLMODE ctrlMode;	// 控制模式,供脱机程序使用,默认为0(软件控制)
}TNetSerialPara;

typedef struct TagNetSerialPara_Ret{
	NET_COMMON_RET ret;
}TNetSerialPara_Ret;


/* 镜头执行动作 NET_CMDID_LENS_DOACTION*/
typedef enum{
	NET_LENS_ACTION_FOCUSADD = 0,// 变焦加
	NET_LENS_ACTION_FOCUSSUB,// 变焦减
	NET_LENS_ACTION_ZOOMADD, // 变倍加
	NET_LENS_ACTION_ZOOMSUB, // 变倍减
	NET_LENS_ACTION_MAX
}NET_LENS_ACTION;

typedef struct TagNetLensAction{
	NET_LENS_ACTION action;
}TNetLensAction;

typedef struct TagNetLensAction_Ret{
	NET_COMMON_RET ret;
}TNetLensAction_Ret;

/*执行格式化TF卡 NET_CMDID_TFCARD_FORMAT*/
typedef enum{
	NET_TFCARD_FORMATRET_OK = 0,// 格式化完成
	NET_TFCARD_FORMATRET_ERR_BUSY, // 格式化失败,设备正忙,
	NET_TFCARD_FORMATRET_ERR_NOTFOUND, // 格式化失败,没找到TF卡
	NET_TFCARD_FORMATRET_ERR_FAILURE, // 格式化失败,
	NET_TFCARD_FORMATRET_MAX
}NET_TFCARD_FORMATRET;

typedef struct TagNetTFCardFormat_Ret{
	NET_TFCARD_FORMATRET ret;
}TNetTFCardFormat_Ret;

/*获取TF卡状态、容量以及使用情况 NET_CMDID_TFCARD_GETINFO*/
typedef enum{
	NET_TFCARD_STATUS_INOK = 0,// TF卡已经插入并且运行正常
	NET_TFCARD_STATUS_INERR, // TF卡已经插入但是读写运行异常
	NET_TFCARD_STATUS_OUT, // 未检测到TF卡
	NET_TFCARD_STATUS_MAX
}NET_TFCARD_STATUS;

typedef struct TagNetTFCardInfo{
	NET_TFCARD_STATUS status;
	unsigned int totalsize; // TF卡的总容量,单位为MBytes;
	unsigned int used; // 已经使用的容量,单位为MBytes;
}TNetTFCardInfo;

/*设置获取车牌识别算法识别区域 NET_CMDID_LPR_GETRECOGNITION*/
typedef struct TagNet_LPRC_VERTEX{
	unsigned X_1000;	//水平方向相对坐标,取值范围0-1000
	unsigned Y_1000;	//竖直方向相对坐标,取值范围0-1000
}TNet_LPRC_VERTEX;

#define NET_LPRC_REGAREA_COUNT	4

/*设置获取车牌识别算法触发区域 NET_CMDID_LPR_GETTRIGGER*/
typedef enum{
	NET_LPRC_DIR_BIDIR = 0,	 //双向触发
	NET_LPRC_DIR_UP2DOWN, //从上到下方向的车辆触发
	NET_LPRC_DIR_DOWN2UP, //从下到上方向的车辆触发
}NET_LPRC_DIR;

typedef enum{
	NET_LPRC_ENABLE_OFF = 0, // 关闭
	NET_LPRC_ENABLE_ON, // 使能
	NET_LPRC_ENABLE_MAX
}NET_LPRC_ENABLE;

typedef enum{
	NET_LPRC_EXTIO_0_TRIG = 0, //外部IO_0触发
	NET_LPRC_EXTIO_1_TRIG,   //外部IO_1触发
	NET_LPRC_EXTIO_MUX_TRIG, //外部IO_0,IO_1触发
	NET_LPRC_VERTEX_TRIG,    //虚拟线圈触发
	NET_LPRC_EXTIO_VERTEX,	 //外部IO_0,IO_1,虚拟线圈同时生效
	NET_LPRC_TRIG_MAX
}NET_LPRC_TRIG_MODE;

typedef struct TagNetLprcTriggerPara
{//虚拟线圈信息定义
	NET_LPRC_ENABLE		byEnable; //是否有效,默认使能
	NET_LPRC_TRIG_MODE	nTrigMode;//触发模式
	unsigned int	   	uNumVertex; //顶点实际个数,默认为4
	TNet_LPRC_VERTEX	struRoiVertex[NET_LPRC_REGAREA_COUNT];		//顶点数组,默认为{{100,275},{900,275},{900,725},{100,725}},
	TNet_LPRC_VERTEX	struVloopVertex[NET_LPRC_REGAREA_COUNT];	//虚拟触发区域，顶点数组,默认为{{100,657},{900,657},{900,725},{100,725}},
	NET_LPRC_DIR		eCrossDir; //穿越方向限制,默认为双向触发
	unsigned int     	uTriggerTimeGap; //对相同车牌的触发时间间隔的限制,单位为秒,默认为10
}TNetLprcTriggerPara;

typedef struct TagNetLprcTriggerPara_Ret{
	NET_COMMON_RET ret;
}TNetLprcTriggerPara_Ret;

typedef enum{
	NET_LPRC_AREA_FULL = 0,
	NET_LPRC_AREA_LOCAL,
	NET_LPRC_AREA_MAX
}NET_LPRC_AREA_MODE;

typedef struct TagNetLprcDefTrigAreaPara{//虚拟线圈信息定义
	NET_LPRC_AREA_MODE		nTrigAreaMode;
	TNet_LPRC_VERTEX		struRoiVertex[NET_LPRC_REGAREA_COUNT];//识别区域，顶点数组,默认为{{100,275},{900,275},{900,725},{100,725}},
	TNet_LPRC_VERTEX		struVloopVertex[NET_LPRC_REGAREA_COUNT];//虚拟触发区域，顶点数组,默认为{{100,657},{900,657},{900,725},{100,725}},
}TNetLprcDefTrigAreaPara;

/*设置获取车牌识别算法默认省份 NET_CMDID_LPR_GETDEFAULTPROVINCE*/
#define NET_LPRC_PROVINCE_STR_LEN	128
typedef struct TagNetLprDefProvince
{
	char strProvinces[NET_LPRC_PROVINCE_STR_LEN]; // 汉字采用GBK编码,每个汉字占用两个字节,默认为"京津冀晋蒙辽吉黑沪苏浙皖闽赣鲁豫鄂湘粤桂琼渝川贵云藏陕甘青宁新"
	unsigned int nCurrIndex; // 当前默认省份的索引,默认为0
}TNetLprDefProvince;

typedef struct TagNetLprDefProvince_Ret{
	NET_COMMON_RET ret;
}TNetLprDefProvince_Ret;

#define NET_LPRC_PROVINCE_MAXINDEX	(31)

typedef struct TagNetLprDefProvinceEX
{
	unsigned int nIndexFirst; // 默认优先省份
	unsigned int nIndexSecond; // 默认次要省份
	unsigned int nIndexThird; // 默认次要省份
	unsigned int nIndexCity; // 默认城市
}TNetLprDefProvinceEx;

typedef struct TagNetLprDefProvinceEx_Ret
{
	NET_COMMON_RET ret;
}TNetLprDefProvinceEx_Ret;

/*设置获取车牌识别算法最大车牌尺寸 NET_CMDID_LPR_GETPLATEMAXSIZE*/
typedef struct TagNetLprcMaxPlateSize{
	unsigned int nMax;			// 检测的最大车牌宽度，以像素为单位,默认为500
	unsigned int nMin;			// 检测的最小车牌宽度，以像素为单位,默认为80
}TNetLprcMaxPlateSize;

typedef struct TagNetLprcMaxPlateSize_Ret{
	NET_COMMON_RET ret;
}TNetLprcMaxPlateSize_Ret;

/*设置获取车牌识别算法所支持的车牌类型 NET_CMDID_LPR_GETPLATETYPE*/
typedef enum
{
	// 参考文通算法的定义,以下表示开关的偏移量,最终还需要在DSP中转换一下.
	NET_LPRC_PLATETYPE_OFFT_INDIVIDUAL = 0,     // 个性化车牌开启 
	NET_LPRC_PLATETYPE_OFFT_TWOROWYELLOW,       //0x2 双层黄色车牌开启
	NET_LPRC_PLATETYPE_OFFT_ARMPOLICE,          //0x4 单层武警车牌开启
	NET_LPRC_PLATETYPE_OFFT_TWOROWARMY,         //0x8 双层军队车牌开启
	NET_LPRC_PLATETYPE_OFFT_TRACTOR,            //0x10 农用车车牌开启
	NET_LPRC_PLATETYPE_OFFT_ONLY_TWOROWYELLOW,  // 只识别双层黄牌开启
	NET_LPRC_PLATETYPE_OFFT_EMBASSY,            //0x40 使馆车牌开启
	NET_LPRC_PLATETYPE_OFFT_ONLY_LOCATION,      // 只定位车牌开启
	NET_LPRC_PLATETYPE_OFFT_ARMPOLICE2,         //0x100 双层武警车牌开启
	NET_LPRC_PLATETYPE_OFFT_CHANGNEI,           // 厂内车牌开启
	NET_LPRC_PLATETYPE_OFFT_MINHANG,            //0x400 民航车牌开启
	NET_LPRC_PLATETYPE_OFFT_CONSULATE,          //0x800 领事馆车牌开启
	NET_LPRC_PLATETYPE_OFFT_NEWENERGY,          //0x1000 新能源车牌开启
	NET_LPRC_PLATETYPE_OFFT_MAX
}NET_LPRC_PLATETYPE_OFFT;

typedef struct TagNetLprcPlateType{
	int nPlateType; // 默认为0
}TNetLprcPlateType;

typedef struct TagNetLprcPlateType_Ret{
	NET_COMMON_RET ret;
}TNetLprcPlateType_Ret;

/*手动触发抓拍一张 NET_CMDID_LPR_MENUTRIGGER*/
typedef struct TagNetLprcMenuTrigger_Ret{
	NET_COMMON_RET ret;
}TNetLprcMenuTrigger_Ret;


/****************************************************************************
DESCRIPTION		: 推送消息定义
****************************************************************************/

/* 推送端口号 */
#define NET_POSHMSG_PORT		(8065)
/* 设置客户端类型 */
typedef enum{
	NET_CILENTTYPE_NULL = 0,

	NET_CILENTTYPE_TUOJI = 0x0010,			// 脱机程序

	NET_CLIENTTYPE_OLD = 0x0100,			// 旧的客户端

	NET_CILENTTYPE_NEW_DEVELOP = 0x0200, 	// 黄工自研发客户端
	NET_CILENTTYPE_NEW_T16ONLINE, 		// 收费系统T16在线监控
	NET_CILENTTYPE_NEW_T16DEBUG, 		// 收费系统T16附带的调试客户端

	NET_CILENTTYPE_MAX
}NET_CILENTTYPE;

typedef struct TagNetPush_ClientType
{
	NET_CILENTTYPE type;
}TagNetPush_ClientType;



/* 推送消息头标识 */
#define NET_PUSHMSG_HEADFLAG	(NET_CMD_HEADFLAG+1)

/* 推送消息ID号定义 */
typedef enum
{
	NET_PUSHMSGID_PLRRESULT = 0, // 车牌识别推送
	NET_PUSHMSGID_NOTIFY_MIN = 0x00001000, // 状态变更通知
	NET_PUSHMSGID_NOTIFY_LINELOOPCHANGED, // 线圈位置改变

	NET_PUSHMSGID_NOTIFY_RS485RECVDATA_1, // 485 1数据
	NET_PUSHMSGID_NOTIFY_RS485RECVDATA_2, // 485 2数据
	// 客户端发送给app
	NET_PUSHMSGID_SET_CLIENTTYPE = 0x00002000,

	NET_PUSHMSGID_MAX
}NET_PUSHMSGID;

/* 推送消息头 */
typedef struct TagNetPushMsgHead{
	unsigned int head_flag;
	NET_PUSHMSGID cmd_id;
	unsigned int len;
	unsigned int reserved;
}TNetPushMsgHead;

typedef struct ClientType
{
	TNetPushMsgHead msgHead;
	TagNetPush_ClientType type;
}ClientType;

/* 车牌识别结果 NET_PUSHMSGID_PLRRESULT*/
typedef struct TagNetPush_Rect
{
	unsigned int left; // 单位为像素点
	unsigned int top;
	unsigned int right;
	unsigned int bottom;
}TNetPush_Rect;

// 以下是车牌颜色定义，和文通算法的一致
typedef enum{
	NET_LPRC_PLATECOLOR_UNKNOWN = 0,	// 未知
	NET_LPRC_PLATECOLOR_BLUE,		// 蓝色
	NET_LPRC_PLATECOLOR_YELLOW,		// 黄色
	NET_LPRC_PLATECOLOR_WHITE,		// 白色
	NET_LPRC_PLATECOLOR_BLACK,		// 黑色
	NET_LPRC_PLATECOLOR_GREEN,		// 绿色
	NET_LPRC_PLATECOLOR_MAX
}NET_LPRC_PLATECOLOR;

// 以下是车牌类型定义，和文通算法的一致
typedef enum{
	NET_LPRC_PLATETYPE_UNKNOWN = 0,   //未知车牌
	NET_LPRC_PLATETYPE_BLUE,   	    //蓝牌
	NET_LPRC_PLATETYPE_BLACK,       //黑牌
	NET_LPRC_PLATETYPE_YELLOW,      //单排黄牌
	NET_LPRC_PLATETYPE_YELLOW2,     //双排黄牌（大车尾牌，农用车）
	NET_LPRC_PLATETYPE_POLICE,      //警车车牌
	NET_LPRC_PLATETYPE_ARMPOL,      //武警车牌
	NET_LPRC_PLATETYPE_INDIVI,      //个性化车牌
	NET_LPRC_PLATETYPE_ARMY,   	    //单排军车
	NET_LPRC_PLATETYPE_ARMY2,       //双排军车
	NET_LPRC_PLATETYPE_EMBASSY,     //使馆牌
	NET_LPRC_PLATETYPE_HONGKONG,    //香港牌
	NET_LPRC_PLATETYPE_TRACTOR,     //拖拉机
	NET_LPRC_PLATETYPE_MACAU,  	    //澳门牌
	NET_LPRC_PLATETYPE_CHANGNEI,    //厂内牌
	NET_LPRC_PLATETYPE_MINHANG,     //民航牌
	NET_LPRC_PLATETYPE_CONSULATE,   //领事馆车牌
	NET_LPRC_PLATETYPE_NEWENERGY,   //新能源车牌
	NET_LPRC_PLATETYPE_MAX
}NET_LPRC_PLATETYPE;


typedef enum
{
	NET_LPRC_white = 0,//白色
	NET_LPRC_GRAY,//灰色
	NET_LPRC_YELLOW,//黄色
	NET_LPRC_PINK,//粉色
	NET_LPRC_RAD,//红色
	NET_LPRC_GREEN,//绿色
	NET_LPRC_BLUE,//蓝色
	NET_LPRC_BROWN,//棕色
	NET_LPRC_BLACK,//黑色
	NET_LPRC_UNKNOWN,//未知
	NET_LPRC_MAX
}
NET_LPRC_VEHICHECOLOR;

typedef enum{
	NET_LPRC_PLATEDETECT_DEFAULT = 0,         // 默认无识别结果
	NET_LPRC_PLATEDETECT_VLOOP, 		// 虚拟线圈有识别结果
	NET_LPRC_PLATEDETECT_EXTIO_0_INVALID,	// 外部IO_0触发无识别结果
	NET_LPRC_PLATEDETECT_EXTIO_0,		// 外部IO_0触发有识别结果
	NET_LPRC_PLATEDETECT_EXTIO_1_INVALID,	// 外部IO_1触发无识别结果
	NET_LPRC_PLATEDETECT_EXTIO_1,		// 外部IO_1触发有识别结果
	NET_LPRC_PLATEDETECT_FORCE_INVALID,     // 手动触发无识别结果
	NET_LPRC_PLATEDETECT_FORCE, 		// 手动触发有识别结果
}NET_LPRC_PLATEDETECT;

typedef struct SZ_LPRS_RESULT_SHOW
{
	NET_LPRC_PLATEDETECT lprDetectFlag;			// 输出类型
	int			havePlate;						// 是否有牌
	char		license[16];					// 车牌字符串
	int			nColor;							// 车牌颜色
	int			nType;							// 车牌类型
	char		time[24];						// 抓拍时间

	int			nPlateW;						// 车牌宽度
	int			nPlateH;						// 车牌高度
	unsigned	nPlatePitch;					// 图像宽度的一行像素所占内存字节数
	unsigned char pBgrVlprImg[640 * 320 * 3];	// 车牌图片

	unsigned	uWidth;							// 抓拍图片宽度
	unsigned	uHeight;						// 抓拍图片高度
	unsigned	uPitch;							// 图像宽度的一行像素所占内存字节数
	//unsigned char pBgrImage[1920 * 1080 * 3];	// 抓拍图片
	unsigned char pBgrImage[2360 * 1320 * 4];	// 抓拍图片
}SZ_LPRS_RESULT_SHOW;


typedef enum
{
	NET_LPRC_VEHICLE_COLOR_NULL = 0,     //未知
	NET_LPRC_VEHICLE_COLOR_WHITE,      //白
	NET_LPRC_VEHICLE_COLOR_BLACK,      //黑
	NET_LPRC_VEHICLE_COLOR_RED,        //红
	NET_LPRC_VEHICLE_COLOR_BLUE,       //蓝
	NET_LPRC_VEHICLE_COLOR_YELLOW,     //黄
	NET_LPRC_VEHICLE_COLOR_GRAY,       //灰
	NET_LPRC_VEHICLE_COLOR_GREEN,      //绿
	NET_LPRC_VEHICLE_COLOR_LIGHTRED,   //浅红
	NET_LPRC_VEHICLE_COLOR_LIGHTBLUE,  //浅蓝
	NET_LPRC_VEHICLE_COLOR_LIGHTYELLOW,//浅黄
	NET_LPRC_VEHICLE_COLOR_LIGHTGRAY,  //浅灰
	NET_LPRC_VEHICLE_COLOR_LIGHTGREEN, //浅绿
	NET_LPRC_VEHICLE_COLOR_DARKBROWN,  //深棕
	NET_LPRC_VEHICLE_COLOR_DARKPINK,   //深粉
	NET_LPRC_VEHICLE_COLOR_LIGHTBROWN, //浅棕
	NET_LPRC_VEHICLE_COLOR_LIGHTPINK,  //浅粉
	NET_LPRC_VEHICLE_COLOR_DARKRED,    //深红
	NET_LPRC_VEHICLE_COLOR_DARKBLUE,   //深蓝
	NET_LPRC_VEHICLE_COLOR_DARKYELLOW, //深黄
	NET_LPRC_VEHICLE_COLOR_DARKGRAY,   //深灰
	NET_LPRC_VEHICLE_COLOR_DARKGREEN,  //深绿
	NET_LPRC_VEHICLE_COLOR_MAX
}NET_LPRC_VEHICLE_COLOR;

typedef enum
{
	NET_LPRC_HAVEPLATE_INVALID = 0,	// 无车牌
	NET_LPRC_HAVEPLATE_VALID, // 有车牌
	NET_LPRC_HAVEPLATE_MAX
}NET_LPRC_HAVEPLATE;

typedef struct TagNetPush_LprResult
{
	NET_LPRC_PLATEDETECT lprDetectFlag; // 输出类型
	char    			 license[16];	// 车牌字符串,汉字用GBK编码,当未检测到车牌时为空字符串
	NET_LPRC_PLATECOLOR  nColor;		// 车牌颜色
	NET_LPRC_PLATETYPE   nType;			// 车牌类型
	TNetPush_Rect		 rcLocation;	// 车牌在抓拍图片中的相对坐标
	int     			 nImageSize;	// 抓拍图片的大小,单位为Bytes
	unsigned int 		 time[7];		// 抓拍时间 (年月日时分秒[星期])
	unsigned char 		 *pBuffer;		// 图像数据
}TNetPush_LprResult;

// 匹配新版本客户端的车牌识别结果推送结构体
typedef struct TagNetPush_LprResultNew
{
	NET_LPRC_PLATEDETECT lprDetectFlag; // 输出类型
	char    			 license[16]; // 车牌字符串,汉字用GBK编码,当未检测到车牌时为空字符串
	NET_LPRC_PLATECOLOR  nColor; // 车牌颜色
	NET_LPRC_PLATETYPE   nType; // 车牌类型
	TNetPush_Rect		 rcLocation; // 车牌在抓拍图片中的相对坐标
	int     			 nImageSize; // 抓拍图片的大小,单位为Bytes
	unsigned int 		 time[7];		// 抓拍时间 (年，月，日，时，分，秒，[星期])

	NET_LPRC_HAVEPLATE	 haveplate; // 是否是无车牌
	NET_LPRC_VEHICLE_COLOR vehicleColor; // 车身颜色
	int					 vehicleLogo; // 车标
	char				 reserve[256]; // 保留字段

	unsigned char 		*pBuffer; // 图像数据
}TNetPush_LprResultNew;

typedef struct _Tag_DrawInfo
{	
	int nsig;//信号强度
	//游标
	TNet_LPRC_VERTEX YouBiaoPoint[NET_LPRC_REGAREA_COUNT];//点坐标
	int npicSize;
	unsigned char bMouseInYouBiao;//鼠标在游标上
	bool bMoveYouBiaoRight;
	bool bDoubleLine;

	//线框
	TNet_LPRC_VERTEX struVloopVertex[NET_LPRC_REGAREA_COUNT];//点坐标
	unsigned char bMouseInLoop;//鼠标在线框中
	int bMoved_Loop;//线框被移动
	bool SelectPoint_1;//点1被选中
	bool SelectPoint_2;//点2被选中
	bool SelectPoint_3;//点3被选中
	bool SelectPoint_4;//点4被选中

	bool bSelectPoint_1_up;//鼠标在点1上
	bool bSelectPoint_2_up;//鼠标在点2上
	bool bSelectPoint_3_up;//鼠标在点3上
	bool bSelectPoint_4_up;//鼠标在点4上

	int nVideoType;
	bool bOnbtnFirst;
	bool bOnbtnSecond;
	bool bResolutionShow;
}Tag_DrawInfo;

//Point g_point1(12, -25);

//回调函数申明

//设备消息回调函数
typedef void (CALLBACK* MessageCallBack)(SzLPRClientHandle handle, long msgType, void* lpStruct, int len, void* lpContext);

//视频数据回调函数
typedef void (CALLBACK* AVDataCallBack)(SzLPRClientHandle handle, char* pBuf, long nSize, STREAM_INFO* pBufInfo, void* lpContext);

//Draw Virtual Loop
typedef void (CALLBACK* DrawVLoopsCallback)(void* pUserData, const SZ_LPRC_IMAGE_INFO* pFrame);

//GET bmp date
typedef void (CALLBACK* GetBMPCallback)(void* pUserData, const BMP_IMAGE_INFO* pFrame);

//Draw Virtual Loop
typedef void (CALLBACK* NetSigCallback)(void* pUserData, int nQuality);

//查找设备回调函数
typedef void (CALLBACK* FindDeviceCallback)(const SZ_LPRC_NETCFG *netCfg, void *pUserData);

//识别结果的回调函数
typedef void (CALLBACK* LprcInfoCallBack)(SzLPRClientHandle handle, void* pUserData, const TNetPush_LprResultNew* pResult, 
	const SZ_LPRC_IMAGE_INFO* pImgFull, const SZ_LPRC_IMAGE_INFO* pImgPlateClip, const SZ_LPRC_IMAGE_INFO* pImgBmpPlateClip);

//RS485回调函数
typedef void (CALLBACK* RS485CallBack)(SzLPRClientHandle handle, int nport, int len, void *data, void *pUserData);

//视频画面绘图回调函数
typedef void (CALLBACK* DrawFunCallBack)(SzLPRClientHandle handle, HDC hDC, RECT local, void *lpContext);

// 升级状态回调函数
typedef void (CALLBACK* UpdateStatusFunCallBack)(SzLPRClientHandle handle, int percent, void *lpContext);

//SDK画图的回调函数
typedef void (CALLBACK *SDKDrawCallBack)(SzLPRClientHandle handle, void *lpContext, Tag_DrawInfo *info);

//识别结果回调函数
typedef void (CALLBACK* RecognitionCallBack)(SzLPRClientHandle handle, char *RetBuf, int RetLet, void* lpContext);

//设备给PC端发送信息的回调
typedef void (CALLBACK* DeviceSendMsgToPc)(SzLPRClientHandle handle, char *RetBuf, int RetLet, void* lpContext);

typedef struct _CHANNEL_CLIENTINFO
{
	char host[MAX_HOST_LEN];
	unsigned long port;
	unsigned long stream;				//0, 1, 2,
	char username[MAX_USER_NAME_LEN];   //用户名
	char password[MAX_PASSWORD_LEN];    //密码

	HWND  hVideoWnd;					//视频窗口句柄

	BYTE  protocol;						//传输协议类型 见 PROTOCOL
	BYTE  notPlay;						//当设置为非0时, 则不启动解码显示模块,作为取视频的操作
	BYTE  tryRGBfirst;					//视频显示时,首先尝试使用RGB表面,默认使用YUV表面
	BYTE  model;						//设备型号,保留
	BYTE  tryOverlay;					//是否使用overlay,暂时无效
	BYTE  res;							//保留
	short webport;						//http 端口,默认80

	unsigned long nColorKey;			//color key

	void *lpContext;					//回调自定义参数
	void *lpContext2;					//回调自定义参数2
	void *lpRs485Context3;              //RS485回调自定义参数
	void *lpSDKDraw;					//sdk画图回调自定义参数
	void *lpRecognition;				//人脸识别设备识别结果回调自定义参数;
	void *lpRecognitionMsg;				//人脸识别设备给PC端发送信息的自定义参数

	MessageCallBack msgFun;				//消息回调函数

}CHANNEL_CLIENTINFO;



//用于设置实时显示车牌信息
typedef enum
{
	NET_LPRC_DRAW_REALTIMERESUALT_OFF = 0, // 关闭,不显示
	NET_LPRC_DRAW_REALTIMERESUALT_ON, // 打开,显示
	NET_LPRC_DRAW_REALTIMERESUALT_MAX
}NET_LPRC_DRAW_REALTIMERESUALT;

typedef struct TagNetLprcDrawRealTimeResualt
{
	NET_LPRC_DRAW_REALTIMERESUALT enable;// 默认打开
}TNetLprcDrawRealTimeResualt;

typedef struct TagNetLprcDrawRealTimeResualt_Ret
{
	NET_COMMON_RET ret;
}TNetLprcDrawRealTimeResualt_Ret;

/*检测无牌车 NET_CMDID_LPR_GET_SNAPNOPLATE*/
typedef enum
{
	NET_LPRC_SNAPNOPLATE_OFF = 0, // 关闭,不检测
	NET_LPRC_SNAPNOPLATE_ON, // 打开,检测
	NET_LPRC_SNAPNOPLATE_MAX
}NET_LPRC_SNAPNOPLATE;

typedef struct TagNetLprcSnapNoPlate
{
	NET_LPRC_SNAPNOPLATE enable;// 默认关闭
}TNetLprcSnapNoPlate;

typedef struct TagNetLprcSnapNoPlate_Ret
{
	NET_COMMON_RET ret;
}TNetLprcSnapNoPlate_Ret;

//////////////////////////////////////////////////////////////////////////
/*提取图片*/
typedef struct TagNetPickupPhotoClient
{
	char		    plateID[16];	//车牌号码(GBK码)
	unsigned int	time[7];		//(年，月，日，时，分，秒，星期) 
	char SaveFilePath[200];
}TNetPickupPhotoClient;

typedef struct TagNetPickupPhoto_ret
{
	NET_COMMON_RET 	ret;
}TagNetPickupPhoto_ret;

/*提取图片*/
typedef struct TagNetPickupPhoto
{
	char		    plateID[16];	//车牌号码(GBK码)
	unsigned int	time[7];		//(年，月，日，时，分，秒，星期) 
}TNetPickupPhoto;

typedef struct TagNetPickupPhoto_Ret
{
	NET_COMMON_RET 	ret;
	unsigned int nlen;
	unsigned char 	*pBuffer; // 图像数据
}TNetPickupPhoto_Ret;


//图片预览获取图片目录
typedef struct TagNetGetPictureDir
{
	char 			path[128];  	//根目录传 "/"
}TNetGetPictureDir;

typedef enum 
{
	NET_FILETYPE_DIR = 0,	//目录
	NET_FILETYPE_FILE,			//文件
	NET_FILETYPE_MAX
}NET_FILETYPE;

//=====================
typedef struct TagNetDirFileObj
{
	NET_FILETYPE		filetype;		//文件类型
	char				filename[64]; 	//文件名
}TNetDirFileObj;

#define MAX_FILE_NUM	(1000)

typedef struct TagNetGetPictureDir_Ret
{
	NET_COMMON_RET	ret;
	unsigned int	count;		//文件或目录数
	char			*pBuffer;	//目录下的文件名或子目录名
}TNetGetPictureDir_Ret;

typedef struct TagNetGetPictureDirInfo_Ret
{
	NET_COMMON_RET	ret;
	unsigned int	count;		//文件或目录数
	TNetDirFileObj	date[1000];	//目录下的文件名或子目录名
}TNetGetPictureDirInfo_Ret;
/////=======================

//图片预览获取图片+++++++++++++++++++++++
typedef struct TagNetGetPicture
{
	char 			filename[128];  	//根目录传 "/"
}TNetGetPicture;

typedef struct TagNetGetPicture_Ret
{
	NET_COMMON_RET 	ret;
	unsigned int	picLen;	  //图片长度
	unsigned char 	*pBuffer; // 图像数据
}TNetGetPicture_Ret;

typedef struct TNetGetPictureInfo_Ret
{
	NET_COMMON_RET 	ret;
	unsigned int	picLen;	  //图片长度
	unsigned char 	date[2000000]; // 图像数据
}TNetGetPictureInfo_Ret;
///+++++++++++++++++

//图片预览下载目录
typedef struct TagNetDownloadPicDir
{
	char 			path[128];  	//目录
}TNetDownloadPicDir;

typedef struct TagNetDownloadPicDir_Ret
{
	NET_COMMON_RET 	ret;
	unsigned int	fileLen;	 		//文件长度
	char 			filename[128];  	//文件名
	unsigned char 	*pBuffer; 			// 文件内容
}TNetDownloadPicDir_Ret;
//////////////////////////////////////////////////////////////////////////


//用于设置是否显示车牌框
typedef enum
{
	NET_LPRC_DRAW_PLATERECT_OFF = 0, // 关闭,不显示
	NET_LPRC_DRAW_PLATERECT_ON, // 打开,显示
	NET_LPRC_DRAW_PLATERECT_MAX
}NET_LPRC_DRAW_PLATERECT;

typedef struct TagNetLprcDrawPlateRect
{
	NET_LPRC_DRAW_PLATERECT enable;// 默认打开
}TNetLprcDrawPlateRect;

typedef struct TagNetLprcDrawPlateRect_Ret
{
	NET_COMMON_RET ret;
}TNetLprcDrawPlateRect_Ret;

//////////////////////////////////////////////////////////////////////////
/*黑白名单*/
#define	NET_MAX_TIMESEG_NUMS	(21)
typedef struct TagTimeSeg
{		/*时间段定义*/
	//Int8			weekDay;  	//星期几(1~7)
	/*时间段定义，一个星期日0时开始，到星期六晚24时结束，以分钟为单位的时间段*/
	unsigned short			startMin;
	unsigned short			offMin;		// 
}TTimeSeg;

typedef enum{ //车辆颜色定义,与15相机偏移数值1
	NET_LPRC_VEHICLECOLOR_NEW_UNKNOWN = 0,//未知
	NET_LPRC_VEHICLECOLOR_NEW_WHITE = 1,//白
	NET_LPRC_VEHICLECOLOR_NEW_SILVER = 2,//灰(银)
	NET_LPRC_VEHICLECOLOR_NEW_YELLOW = 3,//黄
	NET_LPRC_VEHICLECOLOR_NEW_PINK = 4,//粉
	NET_LPRC_VEHICLECOLOR_NEW_RED = 5,//红
	NET_LPRC_VEHICLECOLOR_NEW_GREEN = 6,//绿
	NET_LPRC_VEHICLECOLOR_NEW_BLUE = 7,//蓝
	NET_LPRC_VEHICLECOLOR_NEW_BROWN = 8,//棕
	NET_LPRC_VEHICLECOLOR_NEW_BLACK = 9,//黑
	NET_LPRC_VEHICLECOLOR_NEW_MAX
}NET_LPRC_VEHICLECOLOR_NEW;

typedef enum{ //识别类型(默认允许未知,个性化,农用车)
	NET_LPRC_PLATETYPE_RECOG_NEW_BLUE = 0,//蓝牌	(蓝牌)
	NET_LPRC_PLATETYPE_RECOG_NEW_YELLOW = 1,//黄牌   (单排黄,双排黄)
	NET_LPRC_PLATETYPE_RECOG_NEW_BLACK = 2,//黑牌   (黑牌)
	NET_LPRC_PLATETYPE_RECOG_NEW_COACH = 3,//教练   (教练)
	NET_LPRC_PLATETYPE_RECOG_NEW_POLICE = 4,//警牌   (警牌)
	NET_LPRC_PLATETYPE_RECOG_NEW_ARMPOL = 5,//武警   (武警,双层武警,武警总,双层武警总)
	NET_LPRC_PLATETYPE_RECOG_NEW_ARMY = 6,//军牌   (单排军,双排军)
	NET_LPRC_PLATETYPE_RECOG_NEW_HKMC = 7,//港澳   (香港,澳门进出大陆)
	NET_LPRC_PLATETYPE_RECOG_NEW_EMBASSY = 8,//使领馆 (使领馆)
	NET_LPRC_PLATETYPE_RECOG_NEW_MINHANG = 9,//民航   (民航)
	NET_LPRC_PLATETYPE_RECOG_NEW_NEWENERGY = 10,//新能源(新能源)
	NET_LPRC_PLATETYPE_RECOG_NEW_MAX
}NET_LPRC_PLATETYPE_RECOG;



typedef enum{ // 以下是车牌类型定义，
	NET_LPRC_PLATETYPE_NEW_UNKNOWN = 0,//未知车牌
	NET_LPRC_PLATETYPE_NEW_BLUE = 1,//蓝牌小汽车
	NET_LPRC_PLATETYPE_NEW_BLACK = 2,//黑牌小汽车
	NET_LPRC_PLATETYPE_NEW_YELLOW = 3,//单排黄牌
	NET_LPRC_PLATETYPE_NEW_YELLOW2 = 4,//双排黄牌（大车尾牌，农用车）
	NET_LPRC_PLATETYPE_NEW_POLICE = 5,//警车车牌
	NET_LPRC_PLATETYPE_NEW_ARMPOL = 6,//武警车牌
	NET_LPRC_PLATETYPE_NEW_INDIVI = 7,//个性化车牌
	NET_LPRC_PLATETYPE_NEW_ARMY = 8,//单排军车牌
	NET_LPRC_PLATETYPE_NEW_ARMY2 = 9,//双排军车牌
	NET_LPRC_PLATETYPE_NEW_EMBASSY = 10,//使馆车牌
	NET_LPRC_PLATETYPE_NEW_HONGKONG = 11,//香港进出中国大陆车牌
	NET_LPRC_PLATETYPE_NEW_TRACTOR = 12,//农用车牌
	NET_LPRC_PLATETYPE_NEW_COACH = 13,//教练车牌
	NET_LPRC_PLATETYPE_NEW_MACAO = 14,//澳门进出中国大陆车牌
	NET_LPRC_PLATETYPE_NEW_ARMPOL2 = 15,//双层武警车牌
	NET_LPRC_PLATETYPE_NEW_ARMPOL_ZONGDUI = 16,//武警总队车牌
	NET_LPRC_PLATETYPE_NEW_ARMPOL2_ZONGDUI = 17,//双层武警总队车牌
	NET_LPRC_PLATETYPE_NEW_MINHANG = 18,//民航
	NET_LPRC_PLATETYPE_NEW_NEWENERGY = 19,//新能源
	NET_LPRC_PLATETYPE_NEW_MAX
}NET_LPRC_PLATETYPE_NEW;

typedef struct TagWhiteListInfo
{
	unsigned long long	idx;			//序号
	char		    plateID[16];	//车牌号码, 汉字用utf-8编码
	unsigned int	timeOnCreate;	//创建时间
	unsigned int	timeEnable;		//生效时间
	unsigned int	timeOverdue;	//过期时间
	char			enable;			//是否启用
	char			isBlack;		//是否黑名单(0-白名单   1-黑名单)
	NET_LPRC_VEHICLECOLOR_NEW vehicleColor;	//车辆颜色
	NET_LPRC_PLATETYPE_NEW plateType;		//车牌类型
	char			useTimeSeg;		//是否使用时间段
	TTimeSeg		timeSeg[NET_MAX_TIMESEG_NUMS];	//时间段
	int				customerID;		//客户ID
	char			vehicleRemark[32]; //车辆备注
}TWhiteListInfo;


/*添加单个黑白名单*/
typedef struct TagNetAddWhiteList
{
	TWhiteListInfo		whiteList;
}TNetAddWhiteList;

typedef struct TagNetAddWhiteList_Ret
{
	TWhiteListInfo		whiteList;
}TNetAddWhiteList_Ret;

#define	NET_WHITELISTS_NUMBERS	(20)

typedef struct TagWhiteLists
{
	unsigned int			num;
	TWhiteListInfo  lists[NET_WHITELISTS_NUMBERS];
}TWhiteLists;


/*添加批量黑白名单*/
typedef struct TagNetAddWhiteLists
{
	TWhiteLists		whiteLists;
}TNetAddWhiteLists;

typedef struct TagNetAddWhiteLists_Ret
{
	NET_COMMON_RET ret;
}TNetAddWhiteLists_Ret;

/*删除黑白名单*/
typedef struct TagNetDelWhiteList
{
	long long			idx;			//黑白名单的序号
}TNetDelWhiteList;

typedef struct TagNetDelWhiteList_Ret
{
	NET_COMMON_RET ret;
}TNetDelWhiteList_Ret;

/*清空黑白名单*/
typedef struct TagNetClearWhiteList_Ret
{
	NET_COMMON_RET ret;
}TNetClearWhiteList_Ret;

/*更新黑白名单*/
typedef struct TagNetUpdateWhiteList
{
	TWhiteListInfo		whiteList;
}TNetUpdateWhiteList;

typedef struct TagNetUpdateWhiteList_Ret
{
	NET_COMMON_RET ret;
}TNetUpdateWhiteList_Ret;

/*查询黑白名单页*/
typedef struct TagNetQueryWhiteLists
{
	unsigned int 			pageIdx;		//页码
	char 			plateID[16];	//车牌号码
}TNetQueryWhiteLists;

typedef struct TagNetQueryWhiteLists_Ret
{
	unsigned int	count;			//黑白名单总记录数
	TWhiteLists		lists;
}TNetQueryWhiteLists_Ret;

/*按车牌查询黑白名单*/
typedef struct TagNetQueryWhiteList
{
	char	plateID[16];		//车牌号码
}TNetQueryWhiteList;

typedef struct TagNetQueryWhiteList_Ret
{
	TWhiteListInfo	list;
}TNetQueryWhiteList_Ret;


/*白名单验证模式设置*/
typedef enum
{
	NET_WHITELIST_CHECKMODE_OFF = 0, // 关闭,不使能
	NET_WHITELIST_CHECKMODE_ON,    // 打开,使能
	NET_WHITELIST_CHECKMODE_AUTO,  //脱机使能
	NET_WHITELIST_CHECKMODE_MAX
}NET_WHITELIST_CHECKMODE;

typedef struct TagNetWhitelistCheckSet
{
	NET_WHITELIST_CHECKMODE		enableMode;	//白名单使能模式
	BYTE						openMode;	//军警车放行模式(1--自动放行    0--非自动放行)
}TNetWhitelistCheckSet;

typedef struct TagNetWhitelistCheckSet_Ret
{
	NET_COMMON_RET ret;
}TNetWhitelistCheckSet_Ret;

/*白名单模糊匹配设置*/
typedef enum
{
	NET_WHITELIST_MATCHMODE_ALL = 0, 		// 精确匹配 (车牌号完全匹配) 
	NET_WHITELIST_MATCHMODE_SIMILAR,    // 相似字符匹配(包括:0-D,8-B,0-Q,E-F) 
	NET_WHITELIST_MATCHMODE_MISTINESS,  //普通字符模糊匹配
	NET_WHITELIST_MATCHMODE_MAX
}NET_WHITELIST_MATCHMODE;

typedef struct TagNetWhitelistMatchSet
{
	NET_WHITELIST_MATCHMODE		matchMode;	//白名单匹配模式
	BYTE						misLprcLen;	// (模糊匹配)允许误识别长度(1,   2,  3)
	BYTE						ignoreCHN;  //忽略汉字(0--不忽略      1--忽略)
}TNetWhitelistMatchSet;

typedef struct TagNetWhitelistMatchSet_Ret
{
	NET_COMMON_RET ret;
}TNetWhitelistMatchSet_Ret;

/*输出联动*/
typedef enum
{
	NET_DEV_INPUT_WHITELIST_PASS,		//白名单验证通过
	NET_DEV_INPUT_WHITELIST_NOPASS,		//白名单验证不通过
	NET_DEV_INPUT_NO_PLATE,				//无车牌
	NET_DEV_INPUT_BLACKLIST,			//黑名单
	NET_DEV_INPUT_SPECIAL_PLATE,		//特殊车牌
	NET_DEV_INPUT_GPIOINCTL1,			//GPIOIN1 	
	NET_DEV_INPUT_GPIOINCTL2,			//GPIOIN2
	NET_DEV_INPUT_TYPE_MAX
}DEVICE_INPUT_TYPE;

typedef struct TagNetDevOutputConfig
{
	DEVICE_INPUT_TYPE		inputType;		//触发输入的类型
	BYTE					gpioOut1; 		//GPIOOUT1输出(0--未选中    1--选中)
	BYTE					gpioOut2; 		//GPIOOUT2输出(0--未选中    1--选中)
	BYTE					rs485Out_1; 	//rs485Out_1输出(0--未选中    1--选中)
	BYTE					rs485Out_2; 	//rs485Out_2输出(0--未选中    1--选中)
	BYTE					reserved1;
	BYTE					reserved2;
	BYTE					reserved3;
	BYTE					reserved4;
}TNetDevOutputConfig;

typedef struct TagNetDevOutputParam
{
	TNetDevOutputConfig		outConfig[NET_DEV_INPUT_TYPE_MAX]; //多个输出配置输出的信息
}TNetDevOutputParam;

typedef struct TagNetDevOutputParam_Ret
{
	NET_COMMON_RET ret;
}TNetDevOutputParam_Ret;

//////////////////////////////////////////////////////////////////////////
/*测试 NET_CMDID_TSET_START*/
typedef struct TagNetTestStart_Ret
{
	NET_COMMON_RET ret;
}TNetTestStart_Ret;

typedef struct TagNetTestDefstatus_Ret{
	NET_COMMON_RET ret;
}TNetTestDefstatus_Ret;

typedef struct TagNetTestAllout_Ret
{
	NET_COMMON_RET ret;
}TNetTestAllout_Ret;

typedef struct TagNetTestAllin_Ret
{
	NET_COMMON_RET retIn1;
	NET_COMMON_RET retIn2;
	NET_COMMON_RET retRs485_1;
	NET_COMMON_RET retRs485_2;
}TNetTestAllin_Ret;

typedef struct TagNetTestOhter_Ret
{
	NET_COMMON_RET retRTC;
	NET_COMMON_RET retEEPROM;
	NET_COMMON_RET retUSB;
	NET_COMMON_RET retTFCard;
}TNetTestOhter_Ret;

typedef struct TagNetTestReset_Ret
{
	NET_COMMON_RET retReset;
}TNetTestReset_Ret;

typedef struct TagNetTestExit_Ret
{
	NET_COMMON_RET ret;
}TNetTestExit_Ret;

/*特殊车牌设置*/
typedef struct TagNetSpecialPlateSet
{
	BYTE	plateType[NET_LPRC_PLATETYPE_NEW_MAX]; //NET_LPRC_PLATETYPE_NEW_MAX
}TNetSpecialPlateSet;

typedef struct TagNetSpecialPlateSet_Ret
{
	NET_COMMON_RET ret;
}TNetSpecialPlateSet_Ret;


/*485透传NET_CMDID_SERIAL_TRANSFER_OUT*/
#define NET_SERIALTRAN_MAXLEN	(256)
typedef struct TagNetSerialTransferOut
{
	NET_SERIAL_PORT uPort; // 485端口号
	unsigned int length; // 发送数据的长度,取值范围0-256
	unsigned char buffer[NET_SERIALTRAN_MAXLEN]; // 发送数据的缓冲区,没有使用就填0
}TNetSerialTransferOut;

typedef struct TagNetSerialTransferOut_Ret
{
	NET_COMMON_RET ret;
}TNetSerialTransferOut_Ret;


typedef enum
{
	NET_SERIALIN_EN_OFF = 0,
	NET_SERIALIN_EN_ON,
	NET_SERIALIN_EN_MAX
}NET_SERIALIN_EN;

typedef struct TagNetSerialTransferIn
{
	NET_SERIAL_PORT uPort; // 485端口号
	NET_SERIALIN_EN enable; // 打开或关闭
}TNetSerialTransferIn;

typedef struct TagNetSerialTransferIn_Ret
{
	NET_COMMON_RET ret;
}TNetSerialTransferIn_Ret;


typedef enum
{
	NET_ENC_RES_352_288 = 0,
	NET_ENC_RES_640_480,
	NET_ENC_RES_720_480,
	NET_ENC_RES_1280_720,
	NET_ENC_RES_1920_1080,
	NET_ENC_RES_MAX
}NET_ENC_RES;

typedef enum
{
	NET_ENC_TYPE_H264 = 0,
	NET_ENC_TYPE_MJPEG,
	NET_ENC_TYPE_H265,
	NET_ENC_TYPE_MAX
}NET_ENC_TYPE;

typedef enum
{
	NET_ENC_BRMODE_CBR = 0, // 定码率
	NET_ENC_BRMODE_VBR, // 编码率
	NET_ENC_BRMODE_MAX
}NET_ENC_BRMODE;

typedef enum
{
	NET_ENC_IMGQ_LEVEL0 = 0, // 最流畅
	NET_ENC_IMGQ_LEVEL1, // 较流畅
	NET_ENC_IMGQ_LEVEL2, // 流畅
	NET_ENC_IMGQ_LEVEL3, // 中等
	NET_ENC_IMGQ_LEVEL4, // 清晰
	NET_ENC_IMGQ_LEVEL5, // 较清晰
	NET_ENC_IMGQ_LEVEL6, // 最清晰
	NET_ENC_IMGQ_MAX
}NET_ENC_IMGQ;

typedef struct TagNetEncPara
{
	NET_ENC_RES res; // 分辨率 默认NET_ENC_RES_1920_1080
	unsigned int framerate; // 帧率 取值范围1-25 默认25
	NET_ENC_TYPE enctype; // 编码类型 默认NET_ENC_TYPE_H264
	NET_ENC_BRMODE bitratemode; // 码率控制模式 默认NET_ENC_BRMODE_CBR
	unsigned int bitratemax; // 码率上限,编码率时有效,取值范围256-4000,默认1000
	NET_ENC_IMGQ imgquality; // 图像质量,定码率时有效,默认NET_ENC_IMGQ_LEVEL3
}TNetEncPara;


typedef enum
{
	NET_FLASHLED_EN_OFF = 0,
	NET_FLASHLED_EN_ON,
	NET_FLASHLED_EN_MAX
}NET_FLASHLED_EN;

typedef struct TagNetFlashLEDControl
{
	NET_FLASHLED_EN enable; // 开启爆闪灯联动控制,默认关闭NET_FLASHLED_EN_OFF

	int tdelay; // 触发延时,单位为ms,取值范围为0-3000ms,
	int fhold; // 爆闪持续时间,单位为ms,取值范围为0-3000ms,
	int	fdelay; // 爆闪延迟,单位为ms,取值范围为0-3000ms,

	int in_gpio1; // 触发事件-地感1(输入开关量1)(0--未选中    1--选中)
	int in_gpio2; // 触发事件-地感2(输入开关量2)(0--未选中    1--选中)
	int in_res1;
	int in_res2;
	int in_res3;
	int in_res4;

	int out_gpio1; // 爆闪灯控制信号-开闸(输出开关量1)(0--未选中    1--选中)
	int out_gpio2; // 爆闪灯控制信号-开闸(输出开关量2)(0--未选中    1--选中)
	int out_res1;
	int out_res2;
	int out_res3;
	int out_res4;
}TNetFlashLEDControl;

/*设置获取应用层过滤的车牌类型 NET_CMDID_LPR_GETPLATETYPE_NEW*/
typedef struct TagNetLprcPlateTypeNew
{
	int nPlateType; // // 默认为0x7FF 全开
}TNetLprcPlateTypeNew;

typedef struct TagNetLprcPlateTypeNew_Ret
{
	NET_COMMON_RET ret;
}TNetLprcPlateTypeNew_Ret;

#define NET_PM_MAXNUM	(20)
typedef struct TagNetLprPlateMap
{
	int enable; // 0-disable,1-enable
	char src[NET_PM_MAXNUM][16]; // 字符长度最大为15字节(最后一个字节为结束符),为空表示该项不生效
	char dst[NET_PM_MAXNUM][16];
}TNetLprPlateMap;

typedef struct TagNetLprPlateMap_Ret
{
	NET_COMMON_RET ret;
}TNetLprPlateMap_Ret;

#define NET_PF_MAXNUM	(20)
typedef struct TagNetLprcPlateFilter
{
	int enable; // 允许车牌过滤,0-不过滤,上报所有的识别类型,1-过滤
	int type;// 保留字段,过滤类型,默认为0-精确匹配
	char str[NET_PF_MAXNUM][16];// 当车牌输出结果中有包含本字段中的任意字符串，相机将不输出；
}TNetLprcPlateFilter;


typedef struct TagNetLprcPlateFilter_Ret
{
	NET_COMMON_RET ret;
}TNetLprcPlateFilter_Ret;

typedef struct TagNetCheDuiMode
{
	int brunning; // 0-关闭,1-开启
}TNetCheDuiMode;

typedef struct TagNetCheDuiMode_Ret
{
	NET_COMMON_RET ret;
}TNetCheDuiMode_Ret;

typedef struct TagNetStableOutput
{
	int enable; // 0-关闭稳定结果输出,1-打开稳定结果输出,默认关闭
}TNetStableOutput;

typedef struct TagNetStableOutput_Ret
{
	NET_COMMON_RET ret;
}TNetStableOutput_Ret;

typedef struct TagNetPlatformTcp
{
	unsigned int tcpEnable;  	// 是否开启心跳  取值 0  或 1
	unsigned int tcpPort;      	// 端口号 9005
	char serverip[16]; 	// 服务器IP 地址
	char camid[16];  	// 像机 唯一标示符
}TNetPlatformTcp;

typedef struct TagNetHttpPost
{
	unsigned int httpEnable; 	// http 推送 使能 
	unsigned int httpPort; 		// 端口号 9003
	unsigned int timeout;  		// 超时 时间
	unsigned int repeat;   		// 重发次数 0 不开启  1~5 发送次数
	unsigned int lprResult;  	// 是否发送识别结果 0 不发送  1 发送
	unsigned int sendPic;  		// 是否发送图片 0 不发送 1 发送  	lprResult 为不发送时，此值无效
	char address[64];  	// http 地址
}TNetHttpPostMsg;

typedef struct TagNetRabbitmq
{
	unsigned  int    rabbitEnable;  // mq 使能
	char  serverip[16]; 	// mq 服务器IP 地址 和心跳及http 推送 可能不是一个服务器
	char  username[16]; 	// 登录时的用户名和密码
	char  password[16];
}TNetRabbitmq;

typedef struct Tag4GMsg
{
	char    moudleType[32];
	char    user[16];
	char    pwd[16];
	int     isDefUser;
	int     asyncmapDef;
	int     enable4GConn;
	int     startAutoConn;
	int     connStatus;
	char    ipAddress[32];
}T4GMsg;

// P2P直播模块参数配置
typedef struct TagNetPeergineLive{
	unsigned  int peergineLiveEnable;  	// P2P使能
	unsigned char lpszUser[32];  		// 客户端时为帐号用户名
	unsigned char lpszPass[32]; 		// 客户端时为帐号密码
	unsigned char lpszSvrAddr[128]; 	// P2P服务器的地址端口
	unsigned char lpszRelayList[128];	// 中继服务器地址列表，P2P无法穿透的情况下通过中继服务器转发
}TNetPeergineLive;
typedef struct TagNetPeergineLive_Ret{
	NET_COMMON_RET ret;
}TNetPeergineLive_Ret;

typedef struct TagNetRebootTime
{
	unsigned int enable;
	unsigned int wday; // 取 [0,7] 取值区间为[0,7]，其中0代表每天，1代表星期一, 2代表星期二，7代表星期日
	unsigned int hour;
	unsigned int min;
	unsigned int startflag;
}TNetRebootTime;

//主从相机参数配置
typedef struct TagNetMasterSlavePara
{
	unsigned char       enable;         //是否启用主从相机模式 1-启用 0-不启用
	unsigned char       master;         //是否主相机 1-主相机  0-从相机
	unsigned int      timeout;        //车牌匹配超时时间(s)
	char        materIP[16];   //主相机IP    
}TNetMasterSlavePara;

typedef struct TagNetMasterSlavePara_Ret
{
	NET_COMMON_RET ret;
}TNetMasterSlavePara_Ret;


typedef struct TagNetTuojiVersion
{
	unsigned char	cMajorVersion;      /*主版本号*/
	unsigned char   cMinorVersion;      /*次版本号*/
	unsigned char   cModifyVersion;     /*修订版本号*/
	unsigned char   cCustomerCode;      /*客户代码*/
	unsigned char   cProtocolCode;      /*协议代码*/
	unsigned char   cReserved;          /*预留*/
	char    szModifyDate[8];    /*修改日期*/
	char    szName[16];         /*软件内部名称*/
}TNetTuojiVersion;

/* 伪车牌过滤 NET_CMDID_LPR_GET_FILTERPLATE */
typedef struct TagNetFilterPlate
{
	int enable; // 0-关闭伪车牌过滤,1-打开伪车牌过滤,默认关闭
}TNetFilterPlate;

typedef struct TagNetFilterPlate_Ret
{
	NET_COMMON_RET ret;
}TNetFilterPlate_Ret;

/*是否启用计费功能*/
typedef struct TagNetEnableTuoji
{
	int 	enable;		/*是否启用计费功能: 0-关闭，1-开启    */
}TNetEnableTuoji;

typedef struct TagNetEnableTuoji_Ret
{
	NET_COMMON_RET ret;
}TNetEnableTuoji_Ret;

typedef enum
{
	NET_IMG_ZOOM_MIN = 0,
	NET_IMG_ZOOM_2_4M, //  2 到 4 M 
	NET_IMG_ZOOM_4_6M, //  4 到 6M 
	NET_IMG_ZOOM_6_8M, //  4 到 6M 
	NET_IMG_ZOOM_MAX
}NET_IMG_ZOOM;

typedef struct TagNetImgZoomPara
{
	NET_IMG_ZOOM zoomTpye; // 缩放比例 默认NET_IMG_ZOOM_2_4M
}TNetImgZoomPara;

typedef struct TNetImgZoomPara_Ret
{
	NET_COMMON_RET ret;
}TNetImgZoomPara_Ret;


typedef enum
{
	NET_IMG_PIXEL_200W = 0,
	NET_IMG_PIXEL_300W, //  2 到 4 M 
	NET_IMG_PIXEL_MAX
}NET_IMG_Pixel;

typedef struct TagNetImgPixel
{
	NET_IMG_Pixel nPixel; // 像素大小
}TagNetImgPixel;

typedef struct TagNetRelayDelayTime{
	int delaytime; // 继电器延时 范围 1000ms ~ 5000ms 默认 1500mS
}TNetRelayDelayTime;

typedef struct TNetRelayDelayTime_Ret{
	NET_COMMON_RET ret;
}TNetRelayDelayTime_Ret;

#endif





