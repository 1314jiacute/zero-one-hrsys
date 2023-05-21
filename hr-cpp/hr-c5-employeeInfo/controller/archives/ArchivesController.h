#pragma once

#ifndef _ARCHIVES_CONTROLLER_H_
#define _ARCHIVES_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/archives/ArchivesQuery.h"
#include "domain/vo/archives/ArchivesVO.h"

/*
	��Ϣ������
*/


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) // 0

class ArchivesController : public oatpp::web::server::api::ApiController // 1
{
	// 2 ����������������
	API_ACCESS_DECLARE(ArchivesController);
public: // ����ӿ�
	//3 ����ӿ�����
	ENDPOINT_INFO(queryArchivesinfo) {
		//����ӿڱ���
		info->summary = ZH_WORDS_GETTER("archives.get.summary");
		//������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(ArchivesPageJsonVO);
		//�����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
	}
	//4 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/employee-info/query-archives", queryArchivesinfo, QUERIES(QueryParams, qps)) {
		//������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, PageQuery, qps);
		//��Ӧ���
		API_HANDLER_RESP_VO(execQueryArchivesinfo(query));
	}

private: // ����ӿ�ִ�к���
	//5 ����ӿ�ִ�к���
	ArchivesPageJsonVO::Wrapper execQueryArchivesinfo(const PageQuery::Wrapper& query);
};


// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) // 0
#endif 