#pragma once
#ifndef _TEMPORARYSTAFF_DO_
#define _TEMPORARYSTAFF_DO_
#include "../DoInclude.h"

/**
* ��ְ��Ա���ݿ�ʵ����
*/
class TemporaryStaffDO {
	//Ա�����
	CC_SYNTHESIZE(string, ygbh, ygbh);
	//Ա������
	CC_SYNTHESIZE(string, pimPersonName, pimPersonName);
	//Ա��״̬
	CC_SYNTHESIZE(string, ygzt, ygzt);
	//��ְ״̬
	CC_SYNTHESIZE(string, gzzt, gzzt);
	//��ְ��֯
	CC_SYNTHESIZE(string, gzzz, gzzz);
	//��ְ����
	CC_SYNTHESIZE(string, gzbm, gzbm);
	//��ְ��ʼʱ��
	CC_SYNTHESIZE(string, gzkssj, gzkssj);
	//��ְ����ʱ��
	CC_SYNTHESIZE(string, gzjssj, gzjssj);
public:
	TemporaryStaffDO() {
		ygbh = "0";
		pimPersonName = "";
		ygzt = "��ְ";
		gzzt = "��ְ��";
		gzzz = "";
		gzbm = "";
		gzkssj = "";
		gzjssj = "";
	}
};





#endif // !_TEMPORARYSTAFF_DO_
