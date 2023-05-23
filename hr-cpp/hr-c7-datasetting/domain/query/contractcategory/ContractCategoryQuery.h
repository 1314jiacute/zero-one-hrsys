#pragma once
#ifndef _CONTRACT_CATEGORY_QUERY_
#define _CONTRACT_CATEGORY_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ͬ����ҳ��ѯ����
 */
class ContractCategoryQuery : public PageQuery
{
	DTO_INIT(ContractCategoryQuery, PageQuery);
	// �������
	DTO_FIELD(String, categoryName);
	DTO_FIELD_INFO(categoryName) {
		info->description = ZH_WORDS_GETTER("contractCategory.field.categoryName");
	}
	// ��ǰҳ��
	DTO_FIELD(UInt32, pageNum);
	DTO_FIELD_INFO(pageNum) {
		info->description = ZH_WORDS_GETTER("contractCategory.field.pageNum");
	}
	// ÿҳ��ʾ������
	DTO_FIELD(UInt32, pageSize);
	DTO_FIELD_INFO(pageSize) {
		info->description = ZH_WORDS_GETTER("contractCategory.field.pageSize");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_
