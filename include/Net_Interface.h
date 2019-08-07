/**************************************************************************
* ��    Ȩ�� 	Copyright (c) 2015 
* �ļ����ƣ�	Net_Interface.h
* �ļ���ʶ�� 
* ����ժҪ��    ��������翪��SDK,������Ƶ����ͼƬ��������Ϣ
* ����˵���� 
* ��ǰ�汾��	V1.0
* ��    ��	
* ������ڣ�	2013��08��28��
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
 *                         ��������                                    *
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
	WL_MODE_OFFLINE,	 /*�ѻ�ʹ��*/ 
	WL_MODE_ENABLE,	 /*������ʹ�ܣ��������������ѻ�*/ 
	WL_MODE_DISABLE,	 /*��������ʹ��*/ 
	WL_MODE_MAX 
}E_WhiteListMode; 

typedef struct
{
	unsigned char ucMode;
	unsigned char ucArmyPoliceEn; /*�������Զ�����ʹ�ܱ�ʶ*/ 
	unsigned char ucNotSnaptmp;/*�ѻ��²�������ʱ����¼*/
	unsigned char acReserved;
}T_WhiteListMode;

typedef enum
{
	LED_SUB_MOD_VEH_PLATE=0,/*������ʾ*/
	LED_SUB_MOD_VEH_WELCOME,/*��ӭ����ʾ*/
	LED_SUB_MOD_VEH_PAY,  /*ͣ��������ʾ*/
	LED_SUB_MOD_VEH_TIME, /*ͣ��ʱ����ʾ*/
	LED_SUB_MOD_VEH_PERIOD, /*������Ч����ʾ*/
	LED_SUB_MOD_TIME,/*ʱ����ʾ����ʽ:XXXX��XX��XXʱXX��*/
	LED_SUB_MOD_VEH_LEFT,/*ʣ��ͣ��λ��ʾ*/
	LED_SUB_MOD_CUSTOM,  /*�Զ���������ʾ*/
	LED_SUB_MOD_MAX,
}E_SubLedMode;

typedef struct
{
	unsigned char 	ucEnable;
	unsigned char  	ucInterval;//ʱ����  s��
	unsigned char   ucLedLine;//˫����������1������2;
	unsigned char   ucMode;//E_SubLedMode
	unsigned char   aucContent[MAX_LED_CONTENT]; //GB2312���Զ���ģʽ��Ч
}T_SubLedSetup;

typedef struct
{
	//unsigned char           ucType;//��ڿ���-0; ���æ-1; ���ڿ���-2; ����æ-3;
	unsigned char           ucAudioEnable;
	unsigned char           ucReserved[3];
	T_SubLedSetup   atSubLedInIdle[MAX_LED_COUNT];//��ڿ���
	T_SubLedSetup   atSubLedInBusy[MAX_LED_COUNT];//���æ  
	T_SubLedSetup   atSubLedOutIdle[MAX_LED_COUNT];//���ڿ���
	T_SubLedSetup   atSubLedOutBusy[MAX_LED_COUNT];//����æ
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
	unsigned char  	ucInterval;		//ʱ����  s��
	unsigned char   ucLedLine;		//(��������)
	unsigned char   ucLedcolor;  	//E_LED_COLOR
	unsigned short  usModeBit;		
	unsigned char  ucReserved[2];
	unsigned char  welAudioText[MAX_VEL_CONTENT]; 	//GB2312��ѹ�ظб���ӭ��
	unsigned char  levAudioText[MAX_VEL_CONTENT]; 	//GB2312����բ����ӭ��
	unsigned char  aucContent[MAX_LED_CONTENT]; //GB2312���Զ���ģʽ��Ч
}T_LZ_SubLedSetup;

typedef struct
{
	//unsigned char           ucType;//��ڿ���-0; ���æ-1; ���ڿ���-2; ����æ-3;
	unsigned char   ucAudioEnable;
	unsigned char   ucReserved[3];
	T_LZ_SubLedSetup   atSubLedIdle[MAX_LZ_LED_COUNT];//����
	T_LZ_SubLedSetup   atSubLedBusy[MAX_LZ_LED_COUNT];//æ  
}T_LZ_LedSetup;

typedef struct
{
	unsigned char   ucLedSubType;  //E_LedScreenSubType
	unsigned char   ucReserved[3];
	char			acInContent[MAX_LED_CONTENT]; //GB2312���Զ���ģʽ��Ч
	char			acOutContent[MAX_LED_CONTENT]; //GB2312���Զ���ģʽ��Ч
}T_DCScreenSetup;

/*֡��Ϣ*/
#ifndef _T_FRAMEINFO_
#define _T_FRAMEINFO_
typedef struct
{
	unsigned int uiFrameId;          //֡ID
	unsigned int uiTimeStamp;        //RTPʱ���
	unsigned int uiEncSize;          //֡��С
	unsigned int uiFrameType;        // 1:i֡ 0:����

}T_FrameInfo;
#endif

typedef struct
{
	unsigned int	uiImageId;
	unsigned char   ucLightIndex;	/*������ţ�1~25,������ĳ�������һ��*/
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
	VEHCOLOR_UNKNOW = 0,/*δ֪*/
	VEHCOLOR_WHITE = 1,/* ��*/
	VEHCOLOR_BLACK = 2,/* ��*/
	VEHCOLOR_RED = 3,/* ��*/
	VEHCOLOR_BLUE = 4,/* ��*/
	VEHCOLOR_YELLOW = 5,/* ��*/
	VEHCOLOR_GRAY = 6,/* ��*/
	VEHCOLOR_GREEN = 7,/* ��*/
	VEHCOLOR_LIGHT_RED = 8,/*ǳ��*/
	VEHCOLOR_LIGHT_BLUE = 9,/*ǳ��*/
	VEHCOLOR_LIGHT_YELLOW = 10,/*ǳ��*/
	VEHCOLOR_LIGHT_GRAY = 11,/*ǳ��*/
	VEHCOLOR_LIGHT_GREEN = 12,/*ǳ��*/
	VEHCOLOR_DARK_BROWN = 13,/*����*/
	VEHCOLOR_DARK_PINK = 14,	/*���*/
	VEHCOLOR_LIGHT_BROWN = 15,/*ǳ��*/
	VEHCOLOR_LIGHT_PINK = 16, /*ǳ��*/
	VEHCOLOR_DARK_RED = 17,/*���*/
	VEHCOLOR_DARK_BLUE = 18,/*����*/
	VEHCOLOR_DARK_YELLOW = 19,/*���*/
	VEHCOLOR_DARK_GRAY = 20,/*���*/
	VEHCOLOR_DARK_GREEN = 21,/*����*/
	VEHCOLOR_ALL,
}E_VehColorType;


//������Ϣ
typedef enum
{
	UNKNOWN_FLAG,
	TOYOTA,        /*����*/
	VolksWagen,    /*����*/
	HONDA,         /*����*/
	PEUGEOT,       /*����*/
	HYUNDAI,       /*�ִ�*/
	BUICK,         /*���*/
	AUDI,          /*�µ�*/
	KIA,           /*����*/
	JEEP,          /*����*/
	FORD,          /*����*/
	BENZ,          /*����*/
	BMW,           /*����*/
	MAZDA,         /*���Դ�*/
	SUZUKI,        /*��ľ*/
	CITROEN,       /*ѩ����*/
	NISSAN,        /*��ɣ*/
	MITSUBISHI,    /*����*/
	LEXUS,         /*�׿���˹*/
	CHEVROLET,     /*ѩ����*/
	VOLVO,         /*�ֶ���*/
	FIAT,          /*������*/
	BYD,           /*���ǵ�*/
	CHERY          /*����*/
}E_VehicleFlag;

//������Ϣ
typedef enum    its_tb_vt
{
	TB_VEHICLE_TYPE_NULL=0,    //δ֪
    TB_VEHICLE_TYPE_LARGE=1,   //���ͳ�
    TB_VEHICLE_TYPE_MEDIUM,    //���ͳ�
    TB_VEHICLE_TYPE_SMALL,     //С�ͳ� 
	TB_VEHICLE_TYPE_MOTOCYCLE, //Ħ�г�
    TB_VEHICLE_TYPE_PEDESTRIAN,//����
}ITS_Tb_Vt; 

typedef enum
{
	VIO_CODE_NORMAL = 0,  		/*��������*/
	VIO_CODE_BLACKLIST,    		/*����������*/
	VIO_CODE_OVERSPEED_LITTLE,	/*����50%����*/
	VIO_CODE_OVERSPEED_MID,		/*����50%~100%*/
	VIO_CODE_OVERSPEED_MORE,    /*����100%����*/
	VIO_CODE_RETROGRADE,   		/*����*/
	VIO_CODE_RUSH_REDLIGHT,		/*�����*/
	VIO_CODE_LOWSPEED, 			/*������ʻ*/
	VIO_CODE_PROHIBIT,			/*����*/
	VIO_CODE_EXCEED,			/*Խ��*/
	VIO_CODE_ABNORMAL_STEER,	/*����������ʻ*/
	VIO_CODE_ILLEGAL_STOP,      /*Υͣ*/
	VIO_CODE_FACE_MAIN,         /*������ͼ*/
	VIO_CODE_FACE,              /*����*/
	VIO_CODE_ALL,
}E_ViolationCode;

/* �г������� */
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
	CONN_STATE_TRYING, 		/*������*/
	CONN_STATE_SUCC,		/*���ӳɹ�*/
	CONN_STATE_DIS,			/*����ʧ��*/
	CONN_STATE_ALL,
}E_ConnState;

typedef enum 
{ 
	SNAP_MODE_UNKNOW = 0, 
	SNAP_MODE_MANUAL,	 /*�ֶ�*/ 
	SNAP_MODE_VIDEO,     /*��Ƶ*/ 
	SNAP_MODE_LOOP,      /*��Ȧ*/ 
	SNAP_MODE_MAX, 
}E_SnapType;

typedef enum its_ep_pt
{
	EP_PLATE_TYPE_NULL=0,      //δ֪
	EP_PLATE_TYPE_BLUE,        //��ͨ����
	EP_PLATE_TYPE_BLACK,       //��ͨ����
	EP_PLATE_TYPE_YELL,        //��ͨ����
	EP_PLATE_TYPE_YELL2,       //˫�����
	EP_PLATE_TYPE_POL,         //���쳵��
	EP_PLATE_TYPE_APOL,        //�侯����
	EP_PLATE_TYPE_APOL2,       //˫���侯    
	EP_PLATE_TYPE_ARM,         //�������
	EP_PLATE_TYPE_ARM2,        //˫�����
	EP_PLATE_TYPE_INDI,        //���Գ���
	EP_PLATE_TYPE_NEWN,        //����ԴС����
	EP_PLATE_TYPE_NEWN1,       //����Դ����
	EP_PLATE_TYPE_EMB,         //��ʹ�ݳ���
	EP_PLATE_TYPE_CON,         //���¹ݳ���
	EP_PLATE_TYPE_MIN,         //�񺽳���
}ITS_Ep_Pt;

typedef enum
{
	IPNC_TYPE_UNKNOW = 0,
	IPNC_TYPE_ENTRY,
	IPNC_TYPE_EXIT,
	IPNC_TYPE_PLATE_REC,  /*����ʶ�����*/
	IPNC_TYPE_MAX,     
}E_IpncType;

/*����ͼƬץ����Ϣ*/
typedef struct 
{
	unsigned short 	usWidth;   /*ͼƬ�Ŀ�ȣ���λ:����*/
	unsigned short	usHeight;  /*ͼƬ�ĸ߶ȣ���λ:����*/
	unsigned char	ucVehicleColor;/*������ɫ��E_ColorType*/
	unsigned char	ucVehicleBrand;/*���꣬E_VehicleFlag*/
	unsigned char	ucVehicleSize;/*����(1��2��3С)��ITS_Tb_Vt,Ŀǰ���ݳ�����ɫ�����ִ�С��������ΪС��������Ϊ��*/
	unsigned char	ucPlateColor;/*������ɫ��E_ColorType*/
	char  			szLprResult[16];/*���ƣ���Ϊ'\0'����ʾ��ЧGB2312����*/
	unsigned short	usLpBox[4];  /*����λ�ã����Ͻ�(0, 1), ���½�(2,3)*/
	unsigned char	ucLprType;/*��������, ITS_Ep_Pt*/
	unsigned short 	usSpeed;     /*��λkm/h*/
	unsigned char 	ucSnapType;  /*ץ��ģʽ, E_SnapType*/
	unsigned char 	ucReserved;     
	char 			acSnapTime[18];         /*ͼƬץ��ʱ��:��ʽYYYYMMDDHHMMSSmmm(������ʱ�������)*/
	
	unsigned char	ucViolateCode;    /*Υ������E_ViolationCode*/
	unsigned char	ucLaneNo;          /*������,��0��ʼ����*/
	unsigned int 	uiVehicleId; 		/*��⵽�ĳ���id����Ϊͬһ��������id��ͬ*/
	unsigned char	ucScore;    		/*����ʶ����ж�*/
	unsigned char	ucDirection;       /*�г�����E_IpncType*/
	unsigned char	ucTotalNum;        /*�ó���ץ��������*/
	unsigned char	ucSnapshotIndex;   /*��ǰץ�ĵڼ��ţ���0��ʼ���*/
}T_ImageUserInfo;

/*����ͼƬץ����Ϣ*/
typedef struct 
{
	unsigned short 	usWidth;   /*ͼƬ�Ŀ�ȣ���λ:����*/
	unsigned short	usHeight;  /*ͼƬ�ĸ߶ȣ���λ:����*/
	unsigned char	ucVehicleColor;/*������ɫ��E_ColorType*/
	unsigned char	ucVehicleBrand;/*���꣬E_VehicleFlag*/
	unsigned char	ucVehicleSize;/*����(1��2��3С)��ITS_Tb_Vt,Ŀǰ���ݳ�����ɫ�����ִ�С��������ΪС��������Ϊ��*/
	unsigned char	ucPlateColor;/*������ɫ��E_ColorType*/
	char  			szLprResult[16];/*���ƣ���Ϊ'\0'����ʾ��ЧGB2312����*/
	unsigned short	usLpBox[4];  /*����λ�ã����Ͻ�(0, 1), ���½�(2,3)*/
	unsigned char	ucLprType;/*��������, ITS_Ep_Pt*/
	unsigned short 	usSpeed;     /*��λkm/h*/
	unsigned char 	ucSnapType;  /*ץ��ģʽ, E_SnapType*/
	unsigned char 	ucReserved;     
	char 			acSnapTime[18];         /*ͼƬץ��ʱ��:��ʽYYYYMMDDHHMMSSmmm(������ʱ�������)*/

	unsigned char	ucViolateCode;    /*Υ������E_ViolationCode*/
	unsigned char	ucLaneNo;          /*������,��0��ʼ����*/
	unsigned int 	uiVehicleId; 		/*��⵽�ĳ���id����Ϊͬһ��������id��ͬ*/
	unsigned char	ucScore;    		/*����ʶ����ж�*/
	unsigned char	ucDirection;       /*�г�����E_Direction*/
	unsigned char	ucTotalNum;        /*�ó���ץ��������*/
	unsigned char	ucSnapshotIndex;   /*��ǰץ�ĵڼ��ţ���0��ʼ���*/

	unsigned int 	uiVideoProcTime;   /*����ͷ�Ӵ������յ��ϴ����Ƶ���ʱ����λms*/
	char			strVehicleBrand[128]; /*����Ʒ��*/
	char			strConfidence[12];	  /*���Ϳ��Ŷ�*/
	char			strSpecialCode[20][12]; /*������*/
	char			ucHasCar;				/*�Ƿ��г�*/
	char			aucReserved1[3];			/*�����ֶ�*/
	unsigned char   aucReserved2[252];		/*�����ֶ�*/
}T_ImageUserInfo2;


/* ��Ա ����*/
typedef enum {
	TEMPORARY_CAR = 0,  	/* ��ʱ��*/
	MOON_CAR,      	/* �¿�*/
	VIP_CAR,   		/* �����*/
	STORED_CAR,  	/* ��ֵ��*/
	LEAD_CAR,      	/* �쵼��*/
	SPECIAL_CAR,   	/* ���⳵*/
	INSIDE_CAR ,  	/* �ڲ���*/
	WHITE_CAR,     	/* ������*/
	BLACK_CAR,  	 /* ������*/
	MAX_CAR
} E_MemberType;


typedef struct
{
	char			acPlate[16];	 /* ���ƺ��룬GB2312���� */
	char			acEntryTime[18]; /* �볡ʱ��*/
	char			acExitTime[18]; /* ����ʱ��*/
	unsigned int	uiRequired;  /* Ӧ����0.1ԪΪ��λ*/
	unsigned int	uiPrepaid;  	/* �Ѹ���0.1ԪΪ��λ*/
	unsigned char	ucVehType;  /* ��������1С��2�� E_ParkVehSize*/
	unsigned char	ucUserType;  /*��Ա����E_MemberType*/
	char			ucResultCode; /* �շѽ��״̬��0 �ɹ� 1 û���ҵ��볡��¼*/
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
	unsigned  char		ucReserved[3];  /*ucReserved[0]��ʾ0-4·IO��������*/
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
	unsigned int uiPanoramaPicLen;  /*ȫ��ͼƬ��С*/
	unsigned int uiVehiclePicLen;      /*����ͼƬ��С*/
	unsigned char *ptPanoramaPicBuff;   /*ȫ��ͼƬ������*/
	unsigned char *ptVehiclePicBuff;  /*����ͼƬ������*/
}T_PicInfo;

typedef struct
{
	unsigned char LprResult[16];/*���ƺ��룻������Ϣ���80�����ƺ��룻�����ֶ�����Ϣ����*/
	unsigned char StartTime[16];//eg:20151012190303 YYYYMMDDHHMMSS
	unsigned char EndTime[16];//eg:20151012190303 YYYYMMDDHHMMSS
}T_LprResult;

typedef enum
{
	ADD_PLATE_MODE,//���������ó����Ѵ��ڣ�����Զ�����
	DELETE_PLATE_MODE,//ɾ��
	SEND_MODE_MAX
}E_SendLprMode;


typedef struct 
{
	unsigned char ucType;//E_SendLprMode
	unsigned char ucConut;//���δ���ĳ��Ƹ���
	unsigned char aucReserved[2];//����λ
	T_LprResult	  atLprResult[10];//������Ϣ
}T_SendLprByMess;

typedef struct  
{
	unsigned char ucResult; //��ѯ�Ľ����0Ϊδ�ҵ��ó��ƣ�1Ϊ�ɹ��ҵ��ó���
	unsigned char aucReserved[3];
	T_LprResult	  tLprResult;
}T_RspLprResult;
typedef struct
{
	int uiCount;  /* ��ǰ׼��д��������ĳ��Ƹ�������ptLprResultָ��Ĵ�д��ĳ��Ƶĸ���*/
	char aucLplPath[256];
}T_BlackWhiteListCount;
typedef struct
{
	unsigned char LprMode;  /* 0����������1��������*/
	unsigned char LprCode;      /* 0�����ƺ���utf-8�ַ����룻1�����ƺ���gb2312�ַ�����*/
	unsigned char Lprnew; /*0�� ���·��ͣ�1��������2:ɾ����*/
	char aucLplPath[256];
}T_BlackWhiteList;


typedef struct
{
	unsigned char LprMode;  /* 0����������1��������*/
	unsigned char LprCode;      /* 0�����ƺ���utf-8�ַ����룻1�����ƺ���gb2312�ַ�����*/
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
	unsigned char       ucType; //����1 �佹2
	unsigned char       ucReserved[3];
}T_AssCameraType;

#ifndef _T_RCVMSG_
#define _T_RCVMSG_
typedef struct
{
	unsigned int		uiFlag;								/*��־λ��111��ʾVersion��IP��MAC*/
	unsigned char		aucDstMACAdd[6];					/*Ŀ��MAC��ַ*/
	char				aucAdapterName[VERSION_NAME_LEN];	/*��������������*/		
	unsigned int		uiAdapterSubMask;					/*������������������*/
	char				ancDevType[64];						/* �豸���ͣ�����ʱ�趨��*/
	char				ancSerialNum[64];					/* �豸���к�*/
	char				ancAppVersion[VERSION_NAME_LEN];	/* ����汾*/
	char				ancDSPVersion[VERSION_NAME_LEN];	/* DSP�汾*/
	T_NetSetup			tNetSetup;							/* ������Ϣ*/
	T_MACSetup			tMacSetup;							/* MAC��Ϣ*/
}T_RcvMsg;
#endif

typedef struct 
{ 
	unsigned char ucRegState; /*0:ע�� 1��ע��*/ 
	unsigned char aucReserved[3]; 
}T_RegState;//ע��ע����ͤ��

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
	unsigned char ucState;//0��ʾ�ɹ�
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
	unsigned char	switchflag;// 1 ��  0 �ر� 
	unsigned char	aucReserved[3];
	T_TwoEncpyption Encpyptioninfo;// ���μ����ַ���
}T_TwoEncpyptionSet;//���ÿ����ر�

typedef struct
{
	T_TwoEncpyption Encpyptioninfo;// ���μ����ַ���
	unsigned char	aucReserved[4];
}T_TwoEncpyptionAuth;//��Ȩ

typedef struct
{
	T_TwoEncpyption currentEncpyption;// ��ǰ���μ����ַ���
	T_TwoEncpyption newEncpyption;// �¶��μ����ַ���
	unsigned char	aucReserved[4];
}T_TwoEncpyptionModify;//�޸�

typedef struct
{
	unsigned char	switchflag;// 1 ��  0 �ر� 
	unsigned char	aucReserved[3];
}T_TwoEncpyptionQuery;//��ѯ�����ر�

typedef struct
{
	char acOldPwd[32]; /*AES 128λ�㷨 ����MAC��ַ�ַ���,��base64*/
	T_TwoEncpyption Encpyptioninfo;// ���μ����ַ���
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
	unsigned short usLensSteps; // ����(1-20) 
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
	unsigned char	ucLumaTH; //���ȷ�ֵ1~100 
	unsigned char	ucReserved;
}T_ParkLedLightSetup;
typedef struct 
{ 
	char acUserName[32]; 
	char acPasswd[36]; /*����*/ 
}T_UserAccount; 
typedef struct
{
	char acOldUserName[32];
	char acOldPasswd[36];     /*����*/
	char acNewUserName[32];
	char acNewPasswd[36];     /*����*/
}T_ModifyUserAccount;
typedef struct 
{ 
	unsigned short	usUserPort;
	unsigned short	usReserved;
}T_UserPort; 
typedef enum 
{ 
	WL_FM_FULL = 0,	 /*��ȷ����*/ 
	WL_FM_SIMILAR = 0x1,	/*�����ַ�����:0-D 8-B 0-Q E-F*/ 
	WL_FM_ORD_CHAR = 0x2, /*��ͨ�ַ����������ʧ�ܸ���*/ 
	WL_FM_IGN_CC = 0x4,	/*���Ժ���*/ 
	WL_FM_MAX, 
}E_WhilteListFuzzyMatch; 
/******************************************************************************************************
ucMatchMode ����λ����
ucMatchMode	WL_FM_IGN_CC  WL_FM_ORD_CHAR  WL_FM_SIMILAR
	0			0				0				0			��ȷƥ��ģʽ
	1			0				0				1			�����ַ�ƥ��ģʽ
	2			0				1				0			��ͨ�ַ�ƥ��ģʽ
	3			0				1				1			�����ַ�ƥ��ģʽ+��ͨ�ַ�ƥ��ģʽ
	4			1				0				0			���Ժ���ģʽ
	5			1				0				1			���Ժ���ģʽ+�����ַ�ƥ��ģʽ
	6			1				1				0			���Ժ���ģʽ+��ͨ�ַ�ƥ��ģʽ
	7			1				1				1			���Ժ���ģʽ+��ͨ�ַ�ƥ��ģʽ+�����ַ�ƥ��ģʽ
*********************************************************************************************************/	
typedef struct 
{ 
	unsigned char	ucMatchMode; /*E_WhilteListFuzzyMatch*/ 
	unsigned char	ucValue; /*WL_FM_ORD_CHAR ʱʹ��*/ 
	unsigned char	aucReserved[2]; 
}T_WLFuzzyMatch;

typedef enum 
{ 
	OP_MODE_UNKNOW = 0, 
	OP_MODE_OFFLINE,	 /*�ѻ�ʹ��*/ 
	OP_MODE_ENABLE,	 /*ʹ�ܣ��������������ѻ�*/ 
	OP_MODE_DISABLE,	 /*��ʹ��*/ 
	OP_MODE_MAX 
}E_OffLinePayMode; 

typedef struct
{
	unsigned char	ucMode;//E_OffLinePayMode
	unsigned char	aucReserved[3];
}T_OffLinePayMode;//�ѻ��շ�ģʽ
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
	PAY_MODE_ONTIME,/*��ʱ�Ʒ� */
	PAY_MODE_TIMES,/*���μƷ� */
	PAY_MODE_TIME_SECTION,/*�ֶμƷ� */
	PAY_MODE_TABLE,/*���Ʒ� */
	PAY_MODE_MAX
}E_PayMode;   /*�Ʒ�ģʽ*/

typedef enum
{
	STRATEGY_TYPE_UNKNOW = 0,
	STRATEGY_TYPE_NOPAY, //���շ�
	STRATEGY_TYPE_CYCLE,//��һ�������շ�
	STRATEGY_TYPE_BYTIME,//����ʱ���շ�
	STRATEGY_TYPE_MAX
}E_StrategyType;  /*����һ�����ڵļƷѲ���*/
typedef struct
{
	unsigned char	ucEnable;
	unsigned char	ucVehType;	/*��������*/
	unsigned char	aucReserved[2];
	unsigned short	usCyclePay;/* �����շѽ��*/
	unsigned short	usStartPay;/* �𲽽��*/
	unsigned short	usFreeTime;/* ���ʱ��*/
	unsigned short	usCycleTime;/* �Ʒ�����*/
	unsigned short	usStartTime;/* ��ʱ��*/
	unsigned short	usTotalPreDay;/* �ⶥ���*/
}T_OnTimePay;  /*��ʱ�շ�*/

typedef struct
{
	unsigned char	ucEnable;
	unsigned char	ucVehType;	/*��������*/
	unsigned char	ucMaxTime;/*�ⶥ����*/
	unsigned char	ucReserved;
	unsigned short	usPayOne;/*һ���շѽ��*/
	unsigned short	usFreeTime;/*���ʱ��*/
	unsigned short	usFreeStartTime;  /*��ѿ�ʼʱ�䣬�Է���Ϊ��λ*/
	unsigned short	usFreeEndTime; /*��ѽ���ʱ�䣬�Է���Ϊ��λ*/
	unsigned short	usPayStartTime;  /*�շѿ�ʼʱ�䣬�Է���Ϊ��λ*/
	unsigned short	usPayEndTime;/*�շѽ���ʱ�䣬�Է���Ϊ��λ*/
}T_TimesPay; /*�����շ�*/

typedef struct
{
	unsigned char	ucEnable;
	unsigned char	ucVehType;	/*��������*/
	unsigned char	aucReserved[2];
	unsigned short	usCyclePay;/* �����շѽ��*/
	unsigned short	usStartPay;/* �𲽽��*/
	unsigned short	usFreeTime;/* ���ʱ��*/
	unsigned short	usCycleTime;/* �Ʒ�����*/
	unsigned short	usStartTime;/* ��ʱ��*/
	unsigned short	usTotalPreDay;/* ʱ�ηⶥ���*/
	unsigned short	usSectionStartTime;  /*ʱ�ο�ʼʱ�䣬�Է���Ϊ��λ*/
	unsigned short	usSectionEndTime;/*ʱ�ν���ʱ�䣬�Է���Ϊ��λ*/
}T_TimeSectionPay;	/*��ʱ���շ�*/

typedef struct
{
	unsigned short usFreeTime;
	unsigned short usTotalPreDay;
	unsigned short usTablePay[48];	
	unsigned char  ucTableType;  /* 0�԰�СʱΪ��λ,1��1СʱΪ��λ*/
	unsigned char aucReserved[3];
}T_TablePay; /*����շ�*/

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
	unsigned char ucType;  /*������Ϣ���ݣ�0Ϊ�����ڳ���Ϣ��*/
	char aucLplPath[256];
}T_GetPrensentVehInfo;

typedef struct
{
	unsigned char	ucEntryEnable;//�������Ƿ�̧բʹ�ܱ�־
	unsigned char	ucExitEnable;//�������Ƿ�̧բʹ�ܱ�־
	unsigned char	aucReserved[2];
}T_AutoControlGate;

typedef enum
{
	Sync_OffLine_Pay_Rule,//ͬ���շѹ���
	Sync_OffLine_Pay_Mode,//ͬ���շ�ģʽ
	Sync_OffLine_Auto_Open_Gate,//ͬ�����̧բ����
	Sync_485Ctrl_Rule,//ͬ��485����
	Sync_LampCtrl_Rule,//ͬ���ƿع���
	Sync_Max_Type
}E_SyncType;

typedef struct
{
	unsigned char	ucSyncType;//E_SyncType
	unsigned char	aucReserved[3];
}T_SyncConfigByMuticast;

typedef enum
{
	BlackWhiteList_NoError = 0, //����
	BlackWhiteList_InvalidParam,//������Ϣ��ʽ����
	BlackWhiteList_PlateLengthError,//���ƺ����ַ������Ȳ���
	BlackWhiteList_PlateInvalidCharError,//���ƺ��������Ч�ַ�
	BlackWhiteList_StartTimeLengthError,//��ʼʱ���ַ������Ȳ���
	BlackWhiteList_StartTimeInvalidCharError,//��ʼʱ���ַ���������Ч�ַ�
	BlackWhiteList_StartTimeYearError,  //��ʼʱ����ݲ���
	BlackWhiteList_StartTimeMonthError, //��ʼʱ���·ݲ���
	BlackWhiteList_StartTimeDayError,   //��ʼʱ�����ڲ���
	BlackWhiteList_StartTimeHourError,  //��ʼʱ��Сʱ����
	BlackWhiteList_StartTimeMinuteError,//��ʼʱ����Ӳ���
	BlackWhiteList_StartTimeSecondError,//��ʼʱ����������
	BlackWhiteList_EndTimeLengthError,  //����ʱ���ַ������Ȳ���
	BlackWhiteList_EndTimeInvalidCharError,//����ʱ���ַ���������Ч�ַ�
	BlackWhiteList_EndTimeYearError,    //����ʱ����ݲ���
	BlackWhiteList_EndTimeMonthError,	//����ʱ���·ݲ���
	BlackWhiteList_EndTimeDayError,		//����ʱ�����ڲ���
	BlackWhiteList_EndTimeHourError,	//����ʱ��Сʱ����
	BlackWhiteList_EndTimeMinuteError,	//����ʱ����Ӳ���
	BlackWhiteList_EndTimeSecondError,  //����ʱ����������
	BlackWhiteList_StartTimeHourBigEndTime,//��ʼʱ����ڽ���ʱ��
	BlackWhiteList_FormatError,//��ʽ����ȷ
	BlackWhiteList_AccoundFormatError,//�˺Ű����������ַ�
	BlackWhiteList_AccoundValueTooBig,//�˺�ֵ̫��
	BlackWhiteList_TotalNumFormatError,//�ܳ�λ�������������ַ�
	BlackWhiteList_TotalNumValueTooBig,//�ܳ�λ��ֵ���ܴ���255
	BlackWhiteList_IdleNumFormatError,//ʣ�೵λ�������������ַ�
	BlackWhiteList_IdleNumValueBigTotalNum,//ʣ�೵λ�����ܴ����ܳ�λ��
	BlackWhiteList_IdleNumValueTooBig,//ʣ�೵λ��ֵ���ܴ���255
	BlackWhiteList_SectionLengthError,//24Сʱʱ�θ�ʽ���ȱ���Ϊ4
	BlackWhiteList_SectionFormatError,//24Сʱʱ�θ�ʽֻ�ܰ����ַ�0-9,A-F
	BlackWhiteList_UTF8TransToUnicodeFormatError,//UTF8תUnicode����
	BlackWhiteList_UnicodeTransToGBKFormatError,//UTF8תUnicode����
}E_BlackWhiteListErrorCode;

typedef enum
{
	LOOP_IO_ID = 0, /* ��ȦIO Id*/
	IO_INDEX_MAX,
}E_IOAppIndex;

typedef struct
{
	unsigned char	ucIndex; /* E_IOAppIndex*/
	unsigned char	ucLState; /* 0 �½�������  1 ����������*/
	unsigned char	aucReserved[2];
}T_IOStateRsp;


typedef enum
{
	DEV_STATE_LED = 103, //״̬��
	NET_STATE_LED = 92, //�����
	VEH_CHECK_IN1 = 111, // ����������1
	VEH_CHECK_IN2 = 104, // ����������2
	VEH_CHECK_IN3 = 112, // ����������3
	RELAY_OUT1 = 94, // �̵������1
	RELAY_OUT2 = 95, // �̵������2
	RELAY_OUT3 = 118, // �̵������3
	PARKING_SPACE_LED1_R = 33, // ��λ���LED1-R
	PARKING_SPACE_LED1_G = 32, // ��λ���LED1-G
	PARKING_SPACE_LED1_B = 11, // ��λ���LED1-B

	PARKING_SPACE_LED2_R = 13, // ��λ���LED2-R
	PARKING_SPACE_LED2_G = 10, // ��λ���LED2-G
	PARKING_SPACE_LED2_B = 12, // ��λ���LED2-B

	PARKING_SPACE_LED3_R = 14, // ��λ���LED3-R
	PARKING_SPACE_LED3_G = 15, // ��λ���LED3-G
	PARKING_SPACE_LED3_B = 9, // ��λ���LED3-B
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
	char	acPlate[16];	 /* ���ƺ��룬GB2312���� */
	char	acEntryTime[18]; /* �볡ʱ��*/
	char	acExitTime[18]; /* ����ʱ��*/
	unsigned int	uiRequired;  /* Ӧ����0.1ԪΪ��λ*/
	unsigned int	uiPrepaid;  	/* �Ѹ���0.1ԪΪ��λ*/
	unsigned char 	ucVehState;   /*E_VehState*/
	unsigned char	ucVehType;  /* ��������1С��2�� */
	unsigned char	ucUserType;  /*��Ա����E_MemberType*/
	unsigned char	ucPlateColor; /*������ɫ����Ϊ0����ʾ��ЧE_PlateColor*/
}T_OfflineVehInfoTest;

typedef struct
{
	unsigned char enable;//0 �ر�  1 ���������Խ�  2 ������Ƶ   3 �����ɼ�
	unsigned char pressstatus;//0 δ����    1 �а���
	unsigned char Reserverd[6];
}T_AudioTalkBack;

typedef struct
{
	unsigned char inVol;//����������С 0-100
	unsigned char outVol;//���������С 0-100
	unsigned char intype;//0 ʰ����  1 ��˷�
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

/*������ṹ�嶨��*/
typedef struct 
{
	char   strSpecialCode[20][12]; 
}T_SpecialCode;


/*ͼƬ��Ϣ�ṹ�嶨��*/
typedef struct 
{
	unsigned short 	usWidth;   /*ͼƬ�Ŀ�ȣ���λ:����*/
	unsigned short	usHeight;  /*ͼƬ�ĸ߶ȣ���λ:����*/

	T_Point		 atPlateRegion[4];    /*����ʶ��������ʱ�뷽��4����*/
	unsigned short	usPlateBox[4];    /*����λ�ã����Ͻ�(0, 1), ���½�(2,3)*/
	unsigned short	usVehicleBox[4];  /*����λ�ã����Ͻ�(0, 1), ���½�(2,3)*/

	char	strVehicleBrand[128]; /*����*/
	char	strConfidence[12];    /*���Ϳ��Ŷ�*/

	T_SpecialCode   tSpecialCode;/*������*/

	int hasCar;				//�Ƿ��г�

	unsigned char   ucReserved[256];  /*�����ֶ�*/ 

}T_SpecialCodeImageInfo;

/*α����ͼƬ��Ϣ�ṹ�嶨��*/
typedef struct 
{
	unsigned short 	usWidth;   /*ͼƬ�Ŀ�ȣ���λ:����*/
	unsigned short	usHeight;  /*ͼƬ�ĸ߶ȣ���λ:����*/

	unsigned short	usPlateBox[4];  /*����λ�ã����Ͻ�(0, 1), ���½�(2,3)*/
	unsigned short	usVehicleBox[4];  /*����λ�ã����Ͻ�(0, 1), ���½�(2,3)*/

	char strVehicleSubBrand[128];	/*α����*/
	char strConfidence[12];         /*α���ƿ��Ŷ�*/

	unsigned char   ucReserved[256];  /*�����ֶ�*/ 

}T_PlateClassfyImageInfo;

//////////////////////////////////////////////////////////////////////////

/**********************************************************************
* �������ƣ�Net_EnableLog
* ������������־���ܿ���,Ĭ�Ͽ�����־
* ���������iEnable 0:�ر���־,1:������־
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_EnableLog(int iEnable);

NET_API E_ReturnCode _stdcall Net_Log(char *strLog, ...);

NET_API E_ReturnCode _stdcall Net_SetLogSize(int iSize);

/**********************************************************************
* �������ƣ�Net_FindDevice
* �����������������������������IP��ͨ��ע��ص�������ȡ���������Ϣ,ϵͳ��Ҫ��װ��WinPcapץ������
* �����������
* �����������
* �� �� ֵ��״̬��  
***********************************************************************/
typedef void (CALLBACK *NET_FIND_DEVICE_CALLBACK)(T_RcvMsg *ptFindDevice, void *pUserData);
NET_API E_ReturnCode _stdcall Net_FindDevice(NET_FIND_DEVICE_CALLBACK func, void *pUserData);

NET_API E_ReturnCode _stdcall Net_FindDeviceEx(NET_FIND_DEVICE_CALLBACK func, void *pUserData);

/**********************************************************************
* �������ƣ�Net_FindDeviceMac
* �����������������������������Mac��ͨ��ע��ص�������ȡ�������Mac��Ϣ,ϵͳ��Ҫ��װ��WinPcapץ������
* �����������
* �����������
* �� �� ֵ��״̬��  
***********************************************************************/
typedef void (CALLBACK *NET_FIND_DEVICE_MAC_CALLBACK)(const char *strFindDeviceMac, void *pUserData);
NET_API E_ReturnCode _stdcall Net_FindDeviceMac(NET_FIND_DEVICE_MAC_CALLBACK func, void *pUserData);

/**********************************************************************
* �������ƣ�Net_FindDeviceIp
* �����������������������������Ip��ͨ��ע��ص�������ȡ�������Ip��Ϣ,ϵͳ��Ҫ��װ��WinPcapץ������
* �����������
* �����������
* �� �� ֵ��״̬��  
***********************************************************************/
typedef void (CALLBACK *NET_FIND_DEVICE_IP_CALLBACK)(const char *strFindDeviceIp, void *pUserData);
NET_API E_ReturnCode _stdcall Net_FindDeviceIp(NET_FIND_DEVICE_IP_CALLBACK func, void *pUserData);

/**********************************************************************
* �������ƣ�Net_ModifyDeviceIpByMac
* �����������������Mac�޸�Ip,��������
* �����������
* �����������
* �� �� ֵ��״̬��  
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ModifyDeviceIpByMac(const char *strMac, const char *strIp, const char *strMaskAddress);

/**********************************************************************
* �������ƣ�Net_Init
* ����������sdk���ʼ������ʼ�����������Դ
* �����������
* �����������
* �� �� ֵ��״̬��  
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_Init(void);

/**********************************************************************
* �������ƣ�Net_UNinit
* ����������sdk�ⷴ��ʼ�����Ͽ�������ӣ��ͷ����������Դ
* �����������
* �����������
* �� �� ֵ����  
***********************************************************************/
NET_API void _stdcall Net_UNinit(void);

/**********************************************************************
* �������ƣ�Net_AddCamera
* �������������������������������
* ������������IP,"***.***.***.***"
* �����������
* �� �� ֵ��������,-1Ϊ��Ч���
***********************************************************************/
NET_API DCHANDLE _stdcall Net_AddCamera(char *ptIp);

/**********************************************************************
* �������ƣ�Net_AddAssCamera
* ������������Ӹ�������������������
* ���������ptIp ���IP,"***.***.***.***"
			nAssDevFlag ������豸��־
* �����������
* �� �� ֵ��������,-1Ϊ��Ч���
***********************************************************************/
NET_API DCHANDLE _stdcall Net_AddAssCamera(char *ptIp, int nAssDevFlag);

/**********************************************************************
* �������ƣ�Net_DelCamera
* �����������Ͽ������֮������ӣ��ͷ����������
* ��������� ������
* ��������� ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_DelCamera(DCHANDLE tHandle);

/**********************************************************************
* �������ƣ�Net_ConnCamera
* ������������������������������ͼƬ���գ���һ�����ӳɹ���SDK�ڲ������Դ������������ƣ�����ʱ��᲻������
* ���������tHandle ������
*           usPort  �������˿ڣ�Ϊ0ʱ��ʹ��Ĭ�϶˿�30000
* 			usTimeout �����ʱʱ������λΪ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ConnCamera(DCHANDLE tHandle,  unsigned short usPort,  unsigned short usTimeout);


NET_API E_ReturnCode _stdcall Net_ConnCamera2(DCHANDLE tHandle,  unsigned short usPort,  unsigned short usTimeout);
/**********************************************************************
* �������ƣ�Net_ConnCameraEx
* ����������Net_ConnCamera��������չ����������������������ͼƬ����,��Ҫ�����û��������룬��һ�����ӳɹ���SDK�ڲ������Դ������������ƣ�����ʱ��᲻������
* ���������tHandle ������
*           usPort  �������˿ڣ�Ϊ0ʱ��ʹ��Ĭ�϶˿�30000
* 			usTimeout �����ʱʱ������λΪ��
*			pUserName	�û���
*			pPassWord	����
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ConnCameraEx(DCHANDLE tHandle,  unsigned short usPort,  unsigned short usTimeout,unsigned char *pUserName,unsigned char *pPassWord);

NET_API E_ReturnCode _stdcall Net_ConnCameraEtcp(DCHANDLE tHandle,  unsigned short usPort, unsigned short usTimeout, unsigned char *pUserName,unsigned char *pPassWord, int ucDetectMode);
/**********************************************************************
* �������ƣ�Net_DisConnCamera
* �����������Ͽ������֮���������·���ͷ�ͼƬ������Դ
* ���������������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_DisConnCamera(DCHANDLE tHandle);

/*********************************************************************
* �������ƣ�Net_StartVideo
* ������������ʼ������Ƶ������������Ƶˢ�����ھ����
* ���������tHandle ��������
*				   niStreamType ������0��ʾ��������1��ʾ������
*			hWnd ���ھ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_StartVideo(DCHANDLE tHandle, int niStreamType, HWND hWnd);

/**********************************************************************
* �������ƣ�Net_SetRealDataCallBack
* ����������ע���������պ�����ͨ��ע��ص���������ȡʵʱ��Ƶ֡
* ���������tHandle ������
*			pRealDataCallBack �ص�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
typedef void (CALLBACK *NET_REALDATACALLBACK) (DCHANDLE tHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser);
NET_API E_ReturnCode _stdcall Net_SetRealDataCallBack(DCHANDLE tHandle, NET_REALDATACALLBACK pRealDataCallBack);

/**********************************************************************
* �������ƣ�Net_SetRealDataCallBackEx
* ����������ע���������պ�����ͨ��ע��ص���������ȡʵʱ��Ƶ֡��Net_SetRealDataCallBack��������չ�������˻ص�����������
* ���������tHandle ������
*			pRealDataCallBack �ص�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
typedef void (CALLBACK *NET_REALDATACALLBACKEx) (DCHANDLE tHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize,T_FrameInfo *pTframeInfo, void* pUserData);
NET_API E_ReturnCode _stdcall Net_SetRealDataCallBackEx(DCHANDLE tHandle, NET_REALDATACALLBACKEx pRealDataCallBack,void *pUserData);

/**********************************************************************
* �������ƣ�Net_AddPlayWindow
* ������������Ӳ�����Ƶ�Ĵ��ھ��
* ���������tHandle ������
*			hWnd	���ھ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_AddPlayWindow(DCHANDLE tHandle, HWND hWnd);

/**********************************************************************
* �������ƣ�Net_DelPlayWindow
* ����������ɾ��������Ƶ�Ĵ��ھ��
* ���������tHandle ������
*			hWnd	���ھ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_DelPlayWindow(DCHANDLE tHandle, HWND hWnd);

/**********************************************************************
* �������ƣ�Net_SaveBmpFile
* �������������浱ǰ֡Ϊλͼ�ļ�
* ���������tHandle ������
*           strBmpFile λͼ�ļ���
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SaveBmpFile(DCHANDLE tHandle, const char * strBmpFile);

/**********************************************************************
* �������ƣ�Net_SaveJpgFile
* �������������浱ǰ֡ΪJpg�ļ�
* ���������tHandle ������
*           strJpgFile λͼ�ļ���
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SaveJpgFile(DCHANDLE tHandle, const char * strJpgFile);

/**********************************************************************
* �������ƣ�Net_GetJpgBuffer
* ������������ȡ��ǰ֡��Jpg����
* ���������tHandle ������
*           ucJpgBuffer Jpg����ָ��, �ڴ��ɺ����ڲ�����
* ���������lSize Jpg�����С
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_GetJpgBuffer(DCHANDLE tHandle, unsigned char ** ucJpgBuffer, unsigned long * ulSize);

NET_API E_ReturnCode _stdcall Net_GetJpgBufferEx(DCHANDLE tHandle, unsigned char ** ucJpgBuffer, unsigned long * ulSize);

NET_API E_ReturnCode _stdcall Net_GetFrameData(DCHANDLE tHandle, unsigned char** data ,int *width, int *height);

/**********************************************************************
* �������ƣ�Net_FreeBuffer
* �����������ͷŻ���
* ���������ucBuffer ���ͷŻ���ָ��(Net_GetJpgBuffer, Net_GetJpgBufferEx������ڴ�)
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_FreeBuffer(void* pBuffer);

/**********************************************************************
* �������ƣ�Net_StartRecord
* ������������ʼ¼��
* ���������tHandle ������
*			strFile: ¼���ļ���
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_StartRecord(DCHANDLE tHandle, const char * strFile);

NET_API E_ReturnCode _stdcall Net_StartRecordEx(DCHANDLE tHandle, const char * strFile, int nSectionTime);

/**********************************************************************
* �������ƣ�Net_StopRecord
* ����������ֹͣ¼��
* ���������tHandle ������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_StopRecord(DCHANDLE tHandle);

/**********************************************************************
* �������ƣ�Net_SetDrawFunCallBack
* ����������ע��ͼ����������������Ƶ�ϻ���
* ���������tHandle ������
*			pDrawFun �ص�����ָ��
*			lpDrawFunData �ص�����������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
typedef void (CALLBACK *NET_DRAWFUNCALLBACK)(DCHANDLE tHandle,HDC hdc, int width, int height, void* pUser);
NET_API E_ReturnCode _stdcall Net_SetDrawFunCallBack(DCHANDLE tHandle, NET_DRAWFUNCALLBACK pDrawFun, void * lpDrawFunData);

/**********************************************************************
* �������ƣ�Net_SetDrawFunCallBack
* ����������ע��ͼ�����ݵ����ص�
* ���������tHandle ������
*			pDataOut �ص�����ָ��
*			pUser �ص�����������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
typedef void (CALLBACK *NET_DrawDataOut)(DCHANDLE tHandle, void * hdd, void * bmi, unsigned char* data, int width, int height, void* pUser);
NET_API E_ReturnCode _stdcall Net_SetDrawDataOut(DCHANDLE tHandle, NET_DrawDataOut pDrawDataOut, void * pUser);

/**********************************************************************
* �������ƣ�Net_ShowNetSignal
* ��������������Ƶ������ʾ�����ź�ǿ��
* ���������tHandle ������
*			niShowMode ��ʾģʽ,0:����ʾ,1:��ʾ
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ShowNetSignal(DCHANDLE tHandle, int niShowMode);

/**********************************************************************
* �������ƣ�Net_ShowPlateRegion
* ��������������Ƶ������ʾ����ʶ����
* ���������tHandle ������
*			niShowMode ��ʾģʽ,0:����ʾ,1:��ʾ
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ShowPlateRegion(DCHANDLE tHandle, int niShowMode);

/**********************************************************************
* �������ƣ�Net_UpdatePlateRegion
* ����������������Ƶ���泵��ʶ����
* ���������tHandle ������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_UpdatePlateRegion(DCHANDLE tHandle);

/**********************************************************************
* �������ƣ�Net_StopVideo
* ����������ֹͣ������Ƶ����
* ���������tHandle ������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_StopVideo(DCHANDLE tHandle);

/**********************************************************************
* �������ƣ�Net_QueryVideoState
* ������������ѯ��������״̬
* ���������tHandle ������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryVideoState(DCHANDLE tHandle);

/**********************************************************************
* �������ƣ�Net_QueryConnState
* ������������ѯ�������״̬
* ���������tHandle ������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryConnState(DCHANDLE tHandle);

/**********************************************************************
* �������ƣ�Net_ImageSnap
* ����������ͼƬץ�ģ��·�ͼƬץ�����ͨ��Net_RegImageRecvExע��ص���������ͼƬ��Ϣ
* ���������tHandle ������
*			ptImageSnap  ͼƬץ�Ĳ�������ȫ����0
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ImageSnap(DCHANDLE tHandle, T_DCImageSnap *ptImageSnap);

/**********************************************************************
* �������ƣ�Net_ParkingInfo
* �����������·���λ��ͣ����Ϣ�ϱ���ͨ��Net_RegReportMessExע��ص���������ͼƬ��Ϣ
* ���������tHandle ������
*			ptRspParkingInfo  ��λ��ͣ����Ϣ��������ȫ����0
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ParkingInfo(DCHANDLE tHandle, T_RspParkingInfo *ptRspParkingInfo);

/**********************************************************************
* �������ƣ�Net_GetImage
* ������������ȡͼƬ��Ϣ�����ʹ�øú�������Ҫ����Net_SetSnapMode��ץ��ģʽ����Ϊ����ģʽ
* ���������tHandle ������
*			uiImageId ͼƬID
*			ptImageInfo ����ʶ����ָ��
*			ptPicInfo   ͼƬ������ָ�뼰��С
* ���������ptImageInfo  ͼƬ�г�����Ϣ
*			ptPicInfo  ͼƬ���ݼ�ͼƬ��С
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_GetImage(DCHANDLE tHandle, unsigned int  uiImageId, T_ImageUserInfo *ptImageInfo, T_PicInfo *ptPicInfo);

/**********************************************************************
* �������ƣ�Net_GateSetup
* ����������բ������
* ���������tHandle ������
*           ptControlGate բ�����Ʋ���ָ�룬1��բ��2��բ��3ͣբ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_GateSetup(DCHANDLE tHandle,  T_ControlGate *ptControlGate);

/**********************************************************************
* �������ƣ�Net_GetSdkVersion
* ������������ȡsdk�汾��Ϣ
* ���������szVersion �汾������
*		    ptLen   ��������С
* ���������szVersion sdk�汾��Ϣ
*           ptLen   �汾��ʵ����
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_GetSdkVersion(unsigned char *szVersion, unsigned int *ptLen);

#ifndef _E_SnapMode_
#define _E_SnapMode_
typedef enum
{
	SNAP_MODE_TOUCH = 0, /*����ץ��*/
	SNAP_MODE_PERSIST,   /*����ץ��*/
	SNAP_MODE_ALL,
}E_SnapMode;
#endif

/**********************************************************************
* �������ƣ�Net_SetSnapMode
* �����������������ץ��ģʽ
* ���������tHandle	������
			niSnapMode ���ץ��ģʽ����E_SnapMode��ͨ���ص�������ȡͼƬΪ����ץ��ģʽ��ͨ��Net_GetImage��ȡͼƬ��Ϣ��Ϊ����ץ��ģʽ
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SetSnapMode(DCHANDLE tHandle, int niSnapMode);

/**********************************************************************
* �������ƣ�Net_RegImageRecv
* ����������ͨ��ע��ص���������ȡ�ϱ���ͼƬ��Ϣ��ʶ����
			ֻ����SDK��ʼ���ɹ���ע��һ�λص�����,���ע�������һ��ע��Ļص�����Ϊ׼
			�Ƽ�ʹ��Net_RegImageRecvEx
* ���������fCb �ص�����
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
typedef int (CALLBACK *FGetImageCB)(DCHANDLE tHandle, unsigned int  uiImageId, T_ImageUserInfo *ptImageInfo, T_PicInfo *ptPicInfo);
NET_API E_ReturnCode _stdcall Net_RegImageRecv(FGetImageCB fCb);

/**********************************************************************
* �������ƣ�Net_RegImageRecv2
* ����������ͨ��ע��ص���������ȡ�ϱ���ͼƬ��Ϣ��ʶ�����������������Ϣ�����Net_RegImageRecv�ϱ����ݸ��ḻ
			ֻ����SDK��ʼ���ɹ���ע��һ�λص�����,���ע�������һ��ע��Ļص�����Ϊ׼
* ���������fCb �ص�����
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
typedef int (CALLBACK *FGetImageCB2)(DCHANDLE tHandle, unsigned int  uiImageId, T_ImageUserInfo2 *ptImageInfo, T_PicInfo *ptPicInfo);
NET_API E_ReturnCode _stdcall Net_RegImageRecv2(FGetImageCB2 fCb);

/**********************************************************************
* �������ƣ�Net_RegImageRecvEx
* ����������ͨ��ע��ص���������ȡ�ϱ���ͼƬ��ʵʱʶ����ͨ���ûص�������Net_RegImageRecv����չ���������ӻص�������������
			ÿ����һ�����ӱ���ע��һ�η����ϱ�,ͬ�����Ӷ��ע�������һ��ע��Ļص�����Ϊ׼
* ���������tHandle ������
*			fCb �ص�����
			{
				tHandle ������
				uiImageId �ϴ���ʶ���������ͣ�0Ϊʵʱʶ������
				ptImageInfo ָ��ʶ������ָ��
				ptPicInfo ʶ����ͼƬ�Ļ�����������ͼƬ�������ָ��Ϊ��
				pUser	�ص�����������
			}
			pUser �ص�����������

* �����������
* �� �� ֵ��״̬��
***********************************************************************/
typedef int (CALLBACK *FGetImageCbEx)(DCHANDLE tHandle,unsigned int  uiImageId, T_ImageUserInfo *ptImageInfo, T_PicInfo *ptPicInfo,void *pUser);
NET_API E_ReturnCode _stdcall Net_RegImageRecvEx(DCHANDLE tHandle, FGetImageCbEx fCb,void *pUser);

