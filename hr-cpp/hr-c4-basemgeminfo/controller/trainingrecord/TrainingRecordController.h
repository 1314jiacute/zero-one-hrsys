#pragma once

//Author: Diaukray

#ifndef _TRAININGRECORDCONTROLLER_H_
#define _TRAININGRECORDCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class TrainingRecordController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(TrainingRecordController);
public: // ����ӿ�
	// ����ӿ�����
	ENDPOINT_INFO(queryTest) {
		// ����ӿڱ���
		info->summary = "This is TrainingRecord PageQuery";
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
	}
	
	ENDPOINT(API_M_GET, "/trianingrecord", queryTest, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, PageQuery, qps);
		//��Ӧ���
		API_HANDLER_RESP_VO(execQueryTest(query));
	}


private: // ����ӿ�ִ�к���
	StringJsonVO::Wrapper execQueryTest(const PageQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif