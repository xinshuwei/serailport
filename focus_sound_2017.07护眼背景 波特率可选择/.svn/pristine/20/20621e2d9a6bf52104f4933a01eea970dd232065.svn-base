
// focus_soundDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "focus_sound.h"
#include "focus_soundDlg.h"
#include "LC_DLL.h"
#include "Pcomm.h"
#include "serialport.h"
#include "cstringt.h"
#include "AES.h"
#include "BitItem.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// Cfocus_soundDlg 对话框
//默认组合框的选择位置。
Cfocus_soundDlg::Cfocus_soundDlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cfocus_soundDlg::IDD, pParent)
   , m_strProjectFilePath("")
	/*
	, m_nHardType(0)
	, m_nVoiceType(0)
	, m_nNumber(0)
	, m_nDspVersion(0)
	, M_size(0)
	, m_nMnum(0)
	, m_nMtype(0)*/
	,m_gain(15)
	,m_nHversion(0)
	,comport(0)
	, m_bat(0)
{
	m_hIcon = (HICON)LoadImage(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP_LOGO),IMAGE_ICON,16,16,LR_DEFAULTCOLOR|LR_CREATEDIBSECTION);
	hAccKey=LoadAccelerators(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_ACCELERATOR_OPENFILE));
	hupware=LoadAccelerators(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDC_BUTTON_HARDUPDATE));
	hgetver=LoadAccelerators(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDC_BUTTON_GETVERSION));
	hupdsp=LoadAccelerators(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDC_BUTTON_DSP));
}

