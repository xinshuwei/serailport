#ifndef _LCDLL_H_
#define _LCDLL_H_

//���ƿ��ͺ�
//���ƿ�������
enum  SCREEN_CONTROL_TYPE				
{
	    LC_S  =      0,
		LC_S2,
		LC_S3,
		LC_T,
		LC_T2,
		LC_U,
		LC_U2,
		LC_U3,
		LC_N,
		LC_M,
		LC_M2,
		LC_L,
		LC_L1,
		LC_L2,
		LC3_S,
		LC3_S2,
		LC3_S3,
		LC3_T,
		LC3_U,
		LC3_U2,
		LC3_U3,
		LC3_M,
		LC3_M2,
		LC3_WIFI,
		LC3_GPRS
};

//��ɫ
#define LC_RED       0	//��ɫ
#define LC_GREEN     1	//��ɫ
#define LC_YELLOW    2	//��ɫ

//��Ŀ����
#define FIXED_TIME_PLAY	 0  //��������
#define ORDER_PLAY		 2  //˳�򲥷�
#define DEF_PLAY_TIME	 30 //Ĭ�Ͻ�Ŀ����ʱ��

//����ͨ������
#define B_9600			0
#define B_12800			1
#define B_57600			2
#define B_115200        3

#define DISPLAY_RANDOM  0                           //���		 
#define DISPLAY_STATIC  1							//��ֹ��ʾ	 
#define DISPLAY_QUICK   2							//������ʾ	
#define DISPLAY_MV_CONTINUTE_LEFT  3				//��������
#define DISPLAY_MV_CONTINUTE_RIGHT 4				//��������
#define DISPLAY_MV_CONTINUTE_UP 5			        //��������
#define DISPLAY_MV_CONTINUTE_DOWN 6					//��������
#define DISPLAY_MV_LEFT 7							//�����ƶ�
#define DISPLAY_MV_RIGHT 8							//�����ƶ�
#define DISPLAY_MV_UP 9								//�����ƶ�
#define DISPLAY_MV_DOWN 10 							//�����ƶ�
#define DISPLAY_MV_SCREEN_LEFT 11					//������Ļ
#define DISPLAY_MV_SCREEN_RIGHT 12  				//������Ļ
#define DISPLAY_MV_CENTER_FROM_LEFT_RIGHT 13 		//���ұպ�
#define DISPLAY_ST_LEFT_RIGHT 	14				    //���ҶԿ�

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32
#define LCCALL WINAPI
#else
#define LCCALL 
#endif

/*****************************************************************
����:�����ʾ��
����:
    nHardType:		   �� ���ƿ�����  0-LC_S    2-LC_S2  3-LC_N  4-LC_S3 5-LC_M  7-LC_T 6-LC_L
    nScreenNum:        �� ���� 1~255
	m_nScreenType:     �� ��������  0 ��ɫ  1 ˫��ɫ 
	m_bPointType:      �� ��������  0 R+G   1 G+R
	m_bDataType:	   �� ��������  0 ���� 1 ����
	m_nRowSort:		   �� ��˳��    0 +1 1 0 2 -1
	m_bOE:			   �� OE����    0 ����Ч 1 ����Ч
	m_bDA:			   �� ���ݼ��ԡ�0 ������ 1 ������
	m_nScannMode:      �� ɨ�跽ʽ  ���Ӧͨ�����
	m_nScannData:      �� ��������
����ֵ: �ܵ���ʾ����
*****************************************************************/

int    LCCALL LC_AddScreen(int nHardType,int nScreenNum,int nWidth, int nHeight, int nScreenType,BOOL bPointType, BOOL bDataType,int nRowSort, BOOL bOE, BOOL bDA,int nScannMode,int nScannData);

