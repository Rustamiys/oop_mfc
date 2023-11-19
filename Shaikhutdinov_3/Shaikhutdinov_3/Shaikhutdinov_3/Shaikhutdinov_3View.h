
// Shaikhutdinov_3View.h: интерфейс класса CShaikhutdinov3View
//

#pragma once


class CShaikhutdinov3View : public CScrollView
{
protected: // создать только из сериализации
	CShaikhutdinov3View() noexcept;
	DECLARE_DYNCREATE(CShaikhutdinov3View)

// Атрибуты
public:
	CShaikhutdinov3Doc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора

// Реализация
public:
	virtual ~CShaikhutdinov3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в Shaikhutdinov_3View.cpp
inline CShaikhutdinov3Doc* CShaikhutdinov3View::GetDocument() const
   { return reinterpret_cast<CShaikhutdinov3Doc*>(m_pDocument); }
#endif

