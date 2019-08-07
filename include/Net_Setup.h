/**************************************************************************
* ��    Ȩ�� 	Copyright (c) 2015 
* �ļ����ƣ�	Net_Setup.h
* �ļ���ʶ�� 
* ����ժҪ��    ��������翪��SDK,����������Ϣ
* ����˵���� 
* ��ǰ�汾��	V1.0
* ��    ��	
* ������ڣ�	2013��08��28��
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
 *                         ��������                                    *
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
#define  AVE_REG_NUM       8       //����������Ŀ

#define MAX_ASS_SEARCH		32
#define NET_MAX_MAC_LEN     32

/* ״̬�볣������*/
typedef enum
{
	DC_NO_ERROR			      = 0,   //����
	DC_HANDLE_INVALID		  = 1,   //��Ч�ľ��
	DC_CONN_FAIL			  = 2,   //����ʧ��
	DC_OBJ_BUSY				  = 3,   //����æ
	DC_OBJ_UNEXIST			  = 4,   //���󲻴���
	DC_CMD_INVALID			  = 5,   //������Ч
	DC_PARA_INVALID			  = 6,   //������Ч
	DC_REQ_TIMEOUT			  = 7,   //����ʱ
	DC_MEMORY_LACK 			  = 8,   //�ڴ�����ʧ��
	DC_SEND_FAIL 			  = 9,   //���ݷ���ʧ��
	DC_RECV_FAIL			  = 10,  //���ݽ���ʧ��
	DC_OPT_FAIL				  = 11,  //����ʧ��
	DC_NOT_CONN 			  = 12,  //û�д�������
	DC_BEYOND_MAX_CLIENT      = 13,  //������������������
	DC_CONNECT_AUTH           = 18,  //���Ӽ�Ȩ
	DC_USER_NOT_EXIST		  = 19,  //�û�������
	DC_PASSWD_ERROR			  = 20,  //�������
	DC_TF_NOT_EXIST			  = 21,  //TF��������
	DC_TF_IO_ERROR			  = 22,  //TF����д����
	DC_ENCPYPTION_ERR		  = 23,  //���μ�������У��ʧ��

	DC_UNDEFINED_ERROR		  = -1,

	//��¼���Ӵ�����
	DC_CONN_PORT_NEGO_FAIL	  = 1000, //���Ͷ˿�Э��ʧ��
	DC_CONN_RXQUE_CREATE_FAIL = 1001, //�������ն���ʧ��
	DC_CONN_TXQUE_CREATE_FAIL = 1002, //�������Ͷ���ʧ��
	DC_CONN_REQUE_CREATE_FAIL = 1003, //������Ϣ�ϱ�����ʧ��
	DC_CONN_30000_CONTROL_TSK_CREATE_FAIL = 1004, //����30000�����߳�ʧ��
	DC_CONN_40000_CONTROL_TSK_CREATE_FAIL = 1005, //����ͼƬ�ϱ��߳�ʧ��
	DC_CONN_SERVER_ERROR				  = 1006, //�������ڲ�����
	DC_CONN_RESPONSE_CODE_AUTHORITY_LIMIT = 1007, //Ȩ������

	//������������
	DC_WHITE_LIST_FILE_OPEN_FAIL = 1100, //�������ļ���ʧ��
	DC_WHITE_LIST_FILE_EMPTY = 1101, //�������ļ�Ϊ��
	DC_WHITE_LIST_FILE_MAPPING_FAIL = 1102, //�������ļ�ӳ��ʧ��
	DC_WHITE_LIST_FILE_MAPPING_OPEN_FAIL = 1103, //�������ļ���ӳ��ʧ��
	DC_WHITE_LIST_MEMORY_LACK_FAIL = 1104, //�������ڴ�����ʧ��
	DC_WHITE_LIST_FILE_SIZE_MORE = 1105, //�������ļ�����1M
	DC_WHITE_LIST_FORMAT_ERROR = 1106, //��������ʽ����ȷ
	DC_WHITE_LIST_CREATE_NEW_FILE_FAIL = 1107, //�����µİ�����ʧ��
	DC_WHITE_LIST_WRITE_NEW_FILE_FAIL = 1108, //д�������ļ�ʧ��
	DC_WHITE_LIST_WRITE_NEW_FILE_LENGTH_ERROR = 1109, //д���������Ȳ���
	DC_WHITE_LIST_MEMORY_LACK_FAIL_OLD = 1110, //�������ڴ�����ʧ��
	DC_WHITE_LIST_CREATE_THREAD_FAIL = 1111, //�����������߳�ʧ��
	DC_WHITE_LIST_PLATE_EMPTY = 1112, //���������ƺ�Ϊ��
	DC_WHITE_LIST_PLATE_LENGTH_ERROR = 1113, //���������Ƴ��ȴ���
	DC_WHITE_LIST_PLATE_SPECIAL_CHAR = 1114, //���������ư��������ַ�
	DC_WHITE_LIST_TIME_YEAR_ERROR = 1115, //������ʱ����ݲ���
	DC_WHITE_LIST_TIME_MONTH_ERROR = 1117, //������ʱ���·ݲ���
	DC_WHITE_LIST_TIME_BIG_MONTH_DAY_ERROR = 1118, //������ʱ��������ڲ���
	DC_WHITE_LIST_TIME_SMALL_MONTH_DAY_ERROR = 1119, //������ʱ��С�����ڲ���
	DC_WHITE_LIST_TIME_LEAP_YEAR_DAY_ERROR = 1120, //������ʱ������������ڲ���
	DC_WHITE_LIST_TIME_NO_LEAP_YEAR_DAY_ERROR = 1121, //������ʱ�������������ڲ���
	DC_WHITE_LIST_TIME_HOUR_ERROR = 1122, //������ʱ��Сʱ����
	DC_WHITE_LIST_TIME_MINUTE_ERROR = 1123, //������ʱ����Ӳ���
	DC_WHITE_LIST_TIME_SECOND_ERROR = 1124, //������ʱ����������
	DC_WHITE_LIST_TIME_START_THAN_END = 1125, //������ʱ�俪ʼʱ����ڽ���ʱ��
	DC_WHITE_LIST_EXPORT_CSV_READ_FAIL = 1126, //����������CSV��ʽ��ʧ��
	DC_WHITE_LIST_EXPORT_CSV_WRITE_FAIL = 1127, //����������CSV��ʽдʧ��

	//�ϴ�
	DC_UPLOAD_DATA_SERVER_ALLOC_FAIL = 1200, //�ϴ����񴴽�ʧ��
	DC_UPLOAD_UNABLE_TO_OPEN_FILE = 1201, //�ϴ��ļ����ܷ���
	DC_UPLOAD_SOCKET_CREATE_FAIL = 1202, //�ϴ����񴴽�socketʧ��
	DC_UPLOAD_CONNECT_CAMERA_FAIL = 1203, //�ϴ������������ʧ��
	DC_UPLOAD_READ_FILE_FAIL = 1204, //�ϴ��ļ���ȡʧ��
	DC_UPLOAD_SEND_FILE_NO_ALL = 1205, //�ϴ��ļ����Ͳ�����

	DC_UPLOAD_DATA_SERVER_ALLOC_FAIL_OLD = 1220, //�ϴ����񴴽�ʧ��
	DC_UPLOAD_DATA_CREATE_THREAD_FAIL_OLD = 1221, //�ϴ����񴴽��߳�ʧ��

	//����
	DC_DOWNLOAD_DATA_SERVER_ALLOC_FAIL = 1250, //���ط��񴴽�ʧ��
	DC_DOWNLOAD_SOCKET_CREATE_FAIL = 1251, //���ط��񴴽�socketʧ��
	DC_DOWNLOAD_CONNECT_CAMERA_FAIL = 1252, //���ط����������ʧ��
	DC_DOWNLOAD_CREATE_FILE_FAIL = 1253, //���ط��񴴽��ļ�ʧ��
	DC_DOWNLOAD_RECV_DATA_FAIL = 1254, //���ط����������ʧ��

	//��ȡ���ض˿�
	DC_GET_PORT_SOCKET_ERROR = 1300, //��ȡ���ض˿�socket����
	DC_GET_PORT_GET_LOCAL_IP_FAIL = 1301, //��ȡ���ض˿ڻ�ȡ����IPʧ��
	DC_GET_PORT_FAIL = 1302, //��ȡ���ض˿�ʧ��

	//����
	DC_UPDATE_FILE_TYPE_ERROR = 1400, //�����ļ����Ͳ���
	
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

	unsigned char ucLprMode;  /* 0����������1��������*/
	unsigned char ucReseved;
	unsigned short usServerPort;
	char aucServerIp[32];
}T_ExportBlackWhiteList;

typedef enum 
{
	WHITE_LIST_NEW_SEND,//���·���
	WHITE_LIST_ADD_SEND,//����
	WHITE_LIST_DEL_SEND,//ɾ��
	WHITE_LIST_MAX
}E_WhiteListSendMode;

typedef enum
{
	BLACK_LIST,//������
	WHITE_LIST//������
}E_ListMode;
typedef enum
{
	CODE_IN_UTF8,//UTF-8����
	CODE_IN_GB2312//GB2312����
}E_CodeMode;

typedef struct 
{
	unsigned char ucLprMode;  /* E_ListMode*/
	unsigned char ucLprCode;      /* E_CodeMode*/
	unsigned short usServerPort;
	unsigned char ucLprnew; /*E_WhiteListSendMode��*/
	unsigned char aucReseved[3];
	char aucServerIp[32];
	char aucFileName[128];
	unsigned int  uiFileSize;
}T_ImportBlackWhiteList;


/* ���̷�����ʾ*/
typedef struct
{
	unsigned int	uiSizeM;							/* ������С����MByteΪ��λ*/
	unsigned int	uiUsedM;							/* ��ʹ�ô�С����MByteΪ��λ*/
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
	LS_MODE_OFFLINE,	 /*�ѻ�ʹ��*/ 
	LS_MODE_ENABLE,	 /*ʹ�ܣ��������������ѻ�*/ 
	LS_MODE_DISABLE,	 /*��ʹ��*/ 
	LS_MODE_MAX 
}E_LedScreenMode; 
typedef struct
{
	unsigned int	uiInterval;//̧բ����ʱ��ms	
	unsigned char   ucLed;//E_LedScreenType
	unsigned char   ucLedScreenMode;//E_LedScreenMode
	unsigned short	usDownInterval;//��բ����ʱ��ms
}T_ParkSetup;
typedef struct
{
	unsigned char		ucPartitionNum;
}T_HardDiskNum;/*��ʽ��Ӳ��ѡ�����*/

typedef struct
{
	unsigned char ucTransProt;	/* E_TransmitProtocol*/
	unsigned char szReserved[3];
}T_TransProt;

/*��־����*/
typedef enum
{
	LOG_LEVEL_INFO_MAX = 0,
	LOG_LEVEL_INFO_MID,
	LOG_LEVEL_INFO_MIN,
}E_LogLevelInfo;

typedef enum 
{ 
	WEEK_DAY_EACH =0, /*ÿ��*/ 
	WEEK_DAY_ZERO,  /*������*/
	WEEK_DAY_ONE,   /*����һ*/
	WEEK_DAY_TWO, 
	WEEK_DAY_THREE, 
	WEEK_DAY_FOUR, 
	WEEK_DAY_FIVE, 
	WEEK_DAY_SIX, 
	WEEK_DAY_ALL, 
}E_WeekDay; 

/*��ʱ����*/ 
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
	unsigned short usFileType;//ҵ����0���ں���2���ļ�ϵͳ��3�����E_UpgradeType
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

/* �����������*/
typedef enum
{
	UPGRADE_TYPE_APP = 0,
	UPGRADE_TYPE_APP_FORCE = 1,  /* Ӧ�����ǿ������*/
	UPGRADE_TYPE_KERNEL = 2,
	UPGRADE_TYPE_FS = 3,
	UPGRADE_TYPE_WEB = 4,
	UPGRADE_TYPE_DSP = 5,
	UPGRADE_TYPE_LOGO = 6,
	UPGRADE_TYPE_CONFIG = 7, /* ���������ļ�*/
	UPGRADE_TYPE_LPR = 8, /* ���������*/
	UPGRADE_TYPE_PRESENT_VEH = 9,
	UPGRADE_TYPE_OFFLINE_DATA = 10, /* ��ͼ�ѻ�����*/
	UPGRADE_TYPE_OFFLINE_PAY = 11,  /* ��ͼ�ѻ��շ�����*/
	UPGRADE_TYPE_RE_PLATE = 12,  /* ���ƺ������*/
	UPGRADE_TYPE_IPC_LOGFILE = 13,  /* log��־*/
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
	unsigned char ucFileCode;/* 0��utf-8�ַ����룻1��gb2312�ַ�����*/
	unsigned char ucFileOpt; /*0�� ȫ�����ݣ�1���������ݣ�2:ɾ�����ݣ�*/
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
	unsigned char ucFileCode;/* 0��utf-8�ַ����룻1��gb2312�ַ�����*/
	unsigned char ucFileOpt; /*0�� ȫ�����ݣ�1���������ݣ�2:ɾ�����ݣ�*/
	unsigned char aucReserved[14];  
}T_FileServerSetupCam;

#ifndef _T_NetSetup
#define _T_NetSetup
typedef struct
{
	unsigned char	ucEth;				/* ��̫���ڱ��,Ŀǰֻ֧��0*/
	unsigned char	aucReserved[3];
	unsigned int	uiIPAddress;		/*192.168.0.148 ��Ӧ16���� 0xc0a80094*/
	unsigned int	uiMaskAddress;
	unsigned int	uiGatewayAddress;
	unsigned int	uiDNS1;
	unsigned int	uiDNS2;
	char	szHostName[MAX_HOST_LEN];
}T_NetSetup;
#endif	
/* �鲥����*/
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

/* MAC��ַ����*/
#ifndef _T_MACSETUP
#define _T_MACSETUP
typedef struct
{
	unsigned char	ucEth;				/* ��̫���ڱ��,Ŀǰֻ֧��0*/
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
}T_AssistantIpnc;  /*�����������*/

typedef struct
{
	unsigned char	ucEnable;
	unsigned char	ucCharCode;
	unsigned short 	usPort;
	char			szIpAddr[16];
}T_Messenger;

typedef struct 
{ 
	unsigned char ucCusNo; /*�ͻ���ţ�0��ʾδ֪*/ 
	unsigned char aucReserved[3]; 
}T_CustomerNo;

typedef struct
{
	unsigned char	ucEnable;      /*��ʱʹ��*/
	unsigned char	ucTimeLen;   /*ִ��ʱ������λ:��*/
	unsigned char	aucReserved[2];
	unsigned int	uiAutoStartTime; /*��ˢ��ʱ����ʱ��0x00HHMMSS ���ֽ�Ϊ��*/
}T_WiperTiming;

typedef  struct  
{
	unsigned short x1;                         //�������Ͻ�x����
	unsigned short y1;                         //�������Ͻ�y����
	unsigned short x2;			       //�������½�x����
	unsigned short y2;                         //�������½�y����
}T_Ave_Rect;

//��ʾ����״������
typedef  struct  
{
	unsigned short	uwDist;                  //Ԥ���ʾ����������ˮƽ����
	unsigned short	uwResrved;
	T_Ave_Rect		tAveRect;                //Ԥ���ʾ���������
}T_Ave_Par;

//�ܼ���������Ϣ
typedef  struct  
{
	unsigned char   ucBlureTh;             //ģ������ֵ��Χ��0,100��,Խ��Խģ��
	unsigned char	ucRegNum;		  //Ԥ���ʾ����Ŀ-���8��
	unsigned short	uwResrved;
	T_Ave_Par      tAvePar[AVE_REG_NUM];  //Ԥ���ʾ���������
}T_Ave_Config;

typedef struct
{
	unsigned short	   uwDistVmet;//��λ����
	unsigned short	   uwResrved;
}T_Ave_Result;

typedef enum
{
	PARK_OFFLINE_STATE,//�ѻ�״̬
	PARK_ONLINE_STATE,//����״̬
	PARK_MAX_STATE
}E_ParkState;
typedef struct
{
	unsigned char	ucState;
	unsigned char	aucReserved[3];
}T_ParkRealTimeState;//������ͤ���ӵ�ʵʱ״̬�������������ѻ�

typedef struct 
{
	unsigned char  	ucState; /*0:��1:��*/
	unsigned char	aucReserved[3]; 
}T_WiperManual;  /*��ˢ�ֶ�����*/

typedef struct
{
	unsigned short usSigCtrlSerPort;
	unsigned char  aucReserved[2];
}T_SigControlPort;

 /* ����˿����� */
typedef struct
{
	unsigned short	usHttpPort;
	unsigned short	usRtspPort;
}T_ServicePortSetup;

 /* ͼ�������� */
