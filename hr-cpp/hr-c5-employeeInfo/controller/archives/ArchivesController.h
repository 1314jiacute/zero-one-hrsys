#pragma once

#ifndef _ARCHIVES_CONTROLLER_H_
#define _ARCHIVES_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/archives/ArchivesQuery.h"
#include "domain/vo/archives/ArchivesVO.h"

/*
	������Ϣ������
*/


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) // 0

class ArchivesController
	: public oatpp::web::server::api::ApiController // 1
{
	// 2.����������������
	API_ACCESS_DECLARE(ArchivesController);
public:	// ����ӿ�
	// 3.����ӿ�����
	// �����½������ӿ�����
	ENDPOINT_INFO(addArchivesInfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("archives.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 4.����ӿڴ���
	ENDPOINT(API_M_POST, "/archives/addArchivesInfo", addArchivesInfo, BODY_DTO(ArchivesDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddArchivesInfo(dto));
	}

	// ����ɾ�������ӿ�����
	ENDPOINT_INFO(removeArchivesInfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("archives.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ����ɾ�������ӿڴ���
	ENDPOINT(API_M_DEL, "/archives/removeArchivesInfo", removeArchivesInfo, BODY_DTO(ArchivesDTO::Wrapper, dto)) {
		API_HANDLER_RESP_VO(execRemoveArchivesInfo(dto));
	}

	// �����ѯָ�������ӿ�����
	ENDPOINT_INFO(querySpecifiedArchivesInfo) {
		info->summary = ZH_WORDS_GETTER("specifiedArchives.get.summary");
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ArchivesPageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		
	}
	ENDPOINT(API_M_GET, "/archives/querySpecifiedArchivesInfo", querySpecifiedArchivesInfo, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(archiveQuery, ArchivesQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQuerySpecifiedArchivesInfo(archiveQuery, authObject->getPayload()));
	}

	ENDPOINT_INFO(queryArchivesinfo) {
		//����ӿڱ���
		info->summary = ZH_WORDS_GETTER("archives.get.summary");
		//������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(ArchivesPageJsonVO);
		//�����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������������
		info->queryParams.add<String>("ygbh").description = ZH_WORDS_GETTER("archives.field.YGBH");
		info->queryParams["ygbh"].addExample("default", String("10001"));
		info->queryParams["ygbh"].required = false;// �Ƿ�������

		info->queryParams.add<String>("PimPersonName").description = ZH_WORDS_GETTER("archives.field.PimPersonName");
		info->queryParams["PimPersonName"].addExample("default", String("zhang san"));
		info->queryParams["PimPersonName"].required = false;// �Ƿ�������

		info->queryParams.add<String>("archivesNo").description = ZH_WORDS_GETTER("archives.field.archivesNo");
		info->queryParams["archivesNo"].addExample("default", String("123456"));
		info->queryParams["archivesNo"].required = false;// �Ƿ�������

		info->queryParams.add<String>("ygzt").description = ZH_WORDS_GETTER("archives.field.ygzt");
		info->queryParams["ygzt"].addExample("default", String("zai zhi"));
		info->queryParams["ygzt"].required = false;// �Ƿ�������

		info->queryParams.add<String>("DAZT").description = ZH_WORDS_GETTER("archives.field.DAZT");
		info->queryParams["DAZT"].addExample("default", String("zheng chang"));
		info->queryParams["DAZT"].required = false;// �Ƿ�������

		info->queryParams.add<String>("dajyzt").description = ZH_WORDS_GETTER("archives.field.dajyzt");
		info->queryParams["dajyzt"].addExample("default", String("yi jie chu"));
		info->queryParams["dajyzt"].required = false;// �Ƿ�������
	}
	//4 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/employee-info/query-archives", queryArchivesinfo, QUERIES(QueryParams, qps)) {
		//������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, ArchivesQuery, qps);
		//��Ӧ���
		API_HANDLER_RESP_VO(execQueryArchivesinfo(query));
	}
private:
	// ��ѯָ������
	ArchivesJsonVO::Wrapper execQuerySpecifiedArchivesInfo(const ArchivesQuery::Wrapper& dto, const PayloadDTO& payload);
	// ��������
	Uint64JsonVO::Wrapper execAddArchivesInfo(const ArchivesDTO::Wrapper& dto);
	// ɾ������
	Uint64JsonVO::Wrapper execRemoveArchivesInfo(const ArchivesDTO::Wrapper& dto);

	ArchivesPageJsonVO::Wrapper execQueryArchivesinfo(const ArchivesQuery::Wrapper& query);
};


// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) // 0
#endif 

