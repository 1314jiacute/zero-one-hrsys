#pragma once
#ifndef _SAMPLE_DO_
#define _SAMPLE_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class SampleDO {
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(int, age, Age);
public:
	SampleDO() {
		id = 0;
		name = "";
		sex = "";
		age = -1;
	}
};

#endif // !_SAMPLE_DO_
