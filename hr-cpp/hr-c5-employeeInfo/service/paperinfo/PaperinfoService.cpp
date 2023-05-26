
#include "stdafx.h"
#include "PaperinfoService.h"
#include "../../dao/paperinfo/t_pimpaperDAO.h"

PaperDTO::Wrapper PaperinfoService::listAll(const PaperQuery::Wrapper& query)
{
	// �������ض���
	auto pages = PaperPageDTO::createShared(); 
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	t_pimpaperDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<t_pimpaperDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (t_pimpaperDO sub : result)
	{
		auto dto = PaperDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, fbsj, Fbsj, cbs, Cbs, kwqs, Kwqs,
			fj, Fj, grzlwzzzdpm, Grzlwzzzdpm, kwmc, Kwmc, pimpapername, Pimpapername);
			pages->addData(dto);
	}
	return pages;
}

uint64_t PaperinfoService::saveData(const PaperDTO::Wrapper& dto)
{
	// ��װDO����
	t_pimpaperDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Fbsj, fbsj, Cbs, cbs, Kwqs, kwqs,
		Fj, fj, Grzlwzzzdpm, grzlwzzzdpm, Kwmc, kwmc, Pimpapername, pimpapername)
	// ִ���������
	t_pimpaperDAO dao;
	return dao.insert(data);
}

bool PaperinfoService::updateData(const PaperDTO::Wrapper& dto)
{
	return false;
}

bool PaperinfoService::removeData(uint64_t id)
{
	return false;
}
