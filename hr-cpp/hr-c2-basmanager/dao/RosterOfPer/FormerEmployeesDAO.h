#pragma once

#include "BaseDAO.h"
#include "../../domain/do/RosterOfPer/FormerEmployeesDO.h"
#include "../../domain/query/RosterOfPer/FormerEmployeesQuery.h"

/**
 * ��ְ��Ա���ݿ����ʵ��
 */
class FormerEmployeesDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const FormerEmployeesQuery::Wrapper& query);
	// ��ҳ��ѯ��ְԱ������
	list<FormerEmployeesDO> selectWithPage(const FormerEmployeesQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<FormerEmployeesDO> selectByName(const string& name);
	// ͨ����Ų�ѯ����
	list<FormerEmployeesDO> selectById(const string& id);
};
