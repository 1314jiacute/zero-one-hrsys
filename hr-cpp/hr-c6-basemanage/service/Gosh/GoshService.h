#ifndef _Gosh_SERVICE_
#define _Gosh_SERVICE_
#include <list>
#include "domain/vo/Gosh/ContractVO.h"
#include "domain/query/Gosh/ContractQuery.h"
#include "domain/query/Gosh/PersonQuery.h"
#include "domain/dto/Gosh/ContractDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class GoshService
{
public:
	// ��ҳ��ѯ��������
	ContractDTO_gs::Wrapper listAll(const ContractQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const ContractDTO_gs::Wrapper& dto);
	// �޸�����
	bool updateData(const ContractDTO_gs::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_
