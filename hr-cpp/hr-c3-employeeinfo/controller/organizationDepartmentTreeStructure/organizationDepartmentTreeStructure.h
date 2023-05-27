#pragma once


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
#include "domain/query/orgquery/SectorQuery.h"

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
	
	}
	//�����ѯ����֯��Ϣ�ӿڶ˵㴦��
	ENDPOINT(API_M_GET, "/organization-department-tree-structure/root-org-query", rootOrgQuery, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(rootQuery,RootOrgQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRootOrgQuery(rootQuery));
	}

	//�����ѯ��Ч��֯��Ϣ�ӿڶ˵�����
	ENDPOINT_INFO(validOrgQuery) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("org.field.validorg");
		// ���Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON(MemberJsonVO::Wrapper);

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
	MemberJsonVO::Wrapper execRootOrgQuery(const RootOrgQuery::Wrapper& rootQuery);
	//��ѯ��Ч��֯
	MemberJsonVO::Wrapper execValidOrgQuery(const ValidOrgQuery::Wrapper& validOrg);
	//��ѯ����
	OrgSectorVO::Wrapper execSectorOrgQuery(const SectorQuery::Wrapper& sectorOrg);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_ORGNAIZATION_DEPARTMENT_TREE_STRUCTURE_