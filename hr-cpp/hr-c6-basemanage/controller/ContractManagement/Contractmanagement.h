#pragma once
#ifndef _CONTRACTMANAGEMENT_H_
#define _CONTRACTMANAGEMENT_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/PageQuery.h"
#include "domain/dto/retirement/RetiremetDto.h"
#include "domain/vo/RetirementVo/RetirementVo.h"


// 0 ����API������ʹ�ú�  (api�������Ǵ��������󣬷�����Ӧ��)

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */

class ContractmanageController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	/*
	2 ����������������
	2.1 API���������Ը��ݴ��������URL��HTTP�������࣬Ȼ������·�ɵ���Ӧ�ķ����ͷ����н��д���
	*/
	API_ACCESS_DECLARE(ContractmanageController);
	// 3 ����ӿ�
public:

	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(Contract_Page_query)
	{
		// ����ӿڱ��� �̶�д��
		info->summary = ZH_WORDS_GETTER("retirement_gan.get.summary1");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(RetirementQueryPageJsonVO);
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
	ENDPOINT(API_M_GET, "/Contract-management/Page-query-Contract", Contract_Page_query, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qp1))
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
		API_HANDLER_RESP_VO(execQueryContractmanage(query));
	}


private:
	//����ӿڵ�ִ�к���
	StringJsonVO::Wrapper execQueryContractmanage(const PageQuery::Wrapper& query);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen


#endif // !_CONTRACTMANAGEMENT_H_
