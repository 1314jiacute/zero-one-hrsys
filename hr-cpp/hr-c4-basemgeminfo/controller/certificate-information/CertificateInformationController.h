#pragma once
#ifndef _CERTIFICATE_INFORMATIONCONTROLLER_H_
#define _CERTIFICATE_INFORMATIONCONTROLLER_H_
#include "stdafx.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/certificate-information/CertificateInformationPageQuery.h"
#include "domain/dto/certificate-information/CertificateInformationDTO.h"
#include "domain/vo/certificate-information/CertificateInformationVO.h"
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
class CertificateInformationController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(CertificateInformationController);
	// ����ӿ�
public:
		//�����ѯ�ӿ�����
	ENDPOINT_INFO(queryCertificateInformation) {
		// ����ӿڱ���,�õ���Ӣ���ֵ亯�����ù�zh-dict.yamlȷ������
		info->summary = ZH_WORDS_GETTER("sample.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CertificateInformationPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		//����֤���� 
		info->queryParams.add<String>("zgzsbh").description = ZH_WORDS_GETTER("sample.field.zgzsbh");		
		//����֤������
		info->queryParams.add<String>("pimvocationalname").description = ZH_WORDS_GETTER("sample.field.pimvocationalname");
		//����֤������
		info->queryParams.add<String>("zslx").description = ZH_WORDS_GETTER("sample.field.zslx");		
		//����ǩ������
		info->queryParams.add<String>("zghqrq").description = ZH_WORDS_GETTER("sample.field.zghqrq");
		//����ǩ������
		info->queryParams.add<String>("zgsydw").description = ZH_WORDS_GETTER("sample.field.zgsydw");
		//���뷢֤��Ч��
		info->queryParams.add<String>("fzyxq").description = ZH_WORDS_GETTER("sample.field.fzyxq");
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/certificate-information", queryCertificateInformation, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, CertificateInformationQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQuerySample(userQuery, authObject->getPayload()));
	}
private:
	// 3.3 ��ʾ��ҳ��ѯ����
	CertificateInformationPageJsonVO::Wrapper execQuerySample(const CertificateInformationQuery::Wrapper& query, const PayloadDTO& payload);
};
	// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _DEBUG
