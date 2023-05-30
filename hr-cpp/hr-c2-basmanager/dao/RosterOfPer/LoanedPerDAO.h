#pragma once
#ifndef _LoanedPer_DAO_
#define _LoanedPer_DAO_
#include "BaseDAO.h"
#include "../../domain/do/RosterOfPer/SecondedPersonnelDO.h"
#include "../../domain/query/RosterOfPer/LoanedPerPageQuery.h"

/**
 * �����Ա���ݿ����ʵ��--(��Ա������-�����Ա-��ҳ��ѯԱ���б�)--luoluo
 */
class LoanedPerDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const LoanedPerPageQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<SecondedPersonnelDO> selectWithPage(const LoanedPerPageQuery::Wrapper& query);
};
#endif // !_LoanedPer_DAO_