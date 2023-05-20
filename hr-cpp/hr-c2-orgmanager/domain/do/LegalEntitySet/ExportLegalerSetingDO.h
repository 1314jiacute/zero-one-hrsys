#pragma once
#ifndef _EXPORTLEGALERSETTING_DO_
#define _EXPORTLEGALERSETTING_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class ExportLegalerSetingDO {
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(int, age, Age);
public:
	ExportLegalerSetingDO() {
		id = 0;
		name = "";
		sex = "";
		age = -1;
	}
};
#endif // !_EXPORTLEGALERSETTING_DO_
