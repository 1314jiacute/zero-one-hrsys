#include "stdafx.h"
#include "LegalEntitySetService.h"
#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"
#include "dao/LegalEntitySet/LegalEntitySetDAO.h"

/* ��������ά��Service�����ʵ��--����֯����-��������-��������ά����--TripleGold */
LegalEntitySetPageDTO::Wrapper LegalEntitySetService::listAll(const LegalEntitySetQuery::Wrapper& query)
{
	// �������ض���
	auto pages = LegalEntitySetPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	LegalEntitySetDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<QueryLegalEntitySetDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (QueryLegalEntitySetDO sub : result)
	{
		auto dto = LegalEntitySetQueryDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, CONTRACTSIGNORGID, Id, ORGNAME, OrgName, ORMSIGNORGNAME, LEMName, ISDEFAULTSIGNORG, Defa);
		pages->addData(dto);
	}
	return pages;
}
