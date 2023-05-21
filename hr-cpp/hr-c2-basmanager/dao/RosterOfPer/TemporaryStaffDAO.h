#pragma once
#ifndef _TEMPORARYSTAFF_DAO_
#define _TEMPORARYSTAFF_DAO_
#include "BaseDAO.h"
#include "../../domain/do/RosterOfPer/TemporaryStaffDO.h"
#include "../../domain/query/RosterOfPer/TemporaryStaffQuery.h"

/**
 * ��ְ��Ա���ݿ����ʵ��
 */
class TemporaryStaffDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const TempStaffQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<TemporaryStaffDO> selectWithPage(const TempStaffQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<TemporaryStaffDO> selectByName(const string& name);
};
#endif // !_TEMPORARYSTAFF_DAO_