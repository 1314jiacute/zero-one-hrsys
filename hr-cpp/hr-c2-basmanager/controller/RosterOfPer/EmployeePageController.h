/*
 Copyright Zero One Star. All rights reserved.

 @Author: luoluo
 @Date: 2023/05/18 16:12:54

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
#ifndef _EMPLOYEEPAGECONTROLLER_H_
#define _EMPLOYEEPAGECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/RosterOfPer/EmployeePageDTO.h"
#include "domain/query/RosterOfPer/EmployeePageQuery.h"
#include "domain/vo/RosterOfPer/EmployeePageVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include OATPP_CODEGEN_BEGIN(ApiController)

class EmployeePageController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(EmployeePageController);
public: // ����ӿ�
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryEmployeePage) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("employee.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(EmployeePageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("EMPLOYEEID").description = ZH_WORDS_GETTER("employee.field.employeeid");
		info->queryParams["EMPLOYEEID"].addExample("default", String("N"));
		info->queryParams["EMPLOYEEID"].required = false;
		info->queryParams.add<String>("EMPLOYEENAME").description = ZH_WORDS_GETTER("employee.field.employeename");
		info->queryParams["EMPLOYEENAME"].addExample("default", String("li ming"));
		info->queryParams["EMPLOYEENAME"].required = false;
		
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/query-employeePage", queryEmployeePage, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, EmployeePageQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryEmployeePage(userQuery, authObject->getPayload()));
	}
private: // ����ӿ�ִ�к���
	// 3.3 ��ʾ��ҳ��ѯ����
	EmployeePageJsonVO::Wrapper execQueryEmployeePage(const EmployeePageQuery::Wrapper& query, const PayloadDTO& payload);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_EMPLOYEEPAGECONTROLLER_H_
