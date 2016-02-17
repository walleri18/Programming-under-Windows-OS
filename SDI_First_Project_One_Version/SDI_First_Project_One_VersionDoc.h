
// SDI_First_Project_One_VersionDoc.h : интерфейс класса CSDI_First_Project_One_VersionDoc
//


#pragma once


class CSDI_First_Project_One_VersionDoc : public CDocument
{
protected: // создать только из сериализации
	CSDI_First_Project_One_VersionDoc();
	DECLARE_DYNCREATE(CSDI_First_Project_One_VersionDoc)

// Атрибуты
public:

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
	virtual ~CSDI_First_Project_One_VersionDoc();
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
