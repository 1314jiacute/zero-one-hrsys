#pragma once
/*
* ������������--ɾ����������(֧������ɾ��)--pine
*/
#ifndef _DELETE_LEGAL_ENTITY_DTO_
#define _DELETE_LEGAL_ENTITY_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class DeleteLegalEntityDTO : public oatpp::DTO
{
public:
	//�޲ι���
	DeleteLegalEntityDTO() {};
	DTO_INIT(DeleteLegalEntityDTO, DTO);
	// ������������
	DTO_FIELD(String, ormsignorgname);
	DTO_FIELD_INFO(ormsignorgname) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.name");
	}
	// ǩԼ���嵥λ����
	DTO_FIELD(String, contractsignorgname);
	DTO_FIELD_INFO(contractsignorgname) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.contractsignorgname");
	}
	// Ĭ��ǩԼ����
	DTO_FIELD(UInt64, isdefaultsignorg);
	DTO_FIELD_INFO(isdefaultsignorg) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.isdefaultsignorg");
	}
	//���������ʶORMSIGNORGID
	DTO_FIELD(List<String>, ormsignorgid);
	DTO_FIELD_INFO(ormsignorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.ormsignorgid");
	}

};

/**
 * ʾ����ҳ�������
 */
class DeleteLegalEntityPageDTO : public PageDTO<DeleteLegalEntityDTO::Wrapper>
{
	DTO_INIT(DeleteLegalEntityPageDTO, PageDTO<DeleteLegalEntityDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // 