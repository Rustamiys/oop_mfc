
// lr4View.cpp: реализация класса Clr4View
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "lr4.h"
#include "CMyDialog.h"
#endif

#include "lr4Doc.h"
#include "lr4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clr4View

IMPLEMENT_DYNCREATE(Clr4View, CScrollView)

BEGIN_MESSAGE_MAP(Clr4View, CScrollView)
	ON_COMMAND(IDC_CLOSE_BUTTON, &Clr4View::OnEditMenu)
END_MESSAGE_MAP()

// Создание или уничтожение Clr4View

Clr4View::Clr4View() noexcept
{
	// TODO: добавьте код создания

}

Clr4View::~Clr4View()
{
}

BOOL Clr4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// Рисование Clr4View

void Clr4View::OnDraw(CDC* pDC)
{
	Clr4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->warehouse.Draw(pDC);
	CSize sizeTotal = pDoc->warehouse.Draw(pDC);
	SetScrollSizes(MM_TEXT, sizeTotal);

	// TODO: добавьте здесь код отрисовки для собственных данных
}

void Clr4View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	CSize sizeTotal;
	//int size_scroll = pDoc->warehouse.Load();
	SetScrollSizes(MM_TEXT, sizeTotal);

}


// Диагностика Clr4View

#ifdef _DEBUG
void Clr4View::AssertValid() const
{
	CScrollView::AssertValid();
}

void Clr4View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

Clr4Doc* Clr4View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clr4Doc)));
	return (Clr4Doc*)m_pDocument;
}
#endif //_DEBUG

void Clr4View::OnEditMenu()
{
	CMyDialog EditDialog(GetDocument());
	EditDialog.DoModal();

	Invalidate();
}

// Обработчики сообщений Clr4View
// обработчик исключений
// readonly
// 
//
