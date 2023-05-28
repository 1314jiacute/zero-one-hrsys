#pragma once
#ifndef _Contract_Info_DAO_
#define _Contract_Info_DAO_
#include "BaseDAO.h"
#include "domain/do/Gosh/ContractDO.h"
#include "domain/query/Gosh/ContractQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class ContractInfoDAO : public BaseDAO
{
public:
	// ͨ��ID��ѯ��ͬ��Ϣ
	list<ContractDO> selectById(const string& Id);

	//����ָ����ͬ
	int update(const ContractDO& uObj);

	//��rows��������
	std::list<ContractDO> downloadByRows(oatpp::String sequence, UInt64 rows);
};
#endif // !_SAMPLE_DAO_