#ifndef _LCDLL_H_
#define _LCDLL_H_

//控制卡型号
//控制卡的类型
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

//颜色
#define LC_RED       0	//红色
#define LC_GREEN     1	//绿色
#define LC_YELLOW    2	//黄色

//节目属性
#define FIXED_TIME_PLAY	 0  //定长播放
#define ORDER_PLAY		 2  //顺序播放
#define DEF_PLAY_TIME	 30 //默认节目播放时间

//串口通信属性
#define B_9600			0
#define B_12800			1
#define B_57600			2
#define B_115200        3

#define DISPLAY_RANDOM  0                           //随机		 
#define DISPLAY_STATIC  1							//静止显示	 
#define DISPLAY_QUICK   2							//快速显示	
#define DISPLAY_MV_CONTINUTE_LEFT  3				//向左连移
#define DISPLAY_MV_CONTINUTE_RIGHT 4				//向右连移
#define DISPLAY_MV_CONTINUTE_UP 5			        //向上连移
#define DISPLAY_MV_CONTINUTE_DOWN 6					//向下连移
#define DISPLAY_MV_LEFT 7							//向左移动
#define DISPLAY_MV_RIGHT 8							//向右移动
#define DISPLAY_MV_UP 9								//向上移动
#define DISPLAY_MV_DOWN 10 							//向下移动
#define DISPLAY_MV_SCREEN_LEFT 11					//向左拉幕
#define DISPLAY_MV_SCREEN_RIGHT 12  				//向右拉幕
#define DISPLAY_MV_CENTER_FROM_LEFT_RIGHT 13 		//左右闭合
#define DISPLAY_ST_LEFT_RIGHT 	14				    //左右对开

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32
#define LCCALL WINAPI
#else
#define LCCALL 
#endif

/*****************************************************************
功能:添加显示屏
参数:
    nHardType:		   － 控制卡类型  0-LC_S    2-LC_S2  3-LC_N  4-LC_S3 5-LC_M  7-LC_T 6-LC_L
    nScreenNum:        － 屏号 1~255
	m_nScreenType:     － 屏的类型  0 单色  1 双基色 
	m_bPointType:      － 点阵类型  0 R+G   1 G+R
	m_bDataType:	   － 数据类型  0 正常 1 镜像
	m_nRowSort:		   － 行顺序    0 +1 1 0 2 -1
	m_bOE:			   － OE极性    0 低有效 1 高有效
	m_bDA:			   － 数据极性　0 负极性 1 正极性
	m_nScannMode:      － 扫描方式  请对应通用软件
	m_nScannData:      － 数据流向
返回值: 总的显示屏数
*****************************************************************/

int    LCCALL LC_AddScreen(int nHardType,int nScreenNum,int nWidth, int nHeight, int nScreenType,BOOL bPointType, BOOL bDataType,int nRowSort, BOOL bOE, BOOL bDA,int nScannMode,int nScannData);

/*****************************************************************
功能:添加节目
参数:
    nScreenNum:     － 屏号 1~255
	bPlayMode:	    － 播放模式 0 定长 1 定时
	nPlayTime:      － 定长播放的时间
	nPlayOrder		－顺序播放的次数  1~255
	bPlayLimitation:－ 播放日期 0 无效 1有效
	bPlayTime,		－ 播放时间 0 无效 1有效
	bWeek			－星期使能 0 无效 1有效
	nStartYear:	    － 播放日期 起始年
	nStartMonth:	－ 播放日期 起始月
	nStartDay:		－ 播放日期 起始日
	nEndYear:		－ 播放日期 结束年
	nEndMonth:      － 播放日期 结束月
	nEndDay:        － 播放日期 结束日
	nStartHour:	    － 播放时间 起始时
	nStartMinute:	－ 播放时间 起始分
	nStartSecond:   － 播放时间 起始秒
	nEndHour:		－ 播放时间 结束时
	nEndMinute:		－ 播放时间 结束分
	nEndSecond:     － 播放时间 结束秒		  
	bWeek1:			－ 星期一
	bWeek2:			－ 星期二	
	bWeek3:         － 星期三
	bWeek4:         － 星期四
	bWeek5:         － 星期五
	bWeek6:         － 星期六
	bWeek7:         － 星期日
返回值: 总节目数
*****************************************************************/

