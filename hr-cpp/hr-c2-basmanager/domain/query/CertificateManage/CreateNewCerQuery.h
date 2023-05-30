#pragma once

#ifndef _CREATE_NEW_CER_QUERY_
#define _CREATE_NEW_CER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
֤�����-֤����Ϣ-�½�֤��--pine
 */
class CreateNewCerQuery : public PageQuery
{
	DTO_INIT(CreateNewCerQuery, PageQuery);
	// Ա�����
	DTO_FIELD(UInt64, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("cermanage.field.ygbh");
	}
	// ֤������
	DTO_FIELD(String, pimVocationalName);
	DTO_FIELD_INFO(pimVocationalName) {
		info->description = ZH_WORDS_GETTER("cermanage.field.pimVocationalName");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CreateNewCer_QUERY_