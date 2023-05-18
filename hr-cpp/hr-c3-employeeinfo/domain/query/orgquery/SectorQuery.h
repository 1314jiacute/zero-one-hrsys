#pragma once

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SectorQuery : public PageQuery {
    DTO_INIT(SectorQuery, PageQuery);

    // ��ѯ��parent id
    DTO_FILED(String, parentkey)
    DTO_FILED_INFO(parentkey) {
        info->description = ZH_WORDS_GETTER("sectorquery.query.parentkey");
    }
    // ҳ��
    DTO_FILED(UInt64, page);
    DTO_FILED_INFO(page) {
        info->description = ZH_WORDS_GETTER("sectorquery.query.page");
    }
    // һҳ�ļ�¼��
    DTO_FILED(UInt64, size);
    DTO_FILED_INFO(size) {
        info->description = ZH_WORDS_GETTER("sectorquery.query.size");
    }
    // ����ʽ
    DTO_FILED(String, sort);
    DTO_FILED_INFO(sort) {
        info->description = ZH_WORDS_GETTER("sectorquery.query.sort");
    }
};

#include OATPP_CODEGEN_END(DTO)