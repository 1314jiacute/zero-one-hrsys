#pragma once
#ifndef _CONTRACT_CATEGORY_DO_
#define _CONTRACT_CATEGORY_DO_
#include "../DoInclude.h"

/**
 * ��ͬ�������ݿ�ʵ����
 */
class ContractCategoryDO
{
    // ���
    CC_SYNTHESIZE(uint64_t, id, Id);
    // ��������
    CC_SYNTHESIZE(string, name, Name);
    // ��������
    CC_SYNTHESIZE(string, description, Description);
public:
    ContractCategoryDO() {
        id = 0;
        name = "";
        description = "";
    }
};

#endif // !_
