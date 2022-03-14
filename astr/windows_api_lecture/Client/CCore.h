#pragma once

class CCore
{
	SINGLE(CCore);
private:
	HWND	m_hWnd;			// ���� ������ �ڵ�
	POINT	m_ptResolution;	// ���� ������ �ػ�
	HDC		m_hDc;			// ���� �����쿡 Draw �Լ�

	HBITMAP	m_hBit;
	HDC		m_memDC;

	// ���� ����ϴ� GDI Object
	HBRUSH	m_arrBrush[(UINT)BRUSH_TYPE::END];
	HPEN	m_arrPen[(UINT)PEN_TYPE::END];
public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();
private:
	void CreateBrushPen();
public:
	HWND GetMainHwnd() { return m_hWnd; }
	HDC	GetMainDC() { return m_hDc; }
	POINT GetResolution() { return m_ptResolution; }
	HBRUSH GetBrush(BRUSH_TYPE _eType) { return m_arrBrush[(UINT)_eType]; }
	HPEN GetPen(PEN_TYPE _eType) { return m_arrPen[(UINT)_eType]; }
};