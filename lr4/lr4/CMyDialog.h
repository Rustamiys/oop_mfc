#pragma once
#include "afxdialogex.h"
#include "lr4Doc.h"

// Диалоговое окно CMyDialog
class Clr4Doc;

class CMyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDialog)
public:
	Clr4Doc* pDoc;

public:
	CMyDialog(Clr4Doc*, CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CMyDialog();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()

public:

	CListBox ListBox1;
	CButton EDIT_BUTTON;
	CButton DELETE_BUTTON;
	CButton ADD_BUTTON;
	CButton CLOSE_BUTTON;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedAddButton();
	afx_msg void OnBnClickedDeleteButton();
	afx_msg void OnBnClickedEditButton();
	afx_msg void OnBnClickedCloseButton();
	afx_msg void OnBnClickedSaveButton();
};