BOOL   LCCALL LC_AddProgram(int nScreenNum,BOOL bPlayMode,int  nPlayTime,int   nPlayOrder,BOOL bPlayLimitation,BOOL bPlayTime,BOOL bWeek,int  nStartYear,int  nStartMonth,
											   int  nStartDay,int  nEndYear,int  nEndMonth,int  nEndDay,int  nStartHour,int  nStartMinute,int  nStartSecond,int  nEndHour,
											   int  nEndMinute,int  nEndSecond,BOOL  bWeek1,BOOL  bWeek2,BOOL  bWeek3,BOOL  bWeek4,BOOL  bWeek5,BOOL  bWeek6,BOOL  bWeek7);

/*****************************************************************
功能:添加字幕区域
参数:
	nScreenNum:		－ 区域要添加到的屏号 1~255
    nProgramIdex:	－ 区域要添加到的节目序号 0~7
	nX:				－ 区域起点X
	nY:				－ 区域起点Y
	nW:				－ 区域宽度	
	nH:				－ 区域高度
	bFile:			－ 文字或文本文件 0 文字 1 文本文件
	bDataType	    －数据类型 0 图片 1 字库 16x16国标字库(区域高度只能是16) 
	bMode           -是否多行
	chText: 		－ 文字或文件名
	chFontName:		－ 字体名称
	nFontNum:		－ 字体大小
	nFontColor:		－ 字体颜色 LC_RED 红 LC_GREEN 绿 LC_YELLOW 黄
	nActionType:	－ 移动方式 
	nActionSpeed:	－ 移动速度，值越大速度越慢，0最快
	nStillTime:		－ 停留时间，值越大停留越久，0无停留时间
返回值：  
	TRUE－添加成功
	FALSE－添加失败
*****************************************************************/

BOOL   LCCALL LC_AddTxtArea(int nScreenNum,int nProgramIndex,int nX,int nY,int nW,int nH,BOOL bFile, BOOL bDataType,BOOL bMode,char *Text,char*FontName,int nFontSize,int nFontColor,int nActionType,int nActionSpeed,int nStillTime); 

/*****************************************************************
功能:添加图片区域
参数:
	nScreenNum:		－ 区域要添加到的屏号 1~255
    nProgramIdex:	－ 区域要添加到的节目序号 0~7
	nX:				－ 区域起点X
	nY:				－ 区域起点Y
	nW:				－ 区域宽度	
	nH:				－ 区域高度
	PicFile: 		－ 文字或文件名
	nActionType:	－ 移动方式 
	nActionSpeed:	－ 移动速度，值越大速度越慢，0最快
	nStillTime:		－ 停留时间，值越大停留越久，0无停留时间
返回值：  
	TRUE－添加成功
	FALSE－添加失败
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
功能:添加模拟时钟区域
参数:
	nScreenNum:			－ 区域要添加到的屏号 1~255
    nProgramIdex:		－ 区域要添加到的节目序号 0~7
	nX:					－ 区域起点X
	nY:					－ 区域起点Y
	nW:					－ 区域宽度	   最大 128
	nH:					－ 区域高度	   最大 128
	nCircleRadius:		－ 表盘的半径
	nHourRadius:		－ 时点的半径
	n369Radius:			－ 3,6,9点半经
	nHourHandWidth:		－ 小时的指针的宽度
	nMinuteHandWidth:	－ 分针的指针的宽度
	nSecondHandWidth:	－ 秒针的指针的宽度
	cHourPointColor:	－ 时点的颜色 LC_RED 红 LC_GREEN 绿 LC_YELLOW 黄
	c369PointColor:		－ 3,6,9点的颜色 LC_RED 红 LC_GREEN 绿 LC_YELLOW 黄
	cHourHandColor:		－ 时针的颜色 LC_RED 红 LC_GREEN 绿 LC_YELLOW 黄
	cMinuteHandColor:	－ 分针的颜色 LC_RED 红 LC_GREEN 绿 LC_YELLOW 黄
	cSecondHandColor:	－ 秒针的颜色 LC_RED 红 LC_GREEN 绿 LC_YELLOW 黄
	nHourPointShape:	－ 时点的形状 0 圆形 1 正方形
	n369PointShape:		－ 369点的形状 0 圆形 1 正方形
返回值：  
	TRUE－添加成功
	FALSE－添加失败
*****************************************************************/

