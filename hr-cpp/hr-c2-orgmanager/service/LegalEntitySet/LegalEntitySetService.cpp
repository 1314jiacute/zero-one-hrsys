#include "stdafx.h"
#include "LegalEntitySetService.h"
#include "dao/LegalEntitySet/LegalEntitySetDAO.h"

/*
��֯���� ������������ ���� ������������  -- cpt

�����������������б� `LegalEntitySetPullDownList`

����ָ������������Ϣ  `UpdateLegalerSettingMessage`

������������ `LegalEntitySet`

�����������ã�֧������������** `LegalEntitySet`
*/

//LegalEntitySetPageDTO::Wrapper LegalEntitySetService::legalerNamePullDownList(const LegalEntitySetQuery::Wrapper& query)
//{
//	// �������ض���
//	auto pages = LegalEntitySetPageDTO::createShared();
//	pages->pageIndex = query->pageIndex;
//	pages->pageSize = query->pageSize;
//
//	// ��ѯ����������
//	LegalEntitySetDAO dao;
//	uint64_t count = dao.count(query);
//	if (count <= 0) {
//		return pages;
//	}
//
//	// ��ҳ��ѯ����
//	pages->total = count;
//	pages->calcPages();
//	list<LegalEntitySetDO> result = dao.selectWithPage(query);
//	// ��DOת����DTO
//	for (LegalEntitySetDO sub : result)
//	{
//		auto dto = LegalEntitySetDTO::createShared();
//		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ormsignorgid, ORMSIGNORGID, contractsignorgname, CONTRACTSIGNORGNAME, ormsignorgname, ORMSIGNORGNAME, isdefaultsignorg, ISDEFAULTSIGNORG);
//		pages->addData(dto);
//	}
//	return pages;
//}

uint64_t LegalEntitySetService::insertData(const LegalEntitySetDTO::Wrapper& dto)
{
	// ��װDO����
	LegalEntitySetDO data;
	data.setORMSIGNORGID(dto->ormsignorgid.getValue(""));
	data.setORMSIGNORGNAME(dto->ormsignorgname.getValue(""));
	data.setCONTRACTSIGNORGNAME(dto->contractsignorgname.getValue(""));
	data.setISDEFAULTSIGNORG(dto->isdefaultsignorg.getValue(""));
	
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ORMSIGNORGID, ormsignorgid, ORMSIGNORGNAME, ormsignorgname,
		CONTRACTSIGNORGNAME, contractsignorgname)
	
	// ִ���������
	LegalEntitySetDAO dao;
	dao.insert1(data);
	return dao.insert2(data);
}

bool LegalEntitySetService::updateData(const LegalEntitySetDTO::Wrapper& dto)
{
	// ��װDO����
	LegalEntitySetDO data;
	/*data.setORMSIGNORGID(dto->ormsignorgid.getValue(""));
	data.setORMSIGNORGNAME(dto->ormsignorgname.getValue(""));
	data.setCONTRACTSIGNORGNAME(dto->contractsignorgname.getValue(""));
	data.setISDEFAULTSIGNORG(dto->isdefaultsignorg.getValue(1));;*/
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ORMSIGNORGID, ormsignorgid, ORMSIGNORGNAME, ormsignorgname, CONTRACTSIGNORGNAME, contractsignorgname)
	// ִ�������޸�
	LegalEntitySetDAO dao;
	return dao.update(data) == 1;
}

// ɾ������ 
//bool LegalEntitySetService::removeData(uint64_t id)
//{
//	LegalEntitySetDAO dao;
//	return dao.deleteById(id) == 1;
//}


/* ----------------------------------��������ά��Service�����ʵ��--����֯����-��������-��������ά����--TripleGold ------------------------------------------------*/
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
	list<LegalEntitySetDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (LegalEntitySetDO sub : result)
	{
		auto dto = LegalEntitySetDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ormsignorgid, ORMSIGNORGID, contractsignorgname, CONTRACTSIGNORGNAME, ormsignorgname, ORMSIGNORGNAME, isdefaultsignorg, ISDEFAULTSIGNORG);
		pages->addData(dto);
	}
	return pages;
}