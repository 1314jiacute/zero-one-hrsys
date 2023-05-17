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
    // ҳ��
    DTO_FILED(UInt64, page);
    DTO_FILED_INFO(page) {
        info->description = ZH_WORDS_GETTER("member.query.page");
    }
    // һҳ�ļ�¼��
    DTO_FILED(UInt64, size);
    DTO_FILED_INFO(size) {
        info->description = ZH_WORDS_GETTER("member.query.size");
    }
};

#include OATPP_CODEGEN_END(DTO)