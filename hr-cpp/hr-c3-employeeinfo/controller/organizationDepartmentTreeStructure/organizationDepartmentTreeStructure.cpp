#include "stdafx.h"
#include "organizationDepartmentTreeStructure.h"

//��ѯ���в��Žṹ��
MemberJsonVO::Wrapper organizationDepartmentTreeStructure::execRootOrgQuery(const RootOrgQuery::Wrapper& rootQuery)
{
	// ����һ��MemberJsonVO����
	auto vo = MemberJsonVO::createShared();
	return vo;
}
//��ѯ��Ч��֯
MemberJsonVO::Wrapper organizationDepartmentTreeStructure::execValidOrgQuery(const ValidOrgQuery::Wrapper& validOrg)
{
	// ����һ��MemberJsonVO����
	auto vo = MemberJsonVO::createShared();
	return vo;
}
//��ѯ����
OrgSectorVO::Wrapper organizationDepartmentTreeStructure::execSectorOrgQuery(const SectorQuery::Wrapper& sectorOrg)
{
	// ����һ��OrgSectorVO����
	auto vo = OrgSectorVO::createShared();
	return vo;
}




