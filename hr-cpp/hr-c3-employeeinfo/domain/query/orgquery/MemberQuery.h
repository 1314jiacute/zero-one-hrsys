#pragma once

#ifndef _Member_Query_
#define _Member_Query_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class MemberQuery : public PageQuery {
    DTO_INIT(MemberQuery, PageQuery);

    // ��ѯMember��parent��OrmOrg����OrmOrgsector
	DTO_FIELD(String, parentdename);
	DTO_FIELD_INFO(parentdename) {
		info->description = ZH_WORDS_GETTER("member.query.parentdename");
	}
    // ��ѯ��parent id
	DTO_FIELD(String, parentkey);
	DTO_FIELD_INFO(parentkey) {
		info->description = ZH_WORDS_GETTER("member.query.parentkey");
	}
    // ҳ��
	DTO_FIELD(UInt64, page);
	DTO_FIELD_INFO(page) {
		info->description = ZH_WORDS_GETTER("member.query.page");
	}
    // һҳ�ļ�¼��
	DTO_FIELD(UInt64, size);
	DTO_FIELD_INFO(size) {
		info->description = ZH_WORDS_GETTER("member.query.size");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_Member_Query_