BOOL   LCCALL LC_AddClockArea(  int nScreenNum,int nProgramIndex,int nX,int nY,int nW,int nH,int nHourRadius,
							  int n369Radius,int nHourHandWidth,int nMinuteHandWidth,int nSecondHandWidth,
							  int cHourPointColor,int c369PointColor,int cSecondPointColor,int cHourHandColor,
							  int cMinuteHandColor, int cSecondHandColor,int nHourPointShape,int n369PointShape,
							  char *strtxt,char *fontname,int cTextColor,int fontsize,int CoordinateY);

/*****************************************************************
功能:添加时间区域
参数:
	nScreenNum:			－ 区域要添加到的屏号 1~255
    nProgramIdex:		－ 区域要添加到的节目序号 0~7
	nX:					－ 区域起点X
	nY:					－ 区域起点Y
	nW:					－ 区域宽度	
	nH:					－ 区域高度
    FontName:			－ 字体名字
	nFontSize:			－ 字体大小
    bMode:				－ 显示模式 0 单行 1 多行
	bText:				－ 固定文字是否显示 0 不显示 1 显示
	Text:				－ 固定文字
	TextColor:			－ 固定文字颜色 LC_RED 红 LC_GREEN 绿 LC_YELLOW 黄
    bDate:				－ 日期是否显示 0 不显示 1 显示
    cDateColor:			－ 日期的颜色 LC_RED 红 LC_GREEN 绿 LC_YELLOW 黄
    nDateFormat:		－ 日期的格式,格式如下:
							0 -- YYYY年MM月DD日
							1 -- YY年MM月DD日
							2 -- MM/DD/YYYY
							3 -- YYYY/MM/DD
							4 -- YYYY:MM:DD
							5 -- YY:MM:DD
							6 -- MM:DD
    bWeek:				－ 星期是否显示 0 不显示 1 显示
    cWeekColor:			－ 星期的颜色 LC_RED 红 LC_GREEN 绿 LC_YELLOW 黄
    nWeekFormat:		－ 星期的格式,格式如下:
						   0 -- 星期X
						   1 -- Mon
						   2 -- 周X
    bTime:				－ 时间是否显示 0 不显示 1 显示
    cTimeColor:			－ 时间的颜色 LC_RED 红 LC_GREEN 绿 LC_YELLOW 黄
    nTimeFormat:		－ 时间的格式,格式如下:
						   0 -- HH时mm分ss秒
						   1 -- HH时mm分
						   2 -- HH:mm:ss
						   3 -- HH:mm
    bTimeZones:			－ 时差是否有效 0 无效 1 有效
    nTimeZonesMode:		－ 时差模式  0 + 1 - 
    nTimeZonesHour:		－ 时差 时值
    nTimeZonesMinute:	－ 时差 分值
返回值：  
	TRUE－添加时间区域成功
	FALSE－添加时间区域失败
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
功能:添加计时区域
参数:
	nScreenNum:			－ 区域要添加到的屏号 1~255
    nProgramIdex:		－ 区域要添加到的节目序号 0~7
	nX:					－ 区域起点X
	nY:					－ 区域起点Y
	nW:					－ 区域宽度	
	nH:					－ 区域高度
    FontName:			－ 字体名字
	nFontSize:			－ 字体大小
    bMode:				－ 显示模式 0 单行 1 多行
	bText:				－ 固定文字是否显示 0 不显示 1 显示
	Text:				－ 固定文字
	TextColor:			－ 固定文字颜色 LC_RED 红 LC_GREEN 绿 LC_YELLOW 黄
	bDay:				－ 天是否显示 0 不显示 1 显示
	bHour:				－ 时是否显示 0 不显示 1 显示
	bMinute:			－ 分是否显示 0 不显示 1 显示
	bSecond:			－ 秒是否显示 0 不显示 1 显示
	TimeColor:			－ 计时的颜色 LC_RED 红 LC_GREEN 绿 LC_YELLOW 黄
	nDstYear:			－ 	目标年		
	nDstMonth:			－  目标月
	nDstDay:			－  目标日
	nDstHour:			－  目标时
	nDstMinute:			－  目标分
	nDstSecond:			－  目标秒
返回值：  
	TRUE－添加计时区域成功
	FALSE－添加计时区域失败
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
功能:添加动画区域
参数:
	nScreenNum:		－ 区域要添加到的屏号 1~255
    nProgramIdex:	－ 区域要添加到的节目序号 0~7
	nX:				－ 区域起点X
	nY:				－ 区域起点Y
	nW:				－ 区域宽度	
	nH:				－ 区域高度
	chVidoeName:		－ 字体名称
	nActionSpeed:	－ 移动速度，值越大速度越慢，0最快
	nStillTime:		－ 停留时间，值越大停留越久，0无停留时间
返回值：  
	TRUE－添加成功
	FALSE－添加失败
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
功能:添加温度区域
参数:
	nScreenNum:			－ 区域要添加到的屏号 1~255
    nProgramIdex:		－ 区域要添加到的节目序号 0~7
	nX:					－ 区域起点X
	nY:					－ 区域起点Y
	nW:					－ 区域宽度	
	nH:					－ 区域高度
    FontName:			－ 字体名字
	nFontSize:			－ 字体大小
    bMode:				－ 显示模式 0 单行 1 多行
	bText:				－ 固定文字是否显示 0 不显示 1 显示
	Text:				－ 固定文字
	TextColor:			－ 固定文字颜色
	nSensorType:		－ 温度传感器类型
	nTemperFormat:		－ 温度格式 0x00: C 0x01: F
	nTemperColor:		－ 温度颜色
返回值：  
	TRUE－添加温度区域成功
	FALSE－添加温度区域失败
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
功能:添加湿度区域
参数:
	nScreenNum:			－ 区域要添加到的屏号 1~255
    nProgramIdex:		－ 区域要添加到的节目序号 0~7
	nX:					－ 区域起点X
	nY:					－ 区域起点Y
	nW:					－ 区域宽度	
	nH:					－ 区域高度
    FontName:			－ 字体名字
	nFontSize:			－ 字体大小
    bMode:				－ 显示模式 0 单行 1 多行
	bText:				－ 固定文字是否显示 0 不显示 1 显示
	Text:				－ 固定文字
	TextColor:			－ 固定文字颜色
	nSensorType:		－ 湿度传感器类型
	nHumidityFormat:	－ 湿度格式 0x00: %RH
	nHumidityColor:		－ 湿度颜色
返回值：  
	TRUE－添加温度区域成功
	FALSE－添加温度区域失败
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
功能:设置该显示屏的串口通信参数
参数:
    nScreenNum:	         － 屏号 1~255
	nSerialNum:			 － 串口号
	nSerialBautRate:     － 串口波特率 B_9600 9600 B_12800 12800 
								 B_57600 57600 B_115200 115200

说明:默认的波特率为B_9600，串口号 1
返回:
	TRUE	－配置成功
	FALSE	－配置失败
*****************************************************************/

