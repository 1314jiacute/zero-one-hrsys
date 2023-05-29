#pragma once               
#ifndef _CONTRACTCATEGORY_SERVICE_
#define _CONTRACTCATEGORY_SERVICE_
#include <list>
#include "domain/vo/ContractCategory/ContractCategoryVO.h"
#include "domain/query/ContractCategory/ContractCategoryQuery.h"
#include "domain/dto/ContractCategory/ContractCategoryDTO.h"

/**
 * ��ͬ������ʵ��
 */
class ContractCategoryService
{
public:
    // ��ҳ��ѯ���к�ͬ���
    ContractCategoryPageDTO::Wrapper listAll(const ContractCategoryQuery::Wrapper& query);
    // �½���ͬ���
    uint64_t addContractCategory(const ContractCategoryDTO::Wrapper& dto);
    // �޸ĺ�ͬ���
    bool modifyContractCategory(const ContractCategoryDTO::Wrapper& dto);
    // ͨ��IDɾ����ͬ���
    bool removeContractCategory(uint64_t id);
    // �����ͬ���
    // ������ͬ���
};

#endif // !_CONTRACTCATEGORY_SERVICE_

