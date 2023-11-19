
// Shaikhutdinov_3Doc.cpp: реализация класса CShaikhutdinov3Doc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Shaikhutdinov_3.h"
#endif

#include "Shaikhutdinov_3Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CShaikhutdinov3Doc

IMPLEMENT_DYNCREATE(CShaikhutdinov3Doc, CDocument)

BEGIN_MESSAGE_MAP(CShaikhutdinov3Doc, CDocument)
END_MESSAGE_MAP()


// Создание или уничтожение CShaikhutdinov3Doc

CShaikhutdinov3Doc::CShaikhutdinov3Doc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CShaikhutdinov3Doc::~CShaikhutdinov3Doc()
{
}

BOOL CShaikhutdinov3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	warehouse.Clear();
	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// Сериализация CShaikhutdinov3Doc

void CShaikhutdinov3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		warehouse.Save(ar);
		// TODO: добавьте код сохранения
	}
	else
	{
		warehouse.Clear();
		warehouse.Load(ar);
		// TODO: добавьте код загрузки
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CShaikhutdinov3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CShaikhutdinov3Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CShaikhutdinov3Doc::SetSearchContent(const CString& value)
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

// Диагностика CShaikhutdinov3Doc

#ifdef _DEBUG
void CShaikhutdinov3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CShaikhutdinov3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CShaikhutdinov3Doc
