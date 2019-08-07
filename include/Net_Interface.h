/**************************************************************************
* 版    权： 	Copyright (c) 2015 
* 文件名称：	Net_Interface.h
* 文件标识： 
* 内容摘要：    摄像机网络开发SDK,处理视频流、图片及控制消息
* 其它说明： 
* 当前版本：	V1.0
* 作    者	
* 完成日期：	2013年08月28日
**************************************************************************/
#ifndef __DCINTERFACE_H
#define __DCINTERFACE_H

#ifdef     NET_API
#else
   #define NET_API __declspec(dllimport)
#endif

#include "Net_Setup.h"
#ifdef __cplusplus
extern "C"
{
#endif

/**************************************************************************
 *                         数据类型                                    *
 **************************************************************************/

#define LENS_MAX_STEPS  2284/4/2
#define MAX_PAY_ITEM       		        4
#define MAX_TIMESECTION_NUM		 6	
typedef enum
{
	LIGHT_MODE_CLOSE = 0,
	LIGHT_MODE_OPEN,
	LIGHT_MODE_AUTO,
	LIGHT_MODE_ALL,
}E_LightMode;

typedef enum 
{ 
	WL_MODE_UNKNOW = 0, 
	WL_MODE_OFFLINE,	 /*脱机使能*/ 
	WL_MODE_ENABLE,	 /*白名单使能，不分区联机、脱机*/ 
	WL_MODE_DISABLE,	 /*白名单不使能*/ 
	WL_MODE_MAX 
}E_WhiteListMode; 

typedef struct
{
	unsigned char ucMode;
	unsigned char ucArmyPoliceEn; /*军警牌自动放行使能标识*/ 
	unsigned char ucNotSnaptmp;/*脱机下不保存临时车记录*/
	unsigned char acReserved;
}T_WhiteListMode;

typedef enum
{
	LED_SUB_MOD_VEH_PLATE=0,/*车牌显示*/
	LED_SUB_MOD_VEH_WELCOME,/*欢迎语显示*/
	LED_SUB_MOD_VEH_PAY,  /*停车付费显示*/
	LED_SUB_MOD_VEH_TIME, /*停车时间显示*/
	LED_SUB_MOD_VEH_PERIOD, /*月租有效期显示*/
	LED_SUB_MOD_TIME,/*时间显示，格式:XXXX年XX月XX时XX分*/
	LED_SUB_MOD_VEH_LEFT,/*剩余停车位显示*/
	LED_SUB_MOD_CUSTOM,  /*自定义内容显示*/
	LED_SUB_MOD_MAX,
}E_SubLedMode;

typedef struct
{
	unsigned char 	ucEnable;
	unsigned char  	ucInterval;//时间间隔  s秒
	unsigned char   ucLedLine;//双行屏，上行1；下行2;
	unsigned char   ucMode;//E_SubLedMode
	unsigned char   aucContent[MAX_LED_CONTENT]; //GB2312，自定义模式有效
}T_SubLedSetup;

typedef struct
{
	//unsigned char           ucType;//入口空闲-0; 入口忙-1; 出口空闲-2; 出口忙-3;
	unsigned char           ucAudioEnable;
	unsigned char           ucReserved[3];
	T_SubLedSetup   atSubLedInIdle[MAX_LED_COUNT];//入口空闲
	T_SubLedSetup   atSubLedInBusy[MAX_LED_COUNT];//入口忙  
	T_SubLedSetup   atSubLedOutIdle[MAX_LED_COUNT];//出口空闲
	T_SubLedSetup   atSubLedOutBusy[MAX_LED_COUNT];//出口忙
}T_LedSetup;

typedef enum _E_LED_COLOR
{
	E_LED_COLOR_RED = 0,
	E_LED_COLOR_GREEN,
	E_LED_COLOR_YELLOW
}E_LED_COLOR;

//#define MAX_LED_CONTENT         64
#define MAX_LZ_LED_COUNT         4
#define MAX_VEL_CONTENT         32

typedef struct
{
	unsigned char 	ucEnable;
	unsigned char  	ucInterval;		//时间间隔  s秒
	unsigned char   ucLedLine;		//(保留不用)
	unsigned char   ucLedcolor;  	//E_LED_COLOR
	unsigned short  usModeBit;		
	unsigned char  ucReserved[2];
	unsigned char  welAudioText[MAX_VEL_CONTENT]; 	//GB2312，压地感报欢迎语
	unsigned char  levAudioText[MAX_VEL_CONTENT]; 	//GB2312，开闸报欢迎语
	unsigned char  aucContent[MAX_LED_CONTENT]; //GB2312，自定义模式有效
}T_LZ_SubLedSetup;

typedef struct
{
	//unsigned char           ucType;//入口空闲-0; 入口忙-1; 出口空闲-2; 出口忙-3;
	unsigned char   ucAudioEnable;
	unsigned char   ucReserved[3];
	T_LZ_SubLedSetup   atSubLedIdle[MAX_LZ_LED_COUNT];//空闲
	T_LZ_SubLedSetup   atSubLedBusy[MAX_LZ_LED_COUNT];//忙  
}T_LZ_LedSetup;

typedef struct
{
	unsigned char   ucLedSubType;  //E_LedScreenSubType
	unsigned char   ucReserved[3];
	char			acInContent[MAX_LED_CONTENT]; //GB2312，自定义模式有效
	char			acOutContent[MAX_LED_CONTENT]; //GB2312，自定义模式有效
}T_DCScreenSetup;

/*帧信息*/
#ifndef _T_FRAMEINFO_
#define _T_FRAMEINFO_
typedef struct
{
	unsigned int uiFrameId;          //帧ID
	unsigned int uiTimeStamp;        //RTP时间戳
	unsigned int uiEncSize;          //帧大小
	unsigned int uiFrameType;        // 1:i帧 0:其它

}T_FrameInfo;
#endif

typedef struct
{
	unsigned int	uiImageId;
	unsigned char   ucLightIndex;	/*车道编号，1~25,与相机的车道设置一致*/
	unsigned char   ucLightMode;	/*E_LightMode*/
	unsigned short  usGroupId;
}T_DCImageSnap;

typedef enum
{
	COLOR_TYPE_BLUE = 0,
	COLOR_TYPE_YELLO,
	COLOR_TYPE_WHITE,
	COLOR_TYPE_BLACK,
	COLOR_TYPE_OTHER,
	COLOR_TYPE_GREEN,
	COLOR_TYPE_YELLOW_GREEN,
	COLOR_TYPE_ALL, 
}E_ColorType;

typedef enum
{
	VEHCOLOR_UNKNOW = 0,/*未知*/
	VEHCOLOR_WHITE = 1,/* 白*/
	VEHCOLOR_BLACK = 2,/* 黑*/
	VEHCOLOR_RED = 3,/* 红*/
	VEHCOLOR_BLUE = 4,/* 蓝*/
	VEHCOLOR_YELLOW = 5,/* 黄*/
	VEHCOLOR_GRAY = 6,/* 灰*/
	VEHCOLOR_GREEN = 7,/* 绿*/
	VEHCOLOR_LIGHT_RED = 8,/*浅红*/
	VEHCOLOR_LIGHT_BLUE = 9,/*浅蓝*/
	VEHCOLOR_LIGHT_YELLOW = 10,/*浅黄*/
	VEHCOLOR_LIGHT_GRAY = 11,/*浅灰*/
	VEHCOLOR_LIGHT_GREEN = 12,/*浅绿*/
	VEHCOLOR_DARK_BROWN = 13,/*深棕*/
	VEHCOLOR_DARK_PINK = 14,	/*深粉*/
	VEHCOLOR_LIGHT_BROWN = 15,/*浅棕*/
	VEHCOLOR_LIGHT_PINK = 16, /*浅粉*/
	VEHCOLOR_DARK_RED = 17,/*深红*/
	VEHCOLOR_DARK_BLUE = 18,/*深蓝*/
	VEHCOLOR_DARK_YELLOW = 19,/*深黄*/
	VEHCOLOR_DARK_GRAY = 20,/*深灰*/
	VEHCOLOR_DARK_GREEN = 21,/*深绿*/
	VEHCOLOR_ALL,
}E_VehColorType;


//车标信息
typedef enum
{
	UNKNOWN_FLAG,
	TOYOTA,        /*丰田*/
	VolksWagen,    /*大众*/
	HONDA,         /*本田*/
	PEUGEOT,       /*标致*/
	HYUNDAI,       /*现代*/
	BUICK,         /*别克*/
	AUDI,          /*奥迪*/
	KIA,           /*起亚*/
	JEEP,          /*吉普*/
	FORD,          /*福特*/
	BENZ,          /*奔驰*/
	BMW,           /*宝马*/
	MAZDA,         /*马自达*/
	SUZUKI,        /*铃木*/
	CITROEN,       /*雪铁龙*/
	NISSAN,        /*尼桑*/
	MITSUBISHI,    /*三菱*/
	LEXUS,         /*雷克萨斯*/
	CHEVROLET,     /*雪佛兰*/
	VOLVO,         /*沃尔沃*/
	FIAT,          /*菲亚特*/
	BYD,           /*比亚迪*/
	CHERY          /*奇瑞*/
}E_VehicleFlag;

//车型信息
typedef enum    its_tb_vt
{
	TB_VEHICLE_TYPE_NULL=0,    //未知
    TB_VEHICLE_TYPE_LARGE=1,   //大型车
    TB_VEHICLE_TYPE_MEDIUM,    //中型车
    TB_VEHICLE_TYPE_SMALL,     //小型车 
	TB_VEHICLE_TYPE_MOTOCYCLE, //摩托车
    TB_VEHICLE_TYPE_PEDESTRIAN,//行人
}ITS_Tb_Vt; 

typedef enum
{
	VIO_CODE_NORMAL = 0,  		/*正常车辆*/
	VIO_CODE_BLACKLIST,    		/*黑名单车辆*/
	VIO_CODE_OVERSPEED_LITTLE,	/*超速50%以内*/
	VIO_CODE_OVERSPEED_MID,		/*超速50%~100%*/
	VIO_CODE_OVERSPEED_MORE,    /*超速100%以上*/
	VIO_CODE_RETROGRADE,   		/*逆行*/
	VIO_CODE_RUSH_REDLIGHT,		/*闯红灯*/
	VIO_CODE_LOWSPEED, 			/*低速行驶*/
	VIO_CODE_PROHIBIT,			/*禁行*/
	VIO_CODE_EXCEED,			/*越线*/
	VIO_CODE_ABNORMAL_STEER,	/*不按车道行驶*/
	VIO_CODE_ILLEGAL_STOP,      /*违停*/
	VIO_CODE_FACE_MAIN,         /*人脸大图*/
	VIO_CODE_FACE,              /*人脸*/
	VIO_CODE_ALL,
}E_ViolationCode;

/* 行车方向定义 */
typedef enum
{
	EAST_TO_WEST = 0,
	WEST_TO_EAST,
	SOUTH_TO_NORTH,
	NORTH_TO_SOUTH
}E_Direction;

typedef enum
{
	CONN_STATE_UNKNOW = 0, 
	CONN_STATE_TRYING, 		/*连接中*/
	CONN_STATE_SUCC,		/*连接成功*/
	CONN_STATE_DIS,			/*连接失败*/
	CONN_STATE_ALL,
}E_ConnState;

typedef enum 
{ 
	SNAP_MODE_UNKNOW = 0, 
	SNAP_MODE_MANUAL,	 /*手动*/ 
	SNAP_MODE_VIDEO,     /*视频*/ 
	SNAP_MODE_LOOP,      /*线圈*/ 
	SNAP_MODE_MAX, 
}E_SnapType;

typedef enum its_ep_pt
{
	EP_PLATE_TYPE_NULL=0,      //未知
	EP_PLATE_TYPE_BLUE,        //普通蓝牌
	EP_PLATE_TYPE_BLACK,       //普通黑牌
	EP_PLATE_TYPE_YELL,        //普通黄牌
	EP_PLATE_TYPE_YELL2,       //双层黄牌
	EP_PLATE_TYPE_POL,         //警察车牌
	EP_PLATE_TYPE_APOL,        //武警车牌
	EP_PLATE_TYPE_APOL2,       //双层武警    
	EP_PLATE_TYPE_ARM,         //单层军牌
	EP_PLATE_TYPE_ARM2,        //双层军牌
	EP_PLATE_TYPE_INDI,        //个性车牌
	EP_PLATE_TYPE_NEWN,        //新能源小车牌
	EP_PLATE_TYPE_NEWN1,       //新能源大车牌
	EP_PLATE_TYPE_EMB,         //大使馆车牌
	EP_PLATE_TYPE_CON,         //领事馆车牌
	EP_PLATE_TYPE_MIN,         //民航车牌
}ITS_Ep_Pt;

typedef enum
{
	IPNC_TYPE_UNKNOW = 0,
	IPNC_TYPE_ENTRY,
	IPNC_TYPE_EXIT,
	IPNC_TYPE_PLATE_REC,  /*车牌识别相机*/
	IPNC_TYPE_MAX,     
}E_IpncType;

/*车辆图片抓拍信息*/
typedef struct 
{
	unsigned short 	usWidth;   /*图片的宽度，单位:像素*/
	unsigned short	usHeight;  /*图片的高度，单位:像素*/
	unsigned char	ucVehicleColor;/*车身颜色，E_ColorType*/
	unsigned char	ucVehicleBrand;/*车标，E_VehicleFlag*/
	unsigned char	ucVehicleSize;/*车型(1大2中3小)，ITS_Tb_Vt,目前根据车牌颜色来区分大小车，蓝牌为小车，黄牌为大车*/
	unsigned char	ucPlateColor;/*车牌颜色，E_ColorType*/
	char  			szLprResult[16];/*车牌，若为'\0'，表示无效GB2312编码*/
	unsigned short	usLpBox[4];  /*车牌位置，左上角(0, 1), 右下角(2,3)*/
	unsigned char	ucLprType;/*车牌类型, ITS_Ep_Pt*/
	unsigned short 	usSpeed;     /*单位km/h*/
	unsigned char 	ucSnapType;  /*抓拍模式, E_SnapType*/
	unsigned char 	ucReserved;     
	char 			acSnapTime[18];         /*图片抓拍时间:格式YYYYMMDDHHMMSSmmm(年月日时分秒毫秒)*/
	
	unsigned char	ucViolateCode;    /*违法代码E_ViolationCode*/
	unsigned char	ucLaneNo;          /*车道号,从0开始编码*/
	unsigned int 	uiVehicleId; 		/*检测到的车辆id，若为同一辆车，则id相同*/
	unsigned char	ucScore;    		/*车牌识别可行度*/
	unsigned char	ucDirection;       /*行车方向E_IpncType*/
	unsigned char	ucTotalNum;        /*该车辆抓拍总张数*/
	unsigned char	ucSnapshotIndex;   /*当前抓拍第几张，从0开始编号*/
}T_ImageUserInfo;

/*车辆图片抓拍信息*/
typedef struct 
{
	unsigned short 	usWidth;   /*图片的宽度，单位:像素*/
	unsigned short	usHeight;  /*图片的高度，单位:像素*/
	unsigned char	ucVehicleColor;/*车身颜色，E_ColorType*/
	unsigned char	ucVehicleBrand;/*车标，E_VehicleFlag*/
	unsigned char	ucVehicleSize;/*车型(1大2中3小)，ITS_Tb_Vt,目前根据车牌颜色来区分大小车，蓝牌为小车，黄牌为大车*/
	unsigned char	ucPlateColor;/*车牌颜色，E_ColorType*/
	char  			szLprResult[16];/*车牌，若为'\0'，表示无效GB2312编码*/
	unsigned short	usLpBox[4];  /*车牌位置，左上角(0, 1), 右下角(2,3)*/
	unsigned char	ucLprType;/*车牌类型, ITS_Ep_Pt*/
	unsigned short 	usSpeed;     /*单位km/h*/
	unsigned char 	ucSnapType;  /*抓拍模式, E_SnapType*/
	unsigned char 	ucReserved;     
	char 			acSnapTime[18];         /*图片抓拍时间:格式YYYYMMDDHHMMSSmmm(年月日时分秒毫秒)*/

	unsigned char	ucViolateCode;    /*违法代码E_ViolationCode*/
	unsigned char	ucLaneNo;          /*车道号,从0开始编码*/
	unsigned int 	uiVehicleId; 		/*检测到的车辆id，若为同一辆车，则id相同*/
	unsigned char	ucScore;    		/*车牌识别可行度*/
	unsigned char	ucDirection;       /*行车方向E_Direction*/
	unsigned char	ucTotalNum;        /*该车辆抓拍总张数*/
	unsigned char	ucSnapshotIndex;   /*当前抓拍第几张，从0开始编号*/

	unsigned int 	uiVideoProcTime;   /*摄像头从触发拍照到上传车牌的用时，单位ms*/
	char			strVehicleBrand[128]; /*车型品牌*/
	char			strConfidence[12];	  /*车型可信度*/
	char			strSpecialCode[20][12]; /*特征码*/
	char			ucHasCar;				/*是否有车*/
	char			aucReserved1[3];			/*保留字段*/
	unsigned char   aucReserved2[252];		/*保留字段*/
}T_ImageUserInfo2;


/* 会员 类型*/
typedef enum {
	TEMPORARY_CAR = 0,  	/* 临时车*/
	MOON_CAR,      	/* 月卡*/
	VIP_CAR,   		/* 贵宾卡*/
	STORED_CAR,  	/* 储值卡*/
	LEAD_CAR,      	/* 领导车*/
	SPECIAL_CAR,   	/* 特殊车*/
	INSIDE_CAR ,  	/* 内部车*/
	WHITE_CAR,     	/* 白名单*/
	BLACK_CAR,  	 /* 黑名单*/
	MAX_CAR
} E_MemberType;


typedef struct
{
	char			acPlate[16];	 /* 车牌号码，GB2312编码 */
	char			acEntryTime[18]; /* 入场时间*/
	char			acExitTime[18]; /* 出场时间*/
	unsigned int	uiRequired;  /* 应付金额，0.1元为单位*/
	unsigned int	uiPrepaid;  	/* 已付金额，0.1元为单位*/
	unsigned char	ucVehType;  /* 车辆类型1小车2大车 E_ParkVehSize*/
	unsigned char	ucUserType;  /*会员类型E_MemberType*/
	char			ucResultCode; /* 收费结果状态码0 成功 1 没有找到入场记录*/
	char			acReserved;
}T_VehPayRsp;

typedef  struct
{
	unsigned  int		ParkNum;  
}T_ParkNum;

typedef  struct
{
	unsigned  short		usInYear;  
	unsigned  char		ucInMonth; 
	unsigned  char		ucInDay;  
	unsigned  char		ucInHour; 
	unsigned  char		ucInMinute; 
	unsigned  char		ucInSecond;
	unsigned  char		ucReserved1;
	unsigned  short		usOutYear;
	unsigned  char		ucOutMonth;
	unsigned  char		ucOutDay;
	unsigned  char		ucOutHour;
	unsigned  char		ucOutMinute;
	unsigned  char		ucOutSecond;
	unsigned  char		ucReserved2;
	unsigned  int		uiPayAmount; 
	unsigned  int		uiTimeLen;  
	char	 			acLrpResult[16]; 
}T_PayCount;

typedef enum
{
	GATE_STATE_UNKNOW = 0,
	GATE_STATE_OPEN,
	GATE_STATE_CLOSE,
	GATE_STATE_STOP,
	GATE_STATE_MAX
}E_GateState;

typedef  struct
{
	unsigned  char		ucState;    /*E_GateState*/
	unsigned  char		ucReserved[3];  /*ucReserved[0]表示0-4路IO输入索引*/
}T_ControlGate;

typedef  struct
{
	unsigned  char		rs485Id;
	unsigned  char		ucReserved; 
	unsigned  short		dataLen; 
	unsigned  char		data[1024];
}T_RS485Data;

typedef struct
{
	unsigned int uiPanoramaPicLen;  /*全景图片大小*/
	unsigned int uiVehiclePicLen;      /*车牌图片大小*/
	unsigned char *ptPanoramaPicBuff;   /*全景图片缓冲区*/
	unsigned char *ptVehiclePicBuff;  /*车牌图片缓冲区*/
}T_PicInfo;

typedef struct
{
	unsigned char LprResult[16];/*车牌号码；单条消息最多80条车牌号码；其它分多条消息发送*/
	unsigned char StartTime[16];//eg:20151012190303 YYYYMMDDHHMMSS
	unsigned char EndTime[16];//eg:20151012190303 YYYYMMDDHHMMSS
}T_LprResult;

typedef enum
{
	ADD_PLATE_MODE,//新增，若该车牌已存在，则会自动覆盖
	DELETE_PLATE_MODE,//删除
	SEND_MODE_MAX
}E_SendLprMode;


typedef struct 
{
	unsigned char ucType;//E_SendLprMode
	unsigned char ucConut;//本次传输的车牌个数
	unsigned char aucReserved[2];//保留位
	T_LprResult	  atLprResult[10];//车牌信息
}T_SendLprByMess;

typedef struct  
{
	unsigned char ucResult; //查询的结果，0为未找到该车牌，1为成功找到该车牌
	unsigned char aucReserved[3];
	T_LprResult	  tLprResult;
}T_RspLprResult;
typedef struct
{
	int uiCount;  /* 当前准备写入白名单的车牌个数，即ptLprResult指向的待写入的车牌的个数*/
	char aucLplPath[256];
}T_BlackWhiteListCount;
typedef struct
{
	unsigned char LprMode;  /* 0：黑名单；1：白名单*/
	unsigned char LprCode;      /* 0：车牌号码utf-8字符编码；1：车牌号码gb2312字符编码*/
	unsigned char Lprnew; /*0： 重新发送；1：续传；2:删除；*/
	char aucLplPath[256];
}T_BlackWhiteList;


typedef struct
{
	unsigned char LprMode;  /* 0：黑名单；1：白名单*/
	unsigned char LprCode;      /* 0：车牌号码utf-8字符编码；1：车牌号码gb2312字符编码*/
	char aucLplPath[256];
}T_GetBlackWhiteList;
typedef enum
{
	REPORT_MESS_MAC,
	REPORT_MESS_ACE,
	REPORT_MESS_PARK_STATE,
	REPORT_MESS_RESET_KEY_PRESS,
	REPORT_MESS_VEH_INFO,
	REPORT_MESS_ASS_CAM_IP_SEARCH,
	REPORT_MESS_RS485_IN_DATA,
	REPORT_MESS_LOOP_DETECTOR,
	REPORT_VIDEO_DISTRICT_CHANGED,
	REPORT_TRA_STAT_REPORT,
	REPORT_ASS_CAMERA_TYPE,
	REPORT_FILE_RECV_STATE,
	REPORT_PS_PARKINGINFO,
	REPORT_PARK_NUM,
	REPORT_CKECK_TALKBACK_BNT,
	REPORT_4G_STATUS,
	REPORT_MESS_MAX
}E_ReportMess;
typedef struct
{
	unsigned char  acMac[18];      //eg: "xx:xx:xx:xx:xx:xx"
	unsigned char  acTime[18];     //eg:"YYYYMMDDHHMMSSxxx" 
}T_MacInfo;

typedef struct
{
	unsigned char       ucType; //定焦1 变焦2
	unsigned char       ucReserved[3];
}T_AssCameraType;

#ifndef _T_RCVMSG_
#define _T_RCVMSG_
typedef struct
{
	unsigned int		uiFlag;								/*标志位，111表示Version、IP、MAC*/
	unsigned char		aucDstMACAdd[6];					/*目标MAC地址*/
	char				aucAdapterName[VERSION_NAME_LEN];	/*网络适配器名称*/		
	unsigned int		uiAdapterSubMask;					/*网络适配器子网掩码*/
	char				ancDevType[64];						/* 设备类型，出厂时设定；*/
	char				ancSerialNum[64];					/* 设备序列号*/
	char				ancAppVersion[VERSION_NAME_LEN];	/* 软件版本*/
	char				ancDSPVersion[VERSION_NAME_LEN];	/* DSP版本*/
	T_NetSetup			tNetSetup;							/* 网络信息*/
	T_MACSetup			tMacSetup;							/* MAC信息*/
}T_RcvMsg;
#endif

typedef struct 
{ 
	unsigned char ucRegState; /*0:注销 1：注册*/ 
	unsigned char aucReserved[3]; 
}T_RegState;//注册注销岗亭端

typedef enum 
{ 
	INPUT_INDEX_UNKNOW = 0, 
	INPUT_INDEX1, 
	INPUT_INDEX2, 
	INPUT_INDEX3, 
	INPUT_INDEX_MAX, 
}E_InputIndex; 

typedef enum 
{ 
	OUTPUT_INDEX_UNKNOW = 0, 
	OUTPUT_INDEX1, 
	OUTPUT_INDEX2, 
	OUTPUT_INDEX3, 
	OUTPUT_INDEX_MAX, 
}E_OutputIndex; 

typedef struct 
{ 
	unsigned char ucIndex; //E_InputIndex 
	unsigned char aucReserved[3]; 
}T_InputReadReq; 

typedef struct 
{ 
	unsigned char ucIndex; //E_InputIndex 
	unsigned char ucValue; //0,1 
	unsigned char ucState;//0表示成功
	unsigned char aucReserved[2]; 
}T_InputReadRsp; 

typedef struct 
{ 
	unsigned char ucIndex; //E_OutputIndex 
	unsigned char ucValue; //0,1 
	unsigned char aucReserved[2]; 
}T_OutputWriteReq;

typedef struct 
{ 
	unsigned int uiDataLen; 
	unsigned char aucDataBuff[256]; 
}T_TwoEncpyption;

typedef struct
{
	unsigned char	switchflag;// 1 打开  0 关闭 
	unsigned char	aucReserved[3];
	T_TwoEncpyption Encpyptioninfo;// 二次加密字符串
}T_TwoEncpyptionSet;//设置开启关闭

typedef struct
{
	T_TwoEncpyption Encpyptioninfo;// 二次加密字符串
	unsigned char	aucReserved[4];
}T_TwoEncpyptionAuth;//鉴权

typedef struct
{
	T_TwoEncpyption currentEncpyption;// 当前二次加密字符串
	T_TwoEncpyption newEncpyption;// 新二次加密字符串
	unsigned char	aucReserved[4];
}T_TwoEncpyptionModify;//修改

typedef struct
{
	unsigned char	switchflag;// 1 打开  0 关闭 
	unsigned char	aucReserved[3];
}T_TwoEncpyptionQuery;//查询开启关闭

typedef struct
{
	char acOldPwd[32]; /*AES 128位算法 加密MAC地址字符串,再base64*/
	T_TwoEncpyption Encpyptioninfo;// 二次加密字符串
}T_ResetTwoEncpyption;

typedef enum 
{ 
	LENS_TYPE_ZOOM_MANU = 0, 
	LENS_TYPE_ZOOM_AUTO_START, 
	LENS_TYPE_ZOOM_AUTO_STOP, 
	LENS_TYPE_FOCUS_MANU, 
	LENS_TYPE_FOCUS_AUTO_START, 
	LENS_TYPE_FOCUS_AUTO_STOP, 
	LENS_TYPE_MAX, 
}E_LensType; 

typedef enum 
{ 
	LENS_ACTION_SUBTRACT = 0, 
	LENS_ACTION_ADD, 
	LENS_ACTION_MAX, 
}E_LensAction; 

typedef struct 
{ 
	unsigned char	ucLensType; //E_LensType 
	unsigned char	ucLensAction; //E_LensAction 
	unsigned short usLensSteps; // 步数(1-20) 
}T_LensControl; 
typedef enum
{
	LIGHT_WORK_MODE_CLOSE = 0,
	LIGHT_WORK_MODE_OPEN,
	LIGHT_WORK_MODE_AUTO
}E_LightWorkMode;
typedef enum
{
	PARK_LED_LEVEL_OFF = 0,
	PARK_LED_LEVEL1,
	PARK_LED_LEVEL2,
	PARK_LED_LEVEL3,
	PARK_LED_LEVEL4,
	PARK_LED_LEVEL5,
	PARK_LED_LEVEL6,
	PARK_LED_LEVEL7,
	PARK_LED_LEVEL_MAX,
}E_ParkLedLevel;
typedef struct
{
	unsigned char	ucWorkMode;// E_LightWorkMode
	unsigned char	ucLevel;		//E_ParkLedLevel
	unsigned char	ucLumaTH; //亮度阀值1~100 
	unsigned char	ucReserved;
}T_ParkLedLightSetup;
typedef struct 
{ 
	char acUserName[32]; 
	char acPasswd[36]; /*明文*/ 
}T_UserAccount; 
typedef struct
{
	char acOldUserName[32];
	char acOldPasswd[36];     /*明文*/
	char acNewUserName[32];
	char acNewPasswd[36];     /*明文*/
}T_ModifyUserAccount;
typedef struct 
{ 
	unsigned short	usUserPort;
	unsigned short	usReserved;
}T_UserPort; 
typedef enum 
{ 
	WL_FM_FULL = 0,	 /*精确比配*/ 
	WL_FM_SIMILAR = 0x1,	/*相似字符比配:0-D 8-B 0-Q E-F*/ 
	WL_FM_ORD_CHAR = 0x2, /*普通字符，允许错误失败个数*/ 
	WL_FM_IGN_CC = 0x4,	/*忽略汉字*/ 
	WL_FM_MAX, 
}E_WhilteListFuzzyMatch; 
/******************************************************************************************************
ucMatchMode 由三位决定
ucMatchMode	WL_FM_IGN_CC  WL_FM_ORD_CHAR  WL_FM_SIMILAR
	0			0				0				0			精确匹配模式
	1			0				0				1			相似字符匹配模式
	2			0				1				0			普通字符匹配模式
	3			0				1				1			相似字符匹配模式+普通字符匹配模式
	4			1				0				0			忽略汉字模式
	5			1				0				1			忽略汉字模式+相似字符匹配模式
	6			1				1				0			忽略汉字模式+普通字符匹配模式
	7			1				1				1			忽略汉字模式+普通字符匹配模式+相似字符匹配模式
*********************************************************************************************************/	
typedef struct 
{ 
	unsigned char	ucMatchMode; /*E_WhilteListFuzzyMatch*/ 
	unsigned char	ucValue; /*WL_FM_ORD_CHAR 时使用*/ 
	unsigned char	aucReserved[2]; 
}T_WLFuzzyMatch;

typedef enum 
{ 
	OP_MODE_UNKNOW = 0, 
	OP_MODE_OFFLINE,	 /*脱机使能*/ 
	OP_MODE_ENABLE,	 /*使能，不分区联机、脱机*/ 
	OP_MODE_DISABLE,	 /*不使能*/ 
	OP_MODE_MAX 
}E_OffLinePayMode; 

typedef struct
{
	unsigned char	ucMode;//E_OffLinePayMode
	unsigned char	aucReserved[3];
}T_OffLinePayMode;//脱机收费模式
typedef enum
{
	PARK_VEH_SIZE_UNKNOW = 0,
	PARK_VEH_SIZE_SMALL,
	PARK_VEH_SIZE_LARGE,
	PARK_VEH_SIZE_MAX
}E_ParkVehSize;

typedef enum
{
	PAY_MODE_UNKNOW = 0,
	PAY_MODE_ONTIME,/*按时计费 */
	PAY_MODE_TIMES,/*按次计费 */
	PAY_MODE_TIME_SECTION,/*分段计费 */
	PAY_MODE_TABLE,/*查表计费 */
	PAY_MODE_MAX
}E_PayMode;   /*计费模式*/

typedef enum
{
	STRATEGY_TYPE_UNKNOW = 0,
	STRATEGY_TYPE_NOPAY, //不收费
	STRATEGY_TYPE_CYCLE,//按一个周期收费
	STRATEGY_TYPE_BYTIME,//根据时长收费
	STRATEGY_TYPE_MAX
}E_StrategyType;  /*不足一个周期的计费策略*/
typedef struct
{
	unsigned char	ucEnable;
	unsigned char	ucVehType;	/*车辆类型*/
	unsigned char	aucReserved[2];
	unsigned short	usCyclePay;/* 周期收费金额*/
	unsigned short	usStartPay;/* 起步金额*/
	unsigned short	usFreeTime;/* 免费时长*/
	unsigned short	usCycleTime;/* 计费周期*/
	unsigned short	usStartTime;/* 起步时长*/
	unsigned short	usTotalPreDay;/* 封顶金额*/
}T_OnTimePay;  /*按时收费*/

typedef struct
{
	unsigned char	ucEnable;
	unsigned char	ucVehType;	/*车辆类型*/
	unsigned char	ucMaxTime;/*封顶次数*/
	unsigned char	ucReserved;
	unsigned short	usPayOne;/*一次收费金额*/
	unsigned short	usFreeTime;/*免费时长*/
	unsigned short	usFreeStartTime;  /*免费开始时间，以分钟为单位*/
	unsigned short	usFreeEndTime; /*免费结束时间，以分钟为单位*/
	unsigned short	usPayStartTime;  /*收费开始时间，以分钟为单位*/
	unsigned short	usPayEndTime;/*收费结束时间，以分钟为单位*/
}T_TimesPay; /*按次收费*/

typedef struct
{
	unsigned char	ucEnable;
	unsigned char	ucVehType;	/*车辆类型*/
	unsigned char	aucReserved[2];
	unsigned short	usCyclePay;/* 周期收费金额*/
	unsigned short	usStartPay;/* 起步金额*/
	unsigned short	usFreeTime;/* 免费时长*/
	unsigned short	usCycleTime;/* 计费周期*/
	unsigned short	usStartTime;/* 起步时长*/
	unsigned short	usTotalPreDay;/* 时段封顶金额*/
	unsigned short	usSectionStartTime;  /*时段开始时间，以分钟为单位*/
	unsigned short	usSectionEndTime;/*时段结束时间，以分钟为单位*/
}T_TimeSectionPay;	/*按时段收费*/

typedef struct
{
	unsigned short usFreeTime;
	unsigned short usTotalPreDay;
	unsigned short usTablePay[48];	
	unsigned char  ucTableType;  /* 0以半小时为单位,1以1小时为单位*/
	unsigned char aucReserved[3];
}T_TablePay; /*查表收费*/

typedef struct
{
	unsigned char	ucRuleMode; 		  /*E_PayMode*/
	unsigned char	ucStrategyType;    /*E_StrategyType*/
	unsigned short	usLimitTime;
	T_OnTimePay atOnTimePay[MAX_PAY_ITEM];
	T_TimesPay	  atTimesPay[MAX_PAY_ITEM];
	T_TimeSectionPay atTimeSectionPay[MAX_PAY_ITEM*MAX_TIMESECTION_NUM];
	T_TablePay atTablePay;
	unsigned char aucReserved[4];
}T_PayRule;

typedef struct
{
	unsigned char ucType;  /*导出信息内容，0为车辆在场信息表*/
	char aucLplPath[256];
}T_GetPrensentVehInfo;

typedef struct
{
	unsigned char	ucEntryEnable;//入口相机是否抬闸使能标志
	unsigned char	ucExitEnable;//入口相机是否抬闸使能标志
	unsigned char	aucReserved[2];
}T_AutoControlGate;

typedef enum
{
	Sync_OffLine_Pay_Rule,//同步收费规则
	Sync_OffLine_Pay_Mode,//同步收费模式
	Sync_OffLine_Auto_Open_Gate,//同步相机抬闸配置
	Sync_485Ctrl_Rule,//同步485规则
	Sync_LampCtrl_Rule,//同步灯控规则
	Sync_Max_Type
}E_SyncType;

typedef struct
{
	unsigned char	ucSyncType;//E_SyncType
	unsigned char	aucReserved[3];
}T_SyncConfigByMuticast;

typedef enum
{
	BlackWhiteList_NoError = 0, //正常
	BlackWhiteList_InvalidParam,//车牌信息格式不对
	BlackWhiteList_PlateLengthError,//车牌号码字符串长度不对
	BlackWhiteList_PlateInvalidCharError,//车牌号码包含无效字符
	BlackWhiteList_StartTimeLengthError,//开始时间字符串长度不对
	BlackWhiteList_StartTimeInvalidCharError,//开始时间字符串包含无效字符
	BlackWhiteList_StartTimeYearError,  //开始时间年份不对
	BlackWhiteList_StartTimeMonthError, //开始时间月份不对
	BlackWhiteList_StartTimeDayError,   //开始时间日期不对
	BlackWhiteList_StartTimeHourError,  //开始时间小时不对
	BlackWhiteList_StartTimeMinuteError,//开始时间分钟不对
	BlackWhiteList_StartTimeSecondError,//开始时间秒数不对
	BlackWhiteList_EndTimeLengthError,  //结束时间字符串长度不对
	BlackWhiteList_EndTimeInvalidCharError,//结束时间字符串包含无效字符
	BlackWhiteList_EndTimeYearError,    //结束时间年份不对
	BlackWhiteList_EndTimeMonthError,	//结束时间月份不对
	BlackWhiteList_EndTimeDayError,		//结束时间日期不对
	BlackWhiteList_EndTimeHourError,	//结束时间小时不对
	BlackWhiteList_EndTimeMinuteError,	//结束时间分钟不对
	BlackWhiteList_EndTimeSecondError,  //结束时间秒数不对
	BlackWhiteList_StartTimeHourBigEndTime,//开始时间大于结束时间
	BlackWhiteList_FormatError,//格式不正确
	BlackWhiteList_AccoundFormatError,//账号包含非数字字符
	BlackWhiteList_AccoundValueTooBig,//账号值太大
	BlackWhiteList_TotalNumFormatError,//总车位数包含非数字字符
	BlackWhiteList_TotalNumValueTooBig,//总车位数值不能大于255
	BlackWhiteList_IdleNumFormatError,//剩余车位数包含非数字字符
	BlackWhiteList_IdleNumValueBigTotalNum,//剩余车位数不能大于总车位数
	BlackWhiteList_IdleNumValueTooBig,//剩余车位数值不能大于255
	BlackWhiteList_SectionLengthError,//24小时时段格式长度必须为4
	BlackWhiteList_SectionFormatError,//24小时时段格式只能包含字符0-9,A-F
	BlackWhiteList_UTF8TransToUnicodeFormatError,//UTF8转Unicode错误
	BlackWhiteList_UnicodeTransToGBKFormatError,//UTF8转Unicode错误
}E_BlackWhiteListErrorCode;

typedef enum
{
	LOOP_IO_ID = 0, /* 线圈IO Id*/
	IO_INDEX_MAX,
}E_IOAppIndex;

typedef struct
{
	unsigned char	ucIndex; /* E_IOAppIndex*/
	unsigned char	ucLState; /* 0 下降沿跳变  1 上升沿跳变*/
	unsigned char	aucReserved[2];
}T_IOStateRsp;


typedef enum
{
	DEV_STATE_LED = 103, //状态灯
	NET_STATE_LED = 92, //网络灯
	VEH_CHECK_IN1 = 111, // 车检器输入1
	VEH_CHECK_IN2 = 104, // 车检器输入2
	VEH_CHECK_IN3 = 112, // 车检器输入3
	RELAY_OUT1 = 94, // 继电器输出1
	RELAY_OUT2 = 95, // 继电器输出2
	RELAY_OUT3 = 118, // 继电器输出3
	PARKING_SPACE_LED1_R = 33, // 车位相机LED1-R
	PARKING_SPACE_LED1_G = 32, // 车位相机LED1-G
	PARKING_SPACE_LED1_B = 11, // 车位相机LED1-B

	PARKING_SPACE_LED2_R = 13, // 车位相机LED2-R
	PARKING_SPACE_LED2_G = 10, // 车位相机LED2-G
	PARKING_SPACE_LED2_B = 12, // 车位相机LED2-B

	PARKING_SPACE_LED3_R = 14, // 车位相机LED3-R
	PARKING_SPACE_LED3_G = 15, // 车位相机LED3-G
	PARKING_SPACE_LED3_B = 9, // 车位相机LED3-B
}E_GPIOIndex;

typedef enum
{
	OFFLINE_DATA=0,
}E_OfflineDataType;

typedef struct
{
	unsigned char	ucType; /*E_OfflineDataType */
	unsigned char	aucReserved[3];
}T_ClearOfflineData;

typedef struct
{
	char	acPlate[16];	 /* 车牌号码，GB2312编码 */
	char	acEntryTime[18]; /* 入场时间*/
	char	acExitTime[18]; /* 出场时间*/
	unsigned int	uiRequired;  /* 应付金额，0.1元为单位*/
	unsigned int	uiPrepaid;  	/* 已付金额，0.1元为单位*/
	unsigned char 	ucVehState;   /*E_VehState*/
	unsigned char	ucVehType;  /* 车辆类型1小车2大车 */
	unsigned char	ucUserType;  /*会员类型E_MemberType*/
	unsigned char	ucPlateColor; /*车牌颜色，若为0，表示无效E_PlateColor*/
}T_OfflineVehInfoTest;

typedef struct
{
	unsigned char enable;//0 关闭  1 开启语音对讲  2 播放音频   3 语音采集
	unsigned char pressstatus;//0 未按下    1 有按下
	unsigned char Reserverd[6];
}T_AudioTalkBack;

typedef struct
{
	unsigned char inVol;//输入音量大小 0-100
	unsigned char outVol;//输出音量大小 0-100
	unsigned char intype;//0 拾音器  1 麦克风
	unsigned char Reserverd[5];
}T_AudioVol;

typedef enum 
{
	ROTATE_NONE = 0,
	ROTATE_90   = 1,
	ROTATE_180  = 2,
	ROTATE_270  = 3,
	ROTATE_BUTT
} E_ROTATE;


typedef struct
{
	unsigned char   ucRotateType; // E_ROTATE
	unsigned char	ucReserved[3]; 
}T_VideoRotate;


//////////////////////////////////////////////////////////////////////////

/*特征码结构体定义*/
typedef struct 
{
	char   strSpecialCode[20][12]; 
}T_SpecialCode;


/*图片信息结构体定义*/
typedef struct 
{
	unsigned short 	usWidth;   /*图片的宽度，单位:像素*/
	unsigned short	usHeight;  /*图片的高度，单位:像素*/

	T_Point		 atPlateRegion[4];    /*车牌识别区域，逆时针方向4个点*/
	unsigned short	usPlateBox[4];    /*车牌位置，左上角(0, 1), 右下角(2,3)*/
	unsigned short	usVehicleBox[4];  /*车身位置，左上角(0, 1), 右下角(2,3)*/

	char	strVehicleBrand[128]; /*车型*/
	char	strConfidence[12];    /*车型可信度*/

	T_SpecialCode   tSpecialCode;/*特征码*/

	int hasCar;				//是否有车

	unsigned char   ucReserved[256];  /*保留字段*/ 

}T_SpecialCodeImageInfo;

/*伪车牌图片信息结构体定义*/
typedef struct 
{
	unsigned short 	usWidth;   /*图片的宽度，单位:像素*/
	unsigned short	usHeight;  /*图片的高度，单位:像素*/

	unsigned short	usPlateBox[4];  /*车牌位置，左上角(0, 1), 右下角(2,3)*/
	unsigned short	usVehicleBox[4];  /*车身位置，左上角(0, 1), 右下角(2,3)*/

	char strVehicleSubBrand[128];	/*伪车牌*/
	char strConfidence[12];         /*伪车牌可信度*/

	unsigned char   ucReserved[256];  /*保留字段*/ 

}T_PlateClassfyImageInfo;

//////////////////////////////////////////////////////////////////////////

/**********************************************************************
* 函数名称：Net_EnableLog
* 功能描述：日志功能开关,默认开启日志
* 输入参数：iEnable 0:关闭日志,1:启用日志
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_EnableLog(int iEnable);

NET_API E_ReturnCode _stdcall Net_Log(char *strLog, ...);

NET_API E_ReturnCode _stdcall Net_SetLogSize(int iSize);

/**********************************************************************
* 函数名称：Net_FindDevice
* 功能描述：搜索局域网内所有相机IP，通过注册回调函数获取所有相机信息,系统需要安装有WinPcap抓包工具
* 输入参数：无
* 输出参数：无
* 返 回 值：状态码  
***********************************************************************/
typedef void (CALLBACK *NET_FIND_DEVICE_CALLBACK)(T_RcvMsg *ptFindDevice, void *pUserData);
NET_API E_ReturnCode _stdcall Net_FindDevice(NET_FIND_DEVICE_CALLBACK func, void *pUserData);

NET_API E_ReturnCode _stdcall Net_FindDeviceEx(NET_FIND_DEVICE_CALLBACK func, void *pUserData);

/**********************************************************************
* 函数名称：Net_FindDeviceMac
* 功能描述：搜索局域网内所有相机Mac，通过注册回调函数获取所有相机Mac信息,系统需要安装有WinPcap抓包工具
* 输入参数：无
* 输出参数：无
* 返 回 值：状态码  
***********************************************************************/
typedef void (CALLBACK *NET_FIND_DEVICE_MAC_CALLBACK)(const char *strFindDeviceMac, void *pUserData);
NET_API E_ReturnCode _stdcall Net_FindDeviceMac(NET_FIND_DEVICE_MAC_CALLBACK func, void *pUserData);

/**********************************************************************
* 函数名称：Net_FindDeviceIp
* 功能描述：搜索局域网内所有相机Ip，通过注册回调函数获取所有相机Ip信息,系统需要安装有WinPcap抓包工具
* 输入参数：无
* 输出参数：无
* 返 回 值：状态码  
***********************************************************************/
typedef void (CALLBACK *NET_FIND_DEVICE_IP_CALLBACK)(const char *strFindDeviceIp, void *pUserData);
NET_API E_ReturnCode _stdcall Net_FindDeviceIp(NET_FIND_DEVICE_IP_CALLBACK func, void *pUserData);

/**********************************************************************
* 函数名称：Net_ModifyDeviceIpByMac
* 功能描述：根据相机Mac修改Ip,子网掩码
* 输入参数：无
* 输出参数：无
* 返 回 值：状态码  
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ModifyDeviceIpByMac(const char *strMac, const char *strIp, const char *strMaskAddress);

/**********************************************************************
* 函数名称：Net_Init
* 功能描述：sdk库初始化，初始化相机管理资源
* 输入参数：无
* 输出参数：无
* 返 回 值：状态码  
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_Init(void);

/**********************************************************************
* 函数名称：Net_UNinit
* 功能描述：sdk库反初始化，断开相机连接，释放相机管理资源
* 输入参数：无
* 输出参数：无
* 返 回 值：无  
***********************************************************************/
NET_API void _stdcall Net_UNinit(void);

/**********************************************************************
* 函数名称：Net_AddCamera
* 功能描述：添加相机，分配相机管理项
* 输入参数：相机IP,"***.***.***.***"
* 输出参数：无
* 返 回 值：相机句柄,-1为无效句柄
***********************************************************************/
NET_API DCHANDLE _stdcall Net_AddCamera(char *ptIp);

/**********************************************************************
* 函数名称：Net_AddAssCamera
* 功能描述：添加辅相机，分配相机管理项
* 输入参数：ptIp 相机IP,"***.***.***.***"
			nAssDevFlag 辅相机设备标志
* 输出参数：无
* 返 回 值：相机句柄,-1为无效句柄
***********************************************************************/
NET_API DCHANDLE _stdcall Net_AddAssCamera(char *ptIp, int nAssDevFlag);

/**********************************************************************
* 函数名称：Net_DelCamera
* 功能描述：断开与相机之间的连接，释放相机管理项
* 输入参数： 相机句柄
* 输出参数： 无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_DelCamera(DCHANDLE tHandle);

/**********************************************************************
* 函数名称：Net_ConnCamera
* 功能描述：与相机建立控制信令，启动图片接收，第一次链接成功后，SDK内部机制自带断线重连机制，断线时候会不断重连
* 输入参数：tHandle 相机句柄
*           usPort  相机信令端口，为0时，使用默认端口30000
* 			usTimeout 信令处理超时时长，单位为秒
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ConnCamera(DCHANDLE tHandle,  unsigned short usPort,  unsigned short usTimeout);


NET_API E_ReturnCode _stdcall Net_ConnCamera2(DCHANDLE tHandle,  unsigned short usPort,  unsigned short usTimeout);
/**********************************************************************
* 函数名称：Net_ConnCameraEx
* 功能描述：Net_ConnCamera函数的扩展，与相机建立控制信令，启动图片接收,需要输入用户名和密码，第一次链接成功后，SDK内部机制自带断线重连机制，断线时候会不断重连
* 输入参数：tHandle 相机句柄
*           usPort  相机信令端口，为0时，使用默认端口30000
* 			usTimeout 信令处理超时时长，单位为秒
*			pUserName	用户名
*			pPassWord	密码
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ConnCameraEx(DCHANDLE tHandle,  unsigned short usPort,  unsigned short usTimeout,unsigned char *pUserName,unsigned char *pPassWord);

NET_API E_ReturnCode _stdcall Net_ConnCameraEtcp(DCHANDLE tHandle,  unsigned short usPort, unsigned short usTimeout, unsigned char *pUserName,unsigned char *pPassWord, int ucDetectMode);
/**********************************************************************
* 函数名称：Net_DisConnCamera
* 功能描述：断开与相机之间的信令链路，释放图片接收资源
* 输入参数：相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_DisConnCamera(DCHANDLE tHandle);

/*********************************************************************
* 函数名称：Net_StartVideo
* 功能描述：开始接收视频码流，并将视频刷到窗口句柄上
* 输入参数：tHandle 相机句柄，
*				   niStreamType 流类型0表示主码流，1表示辅码流
*			hWnd 窗口句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_StartVideo(DCHANDLE tHandle, int niStreamType, HWND hWnd);

/**********************************************************************
* 函数名称：Net_SetRealDataCallBack
* 功能描述：注册码流接收函数，通过注册回调函数，获取实时视频帧
* 输入参数：tHandle 相机句柄
*			pRealDataCallBack 回调函数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
typedef void (CALLBACK *NET_REALDATACALLBACK) (DCHANDLE tHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser);
NET_API E_ReturnCode _stdcall Net_SetRealDataCallBack(DCHANDLE tHandle, NET_REALDATACALLBACK pRealDataCallBack);

/**********************************************************************
* 函数名称：Net_SetRealDataCallBackEx
* 功能描述：注册码流接收函数，通过注册回调函数，获取实时视频帧，Net_SetRealDataCallBack函数的扩展，增加了回调函数上下文
* 输入参数：tHandle 相机句柄
*			pRealDataCallBack 回调函数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
typedef void (CALLBACK *NET_REALDATACALLBACKEx) (DCHANDLE tHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize,T_FrameInfo *pTframeInfo, void* pUserData);
NET_API E_ReturnCode _stdcall Net_SetRealDataCallBackEx(DCHANDLE tHandle, NET_REALDATACALLBACKEx pRealDataCallBack,void *pUserData);

/**********************************************************************
* 函数名称：Net_AddPlayWindow
* 功能描述：添加播放视频的窗口句柄
* 输入参数：tHandle 相机句柄
*			hWnd	窗口句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_AddPlayWindow(DCHANDLE tHandle, HWND hWnd);

/**********************************************************************
* 函数名称：Net_DelPlayWindow
* 功能描述：删除播放视频的窗口句柄
* 输入参数：tHandle 相机句柄
*			hWnd	窗口句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_DelPlayWindow(DCHANDLE tHandle, HWND hWnd);

/**********************************************************************
* 函数名称：Net_SaveBmpFile
* 功能描述：保存当前帧为位图文件
* 输入参数：tHandle 相机句柄
*           strBmpFile 位图文件名
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SaveBmpFile(DCHANDLE tHandle, const char * strBmpFile);

/**********************************************************************
* 函数名称：Net_SaveJpgFile
* 功能描述：保存当前帧为Jpg文件
* 输入参数：tHandle 相机句柄
*           strJpgFile 位图文件名
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SaveJpgFile(DCHANDLE tHandle, const char * strJpgFile);

/**********************************************************************
* 函数名称：Net_GetJpgBuffer
* 功能描述：获取当前帧的Jpg缓存
* 输入参数：tHandle 相机句柄
*           ucJpgBuffer Jpg缓存指针, 内存由函数内部分配
* 输出参数：lSize Jpg缓存大小
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_GetJpgBuffer(DCHANDLE tHandle, unsigned char ** ucJpgBuffer, unsigned long * ulSize);

NET_API E_ReturnCode _stdcall Net_GetJpgBufferEx(DCHANDLE tHandle, unsigned char ** ucJpgBuffer, unsigned long * ulSize);

NET_API E_ReturnCode _stdcall Net_GetFrameData(DCHANDLE tHandle, unsigned char** data ,int *width, int *height);

/**********************************************************************
* 函数名称：Net_FreeBuffer
* 功能描述：释放缓存
* 输入参数：ucBuffer 待释放缓存指针(Net_GetJpgBuffer, Net_GetJpgBufferEx分配的内存)
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_FreeBuffer(void* pBuffer);

/**********************************************************************
* 函数名称：Net_StartRecord
* 功能描述：开始录像
* 输入参数：tHandle 相机句柄
*			strFile: 录像文件名
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_StartRecord(DCHANDLE tHandle, const char * strFile);

NET_API E_ReturnCode _stdcall Net_StartRecordEx(DCHANDLE tHandle, const char * strFile, int nSectionTime);

/**********************************************************************
* 函数名称：Net_StopRecord
* 功能描述：停止录像
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_StopRecord(DCHANDLE tHandle);

/**********************************************************************
* 函数名称：Net_SetDrawFunCallBack
* 功能描述：注册图像处理函数，用于在视频上画线
* 输入参数：tHandle 相机句柄
*			pDrawFun 回调函数指针
*			lpDrawFunData 回调函数上下文
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
typedef void (CALLBACK *NET_DRAWFUNCALLBACK)(DCHANDLE tHandle,HDC hdc, int width, int height, void* pUser);
NET_API E_ReturnCode _stdcall Net_SetDrawFunCallBack(DCHANDLE tHandle, NET_DRAWFUNCALLBACK pDrawFun, void * lpDrawFunData);

/**********************************************************************
* 函数名称：Net_SetDrawFunCallBack
* 功能描述：注册图像数据导出回调
* 输入参数：tHandle 相机句柄
*			pDataOut 回调函数指针
*			pUser 回调函数上下文
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
typedef void (CALLBACK *NET_DrawDataOut)(DCHANDLE tHandle, void * hdd, void * bmi, unsigned char* data, int width, int height, void* pUser);
NET_API E_ReturnCode _stdcall Net_SetDrawDataOut(DCHANDLE tHandle, NET_DrawDataOut pDrawDataOut, void * pUser);

/**********************************************************************
* 函数名称：Net_ShowNetSignal
* 功能描述：在视频画面显示网络信号强弱
* 输入参数：tHandle 相机句柄
*			niShowMode 显示模式,0:不显示,1:显示
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ShowNetSignal(DCHANDLE tHandle, int niShowMode);

/**********************************************************************
* 函数名称：Net_ShowPlateRegion
* 功能描述：在视频画面显示车牌识别区
* 输入参数：tHandle 相机句柄
*			niShowMode 显示模式,0:不显示,1:显示
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ShowPlateRegion(DCHANDLE tHandle, int niShowMode);

/**********************************************************************
* 函数名称：Net_UpdatePlateRegion
* 功能描述：更新视频画面车牌识别区
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_UpdatePlateRegion(DCHANDLE tHandle);

/**********************************************************************
* 函数名称：Net_StopVideo
* 功能描述：停止接收视频码流
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_StopVideo(DCHANDLE tHandle);

/**********************************************************************
* 函数名称：Net_QueryVideoState
* 功能描述：查询码流接收状态
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryVideoState(DCHANDLE tHandle);

/**********************************************************************
* 函数名称：Net_QueryConnState
* 功能描述：查询相机连接状态
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryConnState(DCHANDLE tHandle);

/**********************************************************************
* 函数名称：Net_ImageSnap
* 功能描述：图片抓拍，下发图片抓拍命令，通过Net_RegImageRecvEx注册回调函数接收图片信息
* 输入参数：tHandle 相机句柄
*			ptImageSnap  图片抓拍参数，可全部置0
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ImageSnap(DCHANDLE tHandle, T_DCImageSnap *ptImageSnap);

/**********************************************************************
* 函数名称：Net_ParkingInfo
* 功能描述：下发车位上停车信息上报，通过Net_RegReportMessEx注册回调函数接收图片信息
* 输入参数：tHandle 相机句柄
*			ptRspParkingInfo  车位上停车信息参数，可全部置0
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ParkingInfo(DCHANDLE tHandle, T_RspParkingInfo *ptRspParkingInfo);

/**********************************************************************
* 函数名称：Net_GetImage
* 功能描述：获取图片信息，如果使用该函数，需要调用Net_SetSnapMode将抓拍模式设置为连续模式
* 输入参数：tHandle 相机句柄
*			uiImageId 图片ID
*			ptImageInfo 车辆识别结果指针
*			ptPicInfo   图片缓冲区指针及大小
* 输出参数：ptImageInfo  图片中车辆信息
*			ptPicInfo  图片数据及图片大小
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_GetImage(DCHANDLE tHandle, unsigned int  uiImageId, T_ImageUserInfo *ptImageInfo, T_PicInfo *ptPicInfo);

/**********************************************************************
* 函数名称：Net_GateSetup
* 功能描述：闸机控制
* 输入参数：tHandle 相机句柄
*           ptControlGate 闸机控制参数指针，1开闸；2关闸；3停闸；
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_GateSetup(DCHANDLE tHandle,  T_ControlGate *ptControlGate);

/**********************************************************************
* 函数名称：Net_GetSdkVersion
* 功能描述：获取sdk版本信息
* 输入参数：szVersion 版本缓冲区
*		    ptLen   缓冲区大小
* 输出参数：szVersion sdk版本信息
*           ptLen   版本真实长度
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_GetSdkVersion(unsigned char *szVersion, unsigned int *ptLen);

#ifndef _E_SnapMode_
#define _E_SnapMode_
typedef enum
{
	SNAP_MODE_TOUCH = 0, /*触发抓拍*/
	SNAP_MODE_PERSIST,   /*连续抓拍*/
	SNAP_MODE_ALL,
}E_SnapMode;
#endif

