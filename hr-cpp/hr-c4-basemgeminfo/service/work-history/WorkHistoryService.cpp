#include "stdafx.h"
#include "WorkHistoryService.h"
#include "dao/work-history/WorkHistoryDAO.h"

WorkHistoryDTO::Wrapper WorkHistoryService::listDetail(const WorkHistoryQuery::Wrapper& query)
{
	// �������ض���
	//auto lists = MilitaryDTO::createShared();
	WorkHistoryDAO dao;
	auto lists = dao.selectDetail(query);
	auto dto = WorkHistoryDTO::createShared();
	if (!lists.empty()) {
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, lists.front(), rzkssj, Rzkssj,
			rzjssj, Rzjssj, 
			ormorgname, Ormorgname, 
			ormdutyname, Ormdutyname, 
			ormpostname, Ormpostname, 
			cfplx, Cfplx, enable,Enable);
	}
	return dto;
}

bool WorkHistoryService::updateData(const WorkHistoryDTO::Wrapper& dto)
{
	// ��װDO����
	WorkHistoryDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Rzkssj, rzkssj, Rzjssj, rzjssj, Ormorgname, ormorgname, Ormdutyname, ormdutyname, Ormpostname, ormpostname, Cfplx, cfplx, Enable, enable);
	// ִ�������޸�
	WorkHistoryDAO dao;
	return dao.update(data) == 1;
}


WorkHistoryFindPageDTO::Wrapper WorkHistoryService::listAll(const WorkHistoryPageQuery::Wrapper& query)
{
	// �������ض���
	auto pages = WorkHistoryFindPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	WorkHistoryDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<WorkHistoryFindDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (WorkHistoryFindDO sub : result)
	{
		auto dto = WorkHistoryFindDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, rzkssj, rZKSSJ, 
			rzjssj, rZJSSJ, 
			ormorgname, oRMORGNAME, 
			ormorgsectorname, oRMORGSECTORNAME, 
			ormdutyname, oRMDUTYNAME, 
			ormpostname, oRMPOSTNAME, 
			cfplx, cFPLX, 
			experience, eXPERIENCE, 
			pimworkhistoryid, pIMWORKHISTORYID, 
			pimpersonid, pIMPERSONID);
		pages->addData(dto);

	}
	return pages;
}
