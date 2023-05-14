#pragma once

#ifndef _TESTCONTROLLER_H_
#define _TESTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/PageQuery.h"

/*
	���Կ�����
*/


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) // 0

class TestController : public oatpp::web::server::api::ApiController // 1
{
	// 2 ����������������
	API_ACCESS_DECLARE(TestController);
public: // ����ӿ�
	//3 ����ӿ�����
	ENDPOINT_INFO(queryTest) {
		//����ӿڱ���
		info->summary = "test query";
		//������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//�����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
	}
	//4 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/test", queryTest, QUERIES(QueryParams, qps)) {
		//������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, PageQuery, qps);
		//��Ӧ���
		API_HANDLER_RESP_VO(execQueryTest(query));
	}
private: // ����ӿ�ִ�к���
	//5 ����ӿ�ִ�к���
	StringJsonVO::Wrapper execQueryTest(const PageQuery::Wrapper& query);


};




// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) // 0
#endif // _SAMPLE_CONTROLLER_