/**********************************************************************
* 函数名称：Net_SetSnapMode
* 功能描述：设置相机抓拍模式
* 输入参数：tHandle	相机句柄
			niSnapMode 相机抓拍模式，见E_SnapMode，通过回调函数获取图片为触发抓拍模式，通过Net_GetImage获取图片信息，为连续抓拍模式
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SetSnapMode(DCHANDLE tHandle, int niSnapMode);

/**********************************************************************
* 函数名称：Net_RegImageRecv
* 功能描述：通过注册回调函数，获取上报的图片信息及识别结果
			只需在SDK初始化成功后注册一次回调即可,多次注册以最后一次注册的回调函数为准
			推荐使用Net_RegImageRecvEx
* 输入参数：fCb 回调函数
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
typedef int (CALLBACK *FGetImageCB)(DCHANDLE tHandle, unsigned int  uiImageId, T_ImageUserInfo *ptImageInfo, T_PicInfo *ptPicInfo);
NET_API E_ReturnCode _stdcall Net_RegImageRecv(FGetImageCB fCb);

/**********************************************************************
* 函数名称：Net_RegImageRecv2
* 功能描述：通过注册回调函数，获取上报的图片信息及识别结果，包括车标等信息，相比Net_RegImageRecv上报内容更丰富
			只需在SDK初始化成功后注册一次回调即可,多次注册以最后一次注册的回调函数为准
* 输入参数：fCb 回调函数
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
typedef int (CALLBACK *FGetImageCB2)(DCHANDLE tHandle, unsigned int  uiImageId, T_ImageUserInfo2 *ptImageInfo, T_PicInfo *ptPicInfo);
NET_API E_ReturnCode _stdcall Net_RegImageRecv2(FGetImageCB2 fCb);

/**********************************************************************
* 函数名称：Net_RegImageRecvEx
* 功能描述：通过注册回调函数，获取上报的图片，实时识别结果通过该回调导出，Net_RegImageRecv的扩展函数，增加回调函数的上下文
			每建立一次链接必须注册一次否则不上报,同个链接多次注册以最后一次注册的回调函数为准
* 输入参数：tHandle 相机句柄
*			fCb 回调函数
			{
				tHandle 相机句柄
				uiImageId 上传的识别结果的类型，0为实时识别数据
				ptImageInfo 指向识别结果的指针
				ptPicInfo 识别结果图片的缓存区，若无图片，则里边指针为空
				pUser	回调函数上下文
			}
			pUser 回调函数上下文

* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
typedef int (CALLBACK *FGetImageCbEx)(DCHANDLE tHandle,unsigned int  uiImageId, T_ImageUserInfo *ptImageInfo, T_PicInfo *ptPicInfo,void *pUser);
NET_API E_ReturnCode _stdcall Net_RegImageRecvEx(DCHANDLE tHandle, FGetImageCbEx fCb,void *pUser);

typedef int (CALLBACK *FGetImageCbEx2)(DCHANDLE tHandle,unsigned int  uiImageId, T_ImageUserInfo2 *ptImageInfo, T_PicInfo *ptPicInfo,void *pUser);
NET_API E_ReturnCode _stdcall Net_RegImageRecvEx2(DCHANDLE tHandle, FGetImageCbEx2 fCb,void *pUser);

/**********************************************************************
* 函数名称：MatchSpecialCode
* 功能描述：特征码比较
* 输入参数：ptSpecialCode1 特征码结构体指针
*			ptSpecialCode2  特征码结构体指针
* 输出参数：无  
* 返 回 值：返回分数[0,1]
***********************************************************************/
NET_API float _stdcall Net_MatchSpecialCode(T_SpecialCode * ptSpecialCode1, T_SpecialCode * ptSpecialCode2);

