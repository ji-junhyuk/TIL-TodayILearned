#include "pch.h"
#include "CScene.h"

#include "CObject.h"

CScene::CScene()
{
}

CScene::~CScene()
{
	for (UINT idx = 0; idx < (UINT)GROUP_TYPE::END; ++idx)
	{
		for (size_t jdx = 0; jdx < m_arrObj[idx].size(); ++jdx)
		{
			//m_arrObj[idx] �׷� ������ j ��ü ����
			delete m_arrObj[idx][jdx];
		}
	}
}

void CScene::update()
{
	for (UINT idx = 0; idx < (UINT)GROUP_TYPE::END; ++idx)
	{
		for (size_t jdx = 0; jdx < m_arrObj[idx].size(); ++jdx)
		{
			if (!m_arrObj[idx][jdx]->IsDead())
			{
				m_arrObj[idx][jdx]->update();
			}
		}
	}
}

void CScene::finalupdate()
{
	for (UINT idx = 0; idx < (UINT)GROUP_TYPE::END; ++idx)
	{
		for (size_t jdx = 0; jdx < m_arrObj[idx].size(); ++jdx)
		{
			m_arrObj[idx][jdx]->finalupdate();
		}
	}
}
void CScene::render(HDC _dc)
{
	for (UINT idx = 0; idx < (UINT)GROUP_TYPE::END; ++idx)
	{
		vector<CObject*>::iterator iter = m_arrObj[idx].begin();
		for (; iter != m_arrObj[idx].end();)
		{
			if (!(*iter)->IsDead())
			{
				(*iter)->render(_dc);
				++iter;
			}
			else
			{
				iter = m_arrObj[idx].erase(iter);
			}
		}
	}
}

void CScene::DeleteGroup(GROUP_TYPE _eTarget)
{
	Safe_Delete_Vec<CObject*>(m_arrObj[(UINT)_eTarget]); // �Լ����ø�
}

void CScene::DeleteAll()
{
	for (UINT idx = 0; idx < (UINT)GROUP_TYPE::END; ++idx)
	{
		DeleteGroup((GROUP_TYPE)idx);
	}
}
