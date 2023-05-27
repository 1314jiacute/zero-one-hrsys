#pragma once
#ifndef _Assign_Info_Query_SERVICE_
#define _Assign_Info_Query_SERVICE_
#include <list>
#include "domain/vo/assignInfo/AssignInfoVO.h"
#include "domain/query/assignInfo/AssignInfoQuery.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class AssignInfoService
{
public:
	// ��ҳ��ѯ��������
	AssignInfoPageDTO::Wrapper listAll(const AssignInfoQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const AssignInfoDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const AssignInfoDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(string id);
};

#endif //!_Assign_Info_Query_SERVICE_