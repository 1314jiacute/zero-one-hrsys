#pragma once
#ifndef _EXPORTLEGALERSETTING_DTO_
#define _EXPORTLEGALERSETTING_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ExportLegalerSetingDTO : public oatpp::DTO {
	DTO_INIT(ExportLegalerSetingDTO, DTO);
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
class ExportLegalerSetingPageDTO : public PageDTO<ExportLegalerSetingDTO::Wrapper> {
	DTO_INIT(ExportLegalerSetingPageDTO, PageDTO<ExportLegalerSetingDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORTLEGALERSETTING_DTO_