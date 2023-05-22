#pragma once

#ifndef _PAPERINFO_CONTROLLER_
#define _PAPERINFO_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/paperinfo/PaperQuery.h"
#include "domain/vo/paperinfo/PaperVO.h"

/*
	������Ϣ������
*/


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) // 0

class PaperinfoController : public oatpp::web::server::api::ApiController // 1
{
	// 2 ����������������
	API_ACCESS_DECLARE(PaperinfoController);
public: // ����ӿ�
	//3 ����ӿ�����
	ENDPOINT_INFO(queryPaperinfo) {
		//����ӿڱ���
		info->summary = ZH_WORDS_GETTER("paperinfo.get.summary");
		//������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(PaperPageJsonVO);
		//�����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("paperinfo.field.pimpersonid");
		info->queryParams["pimpersonid"].addExample("default", String("10001"));
		info->queryParams["pimpersonid"].required = true;
	}
	//4 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/employee-info/query-by-pimpersonid", queryPaperinfo, QUERIES(QueryParams, qps)) {
		//������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, PageQuery, qps);
		//��Ӧ���
		API_HANDLER_RESP_VO(execQueryPaperinfo(query));
	}

	// 3.1 �����޸Ľӿ�����
	ENDPOINT_INFO(modifySample) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("paperinfo.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/employee-info/modify-paperinfo", modifySample, BODY_DTO(PaperDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyPaperinfo(dto));
	}

private: // ����ӿ�ִ�к���
	//5 ����ӿ�ִ�к���
	PaperPageJsonVO::Wrapper execQueryPaperinfo(const PageQuery::Wrapper& query);

	// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyPaperinfo(const PaperDTO::Wrapper& dto);
};


// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) // 0
#endif 