/*****************************************************************
����:��ӽ�Ŀ
����:
    nScreenNum:     �� ���� 1~255
	bPlayMode:	    �� ����ģʽ 0 ���� 1 ��ʱ
	nPlayTime:      �� �������ŵ�ʱ��
	nPlayOrder		��˳�򲥷ŵĴ���  1~255
	bPlayLimitation:�� �������� 0 ��Ч 1��Ч
	bPlayTime,		�� ����ʱ�� 0 ��Ч 1��Ч
	bWeek			������ʹ�� 0 ��Ч 1��Ч
	nStartYear:	    �� �������� ��ʼ��
	nStartMonth:	�� �������� ��ʼ��
	nStartDay:		�� �������� ��ʼ��
	nEndYear:		�� �������� ������
	nEndMonth:      �� �������� ������
	nEndDay:        �� �������� ������
	nStartHour:	    �� ����ʱ�� ��ʼʱ
	nStartMinute:	�� ����ʱ�� ��ʼ��
	nStartSecond:   �� ����ʱ�� ��ʼ��
	nEndHour:		�� ����ʱ�� ����ʱ
	nEndMinute:		�� ����ʱ�� ������
	nEndSecond:     �� ����ʱ�� ������		  
	bWeek1:			�� ����һ
	bWeek2:			�� ���ڶ�	
	bWeek3:         �� ������
	bWeek4:         �� ������
	bWeek5:         �� ������
	bWeek6:         �� ������
	bWeek7:         �� ������
����ֵ: �ܽ�Ŀ��
*****************************************************************/

BOOL   LCCALL LC_AddProgram(int nScreenNum,BOOL bPlayMode,int  nPlayTime,int   nPlayOrder,BOOL bPlayLimitation,BOOL bPlayTime,BOOL bWeek,int  nStartYear,int  nStartMonth,
											   int  nStartDay,int  nEndYear,int  nEndMonth,int  nEndDay,int  nStartHour,int  nStartMinute,int  nStartSecond,int  nEndHour,
											   int  nEndMinute,int  nEndSecond,BOOL  bWeek1,BOOL  bWeek2,BOOL  bWeek3,BOOL  bWeek4,BOOL  bWeek5,BOOL  bWeek6,BOOL  bWeek7);

/*****************************************************************
����:�����Ļ����
����:
	nScreenNum:		�� ����Ҫ��ӵ������� 1~255
    nProgramIdex:	�� ����Ҫ��ӵ��Ľ�Ŀ��� 0~7
	nX:				�� �������X
	nY:				�� �������Y
	nW:				�� ������	
	nH:				�� ����߶�
	bFile:			�� ���ֻ��ı��ļ� 0 ���� 1 �ı��ļ�
	bDataType	    ���������� 0 ͼƬ 1 �ֿ� 16x16�����ֿ�(����߶�ֻ����16) 
	bMode           -�Ƿ����
	chText: 		�� ���ֻ��ļ���
	chFontName:		�� ��������
	nFontNum:		�� �����С
	nFontColor:		�� ������ɫ LC_RED �� LC_GREEN �� LC_YELLOW ��
	nActionType:	�� �ƶ���ʽ 
	nActionSpeed:	�� �ƶ��ٶȣ�ֵԽ���ٶ�Խ����0���
	nStillTime:		�� ͣ��ʱ�䣬ֵԽ��ͣ��Խ�ã�0��ͣ��ʱ��
����ֵ��  
	TRUE����ӳɹ�
	FALSE�����ʧ��
*****************************************************************/

BOOL   LCCALL LC_AddTxtArea(int nScreenNum,int nProgramIndex,int nX,int nY,int nW,int nH,BOOL bFile, BOOL bDataType,BOOL bMode,char *Text,char*FontName,int nFontSize,int nFontColor,int nActionType,int nActionSpeed,int nStillTime); 

/*****************************************************************
����:���ͼƬ����
����:
	nScreenNum:		�� ����Ҫ��ӵ������� 1~255
    nProgramIdex:	�� ����Ҫ��ӵ��Ľ�Ŀ��� 0~7
	nX:				�� �������X
	nY:				�� �������Y
	nW:				�� ������	
	nH:				�� ����߶�
	PicFile: 		�� ���ֻ��ļ���
	nActionType:	�� �ƶ���ʽ 
	nActionSpeed:	�� �ƶ��ٶȣ�ֵԽ���ٶ�Խ����0���
	nStillTime:		�� ͣ��ʱ�䣬ֵԽ��ͣ��Խ�ã�0��ͣ��ʱ��
����ֵ��  
	TRUE����ӳɹ�
	FALSE�����ʧ��
*****************************************************************/