void Cfocus_soundDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FILE, m_strFirewareFile);
	DDX_Control(pDX, IDC_STATIC_HARD, m_Static_Hard);
	DDX_Control(pDX, IDC_STATIC_SOFT, m_Static_Soft);
	/*DDX_Control(pDX, IDC_SLIDER_GAIN, m_slider);*/
	DDX_Text(pDX, IDC_EDIT_GAIN, m_gain);
	DDV_MinMaxInt(pDX, m_gain, 5, 30);
	DDX_Control(pDX, IDC_COMBO1, m_colComPort);
	DDX_CBIndex(pDX, IDC_COMBO_HVERSION, m_nHardType);
	DDX_CBIndex(pDX, IDC_COMBO_SOUNDTYPE, m_nVoiceType);
	DDX_CBIndex(pDX, IDC_COMBO_DSPNUM, m_nNumber);
	DDX_CBIndex(pDX, IDC_COMBO_DSPVERSION, m_nDspVersion);
	DDX_Control(pDX, IDC_COMBO_HVERSION, m_colHardType);
	DDX_Control(pDX, IDC_STATIC_SVersion, m_static_SVersion);
	DDX_Control(pDX, IDC_STATIC_DSP, m_Static_Dsp);
	DDX_Control(pDX, IDC_STATIC_SoftVersion, m_static_SoftVersion);
	DDX_Control(pDX, IDC_COMBO1, m_colComPort);
	DDX_CBIndex(pDX, IDC_COMBO_Msize, M_size);
	DDX_CBIndex(pDX, IDC_COMBO_Mnum, m_nMnum);
	DDX_CBIndex(pDX, IDC_COMBO_Mversion, m_nMtype);
	DDX_CBIndex(pDX, IDC_COMBO2, m_nHversion);
	DDX_CBIndex(pDX, IDC_COMBO3, m_bat);
	DDX_Control(pDX, IDC_COMBO3, m_colbat);
}
BEGIN_MESSAGE_MAP(Cfocus_soundDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()//IDD_FOCUS_SOUND_DIALOG,&Cfocus_soundDlg::OnCtlColor
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	//ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_GAIN, Cfocus_soundDlg::OnNMCustomdrawSliderGain)
	ON_WM_DROPFILES(IDC_EDIT_FILE,&Cfocus_soundDlg::OnDropFiles)
	ON_BN_CLICKED(IDC_BUTTON_OPENFILE, &Cfocus_soundDlg::OnBnClickedButtonOpenfile)
	ON_EN_CHANGE(IDC_EDIT_FILE, &Cfocus_soundDlg::OnEnChangeEditFile)
	ON_BN_CLICKED(IDC_BUTTON_HARDUPDATE, &Cfocus_soundDlg::OnBnClickedButtonHardupdate)
	ON_CBN_SELCHANGE(IDC_COMBO_HVERSION, &Cfocus_soundDlg::OnCbnSelchangeComboHversion)
	ON_BN_CLICKED(IDC_BUTTON_GETVERSION, &Cfocus_soundDlg::OnBnClickedButtonGetversion)
	ON_CBN_SELCHANGE(IDC_COMBO_DSPVERSION, &Cfocus_soundDlg::OnCbnSelchangeComboDspversion)
	ON_CBN_SELCHANGE(IDC_COMBO_COMPORT, &Cfocus_soundDlg::OnCbnSelchangeComboComport)
	ON_CBN_SELCHANGE(IDC_COMBO_SOUNDTYPE, &Cfocus_soundDlg::OnCbnSelchangeComboSoundtype)
	ON_CBN_SELCHANGE(IDC_COMBO_DSPNUM, &Cfocus_soundDlg::OnCbnSelchangeComboDspnum)
	//ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_GAIN, &Cfocus_soundDlg::OnNMCustomdrawSliderGain)
	ON_CBN_SELCHANGE(IDC_COMBO1, &Cfocus_soundDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON_DSP, &Cfocus_soundDlg::OnBnClickedButtonDsp)
	ON_BN_CLICKED(IDC_BUTTON_MUTE, &Cfocus_soundDlg::OnBnClickedButtonMute)
	ON_BN_CLICKED(IDC_BUTTON_DAC_ON, &Cfocus_soundDlg::OnBnClickedButtonDacOn)
	ON_BN_CLICKED(IDC_BUTTON_Gain, &Cfocus_soundDlg::OnBnClickedButtonGain)
	ON_STN_CLICKED(IDC_STATIC_SoftVersion, &Cfocus_soundDlg::OnStnClickedStaticSoftversion)
	ON_STN_CLICKED(IDC_STATIC_SVersion, &Cfocus_soundDlg::OnStnClickedStaticSversion)
	ON_CBN_SELCHANGE(IDC_COMBO_Msize, &Cfocus_soundDlg::OnCbnSelchangeComboMsize)
	ON_BN_CLICKED(IDC_RADIO2, &Cfocus_soundDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO_huanneng, &Cfocus_soundDlg::OnBnClickedRadiohuanneng)
	ON_CBN_SELCHANGE(IDC_COMBO_Mnum, &Cfocus_soundDlg::OnCbnSelchangeComboMnum)
	ON_CBN_SELCHANGE(IDC_COMBO_Mversion, &Cfocus_soundDlg::OnCbnSelchangeComboMversion)
	ON_EN_CHANGE(IDC_EDIT_GAIN, &Cfocus_soundDlg::OnEnChangeEditGain)
	ON_BN_CLICKED(IDC_BUTTON_SaveData, &Cfocus_soundDlg::OnBnClickedButtonSavedata)
	ON_CBN_SELCHANGE(IDC_COMBO2, &Cfocus_soundDlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON_search, &Cfocus_soundDlg::OnBnClickedButtonsearch)
	ON_EN_UPDATE(IDC_EDIT_FILE, &Cfocus_soundDlg::OnEnUpdateEditFile)
	//ON_EN_CHANGE(IDC_EDIT_vol, &Cfocus_soundDlg::OnEnChangeEditvol)
	ON_CBN_SELCHANGE(IDC_COMBO3, &Cfocus_soundDlg::OnCbnSelchangeCombo3)
END_MESSAGE_MAP()


// Cfocus_soundDlg 消息处理程序

BOOL Cfocus_soundDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	// TODO: 在此添加额外的初始化代码
	bitmap.LoadBitmap(IDB_BITMAP3); 
	m_hInst=LoadLibrary("LCDLL.dll");
    if (m_hInst);
	else
	AfxMessageBox("加载动态库失败!");
	//this->BuildShareSlider();
	//串口搜索
	FindCommPort(m_colComPort);
	//选择第二个为当前串口号
	Cfocus_soundDlg::m_colComPort.SetCurSel(0);
	//UpdateData(TRUE);
	//参数读取
	char strProjectFilePath[256];
	GetCurrentDirectory(MAX_PATH,strProjectFilePath);
	m_strProjectFilePath=strProjectFilePath;
	m_strProjectFilePath+="\\DATA.INI";
	m_nHardType=GetPrivateProfileInt("HardSet","控制卡类型",1,m_strProjectFilePath);
    m_bat=GetPrivateProfileInt("串口","波特率",1,m_strProjectFilePath);
	m_nVoiceType=GetPrivateProfileInt("换能器","换能器声音类型",1,m_strProjectFilePath);
    m_nNumber=GetPrivateProfileInt("换能器","换能器数量",1,m_strProjectFilePath);
	m_nHversion=GetPrivateProfileInt("换能器","换能器参数版本",1,m_strProjectFilePath);
    m_nDspVersion=GetPrivateProfileInt("换能器","换能器大小",1,m_strProjectFilePath);
	M_size=GetPrivateProfileInt("薄膜","薄膜面积",1,m_strProjectFilePath);
	m_nMnum=GetPrivateProfileInt("薄膜","薄膜个数",1,m_strProjectFilePath);
	m_nMtype=GetPrivateProfileInt("薄膜","参数版本",1,m_strProjectFilePath);
	m_nDspType=GetPrivateProfileInt("输出","输出类型",1,m_strProjectFilePath);
	
	//设置按钮的状态
	if(m_nDspType==1)
		{
		 CheckDlgButton(IDC_RADIO_huanneng, 1);
		Cfocus_soundDlg::OnBnClickedRadiohuanneng();
		}
	if(m_nDspType==2)
		{
		 CheckDlgButton(IDC_RADIO2, 1);
		Cfocus_soundDlg::OnBnClickedRadio2();
		}
	
	GetDlgItem(IDC_BUTTON_Gain)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_MUTE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_DAC_ON)->EnableWindow(FALSE);
	GetDlgItem(	IDC_RADIO2)->EnableWindow(FALSE);
	GetDlgItem(IDC_COMBO3)->EnableWindow(FALSE);
    GetDlgItem(	IDC_BUTTON_SaveData)->EnableWindow(FALSE);
	GetDlgItem(IDC_COMBO_HVERSION)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO_huanneng)->EnableWindow(FALSE);
	InitAllCComBoxStatus();
	//MFC界面图标加载
	m_btn_openfile.SubclassDlgItem(IDC_BUTTON_OPENFILE,this);
    m_btn_openfile.SetIcon(IDI_ICON_OPENFILE);
    m_btn_openfile.DrawTransparent(TRUE);//打开文件图标
	HICON hIcon;
    hIcon = (HICON)LoadImage(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON_hardupdate),IMAGE_ICON,16,16,LR_DEFAULTCOLOR|LR_CREATEDIBSECTION);
	m_btn_updatehard.SubclassDlgItem(IDC_BUTTON_HARDUPDATE,this);
    m_btn_updatehard.SetIcon(hIcon);
    m_btn_updatehard.DrawTransparent(TRUE);//升级固件图标
    m_btn_updatehard.SetTooltipText("升级前请打开固件并确保硬件版本和固件的硬件版本对应！！");
	HICON hIcon1;
    hIcon1 = (HICON)LoadImage(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON_getversion),IMAGE_ICON,16,16,LR_DEFAULTCOLOR|LR_CREATEDIBSECTION);
	m_btn_getversion.SubclassDlgItem(IDC_BUTTON_GETVERSION,this);
    m_btn_getversion.SetIcon(hIcon1);
    m_btn_getversion.DrawTransparent(TRUE);//获取版本图标
	m_btn_getversion.SetTooltipText("此功能是获取板卡中版本信息！！");
	HICON hIcon2;
    hIcon2 = (HICON)LoadImage(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON_UPDATE),IMAGE_ICON,16,16,LR_DEFAULTCOLOR|LR_CREATEDIBSECTION);
	m_btn_updatesoft.SubclassDlgItem(IDC_BUTTON_DSP,this);
    m_btn_updatesoft.SetIcon(hIcon2);
    m_btn_updatesoft.DrawTransparent(TRUE);//配置DSP图标
	m_btn_updatesoft.SetTooltipText("将选择好版本的DSP数据加载到硬件中！！");
	HICON hIcon5;
	hIcon5 = (HICON)LoadImage(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON_gain),IMAGE_ICON,16,16,LR_DEFAULTCOLOR|LR_CREATEDIBSECTION);
	m_btn_gain.SubclassDlgItem(IDC_BUTTON_Gain,this);
    m_btn_gain.SetIcon(hIcon5);
    m_btn_gain.DrawTransparent(TRUE);//配置增益
	HICON hIcon3;
	hIcon3 = (HICON)LoadImage(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON_mute),IMAGE_ICON,16,16,LR_DEFAULTCOLOR|LR_CREATEDIBSECTION);
	m_btn_mute.SubclassDlgItem(IDC_BUTTON_MUTE,this);
    m_btn_mute.SetIcon(hIcon3);
    m_btn_mute.DrawTransparent(TRUE);//配置静音
	HICON hIcon4;
	hIcon4 = (HICON)LoadImage(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON_DAC_on),IMAGE_ICON,16,16,LR_DEFAULTCOLOR|LR_CREATEDIBSECTION);
	m_btn_dac_on.SubclassDlgItem(IDC_BUTTON_DAC_ON,this);
    m_btn_dac_on.SetIcon(hIcon4);
    m_btn_dac_on.DrawTransparent(TRUE);//配置使能输出
	HICON hIcon6;
	hIcon6 = (HICON)LoadImage(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON2),IMAGE_ICON,16,16,LR_DEFAULTCOLOR|LR_CREATEDIBSECTION);
	m_btn_savedata.SubclassDlgItem(IDC_BUTTON_SaveData,this);
    m_btn_savedata.SetIcon(hIcon6);
    m_btn_savedata.DrawTransparent(TRUE);//保存参数
   	HICON hIcon7;
	hIcon7 = (HICON)LoadImage(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON1),IMAGE_ICON,16,16,LR_DEFAULTCOLOR|LR_CREATEDIBSECTION);
	m_btn_search.SubclassDlgItem(IDC_BUTTON_search,this);
    m_btn_search.SetIcon(hIcon7);
    m_btn_search.DrawTransparent(TRUE);//保存参数


	int nSel;
	CString strcom;
    // 获取组合框控件的列表框中选中项的索引   
    nSel = m_colComPort.GetCurSel();   
    // 根据选中项索引获取该项字符串   
    m_colComPort.GetLBText(nSel, strcom);
	comport=string2int(strcom);//提取列表项中的数字
	m_gain=15;
	UpdateData(FALSE);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE

}

