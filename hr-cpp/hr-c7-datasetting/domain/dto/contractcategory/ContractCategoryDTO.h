#pragma once
#ifndef _CONTRACT_CATEGORY_DTO_
#define _CONTRACT_CATEGORY_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ͬ��������
 */
class ContractCategoryDTO : public oatpp::DTO
{
	DTO_INIT(ContractCategoryDTO, DTO);
	// ���ID
	DTO_FIELD(UInt64, categoryId);
	DTO_FIELD_INFO(categoryId) {
		info->description = ZH_WORDS_GETTER("contractCategory.field.categoryId");
	}
	// �������
	DTO_FIELD(String, categoryName);
	DTO_FIELD_INFO(categoryName) {
		info->description = ZH_WORDS_GETTER("contractCategory.field.categoryName");
	}
	// �������
	DTO_FIELD(String, categoryDescription);
	DTO_FIELD_INFO(categoryDescription) {
		info->description = ZH_WORDS_GETTER("contractCategory.field.categoryDescription");
	}
};

/**
 * ��ͬ����ҳ�������
 */
class ContractCategoryPageDTO : public PageDTO<ContractCategoryDTO::Wrapper>
{
	DTO_INIT(ContractCategoryPageDTO, PageDTO<ContractCategoryDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !
