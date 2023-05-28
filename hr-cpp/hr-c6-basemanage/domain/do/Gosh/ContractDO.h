#pragma once
#ifndef _Gosh_DO_
#define _Gosh_DO_
#include "../DoInclude.h"
#include "../hr-sample/Macros.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class ContractDO
{
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	//��ͬ���
	CC_SYNTHESIZE(string, type, Type);
	//��ͬ����
	CC_SYNTHESIZE(string, variety, Variety);
	//��ʼ����
	CC_SYNTHESIZE(string, date, Date);
	//��ͬ״̬
	CC_SYNTHESIZE(string, condition, Condition);
	//��ͬ����λ
	CC_SYNTHESIZE(string, department_m, Department_m);
	//��ͬǩ����λ
	CC_SYNTHESIZE(string, department_c, Department_c);
	//��ͬ����ʱ��
	CC_SYNTHESIZE(string, date_end, Date_end);
	//��ע
	CC_SYNTHESIZE(string, tip, Tip);
public:
	ContractDO() {
		id = 0;
		name = "";
		type = "";
		variety = "";
		date= "";
		condition = "";
		department_m = "";
		department_c = "";
		date_end = "";
		tip = "";
	}
};

#endif 