NET_API float _stdcall Net_MatchSpecialCode2(float fSpecialCode1[20], float fSpecialCode2[20]);

/**********************************************************************
* 函数名称：Net_RegOffLineImageRecvEx
* 功能描述：通过注册回调函数，获取脱机记录数据，包括车牌，车型等信息，当该函数被注册时，相机的脱机记录结果会上抛到该接口
* 输入参数：tHandle 相机句柄

			fCb 回调函数
			{
				tHandle 相机句柄
				uiImageId 上传的识别结果的类型，1为脱机记录数据
				ptImageInfo 指向识别结果的指针
				ptPicInfo 识别结果图片的缓存区，若无图片，则里边指针为空
				pUser	回调函数上下文
			}

			pUserData 回调函数上下文
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
typedef int (CALLBACK *FGetOffLineImageCBEx)(DCHANDLE tHandle, unsigned int  uiImageId,  T_ImageUserInfo *ptImageInfo,T_PicInfo *ptPicInfo,void *pUserData);
NET_API E_ReturnCode _stdcall Net_RegOffLineImageRecvEx(DCHANDLE tHandle,FGetOffLineImageCBEx fCb,void *pUserData);

/**********************************************************************
* 函数名称：Net_RegOffLinePayRecord
* 功能描述：通过注册回调函数，获取出口相机脱机收费记录信息，包括车辆出入场信息，收费金额，会员类型等等
* 输入参数：tHandle 相机句柄
			fCb 回调函数
			{
				tHandle 相机句柄
				ucType	回调上抛消息类型，目前0为脱机收费记录；
				ptVehPayInfo 相机脱机收费记录信息； 
				uiLen		ptVehPayInfo结构体对应的长度；
				ptPicInfo	识别结果图片的缓存区，若无图片，则里边指针为空；
				pUserData 回调函数上下文；
			}
			pUserData 回调函数上下文
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
typedef int (CALLBACK *FGetOffLinePayRecordCB)(DCHANDLE tHandle, unsigned char  ucType, T_VehPayRsp  *ptVehPayInfo, unsigned int uiLen,T_PicInfo *ptPicInfo,void *pUserData);
NET_API E_ReturnCode _stdcall Net_RegOffLinePayRecord(DCHANDLE tHandle,FGetOffLinePayRecordCB fCb,void *pUserData);

/**********************************************************************
* 函数名称：Net_GetPresentVehInfoAsCSV
* 功能描述：以CSV格式导出车辆在场信息表
* 输入参数：tHandle 相机句柄
*			ptGetPresentVehInfo 相机在场信息表参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_GetPresentVehInfoAsCSV(DCHANDLE tHandle, T_GetPrensentVehInfo *ptGetPresentVehInfo);

/**********************************************************************
* 函数名称：Net_SaveImageToJpeg
* 功能描述：截取当前图像，保存到指定路径
* 输入参数：tHandle 相机句柄
*			ucPathNmme 保存图像的路径
* 输出参数：无 
* 返 回 值：状态码
***********************************************************************/

