#pragma once
/*
��֯���� ������������ ���� ������������  -- cpt

�����������������б� `LegalEntitySetPullDownList`

����ָ������������Ϣ  `UpdateLegalerSettingMessage`

������������ `LegalEntitySet`

�����������ã�֧������������** `LegalEntitySet`
*/ 

// LegalEntitySetController

#pragma once

#ifndef _LEGALENTITYSET_CONTROLLER_
#define _LEGALENTITYSET_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/do/LegalEntitySet/LegalEntitySetDO.h"
#include "domain/dto/LegalEntitySet/LegalEntitySetDTO.h"
#include "domain/vo/LegalEntitySet/LegalEntitySetVO.h"
#include "domain/query/LegalEntitySet/LegalEntitySetQuery.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "ApiHelper.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class LegalEntitySetController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(LegalEntitySetController); // 2 ����������������
public:

	ENDPOINT_INFO(LegalEntitySet) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/org/add-LegalerSeting", LegalEntitySet, BODY_DTO(LegalEntitySetDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddLegalEntitySet(dto));
	}

	ENDPOINT_INFO(queryLegalEntitySet) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.export.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(LegalEntitySetPageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/org/export-LegalerSeting", queryLegalEntitySet, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, LegalEntitySetQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execExportLegalEntitySet(userQuery, authObject->getPayload()));
	}

	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryLegalEntitySetPullDownList) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.query.summary3");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(LegalEntitySetPageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/org/query-LegalEntitySetPullDownList", queryLegalEntitySetPullDownList, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, LegalEntitySetQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execLegalEntitySetPullDownList());
	}

	// 3.1 �����޸Ľӿ�����
	ENDPOINT_INFO(modifyLegalEntitySet) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("EmpInfo.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
	}
	// 3.2 �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/org/update-LegalEntitySet", modifyLegalEntitySet, BODY_DTO(LegalEntitySetDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyLegalEntitySet(dto));
	}

	/* ---------------------------�����������ÿ��������--����֯����-��������-�����������ã�--TripleGold ----------------------------*/
	// �����ѯ����������Ϣ�ӿ�����
	ENDPOINT_INFO(queryLES) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.query.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(LegalEntitySetPageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		info->queryParams.add<String>("ormsignorgname").description = ZH_WORDS_GETTER("LegalEntitySet.field.ormsignorgname");
		info->queryParams["ormsignorgname"].addExample("default", String(ZH_WORDS_GETTER("LegalEntitySet.sample.name1")));
		info->queryParams["ormsignorgname"].required = false;
		info->queryParams.add<String>("contractsignorgname").description = ZH_WORDS_GETTER("LegalEntitySet.field.contractsignorgname");
		info->queryParams["contractsignorgname"].addExample("default", String(ZH_WORDS_GETTER("LegalEntitySet.sample.name2")));
		info->queryParams["contractsignorgname"].required = false;
	}
	// �����ѯ����������Ϣ�ӿڴ���
	ENDPOINT(API_M_GET, "/org/query-LES", queryLES, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(legalEntitySetQuery, LegalEntitySetQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryLES(legalEntitySetQuery));
	}

private:
	Uint64JsonVO::Wrapper execAddLegalEntitySet(const LegalEntitySetDTO::Wrapper& dto);

	LegalEntitySetPageJsonVO::Wrapper execExportLegalEntitySet(const LegalEntitySetQuery::Wrapper& query, const PayloadDTO& payload);

	LegalEntitySetPullDownJsonVO::Wrapper execLegalEntitySetPullDownList();
	// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyLegalEntitySet(const LegalEntitySetDTO::Wrapper& dto);
	// ��ҳ��ѯ����
	LegalEntitySetPageJsonVO::Wrapper execQueryLES(const LegalEntitySetQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _LEGALENTITYSET_CONTROLLER_

