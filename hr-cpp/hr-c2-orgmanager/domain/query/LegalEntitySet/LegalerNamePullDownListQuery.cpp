#pragma once

#ifndef _LEGALERNAMEPULLDOWNLISTQUERY_CONTROLLER_
#define _LEGALERNAMEPULLDOWNLISTQUERY_CONTROLLER_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class SampleQuery : public PageQuery
{
	DTO_INIT(SampleQuery, PageQuery);
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// �Ա�
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("sample.field.sex");
	}
	// ����
	DTO_FIELD(UInt32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("sample.field.age");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LEGALERNAMEPULLDOWNLISTQUERY_CONTROLLER_s