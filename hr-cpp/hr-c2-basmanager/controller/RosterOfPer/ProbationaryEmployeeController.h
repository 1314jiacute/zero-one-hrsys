#pragma once

/**
 *  �������� ���� ��Ա������ ���� ����Ա�� ���� ������
 */

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
#ifndef _PROBATIONARY_EMPLOYEE_CONTROLLER_
#define _PROBATIONARY_EMPLOYEE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/RosterOfPer/ProbationaryEmployeeQuery.h"
#include "domain/dto/RosterOfPer/ProbationaryEmployeeDTO.h"
#include "domain/vo/RosterOfPer/ProbationaryEmployeeVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ProbationaryEmployeeController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ProbationaryEmployeeController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ����� ѯ����������Ա������
	ENDPOINT_INFO(queryProbationaryEmployee) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("probationaryemployee.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProbationaryEmployeePageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("id_or_name").description = ZH_WORDS_GETTER("formeremployees.field.id_or_name");
		info->queryParams["id_or_name"].addExample("default", String("1"));
		info->queryParams["id_or_name"].required = false;

		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("sample.field.id");
		info->queryParams["id"].addExample("default", String(""));
		info->queryParams["id"].required = false;

		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("formeremployees.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = false;

		info->queryParams.add<String>("zjhm").description = ZH_WORDS_GETTER("probationaryemployee.field.zjhm");
		info->queryParams["zjhm"].addExample("default", String(""));
		info->queryParams["zjhm"].required = false;

		info->queryParams.add<String>("organization").description = ZH_WORDS_GETTER("probationaryemployee.field.organization");
		info->queryParams["organization"].addExample("default", String(""));
		info->queryParams["organization"].required = false;

		info->queryParams.add<String>("bm").description = ZH_WORDS_GETTER("probationaryemployee.field.bm");
		info->queryParams["bm"].addExample("default", String(""));
		info->queryParams["bm"].required = false;

		info->queryParams.add<String>("ygzt").description = ZH_WORDS_GETTER("probationaryemployee.field.ygzt");
		info->queryParams["ygzt"].addExample("default", String(""));
		info->queryParams["ygzt"].required = false;

		info->queryParams.add<String>("zgzt").description = ZH_WORDS_GETTER("probationaryemployee.field.zgzt");
		info->queryParams["zgzt"].addExample("default", String(""));
		info->queryParams["zgzt"].required = false;

	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/bas/query-all-ProbationaryEmployee", queryProbationaryEmployee, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(Query, ProbationaryEmployeeQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryProbationaryEmployee(Query, authObject->getPayload()));
	}

	// 3.1 ���嵼���ӿ�����
	ENDPOINT_INFO(exportProbationaryEmployee) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("probationaryemployee.get.out");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ������������������
		info->queryParams.add<String>("id_or_name").description = ZH_WORDS_GETTER("formeremployees.field.id_or_name");
		info->queryParams["id_or_name"].addExample("default", String("1"));
		info->queryParams["id_or_name"].required = false;

		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("sample.field.id");
		info->queryParams["id"].addExample("default", String(""));
		info->queryParams["id"].required = false;

		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("formeremployees.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = false;

		info->queryParams.add<String>("zjhm").description = ZH_WORDS_GETTER("probationaryemployee.field.zjhm");
		info->queryParams["zjhm"].addExample("default", String(""));
		info->queryParams["zjhm"].required = false;

		info->queryParams.add<String>("organization").description = ZH_WORDS_GETTER("probationaryemployee.field.organization");
		info->queryParams["organization"].addExample("default", String(""));
		info->queryParams["organization"].required = false;

		info->queryParams.add<String>("bm").description = ZH_WORDS_GETTER("probationaryemployee.field.bm");
		info->queryParams["bm"].addExample("default", String(""));
		info->queryParams["bm"].required = false;

		info->queryParams.add<String>("ygzt").description = ZH_WORDS_GETTER("probationaryemployee.field.ygzt");
		info->queryParams["ygzt"].addExample("default", String(""));
		info->queryParams["ygzt"].required = false;

		info->queryParams.add<String>("zgzt").description = ZH_WORDS_GETTER("probationaryemployee.field.zgzt");
		info->queryParams["zgzt"].addExample("default", String(""));
		info->queryParams["zgzt"].required = false;
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/bas/get-ProbationaryEmployee", exportProbationaryEmployee, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(Query, ProbationaryEmployeeQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execExportProbationaryEmployee(Query, authObject->getPayload()));
	}
private:
	// ��ҳ��ѯ����Ա������
	ProbationaryEmployeePageJsonVO::Wrapper execQueryProbationaryEmployee(const ProbationaryEmployeeQuery::Wrapper& query, const PayloadDTO& payload);
	// ��������Ա��Excel���
	StringJsonVO::Wrapper execExportProbationaryEmployee(const ProbationaryEmployeeQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_