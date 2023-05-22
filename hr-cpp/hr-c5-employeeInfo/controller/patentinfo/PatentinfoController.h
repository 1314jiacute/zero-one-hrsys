#pragma once

#ifndef _TESTCONTROLLER_H_
#define _TESTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/patentinfo/PatentinfoQuery.h"
#include "domain/vo/patentinfo/PatentinfoVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController) // 0

/**
 * ���Կ�����
 */
class PatentinfoController : public oatpp::web::server::api::ApiController // 1
{
	// 2 ����������������
	API_ACCESS_DECLARE(PatentinfoController);
public: // ����ӿ�







	// 3 ����ӿ�����
	ENDPOINT_INFO(queryPatentinfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("patentInformation.select.summary");
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(PatentinfoJsonVO);
		// �����ҳ��ѯ��������
		//API_DEF_ADD_PAGE_PARAMS();
		// ���������ѯ����

		//Ա�����
		info->queryParams.add<String>("PIMPATENTID").description = ZH_WORDS_GETTER("patentInformation.pimpatent.PIMPATENTID");
		info->queryParams["PIMPATENTID"].addExample("default", String("1234"));
		info->queryParams["PIMPATENTID"].required = true;

	}
	// 4 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/test", queryPatentinfo, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, PatentinfoQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryPatentinfo(query));
	}









	// 3.1 �����޸Ľӿ�����
	ENDPOINT_INFO(modifySample) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("patentInformation.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/employee-info/modify-patentinfo", modifySample, BODY_DTO(PatentinfoDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyPatentinfo(dto));
	}










private: // ����ӿ�ִ�к���



	// 5 ����ӿڵ�ִ�к���
	PatentinfoJsonVO::Wrapper execQueryPatentinfo(const PatentinfoQuery::Wrapper& query);

	// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyPatentinfo(const PatentinfoDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_TESTCONTROLLER_H_
