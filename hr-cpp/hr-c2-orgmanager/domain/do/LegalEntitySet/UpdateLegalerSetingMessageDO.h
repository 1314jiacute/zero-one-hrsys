#pragma once
#ifndef _UPDATELEGALERSETINGMESSAGE_DO_
#define _UPDATELEGALERSETINGMESSAGE_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class UpdateLegalerSetingMessageDO {
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(int, age, Age);
public:
	UpdateLegalerSetingMessageDO() {
		id = 0;
		name = "";
		sex = "";
		age = -1;
	}
};
#endif // !_UPDATELEGALERSETINGMESSAGE_DO_
