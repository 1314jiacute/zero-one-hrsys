#pragma once
#ifndef _EMPLOYEEINFO_DO_
#define _EMPLOYEEINFO_DO_
#include "../DoInclude.h"
/**
 * ��Ա��Ϣ��ҳ��ѯDO--(֤�����-��ҳ��ѯԱ����Ϣ�б�)--weixiaoman
 */
class EmployeeInfoDO {
	// ����
	CC_SYNTHESIZE(string, name, Name);
public:
	EmployeeInfoDO() {
		name = "";
	}
};
#endif // !_EMPLOYEEINFO_DO_


