#pragma once
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/sample/SampleDO.h"
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
	list<SampleDO> selectWithPage(const AssignInfoQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<SampleDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const SampleDO& iObj);
	// �޸�����
	int update(const SampleDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_SAMPLE_DAO_
