
// SDI_First_Project_One_VersionDoc.h : ��������� ������ CSDI_First_Project_One_VersionDoc
//


#pragma once


class CSDI_First_Project_One_VersionDoc : public CDocument
{
protected: // ������� ������ �� ������������
	CSDI_First_Project_One_VersionDoc();
	DECLARE_DYNCREATE(CSDI_First_Project_One_VersionDoc)

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
	virtual ~CSDI_First_Project_One_VersionDoc();
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
