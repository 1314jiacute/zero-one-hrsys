#pragma once
#ifndef _RRAINEE_DTO_
#define _RRAINEE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  �������� ���� ��Ա������ ���� ��ϰԱ��  ����Cpt
 */
class RraineeDTO : public oatpp::DTO {
	DTO_INIT(RraineeDTO, DTO);
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
class RraineePageDTO: public PageDTO<RraineeDTO::Wrapper> {
	DTO_INIT(RraineePageDTO, PageDTO<RraineeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RRAINEE_DTO_