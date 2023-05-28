#pragma once

/*
*��	�������á��������������á������������������� (����ҳ����ǰ�����) --cpt
*/

#ifndef _ADDLEGALERSETTING_DO_
#define _ADDLEGALERSETTING_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class AddLegalerSetingDO {
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(int, age, Age);
public:
	AddLegalerSetingDO() {
		id = 0;
		name = "";
		sex = "";
		age = -1;
	}
};
#endif // !_ADDLEGALERSETTING_DO_
