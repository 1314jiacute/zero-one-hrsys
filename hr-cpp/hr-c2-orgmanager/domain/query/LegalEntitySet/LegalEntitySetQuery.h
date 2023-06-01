#pragma once

#ifndef _LEGALENTITYSET_QUERY_
#define _LEGALENTITYSET_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
��֯���� ������������ ���� ������������  -- cpt

�����������������б� `LegalEntitySetPullDownList`

����ָ������������Ϣ  `UpdateLegalerSettingMessage`

������������ `LegalEntitySet`

�����������ã�֧������������** `LegalEntitySet`
*/
class LegalEntitySetQuery : public PageQuery
{
	DTO_INIT(LegalEntitySetQuery, PageQuery);
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
	// Ĭ��ǩԼ����
	DTO_FIELD(String, isdefaultsignorg);
	DTO_FIELD_INFO(isdefaultsignorg) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.isdefaultsignorg");
	}

	DTO_FIELD(String, contractsignorgid);
	DTO_FIELD_INFO(contractsignorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.contractsignorgid");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LEGALENTITYSET_QUERY_