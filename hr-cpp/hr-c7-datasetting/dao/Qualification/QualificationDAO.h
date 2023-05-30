#pragma once
#ifndef _QUALIFICATION_DAO_
#define _QUALIFICATION_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Qualification/QualificationDo.h"
#include "../../domain/query/Qualification/QualificationQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class QualificationDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const QualificationQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<QualificationDO> selectWithPage(const QualificationQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<QualificationDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const QualificationDO& iObj);
	// �޸�����
	int update(const QualificationDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_QUALIFICATION_DAO_
