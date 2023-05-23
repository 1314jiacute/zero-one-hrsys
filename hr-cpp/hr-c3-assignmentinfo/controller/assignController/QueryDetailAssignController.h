#pragma once
#ifndef _Query_Detail_Assign_CONTROLLER_
#define _Query_Detail_Assign_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/assignInfo/AssignInfoQueryDetail.h"
#include "domain/vo/assignInfo/AssignInfoQueryDetailVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) // 0


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class QueryDetailAssignController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(QueryDetailAssignController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(assignQueryDetail) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("employee.get.detail");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AssignInfoQueryDetailJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("employee.field.id");
		info->queryParams["id"].addExample("default", String("114514"));
		info->queryParams["id"].required = true;
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/query-assignInfoDetail", assignQueryDetail, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, AssignInfoQueryDetail, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAssignQueryDetail(userQuery, authObject->getPayload()));
	}
private:

	AssignInfoQueryDetailJsonVO::Wrapper execAssignQueryDetail(const AssignInfoQueryDetail::Wrapper& dto, const PayloadDTO& payload);
};
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_Query_Detail_Assign_CONTROLLER_