NET_API E_ReturnCode _stdcall Net_SaveImageToJpeg(DCHANDLE tHandle,unsigned char *ucPathNmme);

/**********************************************************************
* 函数名称：Net_RegReportMessEx
* 功能描述：通过注册回调函数，获取上报消息；
* 输入参数：tHandle 相机句柄
			fCb 回调函数
			{
				tHandle 相机句柄
				ucType  消息类型，见E_ReportMess
				ptMessage 根据消息类型不同，对应的结构体不同；
				详见下表：	
				REPORT_MESS_MAC					T_MacInfo
				REPORT_MESS_ACE					T_Ave_Result
				REPORT_MESS_PARK_STATE			T_ParkRealTimeState
				REPORT_MESS_RESET_KEY_PRESS		T_ResetKeyPressState
				REPORT_MESS_RESET_VEH_INFO		T_VehResult
				REPORT_MESS_ASS_CAM_IP_SEARCH	T_AssCameraIpSearch
				REPORT_MESS_RS485_IN_DATA		T_RS485Data
				REPORT_MESS_LOOP_DETECTOR		T_IOStateRsp
				REPORT_VIDEO_DISTRICT_CHANGED   NULL
				REPORT_TRA_STAT_REPORT			T_DCTraStatReport
				REPORT_ASS_CAMERA_TYPE			T_AssCameraType
				REPORT_FILE_RECV_STATE			T_FileRecvResult
				REPORT_PS_PARKINGINFO			T_RspParkingInfo
				REPORT_PARK_NUM					T_ParkNum
				REPORT_CKECK_TALKBACK_BNT		NULL
				pUserData 	回调函数上下文
			}
			pUserData 回调函数上下文
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
typedef int (CALLBACK *FGetReportCBEx)(DCHANDLE tHandle,unsigned char ucType,void *ptMessage,void *pUserData);
NET_API E_ReturnCode _stdcall Net_RegReportMessEx(DCHANDLE tHandle, FGetReportCBEx fcb,void *pUserData);

/**********************************************************************
* 函数名称：DCSetSynTimePeriod
* 功能描述：设置SDK内部同步时间周期
* 输入参数：单位秒，当为0时，不启用内部同时
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SetSynTimePeriod(unsigned short usSecTime);

/**********************************************************************
* 函数名称：Net_ParkNumSetup
* 功能描述：设置空余停车位
* 输入参数：tHandle 相机句柄
			ptParkNum 空余停车位参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ParkNumSetup(DCHANDLE tHandle, T_ParkNum *ptParkNum);

/**********************************************************************
* 函数名称：Net_QueryParkNumSetup
* 功能描述：查询空余停车位
* 输入参数：tHandle 相机句柄
			ptParkNum 空余停车位参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryParkNumSetup(DCHANDLE tHandle, T_ParkNum *ptParkNum);

/**********************************************************************
* 函数名称：Net_PayCountSetup
* 功能描述：设置缴费金额
* 输入参数：tHandle 相机句柄
			ptPayCount 缴费金额参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_PayCountSetup(DCHANDLE tHandle, T_PayCount *ptPayCount);

/**********************************************************************
* 函数名称：Net_SendRS485Data
* 功能描述：rs485数据透传接口，向RS485接口透传数据
* 输入参数：tHandle 相机句柄
*			ptRS485Data 透传RS485数据参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SendRS485Data(DCHANDLE tHandle, T_RS485Data *ptRS485Data);

/**********************************************************************
* 函数名称：Net_TransRS485Data
* 功能描述：rs485数据透传接口，向RS485接口透传数据
* 输入参数：tHandle 相机句柄
*			ucRs485Id RS485口的ID，从0编号
*			pRS485Data 指向待传数据的指针
*			ucDatalen 待传数据的长度，最大长度为256个字节
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_TransRS485Data(DCHANDLE tHandle, unsigned char ucRs485Id,unsigned char  *pRS485Data,unsigned char ucDatalen);

/**********************************************************************
* 函数名称：Net_TransRS485Data
* 功能描述：rs485数据透传接口，向RS485接口透传数据
* 输入参数：tHandle 相机句柄
*			ucRs485Id RS485口的ID，从0编号
*			pRS485Data 指向待传数据的指针
*			usDatalen 待传数据的长度，最大长度为1024个字节
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_TransRS485DataEx(DCHANDLE tHandle, unsigned char ucRs485Id,unsigned char  *pRS485Data,unsigned short usDatalen);

/**********************************************************************
* 函数名称：Net_TransRS485HexData
* 功能描述：rs485数据透传接口，向RS485接口透传16进制数据,数据格式参考（00 01 02 F1 F3 ...）,建议用Net_TransRS485HexDataEx
* 输入参数：tHandle 相机句柄
*			ucRs485Id RS485口的ID，从0编号
*			pRS485Data 指向待传数据的16进制字符串指针
*			ucDatalen 指向待传数据的16进制字符串长度,最大长度为256个
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_TransRS485HexData(DCHANDLE tHandle, unsigned char ucRs485Id,unsigned char  *pRS485Data,unsigned char ucDatalen);

/**********************************************************************
* 函数名称：Net_TransRS485HexDataEx
* 功能描述：rs485数据透传接口，向RS485接口透传16进制数据,数据格式参考（00 01 02 F1 F3 ...）, 对 Net_TransRS485HexData的修正,发送字节长度限制
* 输入参数：tHandle 相机句柄
*			ucRs485Id RS485口的ID，从0编号
*			pRS485Data 指向待传数据的16进制字符串指针
*			ucDatalen 指向待传数据的16进制字符串长度,最大长度为3072个(内部一次最多发送1024个16进制字节)
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_TransRS485HexDataEx(DCHANDLE tHandle, unsigned char ucRs485Id, unsigned char  *pRS485Data, unsigned int iDatalen);
/**********************************************************************
* 函数名称：Net_ReadRS485Data
* 功能描述：读取RS485输入的数据
* 输入参数：tHandle 相机句柄
*			ptRS485Data 读取RS485数据参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ReadRS485Data(DCHANDLE tHandle, T_RS485Data *ptRS485Data);

/**********************************************************************
* 函数名称：Net_BlackWhiteListSetup
* 功能描述：可循环调用该函数，将车牌信息按照指定格式写入到文件，再调用Net_BlackWhiteListSend将黑白名单导入到相机
			车牌字符必须为GB2312编码
* 输入参数：ptLprResult 指向存储白名单信息的内存
*			ptBlackWhiteListCount 本次传输的白名单的个数与写入白名单的路径
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_BlackWhiteListSetup(T_LprResult *ptLprResult,T_BlackWhiteListCount *ptBlackWhiteListCount);
/**********************************************************************
* 函数名称：Net_BlackWhiteListSend
* 功能描述：批量导入黑白名单到相机，字符编码必须为GB2312格式，适用于多条车牌与相机交互，当车牌数小于10条时，建议调用Net_SendBlackWhiteListByMess将白名单传入相机；
			车牌字符必须为GB2312编码
* 输入参数：tHandle 相机句柄
*			ptBalckWhiteList 相机黑白名单参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_BlackWhiteListSend(DCHANDLE tHandle, T_BlackWhiteList *ptBalckWhiteList);

/**********************************************************************
* 函数名称：Net_BlackWhiteListSendEx
* 功能描述：批量导入黑白名单到相机，字符编码必须为GB2312格式，适用于多条车牌与相机交互，当车牌数小于10条时，建议调用Net_SendBlackWhiteListByMessEx将白名单传入相机；
			车牌字符必须为GB2312编码
* 输入参数：tHandle 相机句柄
*			ptBalckWhiteList 相机黑白名单参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_BlackWhiteListSendEx(DCHANDLE tHandle, T_BlackWhiteList *ptBalckWhiteList);

/**********************************************************************
* 函数名称：Net_BlackWhiteListSendReportMess
* 功能描述：通过注册回调函数，上报导入白名单中不正确的车牌信息，配合Net_BlackWhiteListSend使用
* 输入参数：tHandle 相机句柄
*			fCb 回调函数
			{
				iErrCode 错误码 参见 E_BlackWhiteListErrorCode
				iLine >=0 不正确车牌的行数
				pPlateInfoPlateInfo 指向出错的车牌信息
				pUser	回调函数上下文
			}
			pUser 回调函数上下文

* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
typedef int (CALLBACK *FBlackWhiteListSendReportMess)(int iErrCode, int iLine, const char *pPlateInfo, void *pUser);
NET_API E_ReturnCode _stdcall Net_BlackWhiteListSendReportMess(DCHANDLE tHandle, FBlackWhiteListSendReportMess fCb, void *pUser);

/**********************************************************************
* 函数名称：Net_SendBlackWhiteListByMess
* 功能描述：通过消息将白名单导入到相机，适用于1到10条车牌信息与相机交互；当车牌数大于10条时，请参考批量导入接口Net_BlackWhiteListSend;
			车牌字符必须为GB2312编码
* 输入参数：tHandle 相机句柄
			pSendLprByMess	指向待传输车牌的信息
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SendBlackWhiteListByMess(DCHANDLE tHandle,T_SendLprByMess *ptSendLprByMess);

/**********************************************************************
* 函数名称：Net_DeleteAllBlackWhiteList
* 功能描述：删除相机内所有黑白名单
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_DeleteAllBlackWhiteList(DCHANDLE tHandle);

/**********************************************************************
* 函数名称：Net_ClearOfflineData
* 功能描述：清除脱机数据
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ClearOfflineData(DCHANDLE tHandle);

/**********************************************************************
* 函数名称：Net_QueryWhiteListByPlate
* 功能描述：通过车牌查询白名单内该车牌信息，车牌字符必须为GB2312编码
* 输入参数：tHandle 相机句柄
*			pPlateInfo 车牌号码
			ptLprResult 指向查询到的车牌信息
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryWhiteListByPlate(DCHANDLE tHandle, const char *pPlateInfo,T_RspLprResult *ptLprResult);

/**********************************************************************
* 函数名称：Net_GetBlackWhiteList
* 功能描述：导出相机黑白名单
* 输入参数：tHandle 相机句柄
*			ptBalckWhiteList 相机黑白名单参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_GetBlackWhiteList(DCHANDLE tHandle, T_GetBlackWhiteList *ptGetBalckWhiteList);

/**********************************************************************
* 函数名称：Net_GetBlackWhiteListAsCSV
* 功能描述：以CSV格式导出相机黑白名单
* 输入参数：tHandle 相机句柄
*			ptBalckWhiteList 相机黑白名单参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_GetBlackWhiteListAsCSV(DCHANDLE tHandle, T_GetBlackWhiteList *ptGetBalckWhiteList);

/**********************************************************************
* 函数名称：Net_GetBlackWhiteListAsCSVEx
* 功能描述：以CSV格式导出相机黑白名单
* 输入参数：tHandle 相机句柄
*			ptBalckWhiteList 相机黑白名单参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_GetBlackWhiteListAsCSVEx(DCHANDLE tHandle, T_GetBlackWhiteList *ptGetBalckWhiteList);

/**********************************************************************
* 函数名称：Net_SetControlCallBack
* 功能描述：通过注册该回调函数，获取相机的实时连接状态,相机连接状态见枚举E_ConnState
* 输入参数：pControlCallBack 回调函数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/

typedef void (CALLBACK *NET_CONTROLCALLBACK) (DCHANDLE tHandle,unsigned char ucCtrlConnState, void* pUser);
NET_API E_ReturnCode _stdcall Net_SetControlCallBack(NET_CONTROLCALLBACK pControlCallBack);

/**********************************************************************
* 函数名称：Net_SetControlCallBackEx
* 功能描述：通过注册该回调函数，获取相机的实时连接状态，Net_SetControlCallBack的扩展函数，增加回调函数上下文，相机连接状态见枚举E_ConnState
* 输入参数：tHandle 相机句柄
*			pControlCallBack 回调函数指针
			pUser 回调函数上下文
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/

typedef void (CALLBACK *NET_CONTROLCALLBACKEx) (DCHANDLE tHandle,unsigned char ucCtrlConnState, void* pUser);
NET_API E_ReturnCode _stdcall Net_SetControlCallBackEx(DCHANDLE tHandle,NET_CONTROLCALLBACKEx pControlCallBack, void* pUser);


/**********************************************************************
* 函数名称：Net_SetWhiteListMode
* 功能描述：设置白名单工作模式，即脱机使能，使能，不使能三种模式
* 输入参数：tHandle 相机句柄
*			ptWhiteListMode 白名单模式参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetWhiteListMode(DCHANDLE tHandle, T_WhiteListMode *ptWhiteListMode);

/**********************************************************************
* 函数名称：Net_QueryWhiteListMode
* 功能描述：查询白名单工作模式
* 输入参数：tHandle 相机句柄
*			ptWhiteListMode 白名单模式参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryWhiteListMode(DCHANDLE tHandle,T_WhiteListMode *ptWhiteListMode);

/**********************************************************************
* 函数名称：Net_ExportWhiteListTemplate
* 功能描述：导出白名单模板
* 输入参数：szPath 导出路径
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ExportWhiteListTemplate(unsigned char *szPath);

/**********************************************************************
* 函数名称：Net_LedSetup
* 功能描述：设置LED显示屏内容
* 输入参数：tHandle 相机句柄
*			ptSLedSetup LED显示内容参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SLedSetup(DCHANDLE tHandle,T_SLedSetup *ptSLedSetup);

/**********************************************************************
* 函数名称：Net_QueryLedSetup
* 功能描述：查询LED显示屏内容
* 输入参数：tHandle 相机句柄
*			ptSLedSetup LED显示内容参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QuerySLedSetup(DCHANDLE tHandle,T_SLedSetup *ptSLedSetup);

/**********************************************************************
* 函数名称：Net_SLedTfgSetup
* 功能描述：设置屏显扩展内容
* 输入参数：tHandle 相机句柄
*			T_SLedSetup_tfg 屏显扩展内容参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SLedTfgSetup(DCHANDLE tHandle,T_SLedSetup_tfg *ptSLedSetup);

/**********************************************************************
* 函数名称：Net_QuerySLedTfgSetup
* 功能描述：查询屏显扩展内容
* 输入参数：tHandle 相机句柄
*			T_SLedSetup_tfg 屏显扩展内容参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QuerySLedTfgSetup(DCHANDLE tHandle,T_SLedSetup_tfg *ptSLedSetup);

/**********************************************************************
* 函数名称： Net_SLedSetupExt
* 功能描述：设置LED显示屏扩展内容
* 输入参数：tHandle 相机句柄
*			ptSLedSetupExt LED显示扩展内容参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SLedSetupExt(DCHANDLE tHandle,T_SLedSetupExt *ptSLedSetupExt);

/**********************************************************************
* 函数名称： Net_QuerySLedSetupExt
* 功能描述：查询LED显示屏内容
* 输入参数：tHandle 相机句柄
*			ptSLedSetupExt LED显示扩展内容参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QuerySLedSetupExt(DCHANDLE tHandle,T_SLedSetupExt *ptSLedSetupExt);

/**********************************************************************
* 函数名称：Net_LedSetup
* 功能描述：设置LED显示屏内容
* 输入参数：tHandle 相机句柄
*			ptLedSetup LED显示内容参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_LedSetup(DCHANDLE tHandle,T_LedSetup *ptLedSetup);

/**********************************************************************
* 函数名称：Net_QueryLedSetup
* 功能描述：查询LED显示屏内容
* 输入参数：tHandle 相机句柄
*			ptLedSetup LED显示内容参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryLedSetup(DCHANDLE tHandle,T_LedSetup *ptLedSetup);

/**********************************************************************
* 函数名称：Net_LedSetupEx
* 功能描述：设置LED显示屏内容
* 输入参数：tHandle 相机句柄
*			ptLedSetup LED显示内容参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_LedSetupEx(DCHANDLE tHandle,T_LedSetup *ptLedSetup);

/**********************************************************************
* 函数名称：Net_QueryLedSetupEx
* 功能描述：查询LED显示屏内容
* 输入参数：tHandle 相机句柄
*			ptLedSetup LED显示内容参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryLedSetupEx(DCHANDLE tHandle,T_LedSetup *ptLedSetup);

/**********************************************************************
* 函数名称：Net_LedLzSetup
* 功能描述：设置LED显示屏内容
* 输入参数：tHandle 相机句柄
*			ptLedLzSetup LED显示内容参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_LedLzSetup(DCHANDLE tHandle,T_LZ_LedSetup *ptLedLzSetup);

/**********************************************************************
* 函数名称：Net_QueryLedLzSetup
* 功能描述：查询LED显示屏内容
* 输入参数：tHandle 相机句柄
*			ptLedLzSetup LED显示内容参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryLedLzSetup(DCHANDLE tHandle,T_LZ_LedSetup *ptLedLzSetup);

/**********************************************************************
* 函数名称：Net_LedDcSetup
* 功能描述：设置LED显示屏内容
* 输入参数：tHandle 相机句柄
*			ptDCScreenSetup LED显示内容参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_LedDcSetup(DCHANDLE tHandle,T_DCScreenSetup *ptDCScreenSetup);

/**********************************************************************
* 函数名称：Net_QueryLedDcSetup
* 功能描述：查询LED显示屏内容
* 输入参数：tHandle 相机句柄
*			ptDCScreenSetup LED显示内容参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryLedDcSetup(DCHANDLE tHandle,T_DCScreenSetup *ptDCScreenSetup);

/**********************************************************************
* 函数名称：Net_RegOffLineClient
* 功能描述：即将当前客户端注册为岗亭端，将相机与当前客户端链接状态作为相机是否脱机的依据
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_RegOffLineClient(DCHANDLE tHandle);

/**********************************************************************
* 函数名称：Net_ReadGPIOState
* 功能描述：读取指定接口的GPIO状态，即读取接入的车检器状态
* 输入参数：tHandle 相机句柄
			ucIndex  接口索引值，从0开始编号
			pucValue  指向返回的状态值的指针，0或1
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ReadGPIOState(DCHANDLE tHandle,unsigned char ucIndex,unsigned char *pucValue);

/**********************************************************************
* 函数名称：Net_WriteGPIOSate
* 功能描述：向指定接口的GPIO写入值，即向指定继电器写入状态。0为开路，1为短路
* 输入参数：tHandle 相机句柄
			ucIndex  接口索引值，从0开始编号
			ucValue  写入的状态值，0或1
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_WriteGPIOState(DCHANDLE tHandle,unsigned char ucIndex,unsigned char ucValue);

/**********************************************************************
* 函数名称：Net_WriteTwoEncpyption
* 功能描述：写入用户私有数据，用于二次加密
* 输入参数：tHandle 相机句柄
			pUserData	用户数据
*			uiDataLen 用户数据的长度
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_WriteTwoEncpyption(DCHANDLE tHandle,unsigned char *pUserData,unsigned int uiDataLen);

/**********************************************************************
* 函数名称：Net_ReadTwoEncpyption
* 功能描述：读出用户写入的私有数据
* 输入参数：tHandle 相机句柄
*			pBuff 用于存放读到的用户数据
			uiSizeBuff  用户数据缓冲区的大小,uiSizeBuff必须>=256
* 输出参数：无
* 返 回 值：返回值为实际用户数据的字节数，返回-1表示失败
***********************************************************************/ 
NET_API int _stdcall Net_ReadTwoEncpyption(DCHANDLE tHandle,  unsigned char *pBuff, unsigned int uiSizeBuff);

/**********************************************************************
* 函数名称：Net_TwoEncpyptionSet
* 功能描述：设置二次加密开启关闭
* 输入参数：tHandle 相机句柄
			ptTwoEncpyptionSet  二次加密设置结构体
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_TwoEncpyptionSet(DCHANDLE tHandle,  T_TwoEncpyptionSet *ptTwoEncpyptionSet);

/**********************************************************************
* 函数名称：Net_TwoEncpyptionAuth
* 功能描述：二次加密鉴权
* 输入参数：tHandle 相机句柄
			ptTwoEncpyptionAuth  二次加密鉴权结构体
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_TwoEncpyptionAuth(DCHANDLE tHandle,  T_TwoEncpyptionAuth *ptTwoEncpyptionAuth);

/**********************************************************************
* 函数名称：Net_TwoEncpyptionModify
* 功能描述：二次加密修改
* 输入参数：tHandle 相机句柄
			ptTwoEncpyptionModify  二次加密修改结构体
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_TwoEncpyptionModify(DCHANDLE tHandle,  T_TwoEncpyptionModify *ptTwoEncpyptionModify);

/**********************************************************************
* 函数名称：Net_TwoEncpyptionQuery
* 功能描述：二次加密查询开启关闭
* 输入参数：tHandle 相机句柄
			ptTwoEncpyptionQuery  二次加密开启关闭结构体
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_TwoEncpyptionQuery(DCHANDLE tHandle,  T_TwoEncpyptionQuery *ptTwoEncpyptionQuery);

/**********************************************************************
* 函数名称：Net_OffLinePayTest
* 功能描述：脱机收费测试
* 输入参数：tHandle 相机句柄
*			ptOfflineVehInfoTest 脱机收费测试结构体
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_OffLinePayTest(DCHANDLE tHandle, T_OfflineVehInfoTest *ptOfflineVehInfoTest);

/**********************************************************************
* 函数名称：Net_LensControl
* 功能描述：设置变倍马达
* 输入参数：tHandle 相机句柄
			ptLensControl 指向控制相机马达的结构体
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_LensControl(DCHANDLE tHandle,T_LensControl *ptLensControl);

/**********************************************************************
* 函数名称：Net_AssLensControl
* 功能描述：设置变倍马达
* 输入参数：tHandle 相机句柄
			ptLensControl 指向控制相机马达的结构体
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_AssLensControl(DCHANDLE tHandle,T_LensControl *ptLensControl);

/**********************************************************************
* 函数名称：Net_ParkLedLightSetup
* 功能描述：设置LED灯亮度
* 输入参数：tHandle 相机句柄
			ptParkLedLightSetup  指向LED灯亮度设置的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ParkLedLightSetup(DCHANDLE tHandle,T_ParkLedLightSetup *ptParkLedLightSetup);

/**********************************************************************
* 函数名称：Net_ParkLedLightSetup
* 功能描述：查询LED灯亮度
* 输入参数：tHandle 相机句柄
			ptParkLedLightSetup  指向LED灯亮度设置的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryParkLedLightSetup(DCHANDLE tHandle,T_ParkLedLightSetup *ptParkLedLightSetup);

/**********************************************************************
* 函数名称：Net_ChangeUserPassword
* 功能描述：更改用户名和密码
* 输入参数：tHandle 相机句柄
			ptUserAccount  指向用户名和密码配置的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ModifyUserPassword(DCHANDLE tHandle,T_ModifyUserAccount *ptUserAccount);

/**********************************************************************
* 函数名称：Net_ModifyUserPort
* 功能描述：更改用户连接端口
* 输入参数：tHandle 相机句柄
			ptUserPort  指向端口的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ModifyUserPort(DCHANDLE tHandle,T_UserPort *ptUserPort);

/**********************************************************************
* 函数名称：Net_SetWLFuzzyMatchMode
* 功能描述：设置白名单模糊匹配模式
* 输入参数：tHandle 相机句柄
			ptWlFuzzyMatch  指向模糊匹配规则的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetWLFuzzyMatchMode(DCHANDLE tHandle,T_WLFuzzyMatch *ptWlFuzzyMatch);

/**********************************************************************
* 函数名称：Net_QueryWLFuzzyMatchMode
* 功能描述：查询白名单模糊匹配模式
* 输入参数：tHandle 相机句柄
			ptWlFuzzyMatch  指向模糊匹配规则的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryWLFuzzyMatchMode(DCHANDLE tHandle,T_WLFuzzyMatch *ptWlFuzzyMatch);

/**********************************************************************
* 函数名称：Net_ManulWiperOpen
* 功能描述：手动开启雨刷
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ManulWiperOpen(DCHANDLE tHandle);

/**********************************************************************
* 函数名称：Net_ManulWiperClose
* 功能描述：手动关闭雨刷
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ManulWiperClose(DCHANDLE tHandle);

/**********************************************************************
* 函数名称：Net_SetOffLinePayMode
* 功能描述：设置脱机收费模式，即脱机使能，使能，不使能
* 输入参数：tHandle 相机句柄
			ptOffLinePayMode  指向脱机收费模式的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetOffLinePayMode(DCHANDLE tHandle,T_OffLinePayMode *ptOffLinePayMode);

/**********************************************************************
* 函数名称：Net_QueryOffLinePayMode
* 功能描述：查询脱机收费模式
* 输入参数：tHandle 相机句柄
			ptOffLinePayMode  指向脱机收费模式的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryOffLinePayMode(DCHANDLE tHandle,T_OffLinePayMode *ptOffLinePayMode);

/**********************************************************************
* 函数名称：Net_SetOffLinePayRule
* 功能描述：设置脱机收费规则
* 输入参数：tHandle 相机句柄
			ptOffLinePayRule  指向脱机收费规则的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetOffLinePayRule(DCHANDLE tHandle,T_PayRule *ptOffLinePayRule);

/**********************************************************************
* 函数名称：Net_QueryOffLinePayRule
* 功能描述：查询脱机收费规则
* 输入参数：tHandle 相机句柄
			ptOffLinePayRule  指向脱机收费规则的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryOffLinePayRule(DCHANDLE tHandle,T_PayRule *ptOffLinePayRule);

/**********************************************************************
* 函数名称：Net_SetGateAutoOpen
* 功能描述：设置出入口相机自动抬闸配置
* 输入参数：tHandle 相机句柄
			ptAutoControlGate  指向出入口相机自动抬闸规则的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetGateAutoOpen(DCHANDLE tHandle,T_AutoControlGate *ptAutoControlGate);

/**********************************************************************
* 函数名称：Net_QueryGateAutoOpen
* 功能描述：查询出入口相机自动抬闸配置
* 输入参数：tHandle 相机句柄
			ptAutoControlGate  指向出入口相机自动抬闸规则的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryGateAutoOpen(DCHANDLE tHandle,T_AutoControlGate *ptAutoControlGate);

/**********************************************************************
* 函数名称：Net_SyncConfigByMulticast
* 功能描述：通过组播同步相机配置到其他相机
* 输入参数：tHandle 相机句柄
			ptSyncConfigByMuticast  指向同步相机配置规则的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SyncConfigByMulticast(DCHANDLE tHandle,T_SyncConfigByMuticast *ptSyncConfigByMuticast);

/**********************************************************************
* 函数名称：Net_SetVideoRotate
* 功能描述：设置视频旋转
* 输入参数：tHandle 相机句柄
			ptVideoRotate  指向视频旋转的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetVideoRotate(DCHANDLE tHandle,T_VideoRotate *ptVideoRotate);

/**********************************************************************
* 函数名称：Net_QueryVideoRotate
* 功能描述：查询视频旋转
* 输入参数：tHandle 相机句柄
			ptVideoRotate  指向视频旋转的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryVideoRotate(DCHANDLE tHandle,T_VideoRotate *ptVideoRotate);

/**********************************************************************
* 函数名称：Net_SetAudioVol
* 功能描述：设置语音音量
* 输入参数：tHandle 相机句柄
			ptAudioVol  指向语音音量的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetAudioVol(DCHANDLE tHandle,T_AudioVol *ptAudioVol);

/**********************************************************************
* 函数名称：Net_QueryAudioVol
* 功能描述：查询语音音量
* 输入参数：tHandle 相机句柄
			ptAudioVol  指向语音音量的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryAudioVol(DCHANDLE tHandle,T_AudioVol *ptAudioVol);

/**********************************************************************
* 函数名称：Net_AudioTalkBack
* 功能描述：语音对讲设置
* 输入参数：tHandle 相机句柄
			ptAudioTalkBack  指向语音对讲的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_AudioTalkBack(DCHANDLE tHandle, T_AudioTalkBack *ptAudioTalkBack);

/**********************************************************************
* 函数名称：Net_StartTalk
* 功能描述：开启语音对讲
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_StartTalk(DCHANDLE tHandle);

/**********************************************************************
* 函数名称：Net_StopTalk
* 功能描述：关闭语音对讲
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_StopTalk(DCHANDLE tHandle);

NET_API E_ReturnCode _stdcall Net_StartRecordCameraVoice(char * strFilePath);
NET_API E_ReturnCode _stdcall Net_StopRecordCameraVoice();
NET_API E_ReturnCode _stdcall Net_StartRecordPcVoice(char * strFilePath);
NET_API E_ReturnCode _stdcall Net_StopRecordPcVoice();

/**********************************************************************
* 函数名称：Net_ImportBlackWhiteList
* 功能描述：导入相机黑白名单
* 输入参数：tHandle 相机句柄
*			ptBalckWhiteList 相机黑白名单参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ImportBlackWhiteList(DCHANDLE tHandle, T_BlackWhiteList *ptBalckWhiteList);

NET_API E_ReturnCode _stdcall Net_ImportBlackWhiteListEx(DCHANDLE tHandle, T_BlackWhiteList *ptBalckWhiteList);

NET_API E_ReturnCode _stdcall Net_ImportBlackWhiteListCy(DCHANDLE tHandle, T_BlackWhiteList *ptBalckWhiteList);

/**********************************************************************
* 函数名称：Net_ExportBlackWhiteList
* 功能描述：导出相机黑白名单
* 输入参数：tHandle 相机句柄
*			ptGetBalckWhiteList 相机黑白名单参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ExportBlackWhiteList(DCHANDLE tHandle, T_GetBlackWhiteList *ptGetBalckWhiteList);

NET_API E_ReturnCode _stdcall Net_ExportBlackWhiteListAsCSV(DCHANDLE tHandle, T_GetBlackWhiteList *ptGetBalckWhiteList);

NET_API E_ReturnCode _stdcall Net_ExportBlackWhiteListCyAsCSV(DCHANDLE tHandle, T_GetBlackWhiteList *ptGetBalckWhiteList);


/**********************************************************************
* 函数名称：Net_ImportRePlate
* 功能描述：导入车牌后处理规则
* 输入参数：tHandle 相机句柄
*			strFile 文件名
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ImportRePlate(DCHANDLE tHandle, const char * strFile);

/**********************************************************************
* 函数名称：Net_ExportRePlate
* 功能描述：导出车牌后处理规则
* 输入参数：tHandle 相机句柄
*			strFile 文件名
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ExportRePlate(DCHANDLE tHandle, const char * strFile);

#ifdef __cplusplus
}
#endif
#endif

