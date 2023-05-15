#pragma once
#ifndef _JOBTITLE_INFORMATIONCONTROLLER_H_
#define _JOBTITLE_INFORMATIONCONTROLLER_H_
#include "stdafx.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/certificate-information/JobTitleInformationPageQuery.h"
#include "domain/dto/certificate-information/JobTitleInformationDTO.h"
#include "domain/vo/certificate-information/JobTitleInformationVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class JobTitleInformationController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(JobTitleInformationController);
	// ����ӿ�
public:
	//�����ѯ�ӿ�����
	ENDPOINT_INFO(queryJobTitleInformation) {
		// ����ӿڱ���,�õ���Ӣ���ֵ亯�����ù�zh-dict.yamlȷ������
		info->summary = ZH_WORDS_GETTER("sample.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(JobTitleInformationPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		//����ְ������ professoranalysis_name
		info->queryParams.add<String>("professoranalysis_name").description = ZH_WORDS_GETTER("sample.field.professoranalysis_name");
		//����֤���� credentials_num
		info->queryParams.add<String>("credentials_num").description = ZH_WORDS_GETTER("sample.field.credentials_num");
		//����ְ�Ƶȼ� professor_grades
		info->queryParams.add<String>("professor_grades").description = ZH_WORDS_GETTER("sample.field.professor_grades");
		//ְ�ƻ�ȡ���� zchqrq
		info->queryParams.add<String>("zchqrq").description = ZH_WORDS_GETTER("sample.field.zchqrq");
		//��������λ reviewbody
		info->queryParams.add<String>("reviewbody").description = ZH_WORDS_GETTER("sample.field.reviewbody");
		//����ǩ������ lssuingagency
		info->queryParams.add<String>("lssuingagency").description = ZH_WORDS_GETTER("sample.field.lssuingagency");
		//����ְ��Ƹ��ʱ�� employtime
		info->queryParams.add<String>("employtime").description = ZH_WORDS_GETTER("sample.field.employtime");
		//�����Ƿ����ְ�� enable
		info->queryParams.add<String>("enable").description = ZH_WORDS_GETTER("sample.field.enable");
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/certificate-information", queryJobTitleInformation, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, JobTitleInformationQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryJobTitleInformation(userQuery, authObject->getPayload()));
	}
private:
	// 3.3 ��ʾ��ҳ��ѯ����
	JobTitleInformationPageJsonVO::Wrapper execQueryJobTitleInformation(const JobTitleInformationQuery::Wrapper& query, const PayloadDTO& payload);
};
// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _DEBUG





