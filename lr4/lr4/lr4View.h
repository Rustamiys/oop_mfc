
// lr4View.h: интерфейс класса Clr4View
//

#pragma once


class Clr4View : public CScrollView
{
protected: // создать только из сериализации
	Clr4View() noexcept;
	DECLARE_DYNCREATE(Clr4View)

// Атрибуты
public:
	Clr4Doc* GetDocument() const;

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
	virtual ~Clr4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в lr4View.cpp
inline Clr4Doc* Clr4View::GetDocument() const
   { return reinterpret_cast<Clr4Doc*>(m_pDocument); }
#endif

