#pragma once

//cf.
// ����
// ����
// ���� (������ ����)
// 1. �Լ� �ȿ�
// 2. ���� 
// 3. Ŭ���� �ȿ� 
// ��������� Ŭ���� �ۿ��� �ݵ�� �ʱ�ȭ���־�� �Ѵ�.
// �ܺ�

// �̱��� ����
// ��ü�� ������ 1���� ����
// ��𼭵� ���� ���� ����

/*
class CCore
{
private:
	static CCore* g_pInst;
public:
	// ���� ����Լ�, ��ü ���� ȣ�� ���� ��, ����� ���� �Ұ���(this Ű���尡 ����), ���� ����� ���� ����.
	static CCore* GetInstance()
	{
		if (g_pInst == nullptr)
		{
			g_pInst = new CCore;
		}
		return g_pInst;
	}
	static void Release()
	{
		if (g_pInst != nullptr)
		{
			delete g_pInst;
			g_pInst = nullptr;
		}
	}
private:
	CCore();
	~CCore();
};
*/

class CCore
{
	SINGLE(CCore);
	//static CCore* GetInst()
	//{
	//	static CCore core;

	//	return &core;
	//}
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
private:
	CCore();
	~CCore();
};