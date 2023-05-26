#pragma once
#ifndef _TEMPORARYSTAFF_DAO_
#define _TEMPORARYSTAFF_DAO_
#include "BaseDAO.h"
#include "../../domain/do/RosterOfPer/TemporaryStaffDO.h"
#include "../../domain/query/RosterOfPer/TemporaryStaffQuery.h"

/**
 * ��ְ��Ա���ݿ����ʵ��--(��Ա������-��ְ��Ա-��ҳ��ѯԱ���б�)--weixiaoman
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
	// ͨ����Ų�ѯ����
	list<TemporaryStaffDO> selectById(const string& id);
};
#endif // !_TEMPORARYSTAFF_DAO_