
// lr4Doc.cpp: реализация класса Clr4Doc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "lr4.h"
#endif

#include "lr4Doc.h"
#include "CMyDialog.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Clr4Doc

IMPLEMENT_DYNCREATE(Clr4Doc, CDocument)

BEGIN_MESSAGE_MAP(Clr4Doc, CDocument)
	ON_COMMAND(ID_APP_ABOUT, &Clr4Doc::OnEditDialog)
END_MESSAGE_MAP()


// Создание или уничтожение Clr4Doc

Clr4Doc::Clr4Doc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора

}

Clr4Doc::~Clr4Doc()
{
}

BOOL Clr4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	warehouse.Clear();
	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// Сериализация Clr4Doc

void Clr4Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		warehouse.Save(ar);

	}
	else
	{
		warehouse.Clear();
		warehouse.Load(ar);
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void Clr4Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void Clr4Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void Clr4Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика Clr4Doc

#ifdef _DEBUG
void Clr4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Clr4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды Clr4Doc


void Clr4Doc::OnEditDialog()
{
	CMyDialog dlg(this);
	if (dlg.DoModal() == IDOK)
		UpdateAllViews(NULL);
}

