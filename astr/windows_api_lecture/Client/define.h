#include "pch.h"
#pragma once

// #define Add(a, b)	(a + b)
// i_cal = 10 * ADD(10, 20) �� �� 120. ����� �ٸ��� �۵��Ѵ�. 10 * 10 + 20

#define SINGLE(type) public: static type* GetInst() { static type mgr; return &mgr; }
//static CCore* GetInst()
//{
//	static CCore core;
//
//	return &core;
//}