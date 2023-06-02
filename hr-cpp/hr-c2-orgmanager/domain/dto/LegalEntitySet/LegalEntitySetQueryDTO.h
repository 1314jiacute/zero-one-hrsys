#pragma once

/*
��֯���� ���� �������� ���� ������������  -- cpt

�����������������б� `LegalEntitySetPullDownList`

����ָ������������Ϣ  `UpdateLegalerSettingMessage`

������������ `LegalEntitySet`

�����������ã�֧������������** `LegalEntitySet`
*/

#ifndef _LEGALENTITYSETQUERY_DTO_
#define _LEGALENTITYSETQUERY_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class LegalEntitySetQueryDTO : public oatpp::DTO {
public:
	LegalEntitySetQueryDTO() {};
	LegalEntitySetQueryDTO(String ormsignorgid, String ormorgid, String signorgid, String isdefaultsignorg) : ormorgid(ormorgid), signorgid(signorgid), isdefaultsignorg(isdefaultsignorg) {};
	DTO_INIT(LegalEntitySetQueryDTO, DTO);
	// ���������ʶ
	DTO_FIELD(String, ormsignorgid);
	DTO_FIELD_INFO(ormsignorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.ormsignorgid");
	}
	// ����λ��ʶ
	DTO_FIELD(String, ormorgid);
	DTO_FIELD_INFO(ormorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.ormorgid");
	}
	// ���������ʶ
	DTO_FIELD(String, signorgid);
	DTO_FIELD_INFO(signorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.signorgid");
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
class LegalEntitySetQueryPageDTO : public PageDTO<LegalEntitySetQueryDTO::Wrapper> {
	DTO_INIT(LegalEntitySetQueryPageDTO, PageDTO<LegalEntitySetQueryDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LEGALENTITYSETQUERY_DTO_