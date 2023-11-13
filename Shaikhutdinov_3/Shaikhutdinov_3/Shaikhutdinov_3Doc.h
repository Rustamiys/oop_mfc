
// Shaikhutdinov_3Doc.h: интерфейс класса CShaikhutdinov3Doc 
//


#pragma once
#include "Shaikhutdinov_Warehouse.h"

class CShaikhutdinov3Doc : public CDocument
{
protected: // создать только из сериализации
	CShaikhutdinov3Doc() noexcept;
	DECLARE_DYNCREATE(CShaikhutdinov3Doc)

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
	virtual ~CShaikhutdinov3Doc();
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
};
