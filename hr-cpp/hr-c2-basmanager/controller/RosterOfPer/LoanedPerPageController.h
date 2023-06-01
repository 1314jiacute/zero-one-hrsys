#pragma once
/*
����Ա������-�����Ա-��ҳ��ѯԱ���б�������ҳ��ǰ����ɣ���--luoluo
*/
#ifndef _LOANEDPERPAGE_CONTROLLER_
#define _LOANEDPERPAGE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"

#include "domain/query/RosterOfPer/LoanedPerPageQuery.h"
#include "domain/dto/RosterOfPer/LoanedPerPageDTO.h"
#include "domain/vo/RosterOfPer/LoanedPerPageVO.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class LoanedPerPageController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(LoanedPerPageController);
	// 3 ����ӿ�
public:

	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryLoanedPerPage) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("loanedperpage.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(LoanedPerPageVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("sample.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = false;
		info->queryParams.add<String>("sex").description = ZH_WORDS_GETTER("sample.field.sex");
		info->queryParams["sex"].addExample("default", String("N"));
		info->queryParams["sex"].required = false;
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/bas/query-LoanedPerPage", queryLoanedPerPage, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, LoanedPerPageQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryLoanedPerPage(userQuery, authObject->getPayload()));
	}

private:
	// 3.3 ��ʾ��ҳ��ѯ����
	LoanedPerPageVO::Wrapper execQueryLoanedPerPage(const LoanedPerPageQuery::Wrapper& query, const PayloadDTO& payload);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _LOANEDPERPAGE_CONTROLLER_