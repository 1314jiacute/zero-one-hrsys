#pragma once
#ifndef _LEGALERNAMEPULLDOWNLIST_DTO_
#define _LEGALERNAMEPULLDOWNLIST_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class LegalerNamePullDownListDTO : public oatpp::DTO {
	DTO_INIT(LegalerNamePullDownListDTO, DTO);
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
class LegalerNamePullDownListPageDTO : public PageDTO<LegalerNamePullDownListDTO::Wrapper> {
	DTO_INIT(LegalerNamePullDownListPageDTO, PageDTO<LegalerNamePullDownListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LEGALERNAMEPULLDOWNLIST_DTO_