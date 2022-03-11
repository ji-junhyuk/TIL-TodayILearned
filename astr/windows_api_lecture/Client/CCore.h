#pragma once

class CCore
{
	SINGLE(CCore);
private:
	HWND	m_hWnd;			// ���� ������ �ڵ�
	POINT	m_ptResolution;	// ���� ������ �ػ�
	HDC		m_hDc;			// ���� �����쿡 Draw �Լ�
public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();
private:
	void update();
	void render();
public:
	HWND GetMainHwnd() { return m_hWnd; }
};