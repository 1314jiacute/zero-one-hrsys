#pragma once
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/assignDO/AssignInfoDO.h"
#include "../../domain/query/assignInfo/AssignInfoQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class SampleDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const AssignInfoQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<AssignInfoDO> selectWithPage(const AssignInfoQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<AssignInfoDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const AssignInfoDO& iObj);
	// �޸�����
	int update(const AssignInfoDO& uObj);
	// ͨ��IDɾ������
	int deleteById(string id);
};
#endif // !_SAMPLE_DAO_
