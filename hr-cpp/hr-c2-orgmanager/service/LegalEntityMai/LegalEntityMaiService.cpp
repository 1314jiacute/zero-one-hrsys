#include "stdafx.h"
#include "LegalEntityMaiService.h"
#include "dao/LegalEntityMai/LegalEntityMaiDAO.h"

/* ��������ά��Service�����ʵ��--����֯����-��������-��������ά����--TripleGold */
LegalEntityMaiPageDTO::Wrapper LegalEntityMaiService::listAll(const LegalEntityMaiQuery::Wrapper& query)
{
	// �������ض���
	auto pages = LegalEntityMaiPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	LegalEntityMaiDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<OrmsignorgDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (OrmsignorgDO sub : result)
	{
		auto dto = LegalEntityMaiDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ORMSIGNORGID, Id, ORMSIGNORGNAME, Name,ORGCODE, Code);
		/*ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ORMSIGNORGID, ORMSIGNORGID,
			UPDATEMAN, UPDATEMAN, CREATEMAN, CREATEMAN,
			CREATEDATE, CREATEDATE, ORMSIGNORGNAME, ORMSIGNORGNAME,
			UPDATEDATE, UPDATEDATE, ORGCODE, ORGCODE, ZZJC, ZZJC);*/
		pages->addData(dto);
	}
	return pages;
}

bool LegalEntityMaiService::updateData(const LegalEntityMaiDTO::Wrapper& dto)
{
	// ��װDO����
	OrmsignorgDO data;
	/*data.setId(dto->ORMSIGNORGID.getValue(""));
	data.setName(dto->ORMSIGNORGNAME.getValue(""));
	data.setCode(dto->ORGCODE.getValue(""));*/
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, ORMSIGNORGID, Name, ORMSIGNORGNAME, Code, ORGCODE);
	// ִ���������
	LegalEntityMaiDAO dao;
	return dao.update(data) == 1;
}

uint64_t LegalEntityMaiService::saveData(const LegalEntityMaiDTO::Wrapper& dto)
{
	// ��װDO����
	OrmsignorgDO data;
	/*data.setName(dto->ORMSIGNORGNAME.getValue(""));
	data.setCode(dto->ORGCODE.getValue(""));*/
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, ORMSIGNORGID, Name, ORMSIGNORGNAME, Code, ORGCODE);
	// ִ���������
	LegalEntityMaiDAO dao;
	return dao.insert(data);
}

bool LegalEntityMaiService::removeData(string id)
{
	LegalEntityMaiDAO dao;
	return dao.deleteById(id) == 1;
}

//bool LegalEntityMaiService::importFile()
//{
//	return true;
//}
//
//bool LegalEntityMaiService::exportFile()
//{
//	return true;
//}

