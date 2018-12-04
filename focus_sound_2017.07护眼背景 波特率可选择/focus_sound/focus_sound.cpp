
// focus_sound.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "focus_sound.h"
#include "focus_soundDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cfocus_soundApp

BEGIN_MESSAGE_MAP(Cfocus_soundApp, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// Cfocus_soundApp 构造

Cfocus_soundApp::Cfocus_soundApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 Cfocus_soundApp 对象

Cfocus_soundApp theApp;


// Cfocus_soundApp 初始化

BOOL Cfocus_soundApp::InitInstance()

{
	if(m_pswDialog.DoModal()==IDOK)//用户单击“确定”
	{
		if(m_pswDialog.m_paasWord!="focus_sound")
			{
				//如果口令不对，则显示出错信息，结束程序
			MessageBox(NULL,_T("口令错误，即将退出程序"),_T("错误"),MB_OK|MB_ICONERROR);
			return FALSE;
			}
	     //MessageBox(NULL,_T("口令正确，确定后将运行程序"),_T("正确"),MB_OK|MB_ICONASTERISK);
		//此处加入CDKEY校验。
	}
	else
		return FALSE;//当用户点击取消时，要退出所有程序
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	AfxEnableControlContainer();

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	Cfocus_soundDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}
