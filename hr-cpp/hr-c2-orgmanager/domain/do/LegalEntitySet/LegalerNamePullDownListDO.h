#pragma once
#ifndef _LEGALERNAMEPULLDOWNLIST_DO_
#define _LEGALERNAMEPULLDOWNLIST_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class LegalerNamePullDownListDO {
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(int, age, Age);
public:
	LegalerNamePullDownListDO() {
		id = 0;
		name = "";
		sex = "";
		age = -1;
	}
};
#endif // !_LEGALERNAMEPULLDOWNLIST_DO_
