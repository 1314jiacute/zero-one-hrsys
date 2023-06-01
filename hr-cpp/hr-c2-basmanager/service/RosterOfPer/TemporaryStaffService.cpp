#include "stdafx.h"
#include "TemporaryStaffService.h"
#include "../../dao/RosterOfPer/TemporaryStaffDAO.h"
/**
* ��ְ��Աservice--(��Ա������-��ְ��Ա-��ҳ��ѯԱ���б�)--weixiaoman
*/
TemporaryStaffPageDTO::Wrapper TemporaryStaffService::listAll(const TempStaffQuery::Wrapper& query)
{
	// �������ض���
	auto pages = TemporaryStaffPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	TemporaryStaffDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<TemporaryStaffDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (TemporaryStaffDO sub : result)
	{
		auto dto = TemporaryStaffDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, ygbh, name, pimPersonName, empStatus,
			ygzt,tempStatus, gzzt, tempOrg, gzzz,
			tempDept, gzbm, tempStartTime, gzkssj,tempEndTime, gzjssj);
		pages->addData(dto);

	}
	return pages;
}
