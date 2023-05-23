#pragma once
#ifndef _CONTRACTCATEGORY_DELETE_DTO_
#define _CONTRACTCATEGORY_DELETE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ContractCategoryDeleteDTO : public oatpp::DTO
{
	DTO_INIT(ContractCategoryDeleteDTO, DTO);

	// ��ɾ����ͬ����ID�б�
	DTO_FIELD(List<Int64>, ids);
	DTO_FIELD_INFO(ids) {
		info->description = ZH_WORDS_GETTER("contractCategory.field.ids");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif