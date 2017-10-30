
// 2014111624_이수민View.h : CMy2014111624_이수민View 클래스의 인터페이스
//
enum DRAW{DRAW_NONE,DRAW_MODE,ERASE_MODE};
#pragma once
#include "atltypes.h"


class CMy2014111624_이수민View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy2014111624_이수민View();
	DECLARE_DYNCREATE(CMy2014111624_이수민View)

// 특성입니다.
public:
	CMy2014111624_이수민Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMy2014111624_이수민View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPen();
	bool m_bDraw;
	afx_msg void OnErase();
	bool m_bErase;
	bool m_bLButtonDown;
	bool m_bRButtonDown;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CPoint m_ptStart;
	CPoint m_ptPrev;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	bool m_bContextMenu;
	bool m_bFirst;
	int m_nDrawMode;
};

#ifndef _DEBUG  // 2014111624_이수민View.cpp의 디버그 버전
inline CMy2014111624_이수민Doc* CMy2014111624_이수민View::GetDocument() const
   { return reinterpret_cast<CMy2014111624_이수민Doc*>(m_pDocument); }
#endif

