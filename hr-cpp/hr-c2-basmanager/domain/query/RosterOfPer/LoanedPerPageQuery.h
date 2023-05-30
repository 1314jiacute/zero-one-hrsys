#pragma once
/*
����Ա������-�����Ա-��ҳ��ѯԱ���б�������ҳ��ǰ����ɣ���--luoluo
*/
#ifndef _LOANEDPERPAGE_QUERY_
#define _LOANEDPERPAGE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class LoanedPerPageQuery : public PageQuery
{
	DTO_INIT(LoanedPerPageQuery, PageQuery);
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// ���
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	//// ����
	//DTO_FIELD(UInt32, age);
	//DTO_FIELD_INFO(age) {
	//	info->description = ZH_WORDS_GETTER("sample.field.age");
	//}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LOANEDPERPAGE_QUERY_