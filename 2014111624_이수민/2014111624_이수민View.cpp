
// 2014111624_이수민View.cpp : CMy2014111624_이수민View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "2014111624_이수민.h"
#endif

#include "2014111624_이수민Doc.h"
#include "2014111624_이수민View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2014111624_이수민View

IMPLEMENT_DYNCREATE(CMy2014111624_이수민View, CView)

BEGIN_MESSAGE_MAP(CMy2014111624_이수민View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy2014111624_이수민View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(IDM_PEN, &CMy2014111624_이수민View::OnPen)
	ON_COMMAND(IDM_ERASE, &CMy2014111624_이수민View::OnErase)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy2014111624_이수민View 생성/소멸

CMy2014111624_이수민View::CMy2014111624_이수민View()
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
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy2014111624_이수민View::~CMy2014111624_이수민View()
{
}

BOOL CMy2014111624_이수민View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy2014111624_이수민View 그리기

void CMy2014111624_이수민View::OnDraw(CDC* pDC)
{
	CMy2014111624_이수민Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
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


// CMy2014111624_이수민View 인쇄


void CMy2014111624_이수민View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy2014111624_이수민View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy2014111624_이수민View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy2014111624_이수민View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMy2014111624_이수민View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy2014111624_이수민View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	if(!m_bContextMenu)
		theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
	m_bContextMenu=FALSE;
#endif
}


// CMy2014111624_이수민View 진단

#ifdef _DEBUG
void CMy2014111624_이수민View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2014111624_이수민View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2014111624_이수민Doc* CMy2014111624_이수민View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2014111624_이수민Doc)));
	return (CMy2014111624_이수민Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2014111624_이수민View 메시지 처리기


void CMy2014111624_이수민View::OnPen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nDrawMode= DRAW_MODE;
}


void CMy2014111624_이수민View::OnErase()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nDrawMode= ERASE_MODE;
}


void CMy2014111624_이수민View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

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


void CMy2014111624_이수민View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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


void CMy2014111624_이수민View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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


void CMy2014111624_이수민View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
