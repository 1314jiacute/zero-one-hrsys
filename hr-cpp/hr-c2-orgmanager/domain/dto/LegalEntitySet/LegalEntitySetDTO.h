#pragma once

/*
��֯���� ���� �������� ���� ������������  -- cpt

�����������������б� `LegalEntitySetPullDownList`

����ָ������������Ϣ  `UpdateLegalerSettingMessage`

������������ `LegalEntitySet`

�����������ã�֧������������** `LegalEntitySet`
*/

#ifndef _LEGALENTITYSET_DTO_
#define _LEGALENTITYSET_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class LegalEntitySetDTO : public oatpp::DTO {
public: 
	LegalEntitySetDTO() {};
	LegalEntitySetDTO(String ormsignorgname, String contractsignorgname, String isdefaultsignorg) : ormsignorgname(ormsignorgname), contractsignorgname(contractsignorgname), isdefaultsignorg(isdefaultsignorg) {};
	LegalEntitySetDTO(String ormsignorgid, String ormsignorgname, String contractsignorgname, String isdefaultsignorg) {	};
	DTO_INIT(LegalEntitySetDTO, DTO);
	// ���������ʶ
	DTO_FIELD(String, ormsignorgid);
	DTO_FIELD_INFO(ormsignorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.ormsignorgid");
	}
	// ������������
	DTO_FIELD(String, ormsignorgname);
	DTO_FIELD_INFO(ormsignorgname) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.ormsignorgname");
	}
	// ǩԼ���嵥λ����
	DTO_FIELD(String, contractsignorgname);
	DTO_FIELD_INFO(contractsignorgname) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.contractsignorgname");
	}
	// // Ĭ��ǩԼ����
	DTO_FIELD(String, isdefaultsignorg);
	DTO_FIELD_INFO(isdefaultsignorg) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.isdefaultsignorg");
	}
};

/**
 * ʾ����ҳ�������
 */
class LegalEntitySetPageDTO : public PageDTO<LegalEntitySetDTO::Wrapper> {
	DTO_INIT(LegalEntitySetPageDTO, PageDTO<LegalEntitySetDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LEGALENTITYSET_DTO_