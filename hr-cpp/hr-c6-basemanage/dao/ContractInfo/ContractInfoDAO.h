#pragma once
#ifndef _Contract_Info_DAO_
#define _Contract_Info_DAO_
#include "BaseDAO.h"
#include "domain/do/contractInfoakie/ContractInfoDO.h"
#include "domain/query/ContractQuery/ContractQuery_.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class ContractInfoDAO : public BaseDAO
{
public:
	// ͨ��id��ѯ��ͬ��Ϣ
	list<ContractInfoDO> selectByInfoid(const string& infoid);

	//����ָ����ͬ
	int update(const ContractInfoDO& uObj);

	//��rows��������
	std::list<ContractInfoDO> downloadByRows(oatpp::String sequence, UInt64 rows);

	// ��������
	uint64_t insert(const ContractInfoDO& iObj);
};
#endif // !_SAMPLE_DAO_