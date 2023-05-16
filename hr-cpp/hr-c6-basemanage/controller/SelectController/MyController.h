#pragma once
#ifndef  _MYCONTROLLER_H_
#define  _MYCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/PageQuery.h"

// 0 ����API������ʹ�ú�  (api�������Ǵ��������󣬷�����Ӧ��)

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */

class TestController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	// 2.1 API���������Ը��ݴ��������URL��HTTP�������࣬Ȼ������·�ɵ���Ӧ�ķ����ͷ����н��д���
	API_ACCESS_DECLARE(TestController);
	// 3 ����ӿ�
public:

	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryTest) 
	{
		// ����ӿڱ��� �̶�д��
		info->summary = "query test";
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
	}

	// 3.2 �����ѯ�ӿڴ���
		//���ܱ�������ʱ����Ҫ�ú�   QUERIES(QueryParams, qp1)
		//������Ĭ����Ȩ������Ҫ��·��(/query)������� API_HANDLER_AUTH_PARAME
	ENDPOINT(API_M_GET, "/query", queryTest, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qp1))
	{
		// ������ѯ����(����Ϊ����ģ�Ͷ���) Ҳ����query��dto
		API_HANDLER_QUERY_PARAM(query, PageQuery, qp1);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryTest(query));
	}

	
private:
	//����ӿڵ�ִ�к���
	StringJsonVO::Wrapper execQueryTest(const PageQuery::Wrapper& query);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen


#endif // ! _MYCONTROLLER_H_
