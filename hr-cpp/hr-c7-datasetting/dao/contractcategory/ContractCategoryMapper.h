#pragma once
#ifndef _CONTRACT_CATEGORY_MAPPER_
#define _CONTRACT_CATEGORY_MAPPER_

#include "Mapper.h"
#include "../../domain/do/contractcategory/ContractCategoryDO.h"

/**
 * ��ͬ���ͱ��ֶ�ƥ��ӳ��
 */
class ContractMapper : public Mapper<ContractCategoryDO>
{
public:
    ContractCategoryDO mapper(ResultSet* resultSet) const override
    {
        ContractCategoryDO data;
        data.setId(resultSet->getUInt64(1));
        data.setName(resultSet->getString(2));
        return data;
    }
};

#endif // 
