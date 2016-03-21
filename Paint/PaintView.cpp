
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
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// ��������/����������� CPaintView

CPaintView::CPaintView() : isPencil(TRUE)
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

void CPaintView::OnDraw(CDC* pDC)
{
	CPaintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// ����� ������� ����
	CRect rect = new CRect;
	GetClientRect(rect);

	// ������ ����� �������� ����������
	CDC p_newDC;
	p_newDC.CreateCompatibleDC(pDC);

	// ������ ����������� ����������� � ������ ����������� �����������
	m_Bitmap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());

	p_newDC.SelectObject(&m_Bitmap);

	auto *mList = GetDocument()->GetListLine();

	auto current_position = mList->GetTailPosition();

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

		// ������ ������ �����
		CPen newPen(PS_SOLID, extensive, color);

		// ���������� ����� ���� �������
		p_newDC.SelectObject(&newPen);

		// �������� ����� �� ���������� ����� �� �������
		p_newDC.MoveTo(mList->GetAt(current_position).x_begin,
			mList->GetAt(current_position).y_begin); // ��������� ����������� ������
		p_newDC.LineTo(mList->GetAt(current_position).x_end,
			mList->GetAt(current_position).y_end); // �������� �� �������

		mList->GetPrev(current_position);
	}

	DisplayBitmap(pDC, &m_Bitmap, 0, 0);

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
	// �������� �� ������� ����� �������
	//if ((nFlags | MK_LBUTTON) == MK_LBUTTON)
	if (GetDocument()->isLeftButtonMouse == TRUE)
	{
		if (isPencil == TRUE)
		{
			// �������� �����
			int extensive = GetDocument()->extensive;

			// ���� �����
			COLORREF color = GetDocument()->color;

			// ������ ��������� ������ �����
			Line tmp(previous_x, previous_y, point.x, point.y, color, extensive);

			// ���������
			previous_x = point.x;
			previous_y = point.y;

			// ��������� ������ ����� � ������
			GetDocument()->GetListLine()->AddHead(tmp);
		}
		else
		{
			// �������� �����
			int extensive = 3 * GetDocument()->extensive;

			// ���� �����
			COLORREF color = RGB(255, 255, 255);

			// ������ ��������� ������ �����
			Line tmp(previous_x, previous_y, point.x, point.y, color, extensive);

			// ���������
			previous_x = point.x;
			previous_y = point.y;

			// ��������� ������ ����� � ������
			GetDocument()->GetListLine()->AddHead(tmp);
		}

		Invalidate();
	}

	CView::OnMouseMove(nFlags, point);
}

void CPaintView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// ���������� ���������� �������
	previous_x = point.x;
	previous_y = point.y;

	// ������ ����� ������� ����
	GetDocument()->isLeftButtonMouse = TRUE;

	CView::OnLButtonDown(nFlags, point);
}

void CPaintView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// ����� ������� ��������
	GetDocument()->isLeftButtonMouse = FALSE;

	CView::OnLButtonUp(nFlags, point);
}
