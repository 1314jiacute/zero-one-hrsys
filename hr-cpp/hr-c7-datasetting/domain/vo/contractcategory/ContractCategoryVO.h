#pragma once
#ifndef _CONTRACT_CATEGORY_VO_
#define _CONTRACT_CATEGORY_VO_

#include "../../GlobalInclude.h"
#include "../../dto/contractcategory/ContractCategoryDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ͬ�����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ContractCategoryJsonVO : public JsonVO<ContractCategoryDTO::Wrapper> {
	DTO_INIT(ContractCategoryJsonVO, JsonVO<ContractCategoryDTO::Wrapper>);
};

/**
 * ��ͬ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ContractCategoryPageJsonVO : public JsonVO<ContractCategoryPageDTO::Wrapper> {
	DTO_INIT(ContractCategoryPageJsonVO, JsonVO<ContractCategoryPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_
