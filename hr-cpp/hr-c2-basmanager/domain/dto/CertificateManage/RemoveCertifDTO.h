#pragma once
/*
��֤�����-֤����Ϣ-ɾ��֤�飨֧������ɾ������--����
*/
#ifndef _REMOVECERTIF_DTO_
#define _REMOVECERTIF_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class RemoveCertifDTO : public oatpp::DTO
{
	DTO_INIT(RemoveCertifDTO, DTO);
	// ��� CREDENTIALS_NUM
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("certif.field.id");
	}
	/*
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
	*/
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REMOVECERTIF_DTO_