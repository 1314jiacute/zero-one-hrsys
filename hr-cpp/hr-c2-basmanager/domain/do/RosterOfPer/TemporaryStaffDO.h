#pragma once
#ifndef _TEMPORARYSTAFF_DO_
#define _TEMPORARYSTAFF_DO_
#include "../DoInclude.h"

/**
* ��ְ��Ա���ݿ�ʵ����
*/
class TemporaryStaffDO {
	//Ա�����
	CC_SYNTHESIZE(string, id, Id);
	//Ա������
	CC_SYNTHESIZE(string, name, Name);
	//Ա��״̬
	CC_SYNTHESIZE(string, empStatus, EmpStatus);
	//��ְ״̬
	CC_SYNTHESIZE(string, tempStatus, TempStatus);
	//��ְ��֯
	CC_SYNTHESIZE(string, tempOrg, TempOrg);
	//��ְ����
	CC_SYNTHESIZE(string, tempDept, TempDept);
	//��ְ��ʼʱ��
	CC_SYNTHESIZE(string, tempStartTime, TempStartTime);
	//��ְ����ʱ��
	CC_SYNTHESIZE(string, tempEndTime, TempEndTime);
public:
	TemporaryStaffDO() {
		id = "0";
		name = "";
		empStatus = "��ְ";
		tempStatus = "��ְ��";
		tempOrg = "";
		tempDept = "";
		tempStartTime = "";
		tempEndTime = "";
	}
};





#endif // !_TEMPORARYSTAFF_DO_
