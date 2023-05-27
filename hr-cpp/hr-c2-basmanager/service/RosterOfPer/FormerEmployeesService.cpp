#include "stdafx.h"
#include "FormerEmployeesService.h"
#include "../../dao/RosterOfPer/FormerEmployeesDAO.h"
FormerEmployeesPageDTO::Wrapper FormerEmployeesService::listAll(const FormerEmployeesQuery::Wrapper& query)
{
	// �������ض���
	auto pages = FormerEmployeesPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	FormerEmployeesDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<FormerEmployeesDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (FormerEmployeesDO sub : result)
	{
		auto dto = FormerEmployeesDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, ygbh, name, pimPersonName, 
			sex, sex, phoneNumber, lxdh, chushengriqi, csrq,
			organization, organizationName, department, bm, rank, rank,
			mail_address, postalAddress, family_contact, jtlxr, family_contact_number, jtlxrdh);
		pages->addData(dto);

	}
	return pages;
}