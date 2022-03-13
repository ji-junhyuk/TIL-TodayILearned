#pragma once

class CCore
{
	SINGLE(CCore);
private:
	HWND	m_hWnd;			// 메인 윈도우 핸들
	POINT	m_ptResolution;	// 메인 윈도우 해상도
	HDC		m_hDc;			// 메인 윈도우에 Draw 함수

	HBITMAP	m_hBit;
	HDC		m_memDC;

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();
private:
	void update();
	void render();
public:
	HWND GetMainHwnd() { return m_hWnd; }
	HDC	GetMainDC() { return m_hDc; }
	POINT GetResolution() { return m_ptResolution; }
};