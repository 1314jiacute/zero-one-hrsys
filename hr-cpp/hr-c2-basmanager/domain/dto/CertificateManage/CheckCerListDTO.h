#pragma once
/*
* ��ҳ��ѯ֤���б�--(֤�����-��ҳ��ѯ֤���б�)--pine
*/
#ifndef _CHECK_CER_DTO_
#define _CHECK_CER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class CheckCerListDTO : public oatpp::DTO
{
public:
	//�޲ι���
	CheckCerListDTO() {};
	//�вι���
	//CheckCerListDTO(UInt64 id, String name, Int32 age, String sex) {};
	CheckCerListDTO(UInt64 ygbh, String pimperSonName, String pimVocationalName) :ygbh(ygbh), pimperSonName(pimperSonName), pimVocationalName(pimVocationalName) {};
	DTO_INIT(CheckCerListDTO, DTO);
	// Ա�����
	DTO_FIELD(UInt64, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("cermanage.field.ygbh");
	}
	// Ա������
	DTO_FIELD(String, pimperSonName);
	DTO_FIELD_INFO(pimperSonName) {
		info->description = ZH_WORDS_GETTER("cermanage.field.pimperSonName");
	}
	// ֤������
	DTO_FIELD(String, pimVocationalName);
	DTO_FIELD_INFO(pimVocationalName) {
		info->description = ZH_WORDS_GETTER("cermanage.field.pimVocationalName");
	}
};

/**
 * ʾ����ҳ�������
 */
class CheckCerListPageDTO : public PageDTO<CheckCerListDTO::Wrapper>
{
	DTO_INIT(CheckCerListPageDTO, PageDTO<CheckCerListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // 