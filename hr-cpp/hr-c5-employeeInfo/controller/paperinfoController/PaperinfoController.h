#pragma once

#ifndef _PAPERINFO_CONTROLLER_H_
#define _PAPERINFO_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/paperinfo/PaperQuery.h"
#include "domain/dto/paperinfo/PaperDTO.h"
#include "domain/vo/paperinfo/PaperVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

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
		API_DEF_ADD_RSP_JSON_WRAPPER(PaperJsonVO);
		//�����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
	}
	//4 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/test", queryPaperinfo, QUERIES(QueryParams, qps)) {
		//������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, PageQuery, qps);
		//��Ӧ���
		API_HANDLER_RESP_VO(execQueryPaperinfo(query));
	}
private: // ����ӿ�ִ�к���
	//5 ����ӿ�ִ�к���
	StringJsonVO::Wrapper execQueryPaperinfo(const PageQuery::Wrapper& query);
};


// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) // 0
#endif // _SAMPLE_CONTROLLER_