typedef int (CALLBACK *FGetImageCbEx2)(DCHANDLE tHandle,unsigned int  uiImageId, T_ImageUserInfo2 *ptImageInfo, T_PicInfo *ptPicInfo,void *pUser);
NET_API E_ReturnCode _stdcall Net_RegImageRecvEx2(DCHANDLE tHandle, FGetImageCbEx2 fCb,void *pUser);

/**********************************************************************
* �������ƣ�MatchSpecialCode
* ����������������Ƚ�
* ���������ptSpecialCode1 ������ṹ��ָ��
*			ptSpecialCode2  ������ṹ��ָ��
* �����������  
* �� �� ֵ�����ط���[0,1]
***********************************************************************/
NET_API float _stdcall Net_MatchSpecialCode(T_SpecialCode * ptSpecialCode1, T_SpecialCode * ptSpecialCode2);

NET_API float _stdcall Net_MatchSpecialCode2(float fSpecialCode1[20], float fSpecialCode2[20]);

/**********************************************************************
* �������ƣ�Net_RegOffLineImageRecvEx
* ����������ͨ��ע��ص���������ȡ�ѻ���¼���ݣ��������ƣ����͵���Ϣ�����ú�����ע��ʱ��������ѻ���¼��������׵��ýӿ�
* ���������tHandle ������

			fCb �ص�����
			{
				tHandle ������
				uiImageId �ϴ���ʶ���������ͣ�1Ϊ�ѻ���¼����
				ptImageInfo ָ��ʶ������ָ��
				ptPicInfo ʶ����ͼƬ�Ļ�����������ͼƬ�������ָ��Ϊ��
				pUser	�ص�����������
			}

			pUserData �ص�����������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
typedef int (CALLBACK *FGetOffLineImageCBEx)(DCHANDLE tHandle, unsigned int  uiImageId,  T_ImageUserInfo *ptImageInfo,T_PicInfo *ptPicInfo,void *pUserData);
NET_API E_ReturnCode _stdcall Net_RegOffLineImageRecvEx(DCHANDLE tHandle,FGetOffLineImageCBEx fCb,void *pUserData);

/**********************************************************************
* �������ƣ�Net_RegOffLinePayRecord
* ����������ͨ��ע��ص���������ȡ��������ѻ��շѼ�¼��Ϣ�������������볡��Ϣ���շѽ���Ա���͵ȵ�
* ���������tHandle ������
			fCb �ص�����
			{
				tHandle ������
				ucType	�ص�������Ϣ���ͣ�Ŀǰ0Ϊ�ѻ��շѼ�¼��
				ptVehPayInfo ����ѻ��շѼ�¼��Ϣ�� 
				uiLen		ptVehPayInfo�ṹ���Ӧ�ĳ��ȣ�
				ptPicInfo	ʶ����ͼƬ�Ļ�����������ͼƬ�������ָ��Ϊ�գ�
				pUserData �ص����������ģ�
			}
			pUserData �ص�����������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
typedef int (CALLBACK *FGetOffLinePayRecordCB)(DCHANDLE tHandle, unsigned char  ucType, T_VehPayRsp  *ptVehPayInfo, unsigned int uiLen,T_PicInfo *ptPicInfo,void *pUserData);
NET_API E_ReturnCode _stdcall Net_RegOffLinePayRecord(DCHANDLE tHandle,FGetOffLinePayRecordCB fCb,void *pUserData);

/**********************************************************************
* �������ƣ�Net_GetPresentVehInfoAsCSV
* ������������CSV��ʽ���������ڳ���Ϣ��
* ���������tHandle ������
*			ptGetPresentVehInfo ����ڳ���Ϣ�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_GetPresentVehInfoAsCSV(DCHANDLE tHandle, T_GetPrensentVehInfo *ptGetPresentVehInfo);

/**********************************************************************
* �������ƣ�Net_SaveImageToJpeg
* ������������ȡ��ǰͼ�񣬱��浽ָ��·��
* ���������tHandle ������
*			ucPathNmme ����ͼ���·��
* ����������� 
* �� �� ֵ��״̬��
***********************************************************************/

NET_API E_ReturnCode _stdcall Net_SaveImageToJpeg(DCHANDLE tHandle,unsigned char *ucPathNmme);

/**********************************************************************
* �������ƣ�Net_RegReportMessEx
* ����������ͨ��ע��ص���������ȡ�ϱ���Ϣ��
* ���������tHandle ������
			fCb �ص�����
			{
				tHandle ������
				ucType  ��Ϣ���ͣ���E_ReportMess
				ptMessage ������Ϣ���Ͳ�ͬ����Ӧ�Ľṹ�岻ͬ��
				����±�	
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
				pUserData 	�ص�����������
			}
			pUserData �ص�����������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
typedef int (CALLBACK *FGetReportCBEx)(DCHANDLE tHandle,unsigned char ucType,void *ptMessage,void *pUserData);
NET_API E_ReturnCode _stdcall Net_RegReportMessEx(DCHANDLE tHandle, FGetReportCBEx fcb,void *pUserData);

/**********************************************************************
* �������ƣ�DCSetSynTimePeriod
* ��������������SDK�ڲ�ͬ��ʱ������
* �����������λ�룬��Ϊ0ʱ���������ڲ�ͬʱ
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SetSynTimePeriod(unsigned short usSecTime);

/**********************************************************************
* �������ƣ�Net_ParkNumSetup
* �������������ÿ���ͣ��λ
* ���������tHandle ������
			ptParkNum ����ͣ��λ����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ParkNumSetup(DCHANDLE tHandle, T_ParkNum *ptParkNum);

/**********************************************************************
* �������ƣ�Net_QueryParkNumSetup
* ������������ѯ����ͣ��λ
* ���������tHandle ������
			ptParkNum ����ͣ��λ����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryParkNumSetup(DCHANDLE tHandle, T_ParkNum *ptParkNum);

/**********************************************************************
* �������ƣ�Net_PayCountSetup
* �������������ýɷѽ��
* ���������tHandle ������
			ptPayCount �ɷѽ�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_PayCountSetup(DCHANDLE tHandle, T_PayCount *ptPayCount);

/**********************************************************************
* �������ƣ�Net_SendRS485Data
* ����������rs485����͸���ӿڣ���RS485�ӿ�͸������
* ���������tHandle ������
*			ptRS485Data ͸��RS485���ݲ���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SendRS485Data(DCHANDLE tHandle, T_RS485Data *ptRS485Data);

/**********************************************************************
* �������ƣ�Net_TransRS485Data
* ����������rs485����͸���ӿڣ���RS485�ӿ�͸������
* ���������tHandle ������
*			ucRs485Id RS485�ڵ�ID����0���
*			pRS485Data ָ��������ݵ�ָ��
*			ucDatalen �������ݵĳ��ȣ���󳤶�Ϊ256���ֽ�
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_TransRS485Data(DCHANDLE tHandle, unsigned char ucRs485Id,unsigned char  *pRS485Data,unsigned char ucDatalen);

/**********************************************************************
* �������ƣ�Net_TransRS485Data
* ����������rs485����͸���ӿڣ���RS485�ӿ�͸������
* ���������tHandle ������
*			ucRs485Id RS485�ڵ�ID����0���
*			pRS485Data ָ��������ݵ�ָ��
*			usDatalen �������ݵĳ��ȣ���󳤶�Ϊ1024���ֽ�
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_TransRS485DataEx(DCHANDLE tHandle, unsigned char ucRs485Id,unsigned char  *pRS485Data,unsigned short usDatalen);

/**********************************************************************
* �������ƣ�Net_TransRS485HexData
* ����������rs485����͸���ӿڣ���RS485�ӿ�͸��16��������,���ݸ�ʽ�ο���00 01 02 F1 F3 ...��,������Net_TransRS485HexDataEx
* ���������tHandle ������
*			ucRs485Id RS485�ڵ�ID����0���
*			pRS485Data ָ��������ݵ�16�����ַ���ָ��
*			ucDatalen ָ��������ݵ�16�����ַ�������,��󳤶�Ϊ256��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_TransRS485HexData(DCHANDLE tHandle, unsigned char ucRs485Id,unsigned char  *pRS485Data,unsigned char ucDatalen);

/**********************************************************************
* �������ƣ�Net_TransRS485HexDataEx
* ����������rs485����͸���ӿڣ���RS485�ӿ�͸��16��������,���ݸ�ʽ�ο���00 01 02 F1 F3 ...��, �� Net_TransRS485HexData������,�����ֽڳ�������
* ���������tHandle ������
*			ucRs485Id RS485�ڵ�ID����0���
*			pRS485Data ָ��������ݵ�16�����ַ���ָ��
*			ucDatalen ָ��������ݵ�16�����ַ�������,��󳤶�Ϊ3072��(�ڲ�һ����෢��1024��16�����ֽ�)
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_TransRS485HexDataEx(DCHANDLE tHandle, unsigned char ucRs485Id, unsigned char  *pRS485Data, unsigned int iDatalen);
/**********************************************************************
* �������ƣ�Net_ReadRS485Data
* ������������ȡRS485���������
* ���������tHandle ������
*			ptRS485Data ��ȡRS485���ݲ���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ReadRS485Data(DCHANDLE tHandle, T_RS485Data *ptRS485Data);

/**********************************************************************
* �������ƣ�Net_BlackWhiteListSetup
* ������������ѭ�����øú�������������Ϣ����ָ����ʽд�뵽�ļ����ٵ���Net_BlackWhiteListSend���ڰ��������뵽���
			�����ַ�����ΪGB2312����
* ���������ptLprResult ָ��洢��������Ϣ���ڴ�
*			ptBlackWhiteListCount ���δ���İ������ĸ�����д���������·��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_BlackWhiteListSetup(T_LprResult *ptLprResult,T_BlackWhiteListCount *ptBlackWhiteListCount);
/**********************************************************************
* �������ƣ�Net_BlackWhiteListSend
* ������������������ڰ�������������ַ��������ΪGB2312��ʽ�������ڶ��������������������������С��10��ʱ���������Net_SendBlackWhiteListByMess�����������������
			�����ַ�����ΪGB2312����
* ���������tHandle ������
*			ptBalckWhiteList ����ڰ���������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_BlackWhiteListSend(DCHANDLE tHandle, T_BlackWhiteList *ptBalckWhiteList);

/**********************************************************************
* �������ƣ�Net_BlackWhiteListSendEx
* ������������������ڰ�������������ַ��������ΪGB2312��ʽ�������ڶ��������������������������С��10��ʱ���������Net_SendBlackWhiteListByMessEx�����������������
			�����ַ�����ΪGB2312����
* ���������tHandle ������
*			ptBalckWhiteList ����ڰ���������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_BlackWhiteListSendEx(DCHANDLE tHandle, T_BlackWhiteList *ptBalckWhiteList);

/**********************************************************************
* �������ƣ�Net_BlackWhiteListSendReportMess
* ����������ͨ��ע��ص��������ϱ�����������в���ȷ�ĳ�����Ϣ�����Net_BlackWhiteListSendʹ��
* ���������tHandle ������
*			fCb �ص�����
			{
				iErrCode ������ �μ� E_BlackWhiteListErrorCode
				iLine >=0 ����ȷ���Ƶ�����
				pPlateInfoPlateInfo ָ�����ĳ�����Ϣ
				pUser	�ص�����������
			}
			pUser �ص�����������

* �����������
* �� �� ֵ��״̬��
***********************************************************************/
typedef int (CALLBACK *FBlackWhiteListSendReportMess)(int iErrCode, int iLine, const char *pPlateInfo, void *pUser);
NET_API E_ReturnCode _stdcall Net_BlackWhiteListSendReportMess(DCHANDLE tHandle, FBlackWhiteListSendReportMess fCb, void *pUser);