typedef struct
{
	unsigned char	ucMode;			/* ����ģʽ��Ŀǰ��֧��JPEG��*/
	unsigned char	ucFmt;			/* �����ʽ���ֱ������ 0 1080p(1920*1080)  1 720p(1280*720) 2 4cif(720*576) 3 cif(352*288)*/
	unsigned char	ucQuality;		/* ��������*/
	unsigned char	ucPeriod;		/* �������ڣ�1��7��/��*/
}T_ImageCodec;

/* ����ģʽ*/
typedef enum
{
	OPERATE_MODE_MANUAL = 1, 				/* �ֶ�ģʽ*/
	OPERATE_MODE_AUTO,	            /* �Զ�ģʽ*/
	OPERATE_MODE_ALL
}E_OperateMode;


/* ��Ƶ�������*/
typedef struct
{
	unsigned char	ucMode;			/* ����ģʽ��Ŀǰ��֧��H264��*/
	unsigned char	ucFmt;			/* �����ʽ���ֱ������*/
	unsigned char	ucFps;			/* ֡Ƶ�� PAL��1��25��ѡ��NTSC�ƣ����ֱ���Ϊ1080Pʱ��1��25��ѡ���������1��30��ѡ��*/
	unsigned char	ucRateControl; 	/* ���ʿ��ƣ�0->VBR(�ɱ�����)��1->CBR(�̶�����)*/
	unsigned int	uiRate;			/* ���ʣ�384000��16000000 bps*/
	unsigned char	ucIFPeriod;		/* I֡�����1��5 �룻*/
	unsigned char	ucEnabled;		/*�����Ƿ�����������Ƶ��Ч*/
	unsigned char   ucIncSnapFrame; /*����ץ��֡ʹ��*/      
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
	CHECK_TYPE_NONE,	/* ��У��*/
	CHECK_TYPE_ODD,		/* ��У��*/
	CHECK_TYPE_EVEN,	/* żУ��*/
	CHECK_TYPE_FLAG,	/* ��־У��*/
	CHECK_TYPE_EMPTY,	/* ��У��*/
	CHECK_TYPE_ALL
}E_CheckType;
/* RS485����*/
typedef struct
{
	unsigned char   ucIndex;
	unsigned char   ucFunction;         /*E_RS485Function*/
	unsigned char	ucBaudRate;			/* E_BaudRate*/
	unsigned char	ucDataBits;			/* ����λ��5��8��*/
	unsigned char	ucStopBits;			/* ֹͣλ��0��2��*/
	unsigned char	ucCheckOut;			/* E_CheckType*/
	unsigned char   ucType;             /* 0:�Զ�,1:485,2:232 */
	unsigned char   ucReserved;
}T_RS485Setup;

 /*���ⲹ��*/
typedef struct
{
	unsigned char ucEnable;
	unsigned char aucReservel[3];
}T_ImageEv; 

typedef enum
{
	KAKOU = 0,          /*����*/
	RUN_REDLIGHT,   	/*�����*/
	OVER_SPEED,     	/*����*/
	REVERSE,        	/*����*/
	TRAFFIC_BAN,    	/*���У�����ʹ��*/
	CROSS_LINE,     	/*Խ��*/
	ILLEGAL_STOP,    	/*Υͣ*/
	ILLEGAL_OCCUP,   	/*ר�õ�*/
	ILLEGAL_PRESS_LINE, /*ѹ��*/
	ILLEGAL_NOLANE_RUN, /*����������ʻ*/
	SNAPSHOT_TYPE_ALL,  /*��Ч����*/
	ILLEGAL_PREDICT,  	/*Υ��Ԥ��*/
	NET_SNAP = 0xFF,
}E_SnapshotType;

typedef enum
{
	MERGE_TYPE_NONE,
	MERGE_TYPE_H,					/* ����ϲ�*/
	MERGE_TYPE_V,					/* ����ϲ�*/
	MERGE_TYPE_H_ADAPT,				/* ����+��Ƶ(���²���)*/
	MERGE_TYPE_V_ADAPT,				/* ����+��Ƶ(���Ҳ���)*/
	MERGE_TYPE_FOUR,				/* ������*/
	MERGE_TYPE_SIX,					/* �����Σ�6��*/
	MERGE_TYPE_H_SMALL,				/* ����ϲ�����*/
	MERGE_TYPE_V_SMALL,				/* ����ϲ�����*/
	MERGE_TYPE_FOUR_SMALL,			/* ����������*/
	MERGE_TYPE_ALL
}E_ImageMergType;


/* �¼�ץ�Ĳ���*/
typedef struct
{
	unsigned char	ucEventCaptureType;   /* �¼�ץ������ E_SnapshotType 0(����ץ��)1�������ץ�ģ�3(����)4������ץ�ģ�5��Խ��ץ�ģ�6��Υͣץ�ģ�8��ѹ��ץ�ģ�9(����������ʻץ��)*/
	unsigned char	ucPicSnapshotNum;     /*ץ������*/
	unsigned char	szReserver[2];
	/* -1������Ȧ1��-2������Ȧ2��-3������Ȧ1��-4������Ȧ2��
		-5��������� ������Ƶ��⣬��ʾ��ͷ����������ˣ���Ϊ�״��⣬���������״����򣬱��״��豸����
		-6��������� ������Ƶ��⣬��ʾ��β�뿪������ˣ���Ϊ�״��⣬���ѡ����Ч��
		��������0��ֵ����ʾ��ʱץ�ģ���ֵ��ʾ��ʱʱ�䣬 0��300ms
	*/
	int	aiGetPicPosition[3];
	unsigned char	ucPicMergeType;				/* ͼƬ�ϳ����ͣ�0�����ϳɣ�1������ϳɣ�2������ϳɣ�3����Ƶ+���루���²��֣���4����Ƶ+���루���Ҳ��֣���5�����ַ��*/
	unsigned char	ucMainPicItem;				/* ��ͼ��ţ���ͼƬ����Ϊ3��4ʱ��Ч��*/
	unsigned char	ucRecordEnable;				/* �Ƿ�֧��Υ��¼��*/
	unsigned char	ucRecordTime;				/* ¼��ʱ����4��7��*/
	unsigned char 	ucPreRecordTime;			/*Ԥ¼ʱ����0��3�룬Ĭ��Ϊ2s*/
	unsigned char 	ucReserved;					/*�����ֶ�*/
	unsigned short  usIllegalCode;				/*����Υ�´���*/
}T_EventCapturePara;

/*ʱ��*/
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


/* ��������ò���*/
typedef struct
{
	unsigned char		ucFlashLightMode;		/* ���ơ����ģʽ��0:����*/
	unsigned char		ucNormalWorkMode;		/*��������ģʽE_LightWorkMode*/
	unsigned char		ucIllegalWorkMode;		/*Υ������ģʽE_LightWorkMode*/
	unsigned char		ucOpenBrightnessTH;		/* �Զ�ģʽ�£�����ƿ�����������ֵ��*/
	T_EnableTimeBucket	atFourceFlashTime[2];	/*ǿ������ʱ��*/
}T_FlashLightSetup;

/* Ƶ�������ò���*/
typedef struct
{
	unsigned char	ucNormalWorkMode;			/* ��������ģʽE_LightWorkMode*/
	unsigned char	ucCombinationalWorkMode;	/* ��ϲ���ģʽ����ָ������ƿ���������µĲ���ģʽE_LightWorkMode*/
	unsigned char	ucOpenBrightnessTH;			/* �Զ�ģʽ�£�Ƶ���ƿ�����������ֵ��*/
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
	FT_PICTURE_KK = 0,   /*����ͼƬ*/
	FT_PICTURE_CHD,      /*�����*/
	FT_PICTURE_CS,       /*����*/
	FT_PICTURE_NX,       /*����*/
	FT_PICTURE_JX,       /*����*/
	FT_PICTURE_YX,       /*Խ��*/
	FT_PICTURE_WT,       /*Υͣ*/
	FT_PICTURE_ZD,       /*ռ��*/
	FT_PICTURE_PL,       /*ѹ��*/
	FT_PICTURE_NRW,      /*����������ʻ*/
	FT_EVENT_STAT,       /*��ͨ�¼�ͳ��*/
	FT_LOG_FILE,		 /*����*/
	FT_AUTO_UPGRADE,     /*�Զ�����*/
	FT_ALL,
}E_FileType;

typedef struct
{	
	unsigned char	ucEnabled;   		/*ʱ��ֶ�����*/
	unsigned char	ucWorkDayEnable;	/*����������*/
	unsigned char	ucWeekEndEnable;	/*��ĩ����*/
	unsigned char	ucReserved1;
	T_TimeBucket	tTimeBucket;
	unsigned char	ucRunRedLightSnap;  /*�����ץ��*/
	unsigned char	ucKaKouSnap;        /*����ץ��*/    
	unsigned char	ucReverseSnap;      /*����ץ��*/
	unsigned char	ucCrossLineSnap;    /*Խ��ץ��*/
	unsigned char	ucOverSpeedSnap;	/* ����ץ������*/
	unsigned char	aucReserved2[3];
}T_EventCapTimeBasicSetup;

typedef enum
{
	PLATE_DIRECTION_TAIL = 0,  /*��β����*/
	PLATE_DIRECTION_HEAD,      /*��ͷ����*/
	PLATE_DIRECTION_ALL,
}E_PlateDirection;

typedef struct
{
	unsigned char ucEnabled;			/**/
	unsigned char ucLaneNo;				/*������*/
	unsigned char ucLaneIndex;
	unsigned char ucLaneType;			/*��������E_LaneType*/
	unsigned char ucRedLightSnapTestEn;	/*�����ץ�Ĳ�������*/
	unsigned char ucTimeSegEnable;  	/*��ʱ��*/
	
	unsigned char ucLaneDir; 			/*E_PlateDirection*/
	
	/*�������*/
	unsigned char ucMaxSpeed;			/*��λ��KM/H ���Ӿ����ڲ�ʹ�ã���web������Ϊ�����ֶ�*/
	
	T_EventCapTimeBasicSetup atCaptureTime[MAX_TIMEBUCKET];/*ץ��ʱ��*/
}T_RoadLaneBasicSetup;

typedef struct
{	
	unsigned char ucEnabled;   		  /*ʱ��ֶ�����*/
    unsigned char ucWorkDayEnable;    /*����������*/
	unsigned char ucWeekEndEnable;	  /*��ĩ����*/
	unsigned char uacReserved1;
	T_TimeBucket  tTimeBucket;
	unsigned char ucPressLineSnap;    /*ѹ��ץ��*/
	unsigned char ucNoAccordRoadWay;  /*����������ʻ*/
	unsigned char ucTrafficBanSnap;   /*����ץ��*/ 
	unsigned char ucIllegeStopSnap;   /*Υͣץ��*/ 
	unsigned char ucSpecialRoadSnap;  /*ר�õ�ץ��*/
	unsigned char aucReserved[3];
}T_EventCapTimeExtendSetup;

/* ������չ��������*/
typedef struct
{
	unsigned char	ucLaneIndex;
	unsigned char	ucTrafficStaEn;			/*�Ƿ����ý�ͨ�¼�ͳ��*/
	unsigned char	ucOccupRatioEventEn;	/*�Ƿ�����ռ���ʱ���*/
	unsigned char	ucVehicleStopEventEn;	/*�Ƿ�����ͣʻ����*/
	unsigned char	ucTrafficJamEventEn;	/*�Ƿ����ý�ͨӵ�±���*/
	unsigned char	ucSpecialRoadType;
	unsigned char	ucTimeSegEnable;
	unsigned char	ucVehStatTime;			/*��ͨ����ͳ�����ڣ���λΪ����*/
	T_EventCapTimeExtendSetup  atCaptureTime[EVENT_CAP_TIMEBUCEKT_CNT];/*ץ��ʱ��*/
}T_RoadLaneExtendSetup;

/* ���ٲ�������*/
typedef struct
{
	unsigned char	ucLaneIndex;
	char			cLoopDefaultSpeedRatio;		/*��ȦĬ���ٶ�У��*/
	char			cLoopHightSpeedRatio;		/*��Ȧ�����ٶ�У��*/
	unsigned char	ucLoopHightSpeedCaliLimit;	/*��Ȧ����У���ٶ�ֵ*/
	char			cRadarDefaultSpeedRatio;	/*�״�Ĭ���ٶ�У��*/
	char			cRadarHightSpeedRatio;		/*�״�����ٶ�У��*/
	unsigned char	ucRadarHightSpeedCaliLimit;	/*�״����У���ٶ�ֵ*/
	char			cVideoDefaultSpeedRatio;	/*��ƵĬ���ٶ�У��*/
	char			cVideoHightSpeedRatio;		/*��Ƶ�����ٶ�У��*/
	unsigned char	ucVideoHightSpeedCaliLimit;	/*��Ƶ����У���ٶ�ֵ*/
	unsigned char	ucHighSpeedLimit;			/*��������ٶ�*/
	unsigned char	ucLowSpeedLimit;			/*��������ٶ�*/
	unsigned char	ucSpeedLimitClassifyEn;		/*��������������*/
	unsigned char	ucCarHighSpeedLimit;		/*С�ͳ�����ٶ�*/
	unsigned char	ucCarLowSpeedLimit;			/*С�ͳ�����ٶ�*/
	unsigned char	ucTruckHighSpeedLimit;		/*���ͳ�����ٶ�*/
	unsigned char	ucTruckLowSpeedLimit;		/*���ͳ�����ٶ�*/
	unsigned char	szReserved[3];
}T_SpeedCorrAndLimitSetup;

typedef struct
{
	unsigned char	ucPlateRealTimeShowEn;	    /* modify by zhuby 20160712:��ʾʵʱ���ƣ�Ĭ�Ϲر�*/
	unsigned char	ucRecRegShowEn;			    /* modify by zhuby 20160712:��ʾ����ʶ������Ĭ�ϴ�*/
	unsigned char	ucArmyLprPrior;			    /* ��������*/
	unsigned char	ucNoPlateVehicleSnapEn;		/* ���Ƴ�ץ�ı�ʶ��0����ץ�� 1����ʾץ��*/
	unsigned char	ucCpHightTI;				/* ͬһ����ץ�ļ�����ֽ�*/
	unsigned char	ucLocalCity; 				/*���Ƶĵڶ����ַ���'A'~'Z'*/
	unsigned char	ucPlateDirection;           /*���Ʒ���E_PlateDirection*/   
	unsigned char	ucCpTimeInterval;           // ͬһ����ץ�ļ��  ���ֽ�
	unsigned int	uiPlateDefaultWord;			/* Ĭ��ʡ�ݣ�����UTF-8����*/

	unsigned short	usMinPlateW;				/*����ʶ����С���,��λ:����*/
	unsigned short	usMaxPlateW;				/*����ʶ������ȣ���λ:����*/
	unsigned char	ucInvalidLprLevel;			/*α���ƴ���ȼ�*/
	unsigned char	ucVehicleInterval;			/*ǰ��ץ�ļ������λ:��*/
	unsigned char	ucPolicePlate;				/*�侯���ƺ��������0: �����1:���*/
	unsigned char	ucPlateFeature;				/*������д*/
}T_VehicleVAFunSetup;

typedef struct
{
	unsigned char	ucPlateRealTimeShowEn;				/* modify by zhuby 20160712:��ʾʵʱ���ƣ�Ĭ�Ϲر�*/
	unsigned char	ucRecRegShowEn;						/* modify by zhuby 20160712:��ʾ����ʶ������Ĭ�ϴ�*/
	unsigned char	ucVehicleColorRecogEn;		/* ������ɫʶ��ʹ��*/
	unsigned char	ucNoPlateVehicleSnapEn;		/* ���Ƴ�ץ�ı�ʶ��0����ץ�� 1����ʾץ��*/
	unsigned char	ucCpHightTI;				/* ͬһ����ץ�ļ�����ֽ�*/
	unsigned char	ucLocalCity; 					/*���Ƶĵڶ����ַ���'A'~'Z'*/
	unsigned char	ucPlateDirection;           		/*���Ʒ���E_PlateDirection*/   
	unsigned char	ucCpTimeInterval;           		// ͬһ����ץ�ļ��  ���ֽ�
	unsigned int	uiPlateDefaultWord;			/* Ĭ��ʡ�ݣ�����UTF-8����*/
	unsigned short	usMinPlateW;				/*����ʶ����С���,��λ:����*/
	unsigned short	usMaxPlateW;				/*����ʶ������ȣ���λ:����*/
	unsigned char	ucDoubleYellowPlate;			/*˫�����ʶ��1��ʶ�� 0����ʶ��*/
	unsigned char	ucVehicleInterval;			/*ǰ��ץ�ļ������λ:��*/
	unsigned char	ucPolicePlate;				/*�侯���ƺ��������0: �����1:���*/
	unsigned char	ucPlateFeature;				/*������д*/

	unsigned char	ucLprHead;				/* ʶ��ģʽ,TRUE��ͷģʽ,FALSE��βģʽ(��ͷģʽ:����˫����ƾ�ʶ�𣬳�βģʽ:ֻ�Ǳ�˫�����)*/
	unsigned char	ucZoomSlop;				/* ����ͼ���Ƿ������б����*/
	unsigned char	ucCpMode;				/* ץ��ģʽ 0 : ��������ץ��  1: ������Ȧ,����ץ��*/
	unsigned char	aucReserved[29];
}T_VehicleVAFunSetupEX;


typedef enum
{
	INVALID_LPR_LEVEL1 = 1, /* ���ƺ���ȫΪ7,Z,2,1,T,L��ͬһ�ַ������ڵ���4*/
	INVALID_LPR_LEVEL2, /* ���Ʒ���С��88*/
	INVALID_LPR_LEVEL3, /* �׺���С��50���ҳ��Ʒ���С��88*/
	INVALID_LPR_MAX,
}E_INVALID_LPR_LEVEL;

typedef enum
{
	INVALID_LPR_WHITE = 0x01, /*����*/
	INVALID_LPR_BLUE = 0x02,   /*����*/
	INVALID_LPR_YELLOW = 0x04, /*����*/
	INVALID_LPR_BLACK = 0x08, /*����*/     	
}E_INVALID_LPR_COLOR;

typedef struct
{
	unsigned char	ucLevel; // E_INVALID_LPR_LEVEL ����ȼ�
	unsigned short	usColorBit;//��Դ���ĳ�����ɫE_INVALID_LPR_COLOR
	unsigned char Reserved[13]; //����λ
}T_InvalidLprLevel;

typedef struct
{
	unsigned char ucTime;
	unsigned char ucAddress;
	unsigned char ucDevNo;
	unsigned char ucRecordNo;		/*������*/
	unsigned char ucIllegalCode;
	unsigned char ucPicType;
	unsigned char ucRoadNo;
	unsigned char ucVehiclePlate;
	unsigned char ucVehicleSize;
	unsigned char ucVehicleSpeed;
	unsigned char ucVehicleFace;
	unsigned char ucWaterMark;
	unsigned char ucOverlayType;	/* ͼƬ����Ļ���ӷ��0�����е��ӣ�1�����е���*/
	unsigned char ucVehicleColor;
	unsigned char ucPlateRealPixel;  /* �Ƿ���ӳ���ʵ������*/
	unsigned char ucReserved; 
}T_PicOsdSetup;

typedef enum
{
	DIR_STRUCT_DEV_DATE,			/* ���豸���+����+ʱ����֯Ŀ¼*/
	DIR_STRUCT_DEV_DIR_LANE_DATE,	/* ���豸���+����+������+����+ʱ����֯Ŀ¼*/
	DIR_STRUCT_ALL
}E_DirStruct;

/* SD���洢��������*/
typedef enum
{
	SD_WRITE_TYPE_ROLL,
	SD_WRITE_TYPE_STOP,
	SD_WRITE_TYPE_ALL
}E_FULL_WRITE_TYPE;

/* �洢����*/
typedef struct
{
	unsigned char	ucEnable;					/* ���ش洢ʹ��*/
	unsigned char	ucDirStuct;					/* Ŀ¼�ṹ��E_DirStruct*/
	unsigned char	ucWritePolicy;				/* ������ʱ�Ĵ�����ԣ�E_FULL_WRITE_TYPE*/
	unsigned char	ucBackupPolicyNormal;		/* ����ͼƬ�ı��ݲ��ԣ�0�������ݣ�1������*/
	unsigned char	ucBackupPolicyIllegal;		/* Υ��ͼƬ�ı��ݲ��ԣ�0�������ݣ�1������*/
	unsigned char	ucBackupPolicyIRecord;		/* Υ��¼���Ƿ񱣴�0:�����ݣ�1:����*/
	unsigned char	ucIllegalRecordEn;			/* Υ��¼��ʹ�ܱ�־*/
	unsigned char	ucIllegalRecordTime;		/* Υ��¼��¼��ʱ��*/
	unsigned char	ucIllegalRecordReadyTime; 	/* Ԥ¼ʱ��*/

	unsigned char	ucRealTimeRecordEn;			/* ʵʱ¼���Ƿ�����*/
	unsigned char	ucRealTimeRecordDuration;	/* ʵʱ¼��ʱ��,����(1~120)*/
	unsigned char	ucReserved;
}T_StorageSetup;

typedef struct
{
	unsigned char	ucEnable;
	unsigned char	ucMode;			/* ��ʾģʽ��0: ��ý����ʾ, 1:�����ļ���ʾ*/
	unsigned char	aucReserved[2];
	char			szUrl[256];
}T_DemoSetup;
 

typedef enum
{
	SUBDIR_TYPE_ROOT,   					/*ʹ�ø�Ŀ¼*/
	SUBDIR_TYPE_DATE,						/*ʹ�����ڷ�Ŀ¼*/
	SUBDIR_TYPE_DEVNUM,						/*�豸��ŷ�Ŀ¼*/
	SUBDIR_TYPE_DEVNUM_DATE,				/*�豸���+ ����Ŀ¼*/
	SUBDIR_TYPE_DEVNUM_DATE_HOUR,			/*�豸���+ ����+ СʱĿ¼*/
	SUBDIR_TYPE_DEVNUM_ROAD_DATE_HOUR,		/*�豸���+����+����+СʱĿ¼*/
	SUBDIR_TYPE_DEVNUM_DIR_ROAD_DATE_HOUR,	/*�豸���+ ����+ ����+ ����+СʱĿ¼*/
	SUBDIR_TYPE_ALL
}E_SubDirType;

/* FTP����*/
typedef struct
{
	unsigned char	ucEnabled;
	unsigned char	ucSubDirCreateType;   /* ��Ŀ¼������ʽE_SubDirType*/
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

/* �豸��Ϣ����*/
typedef struct
{
	char			szDistrictNumber[16];	/* �������*/
	char			szProjectName[64];		/* ��Ŀ����*/
	char			szDevNumber[16];		/* �豸�ţ��û����壻*/
	char			szRoadName[64];			/* ���������*/
	char			szRoadNumber[16];		/* ����ڱ��*/
	unsigned char	ucDirection;			/* ����:1��ڣ�2������*/
	unsigned char	aucReserved[3];		  	/* �����ֶ�*/
	char			szLicenseNum[64];  		/* license��*/
	char			szRecordNum[32];        /*������*/
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

/*�źŵƼ��Դ*/
typedef enum
{
	CHECK_MODE_RS485 = 0,
	CHECK_MODE_VIDEO,
}E_SignalLightCheckMode;

/*�źŵƲ�������*/
typedef struct 
{
	unsigned char ucCheckSrc;   /*�źŵƼ��Դ E_SignalLightCheckMode*/
	unsigned char ucRedShine;	/*�Ƿ�����˸*/
	unsigned char ucMode;		/*0-��/1-ȫ��ģʽ/2-��ת��ͣ*/
	unsigned char ucBanRt;		/*����Ƿ��ֹ��ת*/

	unsigned char ucType;		/*�źŵ�����E_SignalLightType*/
	unsigned char ucLeftDelay;	/*��ת��ʱ*/
	unsigned char ucRightDelay;	/*��ת��ʱ*/
	unsigned char ucGoStraightDelay;/*ֱ����ʱ*/
	T_EnableTimeBucket atInvalidTimeBucket[MAX_TIMEBUCKET];/*ʧЧʱ��*/	
}T_SignalLightSetup;

typedef struct
{
	unsigned short	uwIndex;//С�����
	unsigned short	uwX;//
	unsigned short	uwY;//
	unsigned short	uwReserved;
	unsigned char	ucRed;//��
	unsigned char	ucYellow;//��
	unsigned char	ucGreen;//��
	unsigned char	ucCountdown;//����ʱ
	unsigned char	ucLeft;//��
	unsigned char	ucStraight;//ֱ
	unsigned char	ucRight;//��
	unsigned char	ucSwing;//��ͷ
} T_LightParm;

typedef struct 
{
	unsigned char	ucRadius;//�뾶				  ��λ�����أ�		
	unsigned char	ucTrack;//�Ƿ����			  1��/0��
	unsigned char	ucBanRight;//�Ƿ����         1��/0��
	unsigned char	ucBanYellow;//�Ƿ�ץ�Ĵ��Ƶ�  1��/0��
	unsigned short	uwLightNum;//С�Ƹ���
	unsigned short	uwReserved;
	T_LightParm	tLightParm[9];//С����Ϣ
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

/* SNTP����*/
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

/*������ͬ��*/
typedef struct
{
	unsigned char ucEnable;
	unsigned char ucOffset;
	unsigned char szReserved[2];
}T_DCAcSyncSetup;

typedef struct
{
	unsigned char	ucIndex;	/* ��Ļ��ţ�0-4������0·Ϊʱ����Ļ��ֻ�������Ƿ���ӣ� */                      
	unsigned char	ucEnabled;		/* ʹ�ܱ�־��*/                                                                 
	unsigned char	ucFontSize;		/* �����С��*/                                             
	unsigned char	ucWeekEnabled;	/*������ʾ*/                                             
	unsigned int	uiForeColor;		/* ǰ��ɫ����ʽΪ0x00RRGGBB��*/                             
	unsigned int	uiBackColor;		/* ����ɫ����ʽΪ0xXXRRGGBB�����XX��Ϊ0����ʾ����Ҫ����ɫ��*/
	unsigned short	usPosX;			/* X����  */                                                                    
	unsigned short	usPosY;			/* Y����  */                                                                    
	unsigned short	ausContent[33];   /* ��Ļ���ݣ�UNICODE16��ʽ����0��β��    */
	unsigned char   ucShowPlrflag;	 /*�Ƿ����ʶ���ƽ��*/	
	unsigned char   ucReserved;
}T_Subtitle;

typedef struct
{ 
	unsigned char	ucGroupId;                   /* ��ID */
	unsigned char	ucShutterMode;               /* ����ģʽ */
	unsigned char	ucGainMode;                  /* ����ģʽ */
	unsigned char	ucReserved;					 /*�����ֶ�*/
	unsigned int	uiShutterValue;              /* ����ֵ */
	unsigned short	usGainValue;                 /* ���� */
	unsigned short	usBrightnessTH;              /* ���ȷ�ֵ*/
}T_DCSnapParaSetup;

typedef struct 
{
	unsigned char	ucLaneNo;			/*�������*/
	unsigned char   ucReserved;
	unsigned short  usReverseCount;  /*���ཻͨ����*/
	unsigned int	uiDate;
	unsigned int	uiTime;
	unsigned int	uiVehicleNum;		/*������*/
	unsigned int	uiAveSpeed;			/*ƽ������*/
	unsigned int	uiTimeOccupyRate;	/*ʱ��ռ����*/
}T_DCTraStatReport;


typedef struct
{ 
	unsigned char ucShutterMode;                /* ����ģʽ */
	unsigned char ucGainMode;                   /* ����ģʽ */
	unsigned char szReserved[2]; 				/*�����ֶ�*/
	unsigned int uiShutterValue;				/* ����ֵ */
	unsigned short usGainValue;                 /* ���� */
	unsigned short usBrightnessTH;              /* ���ȵı�׼�ο�ֵ */
}T_VideoParaSetup;

typedef struct
{
	unsigned char	ucMode;			/* ����ģʽ��Ŀǰ��֧��H264��*/
	unsigned char	ucFmt;			/* �����ʽ���ֱ������*/
	unsigned char	ucFps;			/* ֡Ƶ1<<25*/
	unsigned char	ucRateControl; 	/* ���ʿ��ƣ�0->VBR(�ɱ�����)��1->CBR(�̶�����)*/
	unsigned int	uiRate;			/* ���ʣ�384000��16000000 bps*/
	unsigned char	ucIFPeriod;		/* I֡�����1��5 �룻*/
	unsigned char	ucEnabled;		/*�����Ƿ�����������Ƶ��Ч*/
	unsigned char   ucIncSnapFrame; /*����ץ��֡ʹ��*/      
	unsigned char	ucquality;     //ucReserved;//�������� 0 ��  1 ��  2 ��
}T_VideoCodeSetup;

/*��̬��Ƶ����ṹ��*/
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
	unsigned int	uiVideoFormat;//��Ƶ֧�ֵĸ�ʽ����λֵ����ʾ����ͬλ��ֵ��ʾ���£�0->��Ч��1->CIF��2->4CIF��3->SXGA��4->720P��5->UXGA��6->1080P��7��30������31->ȫ�ֱ��ʣ���������Ⱥ͸߶ȵ�ֵ�ó���
	float   ucMaxFs;
}T_DCSpec;

typedef enum
{
	FILE_DOWNLOAD_TFTP = 0,
	FILE_DOWNLOAD_FTP,
	FILE_DOWNLOAD_ALL,
}E_FileDownloadType;


/*�ϱ��汾��*/
typedef struct
{
	char		szKernelVersion[VERSION_NAME_LEN];
	char		szFileSystemVersion[VERSION_NAME_LEN];
	char		szAppVersion[VERSION_NAME_LEN];
	char		szWebVersion[16];
	char		szProtocolVersion[16];
	char		aucReserved[32];
	char		szHardwareVersion[VERSION_NAME_LEN];
	char		szDevType[64];		/* �豸��������������ʱ�趨��*/
	char		szSerialNum[64];    	/*��Ʒ���к�*/
	unsigned int uiDateOfExpiry;		/*��Ʒ��Ч��*/
	char		szDSPVersion[VERSION_NAME_LEN];
}T_QueVersionRsp;

/* ϵͳ״̬�ϱ�*/
typedef struct
{
	unsigned char	ucLoopStatus;		/* ��Ȧ�����״̬��0�������������쳣*/
	unsigned char	ucRadarStatus;		/* �״�����״̬��0�������������쳣*/
	unsigned char	ucVAStatus;			/* ���ܷ���ģ��״̬��0�������������쳣*/
	unsigned char	ucSSDStatus;		/* Ӳ��״̬��0�������������쳣*/
	unsigned int	uiSSDSize;			/* Ӳ����������λGB*/
	unsigned int	uiSSDReserved;		/* ʣ����������λGB*/
}T_SysState;

typedef enum
{
	LOOP_DETECT = 0,	/*��Ȧ���*/
	RADAR_DETECT,		/*�״���*/
	VIDEO_DETECT,		/*��Ƶ���*/
	LOOP_VIDEO_DETECT,	/*��Ȧ+��Ƶ���*/
	RADAR_VIDEO_DETECT, /*�״�+��Ƶ���*/
	ALL_DETECT_METHOD
}E_DetectMethod;

/* ���ģʽ����*/
typedef struct
{
	unsigned char ucDetectMode;	   /*���ģʽE_DetectMethod*/
	unsigned char szReserved[3];   /*�����ֶ�*/
}T_DetectModeSetup;

/* ��Ȧ��������Ϣ*/
typedef enum
{
	LEAVE_LOOP, /*����Ȧ*/
	ENTER_LOOP, /*����Ȧ*/
}E_LoopInfo;

/*��Ȧ��������*/
typedef struct
{
	unsigned char	ucLaneIndex;     /* ������Ȧ��Ӧ�ĳ��������� */
	unsigned char  ucLoopLaneIndex; /*�������϶�Ӧ�ĳ�����������0��ʼ���*/
	unsigned char   ucMode;
	unsigned char   szReserved;
	//unsigned char  szReserved[2];    /*�����ֶ�*/
	unsigned short	usLoopWidth;     /*��Ȧ���*/
	unsigned short	usLoopInterval;  /*��Ȧ���*/
}T_LoopParamSetup;


/*�״��������*/
typedef struct
{
	unsigned char	ucLaneIndex;		/*������Ȧ��Ӧ�ĳ���������*/
    unsigned char  ucRadarLaneIndex;	/*�״ﳵ������,��0��ʼ���*/
	unsigned char  szReserved[2];       /*�����ֶ�*/
	unsigned short	usPoleHeight;    /* ���˸߶� */
	unsigned short	usPoleToCenter;  /* ���˵��״��������������� */
}T_RadarParamSetup;

/* ��*/
typedef struct
{
	short sX;
	short sY;
}T_Point;

/* ��*/
typedef struct
{
	T_Point tStartPoint;
	T_Point tEndPoint;
}T_Line;

/* ����*/
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

/*��Ƶ��������������*/
typedef struct
{
	unsigned char		ucLanes;	   /* ������  */
	unsigned char		ucSnapAutoBike;/* Ħ�г�ץ��1:ץ��0:��ץ��*/
	unsigned char 		ucMinScore;    /* ץ��������  �� ʱ  ץ�ķ�ֵ����(0-100)*//* UINT16 usBanTime; /*Υͣʱ����ֵ����λ:�룻 ucMinScore��ucReserved��usBanTime��ֶ���*/
	unsigned char		ucReserved;
	unsigned char		ucCpMode;	/* ץ��ģʽ 0 : ��������ץ��  1: ������Ȧ,����ץ�� 2 ��������(��Ӧץ��������  0 ��  1 ��  ��)*/
	unsigned char		ucWidthFlag;/* ��ʶ���ƿ�ȱ�־λ: 0ʶ��Χ80-200, 1ʶ��Χ80-400, 2 ʶ��Χ160-400 */
	unsigned char		ucLprHead;	/* ʶ��ģʽ,TRUE��ͷģʽ,FALSE��βģʽ(��ͷģʽ:����˫����ƾ�ʶ�𣬳�βģʽ:ֻ�Ǳ�˫�����)*/
	unsigned char		ucZoomSlop;	/* ����ͼ���Ƿ������б����*/

	T_Point		atPlateRegion[4];      /*����ʶ������*/
	T_Line		aStopLine;              /*����:������ ���Ӿ���:ֹͣ��*/
	T_Point		atSpeedRegion[4];/*��������  */
	T_Line		atOccupCheckLine[2];/*ռ���ʼ����   */
	T_DivisionLine	atDivisionLine[ONE_DIRECTION_LANES+1];/*�����ָ���*/
	T_Line		tPrefixLine;  /*�羯ǰ����*/
	T_Line		tLeftBorderLine;  /*�羯��߽���*/
	T_Line		tRightBorderLine;  /*�羯�ұ߽���*/
	T_Point		atVirLoop[ONE_DIRECTION_LANES][4]; /*������Ȧ*/

	/*�Ƿ�ͣ����*/
	T_Point		atBanRegion[4];   /*�Ƿ���ͣ��*/

	unsigned short		usCameraHeight;        /* �����װ�߶� */
	unsigned short		usRectLength;          /*·����γ���(����)*/
	unsigned short		usRectWidth;           /*·����ο��(����)*/
	unsigned short		usTotalDis;            /*�������Ͻǵ��������ֱͶӰ�ľ���(����)*/
}T_VideoDetectParamSetup;


typedef struct 
{
	unsigned char		ucLanes;		/*������  */
	unsigned char		ucSnapAutoBike; /*Ħ�г�ץ��1:ץ��0:��ץ��*/
	unsigned short		usBanTime;   /*Υͣʱ����ֵ����λ:��*/
	unsigned char		ucVirLoopNum; /*������Ȧ��ץ��Ħ�г�ʹ��*/
	/*Υ������������*/
	unsigned char 		ucRunRedLight;   /*�����E_IllegalSensitive*/
	unsigned char             ucNobyLane;        /*��������*/
	unsigned char             ucCrossLine;        /*ѹ��*/
	T_Point		atPlateRegion[4];      /*����ʶ������*/
	T_Line		aStopLine;              /*����:������ ���Ӿ���:ֹͣ��*/
	T_Point		atSpeedRegion[4];/*��������  */
	T_Line		atOccupCheckLine[2];/*ռ���ʼ����   */
	T_DivisionLine	atDivisionLine[ONE_DIRECTION_LANES+1];/*�����ָ���*/
	T_Line		tPrefixLine;  /*�羯ǰ����*/
	T_Line		tLeftBorderLine;  /*�羯��߽���*/
	T_Line		tRightBorderLine;  /*�羯�ұ߽���*/
	T_Point		atVirLoop[ONE_DIRECTION_LANES][4]; /*������Ȧ*/

	/*�Ƿ�ͣ����*/
	T_Point		atBanRegion[4];   /*�Ƿ���ͣ��*/

	unsigned short		usCameraHeight;        /* �����װ�߶� */
	unsigned short		usRectLength;          /*·����γ���(����)*/
	unsigned short		usRectWidth;           /*·����ο��(����)*/
	unsigned short		usTotalDis;              /*�������Ͻǵ��������ֱͶӰ�ľ���(����)*/
	unsigned char 	       ucReverseRun;        /*����*/
	unsigned char   	       ucIllegalStop;         /*Υͣ*/
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

/*�ļ����Ͷ���*/
typedef enum
{
	FILE_TYPE_LOG = 0,
	FILE_TYPE_RECORD,
	FILE_TYPE_IMAGE,
	FILE_TYPE_ALL,
}E_FILE_TYPE;

/* �ļ���Ŀ��ѯ�ṹ*/
typedef struct 
{
	unsigned  char  ucType;   //E_FILE_TYPE
	unsigned  char  aucReserved[3];
	unsigned  int	uiStartDate; 		/*0��7��ʾ�գ�8��15��ʾ�£�16��31λ��ʾ��*/
	unsigned  int	uiStartTime; 		/*0��7λ��ʾ�룬8��15λ��ʾ�֣�16��23λ��ʾʱ*/
	unsigned  int	uiEndDate;		
	unsigned  int	uiEndTime;		
}T_QueryFileBase;

/* �ļ���Ϣ��ѯ�ṹ*/
typedef struct
{
	T_QueryFileBase tBase;
	unsigned  int uiItem;
}T_QueryFileItem;

/* �ļ���Ŀ�ϱ�*/
typedef struct
{
	T_QueryFileBase tQueFileInfo;
	unsigned  int uiCount;
}T_FileCountRsp;

 /* �ļ���Ϣ�ϱ�*/
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
	unsigned  char	ucState; // 1:�̰�,2:����
	unsigned  char	aucReserved[3];
}T_ResetKeyPressState;//�����λ�����µ�״̬���̰��򳤰�

typedef struct
{
	unsigned  char 	ucEnable;    /*�Ƿ�ʹ��*/
	unsigned  char 	ucLevel;      /*LED���ȵȼ�1~7*/ 
	unsigned  char  	aucReserved[2];
	unsigned  short  usStartTime;  /*��ʼʱ�䵥λ:����*/
	unsigned  short  usEndTime;   /*����ʱ�䵥λ:����*/
}T_ParkLedManualItem;

typedef struct
{
	T_ParkLedManualItem atParkLedMan[3];
}T_ParkLedManual; /*LEDǿ�ƿ�����*/

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
	LED_SCREEN_SUB_SINGLE = 0, /*������*/ 
	LED_SCREEN_SUB_TOW,		   /*˫����*/ 
	LED_SCREEN_SUB_FOUR,	  /*�Ĳ���*/
	LED_SCREEN_XW_WHOLE,     /*����һ�����*/
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
	unsigned  char LprResult[16];/*���ƺ��룻������Ϣ���10�����ƺ��룻�����ֶ�����Ϣ����*/
	unsigned  char TotalNum;   // �û��ܳ�λ��
	unsigned  char IdleNum;   // �û�ʣ�೵λ��
	char	  szEndTime[16]; //��������
	unsigned  int Id;        //�˻�id
	unsigned  char Auth[10]; //10�ֽ��ַ�����ͨ��ʮ�����Ƶ��ַ�����ʾ40����ʶλ
	unsigned  char VehType; //0����ʱ��1����Ա��
	unsigned  char MemberValid; //��Ա���Ƿ���Ч��0����ʾ��Ч��1����ʾ��Ч
	unsigned  char Reserved[2]; //����λ
}T_VehResult;


typedef struct
{
	unsigned short Start; //����Ϊ��λ,08:20��ʾ8*60+20=500
	unsigned short End;   //����Ϊ��λ,08:20��ʾ8*60+20=500
}T_Section;

typedef struct
{
	unsigned  char	ucSync; // 0:��ͬ�����������,1:ͬ�����������
	unsigned  char	aucReserved[3];
	T_Section tTable[16];
}T_SectionTable;

typedef struct
{
	unsigned  int  Id;        // �˻�id
	unsigned  char TotalNum;  // �û��ܳ�λ��
	unsigned  char IdleNum;   // �û�ʣ�೵λ��
}T_UserParkInfo;

typedef struct
{
	char	  szPlate[16];		/*���ƺ��룬GB2312*/
	char	  szStartTime[16];  /*��ʼʱ��YYYYMMDDhhmmss*/
	char	  szEndTime[16];    /*����YYYYMMDDhhmmss*/
	unsigned  int Id;           //�˻�id
	unsigned  char TotalNum;    //�û��ܳ�λ��
	unsigned  char IdleNum;     //�û�ʣ�೵λ��
	unsigned  char Auth[12];    //10�ֽ��ַ�����ͨ��ʮ�����Ƶ��ַ�����ʾ40����ʶλ
	unsigned  char Section[6];  //24Сʱʱ��,4��ʮ�����Ƶ��ַ�����ʾ��ʽ�洢16��ʱ�εı�ʶ��Ϣ
}T_LprInfo;

typedef struct 
{
	unsigned  char ucType;         //��E_SendLprMode
	unsigned  char ucConut;        //���δ���ĳ��Ƹ���
	unsigned  char aucReserved[2]; //����λ
	T_LprInfo	  atLprResult[10]; //������Ϣ
}T_SendLprByMessEx;

typedef struct  
{
	unsigned  char ucResult; //��ѯ�Ľ����0Ϊδ�ҵ��ó��ƣ�1Ϊ�ɹ��ҵ��ó���
	unsigned  char aucReserved[3];
	T_LprInfo	  tLprResult;
}T_RspLprResultEx;

typedef enum
{
	PARK_BLUE_PLATE = 0x01,   /*����*/
	PARK_YELLOW_PLATE = 0x02, /*����*/
	PARK_BLACK_PLATE = 0x04, /*����*/
	PARK_JIAOLIAN_PLATE = 0x08,/*������*/
	PARK_JINGCHE_PLATE = 0x10, /*����*/
	PARK_WUJING_PLATE = 0x20, /*�侯��*/
	PARK_JUNCHE_PLATE = 0x40, /*����*/
	PARK_GANGAO_PLATE = 0x80, /*�۰���*/
	PARK_SHIGUAN_PLATE = 0x100, /*ʹ����*/
	PARK_NEWENERGY_PLATE = 0x200, /*����Դ��*/
	PARK_MINHANG_PLATE = 0x400, /*����*/
	PARK_MOTOR_PLATE = 0x800, /*Ħ�г���*/
}E_DetectPlateType;

typedef struct
{
	unsigned short usTypeBit;
}T_DetectPlateType;

typedef struct
{
	unsigned char	ucEnable; //�����ʹ��; 0:��ʹ�� 1:ʹ��
	unsigned char   ucBLCEnable;//˳��ⱳ�ⲹ��      0:��ʹ�� 1:ʹ��
	unsigned char	ucType;//���������  0:��Э�����  1:��׼���
	unsigned char	ucFusetime;//�ں�ʱ�� ��λms;
	char    ncMacAddr[NET_MAX_MAC_LEN];
	unsigned int	uiIpAddr;//�����ip��ַ��С���ֽ���0��ʾ��Чֵ��
}T_AssCameraSetup;

typedef struct
{
	unsigned char  ucStatus;//0 ��ʾ�ж� 1 ��������
	unsigned char  ucReserved[3];
}T_AssCameraStatus;

typedef struct
{
	unsigned int  uiIPAddress;//�����ip��ַ��С���ֽ���0��ʾ��Чֵ��
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
	unsigned int  uiIpAddr[MAX_ASS_SEARCH];//�����ip��ַ��С���ֽ���0��ʾ��Чֵ��
	char    ncMacAddr[MAX_ASS_SEARCH][NET_MAX_MAC_LEN];
}T_AssCameraIpSearch;

typedef struct
{
	int  level;    //�ع�ȼ� [0,8]
	unsigned int  leastTime;//�Զ��ع�ʱ�����޻��ֶ��ع�ʱ�䣬��λ΢��
	unsigned int  mostTime;//�Զ��ع�ʱ�����ޣ���λ΢��
}T_XMExposureCfg;

typedef struct
{
	int  gain;//�Զ���������(�Զ���������)��̶�����ֵ
	int  autoGain;//�Զ������Ƿ����ã�0:������  1:����
}T_XMGainCfg;

typedef struct
{
	unsigned char  ucBright;
	unsigned char  ucNight_nfLevel;
	unsigned char  ucDay_nfLevel;
	unsigned char  ucDayNightColor;
	unsigned int   uiDebugCmd; //SDK ���� 2
	T_XMExposureCfg xmExposureCfg;
	T_XMGainCfg     xmGainCfg;
}T_AssCameraParam;

typedef struct
{
	char  acDate[12]; /* ������YYYYMMDD ,���Ϊ"00000000"��ʾ���������� */
}T_ExpDate;

typedef struct
{
	unsigned char ucEncId;   /* ���Ϊ0��Ϊ������,���Ϊ��������Ϊ����*/
	unsigned char aucReserved[3]; 
	char acSignatrue[20];     /*�ӿ�ǩ���ַ���*/
}T_UserSignatrue;

typedef struct
{
	char acOldPwd[32]; /*AES 128λ�㷨ʹ��������,���ܽӿ�ǩ���ַ���,��base64*/
	char acNewPwd[32]; /*AES 128λ�㷨ʹ��������,�����������ַ���,��base64*/
}T_ModifyEncPwd;

typedef struct
{
	unsigned char ucEncId;   /* ���Ϊ0��Ϊ������,���Ϊ��������Ϊ����*/
	unsigned char aucReserved[3]; 
	char acPwd[32];  /*AES 128λ�㷨ʹ������,���ܽӿ�ǩ���ַ���,��base64*/
}T_EncEnable;

typedef struct
{
	unsigned int iId;
	unsigned char szFilePath[256];
}T_GetImageById;

typedef enum
{
	BIT_MOD_VEH_PLATE = 0x01,/*������ʾ*/
	BIT_MOD_VEH_WELCOME = 0x02,/*��ӭ����ʾ*/
	BIT_MOD_VEH_PAY = 0x04,  /*ͣ��������ʾ*/
	BIT_MOD_VEH_TIME = 0x08, /*ͣ��ʱ����ʾ*/
	BIT_MOD_VEH_PERIOD = 0x10, /*������Ч����ʾ*/
	BIT_MOD_TIME = 0x20,/*ʱ����ʾ����ʽ:XXXX��XX��XXʱXX��*/
	BIT_MOD_VEH_LEFT = 0x40,/*ʣ��ͣ��λ��ʾ*/
	BIT_MOD_CUSTOM = 0x80,  /*�Զ���������ʾ*/
	BIT_MOD_VEH_USERTYPE = 0x100,  /*ͣ���û�����*/
	BIT_MOD_MAX,
}E_LedModeBit;

typedef struct
{
	unsigned char		ucEnable;
	unsigned char		ucInterval;//ʱ����  s��
	unsigned char		ucLedLine;//˫����������1������2;
	unsigned char   	ucLedcolor;//E_LED_COLOR
	unsigned short  	usModeBit;//(�������λ����)
	unsigned char  		ucReserved[2];
	char				acContent[32]; //GB2312���Զ���ģʽ��Ч
}T_LedLineSetup;

typedef enum 
{ 
	LED_SCREEN_HORIZONTAL = 0, /*����*/ 
	LED_SCREEN_VERTICAL,	 /*����*/ 
	LED_SCREEN_STYLE_MAX 
}E_LedScreenStyle;

typedef struct
{
	unsigned char    ucAudioEnable;   /*�����Ƿ�ʹ��*/
	unsigned char    ucScreenStyle;   /* ��ʾ�����ͺ������E_LedScreenStyle*/
	unsigned char    ucLedSubType;  //E_LedScreenSubType			
	unsigned char    ucReserved;
	T_LedLineSetup   atSubLedInIdle[MAX_LED_COUNT];//��ڿ���
	T_LedLineSetup   atSubLedInBusy[MAX_LED_COUNT];//���æ  
	T_LedLineSetup   atSubLedOutIdle[MAX_LED_COUNT];//���ڿ���
	T_LedLineSetup   atSubLedOutBusy[MAX_LED_COUNT];//����æ
}T_SLedSetup;

typedef struct
{
	unsigned char	   ucmode;   //0:���У�1:���У�2:����
	unsigned char 	   uc_tmp_in;//��ʱ���볡��0 ��ӭ����  1 ף������  ����
	unsigned char      uc_tmp_out;// ��ʱ��������0 һ·˳��  1 һ·ƽ��
	unsigned char 	   uc_vip_in;//���⳵�볡��0 ��ӭ����  1 ��ӭ�ؼ�
	unsigned char      uc_vip_out;//���⳵������0 һ·˳��  1 ����ƽ��
	unsigned char 	   ucSleeptimes;// ���̵��ӳ� 0-255��
	unsigned char	   ucvolume;//������С 0 - 8 ��С����
	unsigned char      ucReserved[5];
}T_SLedSetup_tfg;

typedef struct{	
	unsigned short	usdaytime;		//�������ʱ��	
	unsigned short	usnighttime;	//�������ʱ��	
	unsigned char	ucdayvolume;	//��������(0-9)
	unsigned char	ucnightvolume;	//��������(0-9)	
	unsigned char   ucReserved[2];
}T_LedVocieSetup;

typedef struct{	
	unsigned char  ucColortype;  //ÿ����ʾ����ɫ���� 1/�� 2/�� 3�� 
	unsigned char  ucReserved[3];
}T_LedLineextSetup;

typedef struct
{
	unsigned char	  InswitchOvertime;//���ÿ�բʱ�̵Ƴ�ʱת���ʱ�䣨5-20S�� Ĭ�� 10S
	unsigned char	  OutswitchOvertime;//���ÿ�բʱ�̵Ƴ�ʱת���ʱ�䣨5-20S�� Ĭ�� 10S
	unsigned char     ucReserved[2];
	T_LedLineextSetup Inatlineext[MAX_LED_COUNT];
	T_LedLineextSetup Outatlineext[MAX_LED_COUNT];
	T_LedVocieSetup  InatVolumeInfo;//��������
	T_LedVocieSetup  OutatVolumeInfo;//��������
}T_SLedSetupExt;

typedef struct
{
	unsigned char ucnotin;//0 ���г�����   1  ���г���ֹ
	char uaReserved[7];
}T_XWCarinParam; 

typedef enum
{
	E_T4G_NoYJ = 0,//��4Gģ��
	E_T4G_NoPPPoe,//δ���ųɹ�
	E_T4G_PPPoeOk,//���ųɳɹ���δ����
	E_T4G_InternetOk//���ųɹ��������ɹ� 
}E_T4G_StatuList;

typedef struct
{
	unsigned char ucStatus;//4G����״̬ ��� E_T4G_StatuList
	unsigned char ucSignalLevel;//�ź�ǿ�� 0 �� 1-5  �ź�1-5��
	char uaReserved[14];
}T_T4GInfoParam;

//GB28181����
#define SIP_MAX_ID_LEN 	32
#define MAX_NAME_LEN 	32
#define RESERVED_LEN 	128

typedef struct
{
	char    szSIPdomain[SIP_MAX_ID_LEN];//������
	char  	szSIPserverId[SIP_MAX_ID_LEN];//������sip id
	char  	szSIPdeviceId[SIP_MAX_ID_LEN];//�豸sip id
	char  	szSIPalarmId[SIP_MAX_ID_LEN];//����id
	char  	szDeviceName[MAX_NAME_LEN];//�豸�����ͺ�
	char  	szServerIPAddress[16];	//������ip
	char	usServerPort[16];//�������˿�
	char	usDevicePort[16];//�豸�˿�
	unsigned int 	usRegExpiration;//ע�����ʱ��
	unsigned int 	usHeartBeatInterval;//�������ʱ��
	char 	szAuthName[MAX_NAME_LEN];//��֤�û���
	char 	szAuthPwd[MAX_NAME_LEN];//��֤����
	//char		szReserved[RESERVED_LEN];//��չ����
}T_GB28181_sipSetup;

typedef struct
{
	char		ncEncodeFormat;//�����ʽ1��MPEG��4��2��H��264��3��SVAC��4��3GP��
	char		ncResolution;//�ֱ���1��QCIF��2��CIF��3��4CIF��4��D1��5��720P��6��1080P��1��
	char		ncFps;//֡��o��99
	char		ncRateType;//��������1���̶�����(CBR)��2���ɱ�����(VBR)��
	int			ncRate;//���ʣ�o��100000(��1��ʾ1 kbps)
	//char		szReserved[8];//��չ����

}T_GB28181_MediaSetup;

typedef struct 
{
	unsigned char 	ucEnabled;//gb28181ģ��ʹ��
	unsigned char   ucReserved[3];
	char 	szDeviceIP[16];//����IP
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
	char		szPMod[32];/* ���ò�Ʒ�ͺ�*/
}T_ProduceMod;


typedef struct
{
	unsigned char   ucIndex;
	unsigned char   ucOpt;         /*1 ��,0 �ر�*/
	unsigned char   ucReserved[2];
}T_RS485Opt;

typedef struct
{
	unsigned char   ucMerge;
	unsigned char   ucReserved[3];
}T_AssMerge;


typedef enum
{
	PS_TYPE_GENERAL = 0,  /*��ͨ��λ*/
	PS_TYPE_SPECIAL, 	  /*���⳵λ*/
	PS_TYPE_MAX,
}E_PSType;

typedef struct 
{ 
	unsigned char ucEnable; /*�Ƿ�ʹ��*/ 
	unsigned char ucPSType; /*��λ����:0����ͨ��λ 1�����⳵λ*/ 
	unsigned char uclampIndex; /*0:���õƣ�1:���õ�1    2:���õ�2    3:���õ�3*/
	unsigned char aucReserved;
	unsigned char acPSNo[16]; /*��λ���*/ 
	T_Point tPsRect[4]; /*��λ����*/ 
}T_PSAttrItem;  

typedef struct
{
	unsigned char 	ucPsNum;   /*ͣ��λ��*/
	unsigned char   ucSnaptype;/*��λ���޳�״̬��Ϊ�г�״̬ʱ ץͼ����0:ץ��ȫ��ͼ 1:ץ�ľֲ�ͼ*/
	unsigned char	aucReserved[2];  
	T_PSAttrItem atPsAttr[3]; 
}T_ParkSpaceAttr;

typedef enum
{
	PS_STATUS_NOCAR = 0, /*�޳�*/
	PS_STATUS_HAVECAR,   /*�г�*/
	PS_STATUS_PRESSLINE, /*ѹ��*/
	PS_STATUS_SPECIAL,   /*���⳵λ*/
	PS_STATUS_MAX,
}E_PSStatus;

typedef enum
{
	LAMP_COLOR_OFF = 0,		//��
	LAMP_COLOR_RED,			//��	
	LAMP_COLOR_GREEN,		//��
	LAMP_COLOR_YELLOW,		//��
	LAMP_COLOR_BLUE,		//��
	LAMP_COLOR_MAGENTA,		//Ʒ��
	LAMP_COLOR_DARKGREEN,	//��
	LAMP_COLOR_WHITE, 		//��ɫ
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
	unsigned char ucFlicker;	//0:����˸1:��˸
	unsigned char ucLampColor;	//E_LampColor
	unsigned char ucReserved;
}T_LampControlPara;

typedef struct
{
	unsigned char ucLCMode;  /*�ƿ�ģʽ*/
	unsigned char aucReserved[3];
	T_LampControlPara atInternalPara[PS_STATUS_MAX];    /*���õƿ���*/
	T_LampControlPara atExternalPara[3][PS_STATUS_MAX]; /*���õƿ���*/
}T_LampControl;

typedef struct 
{ 
	unsigned char    ucEnable; 
	unsigned char    ucFlicker;	//0:����˸1:��˸ 
	unsigned char    ucLampColor;//E_LampColor 
	unsigned char    ucIndex; /*0:���õƣ�1:���õ�1 2:���õ�2 3:���õ�3*/ 
}T_NetLampControl;

typedef struct
{
	unsigned char   ucMirror;  /*���� 0���� 1����*/
	unsigned char  	ucFlip;    /*��ת 0���� 1����*/
	unsigned char 	aucReserved[2];
}T_ImageAdjust;


typedef struct
{
	unsigned char	spaceState;             /*��ǰ��λ��״̬:0:�޳�   1:�г�  */
	unsigned char   auReserverd[3];
	char            szLprResult[16];     //���ƺ���
}T_PResetInfo;

typedef struct
{
	unsigned char 	ucNum;   /*ͣ��λ��*/
	unsigned char         ucILampValue;/*���õ���ɫ*/
	unsigned char        auReserverd[2];
	T_PResetInfo pInfo[3];
}T_RspParkingInfo;

typedef enum
{
	FILE_SEND_SUCC = 0, /* �ļ����ͳɹ�*/
	FILE_MD5_FAILED = 1, /* �ļ�md5У��ʧ��*/
	FILE_VERSION_LOW,   /* �ļ��汾����*/
	FILE_ACCESS_FAILED, /* �ļ������Է���*/
	FILE_HW_NO_MATCH,   /* Ӳ���汾��ƥ��*/
	FILE_TYPE_NO_MATCH, /*�ļ����Ͳ�ƥ��*/
	CMD_INVALID_PARAM,   /*������Ч���� */
}E_FileRecvState;

typedef struct
{
	unsigned char 	ucState;  /* E_FileRecvState*/
	unsigned char	acReserved[3];
}T_FileRecvResult;

typedef struct
{
	char aucIp[32];  //Ŀ�������IP
	unsigned short usPort;  // Ŀ��������˿�
	unsigned char ucDevNo;  // Ŀ���������
	unsigned char ucParkNo; // ͣ����UID
	unsigned char ucCamNo; // ���UID
	unsigned char ucEnable; /* 1 ����0 ������*/
	unsigned char ucAck;   /* 0 ����֤ 1 ��֤*/
	unsigned char ucReserved;
}T_PushTargetSetup;

typedef struct
{
	unsigned char	ucEnable;  // �����Ƿ���
	unsigned char	ucSSLEnable;  // ssl �Ƿ���
	unsigned short	usPort;    // �������˿�
	char			szIpAddr[16];  // ������IP
	unsigned short	usSSLPort;  // ssl �˿�
	unsigned short	usTimeout;  //��ʱ����
	unsigned char	ucDevReg;  // �豸ע��
	char			szRegAddr[127];  //  �豸ע���ַ
	unsigned char	ucPlatePush; // ���ͳ���ʶ����
	char			szPPushAddr[127]; // ���ͳ���ʶ������ַ
	unsigned char	ucBigPic;  //  ����ͼƬ
	unsigned char	ucSmallPic; //  ����Сͼ
	unsigned char	ucGpioPush; // ���Ͷ˿ڴ�����Ϣ
	char			szGPushAddr[129]; // ���Ͷ˿ڴ�����Ϣ��ַ
	unsigned char	ucSerialPush;  // ���ʹ�������
	char			szSPushAddr[63];  // ���ʹ������ݵ�ַ
	char			szWebaddr[64];  // WEB������IP ���� ����
}T_HttpPushSetup;

typedef struct
{
	unsigned char	ucEnable;  // �����Ƿ���
	unsigned char	ucBigPic;  //  ��η���ʱ���ʹ�ͼƬ
	unsigned char	ucSmallPic; //  ��η���ʱ����Сͼ
	unsigned char	Reserverd[5]; 
	unsigned int	uiInterval;//��η���ʱ���ʱ�� S
	unsigned int	uiMaxtime;//��η��͵����ʱ�� S
}T_HttpSetupExt;

typedef struct
{
	unsigned int	uiIpAddr;/* IP��ַ*/
	unsigned short	uwPort;
	char			acReserved[18];
}T_QyTInfo;

typedef struct
{
	T_QyTInfo info[5];
}T_TcpClientInfo;

typedef struct
{
	unsigned int uiRuntime;   /*ϵͳ����ʱ��,��λСʱ*/
}T_DevRunTime;

//typedef struct
//{
//	unsigned char 	ucEnable;    /*�Ƿ�ʹ��0:disable 1:enable*/
//	unsigned char 	ucLevel;      /*LED���ȵȼ�1~7*/
//	unsigned char  	aucReserve[2];
//	unsigned short  	usStartTime;  /*��ʼʱ�䵥λ:����0~1440*/
//	unsigned short  	usEndTime;   /*����ʱ�䵥λ:����0~1440*/
//}T_ParkLedManualItem;

typedef struct
{
	T_ParkLedManualItem atParkOpenMan[3];
}T_ParkOpenManual; /*ǿ�ƿ�բ����*/

/**********************************************************************
* �������ƣ�Net_RebootCamera
* ��������������������Ͽ������֮�������
* ���������tHandle ������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_RebootCamera(DCHANDLE tHandle);


/**********************************************************************
* �������ƣ�Net_TimeSetup
* �������������������ʱ��
* ���������tHandle ������
*			ptTimeSetup ʱ������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_TimeSetup(DCHANDLE tHandle,  T_DCTimeSetup *ptTimeSetup);

/**********************************************************************
* �������ƣ�Net_QueryTimeSetup
* ������������ѯ���ʱ��
* ���������tHandle ������
* ���������ptTimeSetup ʱ�����ý��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryTimeSetup(DCHANDLE tHandle,  T_DCTimeSetup *ptTimeSetup);

/**********************************************************************
* �������ƣ�Net_SntpSetup
* ��������������ָ�������sntp��Ϣ
* ���������tHandle ������
*           ptSntpSetup sntp����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SntpSetup(DCHANDLE tHandle,  T_SNTPSetup *ptSntpSetup);

/**********************************************************************
* �������ƣ�Net_QuerySntpSetup
* ������������ѯ�����sntp��Ϣ
* ���������tHandle ������
* ���������ptSntpSetup sntp���ý��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QuerySntpSetup(DCHANDLE tHandle,  T_SNTPSetup *ptSntpSetup);

/**********************************************************************
* �������ƣ�Net_NETSetup
* �������������������������Ϣ
* ���������tHandle ������
*			ptNetSetup �豸��Ϣ����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_NETSetup(DCHANDLE tHandle,  T_NetSetup *ptNetSetup);

/**********************************************************************
* �������ƣ�Net_QueryNETSetup
* ������������ѯ�����������Ϣ
* ���������tHandle ������
* ���������ptNetSetup �豸��Ϣ���
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryNETSetup(DCHANDLE tHandle,  T_NetSetup *ptNetSetup);

/**********************************************************************
* �������ƣ�Net_QueryMACSetup
* ������������ѯ���MAC��ַ
* ���������tHandle ������
* ���������ptMacSetup �豸��Ϣ���ý��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryMACSetup(DCHANDLE tHandle,  T_MACSetup *ptMacSetup);

/**********************************************************************
* �������ƣ�Net_AcSyncSetup
* ��������������ָ������Ľ���ͬ����Ϣ
* ���������tHandle ������
*           ptAcSyncSetup ������ͬ������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_AcSyncSetup(DCHANDLE tHandle,  T_DCAcSyncSetup *ptAcSyncSetup);

/**********************************************************************
* �������ƣ�Net_QueryAcSyncSetup
* ������������ѯ����Ľ���ͬ����Ϣ
* ���������tHandle ������
* ���������ptAcSyncSetup ������ͬ������ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryAcSyncSetup(DCHANDLE tHandle, T_DCAcSyncSetup *ptAcSyncSetup);

/**********************************************************************
* �������ƣ�Net_ImageQualitySetup
* ��������������ָ�������ͼ��������Ϣ
* ���������tHandle ������
*           ptImageCodec ͼ��������1��100
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ImageQualitySetup(DCHANDLE tHandle,T_ImageCodec *ptImageCodec);

/**********************************************************************
* �������ƣ�Net_QueryImageQualitySetup
* ������������ѯ�����ͼ��������Ϣ
* ���������tHandle ������   
* ���������ptImageCodec  ͼ���������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryImageQualitySetup(DCHANDLE tHandle, T_ImageCodec *ptImageCodec);

/**********************************************************************
* �������ƣ�Net_VideoSubtitleSetup
* ��������������ָ���������Ƶ��Ļ��Ϣ
* ���������tHandle ������
*           ptSubtitle ��Ƶ��Ļ��Ϣָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_VideoSubtitleSetup(DCHANDLE tHandle, T_Subtitle *ptSubtitle);

/**********************************************************************
* �������ƣ�Net_QueryVideoSubtitleSetup
* ������������ѯ�������Ƶ��Ļ��Ϣ
* ���������tHandle ������
*			ptSubtitle->ucIndex ��Ƶ��Ļ�������
* ���������ptSubtitle ��Ƶ��Ļ��Ϣָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryVideoSubtitleSetup(DCHANDLE tHandle, T_Subtitle *ptSubtitle);

/**********************************************************************
* �������ƣ�Net_QueryImageById
* ��������������ͼƬID��ȡͼƬFTP·��
* ���������tHandle ������
*			ptGetImageById->iId ͼƬID
* ���������ptGetImageById ͼƬ��Ϣ
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryImageById(DCHANDLE tHandle, T_GetImageById *ptGetImageById);

/**********************************************************************
* �������ƣ�Net_SaveImageById
* ��������������ͼƬID��ȡͼƬ�����浽����
* ���������tHandle ������
*			iId ͼƬID
*			szFileSavePath ͼƬ����·��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SaveImageById(DCHANDLE tHandle, int iId, char *szFileSavePath);

/**********************************************************************
* �������ƣ�Net_SnapParaSetup
* ��������������ָ�������ץ�Ĳ���
* ���������tHandle ������
*           ptSnapParaSetup ץ�Ĳ���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SnapParaSetup(DCHANDLE tHandle, T_DCSnapParaSetup *ptSnapParaSetup);

/**********************************************************************
* �������ƣ�Net_QuerySnapParaSetup
* ������������ѯ�����ץ�Ĳ���
* ���������tHandle ������
*           ptSnapParaSetup->ucGroupId ָ����ID
* ���������ptSnapParaSetup ץ�Ĳ���ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QuerySnapParaSetup(DCHANDLE tHandle,T_DCSnapParaSetup *ptSnapParaSetup);

/**********************************************************************
* �������ƣ�Net_VideoParaSetup
* ��������������ָ���������Ƶ����
* ���������tHandle ������
*           ptVideoParaSetup��Ƶ����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_VideoParaSetup(DCHANDLE tHandle, T_VideoParaSetup *ptVideoParaSetup);

/**********************************************************************
* �������ƣ�Net_QueryVideoParaSetup
* ������������ѯָ�������ץ�Ĳ���
* ���������tHandle ������
* ���������ptVideoParaSetup ��Ƶ����ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryVideoParaSetup(DCHANDLE tHandle, T_VideoParaSetup *ptVideoParaSetup);

/**********************************************************************
* �������ƣ�Net_AssVideoParaSetup
* �������������ø��������Ƶ����
* ���������tHandle ������
*           ptVideoParaSetup��Ƶ����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_AssVideoParaSetup(DCHANDLE tHandle, T_VideoParaSetup *ptVideoParaSetup);

/**********************************************************************
* �������ƣ�Net_QueryAssVideoParaSetup
* ������������ѯ���������Ƶ����
* ���������tHandle ������
* ���������ptVideoParaSetup ��Ƶ����ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryAssVideoParaSetup(DCHANDLE tHandle, T_VideoParaSetup *ptVideoParaSetup);

/**********************************************************************
* �������ƣ�Net_ViceVideoCodeSetup
* ���������������������Ƶ�������
* ���������tHandle ������
*           ptVideoCodeSetup ��Ƶ����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ViceVideoCodeSetup(DCHANDLE tHandle, T_VideoCodeSetup *ptVideoCodeSetup);

/**********************************************************************
* �������ƣ�Net_QueryViceVideoCodeSetup
* ������������ѯ�������Ƶ�������
* ��������� tHandle ������
* ��������� ptVideoCodeSetup ��Ƶ����ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryViceVideoCodeSetup(DCHANDLE tHandle, T_VideoCodeSetup *ptVideoCodeSetup);

/**********************************************************************
* �������ƣ�Net_DynamicCodeSetup
* ��������������ָ������Ķ�̬��Ƶ����
* ���������tHandle ������
*           ptDynamicCode ��̬��Ƶ����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_DynamicCodeSetup(DCHANDLE tHandle, T_DynamicCode *ptDynamicCode);

/**********************************************************************
* �������ƣ�Net_QueryDynamicCodeSetup
* ������������ѯָ������Ķ�̬��Ƶ����
* ��������� tHandle ������
* ��������� ptDynamicCode ��̬��Ƶ����ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryDynamicCodeSetup(DCHANDLE tHandle, T_DynamicCode *ptDynamicCode);

/**********************************************************************
* �������ƣ�Net_QueryCameraSpec
* ������������ѯ������
* ���������tHandle ������
* ���������ptSpec ����������ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryCameraSpec(DCHANDLE tHandle, T_DCSpec  *ptSpec);

/**********************************************************************
* �������ƣ�Net_DevInfoSetup
* ������������������豸��Ϣ
* ���������tHandle ������
*           ptDevSetup ����豸��Ϣָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_DevInfoSetup(DCHANDLE tHandle,  T_DevSetup *ptDevSetup);

/**********************************************************************
* �������ƣ�Net_QueryDevSetup
* ������������ѯ����豸��Ϣ
* ���������tHandle ������
* ���������ptDevSetup ����豸��Ϣָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryDevSetup(DCHANDLE tHandle, T_DevSetup *ptDevSetup);

/**********************************************************************
* �������ƣ�Net_FTPSetup
* �����������������FTP��Ϣ
* ���������tHandle ������
*           ptFtpSetup ���FTP��Ϣָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_FTPSetup(DCHANDLE tHandle,  T_FTPSetup *ptFtpSetup);

/**********************************************************************
* �������ƣ�Net_QueryFTPSetup
* ������������ѯ���FTP��Ϣ
* ���������tHandle ������
* ���������ptFtpSetup ���FTP��Ϣָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API  E_ReturnCode _stdcall Net_QueryFTPSetup(DCHANDLE tHandle,T_FTPSetup *ptFtpSetup);

/**********************************************************************
* �������ƣ�Net_AssistantIpncSetup
* �������������ø������������Ϣ
* ���������tHandle ������
*           ptAssistantIpnc �������������Ϣָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_AssistantIpncSetup(DCHANDLE tHandle,  T_AssistantIpnc *ptAssistantIpnc);

/**********************************************************************
* �������ƣ�Net_QueryAssistantIpncSetup
* ������������ѯ�������������Ϣ
* ���������tHandle ������
* ���������ptAssistantIpnc �������������Ϣָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryAssistantIpncSetup(DCHANDLE tHandle,  T_AssistantIpnc *ptAssistantIpnc);

/**********************************************************************
* �������ƣ�Net_MessegerSetup
* �������������ú�̨ͨѶ���ò���
* ���������tHandle ������
*           ptMessenger ��̨ͨ�����ò���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_MessegerSetup(DCHANDLE tHandle,  T_Messenger *ptMessenger);

/**********************************************************************
* �������ƣ�Net_QueryMessegerSetup
* ������������ѯ��̨ͨѶ���ò���
* ���������tHandle ������
* ���������ptMessenger ��̨ͨ�����ò���ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryMessegerSetup(DCHANDLE tHandle,  T_Messenger *ptMessenger);

/**********************************************************************
* �������ƣ�Net_SigControlPortSetup
* ���������������źſ���ͨ�Ŷ˿ڲ���
* ���������tHandle ������
*           ptSigControlPort �źŻ����ƶ˿ڲ���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SigControlPortSetup(DCHANDLE tHandle,  T_SigControlPort *ptSigControlPort);

/**********************************************************************
* �������ƣ�Net_QuerySigControlPortSetup
* ������������ѯ�źſ���ͨ�Ŷ˿ڲ���
* ���������tHandle ������
* ���������ptSigControlPort �źŻ����ƶ˿ڲ���ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QuerySigControlPortSetup(DCHANDLE tHandle,  T_SigControlPort *ptSigControlPort);

/**********************************************************************
* �������ƣ�Net_CaptureSetup
* ���������������¼�ץ�Ĳ���
* ���������tHandle ������
*           ptEventCapturePara ץ��λ�ò���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_CaptureSetup(DCHANDLE tHandle,  T_EventCapturePara *ptEventCapturePara);

/**********************************************************************
* �������ƣ�Net_QueryCaptureSetup
* ������������ѯ�¼�ץ�Ĳ���
* ���������tHandle ������
* ���������ptEventCapturePara ץ��λ�ò���ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryCaptureSetup(DCHANDLE tHandle,T_EventCapturePara *ptEventCapturePara);

/**********************************************************************
* �������ƣ�Net_RoadLaneBasicSetup
* �������������û����������ò���
* ���������tHandle ������
*           ptRoadLaneBasicSetup �������ò���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_RoadLaneBasicSetup(DCHANDLE tHandle,  T_RoadLaneBasicSetup *ptRoadLaneBasicSetup);

/**********************************************************************
* �������ƣ�Net_QueryRoadLaneBasicSetup
* ������������ѯ�����������ò���
* ���������tHandle ������
* ���������ptRoadLaneBasicSetup �������ò���ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryRoadLaneBasicSetup(DCHANDLE tHandle,T_RoadLaneBasicSetup *ptRoadLaneBasicSetup);

/**********************************************************************
* �������ƣ�Net_RoadLaneExternSetup
* ����������������չ�������ò���
* ���������tHandle ������
*           ptRoadLaneExtendSetup ��չ�������ò���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_RoadLaneExternSetup(DCHANDLE tHandle,  T_RoadLaneExtendSetup *ptRoadLaneExtendSetup);

/**********************************************************************
* �������ƣ�Net_QueryRoadLaneExternSetup
* ������������ѯ��չ�������ò���
* ���������tHandle ������
* ���������ptRoadLaneExtendSetup ��չ�������ò���ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryRoadLaneExternSetup(DCHANDLE tHandle, T_RoadLaneExtendSetup *ptRoadLaneExtendSetup);

/**********************************************************************
* �������ƣ�Net_VideoCodeSetup
* ����������������Ƶ�������
* ���������tHandle ������
*           ptVideoCodec ��Ƶ�������ָ��
* ����������� 
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_VideoCodeSetup(DCHANDLE tHandle, T_VideoCodeSetup *ptVideoCodeSetup);

/**********************************************************************
* �������ƣ�Net_QueryVideoCodeSetup
* ������������ѯ��Ƶ�������
* ���������tHandle ������
* ���������ptVideoCodec ��Ƶ�������ָ�� 
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryVideoCodeSetup(DCHANDLE tHandle, T_VideoCodeSetup *ptVideoCodeSetup);

/**********************************************************************
* �������ƣ�Net_QueryRS485Setup
* ��������������RS485���ò���
* ���������tHandle ������
*           ptRs485Setup RS485���ò���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_RS485Setup(DCHANDLE tHandle,  T_RS485Setup *ptRs485Setup);

/**********************************************************************
* �������ƣ�Net_QueryRS485Setup
* ������������ѯRS485���ò���
* ���������tHandle ������
* ���������ptRs485Setup RS485���ò���ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryRS485Setup(DCHANDLE tHandle,  T_RS485Setup *ptRs485Setup);

/**********************************************************************
* �������ƣ�Net_ParkRS485Setup
* ��������������ͣ����RS485���ò���
* ���������tHandle ������
*           ptRs485Setup ͣ����RS485���ò���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ParkRS485Setup(DCHANDLE tHandle,  T_ParkRS485Setup *ptRs485Setup);

/**********************************************************************
* �������ƣ�Net_QueryParkRS485Setup
* ������������ѯͣ����RS485���ò���
* ���������tHandle ������
* ���������ptRs485Setup ͣ����RS485���ò���ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryParkRS485Setup(DCHANDLE tHandle,  T_ParkRS485Setup *ptRs485Setup);

/**********************************************************************
* �������ƣ�Net_VehicleVAFunSetup
* �������������ó���ʶ�����ò���
* ���������tHandle ������
*           ptVehicleVAFunSetup	����ʶ�����ò���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_VehicleVAFunSetup(DCHANDLE tHandle,  T_VehicleVAFunSetup *ptVehicleVAFunSetup);

/**********************************************************************
* �������ƣ�Net_QueryVehicleVAFunSetup
* ������������ѯ����ʶ�����ò���
* ���������tHandle ������
* ���������ptVehicleVAFunSetup	����ʶ�����ò���ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryVehicleVAFunSetup(DCHANDLE tHandle,  T_VehicleVAFunSetup *ptVehicleVAFunSetup);

/**********************************************************************
* �������ƣ�Net_VehicleVAFunSetupEX
* �������������ó���ʶ��������չ����
* ���������tHandle ������
*           ptVehicleVAFunSetupEX	����ʶ��������չ����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_VehicleVAFunSetupEX(DCHANDLE tHandle,  T_VehicleVAFunSetupEX *ptVehicleVAFunSetupEX);

/**********************************************************************
* �������ƣ�Net_QueryVehicleVAFunSetupEX
* ������������ѯ����ʶ��������չ����
* ���������tHandle ������
* ���������ptVehicleVAFunSetupEX	����ʶ��������չ����ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryVehicleVAFunSetupEX(DCHANDLE tHandle,  T_VehicleVAFunSetupEX *ptVehicleVAFunSetupEX);

/**********************************************************************
* �������ƣ�Net_InvalidLprLevelSetup
* ��������������α���ƴ���ȼ�����
* ���������tHandle ������
*           ptInvalidLprLevel	α���ƴ���ȼ�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_InvalidLprLevelSetup(DCHANDLE tHandle,  T_InvalidLprLevel *ptInvalidLprLevel);

/**********************************************************************
* �������ƣ�Net_QueryInvalidLprLevelSetup
* ������������ѯα���ƴ���ȼ�����
* ���������tHandle ������
* ���������ptInvalidLprLevel	α���ƴ���ȼ�����ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryInvalidLprLevelSetup(DCHANDLE tHandle,  T_InvalidLprLevel *ptInvalidLprLevel);

/**********************************************************************
* �������ƣ�Net_PicOsdSetup
* �������������ó�ͼƬ��Ļ���ò���
* ���������tHandle ������
*           ptPicOsdSetup ��ͼƬ��Ļ���ò���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_PicOsdSetup(DCHANDLE tHandle,  T_PicOsdSetup *ptPicOsdSetup);

/**********************************************************************
* �������ƣ�Net_QueryPicOsdSetup
* ������������ѯ��ͼƬ��Ļ���ò���
* ���������tHandle ������
* ���������ptPicOsdSetup ��ͼƬ��Ļ���ò���ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryPicOsdSetup(DCHANDLE tHandle,  T_PicOsdSetup *ptPicOsdSetup);

/**********************************************************************
* �������ƣ�Net_StorageSetup
* �������������ô�����Ϣ���ò���
* ���������tHandle ������
*           ptStorageSetup ������Ϣ���ò���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode  _stdcall Net_StorageSetup(DCHANDLE tHandle,  T_StorageSetup *ptStorageSetup);

/**********************************************************************
* �������ƣ�Net_QueryStorageSetup
* ������������ѯ������Ϣ���ò���
* ���������tHandle ������
* ���������ptStorageSetup ������Ϣ���ò���ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryStorageSetup(DCHANDLE tHandle,  T_StorageSetup *ptStorageSetup);
/**********************************************************************
* �������ƣ�Net_DemoSetup
* ������������ʾģʽ���ò���
* ���������tHandle ������
*           ptDemoSetup	   ��ʾģʽ���ò���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_DemoSetup(DCHANDLE tHandle,  T_DemoSetup *ptDemoSetup);

/**********************************************************************
* �������ƣ�Net_QueryDemoSetup
* ������������ѯ��ʾģʽ���ò���
* ���������tHandle ������
* ���������ptSetup  ��ʾģʽ���ò���ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryDemoSetup(DCHANDLE tHandle,  T_DemoSetup *ptSetup);

/**********************************************************************
* �������ƣ�Net_ImageEvSetup
* ��������������˳��������ò���
* ���������tHandle ������
*           ptImageEv ��̬���ò���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ImageEvSetup(DCHANDLE tHandle,  T_ImageEv *ptImageEv);

/**********************************************************************
* �������ƣ�Net_QueryImageEvSetup
* ������������ѯ˳��������ò���
* ���������tHandle ������
* ���������ptImageEv ��̬���ò���ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryImageEvSetup(DCHANDLE tHandle,  T_ImageEv *ptImageEv);

/**********************************************************************
* �������ƣ�Net_ServicePortSetup
* ��������������RTSP/HTTP����˿ڲ���
* ���������tHandle ������
*           ptServicePortSetup	����˿ڲ���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ServicePortSetup(DCHANDLE tHandle,  T_ServicePortSetup *ptServicePortSetup);

/**********************************************************************
* �������ƣ�Net_QueryServicePortSetup
* ��������������RTSP/HTTP����˿ڲ���
* ���������tHandle ������
* ���������ptServicePortSetup	����˿ڲ���ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode  _stdcall Net_QueryServicePortSetup(DCHANDLE tHandle,  T_ServicePortSetup *ptServicePortSetup);

/**********************************************************************
* �������ƣ�Net_ImageCodecSetup
* ��������������ͼ��������
* ���������tHandle ������
*           ptImageCodec ͼ��������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ImageCodecSetup(DCHANDLE tHandle,  T_ImageCodec *ptImageCodec);

/**********************************************************************
* �������ƣ�Net_QueryImageCodecSetup
* ������������ѯͼ��������
* ���������tHandle ������
* ���������ptImageCodec ͼ��������ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryImageCodecSetup(DCHANDLE tHandle,  T_ImageCodec *ptImageCodec);

/**********************************************************************
* �������ƣ�Net_FlashLightSetup
* ����������������������ò���
* ���������tHandle ������
*           ptFlashLightSetup ��������ò���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_FlashLightSetup(DCHANDLE tHandle,  T_FlashLightSetup *ptFlashLightSetup);

/**********************************************************************
* �������ƣ�Net_QueryFlashLightSetup
* ������������ѯ��������ò���
* ���������tHandle ������
* ���������ptFlashLightSetup ��������ò���ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryFlashLightSetup(DCHANDLE tHandle,  T_FlashLightSetup *ptFlashLightSetup);

/**********************************************************************
* �������ƣ�Net_SignalLightSetup
* ���������������źŵ����ò���
* ���������tHandle ������
*           ptSignalLightSetup �źŵ����ò���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SignalLightSetup(DCHANDLE tHandle,  T_SignalLightSetup *ptSignalLightSetup);

/**********************************************************************
* �������ƣ�Net_QuerySignalLightSetup
* ������������ѯ�źŵ����ò���
* ���������tHandle ������
* ���������ptSignalLightSetup �źŵ����ò���ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QuerySignalLightSetup(DCHANDLE tHandle,  T_SignalLightSetup *ptSignalLightSetup);

/**********************************************************************
* �������ƣ�Net_SetSigLightParm
* ���������������źŵ�����
* ���������tHandle ������
			ptSigLightParm  ָ���źŵ����õ�ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SigLightParmSetup(DCHANDLE tHandle,T_SigLightParm *ptSigLightParm);

/**********************************************************************
* �������ƣ�Net_QuerySigLightParm
* ������������ѯ�źŵ�����
* ���������tHandle ������
			ptSigLightParm  ָ���źŵ����õ�ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QuerySigLightParmSetup(DCHANDLE tHandle,T_SigLightParm *ptSigLightParm);

/**********************************************************************
* �������ƣ�Net_LedLightBasicSetup
* ���������������źŵ����ò���
* ���������tHandle ������
*           ptLedLightBasicSetup �źŵ����ò���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_LedLightBasicSetup(DCHANDLE tHandle,  T_LedLightBasicSetup *ptLedLightBasicSetup);

/**********************************************************************
* �������ƣ�Net_QueryLedLightBasicSetup
* ������������ѯ�źŵ����ò���
* ���������tHandle ������
* ���������ptLedLightBasicSetup �źŵ����ò���ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryLedLightBasicSetup(DCHANDLE tHandle,  T_LedLightBasicSetup *ptLedLightBasicSetup);

/**********************************************************************
* �������ƣ�Net_FileUpdate
* ����������ϵͳ����
* ���������tHandle ������
*			ptUpdateSetup ϵͳ��������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_FileUpdate(DCHANDLE tHandle,  T_UpdateSetup *ptUpdateSetup);

/**********************************************************************
* �������ƣ�Net_RegFileUpdateProgress
* ����������ע��ϵͳ�����ļ�����״̬
* ���������tHandle ������
*			pFileSendProgress �ص���������ָ��
*			pUser	�û�˽������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
typedef void (CALLBACK *NET_FileSendProgress) (DCHANDLE tHandle, int nProgress, void* pUser);
NET_API E_ReturnCode _stdcall Net_RegFileUpdateProgress(DCHANDLE tHandle,  NET_FileSendProgress pFileSendProgress, void* pUser);

/**********************************************************************
* �������ƣ�Net_DetectModeSetup
* ������������������ļ��ģʽ
* ���������tHandle ������
*			ptDetectModeSetup ������ģʽ����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_DetectModeSetup(DCHANDLE tHandle,  T_DetectModeSetup *ptDetectModeSetup);

/**********************************************************************
* �������ƣ�Net_QueryDetectModeSetup
* ������������ѯ����ļ��ģʽ
* ���������tHandle ������
* ���������ptDetectModeSetup ������ģʽ����ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryDetectModeSetup(DCHANDLE tHandle,  T_DetectModeSetup *ptDetectModeSetup);

/**********************************************************************
* �������ƣ�Net_LoopDetectSetup
* ����������������Ȧ���ģʽ����
* ���������tHandle ������
*			ptLoopParamSetup ��Ȧ���ģʽ����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_LoopDetectSetup(DCHANDLE tHandle,  T_LoopParamSetup *ptLoopParamSetup);

/**********************************************************************
* �������ƣ�Net_QueryLoopDetectSetup
* ������������ѯ��Ȧ���ģʽ����
* ���������tHandle ������
* ���������ptLoopParamSetup ��Ȧ���ģʽ����ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryLoopDetectSetup(DCHANDLE tHandle,  T_LoopParamSetup *ptLoopParamSetup);

/**********************************************************************
* �������ƣ�Net_VideoDetectSetup
* ����������������Ƶ����������
* ���������tHandle ������
*			ptVideoDetectParamSetup ��Ƶ����������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_VideoDetectSetup(DCHANDLE tHandle,  T_VideoDetectParamSetup *ptVideoDetectParamSetup);

/**********************************************************************
* �������ƣ�Net_QueryVideoDetectSetup
* ������������ѯ��Ƶ����������
* ���������tHandle ������
* ���������ptVideoDetectParamSetup ��Ƶ����������ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryVideoDetectSetup(DCHANDLE tHandle,  T_VideoDetectParamSetup *ptVideoDetectParamSetup);

/**********************************************************************
* �������ƣ�Net_VideoDetectSetup
* ����������������Ƶ����������
* ���������tHandle ������
*			ptVideoDetectParamSetup ��Ƶ����������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_DJVideoDetectSetup(DCHANDLE tHandle,  T_DJVideoDetectParamSetup *ptVideoDetectParamSetup);

/**********************************************************************
* �������ƣ�Net_QueryVideoDetectSetup
* ������������ѯ��Ƶ����������
* ���������tHandle ������
* ���������ptVideoDetectParamSetup ��Ƶ����������ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryDJVideoDetectSetup(DCHANDLE tHandle,  T_DJVideoDetectParamSetup *ptVideoDetectParamSetup);


/**********************************************************************
* �������ƣ�Net_RadarParamSetup
* ���������������״������
* ���������tHandle ������
*			ptRadarParamSetup �״������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_RadarParamSetup(DCHANDLE tHandle,  T_RadarParamSetup *ptRadarParamSetup);

/**********************************************************************
* �������ƣ�Net_QueryVideoDetectSetup
* ������������ѯ�״������
* ���������tHandle ������
* ���������ptRadarParamSetup �״������ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryRadarParamSetup(DCHANDLE tHandle,  T_RadarParamSetup *ptRadarParamSetup);

/**********************************************************************
* �������ƣ�Net_SetupRestore
* �����������ָ���������
* ���������tHandle ������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SetupRestore(DCHANDLE tHandle);

/**********************************************************************
* �������ƣ�Net_StoreConfig
* �������������浱ǰ����
* ���������tHandle ������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_StoreConfig(DCHANDLE tHandle);

/**********************************************************************
* �������ƣ�Net_ReStoreConfig
* �����������ָ�������һ������
* ���������tHandle ������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ReStoreConfig(DCHANDLE tHandle);

/**********************************************************************
* �������ƣ�Net_OneKeyFocus
* ����������һ���۽�
* ���������tHandle ������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_OneKeyFocus(DCHANDLE tHandle);

/**********************************************************************
* �������ƣ�Net_GetSysState
* ������������ѯϵͳ״̬����
* ���������tHandle ������
*			ptSysState ϵͳ״̬����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_GetSysState(DCHANDLE tHandle, T_SysState *ptSysState);

/**********************************************************************
* �������ƣ�Net_ImportConfig
* ������������������
* ���������tHandle ������
*			ptImportConfigSetup ���õ������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ImportConfig(DCHANDLE tHandle, T_ImportConfigSetup *ptImportConfigSetup);

/**********************************************************************
* �������ƣ�Net_ExportConfig
* ������������������
* ���������tHandle ������
*			ptExportConfigSetup ���õ�������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ExportConfig(DCHANDLE tHandle, T_ExportConfigSetup *ptExportConfigSetup);

NET_API E_ReturnCode _stdcall Net_ExportOfflineData(DCHANDLE tHandle, T_FileName *ptFileName);

NET_API E_ReturnCode _stdcall Net_ExportOfflinePay(DCHANDLE tHandle, T_FileName *ptFileName);

/**********************************************************************
* �������ƣ�Net_ExportLog
* ����������������־
* ���������tHandle ������
*			szLogFilePath ��־�ļ�·��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ExportLog(DCHANDLE tHandle, char *szLogFilePath);

NET_API E_ReturnCode _stdcall Net_ExportLogEx(DCHANDLE tHandle, char *szLogFilePath);

/**********************************************************************
* �������ƣ�Net_RebootTimeSetup
* �������������ö�ʱ����ϵͳ����
* ���������tHandle ������
*			ptTimeReboot ��ʱ����ϵͳ����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_RebootTimeSetup(DCHANDLE tHandle, T_TimeReboot *ptTimeReboot);

/**********************************************************************
* �������ƣ�Net_QueryRebootTimeSetup
* ������������ѯ��ʱ����ϵͳ����
* ���������tHandle ������
* ���������ptTimeReboot ��ʱ����ϵͳ����ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryRebootTimeSetup(DCHANDLE tHandle, T_TimeReboot *ptTimeReboot);

/**********************************************************************
* �������ƣ�Net_QuerySysVersion
* ������������ѯ���ϵͳ�汾
* ���������tHandle ������	
* ���������ptQueVersionRsp ϵͳ�汾����ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QuerySysVersion(DCHANDLE tHandle, T_QueVersionRsp *ptQueVersionRsp);

/**********************************************************************
* �������ƣ�Net_SpeedLimitSetup
* �������������ó������ٲ���
* ���������tHandle ������
*			ptSpeedCorrAndLimitSetup ���ٲ���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SpeedLimitSetup(DCHANDLE tHandle,  T_SpeedCorrAndLimitSetup *ptSpeedCorrAndLimitSetup);

/**********************************************************************
* �������ƣ�Net_QuerySpeedLimitSetup
* ������������ѯ�������ٲ���
* ���������tHandle ������
* ���������ptSpeedCorrAndLimitSetup ���ٲ���ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QuerySpeedLimitSetup(DCHANDLE tHandle,  T_SpeedCorrAndLimitSetup *ptSpeedCorrAndLimitSetup);

/**********************************************************************
* �������ƣ�Net_PicTransPortSetup
* ��������������ͼƬ����Э��
* ���������tHandle ������
*           ptTransPort ͼƬ����Э�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_PicTransPortSetup(DCHANDLE tHandle, T_TransProt *ptTransPort);

/**********************************************************************
* �������ƣ�Net_QueryPicTransPortSetup
* ������������ѯͼƬ����Э��
* ���������tHandle ������
* ���������ptTransPort ͼƬ����Э�����ָ��
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryPicTransPortSetup(DCHANDLE tHandle, T_TransProt *ptTransPort);

/**********************************************************************
* �������ƣ�Net_MulticastSetup
* ���������������鲥���ò���
* ���������tHandle ������
*           ptMulticastSetup �鲥���ò���ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_MulticastSetup(DCHANDLE tHandle, T_MulticastSetup *ptMulticastSetup);

/**********************************************************************
* �������ƣ�Net_QueryMulticastSetup
* ������������ѯ�鲥���ò���
* ���������tHandle ������
* ���������ptMulticastSetup �鲥���ò���ָ��
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryMulticastSetup(DCHANDLE tHandle, T_MulticastSetup *ptMulticastSetup);

/**********************************************************************
* �������ƣ�Net_QueryHardInfo
* ������������ѯ���Ӳ����Ϣ
* ���������tHandle ������
* ���������ptHardDiskInfo ���Ӳ����Ϣָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryHardInfo(DCHANDLE tHandle, T_HardDiskInfo *ptHardDiskInfo);

/**********************************************************************
* �������ƣ�Net_DiskFomat
* ������������ʽ��SSD
* ���������tHandle ������
			ptHardDiskNum ����ѡ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_DiskFomat(DCHANDLE tHandle, T_HardDiskNum *ptHardDiskNum);

/**********************************************************************
* �������ƣ�Net_DiskFomatTF
* ������������ʽ��TF��
* ���������tHandle ������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_DiskFomatTF(DCHANDLE tHandle);

/**********************************************************************
* �������ƣ�Net_TestTF
* ��������������TF����д����
* ���������tHandle ������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_TestTF(DCHANDLE tHandle);

/**********************************************************************
* �������ƣ�Net_TestUSB
* ��������������USB��д����
* ���������tHandle ������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_TestUSB(DCHANDLE tHandle);

/**********************************************************************
* �������ƣ�Net_QueryLogCount
* ������������ѯ��־�ļ�����
* ���������tHandle ������
			ptLogCount ��־�ļ���Ŀ��ѯ�ṹָ��
* ���������ptLogCountRsp ��־�ļ�����ָ��
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryLogCount(DCHANDLE tHandle, T_QueryFileBase *ptLogCount,T_FileCountRsp *ptLogCountRsp);

/**********************************************************************
* �������ƣ�Net_QueryLogInfo
* ������������ѯ��־�ļ���Ϣ
* ���������tHandle ������
			ptLogInfo ��־�ļ���Ϣ��ѯ�ṹָ��
* ���������ptLogInfoRsp ��־�ļ���Ϣָ��
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryLogInfo(DCHANDLE tHandle, T_QueryFileItem *ptLogInfo,T_FileInfoRsp *ptLogInfoRsp);

/**********************************************************************
* �������ƣ�Net_ParkGatePulseSetup
* ��������������ͣ����բ������ʱ��
* ���������tHandle ������
*			ptGatePulse ���բ������ʱ��ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ParkGatePulseSetup(DCHANDLE tHandle, T_ParkSetup *ptGatePulse);

/**********************************************************************
* �������ƣ�Net_QueryParkGatePulse
* ������������ѯͣ����բ������ʱ��
* ���������tHandle ������
* ���������ptGatePulse ���բ������ʱ��ָ��
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryParkGatePulse(DCHANDLE tHandle, T_ParkSetup *ptGatePulse);

/**********************************************************************
* �������ƣ�Net_BackMessagerSetup
* �������������ñ��÷������Ķ˿�����
* ���������tHandle ������
*			ptMessenger ���÷������˿�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_BackMessagerSetup(DCHANDLE tHandle,T_Messenger *ptMessenger);

/**********************************************************************
* �������ƣ�Net_BackMessagerSetup
* �������������ñ��÷������Ķ˿�����
* ���������tHandle ������
*			ptMessenger ���÷������˿�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryBackMessagerSetup(DCHANDLE tHandle,T_Messenger *ptMessenger);

/**********************************************************************
* �������ƣ�Net_SetWiperTime
* ����������������ˢ��ʱʱ��
* ���������tHandle ������
			ptWiperTimeing  ָ��ʱ��ˢ���õ�ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetWiperTime(DCHANDLE tHandle,T_WiperTiming *ptWiperTimeing);

/**********************************************************************
* �������ƣ�Net_QueryWiperTime
* ������������ѯ��ˢ��ʱʱ��
* ���������tHandle ������
			ptWiperTimeing  ָ��ʱ��ˢ���õ�ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryWiperTime(DCHANDLE tHandle,T_WiperTiming *ptWiperTimeing);

/**********************************************************************
* �������ƣ�Net_SetVideoAve
* ���������������ܼ�������
* ���������tHandle ������
			ptAveConfig  ָ���ܼ������õ�ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetVideoAve(DCHANDLE tHandle,T_Ave_Config *ptAveConfig);

/**********************************************************************
* �������ƣ�Net_QueryVideoAve
* ������������ѯ�ܼ�������
* ���������tHandle ������
			ptAveConfig  ָ���ܼ������õ�ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryVideoAve(DCHANDLE tHandle,T_Ave_Config *ptAveConfig);

/**********************************************************************
* �������ƣ�Net_SetParkLedManual
* ��������������LEDǿ�ƿ����Ʋ���
* ���������tHandle ������
			ptParkLedManual  ָ��LEDǿ�ƿ����Ʋ�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetParkLedManual(DCHANDLE tHandle,T_ParkLedManual *ptParkLedManual);

/**********************************************************************
* �������ƣ�Net_QueryParkLedManual
* ������������ѯLEDǿ�ƿ����Ʋ���
* ���������tHandle ������
			ptParkLedManual  ָ��LEDǿ�ƿ����Ʋ�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryParkLedManual(DCHANDLE tHandle,T_ParkLedManual *ptParkLedManual);


/**********************************************************************
* �������ƣ�Net_SetWirelessSetup
* ���������������ȵ����ò���
* ���������tHandle ������
			ptWirelessSetup  ָ���ȵ����ò�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetWirelessSetup(DCHANDLE tHandle,T_WirelessSetup *ptWirelessSetup);

/**********************************************************************
* �������ƣ�Net_QueryWirelessSetup
* ������������ѯ�ȵ����ò���
* ���������tHandle ������
			ptWirelessSetup  ָ���ȵ����ò�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryWirelessSetup(DCHANDLE tHandle,T_WirelessSetup *ptWirelessSetup);

/**********************************************************************
* �������ƣ�Net_Set3GSetup
* ��������������3G���ò���
* ���������tHandle ������
			pt3GSetup  ָ��3G���ò�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_Set3GSetup(DCHANDLE tHandle,T_3GSetup *pt3GSetup);

/**********************************************************************
* �������ƣ�Net_Query3GSetup
* ������������ѯ3G���ò���
* ���������tHandle ������
			pt3GSetup  ָ��3G���ò�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_Query3GSetup(DCHANDLE tHandle,T_3GSetup *pt3GSetup);

/**********************************************************************
* �������ƣ�Net_SetScreenSetup
* ���������������������ò���
* ���������tHandle ������
			ptScreenSetup  ָ���������ò�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetScreenSetup(DCHANDLE tHandle,T_ScreenSetup *ptScreenSetup);

/**********************************************************************
* �������ƣ�Net_QueryScreenSetup
* ������������ѯ�������ò���
* ���������tHandle ������
			ptScreenSetup  ָ���������ò�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryScreenSetup(DCHANDLE tHandle,T_ScreenSetup *ptScreenSetup);

/**********************************************************************
* �������ƣ�Net_SetSection
* ��������������ʱ�α����
* ���������tHandle ������
			ptSectionTable  ָ��ʱ�α����ò�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetSectionTable(DCHANDLE tHandle,T_SectionTable *ptSectionTable);

/**********************************************************************
* �������ƣ�Net_QuerySection
* ������������ѯʱ�α����
* ���������tHandle ������
			ptSectionTable  ָ��ʱ�α����ò�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QuerySectionTable(DCHANDLE tHandle,T_SectionTable *ptSectionTable);

/**********************************************************************
* �������ƣ�Net_SetUserParkInfo
* ���������������û���λ����Ϣ����
* ���������tHandle ������
			ptUserParkInfo  ָ���û���λ����Ϣ���ò�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetUserParkInfo(DCHANDLE tHandle,T_UserParkInfo *ptUserParkInfo);

/**********************************************************************
* �������ƣ�Net_QueryUserParkInfo
* ������������ѯ�û���λ����Ϣ����
* ���������tHandle ������
			ptUserParkInfo  ָ���û���λ����Ϣ���ò�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryUserParkInfo(DCHANDLE tHandle,T_UserParkInfo *ptUserParkInfo);

/**********************************************************************
* �������ƣ�Net_SetDetectPlateType
* �������������ó���ʶ��������Ϣ����
* ���������tHandle ������
			ptDetectPlateType  ָ����ʶ��������Ϣ������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetDetectPlateType(DCHANDLE tHandle,T_DetectPlateType *ptDetectPlateType);

/**********************************************************************
* �������ƣ�Net_QueryDetectPlateType
* ������������ѯ����ʶ��������Ϣ����
* ���������tHandle ������
			ptDetectPlateType  ָ����ʶ��������Ϣ������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryDetectPlateType(DCHANDLE tHandle,T_DetectPlateType *ptDetectPlateType);

/**********************************************************************
* �������ƣ�Net_SetExpDate
* �������������������Ч��
* ���������tHandle ������
			ptExpDate  ָ�������Ч����Ϣ������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetExpDate(DCHANDLE tHandle,T_ExpDate *ptExpDate);

/**********************************************************************
* �������ƣ�Net_QueryExpDate
* ������������ѯ�����Ч��
* ���������tHandle ������
			ptExpDate  ָ�������Ч����Ϣ������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryExpDate(DCHANDLE tHandle,T_ExpDate *ptExpDate);

/**********************************************************************
* �������ƣ�Net_SetGB28181Priv
* ��������������GB28181����
* ���������tHandle ������
			ptGB28181Priv  ָ��GB28181��Ϣ������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetGB28181Priv(DCHANDLE tHandle,T_GB28181Priv *ptGB28181Priv);

/**********************************************************************
* �������ƣ�Net_QueryGB28181Priv
* ������������ѯGB28181����
* ���������tHandle ������
			ptGB28181Priv  ָ��GB28181��Ϣ������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryGB28181Priv(DCHANDLE tHandle,T_GB28181Priv *ptGB28181Priv);

/**********************************************************************
* �������ƣ�Net_QueryProduceDate
* ������������ѯ��������
* ���������tHandle ������
			ptProduceDate  ָ������������Ϣ������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryProduceDate(DCHANDLE tHandle,T_ProduceDate *ptProduceDate);

/**********************************************************************
* �������ƣ�Net_SetProduceMod
* �������������ò�Ʒ�ͺ�
* ���������tHandle ������
			ptProduceMod  ָ���Ʒ�ͺ���Ϣ������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetProduceMod(DCHANDLE tHandle,T_ProduceMod *ptProduceMod);

/**********************************************************************
* �������ƣ�Net_QueryProduceMod
* ������������ѯ��Ʒ�ͺ�
* ���������tHandle ������
			ptProduceMod  ָ���Ʒ�ͺ���Ϣ������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryProduceMod(DCHANDLE tHandle,T_ProduceMod *ptProduceMod);

/**********************************************************************
* �������ƣ�Net_SetAssCamera
* �������������ø����IP����
* ���������tHandle ������
			ptAssCameraSetup  ָ�����IP���ò�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetAssCamera(DCHANDLE tHandle, T_AssCameraSetup *ptAssCameraSetup);

/**********************************************************************
* �������ƣ�Net_SetAssCameraAsyn
* �������������ø����IP����,ָʾ��Ϣ
* ���������tHandle ������
			ptAssCameraSetup  ָ�����IP���ò�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SetAssCameraAsyn(DCHANDLE tHandle, T_AssCameraSetup *ptAssCameraSetup);

/**********************************************************************
* �������ƣ�Net_QueryAssCamera
* ������������ѯ�����IP����
* ���������tHandle ������
			ptAssCameraSetup  ָ�����IP���ò�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryAssCamera(DCHANDLE tHandle, T_AssCameraSetup *ptAssCameraSetup);

/**********************************************************************
* �������ƣ�Net_SetAssDistrict
* �������������ø����ʶ����
* ���������tHandle ������
			ptAssDistrict  ָ�����ʶ�������ò�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetAssDistrict(DCHANDLE tHandle, T_AssDistrict *ptAssDistrict);

/**********************************************************************
* �������ƣ�Net_QueryAssDistrict
* ������������ѯ�����ʶ����
* ���������tHandle ������
			ptAssDistrict  ָ�����ʶ�������ò�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryAssDistrict(DCHANDLE tHandle, T_AssDistrict *ptAssDistrict);

/**********************************************************************
* �������ƣ�Net_SetAssMerge
* �������������ø�����ں�ʹ��
* ���������tHandle ������
			ptAssMerge  ָ������ں�ʹ�ܲ�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetAssMerge(DCHANDLE tHandle, T_AssMerge *ptAssMerge);

/**********************************************************************
* �������ƣ�Net_QueryAssMerge
* ������������ѯ������ں�ʹ��
* ���������tHandle ������
			ptAssMerge  ָ������ں�ʹ�ܲ�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryAssMerge(DCHANDLE tHandle, T_AssMerge *ptAssMerge);

/**********************************************************************
* �������ƣ�Net_QueryAssCameraStatus
* ������������ѯ���������״̬
* ���������tHandle ������
			ptAssCameraStatus  ָ���������״̬������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryAssCameraStatus(DCHANDLE tHandle, T_AssCameraStatus *ptAssCameraStatus);

/**********************************************************************
* �������ƣ�Net_AssCameraIpModify
* �����������޸ĸ����IP��ַ
* ���������tHandle ������
			ptAssCameraIpModify  ָ�����IP��ַ������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_AssCameraIpModify(DCHANDLE tHandle, T_AssCameraIpModify *ptAssCameraIpModify);

/**********************************************************************
* �������ƣ�Net_AssCameraIpSearch
* ���������������IP����������Ϣ
* ���������tHandle ������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_AssCameraIpSearch(DCHANDLE tHandle);

/**********************************************************************
* �������ƣ�Net_SendBlackWhiteListByMessEx
* ����������ͨ����Ϣ���������
* ���������tHandle ������
			ptSendLprByMessEx  ָ���������Ϣ���ò�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SendBlackWhiteListByMessEx(DCHANDLE tHandle,T_SendLprByMessEx *ptSendLprByMessEx);

/**********************************************************************
* �������ƣ�Net_QueryWhiteListByPlateEx
* ����������ͨ�����Ʋ�ѯ�������ڸó�����Ϣ�������ַ�����ΪGB2312����
* ���������tHandle ������
*			pPlateInfo ���ƺ���
			ptRspLprResultEx ָ���ѯ���ĳ�����Ϣ
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryWhiteListByPlateEx(DCHANDLE tHandle, const char *pPlateInfo,T_RspLprResultEx *ptRspLprResultEx);

/**********************************************************************
* �������ƣ�Net_QueryVideoAve
* ����������������ѯ��ǰ������ͤ����״̬����Ϣͨ��NET_ParkStateCallBack�ص��ϱ�
* ���������tHandle ������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryParkState(DCHANDLE tHandle);

/**********************************************************************
* �������ƣ�Net_QuerySignatrue
* ������������ѯǩ���ַ���
* ���������tHandle ������
* ���������ucEncId     ����ʹ�ܻ�����
*			szSignatrue ǩ���ַ���������
*		    ptLen		��������С
* ���������ucEncId     ����ʹ����Ϣ,���Ϊ0��Ϊ������,���Ϊ��������Ϊ����
*			szSignatrue ǩ���ַ�����Ϣ
*           ptLen		ǩ���ַ�����ʵ����
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QuerySignatrue(DCHANDLE tHandle, unsigned char *ucEncId, char *szSignatrue, int *ptLen);

/**********************************************************************
* �������ƣ�Net_ResetEncPwd
* �������������ó��ƽ�������
* ���������tHandle ������
* ���������szMainPwd ���������
*		    szNewPwd ���ƽ���������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ResetEncPwd(DCHANDLE tHandle, char *szMainPwd, char *szNewPwd);

/**********************************************************************
* �������ƣ�Net_ResetTwoEncpyption
* �������������ö��μ�������
* ���������tHandle ������
* ���������szMainPwd ���������
*		    szNewPwd ���μ���������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ResetTwoEncpyption(DCHANDLE tHandle, char *szMainPwd, char *szNewPwd);

/**********************************************************************
* �������ƣ�Net_ModifyEncPwd
* �����������޸ĳ��ƽ�������
* ���������tHandle ������
* ���������szOldPwd ���ƽ��ܾ�����
*		    szNewPwd ���ƽ���������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_ModifyEncPwd(DCHANDLE tHandle, char *szOldPwd, char *szNewPwd);

/**********************************************************************
* �������ƣ�Net_ModifyEncPwd
* ���������������Ƿ����
* ���������tHandle ������
* ���������ucEncId ���Ϊ0��Ϊ������,���Ϊ��������Ϊ����,��ʱ��Ҫ����Net_SetDecPwd�������������ܳ���
*		    szPwd ���ƽ�������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_EnableEnc(DCHANDLE tHandle, unsigned char ucEncId, char *szPwd);

/**********************************************************************
* �������ƣ�Net_SetEncPwd
* �������������ó��ƽ�������
* ���������tHandle ������
*		    szPwd ���ƽ�������
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetDecPwd(DCHANDLE tHandle, char *szPwd);

/**********************************************************************
* �������ƣ�Net_SetParkSpaceAttr
* �������������ó�λ����
* ���������tHandle ������
			ptParkSpaceAttr  ָ��λ���Բ�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetParkSpaceAttr(DCHANDLE tHandle, T_ParkSpaceAttr *ptParkSpaceAttr);

/**********************************************************************
* �������ƣ�Net_QueryParkSpaceAttr
* ������������ѯ��λ����
* ���������tHandle ������
			ptParkSpaceAttr  ָ��λ���Բ�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryParkSpaceAttr(DCHANDLE tHandle, T_ParkSpaceAttr *ptParkSpaceAttr);

/**********************************************************************
* �������ƣ�Net_SetLampControl
* �������������ó�λled�ƿز���
* ���������tHandle ������
			ptLampControl  ָ��λled�ƿز�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetLampControl(DCHANDLE tHandle, T_LampControl *ptLampControl);

/**********************************************************************
* �������ƣ�Net_QueryLampControl
* ������������ѯ��λ��λled�ƿز���
* ���������tHandle ������
			ptLampControl  ָ��λled�ƿز�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryLampControl(DCHANDLE tHandle, T_LampControl *ptLampControl);

/**********************************************************************
* �������ƣ�Net_SetNetLampControl
* �������������ó�λ����صƲ���
* ���������tHandle ������
			ptNetLampControl  ָ��λ����صƲ�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetNetLampControl(DCHANDLE tHandle, T_NetLampControl *ptNetLampControl);

/**********************************************************************
* �������ƣ�Net_QueryNetLampControl
* ������������ѯ��λ��λ����صƲ���
* ���������tHandle ������
			ptNetLampControl  ָ��λ����صƲ�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryNetLampControl(DCHANDLE tHandle, T_NetLampControl *ptNetLampControl);

/**********************************************************************
* �������ƣ�Net_SetImageAdjust
* ����������������Ƶ����ת
* ���������tHandle ������
			ptImageAdjust  ָ����ת������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetImageAdjust(DCHANDLE tHandle, T_ImageAdjust *ptImageAdjust);

/**********************************************************************
* �������ƣ�Net_QueryImageAdjust
* ������������ѯ��Ƶ����ת
* ���������tHandle ������
			ptImageAdjust  ָ����ת������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryImageAdjust(DCHANDLE tHandle, T_ImageAdjust *ptImageAdjust);

/**********************************************************************
* �������ƣ�Net_SetPushTargetSetup
* ��������������ʶ������������
* ���������tHandle ������
			ptPushTargetSetup  ָ��ʶ�����������ò�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetPushTargetSetup(DCHANDLE tHandle, T_PushTargetSetup *ptPushTargetSetup);

/**********************************************************************
* �������ƣ�Net_QueryPushTargetSetup
* ������������ѯʶ������������
* ���������tHandle ������
			ptPushTargetSetup  ָ��ʶ�����������ò�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryPushTargetSetup(DCHANDLE tHandle, T_PushTargetSetup *ptPushTargetSetup);

/**********************************************************************
* �������ƣ�Net_SetHttpPushSetup
* ��������������HTTP��������
* ���������tHandle ������
			ptHttpPushSetup  ָ��HTTP�������ò�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetHttpPushSetup(DCHANDLE tHandle, T_HttpPushSetup *ptHttpPushSetup);

/**********************************************************************
* �������ƣ�Net_QueryHttpPushSetup
* ������������ѯHTTP��������
* ���������tHandle ������
			ptPushTargetSetup  ָ��HTTP�������ò�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryHttpPushSetup(DCHANDLE tHandle, T_HttpPushSetup *ptHttpPushSetup);

/**********************************************************************
* �������ƣ�Net_SetHttpSetupExt
* ��������������HTTP����ʶ���������������
* ���������tHandle ������
			ptHttpSetupExt  ָ����ʶ��������������ò�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetHttpSetupExt(DCHANDLE tHandle, T_HttpSetupExt *ptHttpSetupExt);

/**********************************************************************
* �������ƣ�Net_QueryHttpSetupExt
* ������������ѯHTTP����ʶ���������������
* ���������tHandle ������
			ptHttpSetupExt  ָ����ʶ��������������ò�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryHttpSetupExt(DCHANDLE tHandle, T_HttpSetupExt *ptHttpSetupExt);

/**********************************************************************
* �������ƣ�Net_SetParkOpenManual
* ����������ǿ�ƿ�բ����
* ���������tHandle ������
			ptParkOpenManual  ָ��ǿ�ƿ�բ���Ʋ�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetParkOpenManual(DCHANDLE tHandle, T_ParkOpenManual *ptParkOpenManual);

/**********************************************************************
* �������ƣ�Net_QueryParkOpenManual
* ����������ǿ�ƿ�բ����
* ���������tHandle ������
			ptParkOpenManual  ָ��ǿ�ƿ�բ���Ʋ�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryParkOpenManual(DCHANDLE tHandle, T_ParkOpenManual *ptParkOpenManual);

/**********************************************************************
* �������ƣ�Net_QueryTcpClientInfo
* ������������ѯTCP������Ϣ
* ���������tHandle ������
			ptTcpClientInfo  ָ��TCP������Ϣ������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryTcpClientInfo(DCHANDLE tHandle, T_TcpClientInfo *ptTcpClientInfo);

/**********************************************************************
* �������ƣ�Net_QueryDevRunTime
* ������������ѯϵͳ����ʱ��
* ���������tHandle ������
			ptDevRunTime  ָ��ϵͳ����ʱ�������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 

NET_API E_ReturnCode _stdcall Net_QueryDevRunTime(DCHANDLE tHandle, T_DevRunTime *ptDevRunTime);
/**********************************************************************
* �������ƣ�Net_QueryXWCarinParam
* ������������ѯ17������Э��0��λ�볡����
* ���������tHandle ������
			ptXWCarinParam  ָ�������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryXWCarinParam(DCHANDLE tHandle, T_XWCarinParam *ptXWCarinParam);

/**********************************************************************
* �������ƣ�Net_SetXWCarinParam
* ��������������17������Э��0��λ�볡����
* ���������tHandle ������
			ptXWCarinParam  ָ�����ò�����ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetXWCarinParam(DCHANDLE tHandle, T_XWCarinParam *ptXWCarinParam);

/**********************************************************************
* �������ƣ�Net_QueryT4GInfoParam
* ������������ѯ4G״̬����
* ���������tHandle ������
			ptT4GInfoParam  ָ�������ָ��
* �����������
* �� �� ֵ��״̬��
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryT4GInfoParam(DCHANDLE tHandle, T_T4GInfoParam *ptT4GInfoParam);

#ifdef __cplusplus
}
#endif
#endif

