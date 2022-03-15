#include "pch.h"
#include "CCamera.h"

#include "CObject.h"
#include "CCore.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"

CCamera::CCamera()
	: m_pTargetObj(nullptr)
	, m_fTime(0.5f)
	, m_fSpeed(0.f)
	, m_fAccTime(0.5f)
{

}

CCamera::~CCamera()
{

}

void CCamera::update()
{
	if (m_pTargetObj)
	{
		if (m_pTargetObj->IsDead())
		{
			m_pTargetObj = nullptr;
		}
		else
		{
			m_vLootAt = m_pTargetObj->GetPos();
		}
	}
	if (KEY_HOLD(KEY::UP))
		m_vLootAt.y -= 500.f * fDT;
	if (KEY_HOLD(KEY::DOWN))
		m_vLootAt.y += 500.f * fDT;
	if (KEY_HOLD(KEY::LEFT))
		m_vLootAt.x -= 500.f * fDT;
	if (KEY_HOLD(KEY::RIGHT))
		m_vLootAt.x += 500.f * fDT;
	// ȭ�� �߾���ǥ�� ī�޶� LookAt ��ǥ���� ���̰� ���
	CalDiff();
}

void CCamera::CalDiff()
{
	// ���� LookAt �� ���� Look�� ���̰��� �����ؼ� ������ LookAt�� ���Ѵ�

	m_fAccTime += fDT;
	if (m_fTime <= m_fAccTime)
	{
		m_vCurLookAt = m_vLootAt;
	}
	else
	{
		Vec2 vLookDir = m_vLootAt - m_vPrevLookAt;
		m_vCurLookAt = m_vPrevLookAt + vLookDir.Normalize() * m_fSpeed * fDT;
	}
	Vec2 vResolution = CCore::GetInst()->GetResolution();
	Vec2 vCenter = vResolution / 2;

	m_vDiff = m_vCurLookAt - vCenter;
	m_vPrevLookAt = m_vCurLookAt;
}
