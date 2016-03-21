
// PaintView.h : ��������� ������ CPaintView
//

#pragma once


class CPaintView : public CView
{
protected: // ������� ������ �� ������������
	CPaintView();
	DECLARE_DYNCREATE(CPaintView)

// ��������
public:
	CPaintDoc* GetDocument() const;

	// ����� ��������� ��� �������. (�������� = TRUE, ������ = FALSE)
	BOOL isPencil;

	// ���������� ���������� �����
	int previous_x;
	int previous_y;

	// �����������
	CBitmap m_Bitmap;

	// ����� ����������� �� �����
	void DisplayBitmap(CDC *PDC, CBitmap *PBitmap, int X, int Y)
	{
		BITMAP BM;
		CDC MemDC;

		MemDC.CreateCompatibleDC(NULL);
		MemDC.SelectObject(PBitmap);

		PBitmap->GetObject(sizeof(BM), &BM);

		PDC->BitBlt(X, Y, BM.bmWidth, BM.bmHeight, &MemDC, 0, 0, SRCCOPY);
	}

// ��������
public:

// ���������������
public:
	virtual void OnDraw(CDC* pDC);  // �������������� ��� ��������� ����� �������������
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ����������
public:
	virtual ~CPaintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBrush();
	afx_msg void OnClear();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ���������� ������ � PaintView.cpp
inline CPaintDoc* CPaintView::GetDocument() const
   { return reinterpret_cast<CPaintDoc*>(m_pDocument); }
#endif

