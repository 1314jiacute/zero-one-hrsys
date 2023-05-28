#pragma once
#ifndef _Gosh_SERVICE_
#define _Gosh_SERVICE_
#include <list>
#include "domain/vo/Gosh/ContractVO.h"
#include "domain/query/Gosh/ContractQuery.h"
#include "domain/dto/Gosh/ContractDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class GoshService
{
public:
	// ��ҳ��ѯ��ͬ����
	ContractPageDTO_gs::Wrapper listContract(const ContractQuery::Wrapper& query);
	//// ��ҳ��ѯ��ͬ����
	//ContractPageDTO_gs::Wrapper listPerson(const PersonQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const ContractDTO_gs::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(const ContractDTO_gs_delete::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_