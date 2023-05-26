#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _EXPORTCERTIF_CONTROLLER_
#define _EXPORTCERTIF_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/CertificateManage/ExportCertifQuery.h"
#include "domain/dto/CertificateManage/ExportCertifDTO.h"
#include "domain/vo/CertificateManage/ExportCertifJsonVO.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * �ļ�����
 */
class ExportCertifController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ExportCertifController);
public: // ����ӿ�
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(ExportCertif) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("certif.export.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ExportCertifJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("sample.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = false;
		info->queryParams.add<String>("sex").description = ZH_WORDS_GETTER("sample.field.sex");
		info->queryParams["sex"].addExample("default", String("N"));
		info->queryParams["sex"].required = false;

	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/bas/export-certif", ExportCertif, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, ExportCertifQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execExportCertif(userQuery, authObject->getPayload()));
	}
private: // ����ӿ�ִ�к���
	// 3.3 ��ʾ��ҳ��ѯ����
	ExportCertifJsonVO::Wrapper execExportCertif(const ExportCertifQuery::Wrapper& query, const PayloadDTO& payload);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _EXPORTCERTIF_CONTROLLER_