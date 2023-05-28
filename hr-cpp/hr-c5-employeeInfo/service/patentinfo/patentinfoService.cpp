
#include "stdafx.h"
#include "patentinfoService.h"
#include "../../dao/patentinfo/t_pimpatentDAO.h"

PatentinfoPageDTO::Wrapper PaperinfoService::listAll(const PatentinfoQuery::Wrapper& query)
{
	// �������ض���
	auto pages = PatentinfoPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	t_pimpatentDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<PatentinfoDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (PatentinfoDO sub : result)
	{
		auto dto = PatentinfoDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, zlh, ZLH, pimpatentname, PIMPATENTNAME, zlhqsj, ZLHQSJ
			, pimpatentname, PIMPATENTNAME, enclolure, ENCLOLURE)
		pages->addData(dto);
	}
	return pages;
}

uint64_t PaperinfoService::saveData(const PatentinfoDTO::Wrapper& dto)
{
	// ��װDO����
	PatentinfoDTO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, zlh, ZLH, pimpatentname, PIMPATENTNAME, zlhqsj, ZLHQSJ
		, pimpatentname, PIMPATENTNAME, enclolure, ENCLOLURE)
		// ִ���������
		t_pimpatentDAO dao;
	return dao.insert(data);
}

bool PaperinfoService::removeData(string pimpaperid)
{
	t_pimpatentDAO dao;
	return dao.deleteById(pimpaperid) == 1;
}