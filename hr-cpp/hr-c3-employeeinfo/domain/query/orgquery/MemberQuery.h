#pragma once

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class MemberQuery : public PageQuery {
    DTO_INIT(MemberQuery, PageQuery);

    // ��ѯMember��parent��OrmOrg����OrmOrgsector
    DTO_FILED(String, parentdename)
    DTO_FILED_INFO(parentdename) {
        info->description = ZH_WORDS_GETTER("member.query.parentdename");
    }
    // ��ѯ��parent id
    DTO_FILED(String, parentkey);
    DTO_FILED_INFO(parentkey) {
        info->description = ZH_WORDS_GETTER("member.query.parentkey");
    }
};

#include OATPP_CODEGEN_END(DTO)