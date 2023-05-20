#pragma once

#ifndef JOBTITLEYCONTROLLER_H
#define JOBTITLEYCONTROLLER_H

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/JobTitleInfo/JobTitleInfoDTO.h"
#include "domain/vo/JobTitleInfo/JobTitleInfoVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * JobTitleY����������������
 */
class JobTitleInfoController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(JobTitleInfoController);
	// 3 ����ӿ�
public:
	// ��ѯְ��
	ENDPOINT_INFO(queryJobTitle) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("jobtitle.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(JobTitleInfoJsonVO);
		// ������������������
		info->queryParams.add<String>("jobtitle_name").description = ZH_WORDS_GETTER("jobtitle.field.jobtitle_name");
		info->queryParams["jobtitle_name"].addExample("default", String("statistician"));
		info->queryParams["jobtitle_name"].required = true;
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/query-job-title", queryJobTitle, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, JobTitleInfoDTO, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryJobTitle(userQuery, authObject->getPayload()));
	}

	// ����ְ��
	ENDPOINT_INFO(getJobTitle) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("jobtitle.export.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ExportJobTitleJsonVO);
		// ������������������
		info->queryParams.add<String>("jobtitle_name").description = ZH_WORDS_GETTER("jobtitle.field.jobtitle_name");
		info->queryParams["jobtitle_name"].addExample("default", String("statistician"));
		info->queryParams["jobtitle_name"].required = true;
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/export-job-title", getJobTitle, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, JobTitleInfoDTO, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execGetJobTitle(userQuery, authObject->getPayload()));
	}
	
	// 3.1 �����޸Ľӿ�����
	ENDPOINT_INFO(modifyJobTitle) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("jobtitle.update.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/modify-job-title", modifyJobTitle, BODY_DTO(JobTitleInfoDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyJobTitle(dto));
	}
private:
	// 3.3 ��ʾ��ѯ����
	JobTitleInfoJsonVO::Wrapper execQueryJobTitle(const JobTitleInfoDTO::Wrapper& query, const PayloadDTO& payload);
	ExportJobTitleJsonVO::Wrapper execGetJobTitle(const JobTitleInfoDTO::Wrapper& query, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execModifyJobTitle(const JobTitleInfoDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_