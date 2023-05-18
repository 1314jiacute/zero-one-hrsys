#pragma once

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class RootOrgQuery : public PageQuery {
    DTO_INIT(RootOrgQuery, PageQuery);

    // ����ƥ��
    DTO_FILED(String, filter)
    DTO_FILED_INFO(filter) {
        info->description = ZH_WORDS_GETTER("rootorg.query.filter");
    }
    // ����ʽ
    DTO_FILED(String, sort);
    DTO_FILED_INFO(sort) {
        info->description = ZH_WORDS_GETTER("rootorg.query.sort");
    }
};

#include OATPP_CODEGEN_END(DTO)