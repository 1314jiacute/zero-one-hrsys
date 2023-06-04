#pragma once
#include "BaseDAO.h"
#include "../../domain/do/RosterOfPer/FormerEmployeesDO.h"
#include "../../domain/query/RosterOfPer/FormerEmployeesQuery.h"

/**
 * ��Ա������ - ��ְ��Ա���ݿ����ʵ�� - ������
 */

class FormerEmployeesDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const FormerEmployeesQuery::Wrapper& query);
	// ��ҳ��ѯ��ְԱ������
	list<FormerEmployeesDO> selectWithPage(const FormerEmployeesQuery::Wrapper& query);
	// ��ѯ��ְԱ������
	list<FormerEmployeesDO> selectAll(const FormerEmployeesQuery::Wrapper& query);
};
