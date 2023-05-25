#pragma once
#ifndef _EXPORTLEGALERSETTING_CONTROLLER_
#define _EXPORTLEGALERSETTING_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/do/LegalEntitySet/ExportLegalerSetingDO.h"
#include "domain/dto/LegalEntitySet/ExportLegalerSetingDTO.h"
#include "domain/query/LegalEntitySet/ExportLegalerSetingQuery.h"
#include "domain/vo/LegalEntitySet/ExportLegalerSetingVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "ApiHelper.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ExportLegalerSetingController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(ExportLegalerSetingController); // 2 ����������������
public:
	ENDPOINT_INFO(queryExportLegalerSeting) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.export.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ExportLegalerSetingPageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/org/export-LegalerSeting", queryExportLegalerSeting, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, ExportLegalerSetingQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execExportLegalerSeting(userQuery, authObject->getPayload()));
	}
private:
	ExportLegalerSetingPageJsonVO::Wrapper execExportLegalerSeting(const ExportLegalerSetingQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _EXPORTLEGALERSETTING_CONTROLLER_

