
// PaintView.cpp : ���������� ������ CPaintView
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "Paint.h"
#endif

#include "PaintDoc.h"
#include "PaintView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPaintView

IMPLEMENT_DYNCREATE(CPaintView, CView)

BEGIN_MESSAGE_MAP(CPaintView, CView)
	ON_COMMAND(ID_Brush, &CPaintView::OnBrush)
	ON_COMMAND(ID_Clear, &CPaintView::OnClear)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// ��������/����������� CPaintView

CPaintView::CPaintView() : isPencil()
{
}

CPaintView::~CPaintView()
{
}

BOOL CPaintView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// ��������� CPaintView

void CPaintView::PaintBrush()
{
	auto *mList = GetDocument()->m_ListLine;

	auto current_position = mList->GetHeadPosition();

	while (current_position != NULL)
	{
		// �������� �����
		int extensive = mList->GetAt(current_position).extensive;

		// ���� �����
		COLORREF color = mList->GetAt(current_position).color;

		// ������ ��������� ������ �����
		Line tmp(mList->GetAt(current_position).x_begin, 
				 mList->GetAt(current_position).y_begin, 
				 mList->GetAt(current_position).x_end, 
				 mList->GetAt(current_position).y_end, 
				 color, extensive);

		// ������ �������� ���������
		CClientDC dc(this);

		// ������ ������ �����
		CPen newPen(PS_SOLID, extensive, color);

		// ���������� ����� ���� �������
		dc.SelectObject(&newPen);

		// �������� ����� �� ���������� ����� �� �������
		dc.MoveTo(mList->GetAt(current_position).x_begin, mList->GetAt(current_position).y_begin); // ��������� ����������� ������
		dc.LineTo(mList->GetAt(current_position).x_end, mList->GetAt(current_position).y_end); // �������� �� �������

		current_position = mList->Find(mList->GetNext(current_position));
	}
}

void CPaintView::OnDraw(CDC* /*pDC*/)
{
	CPaintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
}


// ����������� CPaintView

#ifdef _DEBUG
void CPaintView::AssertValid() const
{
	CView::AssertValid();
}

void CPaintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPaintDoc* CPaintView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPaintDoc)));
	return (CPaintDoc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� CPaintView

void CPaintView::OnBrush()
{
	isPencil = TRUE;

	// ������ ������� ��� ������� ����� ���� ��������
	AfxGetApp()->m_pMainWnd->GetMenu()->CheckMenuItem(ID_Brush, MF_CHECKED);
	// ������� ������� � ������ ������
	AfxGetApp()->m_pMainWnd->GetMenu()->CheckMenuItem(ID_Clear, MF_UNCHECKED);
}


void CPaintView::OnClear()
{
	isPencil = FALSE;

	// ������� ������� ��� ������� ����� ���� ��������
	AfxGetApp()->m_pMainWnd->GetMenu()->CheckMenuItem(ID_Brush, MF_UNCHECKED);
	// ������ ������� � ������ ������
	AfxGetApp()->m_pMainWnd->GetMenu()->CheckMenuItem(ID_Clear, MF_CHECKED);
}


void CPaintView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (isPencil == TRUE)
	{

		// �������� �� ������� ����� �������
		if ((nFlags & MK_LBUTTON) != MK_LBUTTON)
			return;

		// �������� �����
		int extensive = GetDocument()->extensive;

		// ���� �����
		COLORREF color = GetDocument()->color;

		// ������ ��������� ������ �����
		Line tmp(previous_x, previous_y, point.x, point.y, color, extensive);

		// ������ �������� ���������
		CClientDC dc(this);

		// ������ ������ �����
		CPen newPen(PS_SOLID, extensive, color);

		// ���������� ����� ���� �������
		dc.SelectObject(&newPen);

		// �������� ����� �� ���������� ����� �� �������
		dc.MoveTo(previous_x, previous_y); // ��������� ����������� ������
		dc.LineTo(point.x, point.y); // �������� �� �������

		// ���������
		previous_x = point.x;
		previous_y = point.y;

		// ��������� ������ ����� � ������
		GetDocument()->GetListLine()->AddHead(tmp);
	}
	else
	{
		// �������� �� ������� ����� �������
		if ((nFlags & MK_LBUTTON) != MK_LBUTTON)
			return;

		// �������� �����
		int extensive = 3 * GetDocument()->extensive;

		// ���� �����
		COLORREF color = RGB(255, 255, 255);

		// ������ ��������� ������ �����
		Line tmp(previous_x, previous_y, point.x, point.y, color, extensive);

		// ������ �������� ���������
		CClientDC dc(this);

		// ������ ������ �����
		CPen newPen(PS_SOLID, extensive, color);

		// ���������� ����� ���� �������
		dc.SelectObject(&newPen);

		// �������� ����� �� ���������� ����� �� �������
		dc.MoveTo(previous_x, previous_y); // ��������� ����������� ������
		dc.LineTo(point.x, point.y); // �������� �� �������

		// ���������
		previous_x = point.x;
		previous_y = point.y;

		// ��������� ������ ����� � ������
		GetDocument()->GetListLine()->AddHead(tmp);
	}
	CView::OnMouseMove(nFlags, point);
}


void CPaintView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// ���������� ���������� �������
	previous_x = point.x;
	previous_y = point.y;

	CView::OnLButtonDown(nFlags, point);
}

void CPaintView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	this->PaintBrush();
}