BOOL   LCCALL LC_AddPicArea(    int nScreenNum,
								int nProgramIndex, 
								int nX,
								int nY,
								int nW,
								int nH,
								char* PicFile,
								int	  nActionType,
								int	  nActionSpeed,
								int	  nStillTime
								);

/*****************************************************************
����:���ģ��ʱ������
����:
	nScreenNum:			�� ����Ҫ��ӵ������� 1~255
    nProgramIdex:		�� ����Ҫ��ӵ��Ľ�Ŀ��� 0~7
	nX:					�� �������X
	nY:					�� �������Y
	nW:					�� ������	   ��� 128
	nH:					�� ����߶�	   ��� 128
	nCircleRadius:		�� ���̵İ뾶
	nHourRadius:		�� ʱ��İ뾶
	n369Radius:			�� 3,6,9��뾭
	nHourHandWidth:		�� Сʱ��ָ��Ŀ��
	nMinuteHandWidth:	�� �����ָ��Ŀ��
	nSecondHandWidth:	�� �����ָ��Ŀ��
	cHourPointColor:	�� ʱ�����ɫ LC_RED �� LC_GREEN �� LC_YELLOW ��
	c369PointColor:		�� 3,6,9�����ɫ LC_RED �� LC_GREEN �� LC_YELLOW ��
	cHourHandColor:		�� ʱ�����ɫ LC_RED �� LC_GREEN �� LC_YELLOW ��
	cMinuteHandColor:	�� �������ɫ LC_RED �� LC_GREEN �� LC_YELLOW ��
	cSecondHandColor:	�� �������ɫ LC_RED �� LC_GREEN �� LC_YELLOW ��
	nHourPointShape:	�� ʱ�����״ 0 Բ�� 1 ������
	n369PointShape:		�� 369�����״ 0 Բ�� 1 ������
����ֵ��  
	TRUE����ӳɹ�
	FALSE�����ʧ��
*****************************************************************/

BOOL   LCCALL LC_AddClockArea(  int nScreenNum,int nProgramIndex,int nX,int nY,int nW,int nH,int nHourRadius,
							  int n369Radius,int nHourHandWidth,int nMinuteHandWidth,int nSecondHandWidth,
							  int cHourPointColor,int c369PointColor,int cSecondPointColor,int cHourHandColor,
							  int cMinuteHandColor, int cSecondHandColor,int nHourPointShape,int n369PointShape,
							  char *strtxt,char *fontname,int cTextColor,int fontsize,int CoordinateY);

/*****************************************************************
����:���ʱ������
����:
	nScreenNum:			�� ����Ҫ��ӵ������� 1~255
    nProgramIdex:		�� ����Ҫ��ӵ��Ľ�Ŀ��� 0~7
	nX:					�� �������X
	nY:					�� �������Y
	nW:					�� ������	
	nH:					�� ����߶�
    FontName:			�� ��������
	nFontSize:			�� �����С
    bMode:				�� ��ʾģʽ 0 ���� 1 ����
	bText:				�� �̶������Ƿ���ʾ 0 ����ʾ 1 ��ʾ
	Text:				�� �̶�����
	TextColor:			�� �̶�������ɫ LC_RED �� LC_GREEN �� LC_YELLOW ��
    bDate:				�� �����Ƿ���ʾ 0 ����ʾ 1 ��ʾ
    cDateColor:			�� ���ڵ���ɫ LC_RED �� LC_GREEN �� LC_YELLOW ��
    nDateFormat:		�� ���ڵĸ�ʽ,��ʽ����:
							0 -- YYYY��MM��DD��
							1 -- YY��MM��DD��
							2 -- MM/DD/YYYY
							3 -- YYYY/MM/DD
							4 -- YYYY:MM:DD
							5 -- YY:MM:DD
							6 -- MM:DD
    bWeek:				�� �����Ƿ���ʾ 0 ����ʾ 1 ��ʾ
    cWeekColor:			�� ���ڵ���ɫ LC_RED �� LC_GREEN �� LC_YELLOW ��
    nWeekFormat:		�� ���ڵĸ�ʽ,��ʽ����:
						   0 -- ����X
						   1 -- Mon
						   2 -- ��X
    bTime:				�� ʱ���Ƿ���ʾ 0 ����ʾ 1 ��ʾ
    cTimeColor:			�� ʱ�����ɫ LC_RED �� LC_GREEN �� LC_YELLOW ��
    nTimeFormat:		�� ʱ��ĸ�ʽ,��ʽ����:
						   0 -- HHʱmm��ss��
						   1 -- HHʱmm��
						   2 -- HH:mm:ss
						   3 -- HH:mm
    bTimeZones:			�� ʱ���Ƿ���Ч 0 ��Ч 1 ��Ч
    nTimeZonesMode:		�� ʱ��ģʽ  0 + 1 - 
    nTimeZonesHour:		�� ʱ�� ʱֵ
    nTimeZonesMinute:	�� ʱ�� ��ֵ
����ֵ��  
	TRUE�����ʱ������ɹ�
	FALSE�����ʱ������ʧ��
*****************************************************************/