/**********************************************************************
* �������ƣ�Net_SendBlackWhiteListByMess
* ����������ͨ����Ϣ�����������뵽�����������1��10��������Ϣ�����������������������10��ʱ����ο���������ӿ�Net_BlackWhiteListSend;
			�����ַ�����ΪGB2312����
* ���������tHandle ������
			pSendLprByMess	ָ������䳵�Ƶ���Ϣ
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SendBlackWhiteListByMess(DCHANDLE tHandle,T_SendLprByMess *ptSendLprByMess);

/**********************************************************************
* �������ƣ�Net_DeleteAllBlackWhiteList
* ����������ɾ����������кڰ�����
* ���������tHandle ������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_DeleteAllBlackWhiteList(DCHANDLE tHandle);

/**********************************************************************
* �������ƣ�Net_ClearOfflineData
* ��������������ѻ�����
* ���������tHandle ������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ClearOfflineData(DCHANDLE tHandle);

/**********************************************************************
* �������ƣ�Net_QueryWhiteListByPlate
* ����������ͨ�����Ʋ�ѯ�������ڸó�����Ϣ�������ַ�����ΪGB2312����
* ���������tHandle ������
*			pPlateInfo ���ƺ���
			ptLprResult ָ���ѯ���ĳ�����Ϣ
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryWhiteListByPlate(DCHANDLE tHandle, const char *pPlateInfo,T_RspLprResult *ptLprResult);

/**********************************************************************
* �������ƣ�Net_GetBlackWhiteList
* ������������������ڰ�����
* ���������tHandle ������
*			ptBalckWhiteList ����ڰ���������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_GetBlackWhiteList(DCHANDLE tHandle, T_GetBlackWhiteList *ptGetBalckWhiteList);

/**********************************************************************
* �������ƣ�Net_GetBlackWhiteListAsCSV
* ������������CSV��ʽ��������ڰ�����
* ���������tHandle ������
*			ptBalckWhiteList ����ڰ���������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_GetBlackWhiteListAsCSV(DCHANDLE tHandle, T_GetBlackWhiteList *ptGetBalckWhiteList);

/**********************************************************************
* �������ƣ�Net_GetBlackWhiteListAsCSVEx
* ������������CSV��ʽ��������ڰ�����
* ���������tHandle ������
*			ptBalckWhiteList ����ڰ���������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_GetBlackWhiteListAsCSVEx(DCHANDLE tHandle, T_GetBlackWhiteList *ptGetBalckWhiteList);

/**********************************************************************
* �������ƣ�Net_SetControlCallBack
* ����������ͨ��ע��ûص���������ȡ�����ʵʱ����״̬,�������״̬��ö��E_ConnState
* ���������pControlCallBack �ص�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/

typedef void (CALLBACK *NET_CONTROLCALLBACK) (DCHANDLE tHandle,unsigned char ucCtrlConnState, void* pUser);
NET_API E_ReturnCode _stdcall Net_SetControlCallBack(NET_CONTROLCALLBACK pControlCallBack);

/**********************************************************************
* �������ƣ�Net_SetControlCallBackEx
* ����������ͨ��ע��ûص���������ȡ�����ʵʱ����״̬��Net_SetControlCallBack����չ���������ӻص����������ģ��������״̬��ö��E_ConnState
* ���������tHandle ������
*			pControlCallBack �ص�����ָ��
			pUser �ص�����������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/

typedef void (CALLBACK *NET_CONTROLCALLBACKEx) (DCHANDLE tHandle,unsigned char ucCtrlConnState, void* pUser);
NET_API E_ReturnCode _stdcall Net_SetControlCallBackEx(DCHANDLE tHandle,NET_CONTROLCALLBACKEx pControlCallBack, void* pUser);


/**********************************************************************
* �������ƣ�Net_SetWhiteListMode
* �������������ð���������ģʽ�����ѻ�ʹ�ܣ�ʹ�ܣ���ʹ������ģʽ
* ���������tHandle ������
*			ptWhiteListMode ������ģʽ����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetWhiteListMode(DCHANDLE tHandle, T_WhiteListMode *ptWhiteListMode);

/**********************************************************************
* �������ƣ�Net_QueryWhiteListMode
* ������������ѯ����������ģʽ
* ���������tHandle ������
*			ptWhiteListMode ������ģʽ����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryWhiteListMode(DCHANDLE tHandle,T_WhiteListMode *ptWhiteListMode);

/**********************************************************************
* �������ƣ�Net_ExportWhiteListTemplate
* ��������������������ģ��
* ���������szPath ����·��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ExportWhiteListTemplate(unsigned char *szPath);

/**********************************************************************
* �������ƣ�Net_LedSetup
* ��������������LED��ʾ������
* ���������tHandle ������
*			ptSLedSetup LED��ʾ���ݲ���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SLedSetup(DCHANDLE tHandle,T_SLedSetup *ptSLedSetup);

/**********************************************************************
* �������ƣ�Net_QueryLedSetup
* ������������ѯLED��ʾ������
* ���������tHandle ������
*			ptSLedSetup LED��ʾ���ݲ���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QuerySLedSetup(DCHANDLE tHandle,T_SLedSetup *ptSLedSetup);

/**********************************************************************
* �������ƣ�Net_SLedTfgSetup
* ��������������������չ����
* ���������tHandle ������
*			T_SLedSetup_tfg ������չ���ݲ���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SLedTfgSetup(DCHANDLE tHandle,T_SLedSetup_tfg *ptSLedSetup);

/**********************************************************************
* �������ƣ�Net_QuerySLedTfgSetup
* ������������ѯ������չ����
* ���������tHandle ������
*			T_SLedSetup_tfg ������չ���ݲ���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QuerySLedTfgSetup(DCHANDLE tHandle,T_SLedSetup_tfg *ptSLedSetup);

/**********************************************************************
* �������ƣ� Net_SLedSetupExt
* ��������������LED��ʾ����չ����
* ���������tHandle ������
*			ptSLedSetupExt LED��ʾ��չ���ݲ���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SLedSetupExt(DCHANDLE tHandle,T_SLedSetupExt *ptSLedSetupExt);

/**********************************************************************
* �������ƣ� Net_QuerySLedSetupExt
* ������������ѯLED��ʾ������
* ���������tHandle ������
*			ptSLedSetupExt LED��ʾ��չ���ݲ���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QuerySLedSetupExt(DCHANDLE tHandle,T_SLedSetupExt *ptSLedSetupExt);

/**********************************************************************
* �������ƣ�Net_LedSetup
* ��������������LED��ʾ������
* ���������tHandle ������
*			ptLedSetup LED��ʾ���ݲ���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_LedSetup(DCHANDLE tHandle,T_LedSetup *ptLedSetup);

/**********************************************************************
* �������ƣ�Net_QueryLedSetup
* ������������ѯLED��ʾ������
* ���������tHandle ������
*			ptLedSetup LED��ʾ���ݲ���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryLedSetup(DCHANDLE tHandle,T_LedSetup *ptLedSetup);

/**********************************************************************
* �������ƣ�Net_LedSetupEx
* ��������������LED��ʾ������
* ���������tHandle ������
*			ptLedSetup LED��ʾ���ݲ���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_LedSetupEx(DCHANDLE tHandle,T_LedSetup *ptLedSetup);

/**********************************************************************
* �������ƣ�Net_QueryLedSetupEx
* ������������ѯLED��ʾ������
* ���������tHandle ������
*			ptLedSetup LED��ʾ���ݲ���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryLedSetupEx(DCHANDLE tHandle,T_LedSetup *ptLedSetup);

/**********************************************************************
* �������ƣ�Net_LedLzSetup
* ��������������LED��ʾ������
* ���������tHandle ������
*			ptLedLzSetup LED��ʾ���ݲ���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_LedLzSetup(DCHANDLE tHandle,T_LZ_LedSetup *ptLedLzSetup);

/**********************************************************************
* �������ƣ�Net_QueryLedLzSetup
* ������������ѯLED��ʾ������
* ���������tHandle ������
*			ptLedLzSetup LED��ʾ���ݲ���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryLedLzSetup(DCHANDLE tHandle,T_LZ_LedSetup *ptLedLzSetup);

/**********************************************************************
* �������ƣ�Net_LedDcSetup
* ��������������LED��ʾ������
* ���������tHandle ������
*			ptDCScreenSetup LED��ʾ���ݲ���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_LedDcSetup(DCHANDLE tHandle,T_DCScreenSetup *ptDCScreenSetup);

/**********************************************************************
* �������ƣ�Net_QueryLedDcSetup
* ������������ѯLED��ʾ������
* ���������tHandle ������
*			ptDCScreenSetup LED��ʾ���ݲ���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryLedDcSetup(DCHANDLE tHandle,T_DCScreenSetup *ptDCScreenSetup);

/**********************************************************************
* �������ƣ�Net_RegOffLineClient
* ����������������ǰ�ͻ���ע��Ϊ��ͤ�ˣ�������뵱ǰ�ͻ�������״̬��Ϊ����Ƿ��ѻ�������
* ���������tHandle ������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_RegOffLineClient(DCHANDLE tHandle);

/**********************************************************************
* �������ƣ�Net_ReadGPIOState
* ������������ȡָ���ӿڵ�GPIO״̬������ȡ����ĳ�����״̬
* ���������tHandle ������
			ucIndex  �ӿ�����ֵ����0��ʼ���
			pucValue  ָ�򷵻ص�״ֵ̬��ָ�룬0��1
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ReadGPIOState(DCHANDLE tHandle,unsigned char ucIndex,unsigned char *pucValue);

/**********************************************************************
* �������ƣ�Net_WriteGPIOSate
* ������������ָ���ӿڵ�GPIOд��ֵ������ָ���̵���д��״̬��0Ϊ��·��1Ϊ��·
* ���������tHandle ������
			ucIndex  �ӿ�����ֵ����0��ʼ���
			ucValue  д���״ֵ̬��0��1
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_WriteGPIOState(DCHANDLE tHandle,unsigned char ucIndex,unsigned char ucValue);

/**********************************************************************
* �������ƣ�Net_WriteTwoEncpyption
* ����������д���û�˽�����ݣ����ڶ��μ���
* ���������tHandle ������
			pUserData	�û�����
*			uiDataLen �û����ݵĳ���
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_WriteTwoEncpyption(DCHANDLE tHandle,unsigned char *pUserData,unsigned int uiDataLen);

/**********************************************************************
* �������ƣ�Net_ReadTwoEncpyption
* ���������������û�д���˽������
* ���������tHandle ������
*			pBuff ���ڴ�Ŷ������û�����
			uiSizeBuff  �û����ݻ������Ĵ�С,uiSizeBuff����>=256
* �����������
* �� �� ֵ������ֵΪʵ���û����ݵ��ֽ���������-1��ʾʧ��
***********************************************************************/ 
NET_API int _stdcall Net_ReadTwoEncpyption(DCHANDLE tHandle,  unsigned char *pBuff, unsigned int uiSizeBuff);

