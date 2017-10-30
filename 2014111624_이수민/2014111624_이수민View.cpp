
// 2014111624_�̼���View.cpp : CMy2014111624_�̼���View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "2014111624_�̼���.h"
#endif

#include "2014111624_�̼���Doc.h"
#include "2014111624_�̼���View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2014111624_�̼���View

IMPLEMENT_DYNCREATE(CMy2014111624_�̼���View, CView)

BEGIN_MESSAGE_MAP(CMy2014111624_�̼���View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy2014111624_�̼���View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(IDM_PEN, &CMy2014111624_�̼���View::OnPen)
	ON_COMMAND(IDM_ERASE, &CMy2014111624_�̼���View::OnErase)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy2014111624_�̼���View ����/�Ҹ�

CMy2014111624_�̼���View::CMy2014111624_�̼���View()
	: m_bDraw(false)
	, m_bErase(false)
	, m_bLButtonDown(false)
	, m_bRButtonDown(false)
	, m_ptStart(0)
	, m_ptPrev(0)
	, m_bContextMenu(false)
	, m_bFirst(false)
	, m_nDrawMode(0)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy2014111624_�̼���View::~CMy2014111624_�̼���View()
{
}

BOOL CMy2014111624_�̼���View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy2014111624_�̼���View �׸���

void CMy2014111624_�̼���View::OnDraw(CDC* pDC)
{
	CMy2014111624_�̼���Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	CPen pen, *oldpen;
//	CPen pen2, *oldpen2;
	pen.CreatePen(PS_SOLID, 1, RGB(0,0,0));
//	pen2.CreatePen(PS_SOLID,1, RGB(255,255,255));
	oldpen = pDC-> SelectObject(&pen);
//	oldpen2 = pDC->SelectObject(&pen2);
	pDC-> SetROP2(R2_COPYPEN);

	if(m_nDrawMode==DRAW_MODE)
	{
		pDC->MoveTo(m_ptStart);
		pDC->LineTo(m_ptPrev);
	}
	if(m_nDrawMode==ERASE_MODE)
	{
		
		RECT rectClient;
		GetClientRect(& rectClient);
		ClientToScreen(&rectClient);
		pDC->Rectangle(&rectClient);

	}
	pDC->SelectObject(oldpen);
	pen.DeleteObject();
}


// CMy2014111624_�̼���View �μ�


void CMy2014111624_�̼���View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy2014111624_�̼���View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy2014111624_�̼���View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy2014111624_�̼���View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMy2014111624_�̼���View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy2014111624_�̼���View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	if(!m_bContextMenu)
		theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
	m_bContextMenu=FALSE;
#endif
}


// CMy2014111624_�̼���View ����

#ifdef _DEBUG
void CMy2014111624_�̼���View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2014111624_�̼���View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2014111624_�̼���Doc* CMy2014111624_�̼���View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2014111624_�̼���Doc)));
	return (CMy2014111624_�̼���Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2014111624_�̼���View �޽��� ó����


void CMy2014111624_�̼���View::OnPen()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nDrawMode= DRAW_MODE;
}


void CMy2014111624_�̼���View::OnErase()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nDrawMode= ERASE_MODE;
}


void CMy2014111624_�̼���View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	if(m_bFirst)
	{
		m_ptStart = m_ptPrev = 0;
		m_bLButtonDown = false;
		m_bFirst = true;
		Invalidate(true);
	}

	RECT rectClient;
	GetClientRect(&rectClient);
	ClientToScreen(&rectClient);
	SetCapture();
	ClipCursor(&rectClient);

	if(m_nDrawMode==DRAW_MODE)
	{
		m_bFirst = false;
		m_bLButtonDown = true;
		m_ptStart = m_ptPrev = point;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMy2014111624_�̼���View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	CPen pen, *oldpen;
	pen.CreatePen(PS_SOLID, 1,RGB(0,0,0));
	oldpen = dc.SelectObject(&pen);

	dc.SetROP2(R2_NOTXORPEN);
	 
	if(m_nDrawMode==DRAW_MODE)
	{
		if(m_bLButtonDown)
		{
			dc.MoveTo(m_ptStart);
			dc.LineTo(m_ptPrev);
			dc.MoveTo(m_ptStart);
			dc.LineTo(point);
			m_ptPrev = point;
		}
	}

	CView::OnMouseMove(nFlags, point);
}


void CMy2014111624_�̼���View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_bContextMenu=TRUE;

	RECT rectClient;
	GetClientRect(&rectClient);
	ClientToScreen(&rectClient);
	SetCapture();
	ClipCursor(&rectClient);

	if(m_nDrawMode==ERASE_MODE)
	{
		m_bFirst = false;
		m_bRButtonDown = true;
	}

	CView::OnRButtonDown(nFlags, point);
}


void CMy2014111624_�̼���View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(m_bLButtonDown)
		{
			if(m_nDrawMode==DRAW_MODE)
			{
				m_bLButtonDown = false;
				m_bFirst = true;
				ReleaseCapture();
				::ClipCursor(NULL);
				Invalidate(true);
			}
		}
	CView::OnLButtonUp(nFlags, point);
}