void Cfocus_soundDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

void Cfocus_soundDlg::INITSCREEN()
{
	UpdateData(TRUE);
	BOOL bFlag;
	int m=2,s=3,oe=1;
	int hardtype;
	LC_DelScreen();
	switch(m_nHardType)
	{

	case 0:hardtype=FSB1_V3;break;
	case 1:hardtype=FSB1S;break;
	case 2:hardtype=FSC_V1;break;
	case 3:hardtype=FSE_V1;break;
	default:hardtype=-1;break;
	}
	switch(m_bat)
	{
	case 0: baud=B_9600;break; 
	case 1: baud=B_12800;break; 
	case 2: baud=B_57600;break; 
	case 3: baud=B_115200;break; 
	}
	if(m_nHardType<0)
    {MessageBox("请选择硬件版本！");return;}
	bFlag = LC_AddScreen(hardtype, 1,64,32,1,0,0,1,oe,0,m,s);
	if(bFlag==FALSE)
	{MessageBox("硬件版本不对，请检查参数!");return;}
	bFlag = LC_SetSendMode(1,0x00);//控制卡的通信模式 0 串口 1 网口 2 GPRS 3 驿唐GPRS
	if(bFlag==FALSE)
	{MessageBox("设置通信模式失败，请检查参数!");return;}
	bFlag = LC_SetScreenCom(1,comport,m_bat);
	if(bFlag==FALSE)
	{MessageBox("设置串口参数失败，请检查参数!");return;}
}



// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cfocus_soundDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
		
	}
	else
	{
		//Invalidate();
		CDialog::OnPaint();

		//////////////////添加背景
      
    /*  CPaintDC   dc(this);   
      CRect   rect;   
      GetClientRect(&rect);   
      CDC   dcMem;   
      dcMem.CreateCompatibleDC(&dc);   
      CBitmap   bmpBackground;   
      bmpBackground.LoadBitmap(IDB_BITMAP1);   
            // IDB_BITMAP1是你自己的图对应的ID   
      BITMAP   bitmap;  
      bmpBackground.GetBitmap(&bitmap);   
      CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   
      dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,   
      bitmap.bmWidth,bitmap.bmHeight,SRCCOPY); */

	 /*   CRect rc;  
        GetWindowRect(&rc);  
        CImage mImage;  
        if(mImage.Load(_T("1.bmp")) == S_OK)  
        {  
            //这里让图片绘制区域和窗口大小一致  
            mImage.Draw(GetDC()->GetSafeHdc(), CRect(0,0,rc.Width(),rc.Height()));  
		}*/
		/*CBitmap bmp;  
		bmp.LoadBitmap(IDB_BITMAP1);   
		//m_brush.CreatePatternBrush(&bmp);   
		m_brush.CreateSolidBrush(RGB(0,255,127)); //用纯色作为背景  
	    bmp.DeleteObject();*/

	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cfocus_soundDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
UINT SendDATA(LPVOID lparam)
{
	Cfocus_soundDlg *pthis = (Cfocus_soundDlg*)lparam;
	/*char strpath[500];
	strcpy_s(strpath,pthis->m_strFirewareFile);*/
		unsigned char key[16];
		key[0]=3;
		key[1]=4;
		key[2]=0;
		key[3]=6;
		key[4]=2;
		key[5]=5;
		key[6]=0;
		key[7]=1;
		key[8]=0;
		key[9]=6;
		key[10]=5;
		key[11]=8;
		key[12]=9;
		key[13]=8;
		key[14]=7;
		key[15]=5;
		AES aes(key);

        FILE* fin;
		fin=fopen((LPCTSTR)pthis->m_strFirewareFile,"rb");
		fseek(fin,0,SEEK_END);
		long flen=ftell(fin);//ftell()函数返回文件位置指示符的当前值，即如果现在是在文件结尾，则这个值就是文件长度
		fseek(fin,0,SEEK_SET);
		long blknum=(flen-7)/16;
		long leftnum=(flen-7)%16;

		char *data=NULL;
		data=new char[8];
		memset(data,0,8);
		char *data1=NULL;
		data1=new char[blknum*16+1];
		memset(data1,0,blknum*16+1);
		char *data2=NULL;
		data2=new char[leftnum+1];
		memset(data2,0,leftnum);
		fread(data,1,7,fin);
		fread(data1,1,blknum*16,fin);
		fread(data2,1,leftnum,fin);
		fclose(fin);
		aes.InvCipher(data1,blknum*16);
		char strPath[256];
		GetCurrentDirectory(MAX_PATH,strPath);
		CString outpath;
		CString path;
		outpath=strPath;
		path.Format("//t.hw");
		outpath+=path;
		CFile file1 (outpath,CFile::modeCreate|CFile::modeWrite);
		file1.Write(data,7);
		file1.Write(data1,blknum*16);
		file1.Write(data2,leftnum);
		file1.Flush();
		file1.Close();
		BOOL b=LC_SetScreenPar(1,1,(int)pthis->pBuf[3]%16*256+(int)pthis->pBuf[4]/16*10+(int)pthis->pBuf[4]%16);
		if(b==TRUE)
		{
		pthis->GetDlgItem(IDC_STATICZT)->SetWindowText("正在升级固件...请勿断电!");
		char strpath[500];
	    strcpy_s(strpath,outpath);
		int a=LC_UpdateCpldFile(1,strpath);
		
			if(a!=0)
				{
				char *pFileName="t.hw";
				CFile::Remove(pFileName);
				pthis->GetDlgItem(IDC_STATICZT)->SetWindowText("升级固件版本成功...发送固件成功...");
				delete data1;
		        delete data2;
				delete data;
				}
			else
				{
				char *pFileName="t.hw";
			    CFile::Remove(pFileName);
				pthis->GetDlgItem(IDC_STATICZT)->SetWindowText("升级固件版本成功...发送固件失败...");
			    delete data;
				delete data1;
				delete data2;
			    return 0;
				}

		}
		else
		pthis->GetDlgItem(IDC_STATICZT)->SetWindowText("发送固件版本失败...");
		return 0;
}

void Cfocus_soundDlg::OnBnClickedButtonOpenfile()
{
	// TODO: 在此添加控件通知处理程序代码
	//CString strName;
	CFileDialog dlg(TRUE,
		_T(""),
		_T(""),
		//OFN_EXPLORER,
		OFN_HIDEREADONLY,
		_T("*.hw|*.hw;||"),this);//构建打开文件对话框
	//dlg.m_ofn.lpstrInitialDir= m_strDocPath;
	if(dlg.DoModal()!=IDOK)//显示打开文件对话框
	  return;
		//strName=dlg.GetPathName();//获取文件路径名称
	m_strFirewareFile=dlg.GetPathName();
	CFile filerend(m_strFirewareFile ,CFile::modeRead);     //打开文件
	//char pBuf[7];
	filerend.Read(pBuf,7);                   //读取文件
	filerend.Close();
	CString strVersion;
	strVersion.Format("V%d.%d%d",(int)pBuf[3]%16,(int)pBuf[4]/16,(int)pBuf[4]%16);
    Cfocus_soundDlg::m_static_SoftVersion.SetWindowText(strVersion);
	UpdateData(FALSE);
	Invalidate();


}

void Cfocus_soundDlg::OnEnChangeEditFile()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	 ///强制进行更新
	UpdateData(FALSE);
	Invalidate();


}

void Cfocus_soundDlg::OnBnClickedButtonHardupdate()
{
	// TODO: 在此添加控件通知处理程序代码
	BOOL flag;
    UpdateData(TRUE);
    if(m_strFirewareFile.IsEmpty())
		{
		MessageBox("未打开固件，请打开新的固件!");
	    return;
	    }
	INITSCREEN();
    char buff[6];
    flag=LC_GetVesion(1,buff);
    if(flag==TRUE)
    {
		    m_strVersion.Format("固件版本:V%d.%.2d",buff[0],buff[1]);
			m_strVersion2.Format("硬件版本:V%d.%.2d",buff[2],buff[3]);
			m_Static_Hard.SetWindowText(m_strVersion);
			m_Static_Soft.SetWindowText(m_strVersion2);
			m_strVersion3.Format("V%2d.%.2d",buff[4],buff[5]);
			Cfocus_soundDlg::m_Static_Dsp.SetWindowText(m_strVersion3);
			GetDlgItem(IDC_STATICZT)->SetWindowText("获取版本成功...");
			CFile filerend(m_strFirewareFile ,CFile::modeRead);     //打开文件
			char pBuf[7];
			filerend.Read(pBuf,7);                   //读取文件
			filerend.Close();
			CString strVersion;
			CString strVersion1;
			strVersion.Format("硬件版本:V%d.%.2d",pBuf[5],pBuf[6]);
			strVersion1.Format("固件版本:V%d.%.2d",pBuf[3],pBuf[4]);
            if(strVersion.CompareNoCase(m_strVersion2)!=0)
			{
				GetDlgItem(IDC_STATICZT)->SetWindowText("硬件版本与板卡硬件版本不匹配！");
				UpdateData(FALSE);
				Invalidate();
				return;
			}

			if(strVersion1.CompareNoCase(m_strVersion3)==0)
			{
			    GetDlgItem(IDC_STATICZT)->SetWindowText("固件版本相同，请勿重复升级！");
				UpdateData(FALSE);
				Invalidate();
				return;

			}
			    CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)SendDATA, this,0,NULL);
				UpdateData(FALSE);
				Invalidate();

	}
	else
		GetDlgItem(IDC_STATICZT)->SetWindowText("获取版本失败...");
	   	UpdateData(FALSE);
		Invalidate();
}


void Cfocus_soundDlg::OnCbnSelchangeComboHversion()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
    
}



BOOL Cfocus_soundDlg::GetDataBuf(char *buff, int nByte)
{
	UpdateData(TRUE);
	BOOL bFlag;
	bFlag =WaitComData(comport,COM_WAIT_TIME/COM_WAIT_COUNT,COM_WAIT_COUNT);
	if(bFlag){ //有返回
		for(int i = 0; i < nByte; i++)
			buff[i] = GetComData(comport);
		return TRUE;
	}
	else
		return FALSE;	
}
BOOL Cfocus_soundDlg::WaitComData(int nPort,int iMSec, int iTimes)
{
	int i=0;
	int len=0;
	
	while(i<iTimes)
	{
		Sleep(iMSec);         //等待的时间
		len = sio_iqueue(nPort); //从串口缓冲区内读出的字节数  
		if(len>0)                 
		{
			return TRUE;
		}
		i++;
	}
	return FALSE;
}
char Cfocus_soundDlg::GetComData(int nPort)
{
	return sio_getch(nPort);
}

