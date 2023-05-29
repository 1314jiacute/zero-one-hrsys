#pragma once

/*
*��	�������á��������������á������������������� (����ҳ����ǰ�����) --cpt
*/

#ifndef _LEGALENTITY_DO_
#define _LEGALENTITY_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class LegalEntitySetDO {
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(int, age, Age);
public:
	LegalEntitySetDO() {
		id = 0;
		name = "";
		sex = "";
		age = -1;
	}
};
#endif // !_LEGALENTITY_DO_
