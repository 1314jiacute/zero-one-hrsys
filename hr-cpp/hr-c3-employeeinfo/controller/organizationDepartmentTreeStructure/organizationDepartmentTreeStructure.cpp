#include "stdafx.h"
#include "organizationDepartmentTreeStructure.h"

// ��ѯ����֯
OrgJsonVO::Wrapper organizationDepartmentTreeStructure::execRootOrgQuery(const RootOrgQuery::Wrapper& rootQuery, const std::shared_ptr<CustomerAuthorizeObject> &authObject)
{
	// ����һ��MemberJsonVO����
	auto jvo = OrgJsonVO::createShared();

	OrgService service;
	auto result = service.getRootOrg(rootQuery, authObject->getPayload().getId());
	jvo->success(result);
	return jvo;
}
//��ѯ��Ч��֯
OrgJsonVO::Wrapper organizationDepartmentTreeStructure::execValidOrgQuery(const ValidOrgQuery::Wrapper& validOrg)
{
	auto jvo = OrgJsonVO::createShared();

	OrgService service;
	auto result = service.getValidOrg(validOrg);
	jvo->success(result);
	return jvo;
}
//��ѯ����
OrgSectorVO::Wrapper organizationDepartmentTreeStructure::execSectorOrgQuery(const SectorQuery::Wrapper& sectorOrg)
{
	auto jvo = OrgSectorVO::createShared();

	OrgService service;
	auto result = service.getSector(sectorOrg);
	jvo->success(result);
	return jvo;
}