/**********************************************************************
* �������ƣ�Net_TwoEncpyptionSet
* �������������ö��μ��ܿ����ر�
* ���������tHandle ������
			ptTwoEncpyptionSet  ���μ������ýṹ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_TwoEncpyptionSet(DCHANDLE tHandle,  T_TwoEncpyptionSet *ptTwoEncpyptionSet);

/**********************************************************************
* �������ƣ�Net_TwoEncpyptionAuth
* �������������μ��ܼ�Ȩ
* ���������tHandle ������
			ptTwoEncpyptionAuth  ���μ��ܼ�Ȩ�ṹ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_TwoEncpyptionAuth(DCHANDLE tHandle,  T_TwoEncpyptionAuth *ptTwoEncpyptionAuth);

/**********************************************************************
* �������ƣ�Net_TwoEncpyptionModify
* �������������μ����޸�
* ���������tHandle ������
			ptTwoEncpyptionModify  ���μ����޸Ľṹ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_TwoEncpyptionModify(DCHANDLE tHandle,  T_TwoEncpyptionModify *ptTwoEncpyptionModify);

/**********************************************************************
* �������ƣ�Net_TwoEncpyptionQuery
* �������������μ��ܲ�ѯ�����ر�
* ���������tHandle ������
			ptTwoEncpyptionQuery  ���μ��ܿ����رսṹ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_TwoEncpyptionQuery(DCHANDLE tHandle,  T_TwoEncpyptionQuery *ptTwoEncpyptionQuery);

/**********************************************************************
* �������ƣ�Net_OffLinePayTest
* �����������ѻ��շѲ���
* ���������tHandle ������
*			ptOfflineVehInfoTest �ѻ��շѲ��Խṹ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_OffLinePayTest(DCHANDLE tHandle, T_OfflineVehInfoTest *ptOfflineVehInfoTest);

/**********************************************************************
* �������ƣ�Net_LensControl
* �������������ñ䱶���
* ���������tHandle ������
			ptLensControl ָ�����������Ľṹ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_LensControl(DCHANDLE tHandle,T_LensControl *ptLensControl);

/**********************************************************************
* �������ƣ�Net_AssLensControl
* �������������ñ䱶���
* ���������tHandle ������
			ptLensControl ָ�����������Ľṹ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_AssLensControl(DCHANDLE tHandle,T_LensControl *ptLensControl);

/**********************************************************************
* �������ƣ�Net_ParkLedLightSetup
* ��������������LED������
* ���������tHandle ������
			ptParkLedLightSetup  ָ��LED���������õ�ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ParkLedLightSetup(DCHANDLE tHandle,T_ParkLedLightSetup *ptParkLedLightSetup);

/**********************************************************************
* �������ƣ�Net_ParkLedLightSetup
* ������������ѯLED������
* ���������tHandle ������
			ptParkLedLightSetup  ָ��LED���������õ�ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryParkLedLightSetup(DCHANDLE tHandle,T_ParkLedLightSetup *ptParkLedLightSetup);

/**********************************************************************
* �������ƣ�Net_ChangeUserPassword
* ���������������û���������
* ���������tHandle ������
			ptUserAccount  ָ���û������������õ�ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ModifyUserPassword(DCHANDLE tHandle,T_ModifyUserAccount *ptUserAccount);

/**********************************************************************
* �������ƣ�Net_ModifyUserPort
* ���������������û����Ӷ˿�
* ���������tHandle ������
			ptUserPort  ָ��˿ڵ�ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ModifyUserPort(DCHANDLE tHandle,T_UserPort *ptUserPort);

/**********************************************************************
* �������ƣ�Net_SetWLFuzzyMatchMode
* �������������ð�����ģ��ƥ��ģʽ
* ���������tHandle ������
			ptWlFuzzyMatch  ָ��ģ��ƥ������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetWLFuzzyMatchMode(DCHANDLE tHandle,T_WLFuzzyMatch *ptWlFuzzyMatch);

/**********************************************************************
* �������ƣ�Net_QueryWLFuzzyMatchMode
* ������������ѯ������ģ��ƥ��ģʽ
* ���������tHandle ������
			ptWlFuzzyMatch  ָ��ģ��ƥ������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryWLFuzzyMatchMode(DCHANDLE tHandle,T_WLFuzzyMatch *ptWlFuzzyMatch);

/**********************************************************************
* �������ƣ�Net_ManulWiperOpen
* �����������ֶ�������ˢ
* ���������tHandle ������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ManulWiperOpen(DCHANDLE tHandle);

/**********************************************************************
* �������ƣ�Net_ManulWiperClose
* �����������ֶ��ر���ˢ
* ���������tHandle ������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ManulWiperClose(DCHANDLE tHandle);

/**********************************************************************
* �������ƣ�Net_SetOffLinePayMode
* ���������������ѻ��շ�ģʽ�����ѻ�ʹ�ܣ�ʹ�ܣ���ʹ��
* ���������tHandle ������
			ptOffLinePayMode  ָ���ѻ��շ�ģʽ��ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetOffLinePayMode(DCHANDLE tHandle,T_OffLinePayMode *ptOffLinePayMode);

/**********************************************************************
* �������ƣ�Net_QueryOffLinePayMode
* ������������ѯ�ѻ��շ�ģʽ
* ���������tHandle ������
			ptOffLinePayMode  ָ���ѻ��շ�ģʽ��ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryOffLinePayMode(DCHANDLE tHandle,T_OffLinePayMode *ptOffLinePayMode);

/**********************************************************************
* �������ƣ�Net_SetOffLinePayRule
* ���������������ѻ��շѹ���
* ���������tHandle ������
			ptOffLinePayRule  ָ���ѻ��շѹ����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetOffLinePayRule(DCHANDLE tHandle,T_PayRule *ptOffLinePayRule);

/**********************************************************************
* �������ƣ�Net_QueryOffLinePayRule
* ������������ѯ�ѻ��շѹ���
* ���������tHandle ������
			ptOffLinePayRule  ָ���ѻ��շѹ����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryOffLinePayRule(DCHANDLE tHandle,T_PayRule *ptOffLinePayRule);

/**********************************************************************
* �������ƣ�Net_SetGateAutoOpen
* �������������ó��������Զ�̧բ����
* ���������tHandle ������
			ptAutoControlGate  ָ����������Զ�̧բ�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetGateAutoOpen(DCHANDLE tHandle,T_AutoControlGate *ptAutoControlGate);

/**********************************************************************
* �������ƣ�Net_QueryGateAutoOpen
* ������������ѯ���������Զ�̧բ����
* ���������tHandle ������
			ptAutoControlGate  ָ����������Զ�̧բ�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryGateAutoOpen(DCHANDLE tHandle,T_AutoControlGate *ptAutoControlGate);

/**********************************************************************
* �������ƣ�Net_SyncConfigByMulticast
* ����������ͨ���鲥ͬ��������õ��������
* ���������tHandle ������
			ptSyncConfigByMuticast  ָ��ͬ��������ù����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SyncConfigByMulticast(DCHANDLE tHandle,T_SyncConfigByMuticast *ptSyncConfigByMuticast);

/**********************************************************************
* �������ƣ�Net_SetVideoRotate
* ����������������Ƶ��ת
* ���������tHandle ������
			ptVideoRotate  ָ����Ƶ��ת��ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetVideoRotate(DCHANDLE tHandle,T_VideoRotate *ptVideoRotate);

/**********************************************************************
* �������ƣ�Net_QueryVideoRotate
* ������������ѯ��Ƶ��ת
* ���������tHandle ������
			ptVideoRotate  ָ����Ƶ��ת��ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryVideoRotate(DCHANDLE tHandle,T_VideoRotate *ptVideoRotate);

/**********************************************************************
* �������ƣ�Net_SetAudioVol
* ����������������������
* ���������tHandle ������
			ptAudioVol  ָ������������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetAudioVol(DCHANDLE tHandle,T_AudioVol *ptAudioVol);

/**********************************************************************
* �������ƣ�Net_QueryAudioVol
* ������������ѯ��������
* ���������tHandle ������
			ptAudioVol  ָ������������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryAudioVol(DCHANDLE tHandle,T_AudioVol *ptAudioVol);

/**********************************************************************
* �������ƣ�Net_AudioTalkBack
* ���������������Խ�����
* ���������tHandle ������
			ptAudioTalkBack  ָ�������Խ���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_AudioTalkBack(DCHANDLE tHandle, T_AudioTalkBack *ptAudioTalkBack);

/**********************************************************************
* �������ƣ�Net_StartTalk
* �������������������Խ�
* ���������tHandle ������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_StartTalk(DCHANDLE tHandle);

/**********************************************************************
* �������ƣ�Net_StopTalk
* �����������ر������Խ�
* ���������tHandle ������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_StopTalk(DCHANDLE tHandle);

NET_API E_ReturnCode _stdcall Net_StartRecordCameraVoice(char * strFilePath);
NET_API E_ReturnCode _stdcall Net_StopRecordCameraVoice();
NET_API E_ReturnCode _stdcall Net_StartRecordPcVoice(char * strFilePath);
NET_API E_ReturnCode _stdcall Net_StopRecordPcVoice();

/**********************************************************************
* �������ƣ�Net_ImportBlackWhiteList
* ������������������ڰ�����
* ���������tHandle ������
*			ptBalckWhiteList ����ڰ���������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ImportBlackWhiteList(DCHANDLE tHandle, T_BlackWhiteList *ptBalckWhiteList);

NET_API E_ReturnCode _stdcall Net_ImportBlackWhiteListEx(DCHANDLE tHandle, T_BlackWhiteList *ptBalckWhiteList);

NET_API E_ReturnCode _stdcall Net_ImportBlackWhiteListCy(DCHANDLE tHandle, T_BlackWhiteList *ptBalckWhiteList);

/**********************************************************************
* �������ƣ�Net_ExportBlackWhiteList
* ������������������ڰ�����
* ���������tHandle ������
*			ptGetBalckWhiteList ����ڰ���������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ExportBlackWhiteList(DCHANDLE tHandle, T_GetBlackWhiteList *ptGetBalckWhiteList);

NET_API E_ReturnCode _stdcall Net_ExportBlackWhiteListAsCSV(DCHANDLE tHandle, T_GetBlackWhiteList *ptGetBalckWhiteList);

NET_API E_ReturnCode _stdcall Net_ExportBlackWhiteListCyAsCSV(DCHANDLE tHandle, T_GetBlackWhiteList *ptGetBalckWhiteList);


/**********************************************************************
* �������ƣ�Net_ImportRePlate
* �������������복�ƺ������
* ���������tHandle ������
*			strFile �ļ���
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ImportRePlate(DCHANDLE tHandle, const char * strFile);

/**********************************************************************
* �������ƣ�Net_ExportRePlate
* �����������������ƺ������
* ���������tHandle ������
*			strFile �ļ���
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ExportRePlate(DCHANDLE tHandle, const char * strFile);

#ifdef __cplusplus
}
#endif
#endif

