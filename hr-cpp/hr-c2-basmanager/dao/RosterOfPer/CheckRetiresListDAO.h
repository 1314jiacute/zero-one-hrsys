#pragma once
/*
��Ա������-��������Ա-��ҳ��ѯԱ���б�--pine
*/
#ifndef _CHECH_RETIRES_LIST_DAO_
#define _CHECH_RETIRES_LIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/RosterOfPer/RetiredEmployeesDO.h"
#include "../../domain/query/RosterOfPer/CheckRetiresListQuery.h"

/**
 * ʾ�������ݿ����ʵ�֣�Ա����š�Ա��������
 */
class CheckRetiresListDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const CheckRetiresListQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<RetiredEmployeesDO> selectWithPage(const CheckRetiresListQuery::Wrapper& query);

};
#endif // !_SAMPLE_DAO_
