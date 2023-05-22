#pragma once

#ifndef _VALID_ORG_QUERY_
#define _VALID_ORG_QUERY_


#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ValidOrgQuery : public PageQuery {
    DTO_INIT(ValidOrgQuery, PageQuery);

    // ����ƥ��
	DTO_FIELD(String, filter);
	DTO_FIELD_INFO(filter) {
		info->description = ZH_WORDS_GETTER("validorg.query.filter");
	}
    // ����֯id
	DTO_FIELD(String, porgid);
	DTO_FIELD_INFO(porgid) {
		info->description = ZH_WORDS_GETTER("validorg.query.porgid");
	}
    // ҳ��
	DTO_FIELD(UInt64, page);
	DTO_FIELD_INFO(page) {
		info->description = ZH_WORDS_GETTER("validorg.query.page");
	}
    // һҳ�ļ�¼��
	DTO_FIELD(UInt64, size);
	DTO_FIELD_INFO(size) {
		info->description = ZH_WORDS_GETTER("validorg.query.size");
	}
    // ����ʽ
	DTO_FIELD(String, sort);
	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("validorg.query.sort");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_VALID_ORG_QUERY_