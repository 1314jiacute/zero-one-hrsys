#pragma once

// 
// ʵ��֤���ѯָ��֤���������ָ��֤�����

#ifndef __UPDATECERTIFIDATE_CONTROLLER_
#define __UPDATECERTIFIDATE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/CertificateManage/updateCertificateQuery.h"
#include "domain/dto/CertificateManage/CertificateInfoDTO.h"
#include "domain/vo/CertificateManage/CertificateInfoVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

// ʵ�ֲ�ѯָ��֤����ϸ��Ϣ�͸���ָ��֤�鹦��
class UpdateCertificateController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(UpdateCertificateController);
	// 3 ����ӿ�
public:
	// 3.1 �������ָ��֤����Ϣ�ӿ�����
	ENDPOINT_INFO(updateCertificate) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("certificate.update");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(BooleanJsonVO);
		// �����ҳ��������
		//API_DEF_ADD_PAGE_PARAMS();
		//// ������������������
		//info->queryParams.add<UInt64>("id").description = ZH_WORDS_GETTER("formeremployees.field.id");
		//info->queryParams["id"].addExample("default", String("1"));
		//info->queryParams["id"].required = false;
		//info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("formeremployees.field.name");
		//info->queryParams["name"].addExample("default", String("li ming"));
		//info->queryParams["name"].required = false;
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/update-Certificater", updateCertificate, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, updateCertificateQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execUpdateCertificateInfo(userQuery, authObject->getPayload()));
	}

	// 3.1 �����ѯָ��֤����Ϣ�ӿ�����
	ENDPOINT_INFO(getCertificateInfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("certificate.get");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CertificateInfoJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		//// ������������������
		//info->queryParams.add<UInt64>("outbenye").description = ZH_WORDS_GETTER("formeremployees.field.outbenye");
		//info->queryParams["outbenye"].addExample("default", String("1"));
		//info->queryParams["outbenye"].required = false;
		//info->queryParams.add<UInt64>("outall").description = ZH_WORDS_GETTER("formeremployees.field.outall");
		//info->queryParams["outall"].addExample("default", String("0"));
		//info->queryParams["outall"].required = false;
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/get-Certificater", getCertificateInfo, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, updateCertificateQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execGetCertificateInfo(userQuery, authObject->getPayload()));
	}
private:
	// 3.3 ����֤����Ϣ
	CertificateInfoPageJsonVO::Wrapper execUpdateCertificateInfo(const updateCertificateQuery::Wrapper& query, const PayloadDTO& payload);
	// ��ѯ֤����Ϣ
	CertificateInfoPageJsonVO::Wrapper execGetCertificateInfo(const updateCertificateQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_