
// Shaikhutdinov_3View.cpp: реализация класса CShaikhutdinov3View
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Shaikhutdinov_3.h"
#endif

#include "Shaikhutdinov_3Doc.h"
#include "Shaikhutdinov_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CShaikhutdinov3View

IMPLEMENT_DYNCREATE(CShaikhutdinov3View, CScrollView)

BEGIN_MESSAGE_MAP(CShaikhutdinov3View, CScrollView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Создание или уничтожение CShaikhutdinov3View

CShaikhutdinov3View::CShaikhutdinov3View() noexcept
{
	// TODO: добавьте код создания

}

CShaikhutdinov3View::~CShaikhutdinov3View()
{
}

BOOL CShaikhutdinov3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// Рисование CShaikhutdinov3View

void CShaikhutdinov3View::OnDraw(CDC* pDC)
{
	CShaikhutdinov3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->warehouse.Draw(pDC);
	CSize sizeTotal = pDoc->warehouse.Draw(pDC);

	SetScrollSizes(MM_TEXT, sizeTotal);
	// TODO: добавьте здесь код отрисовки для собственных данных
}

void CShaikhutdinov3View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	//CShaikhutdinov3Doc* pDoc;
	CSize sizeTotal;
	
	//int size_scroll = pDoc->warehouse.Load();

	SetScrollSizes(MM_TEXT, sizeTotal);
}


// Диагностика CShaikhutdinov3View

#ifdef _DEBUG
void CShaikhutdinov3View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CShaikhutdinov3View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CShaikhutdinov3Doc* CShaikhutdinov3View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShaikhutdinov3Doc)));
	return (CShaikhutdinov3Doc*)m_pDocument;
}
#endif //_DEBUG
