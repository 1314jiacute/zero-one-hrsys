#pragma once
#ifndef _CONTRACTDAO_H_
#define _CONTRACTDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/contractType/ContractTypeDO.h"
#include "../../domain/query/contractType/ContractTypeQuery.h"

class ContractTypeDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ContractTypeQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<ContractTypeDO> selectWithPage(const ContractTypeQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<ContractTypeDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const ContractTypeDO& iObj);
	// �޸�����
	int update(const ContractTypeDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};

#endif // !_CONTRACTDAO_H_