
// focus_soundDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "BtnST.h"
#include "BCMenu.h"
#include "WinDef.h"
//#include "BitSlider.h"
//#include "CMySliderControl.h"







enum  HVERSION			
{

	FSB1_V3=43,
	FSB1S,
	FSC_V1,
	FSE_V1

};


#define  COM_WAIT_TIME				8000					//串口的等待返回数据的最大时间
#pragma comment(lib , "Pcomm.lib")
#define  COM_WAIT_COUNT				50					//串口发送数据时等待延时时的查询次数
// Cfocus_soundDlg 对话框
class Cfocus_soundDlg : public CDialog
{
// 构造

	
public:
	//BOOL OnSysCommand(UINT nID, LPARAM lParam);
	void INITSCREEN();
	HINSTANCE m_hInst;
	Cfocus_soundDlg(CWnd* pParent = NULL);	// 标准构造函数
	//~Cfocus_soundDlg();
	CBrush m_brush;

// 对话框数据
	enum { IDD = IDD_FOCUS_SOUND_DIALOG };
	CString	m_str;
	//int		m_nHardType;
	int     comport;
	int		m_nMode;
	//int		m_port;
	CString	m_bootpath;

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

  //private:
//	CSerialPort serial;
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);

	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnReleasedcaptureCoolSlider(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnOutofmemorySlider1(NMHDR* pNMHDR, LRESULT* pResult);
	DECLARE_MESSAGE_MAP();
	CString GetSuffix(CString strFileName);
	int  baud;
public:
	//afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonOpenfile();
	afx_msg void OnEnChangeEditFile();
	CString m_strFirewareFile;
	CString m_strProjectFilePath;
	CString m_strtxtpath;
	afx_msg void OnBnClickedButtonHardupdate();
	
	afx_msg void OnCbnSelchangeComboHversion();
	//afx_msg void OnCbnSelchangeComboSversion();
	afx_msg void OnCbnSelchangeComboComrate();
	afx_msg void OnStnClickedStaticWarning();
	afx_msg void OnStnClickedStaticzt();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	// 硬件版本号
	CString m_HARDVERSION;
	CComboBox m_HVERSION;
	// //换能器个数
	CComboBox m_colDspNum;
	CComboBox m_SVERSION;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButtonGetversion();
	CStatic m_Static_Hard;
	CStatic m_Static_Soft;
	CString m_strVersion;
	CString m_strVersion2;
	CString m_strVersion3;//驱动版本
	afx_msg void OnCbnSelchangeComboDspversion();
	afx_msg void OnCbnSelchangeComboComport();
	afx_msg void OnCbnSelchangeComboSoundtype();
	afx_msg void OnCbnSelchangeComboDspnum();
	//int m_port;
	afx_msg void OnEnChangeEdit1();
	char GetComData(int nPort);
	BOOL WaitComData(int nPort, int iMSec, int iTimes);
	BOOL GetDataBuf(char *buff, int nByte);
	BOOL FindCommPort(CComboBox &colComPort);
	int  string2int(CString str);
	char pBuf[7];
	
	// 换能器增益
	//CSliderCtrl m_slider;

	//CBitSlider m_slider;
	//afx_msg void OnNMCustomdrawSliderGain(NMHDR *pNMHDR, LRESULT *pResult);
	int m_gain;
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox m_colComPor;
	afx_msg void OnBnClickedButtonDsp();
	int m_nHardType;
	int m_nVoiceType;
	int m_nNumber;
	int m_nDspVersion;
	int m_nDspType;
	CComboBox m_colHardType;
	CStatic m_static_SVersion;
	//下两个字符串是指示DSP版本用
	CString str;//换能器版本
	CString str1;//膜版本

	//CString m_strProjectFilePath;
	CStatic m_Static_Dsp;
	afx_msg void OnBnClickedButtonMute();
	afx_msg void OnBnClickedButtonDacOn();
	afx_msg void OnBnClickedButtonGain();
	CStatic m_static_SoftVersion;
	afx_msg void OnStnClickedStaticSoftversion(); 

	//HACCEL  m_hopenfile;
	afx_msg void OnStnClickedStaticSversion();
	afx_msg void OnCbnSelchangeComboMsize();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadiohuanneng();
	void InitAllCComBoxStatus();
	//HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) ;
	//HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CButtonST m_btn_openfile;
	CComboBox m_colComPort;
	CButtonST m_btn_updatehard;
	CButtonST m_btn_updatesoft;
	CButtonST m_btn_getversion;
    CButtonST m_btn_gain;
	CButtonST m_btn_dac_on;
	CButtonST m_btn_mute;
	CButtonST m_btn_savedata;
    CButtonST m_btn_search;
	CBitmap   bitmap;  
	afx_msg void OnCbnSelchangeComboMnum();
	afx_msg void OnCbnSelchangeComboMversion();
	afx_msg void OnEnChangeEditGain();
	int Dsp_Type;
	int M_size;
	int m_nMnum;
	int m_nMtype;
	afx_msg void OnBnClickedButtonSavedata();
	CSeniorset m_seniorDialog;
private:
	// 打开文件
	BOOL PreTranslateMessage(MSG* pMsg);
	HACCEL hAccKey;
	HACCEL hupware;
	HACCEL hgetver;
	HACCEL hupdsp;

public:
	
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnDropFiles( HDROP hDropInfo );
	int m_nHversion;
	afx_msg void OnBnClickedButtonsearch();
	afx_msg void OnEnUpdateEditFile();
	int m_bat;
	CComboBox m_colbat;
	afx_msg void OnCbnSelchangeCombo3();
};

