#pragma once

#ifndef _LEGALENTITYSETQUERY_CONTROLLER_
#define _LEGALENTITYSETQUERY_CONTROLLER_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class LegalEntitySetQuery : public PageQuery
{
	DTO_INIT(LegalEntitySetQuery, PageQuery);
	// ���������ʶ
	DTO_FIELD(String, ORMSIGNORGID);
	DTO_FIELD_INFO(ORMSIGNORGID) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.id");
	}
	// ������
	DTO_FIELD(String, UPDATEMAN);
	DTO_FIELD_INFO(UPDATEMAN) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.updateman");
	}
	// ������
	DTO_FIELD(String, CREATEMAN);
	DTO_FIELD_INFO(CREATEMAN) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.createman");
	}
	// ����ʱ��
	DTO_FIELD(String, CREATEDATE);
	DTO_FIELD_INFO(CREATEDATE) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.createdate");
	}
	// ������������
	DTO_FIELD(String, ORMSIGNORGNAME);
	DTO_FIELD_INFO(ORMSIGNORGNAME) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.name");
	}
	// ����ʱ��
	DTO_FIELD(String, UPDATEDATE);
	DTO_FIELD_INFO(UPDATEDATE) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.updatedate");
	}
	// ��֯���
	DTO_FIELD(String, ORGCODE);
	DTO_FIELD_INFO(ORGCODE) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.orgcode");
	}
	// ���
	DTO_FIELD(String, ZZJC);
	DTO_FIELD_INFO(ZZJC) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.short");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LEGALENTITYSETQUERY_CONTROLLER_