BOOL   LCCALL LC_AddDateArea(   int nScreenNum,int nProgramIndex,int nX,int nY,int nW,int nH,
								char* FontName,int nFontSize, 
								BOOL bMode,
								BOOL bText,char *Text,int TextColor,
								BOOL bDate,int  cDateColor,int  nDateFormat,
								BOOL bWeek,int  cWeekColor,int  nWeekFormat,
								BOOL bTime,int  cTimeColor,int  nTimeFormat,
								BOOL bTimeZones,
								BOOL nTimeZonesMode,
								long nTimeZonesHour,
								long nTimeZonesMinute);
/*****************************************************************
����:��Ӽ�ʱ����
����:
	nScreenNum:			�� ����Ҫ��ӵ������� 1~255
    nProgramIdex:		�� ����Ҫ��ӵ��Ľ�Ŀ��� 0~7
	nX:					�� �������X
	nY:					�� �������Y
	nW:					�� ������	
	nH:					�� ����߶�
    FontName:			�� ��������
	nFontSize:			�� �����С
    bMode:				�� ��ʾģʽ 0 ���� 1 ����
	bText:				�� �̶������Ƿ���ʾ 0 ����ʾ 1 ��ʾ
	Text:				�� �̶�����
	TextColor:			�� �̶�������ɫ LC_RED �� LC_GREEN �� LC_YELLOW ��
	bDay:				�� ���Ƿ���ʾ 0 ����ʾ 1 ��ʾ
	bHour:				�� ʱ�Ƿ���ʾ 0 ����ʾ 1 ��ʾ
	bMinute:			�� ���Ƿ���ʾ 0 ����ʾ 1 ��ʾ
	bSecond:			�� ���Ƿ���ʾ 0 ����ʾ 1 ��ʾ
	TimeColor:			�� ��ʱ����ɫ LC_RED �� LC_GREEN �� LC_YELLOW ��
	nDstYear:			�� 	Ŀ����		
	nDstMonth:			��  Ŀ����
	nDstDay:			��  Ŀ����
	nDstHour:			��  Ŀ��ʱ
	nDstMinute:			��  Ŀ���
	nDstSecond:			��  Ŀ����
����ֵ��  
	TRUE����Ӽ�ʱ����ɹ�
	FALSE����Ӽ�ʱ����ʧ��
*****************************************************************/

BOOL   LCCALL LC_AddTimeArea(   int nScreenNum,
								int nProgramIndex, 
								int nX,
								int nY,
								int nW,
								int nH,
								char* FontName,
								int nFontSize,
								BOOL bMode,
								BOOL bText,
								char *Text,
								int TextColor,
								BOOL bDay,
								BOOL bHour,
								BOOL bMinute,
								BOOL bSecond,
								int  TimeColor,
								int nDstYear,int nDstMonth,int nDstDay,
								int nDstHour,int nDstMinute,int nDstSecond
								);
/*****************************************************************
����:��Ӷ�������
����:
	nScreenNum:		�� ����Ҫ��ӵ������� 1~255
    nProgramIdex:	�� ����Ҫ��ӵ��Ľ�Ŀ��� 0~7
	nX:				�� �������X
	nY:				�� �������Y
	nW:				�� ������	
	nH:				�� ����߶�
	chVidoeName:		�� ��������
	nActionSpeed:	�� �ƶ��ٶȣ�ֵԽ���ٶ�Խ����0���
	nStillTime:		�� ͣ��ʱ�䣬ֵԽ��ͣ��Խ�ã�0��ͣ��ʱ��
����ֵ��  
	TRUE����ӳɹ�
	FALSE�����ʧ��
*****************************************************************/

