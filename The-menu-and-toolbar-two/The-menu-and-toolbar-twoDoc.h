
// The-menu-and-toolbar-twoDoc.h : ��������� ������ CThemenuandtoolbartwoDoc
//


#pragma once


class CThemenuandtoolbartwoDoc : public CDocument
{
protected: // ������� ������ �� ������������
	CThemenuandtoolbartwoDoc();
	DECLARE_DYNCREATE(CThemenuandtoolbartwoDoc)

// ��������
public:

// ��������
public:

// ���������������
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ����������
public:
	virtual ~CThemenuandtoolbartwoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ��������������� �������, �������� ���������� ������ ��� ����������� ������
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
