#pragma once
#ifndef _Assign_Info_Query_SERVICE_
#define _Assign_Info_Query_SERVICE_
#include <list>
#include "domain/vo/assignInfo/AssignInfoVO.h"
#include "domain/query/assignInfo/AssignInfoQuery.h"
#include "domain/query/assignInfo/AssignExportQuery.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class AssignInfoService
{
public:
	// ��ҳ��ѯ��������
	AssignInfoPageDTO::Wrapper listAll(const AssignInfoQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const AssignInfoDTO::Wrapper& dto,const PayloadDTO& payload);
	// �޸�����
	bool updateData(const AssignInfoDTO::Wrapper& dto,const PayloadDTO& payload);
	// ͨ��IDɾ������
	bool removeData(string id);
	// ��ѯ��ϸ����
	AssignInfoDTO::Wrapper QueryDetail(const AssignInfoDTO::Wrapper& dto);
	string exportData(const AssignExportQuery::Wrapper &query);
};

#endif //!_Assign_Info_Query_SERVICE_