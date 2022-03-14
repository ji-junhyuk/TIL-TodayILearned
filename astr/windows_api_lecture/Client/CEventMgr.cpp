#include "pch.h"
#include "CEventMgr.h"
#include "CObject.h"
#include "CSceneMgr.h"
#include "CScene.h"

CEventMgr::CEventMgr()
{

}

CEventMgr::~CEventMgr()
{

}

void CEventMgr::update()
{
	// ================================================
	// ���� �����ӿ��� ����ص� Dead Object�� �����Ѵ�.
	// ================================================
	for (size_t idx = 0; idx < m_vecEvent.size(); ++idx)
	{
		delete m_vecDead[idx];
	}
	m_vecDead.clear();
	// ===========
	// �̺�Ʈ ó��
	// ===========
	for (size_t idx = 0; idx < m_vecEvent.size(); ++idx)
	{
		Excute(m_vecEvent[idx]);
	}
	m_vecEvent.clear();
}

void CEventMgr::Excute(const tEvent& _eve)
{
	switch (_eve.eEven)
	{
	case EVENT_TYPE::CREATE_OBJECT:
	{
		// lParam : Obejct Address
		// wParam : Group Type
		CObject* pNewObj = (CObject*)_eve.lParam;
		GROUP_TYPE eType = (GROUP_TYPE)_eve.wParam;
		CSceneMgr::GetInst()->GetCurScene()->AddObject(pNewObj, eType);
	}
		break;
	case EVENT_TYPE::DELETE_OBJECT:
	{
		// Object�� Dead ���·� ����
		// �������� ������Ʈ���� ��Ƶд�.
		CObject* pDeadObj = (CObject*)_eve.lParam;
		pDeadObj->SetDead();
		m_vecDead.push_back(pDeadObj);
	}
		break;
	case EVENT_TYPE::SCENE_CHANGE:
	{
		CSceneMgr::GetInst()->ChangeScene((SCENE_TYPE)_eve.lParam);
	}

		break;
	}
}
