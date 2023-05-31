#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/05/19 14:44:00

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
#ifndef _EMPLOYEE_INFOMATION_CONTROLLER
#define _EMPLOYEE_INFOMATION_CONTROLLER

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/EmployeeInformationPageQuery/EmployeeInformationPageQuery.h"
#include "domain/vo/EmployeeInformation/EmployeeInformationVO.h"
//#include "domain/dto/AddEmployeeAssignInfo/AddEmployeeAssignInfo.h"
#include "domain/dto/EmployeeInformationPageQuery/EmployeeInformationPageQueryDTO.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

//����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController)
/*
Ա����Ϣ������
*/
class EmployeeInformationController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(EmployeeInformationController);
public: // ����ӿ�

	//�����ҳ��ѯԱ���б�ӿڶ˵�����
	ENDPOINT_INFO(PageQueryInfo) {
		//����ӿڱ���
		info->summary = ZH_WORDS_GETTER("member.field.summary");
		//������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(EmployeeInformationPageJsonVO);
		//�����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		//���
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("employee.field.id");
		info->queryParams["id"].addExample("default", String("10001"));
		info->queryParams["id"].required = false;
		//����
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("employee.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = false;
		//��֯
		info->queryParams.add<String>("organize").description = ZH_WORDS_GETTER("employee.field.organize");
		info->queryParams["organize"].addExample("default", String("N"));
		info->queryParams["organize"].required = false;
		//����
		info->queryParams.add<String>("depart").description = ZH_WORDS_GETTER("employee.field.depart");
		info->queryParams["depart"].addExample("default", String("N"));
		info->queryParams["depart"].required = false;
		//ְ��
		info->queryParams.add<String>("job").description = ZH_WORDS_GETTER("employee.field.job");
		info->queryParams["job"].addExample("default", String("N"));
		info->queryParams["job"].required = false;
		//��λ
		info->queryParams.add<String>("post").description = ZH_WORDS_GETTER("employee.field.post");
		info->queryParams["post"].addExample("default", String("N"));
		info->queryParams["post"].required = false;
		//֤����
		info->queryParams.add<String>("idMum").description = ZH_WORDS_GETTER("employee.field.idMum");
		info->queryParams["idMum"].addExample("default", String("2665643635********"));
		info->queryParams["idMum"].required = false;
		//��������
		info->queryParams.add<String>("birthday").description = ZH_WORDS_GETTER("employee.field.birthday");
		info->queryParams["birthday"].addExample("default", String("1992-10-18 00:00:00"));
		info->queryParams["birthday"].required = false;
		// ����
		info->queryParams.add<UInt32>("age").description = ZH_WORDS_GETTER("employee.field.age");
		info->queryParams["age"].addExample("default", UInt32(20));
		info->queryParams["age"].required = false;
		//�ֻ�����
		info->queryParams.add<String>("phone").description = ZH_WORDS_GETTER("employee.field.phone");
		info->queryParams["phone"].addExample("default", String("159182***22"));
		info->queryParams["phone"].required = false;
		//Ա��״̬
		info->queryParams.add<String>("state").description = ZH_WORDS_GETTER("employee.field.state");
		info->queryParams["state"].addExample("default", String("be on the job"));
		info->queryParams["state"].required = false;
		
	}
	//�����ҳ��ѯԱ���б�ӿڶ˵㴦��
	ENDPOINT(API_M_GET, "/employee-information/page-query", PageQueryInfo, QUERIES(QueryParams, queryParams)) {
		//������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, EmployeeInformationPageQuery, queryParams);
		//��Ӧ���
		API_HANDLER_RESP_VO(execEmployeeInformation(query));
	}	

	//���嵼��Ա����Ϣ�ӿڶ˵�����	
	ENDPOINT_INFO(importEmployeeInfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("user.query-all.import");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	//���嵼��Ա����Ϣ�ӿڶ˵㴦��
	ENDPOINT(API_M_POST, "/employee-information/import-info", importEmployeeInfo, BODY_DTO(EmployeeInformationDTO::Wrapper, importInfo)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execImportEmployeeInfo(importInfo));
	}

	//���嵼��Ա����Ϣ(������ҳ��ǰ�����)�ӿڶ˵�����	
	ENDPOINT_INFO(exportEmployeeInfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("user.query-all.export");
		// ���Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON(EmployeeInformationPageJsonVO::Wrapper);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		//���
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("employee.field.id");
		info->queryParams["id"].addExample("default", String("10001"));
		//����
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("employee.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		//��֯
		info->queryParams.add<String>("organize").description = ZH_WORDS_GETTER("employee.field.organize");
		info->queryParams["organize"].addExample("default", String("N"));
		info->queryParams["organize"].required = false;
		//����
		info->queryParams.add<String>("depart").description = ZH_WORDS_GETTER("employee.field.depart");
		info->queryParams["depart"].addExample("default", String("N"));
		info->queryParams["depart"].required = false;
		//ְ��
		info->queryParams.add<String>("job").description = ZH_WORDS_GETTER("employee.field.job");
		info->queryParams["job"].addExample("default", String("N"));
		info->queryParams["job"].required = false;
		//��λ
		info->queryParams.add<String>("post").description = ZH_WORDS_GETTER("employee.field.post");
		info->queryParams["post"].addExample("default", String("N"));
		info->queryParams["post"].required = false;
		//֤����
		info->queryParams.add<String>("idMum").description = ZH_WORDS_GETTER("employee.field.idMum");
		info->queryParams["idMum"].addExample("default", String("2665643635********"));
		info->queryParams["idMum"].required = false;
		//��������
		info->queryParams.add<String>("birthday").description = ZH_WORDS_GETTER("employee.field.birthday");
		info->queryParams["birthday"].addExample("default", String("20000-00-00"));
		info->queryParams["birthday"].required = false;
		// ����
		info->queryParams.add<UInt32>("age").description = ZH_WORDS_GETTER("employee.field.age");
		info->queryParams["age"].addExample("default", UInt32(20));
		info->queryParams["age"].required = false;
		//�ֻ�����
		info->queryParams.add<String>("phone").description = ZH_WORDS_GETTER("employee.field.phone");
		info->queryParams["phone"].addExample("default", String("159182***22"));
		info->queryParams["phone"].required = false;
		//Ա��״̬
		info->queryParams.add<String>("state").description = ZH_WORDS_GETTER("employee.field.state");
		info->queryParams["state"].addExample("default", String("be on the job"));
		info->queryParams["state"].required = false;
	}
	//���嵼��Ա����Ϣ(������ҳ��ǰ�����)�ӿڶ˵㴦��
	ENDPOINT(API_M_GET, "/employee-information/export-info", exportEmployeeInfo, API_HANDLER_AUTH_PARAME,QUERIES(QueryParams,queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(exportInfo, EmployeeInformationPageQuery,queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execExportEmployeeInfo(exportInfo));
	}
	
	//��������Ա����Ϣ�ӿڶ˵�����	
	ENDPOINT_INFO(addEmployee) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("orgsector.field.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	//��������Ա����Ϣ�ӿڶ˵㴦��
	ENDPOINT(API_M_POST, "/employee-information/add-new-info", addEmployee, BODY_DTO(EmployeeInformationDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddEmployee(dto));
	}
private:// ����ӿ�ִ�к���
	
	//��ҳ��ѯԱ���б�
	EmployeeInformationPageJsonVO::Wrapper execEmployeeInformation(const EmployeeInformationPageQuery::Wrapper& query);
	//����Ա����Ϣ
	Uint64JsonVO::Wrapper execImportEmployeeInfo(const EmployeeInformationDTO::Wrapper& importInfo);
	//����Ա����Ϣ(������ҳ��ǰ�����)
	EmployeeInformationPageJsonVO::Wrapper execExportEmployeeInfo(const EmployeeInformationPageQuery::Wrapper& exportInfo);
	//����Ա����Ϣ
	Uint64JsonVO::Wrapper execAddEmployee(const EmployeeInformationDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_EMPLOYEE_INFOMATION_CONTROLLER
