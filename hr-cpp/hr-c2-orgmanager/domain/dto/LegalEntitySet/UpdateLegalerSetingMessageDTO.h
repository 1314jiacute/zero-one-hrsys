#pragma once
#ifndef _UpdateLegalerSetingMessage_DTO_
#define _UpdateLegalerSetingMessage_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  �������� ���� ��Ա������ ���� ��ϰԱ�� ���� ��ҳ��ѯԱ���б� PageQueryEmployeeList  (��ҳ )ʾ���������
 */
class UpdateLegalerSetingMessageDTO: public oatpp::DTO {
	DTO_INIT(UpdateLegalerSetingMessageDTO, DTO);
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
class UpdateLegalerSetingMessagePageDTO : public PageDTO<UpdateLegalerSetingMessageDTO::Wrapper> {
	DTO_INIT(UpdateLegalerSetingMessagePageDTO, PageDTO<UpdateLegalerSetingMessageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORTLEGALERSETTING_DTO_