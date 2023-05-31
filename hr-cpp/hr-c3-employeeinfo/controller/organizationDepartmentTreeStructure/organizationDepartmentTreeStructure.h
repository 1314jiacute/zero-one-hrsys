#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/05/24 15:14:27

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

#ifndef _ORGNAIZATION_DEPARTMENT_TREE_STRUCTURE_
#define _ORGNAIZATION_DEPARTMENT_TREE_STRUCTURE_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
//#include "domain/query/EmployeeInformationPageQuery/EmployeeInformationPageQuery.h"
//#include "domain/vo/EmployeeInformation/EmployeeInformationVO.h"
//#include "domain/dto/AddEmployeeAssignInfo/AddEmployeeAssignInfo.h"
//#include "domain/dto/EmployeeInformationPageQuery/EmployeeInformationPageQueryDTO.h"
#include "domain/vo/org/MemberVO.h"
#include "domain/query/orgquery/RootOrgQuery.h"
#include "domain/query/orgquery/ValidOrgQuery.h"
#include "domain/vo/org/OrgSectorVO.h"
#include "domain/vo/org/OrgVO.h"
#include "domain/query/orgquery/SectorQuery.h"
#include "service/org/OrgService.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/*
* �����ѯ���в��Žṹ����Ϣ�ӿڶ˵㴦��
*/
class organizationDepartmentTreeStructure : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(organizationDepartmentTreeStructure);
public: // ����ӿ�

	//�����ѯ����֯��Ϣ�ӿڶ˵�����
	ENDPOINT_INFO(rootOrgQuery) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("org.field.root");
		// ���Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON(MemberJsonVO::Wrapper);
		// ������������������
        // ����ƥ��
		info->queryParams.add<String>("filter").description = ZH_WORDS_GETTER("rootorg.query.filter");
		info->queryParams["filter"].addExample("default", String("filter"));
		//����ʽ
		info->queryParams.add<String>("sort").description = ZH_WORDS_GETTER("rootorg.query.sort");
		info->queryParams["sort"].addExample("default", String("sort"));
	
	}
	//�����ѯ����֯��Ϣ�ӿڶ˵㴦��
	ENDPOINT(API_M_GET, "/organization-department-tree-structure/root-org-query", rootOrgQuery, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(rootQuery,RootOrgQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRootOrgQuery(rootQuery, authObject));
	}

	//�����ѯ��Ч��֯��Ϣ�ӿڶ˵�����
	ENDPOINT_INFO(validOrgQuery) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("org.field.validorg");
		// ���Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON(MemberJsonVO::Wrapper);
		// ������������������
		// ����ƥ��
		info->queryParams.add<String>("fillter").description = ZH_WORDS_GETTER("validorg.query.filter");
		info->queryParams["fillter"].addExample("default", String("fillter"));
		//����֯id
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("validorg.query.porgid");
		info->queryParams["id"].addExample("default", String("10001"));
		//����ʽ
		info->queryParams.add<String>("sort").description = ZH_WORDS_GETTER("validorg.query.sort");
		info->queryParams["sort"].addExample("default", String("sort"));
	}
	//�����ѯ��Ч��֯��Ϣ�ӿڶ˵㴦��
	ENDPOINT(API_M_GET, "/organization-department-tree-structure/valid-org-query", validOrgQuery, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(validOrg, ValidOrgQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execValidOrgQuery(validOrg));
	}

	//�����ѯ������Ϣ�ӿڶ˵�����
	ENDPOINT_INFO(secotrOrgQuery) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("org.field.sector");
		// ���Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON(OrgSectorVO::Wrapper);
		// ������������������
		// ��ѯSector��parent��OrmOrg����OrmOrgsector
		info->queryParams.add<String>("parentdename").description = ZH_WORDS_GETTER("sector.query.sort");
		info->queryParams["parentdename"].addExample("default", String("OrmOrg"));
		//�ϼ�����id
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("sector.query.parentkey");
		info->queryParams["id"].addExample("default", String("10001"));
		//����ʽ
		info->queryParams.add<String>("sort").description = ZH_WORDS_GETTER("sector.query.sort");
		info->queryParams["sort"].addExample("default", String("sort"));
	}
	//�����ѯ������Ϣ�ӿڶ˵㴦��
	ENDPOINT(API_M_GET, "/organization-department-tree-structure/sector-org-query", secotrOrgQuery, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(sectorOrg, SectorQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execSectorOrgQuery(sectorOrg));
	}


private: // ����ӿ�ִ�к���
	//��ѯ����֯
	OrgJsonVO::Wrapper execRootOrgQuery(const RootOrgQuery::Wrapper& rootQuery, const std::shared_ptr<CustomerAuthorizeObject> &authObject);
	//��ѯ��Ч��֯
	OrgJsonVO::Wrapper execValidOrgQuery(const ValidOrgQuery::Wrapper& validOrg);
	//��ѯ����
	OrgSectorVO::Wrapper execSectorOrgQuery(const SectorQuery::Wrapper& sectorOrg);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_ORGNAIZATION_DEPARTMENT_TREE_STRUCTURE_