void Cfocus_soundDlg::OnBnClickedButtonGetversion()
{
	
    BOOL flag;
	INITSCREEN();
    char buff[6];
    flag=LC_GetVesion(1,buff);
   if(flag==TRUE)
   {

   			m_strVersion.Format("固件版本:V%d.%.2d",buff[0],buff[1]);
			m_strVersion2.Format("硬件版本:V%d.%.2d",buff[2],buff[3]);
			m_Static_Hard.SetWindowText(m_strVersion);
			m_Static_Soft.SetWindowText(m_strVersion2);
			m_strVersion3.Format("V%2d.%.2d",buff[4],buff[5]);
			Cfocus_soundDlg::m_Static_Dsp.SetWindowText(m_strVersion3);

			
			GetDlgItem(IDC_STATICZT)->SetWindowText("获取版本成功...");
			UpdateData(FALSE);
			Invalidate();
   }
  else 
	     GetDlgItem(IDC_STATICZT)->SetWindowText("获取版本失败...");
   		UpdateData(FALSE);
		Invalidate();
}

void Cfocus_soundDlg::OnCbnSelchangeComboDspversion()
{
	// TODO: 在此添加控件通知处理程序代码
		//CString str;
	UpdateData(TRUE);
	Dsp_Type=1;
	if(m_nNumber!=-1&&m_nVoiceType!=-1&&m_nDspVersion!=-1)
	{
		str.Format("V1%d.%d%d",m_nNumber+1,m_nVoiceType+3*m_nHversion,m_nDspVersion);
        m_static_SVersion.SetWindowText(str);
	}
	Invalidate();
}

void Cfocus_soundDlg::OnCbnSelchangeComboComport()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	
}

void Cfocus_soundDlg::OnCbnSelchangeComboSoundtype()
{   
	// TODO: 在此添加控件通知处理程序代码
	//CString str;
	UpdateData(TRUE);
	Dsp_Type=1;
	if(m_nNumber!=-1&&m_nVoiceType!=-1&&m_nDspVersion!=-1)
	{
		str.Format("V1%d.%d%d",m_nNumber+1,m_nVoiceType+m_nHversion*3,m_nDspVersion);
        m_static_SVersion.SetWindowText(str);
	}
	Invalidate();
}

void Cfocus_soundDlg::OnCbnSelchangeComboDspnum()
{
	// TODO: 在此添加控件通知处理程序代码
			//CString str;
	UpdateData(TRUE);
	Dsp_Type=1;
	if(m_nNumber!=-1&&m_nVoiceType!=-1&&m_nDspVersion!=-1)
	{
		str.Format("V1%d.%d%d",m_nNumber+1,m_nVoiceType+3*m_nHversion,m_nDspVersion);
        m_static_SVersion.SetWindowText(str);
	}
	Invalidate();


}

void Cfocus_soundDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);

}

/*void Cfocus_soundDlg::OnNMCustomdrawSliderGain(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
    // m_gain= m_slider.GetPos();
	*pResult = 0;
    UpdateData(FALSE);

	
}*/

void Cfocus_soundDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString strcom;
	int nSel;
    // 获取组合框控件的列表框中选中项的索引   
    nSel = m_colComPort.GetCurSel();   
    // 根据选中项索引获取该项字符串   
    m_colComPort.GetLBText(nSel, strcom);
	comport=string2int(strcom);
}
BOOL Cfocus_soundDlg::FindCommPort(CComboBox &colComPort)
{
	HKEY hKey;
	
	if( ::RegOpenKeyEx( HKEY_LOCAL_MACHINE,
		_T("Hardware\\DeviceMap\\SerialComm"),
		NULL,
		KEY_READ,
		&hKey) == ERROR_SUCCESS) // 打开串口注册表
	{
		int i=0;
		wchar_t portName[256],commName[256];
		DWORD dwLong,dwSize;
		
		while(1)
		{
			dwLong = dwSize = sizeof(portName);
			if( //::RegEnumValue
				RegEnumValueW( hKey,
				i,
				portName,
				&dwLong,
				NULL,
				NULL,
				(PUCHAR)commName,
				&dwSize ) == ERROR_NO_MORE_ITEMS ) // 枚举串口
				break;
			colComPort.AddString( CString(commName)); // commName就是串口名字

			i++;
		}
		
		if( colComPort.GetCount() == 0 )
		{
			//::PostMessage(GetMainFrame()->m_hWnd, WM_UPDATE_SYS_INFO, NULL, (LPARAM)SYSINFO_NO_COM);
			 GetDlgItem(IDC_STATICZT)->SetWindowText("系统没有串口可用...");
		}
		RegCloseKey(hKey);
	}
	return TRUE;
}

void Cfocus_soundDlg::OnBnClickedButtonDsp()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);
	BOOL flag;
	INITSCREEN();
    char buff[6];
	CString str1;
    flag=LC_GetVesion(1,buff);
   if(flag==TRUE)
   {

   			m_strVersion.Format("固件版本:V%d.%.2d",buff[0],buff[1]);
			m_strVersion2.Format("硬件版本:V%d.%.2d",buff[2],buff[3]);
			m_strVersion3.Format("V%2d.%.2d",buff[4],buff[5]);
			str1.Format("固件版本:V0.00");
			m_Static_Hard.SetWindowText(m_strVersion);
			m_Static_Soft.SetWindowText(m_strVersion2);
			Cfocus_soundDlg::m_Static_Dsp.SetWindowText(m_strVersion3);		
			GetDlgItem(IDC_STATICZT)->SetWindowText("获取版本成功...");
			  if(str1.CompareNoCase(m_strVersion)==0)
					{
                   MessageBox("无固件，请先升级固件!");
                    return;
                    }
			   if(str.IsEmpty())
		{
		MessageBox("未选择驱动版本，请选择后进行加载！");
	    return;
	    }
	 GetDlgItem(IDC_STATICZT)->SetWindowText("升级DSP数据中，请勿进行其他操作...");
	 Invalidate();


	int flag1;
	if(Dsp_Type==1)
		{
		flag1=LC_UpdateZiKu(1,1,m_nNumber,m_nVoiceType,m_nDspVersion,m_nHversion);
		}
	else flag1=LC_UpdateZiKu(1,2,m_nMnum,M_size,m_nMtype,0);
	if(flag1==1)
	{
		GetDlgItem(IDC_STATICZT)->SetWindowText("加载DSP数据成功...");
		BOOL flag;
		if(Dsp_Type==1)
		   {
		  flag=LC_SetScreenPar(1,2,(m_nNumber+11)*256+(m_nVoiceType+m_nHversion*3)*10+m_nDspVersion);
		  if(flag==TRUE)
			{
			 GetDlgItem(IDC_STATICZT)->SetWindowText("发送DSP驱动版本成功，加载DSP数据成功...");
			 Invalidate();
			 return;
			}
			else
				GetDlgItem(IDC_STATICZT)->SetWindowText("发送DSP驱动版本失败...");
		  Invalidate();
		    return;
		   }
		if(Dsp_Type==2)
           {
		  flag=LC_SetScreenPar(1,2,(m_nMnum+21)*256+M_size*10+m_nMtype);
		  if(flag==TRUE)
			{
			 GetDlgItem(IDC_STATICZT)->SetWindowText("发送DSP驱动版本成功，加载DSP数据成功...");
			 Invalidate();
			 return;
			 }
			else
				GetDlgItem(IDC_STATICZT)->SetWindowText("发送DSP驱动版本失败...");
		  Invalidate();
		    return;

		   }

	}
   if(flag1==2)
	 {
     GetDlgItem(IDC_STATICZT)->SetWindowText("DSP数据文件缺失...");
	 Invalidate();
	 return;
     }
   else
		GetDlgItem(IDC_STATICZT)->SetWindowText("加载DSP数据失败...");
		 Invalidate();
	    return;
   }
  else 
	     GetDlgItem(IDC_STATICZT)->SetWindowText("获取版本失败...");

		 Invalidate();
		 return;
}

