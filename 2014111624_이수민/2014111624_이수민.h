
// 2014111624_�̼���.h : 2014111624_�̼��� ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy2014111624_�̼���App:
// �� Ŭ������ ������ ���ؼ��� 2014111624_�̼���.cpp�� �����Ͻʽÿ�.
//

class CMy2014111624_�̼���App : public CWinAppEx
{
public:
	CMy2014111624_�̼���App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy2014111624_�̼���App theApp;
