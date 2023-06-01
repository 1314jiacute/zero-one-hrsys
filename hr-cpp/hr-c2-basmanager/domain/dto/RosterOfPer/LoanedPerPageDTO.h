#pragma once
/*
����Ա������-�����Ա-��ҳ��ѯԱ���б�������ҳ��ǰ����ɣ���--luoluo
*/
#ifndef _LOANEDPERPAGE_DTO_
#define _LOANEDPERPAGE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class LoanedPerDTO : public oatpp::DTO
{
	DTO_INIT(LoanedPerDTO, DTO);
	// ���
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// ����
	DTO_FIELD(Int32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("sample.field.age");
	}
	// �Ա�
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("sample.field.sex");
	}
};

/**
 * ʾ����ҳ�������
 */
class LoanedPerPageDTO : public PageDTO<LoanedPerDTO::Wrapper>
{
	DTO_INIT(LoanedPerPageDTO, PageDTO<LoanedPerDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LOANEDPERPAGE_DTO_