BOOL   LCCALL LC_SetScreenCom(int nScreenNum,int nSerialNum,int nSerialBautRate);

/*****************************************************************
功能:设置该显示屏的网络通信参数
参数:
    nScreenNum:	   － 屏号 1~255
	IP1 :	   － IP地址
	nPort: － 端口号

说明:
返回:
	TRUE	－配置成功
	FALSE	－配置失败
*****************************************************************/

BOOL   LCCALL LC_SetScreenNet(int nScreenNum,char* IP, int nPort);

/*****************************************************************
功能:删除所有节目
参数:
    nScreenNum:    － 屏号 1~255
返回:
	TRUE	－成功
	FALSE	－失败
*****************************************************************/

BOOL   LCCALL LC_DelProgram(int nScreenNum);

/*****************************************************************
功能:系统复位
参数:
    nScreenNum:    － 屏号 1~255
返回:
	TRUE	－成功
	FALSE	－失败
*****************************************************************/

BOOL   LCCALL LC_ResetScreen(int nScreenNum);

/*****************************************************************
功能:设置屏参
参数:
    nScreenNum:   － 屏号 1~255
	set_data:   -命令型式
	01  发送固件版本     0100--0109
	02  发送DSP数据版本  0101---0701
	03  mute——on  null
	04 mute_off   null
	05 gain adj  15-30
	Data：-根据命令型式传送相应的数据
返回:
	TRUE	－成功
	FALSE	－失败
*****************************************************************/

BOOL   LCCALL LC_SetScreenPar(int nScreenNum,long set_data,long Data);

/*****************************************************************
功能:发送节目数据
参数:
    nScreenNum:   － 屏号 1~255
返回:
	TRUE	－成功
	FALSE	－失败
*****************************************************************/

BOOL   LCCALL LC_SendScreenData(int nScreenNum);

/*****************************************************************
功能:强制开机
参数:
    nScreenNum:   － 屏号 1~255
返回:
	TRUE	－成功
	FALSE	－失败
*****************************************************************/

BOOL   LCCALL LC_OpenScreen(int nScreenNum);

/*****************************************************************
功能:强制关机
参数:
    nScreenNum:	  － 屏号 1~255
返回:
	TRUE	－成功
	FALSE	－失败
*****************************************************************/

BOOL   LCCALL LC_CLoseScreen(int nScreenNum);

/*****************************************************************
功能:校时
参数:
    nScreenNum:   － 屏号 1~255
返回:
	TRUE	－成功
	FALSE	－失败
*****************************************************************/

BOOL   LCCALL LC_ReviseTime(int nScreenNum);

/*****************************************************************
功能:定时开关机
参数:
    nScreenNum:		－ 屏号 1~255
	bTimerONOFF1:	－ 第一组使能 0 无效 1 有效
	bTimerONOFF2:	－ 第二组使能 0 无效 1 有效
	bTimerONOFF3:	－ 第三组使能 0 无效 1 有效
	nStartM1, nStartH1, nEndM1, nEndH1:－ 第1组，按顺序为 开机分钟小时 关机分钟小时
	nStartM2, nStartH2, nEndM2 ,nEndH2:－ 第2组，按顺序为 开机分钟小时 关机分钟小时
	nStartM3, nStartH3, nEndM3 ,nEndH3:－ 第3组，按顺序为 开机分钟小时 关机分钟小时
返回:
	TRUE	－成功
	FALSE	－失败
*****************************************************************/

BOOL   LCCALL LC_TimingOpenOrCloseScreen( int nScreenNum,
										  BOOL bTimerONOFF1,BOOL bTimerONOFF2,BOOL bTimerONOFF3,
										  int nStartM1, int nStartH1, int nEndM1, int nEndH1,
										  int nStartM2, int nStartH2, int nEndM2, int nEndH2,
										  int nStartM3, int nStartH3, int nEndM3, int nEndH3);

/*****************************************************************
功能:锁定节目
参数:
     nScreenNum:	－ 屏号 1~255
	 nProgramIndex: － 要锁定的节目序号 0~7
返回:
	TRUE	－成功
	FALSE	－失败
*****************************************************************/

