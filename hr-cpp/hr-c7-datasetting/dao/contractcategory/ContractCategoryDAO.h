#pragma once
#ifndef _CONTRACT_CATEGORY_DAO_
#define _CONTRACT_CATEGORY_DAO_
#include "BaseDAO.h"
#include "../../domain/do/contractcategory/ContractCategoryDO.h"
#include "../../domain/query/contractcategory/ContractCategoryQuery.h"

/**
 * ��ͬ���ͱ����ݿ����ʵ��
 */
class ContractCategoryDAO : public BaseDAO
{
public:
    // ͳ����������
    uint64_t count(const ContractCategoryQuery::Wrapper& query);
    // ��ҳ��ѯ����
    list<ContractCategoryDO> selectWithPage(const ContractCategoryQuery::Wrapper& query);
};
#endif //
