
// lr4Doc.h: интерфейс класса Clr4Doc 
//


#pragma once
#include "Shaikhutdinov_Warehouse.h"

class Clr4Doc : public CDocument
{
protected: // создать только из сериализации
	Clr4Doc() noexcept;
	DECLARE_DYNCREATE(Clr4Doc)

// Атрибуты
public:
	Shaikhutdinov_Warehouse warehouse;
// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~Clr4Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnEditDialog();
};
