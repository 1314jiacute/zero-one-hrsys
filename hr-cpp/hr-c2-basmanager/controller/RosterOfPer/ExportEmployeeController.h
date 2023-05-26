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
#ifndef _EXPORTEMPLOYEE_CONTROLLER_
#define _EXPORTEMPLOYEE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"

#include "domain/query/RosterOfPer/ExportEmployeeQuery.h"
#include "domain/dto/RosterOfPer/ExportEmployeeDTO.h"
#include "domain/vo/RosterOfPer/ExportEmployeeJsonVO.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class ExportEmployeeController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ExportEmployeeController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(exportEmployee) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("employee.export.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ExportEmployeeJsonVO);
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
	ENDPOINT(API_M_GET, "/bas/export-employee", exportEmployee, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, ExportEmployeeQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execExportEmployee(userQuery, authObject->getPayload()));
	}

private:
	// 3.3 ��ʾ��ҳ��ѯ����
	ExportEmployeeJsonVO::Wrapper execExportEmployee(const ExportEmployeeQuery::Wrapper& query, const PayloadDTO& payload);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _EXPORTEMPLOYEE_CONTROLLER_