BOOL   LCCALL LC_LockProgram(int nScreenNum, int nProgramIndex);

/*****************************************************************
功能:锁定节目
参数:
     nScreenNum:	－ 屏号 1~255
	 filepath:		－ 生成的数据文件路径
返回:
	TRUE	－成功
	FALSE	－失败
*****************************************************************/
BOOL   LCCALL  LC_CreateScreenData(int nScreenNum, char *filepath);

/*****************************************************************
功能:设置该显示屏的通信方式
参数:
    nScreenNum:	   － 屏号 1~255
	nSendMode:	   － 通信方式 0x00:串口 0x01:网络

说明:
返回:
	TRUE	－配置成功
	FALSE	－配置失败
*****************************************************************/

BOOL   LCCALL  LC_SetSendMode(int nScreenNum,int nSendMode);
/*****************************************************************
功能:配置IP地址
参数:
nScreenNum:   － 屏号 1~255
*****************************************************************/
//BOOL LCCALL LC_ConfigurationIP(int nScreenNum,long port,BYTE *buf);
BOOL LCCALL LC_ConfigurationIP(int nScreenNum,long port,char *ctrlip,
							   char *subnetmask,char *ngateway);
/********************************************
功能:添加动态区域
参数:
nScreenNum:		－ 区域要添加到的屏号 1~255
nProgramIdex:	－ 区域要添加到的节目序号 0~7
nX:				－ 区域起点X
nY:				－ 区域起点Y
nW:				－ 区域宽度	
nH:				－ 区域高度
bFile:			－ 文字或文本文件 0 文字 1 文本文件
bDataType	    －数据类型 0 图片 1 字库 16x16国标字库(区域高度只能是16) 
chText: 		－ 文字或文件名
chFontName:		－ 字体名称
nFontNum:		－ 字体大小
nFontColor:		－ 字体颜色 LC_RED 红 LC_GREEN 绿 LC_YELLOW 黄
nActionType:	－ 移动方式 
nActionSpeed:	－ 移动速度，值越大速度越慢，0最快
nStillTime:		－ 停留时间，值越大停留越久，0无停留时间
返回值：  
TRUE－添加成功
	FALSE－添加失败
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
功能：更新动态区域内容
参数：
nScreenNum：显示屏号
nPeogram：节目号
Area：区域号
buf：更新的内容
************************************************/
int LCCALL LC_SendDymanicArea(int nScreenNum,int nPeogram,int Area,char *buf);
/*****************************************************************
功能:删除该节目的所有区域信息
参数:
nScreenNum:   － 屏号 1~255
nProgram:  -节目号
返回:
TRUE	－成功
FALSE	－失败
*****************************************************************/

BOOL LCCALL LC_DelArea(int nScreenNum,int nProgram);
/*****************************
发送引导命令
*/////////////////////////////
int LCCALL LC_Updateguide(int nScreenNum);
/**************************
升级固件
*****************************/
int LCCALL LC_UpdateCpldFile(int nScreenNum,char* strfile);
/**************************
升级BOOT
*****************************/
int LCCALL LC_UpdateCpldFileBOOT(int nScreenNum,char* strfile);
/******************************
升级字库文件
********************************/
int LCCALL LC_UpdateZiKu(int nScreenNum,int m_nSoundType,int m_nNumber,int m_nVoiceType,int m_nDspVersion,int m_nHversion);
//删除所有显示屏
BOOL LCCALL LC_DelScreen();
//配置MAC地址
int LCCALL LC_SetMAC(int nScreenNum,BYTE* MAC);
BOOL LCCALL LC_GetVesion(int nScreenNum,char Version[6]);

//设置扫描方式
BOOL LCCALL LC_SetScanMode(int nScreenNum,int nScannMode,int nScannData,int nHave138);

#ifdef __cplusplus
}
#endif

#endif