int Cfocus_soundDlg::string2int(CString str)
{
    int length;
    int i;
    TCHAR temp2[15];
    lstrcpy(temp2,str);    //copies a string to a buffer

    TCHAR temp[4];
    int count;
    count=0;
    length=strlen(temp2);    //length保存了字符数组temp2的长度
    for(i=0;i<length;i++)
    {
        if ((temp2[i]<='9')&&(temp2[i]>='0')) 
        {
            temp[count]=temp2[i];
            count++;
        }
    }
    return (::atoi(temp));
}
void Cfocus_soundDlg::OnBnClickedButtonMute()
{
	// TODO: 在此添加控件通知处理程序代码
		BOOL flag;
    //UpdateData(TRUE);
	flag=LC_SetScreenPar(1,3,0);
	if(flag==TRUE)
	{
		GetDlgItem(IDC_STATICZT)->SetWindowText("设置静音成功...");
		Invalidate();
	}
	else
	{
		GetDlgItem(IDC_STATICZT)->SetWindowText("设置静音失败...");
		Invalidate();
	}
}

void Cfocus_soundDlg::OnBnClickedButtonDacOn()
{
	// TODO: 在此添加控件通知处理程序代码
		BOOL flag;
    //UpdateData(TRUE);
	flag=LC_SetScreenPar(1,4,0);
	if(flag==TRUE)
	{
		GetDlgItem(IDC_STATICZT)->SetWindowText("设置使能输出成功...");
		Invalidate();
	}
	else
	{
		GetDlgItem(IDC_STATICZT)->SetWindowText("设置使能输出失败...");
		Invalidate();
	}
}

void Cfocus_soundDlg::OnBnClickedButtonGain()
{
	// TODO: 在此添加控件通知处理程序代码
	BOOL flag;
    //UpdateData(TRUE);
	flag=LC_SetScreenPar(1,5,m_gain);
	if(flag==TRUE)
	{
		GetDlgItem(IDC_STATICZT)->SetWindowText("配置增益成功...");
		Invalidate();
	}
	else
	{
		GetDlgItem(IDC_STATICZT)->SetWindowText("配置增益失败...");
		Invalidate();
	}
}

void Cfocus_soundDlg::OnStnClickedStaticSoftversion()
{
	// TODO: 在此添加控件通知处理程序代码
}


void Cfocus_soundDlg::OnStnClickedStaticSversion()
{
	// TODO: 在此添加控件通知处理程序代码
}

void Cfocus_soundDlg::OnCbnSelchangeComboMsize()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	Dsp_Type=2;
	str1.Format("V2%d.%d%d",M_size+1,m_nMnum,m_nMtype);
    m_static_SVersion.SetWindowText(str1);
	Invalidate();
}

void Cfocus_soundDlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	Dsp_Type=2;
	InitAllCComBoxStatus();
    GetDlgItem(IDC_COMBO_Msize)->EnableWindow(TRUE);
	GetDlgItem(IDC_COMBO_Mnum)->EnableWindow(TRUE);
	GetDlgItem(IDC_COMBO_Mversion)->EnableWindow(TRUE);
    str1.Format("V2%d.%d%d",M_size+1,m_nMnum,m_nMtype);
    m_static_SVersion.SetWindowText(str1);
	Invalidate();
}

void Cfocus_soundDlg::OnBnClickedRadiohuanneng()
{
	// TODO: 在此添加控件通知处理程序代码
	Dsp_Type=1; 
	InitAllCComBoxStatus();
	GetDlgItem(IDC_COMBO_DSPNUM)->EnableWindow(TRUE);
	GetDlgItem(IDC_COMBO_SOUNDTYPE)->EnableWindow(TRUE);
	GetDlgItem(IDC_COMBO_DSPVERSION)->EnableWindow(TRUE);
	GetDlgItem(IDC_COMBO2)->EnableWindow(TRUE);
    str.Format("V1%d.%d%d",m_nNumber+1,m_nVoiceType+3*m_nHversion,m_nDspVersion);
    m_static_SVersion.SetWindowText(str);
	Invalidate();
}
//关闭所有DSP数据选择状态
void Cfocus_soundDlg::InitAllCComBoxStatus() 
{
	GetDlgItem(IDC_COMBO_DSPNUM)->EnableWindow(FALSE);
	GetDlgItem(IDC_COMBO_SOUNDTYPE)->EnableWindow(FALSE);
	GetDlgItem(IDC_COMBO_DSPVERSION)->EnableWindow(FALSE);
	GetDlgItem(IDC_COMBO_Msize)->EnableWindow(FALSE);
	GetDlgItem(IDC_COMBO_Mnum)->EnableWindow(FALSE);
	GetDlgItem(IDC_COMBO_Mversion)->EnableWindow(FALSE);
	GetDlgItem(IDC_COMBO2)->EnableWindow(FALSE);
}
/*
IDC_COMBO2
//Static静止文档模块透明
HBRUSH Cfocus_soundDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
// TODO: Change any attributes of the DC here
CFont m_font;   //声明变量
m_font.CreatePointFont(600,"华文行楷"); //设置字体大小和类型
if(pWnd->GetDlgCtrlID()==IDC_STATIC01)//可以用CTLCOLOR_STATIC表示静态控件
{
   pDC->SelectObject(&m_font);       //设置字体 
   pDC->SetTextColor(RGB(0,0,255)); //设置字体颜色
   pDC->SetBkMode(TRANSPARENT);      //属性设置为透明
   return (HBRUSH)::GetStockObject(NULL_BRUSH); //不返回画刷
}
// TODO: Return a different brush if the default is not desired
return hbr;
}
// Radio和Check模块背景透明
HBRUSH Cfocus_soundDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    //HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
    HBRUSH hbr = ::CreateSolidBrush(#f9f9f9);

    // TODO:  Change any attributes of the DC here

    if (pWnd->GetDlgCtrlID() == IDC_RADIO_REALNAME  ||
        pWnd->GetDlgCtrlID() == IDC_RADIO_ANONYMOUS ||
        pWnd->GetDlgCtrlID() == IDC_CHECK_SELFSELECT)
    {
        pDC->SetBkMode(TRANSPARENT);

        CRect rc;
        pWnd->GetWindowRect(&rc);
        ScreenToClient(&rc);

        CDC* dc = GetDC();
        pDC->BitBlt(0,0,rc.Width(),rc.Height(),dc,rc.left,rc.top,SRCCOPY);    //把父窗口背景先画到按钮上
        ReleaseDC(dc);

        hbr = (HBRUSH) ::GetStockObject(NULL_BRUSH);
    }
	}*/
