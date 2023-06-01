#include "stdafx.h"
#include "LegalEntitySetService.h"
#include "dao/LegalEntitySet/LegalEntitySetDAO.h"
#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"
/*
��֯���� ������������ ���� ������������  -- cpt

�����������������б� `LegalEntitySetPullDownList`
����ָ������������Ϣ  `UpdateLegalerSettingMessage`
������������ `LegalEntitySet`
�����������ã�֧������������ `LegalEntitySet`
*/


LegalEntitySetPullDownDTO::Wrapper LegalEntitySetService::legalEntityPulldownList() {
	LegalEntitySetDAO dao;
	std::list<LegalEntitySetDO> date = dao.legalerNamePullDownList();
	auto dto = LegalEntitySetPullDownDTO::createShared();
	for (auto it : date) {
		string str = it.getORMSIGNORGNAME();
		dto->legalEntitySetPullDownList->push_back(LegalEntitySetDTO::createShared(str));
	}
	return dto;
}

uint64_t LegalEntitySetService::insertData(const LegalEntitySetDTO::Wrapper& dto) {
	//ѩ���㷨 ����Ψһ��ʶ
	SnowFlake snowid(1, 2); 
	// ��װDO����
	LegalEntitySetDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ORMSIGNORGNAME, ormsignorgname, CONTRACTSIGNORGNAME, 
	contractsignorgname, ISDEFAULTSIGNORG, isdefaultsignorg)
	data.setORMSIGNORGID(to_string(snowid.nextId()));
	data.setCONTRACTSIGNORGID(to_string(snowid.nextId()));
	// ִ���������
	LegalEntitySetDAO dao;
	dao.insert1(data);
	return dao.insert2(data);
}

bool LegalEntitySetService::updateData(const LegalEntitySetDTO::Wrapper& dto) {
	// ��װDO����
	LegalEntitySetDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ORMSIGNORGNAME, ormsignorgname, CONTRACTSIGNORGNAME,
		contractsignorgname, ISDEFAULTSIGNORG, isdefaultsignorg)
	// ִ�������޸�
	LegalEntitySetDAO dao;
	return dao.update1(data) && dao.update2(data);
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