BOOL LCCALL  LC_AddVideoArea(int nScreenNum,	
							 int nProgramIndex, 
							 int nX,
							 int nY,
							 int nW,
							 int nH,
							 char* chVidoeName,
							 int   nActionSpeed,
							 int   nStillTime
							 );

/*****************************************************************
����:����¶�����
����:
	nScreenNum:			�� ����Ҫ��ӵ������� 1~255
    nProgramIdex:		�� ����Ҫ��ӵ��Ľ�Ŀ��� 0~7
	nX:					�� �������X
	nY:					�� �������Y
	nW:					�� ������	
	nH:					�� ����߶�
    FontName:			�� ��������
	nFontSize:			�� �����С
    bMode:				�� ��ʾģʽ 0 ���� 1 ����
	bText:				�� �̶������Ƿ���ʾ 0 ����ʾ 1 ��ʾ
	Text:				�� �̶�����
	TextColor:			�� �̶�������ɫ
	nSensorType:		�� �¶ȴ���������
	nTemperFormat:		�� �¶ȸ�ʽ 0x00: C 0x01: F
	nTemperColor:		�� �¶���ɫ
����ֵ��  
	TRUE������¶�����ɹ�
	FALSE������¶�����ʧ��
*****************************************************************/
BOOL LCCALL  LC_AddTemperArea(  int nScreenNum,
								int nProgramIndex, 
								int nX,
								int nY,
								int nW,
								int nH,
								char* FontName,
								int nFontSize,
								BOOL bMode,
								BOOL bText,
								char *Text,
								int TextColor,
								int nSensorType,
								int nTemperFormat,
								int nTemperColor
								);

/*****************************************************************
����:���ʪ������
����:
	nScreenNum:			�� ����Ҫ��ӵ������� 1~255
    nProgramIdex:		�� ����Ҫ��ӵ��Ľ�Ŀ��� 0~7
	nX:					�� �������X
	nY:					�� �������Y
	nW:					�� ������	
	nH:					�� ����߶�
    FontName:			�� ��������
	nFontSize:			�� �����С
    bMode:				�� ��ʾģʽ 0 ���� 1 ����
	bText:				�� �̶������Ƿ���ʾ 0 ����ʾ 1 ��ʾ
	Text:				�� �̶�����
	TextColor:			�� �̶�������ɫ
	nSensorType:		�� ʪ�ȴ���������
	nHumidityFormat:	�� ʪ�ȸ�ʽ 0x00: %RH
	nHumidityColor:		�� ʪ����ɫ
����ֵ��  
	TRUE������¶�����ɹ�
	FALSE������¶�����ʧ��
*****************************************************************/
BOOL   LCCALL LC_AddHumidityArea(   int nScreenNum,
									int nProgramIndex, 
									int nX,
									int nY,
									int nW,
									int nH,
									char* FontName,
									int nFontSize,
									BOOL bMode,
									BOOL bText,
									char *Text,
									int TextColor,
									int nSensorType,
									int nHumidityFormat,
									int nHumidityColor
									);
/*****************************************************************
����:���ø���ʾ���Ĵ���ͨ�Ų���
����:
    nScreenNum:	         �� ���� 1~255
	nSerialNum:			 �� ���ں�
	nSerialBautRate:     �� ���ڲ����� B_9600 9600 B_12800 12800 
								 B_57600 57600 B_115200 115200

˵��:Ĭ�ϵĲ�����ΪB_9600�����ں� 1
����:
	TRUE	�����óɹ�
	FALSE	������ʧ��
*****************************************************************/

BOOL   LCCALL LC_SetScreenCom(int nScreenNum,int nSerialNum,int nSerialBautRate);

/*****************************************************************
����:���ø���ʾ��������ͨ�Ų���
����:
    nScreenNum:	   �� ���� 1~255
	IP1 :	   �� IP��ַ
	nPort: �� �˿ں�

˵��:
����:
	TRUE	�����óɹ�
	FALSE	������ʧ��
*****************************************************************/

BOOL   LCCALL LC_SetScreenNet(int nScreenNum,char* IP, int nPort);

/*****************************************************************
����:ɾ�����н�Ŀ
����:
    nScreenNum:    �� ���� 1~255
����:
	TRUE	���ɹ�
	FALSE	��ʧ��
*****************************************************************/

BOOL   LCCALL LC_DelProgram(int nScreenNum);

/*****************************************************************
����:ϵͳ��λ
����:
    nScreenNum:    �� ���� 1~255
����:
	TRUE	���ɹ�
	FALSE	��ʧ��
*****************************************************************/

BOOL   LCCALL LC_ResetScreen(int nScreenNum);

/*****************************************************************
����:��������
����:
    nScreenNum:   �� ���� 1~255
	set_data:   -������ʽ
	01  ���͹̼��汾     0100--0109
	02  ����DSP���ݰ汾  0101---0701
	03  mute����on  null
	04 mute_off   null
	05 gain adj  15-30
	Data��-����������ʽ������Ӧ������
����:
	TRUE	���ɹ�
	FALSE	��ʧ��
*****************************************************************/

BOOL   LCCALL LC_SetScreenPar(int nScreenNum,long set_data,long Data);

/*****************************************************************
����:���ͽ�Ŀ����
����:
    nScreenNum:   �� ���� 1~255
����:
	TRUE	���ɹ�
	FALSE	��ʧ��
*****************************************************************/

BOOL   LCCALL LC_SendScreenData(int nScreenNum);

/*****************************************************************
����:ǿ�ƿ���
����:
    nScreenNum:   �� ���� 1~255
����:
	TRUE	���ɹ�
	FALSE	��ʧ��
*****************************************************************/

BOOL   LCCALL LC_OpenScreen(int nScreenNum);

/*****************************************************************
����:ǿ�ƹػ�
����:
    nScreenNum:	  �� ���� 1~255
����:
	TRUE	���ɹ�
	FALSE	��ʧ��
*****************************************************************/

BOOL   LCCALL LC_CLoseScreen(int nScreenNum);

/*****************************************************************
����:Уʱ
����:
    nScreenNum:   �� ���� 1~255
����:
	TRUE	���ɹ�
	FALSE	��ʧ��
*****************************************************************/

BOOL   LCCALL LC_ReviseTime(int nScreenNum);

/*****************************************************************
����:��ʱ���ػ�
����:
    nScreenNum:		�� ���� 1~255
	bTimerONOFF1:	�� ��һ��ʹ�� 0 ��Ч 1 ��Ч
	bTimerONOFF2:	�� �ڶ���ʹ�� 0 ��Ч 1 ��Ч
	bTimerONOFF3:	�� ������ʹ�� 0 ��Ч 1 ��Ч
	nStartM1, nStartH1, nEndM1, nEndH1:�� ��1�飬��˳��Ϊ ��������Сʱ �ػ�����Сʱ
	nStartM2, nStartH2, nEndM2 ,nEndH2:�� ��2�飬��˳��Ϊ ��������Сʱ �ػ�����Сʱ
	nStartM3, nStartH3, nEndM3 ,nEndH3:�� ��3�飬��˳��Ϊ ��������Сʱ �ػ�����Сʱ
����:
	TRUE	���ɹ�
	FALSE	��ʧ��
*****************************************************************/

BOOL   LCCALL LC_TimingOpenOrCloseScreen( int nScreenNum,
										  BOOL bTimerONOFF1,BOOL bTimerONOFF2,BOOL bTimerONOFF3,
										  int nStartM1, int nStartH1, int nEndM1, int nEndH1,
										  int nStartM2, int nStartH2, int nEndM2, int nEndH2,
										  int nStartM3, int nStartH3, int nEndM3, int nEndH3);

/*****************************************************************
����:������Ŀ
����:
     nScreenNum:	�� ���� 1~255
	 nProgramIndex: �� Ҫ�����Ľ�Ŀ��� 0~7
����:
	TRUE	���ɹ�
	FALSE	��ʧ��
*****************************************************************/

BOOL   LCCALL LC_LockProgram(int nScreenNum, int nProgramIndex);

/*****************************************************************
����:������Ŀ
����:
     nScreenNum:	�� ���� 1~255
	 filepath:		�� ���ɵ������ļ�·��
����:
	TRUE	���ɹ�
	FALSE	��ʧ��
*****************************************************************/
BOOL   LCCALL  LC_CreateScreenData(int nScreenNum, char *filepath);

