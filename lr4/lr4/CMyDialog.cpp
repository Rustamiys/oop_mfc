// CMyDialog.cpp: файл реализации
//

#include "pch.h"
#include "lr4.h"
#include "afxdialogex.h"
#include "CMyDialog.h"


// Диалоговое окно CMyDialog

IMPLEMENT_DYNAMIC(CMyDialog, CDialogEx)

CMyDialog::CMyDialog(Clr4Doc* pDoc,CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent), pDoc(pDoc)
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, ListBox1);
	DDX_Control(pDX, IDC_EDIT_BUTTON, EDIT_BUTTON);
	DDX_Control(pDX, IDC_DELETE_BUTTON, DELETE_BUTTON);
	DDX_Control(pDX, IDC_ADD_BUTTON, ADD_BUTTON);
	DDX_Control(pDX, IDC_CLOSE_BUTTON, CLOSE_BUTTON);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialogEx)
	ON_BN_CLICKED(IDC_ADD_BUTTON, &CMyDialog::OnBnClickedAddButton)
	ON_BN_CLICKED(IDC_DELETE_BUTTON, &CMyDialog::OnBnClickedDeleteButton)
	ON_BN_CLICKED(IDC_EDIT_BUTTON, &CMyDialog::OnBnClickedEditButton)
	ON_BN_CLICKED(IDC_CLOSE_BUTTON, &CMyDialog::OnBnClickedCloseButton)
	ON_BN_CLICKED(IDC_SAVE_BUTTON, &CMyDialog::OnBnClickedSaveButton)
END_MESSAGE_MAP()


// Обработчики сообщений CMyDialog

void CMyDialog::OnBnClickedSaveButton()
{
	// TODO: добавьте свой код обработчика уведомлений
}

BOOL CMyDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	if (!pDoc->warehouse.Empty())
	{
		for (auto& p : pDoc->warehouse)
		{
			CString s;
			//s.Format("%d x %d", p.x, p.y);
		//	m_List.AddString(s);
			ListBox1.AddString(s);
		//	m_List.SetCurSel(0);
		//	m_Combo.SetCurSel(0);
		}
		//OnLbnSelchangeList();
	}


	return TRUE;
}

void CMyDialog::OnBnClickedAddButton()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CMyDialog::OnBnClickedDeleteButton()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CMyDialog::OnBnClickedEditButton()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CMyDialog::OnBnClickedCloseButton()
{
	// TODO: добавьте свой код обработчика уведомлений
}
