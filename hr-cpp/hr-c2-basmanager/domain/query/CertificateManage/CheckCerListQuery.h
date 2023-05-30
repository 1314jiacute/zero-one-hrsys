#pragma once
/**
* ��ҳ��ѯ֤���б�--(֤�����-��ҳ��ѯ֤���б�)--pine
 */
#ifndef _CHECK_CER_QUERY_
#define _CHECK_CER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

 /**
 ֤�����-��ҳ��ѯ֤���б�--pine
  */
class CheckCerListQuery : public PageQuery
{
	DTO_INIT(CheckCerListQuery, PageQuery);
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

#include OATPP_CODEGEN_END(DTO)
#endif // !_CheckCerList_QUERY_