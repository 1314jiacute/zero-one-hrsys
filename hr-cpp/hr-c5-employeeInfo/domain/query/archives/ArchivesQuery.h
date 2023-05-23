#pragma once
#ifndef _ARVHIVES_QUERY_
#define _ARVHIVES_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������ҳ��ѯ����
 */
class ArchivesQuery : public PageQuery
{
	DTO_INIT(ArchivesQuery, PageQuery);

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_