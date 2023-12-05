
// lr4.cpp: определяет поведение классов для приложения.
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "lr4.h"
#include "MainFrm.h"

#include "lr4Doc.h"
#include "lr4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clr4App

BEGIN_MESSAGE_MAP(Clr4App, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &Clr4App::OnAppAbout)
	// Стандартные команды по работе с файлами документов
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
END_MESSAGE_MAP()


// Создание Clr4App

Clr4App::Clr4App() noexcept
{

	// TODO: замените ниже строку идентификатора приложения строкой уникального идентификатора; рекомендуемый
	// формат для строки: ИмяКомпании.ИмяПродукта.СубПродукт.СведенияОВерсии
	SetAppID(_T("lr4.AppID.NoVersion"));

	// TODO: добавьте код создания,
	// Размещает весь важный код инициализации в InitInstance
}

// Единственный объект Clr4App

Clr4App theApp;


// Инициализация Clr4App

BOOL Clr4App::InitInstance()
{
	// InitCommonControlsEx() требуются для Windows XP, если манифест
	// приложения использует ComCtl32.dll версии 6 или более поздней версии для включения
	// стилей отображения.  В противном случае будет возникать сбой при создании любого окна.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Выберите этот параметр для включения всех общих классов управления, которые необходимо использовать
	// в вашем приложении.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	EnableTaskbarInteraction(FALSE);

	// Для использования элемента управления RichEdit требуется метод AfxInitRichEdit2()
	// AfxInitRichEdit2();

	// Стандартная инициализация
	// Если эти возможности не используются и необходимо уменьшить размер
	// конечного исполняемого файла, необходимо удалить из следующего
	// конкретные процедуры инициализации, которые не требуются
	// Измените раздел реестра, в котором хранятся параметры
	// TODO: следует изменить эту строку на что-нибудь подходящее,
	// например на название организации
	SetRegistryKey(_T("Локальные приложения, созданные с помощью мастера приложений"));
	LoadStdProfileSettings(4);  // Загрузите стандартные параметры INI-файла (включая MRU)


	// Зарегистрируйте шаблоны документов приложения.  Шаблоны документов
	//  выступают в роли посредника между документами, окнами рамок и представлениями
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(Clr4Doc),
		RUNTIME_CLASS(CMainFrame),       // основное окно рамки SDI
		RUNTIME_CLASS(Clr4View));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// Разрешить использование расширенных символов в горячих клавишах меню
	CMFCToolBar::m_bExtCharTranslation = TRUE;

	// Синтаксический разбор командной строки на стандартные команды оболочки, DDE, открытие файлов
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Включить открытие выполнения DDE
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);


	// Команды диспетчеризации, указанные в командной строке.  Значение FALSE будет возвращено, если
	// приложение было запущено с параметром /RegServer, /Register, /Unregserver или /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// Одно и только одно окно было инициализировано, поэтому отобразите и обновите его
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// вызов DragAcceptFiles только при наличии суффикса
	//  В приложении SDI это должно произойти после ProcessShellCommand
	// Включить открытие перетаскивания
	m_pMainWnd->DragAcceptFiles();
	return TRUE;
}

// Обработчики сообщений Clr4App


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedDeleteButton();
	afx_msg void OnBnClickedEditButton();
	afx_msg void OnBnClickedAddButton();
	afx_msg void OnBnClickedCloseButton();
	afx_msg void OnBnClickedSaveButton();
};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_DELETE_BUTTON, &CAboutDlg::OnBnClickedDeleteButton)
	ON_BN_CLICKED(IDC_EDIT_BUTTON, &CAboutDlg::OnBnClickedEditButton)
	ON_BN_CLICKED(IDC_ADD_BUTTON, &CAboutDlg::OnBnClickedAddButton)
	ON_BN_CLICKED(IDC_CLOSE_BUTTON, &CAboutDlg::OnBnClickedCloseButton)
	ON_BN_CLICKED(IDC_SAVE_BUTTON, &CAboutDlg::OnBnClickedSaveButton)
END_MESSAGE_MAP()

// Команда приложения для запуска диалога
void Clr4App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// Обработчики сообщений Clr4App

void CAboutDlg::OnBnClickedDeleteButton()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CAboutDlg::OnBnClickedEditButton()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CAboutDlg::OnBnClickedAddButton()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CAboutDlg::OnBnClickedCloseButton()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CAboutDlg::OnBnClickedSaveButton()
{
	// TODO: добавьте свой код обработчика уведомлений
}
