#pragma once
#ifndef _RRAINEE_DO_
#define _RRAINEE_DO_
#include "../DoInclude.h"

/**
 *  �������� ���� ��Ա������ ���� ��ϰԱ��ʵ����  ����Cpt
 */
class ExportEmployeeDO {
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(int, age, Age);
public:
	ExportEmployeeDO() {
		id = 0;
		name = "";
		sex = "";
		age = -1;
	}
};

#endif // !_RRAINEE_DO_
