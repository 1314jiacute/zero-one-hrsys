#pragma once
#ifndef _Assign_Info_Query_SERVICE_
#define _Assign_Info_Query_SERVICE_
#include <list>
#include "domain/vo/assignInfo/AssignInfoQueryVO.h"
#include "domain/query/assignInfo/AssignInfoQuery.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class AssignInfoQueryService
{
public:
	// ��ҳ��ѯ��������
	AssignInfoQuery::Wrapper listAll(const AssignInfoQuery::Wrapper& query);
};

#endif //!_Assign_Info_Query_SERVICE_