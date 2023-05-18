#pragma once
#ifndef _WORKHISTORY_CONTROLLER_H_
#define _WORKHISTORY_CONTROLLER_H_
#include "stdafx.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/work-history/WorkHistoryQuery.h"
#include "domain/dto/work-history/ModWorkHistoryDTO.h"
#include "domain/vo/work-history/ModWorkHistoryVO.h"
#include "domain/vo/work-history/WorkHistoryVO.h"
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
class WorkHistoryController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(WorkHistoryController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryWorkHistory) {
		// ����ӿڱ���,�õ���Ӣ���ֵ亯�����ù�zh-dict.yamlȷ������
		info->summary = ZH_WORDS_GETTER("workhistory.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(WorkHistoryJsonVO);
		//// �����ҳ��������
		//API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("ormorgname").description = ZH_WORDS_GETTER("workhistory.field.ormorgname");
		info->queryParams["ormorgname"].addExample("default", String(" "));
		info->queryParams["ormorgname"].required = true;
		
		
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/work-history", queryWorkHistory, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, WorkHistoryQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryWorkHistory(userQuery));
	}
	// 3.1 �����޸Ľӿ�����
	ENDPOINT_INFO(modifyWorkHistory) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("workhistory.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/work-history", modifyWorkHistory, BODY_DTO(WorkHistoryDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyWorkHistory(dto));
	}
private:	
	// 3.3 ��ʾ�޸�����
	WorkHistoryJsonVO::Wrapper execQueryWorkHistory(const WorkHistoryQuery::Wrapper& query);
	StringJsonVO::Wrapper execModifyWorkHistory(const WorkHistoryDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !
