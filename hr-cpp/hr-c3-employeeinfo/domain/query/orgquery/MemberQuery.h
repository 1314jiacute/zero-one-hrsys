#pragma once

#ifndef _MEMBER_QUERY_
#define _MEMBER_QUERY_

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
    DTO_FILED(String, parentkey);
    DTO_FILED_INFO(parentkey) {
        info->description = ZH_WORDS_GETTER("member.query.parentkey");
    }
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MEMBER_QUERY_