void Cfocus_soundDlg::OnCbnSelchangeComboMnum()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	Dsp_Type=2;
   str1.Format("V2%d.%d%d",M_size+1,m_nMnum,m_nMtype);
	m_static_SVersion.SetWindowText(str1);
	Invalidate();
}

void Cfocus_soundDlg::OnCbnSelchangeComboMversion()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	Dsp_Type=2;
	str1.Format("V2%d.%d%d",M_size+1,m_nMnum,m_nMtype);
	m_static_SVersion.SetWindowText(str1);
	Invalidate();
}

void Cfocus_soundDlg::OnEnChangeEditGain()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	Invalidate();
}

//设置默认参数

void Cfocus_soundDlg::OnBnClickedButtonSavedata()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString str;
	str.Format("%d",m_nHardType);
	WritePrivateProfileString("HardSet","控制卡类型",str,m_strProjectFilePath);
	str.Format("%d",m_bat);
    WritePrivateProfileString("串口","波特率",str,m_strProjectFilePath);
	str.Format("%d",m_nVoiceType);
	WritePrivateProfileString("换能器","声音类型",str,m_strProjectFilePath);
	str.Format("%d",m_nNumber);
	WritePrivateProfileString("换能器","换能器数量",str,m_strProjectFilePath);
	str.Format("%d",m_nDspVersion);
	WritePrivateProfileString("换能器","换能器大小",str,m_strProjectFilePath);
    str.Format("%d",M_size);
	WritePrivateProfileString("薄膜","薄膜面积",str,m_strProjectFilePath);
    str.Format("%d",m_nMnum);
	WritePrivateProfileString("薄膜","薄膜个数",str,m_strProjectFilePath);
    str.Format("%d",m_nMtype);
	WritePrivateProfileString("薄膜","参数版本",str,m_strProjectFilePath);
    str.Format("%d",Dsp_Type);
	WritePrivateProfileString("输出","输出类型",str,m_strProjectFilePath);
    str.Format("%d",m_nHversion);
    WritePrivateProfileString("换能器","换能器参数版本",str,m_strProjectFilePath);
    UpdateData(FALSE);
	GetDlgItem(IDC_STATICZT)->SetWindowText("设置默认参数成功...");
	Invalidate();
}

//快捷键设置
BOOL Cfocus_soundDlg::PreTranslateMessage(MSG* pMsg)
{
	if(TranslateAccelerator(m_hWnd,hAccKey,pMsg))//打开文件
	     {
		return true;
	     }
		if(TranslateAccelerator(m_hWnd,hupware,pMsg))//升级固件
	     {
		return true;
	     }
			if(TranslateAccelerator(m_hWnd,hgetver,pMsg))//获取版本
	     {
		return true;
	     }
				if(TranslateAccelerator(m_hWnd,hupdsp,pMsg))//升级DSP
	     {
		return true;
	     }
	if (pMsg-> message == WM_KEYDOWN)
		{
         switch (pMsg-> wParam)
		 {
          case VK_ESCAPE:
			  SetFocus ();return TRUE;
          case 'H':
          if(::GetKeyState(VK_CONTROL) < 0&&::GetKeyState(VK_SHIFT) < 0&&::GetKeyState(VK_MENU)<0)
		   if(m_seniorDialog.DoModal()==IDOK)
		   {
			   if(m_seniorDialog.m_senior_password!="audfly_ok")
			        {
				   m_seniorDialog.m_senior_password="";
				   MessageBox("口令错误");
				   return FALSE;
			        }
			   else
			       {
				   	GetDlgItem(IDC_BUTTON_Gain)->EnableWindow(FALSE);
	                GetDlgItem(IDC_BUTTON_MUTE)->EnableWindow(FALSE);
	                GetDlgItem(IDC_BUTTON_DAC_ON)->EnableWindow(FALSE);
	                GetDlgItem(	IDC_RADIO2)->EnableWindow(TRUE);
                    GetDlgItem(	IDC_BUTTON_SaveData)->EnableWindow(TRUE);
	                GetDlgItem(IDC_COMBO_HVERSION)->EnableWindow(TRUE);
	                GetDlgItem(IDC_RADIO_huanneng)->EnableWindow(TRUE);
					GetDlgItem(IDC_COMBO3)->EnableWindow(TRUE);
					if(m_nDspType==1)
						{
							CheckDlgButton(IDC_RADIO_huanneng, 1);
							Cfocus_soundDlg::OnBnClickedRadiohuanneng();
						}
					if(m_nDspType==2)
						{
							 CheckDlgButton(IDC_RADIO2, 1);
							 Cfocus_soundDlg::OnBnClickedRadio2();
						}
					m_seniorDialog.m_senior_password="";
					return TRUE;
			        }

		   }
		   return TRUE;
		  case 'S':
			  if(::GetKeyState(VK_CONTROL) < 0&&::GetKeyState(VK_SHIFT) < 0&&::GetKeyState(VK_MENU)<0)
		         if(m_seniorDialog.DoModal()==IDOK)
		          {
			        if(m_seniorDialog.m_senior_password!="sound_ok")
			           {
				        m_seniorDialog.m_senior_password="";
				        MessageBox("口令错误");
				        return FALSE;
			            }
			        else
			            {
				     	GetDlgItem(IDC_BUTTON_Gain)->EnableWindow(TRUE);
	                    GetDlgItem(IDC_BUTTON_MUTE)->EnableWindow(TRUE);
	                    GetDlgItem(IDC_BUTTON_DAC_ON)->EnableWindow(TRUE);
					    m_seniorDialog.m_senior_password="";
					    return TRUE;
			            }

		        }//endcase
		   return TRUE;


		   }//endswitch
             return TRUE;
		 
}//检查按键
	SendMessage(pMsg->message,pMsg->wParam,pMsg->lParam);
	return 0;
	//return CDialogEx::PreTranslateMessage(pMsg);
}
void Cfocus_soundDlg::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	Dsp_Type=1;
	str.Format("V1%d.%d%d",m_nNumber+1,m_nVoiceType+m_nHversion*3,m_nDspVersion);
    m_static_SVersion.SetWindowText(str);
	Invalidate();
	
}


