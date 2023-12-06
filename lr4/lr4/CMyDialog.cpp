﻿// CMyDialog.cpp: файл реализации
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
	DDX_Control(pDX, IDC_DELETE_BUTTON, DELETE_BUTTON);
	DDX_Control(pDX, IDC_CLOSE_BUTTON, CLOSE_BUTTON);
	DDX_Control(pDX, IDC_EDIT1, EditMake);
	DDX_Control(pDX, IDC_EDIT2, EditModel);
	DDX_Control(pDX, IDC_EDIT3, EditPower);
	DDX_Control(pDX, IDC_EDIT4, EditEC);
	DDX_Control(pDX, IDC_EDIT5, EditPYear);
	DDX_Control(pDX, IDC_EDIT6, EditNOwners);
	DDX_Control(pDX, IDC_EDIT7, EditMileage);
	DDX_Control(pDX, IDC_ADDC_BUTTON, ADDC_BUTTON);
	DDX_Control(pDX, IDC_ADDUC_BUTTON, ADDUC_BUTTON);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialogEx)
	ON_BN_CLICKED(IDC_DELETE_BUTTON, &CMyDialog::OnBnClickedDeleteButton)
	ON_BN_CLICKED(IDC_CLOSE_BUTTON, &CMyDialog::OnBnClickedCloseButton)
	ON_BN_CLICKED(IDC_SAVE_BUTTON, &CMyDialog::OnBnClickedSaveButton)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMyDialog::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_ADDUC_BUTTON, &CMyDialog::OnBnClickedAdducButton)
	ON_BN_CLICKED(IDC_ADDC_BUTTON, &CMyDialog::OnBnClickedAddcButton)
END_MESSAGE_MAP()


// Обработчики сообщений CMyDialog

void CMyDialog::ClearEdit()
{
	EditMake.SetWindowTextW(L"");
	EditModel.SetWindowTextW(L"");
	EditPower.SetWindowTextW(L"");
	EditEC.SetWindowTextW(L"");
	EditPYear.SetWindowTextW(L"");
	EditNOwners.SetWindowTextW(L"");
	EditMileage.SetWindowTextW(L"");
}

void CMyDialog::EditShow(bool show) {
	if (show) {
		EditMake.ShowWindow(SW_SHOW);
		EditModel.ShowWindow(SW_SHOW);
		EditPower.ShowWindow(SW_SHOW);
		EditEC.ShowWindow(SW_SHOW);
		EditPYear.ShowWindow(SW_SHOW);
	}
	else {
		EditMake.ShowWindow(SW_HIDE);
		EditModel.ShowWindow(SW_HIDE);
		EditPower.ShowWindow(SW_HIDE);
		EditEC.ShowWindow(SW_HIDE);
		EditPYear.ShowWindow(SW_HIDE);
	}
}

BOOL CMyDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	if (!pDoc->warehouse.Empty())
	{
		for (int i = 0; i < pDoc->warehouse.Size(); ++i)
		{
			CString s = pDoc->warehouse.GetCStr(i, 0) + L" " + pDoc->warehouse.GetCStr(i, 1);
			ListBox1.AddString(s);
			ListBox1.SetCurSel(0);
		}
	}
	else {
		EditShow(TRUE);
		EditNOwners.ShowWindow(SW_HIDE);
		EditMileage.ShowWindow(SW_HIDE);
	}
	OnLbnSelchangeList1();
	return TRUE;
}


void CMyDialog::OnLbnSelchangeList1()
{
	int n = ListBox1.GetCurSel();
	if (n < 0 || (pDoc->warehouse.Size()!= ListBox1.GetCount()))
		return;
	ListBox1.SetCurSel(n);
	FillEdit(n);
}

void CMyDialog::FillEdit(int n)
{
	if (!pDoc->warehouse.Size()) { return; }
	if (n >= 0) {
		EditMake.SetWindowTextW(pDoc->warehouse.GetCStr(n, 0));
		EditModel.SetWindowTextW(pDoc->warehouse.GetCStr(n, 1));
		EditPower.SetWindowTextW(pDoc->warehouse.GetCStr(n, 2));
		EditEC.SetWindowTextW(pDoc->warehouse.GetCStr(n, 3));
		EditPYear.SetWindowTextW(pDoc->warehouse.GetCStr(n, 4));
		if (pDoc->warehouse.GetCStr(n, 5) != L"") {
			EditNOwners.ShowWindow(SW_SHOW);
			EditMileage.ShowWindow(SW_SHOW);
			EditNOwners.SetWindowTextW(pDoc->warehouse.GetCStr(n, 5));
			EditMileage.SetWindowTextW(pDoc->warehouse.GetCStr(n, 6));
		}
		else {
			EditNOwners.ShowWindow(SW_HIDE);
			EditMileage.ShowWindow(SW_HIDE);
			EditNOwners.SetWindowTextW(L"");
			EditMileage.SetWindowTextW(L"");
		}
	}
	else {
		ClearEdit();
		EditMake.ShowWindow(SW_HIDE);
		EditModel.ShowWindow(SW_HIDE);
		EditPower.ShowWindow(SW_HIDE);
		EditEC.ShowWindow(SW_HIDE);
		EditPYear.ShowWindow(SW_HIDE);
		EditNOwners.ShowWindow(SW_HIDE);
		EditMileage.ShowWindow(SW_HIDE);
	}
}


void CMyDialog::OnBnClickedSaveButton()
{
	int n = ListBox1.GetCurSel();
	int m = ListBox1.GetCount();
	if (n < 0)
		return;
	vector<CString> car;
	CString str;

	EditMake.GetWindowTextW(str);
	car.push_back(str);
	EditModel.GetWindowTextW(str);
	car.push_back(str);
	EditPower.GetWindowTextW(str);
	car.push_back(str);
	EditEC.GetWindowTextW(str);
	car.push_back(str);
	EditPYear.GetWindowTextW(str);
	car.push_back(str);
	EditNOwners.GetWindowTextW(str);
	car.push_back(str);
	EditMileage.GetWindowTextW(str);
	car.push_back(str);

	bool flag = TRUE;

	if (car[0]!=L"" && car[1]!=L"") {flag == FALSE;}
	if (EditMileage.IsWindowVisible()) {
		car[0] = L"safsadsa";
	}
	if (flag) {
		pDoc->warehouse.AddObj(car, n);
	}
}


void CMyDialog::OnBnClickedDeleteButton()
{
	int n = ListBox1.GetCurSel();
	if (n < 0 || !pDoc->warehouse.Size())
		return;
	pDoc->warehouse.EraseObj(n);
	ListBox1.DeleteString(n);
	if (pDoc->warehouse.Size() == n) { n -= 1;}
	ListBox1.SetCurSel(n);
	FillEdit(n);
}


void CMyDialog::OnBnClickedCloseButton()
{
	EndDialog(1);
}

void CMyDialog::OnBnClickedAdducButton()
{
	ClearEdit();
	ListBox1.AddString(L"");
	ListBox1.SetCurSel(pDoc->warehouse.Size());
	vector<CString> car;
	EditShow(TRUE);
	EditNOwners.ShowWindow(SW_SHOW);
	EditMileage.ShowWindow(SW_SHOW);
}


void CMyDialog::OnBnClickedAddcButton()
{
	ClearEdit();
	ListBox1.AddString(L"");
	ListBox1.SetCurSel(pDoc->warehouse.Size());
	EditShow(TRUE);
	EditNOwners.ShowWindow(SW_HIDE);
	EditMileage.ShowWindow(SW_HIDE);
}
