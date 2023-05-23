#pragma once
#ifndef _CONTRACTCATEGORY_IMPORT_DTO_
#define _CONTRACTCATEGORY_IMPORT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������������ĺ�ͬ���ʹ������
 */
class ContractCategoryImportDTO : public oatpp::DTO
{
    DTO_INIT(ContractCategoryImportDTO, DTO);

    // ��ͬ������
    DTO_FIELD(String, categoryName);
    DTO_FIELD_INFO(categoryName) {
        info->description = ZH_WORDS_GETTER("contractCategory.field.categoryName");
    }

    // ��ͬ��������
    DTO_FIELD(String, categoryDescription);
    DTO_FIELD_INFO(categoryDescription) {
        info->description = ZH_WORDS_GETTER("contractCategory.field.categoryDescription");
    }
};

/**
 * ������������ĺ�ͬ�����б������
 */
class ContractCategorysImportDTO : public oatpp::DTO
{
    DTO_INIT(ContractCategorysImportDTO, DTO);

    // ��ͬ�����б�
    DTO_FIELD(List<Object<ContractCategoryImportDTO>>, categorys);
    DTO_FIELD_INFO(categorys) {
        info->description = ZH_WORDS_GETTER("contractCategory.field.categorys");
    }
};

#include OATPP_CODEGEN_END(DTO)
#endif // !