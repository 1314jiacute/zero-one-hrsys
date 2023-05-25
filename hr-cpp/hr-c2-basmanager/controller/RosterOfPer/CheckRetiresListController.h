#pragma once

#ifndef _CHECK_RETIRES_CONTROLLER_
#define _CHECK_RETIRES_CONTROLLER_

#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/RosterOfPer/CheckRetiresListQuery.h"
#include "domain/dto/RosterOfPer/CheckRetiresListDTO.h"
#include "domain/vo/RosterOfPer/CheckRetiresListVO.h"
/*������δ�õ�*/
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
 * ��ѯ����Ա���б������
 */
class CheckRetiresListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(CheckRetiresListController);

public://  ����ӿڣ�����ӿ�������ӿڶ˵㣩
	// 3���������ӿ�����
	ENDPOINT_INFO(queryCheckRetiresList) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("rosterofper.get.checklist");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(CheckRetiresListPageJsonVO);
		//�����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		//���������ѯ������required��ʾ�Ƿ����
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("rosterofper.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = false;
		info->queryParams.add<String>("sex").description = ZH_WORDS_GETTER("rosterofper.field.sex");
		info->queryParams["sex"].addExample("default", String("N"));
		info->queryParams["sex"].required = false;
	}
	//4 ���������ӿڴ���
	ENDPOINT(API_M_GET, "/query-CheckRetiresList", queryCheckRetiresList, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		API_HANDLER_QUERY_PARAM(query, CheckRetiresListQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryCheckRetiresList(query));
	}

private://����ִ�к���
	// ��ҳ��ѯ����
	CheckRetiresListPageJsonVO::Wrapper execQueryCheckRetiresList(const PageQuery::Wrapper& query);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController)
#endif // _CheckRetiresList_CONTROLLER_