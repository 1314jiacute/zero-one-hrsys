#pragma once

#ifndef _Contract_Info_SERVICE_
#define _Contract_Info_SERVICE_
#include <list>
#include "domain/vo/ContractVO/ContractVO_.h"
#include "domain/query/ContractQuery/ContractQuery_.h"
#include "domain/dto/ContractDTO/ContractDTO_.h"

/**
 * akieʵ��service
 */
class ContractInfoService
{
public:
	// �鿴ָ����ͬ��Ϣ
	ContractDTO_::Wrapper listContract(const ContractQuery_::Wrapper& query);
	// �޸�ָ����ͬ
	bool updateContract(const ContractDTO_::Wrapper& dto);
	// �޸�����
	//bool updateData(const ContractDTO_::Wrapper& dto);
	// ͨ��IDɾ������
	//bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_