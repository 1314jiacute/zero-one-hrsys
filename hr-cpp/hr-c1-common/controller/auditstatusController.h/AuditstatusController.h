#pragma once
#ifndef _AuditstatusCONTROLLER_H_
#define _AuditstatusCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/query/auditstatusQuery/AuditstatusQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/auditstatusVO/AuditstatusVO.h"
//#include "domain/vo/user/MenuVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class AuditstatusController : public oatpp::web::server::api::ApiController
{
	// ��ӷ��ʶ���
	API_ACCESS_DECLARE(AuditstatusController);
public:
	// �����ѯ�����û���Ϣ�ӿڶ˵�����
	ENDPOINT_INFO(queryAuditstatus) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("auditstatus query");
		// ���Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AuditstatusJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
	}

	// �����ѯ�����û���Ϣ�ӿڶ˵㴦��
	ENDPOINT(API_M_GET, "/auditstatusQuery", queryAuditstatus, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, AuditstatusQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryAuditstatus(userQuery, authObject->getPayload()));
	}
	
private:
	// ��ѯ����
	StringJsonVO::Wrapper execQueryAuditstatus(const AuditstatusQuery::Wrapper& auditstatusQuery);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _AuditstatusCONTROLLER_H_