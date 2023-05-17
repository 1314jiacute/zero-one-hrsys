#pragma once

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ValidOrgQuery : public PageQuery {
    DTO_INIT(ValidOrgQuery, PageQuery);

    // ����ƥ��
    DTO_FILED(String, filter)
    DTO_FILED_INFO(filter) {
        info->description = ZH_WORDS_GETTER("validorg.query.filter");
    }
    // ����֯id
    DTO_FILED(String, porgid);
    DTO_FILED_INFO(porgid) {
        info->description = ZH_WORDS_GETTER("validorg.query.porgid");
    }
    // ҳ��
    DTO_FILED(UInt64, page);
    DTO_FILED_INFO(page) {
        info->description = ZH_WORDS_GETTER("validorg.query.page");
    }
    // һҳ�ļ�¼��
    DTO_FILED(UInt64, size);
    DTO_FILED_INFO(size) {
        info->description = ZH_WORDS_GETTER("validorg.query.size");
    }
    // ����ʽ
    DTO_FILED(String, sort);
    DTO_FILED_INFO(sort) {
        info->description = ZH_WORDS_GETTER("validorg.query.sort");
    }
};

#include OATPP_CODEGEN_END(DTO)