void Cfocus_soundDlg::OnDropFiles( HDROP hDropInfo )

{
	UINT cFiles = ::DragQueryFile( hDropInfo, 0xffffffff, 0, 0); //取得文件数
	CString szText;
	CString etc;
	CString etc1="hw";
	char szFile[MAX_PATH];
	for( UINT count = 0; count < cFiles; count++ )
	{
		if(cFiles>0)
		{
			::DragQueryFile(hDropInfo, count, szFile, sizeof(szFile));
			szText += szFile; //绝对路径+文件名存于szFile
            szText += "/r/n"; //取所有的文件到szText中，一行一个
            break; //只取得第一个文件
		}
    }
	etc=GetSuffix(szFile).MakeLower();//获取文件后缀名并转换成小写
	if(etc.CompareNoCase(etc1)==0)
		{
		m_strFirewareFile=szFile;
		CFile filerend(m_strFirewareFile ,CFile::modeRead);     //打开文件
		//char pBuf[7];
		filerend.Read(pBuf,7);                   //读取文件
		filerend.Close();
		CString strVersion;
		strVersion.Format("V%d.%d%d",(int)pBuf[3]%16,(int)pBuf[4]/16,(int)pBuf[4]%16);
		Cfocus_soundDlg::m_static_SoftVersion.SetWindowText(strVersion);
		UpdateData(FALSE);
		//相应操作
		}
	else
		  MessageBox("文件类型不对，请重新选择！");

 }

CString Cfocus_soundDlg::GetSuffix(CString strFileName)//获取文件的后缀名
{
return strFileName.Right(strFileName.GetLength()-strFileName.ReverseFind('.')-1);
}




void Cfocus_soundDlg::OnBnClickedButtonsearch()
{
	// TODO: 在此添加控件通知处理程序代码
    Cfocus_soundDlg::m_colComPort.ResetContent();
	FindCommPort(m_colComPort);
}

HBRUSH Cfocus_soundDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)  
{  
    /*HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);  
	
    // TODO:  Change any attributes of the DC here  
  
    // TODO:  Return a different brush if the default is not desired  
    if(pWnd==this) //this代表当前对话框窗口  
    {   
        return   m_brush;   
    }   
  
  //  return hbr;
	
	/* if (nCtlColor == CTLCOLOR_STATIC)  
		{  
			switch (pWnd->GetDlgCtrlID())  
			{  
			 case IDC_STATIC_1:  
				 pDC->SetTextColor(RGB(255, 0, 0));  
				 //pDC->SetBkColor(RGB(255, 255, 255));  
				 pDC->SetBkMode(TRANSPARENT);  
				 pDC->SelectObject(&m_font1);  
				 return (HBRUSH)::GetStockObject(HOLLOW_BRUSH);  
				 break;  
			 case IDC_STATIC_2:  
				 pDC->SetTextColor(RGB(255, 255, 0));  
				// pDC->SetBkColor(RGB(255, 255, 255));  
				 pDC->SelectObject(&m_font2);  
				 return (HBRUSH)::GetStockObject(HOLLOW_BRUSH);  
				 break;  
             default:  
             break;  
        } */
  //HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);  
       if (nCtlColor == CTLCOLOR_DLG)  
            return (HBRUSH)::GetStockObject(HOLLOW_BRUSH);
	    else  
        pDC->SetTextColor(RGB(128, 42, 42)); 
	     /*  if(pWnd==this) //this代表当前对话框窗口  
		 {   
        return   m_brush;   
		 }   */
	   //设置透明背景模式  
		 pDC->SetBkMode(TRANSPARENT);  
		 //设置背景画刷为空  
		return (HBRUSH)::GetStockObject(HOLLOW_BRUSH); 

}

BOOL Cfocus_soundDlg::OnEraseBkgnd(CDC* pDC)  
{  
    // TODO: Add your message handler code here and/or call default  
   /* CDC dc;   
    dc.CreateCompatibleDC(pDC);   
    dc.SelectObject(&bitmap);   
   
    //获取BITMAP对象信息  
    BITMAP hb;   
    bitmap.GetBitmap(&hb);   
   
    //获取窗口客户区大小   
    CRect rt;   
    GetClientRect(&rt);  
   
    //显示位图   
    pDC->StretchBlt(0, 0, rt.Width(), rt.Height(),   
                    &dc, 0, 0, hb.bmWidth, hb.bmHeight, SRCCOPY);   
  
    return TRUE;  */
		CRect	rcRect;
	this->GetClientRect(rcRect);
	
	pDC->FillSolidRect(rcRect, RGB(199, 237, 204));

	return TRUE;
}  
void Cfocus_soundDlg::OnEnUpdateEditFile()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数，以将 EM_SETEVENTMASK 消息发送到该控件，
	// 同时将 ENM_UPDATE 标志“或”运算到 lParam 掩码中。

	// TODO:  在此添加控件通知处理程序代码
	Invalidate();
}


void Cfocus_soundDlg::OnCbnSelchangeCombo3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	switch(m_bat)
	{
	case 0: baud=B_9600;break; 
	case 1: baud=B_12800;break; 
	case 2: baud=B_57600;break; 
	case 3: baud=B_115200;break; 
	}

}
