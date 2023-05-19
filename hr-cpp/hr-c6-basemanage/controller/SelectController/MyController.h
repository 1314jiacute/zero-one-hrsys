#pragma once
#ifndef  _MYCONTROLLER_H_
#define  _MYCONTROLLER_H_


#include "domain/vo/BaseJsonVO.h"
#include "domain/query/PageQuery.h"
#include "domain/dto/sample/MyDto.h"

// 0 ����API������ʹ�ú�  (api�������Ǵ��������󣬷�����Ӧ��)

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */

class TestController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	/*
	2 ����������������
	2.1 API���������Ը��ݴ��������URL��HTTP�������࣬Ȼ������·�ɵ���Ӧ�ķ����ͷ����н��д���
	*/
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
		/*
		���ܱ�������ʱ����Ҫ�ú�   QUERIES(QueryParams, qp1)
		������Ĭ����Ȩ������Ҫ��·��(/query)������� API_HANDLER_AUTH_PARAME
		API_M_GET��������ʽ����ʾget
		"/query",��url��·��
		queryTest���ӿ�����
		QUERIES(QueryParams, qp1)����ʾ�����Ǳ����ݣ�����Ĳ������ŵ�qp1��
		*/
	ENDPOINT(API_M_GET, "/query", queryTest, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qp1))
	{
		/* 
		������ѯ����(����Ϊ����ģ�Ͷ���) Ҳ����query��dto
		���ȵ���API_HANDLER_QUERY_PARAM����������еĲ�ѯ����(Ҳ����pq1)��
		���������ת����ΪPageQuery��Ķ��󣬲�������query�������ڴ��С�
		*/
		API_HANDLER_QUERY_PARAM(query, PageQuery, qp1);
		/*
		��Ӧ���
		Ȼ�����execQueryTest()����ִ�в�ѯ������
		��ʹ��API_HANDLER_RESP_VO�꽫�����װ��StringJsonVO������н�����Ӧ��
		*/
		API_HANDLER_RESP_VO(execQueryTest(query));
	}


	//// 3.1 �����ѯ�ӿ�����
	//ENDPOINT_INFO(queryTest1)
	//{
	//	// ����ӿڱ��� �̶�д��
	//	info->summary = "query test1";
	//	// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
	//	API_DEF_ADD_AUTH();
	//	// ������Ӧ��������
	//	API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	//	// �����ҳ��������
	//	API_DEF_ADD_PAGE_PARAMS();
	//}

	//// 3.2 �����ѯ�ӿڴ���
	//	//���ܱ�������ʱ����Ҫ�ú�   QUERIES(QueryParams, qp1)
	//	//������Ĭ����Ȩ������Ҫ��·��(/query)������� API_HANDLER_AUTH_PARAME
	//ENDPOINT(API_M_GET, "/query1", queryTest1, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qp2))
	//{
	//	// ������ѯ����(����Ϊ����ģ�Ͷ���) Ҳ����query��dto
	//	API_HANDLER_QUERY_PARAM(query1, PageQuery, qp2);
	//	// ��Ӧ���
	//	API_HANDLER_RESP_VO(execQueryTest(query1));
	//}

	// 
		// 3.1 ���������ӿ�����
	//ENDPOINT_INFO(addSample) {
	//	// ����ӿڱ���
	//	info->summary = ZH_WORDS_GETTER("sample.post.summary");
	//	// ������Ӧ������ʽ
	//	API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	//}
	//// 3.2 ���������ӿڴ���
	//ENDPOINT(API_M_POST, "/sample", addSample, BODY_DTO(SampleDTO::Wrapper, dto)) {
	//	// ��Ӧ���
	//	API_HANDLER_RESP_VO(execAddSample(dto));
	//}


	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addTest) {
		// ����ӿڱ���
		info->summary = "add test";
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/add", addTest, BODY_DTO(ContractDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddSample1(dto));
	}


	// 3.1 �����޸Ľӿ�����
	ENDPOINT_INFO(changeTest) {
		// ����ӿڱ���
		info->summary = "change test";
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/change", changeTest, BODY_DTO(ContractDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifySample(dto));
	}

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeTest) {
		// ����ӿڱ���
		info->summary = "remove test";
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/remove", removeTest, BODY_DTO(ContractDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemoveSample(dto));
	}
private:
	//����ӿڵ�ִ�к���
	StringJsonVO::Wrapper execQueryTest(const PageQuery::Wrapper& query);

	Uint64JsonVO::Wrapper execAddSample1(const ContractDTO::Wrapper& dto);

	Uint64JsonVO::Wrapper execModifySample(const ContractDTO::Wrapper& dto);
	// 3.3 ��ʾɾ������
	Uint64JsonVO::Wrapper execRemoveSample(const ContractDTO::Wrapper& dto);


};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen


#endif // ! _MYCONTROLLER_H_