/*****************************************************************
����:���ø���ʾ����ͨ�ŷ�ʽ
����:
    nScreenNum:	   �� ���� 1~255
	nSendMode:	   �� ͨ�ŷ�ʽ 0x00:���� 0x01:����

˵��:
����:
	TRUE	�����óɹ�
	FALSE	������ʧ��
*****************************************************************/

BOOL   LCCALL  LC_SetSendMode(int nScreenNum,int nSendMode);
/*****************************************************************
����:����IP��ַ
����:
nScreenNum:   �� ���� 1~255
*****************************************************************/
//BOOL LCCALL LC_ConfigurationIP(int nScreenNum,long port,BYTE *buf);
BOOL LCCALL LC_ConfigurationIP(int nScreenNum,long port,char *ctrlip,
							   char *subnetmask,char *ngateway);
/********************************************
����:��Ӷ�̬����
����:
nScreenNum:		�� ����Ҫ��ӵ������� 1~255
nProgramIdex:	�� ����Ҫ��ӵ��Ľ�Ŀ��� 0~7
nX:				�� �������X
nY:				�� �������Y
nW:				�� ������	
nH:				�� ����߶�
bFile:			�� ���ֻ��ı��ļ� 0 ���� 1 �ı��ļ�
bDataType	    ���������� 0 ͼƬ 1 �ֿ� 16x16�����ֿ�(����߶�ֻ����16) 
chText: 		�� ���ֻ��ļ���
chFontName:		�� ��������
nFontNum:		�� �����С
nFontColor:		�� ������ɫ LC_RED �� LC_GREEN �� LC_YELLOW ��
nActionType:	�� �ƶ���ʽ 
nActionSpeed:	�� �ƶ��ٶȣ�ֵԽ���ٶ�Խ����0���
nStillTime:		�� ͣ��ʱ�䣬ֵԽ��ͣ��Խ�ã�0��ͣ��ʱ��
����ֵ��  
TRUE����ӳɹ�
	FALSE�����ʧ��
************************************************/
int LCCALL LC_AddDymanicArea(   int nScreenNum,
							 int nProgramIndex, 
							 int nX,
							 int nY,
							 int nW,
							 int nH,
							 BOOL bFile,
							 BOOL bDataType,
							 //BOOL bMode,
							 char* Text,
							 char* FontName,
							 int	  nFontSize,
							 int	  nFontColor,
							 int	  nActionType,
							 int	  nActionSpeed,
							 int	  nStillTime
							 );
/*********************************************
���ܣ����¶�̬��������
������
nScreenNum����ʾ����
nPeogram����Ŀ��
Area�������
buf�����µ�����
************************************************/
int LCCALL LC_SendDymanicArea(int nScreenNum,int nPeogram,int Area,char *buf);
/*****************************************************************
����:ɾ���ý�Ŀ������������Ϣ
����:
nScreenNum:   �� ���� 1~255
nProgram:  -��Ŀ��
����:
TRUE	���ɹ�
FALSE	��ʧ��
*****************************************************************/

BOOL LCCALL LC_DelArea(int nScreenNum,int nProgram);
/*****************************
������������
*/////////////////////////////
int LCCALL LC_Updateguide(int nScreenNum);
/**************************
�����̼�
*****************************/
int LCCALL LC_UpdateCpldFile(int nScreenNum,char* strfile);
/**************************
����BOOT
*****************************/
int LCCALL LC_UpdateCpldFileBOOT(int nScreenNum,char* strfile);
/******************************
�����ֿ��ļ�
********************************/
int LCCALL LC_UpdateZiKu(int nScreenNum,int m_nSoundType,int m_nNumber,int m_nVoiceType,int m_nDspVersion,int m_nHversion);
//ɾ��������ʾ��
BOOL LCCALL LC_DelScreen();
//����MAC��ַ
int LCCALL LC_SetMAC(int nScreenNum,BYTE* MAC);
BOOL LCCALL LC_GetVesion(int nScreenNum,char Version[6]);

//����ɨ�跽ʽ
BOOL LCCALL LC_SetScanMode(int nScreenNum,int nScannMode,int nScannData,int nHave138);

#ifdef __cplusplus
}
#endif

#endif
