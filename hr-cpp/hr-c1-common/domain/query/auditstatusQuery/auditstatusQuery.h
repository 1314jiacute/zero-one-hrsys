#pragma once
#ifndef _Auditstatus_QUERY_
#define _Auditstatus_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ѯ����
 * �����ˣ�fengchu
 */
class AuditstatusQuery : public PageQuery
{
public:
	DTO_INIT(AuditstatusQuery, PageQuery);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_Auditstatus_QUERY_