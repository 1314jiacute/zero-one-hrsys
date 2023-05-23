#include "stdafx.h"
#include "TemporaryStaffService.h"
#include "../../dao/RosterOfPer/TemporaryStaffDAO.h"
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
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, empStatus, 
			EmpStatus,tempStatus, TempStatus, tempOrg, TempOrg, 
			tempDept, TempDept, tempStartTime, TempStartTime,tempEndTime, TempEndTime);
		pages->addData(dto);

	}
	return pages;
}
