#include "stdafx.h"
#include "FamilysituationService.h"
#include "SnowFlake.h"
#include "../../dao/Familysituation/FamilysituationDAO.h"

// ��ҳ��ѯ��������
FamilysituationPageDTO::Wrapper FamilysituationService::listAll(const FamilysituationQuery::Wrapper& query)
{
	// �������ض���
	auto pages = FamilysituationPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	FamilysituationDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<FamilysituationDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (FamilysituationDO sub : result)
	{
		auto dto = FamilysituationDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, frelationship, Relationship, doctype, Doctype, \
			identification, Identification, gender, Gender, dob, Dob, age, Age, workplace, Workplace, job, Job, \
			politicalstatus, Politicalstatus, testament, Testament, ice, Ice);
			pages->addData(dto);
	}
	return pages;
}

FamilysituationDTO::Wrapper FamilysituationService::getOne(const FamilysituationQuery::Wrapper& query)
{
	// �������ض���
	auto data = FamilysituationDTO::createShared();

	// ��ѯ����������
	FamilysituationDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return data;
	}

	// ָ����ѯ����
	list<FamilysituationDO> result = dao.selectWithOne(query);
	// ��DOת����DTO
	for (FamilysituationDO sub : result)
	{
		ZO_STAR_DOMAIN_DO_TO_DTO(data, sub, name, Name, frelationship, Relationship, doctype, Doctype, \
			identification, Identification, gender, Gender, dob, Dob, age, Age, workplace, Workplace, job, Job, \
			politicalstatus, Politicalstatus, testament, Testament, ice, Ice);
	}
	return data;
}

uint64_t FamilysituationService::saveData(const FamilysituationDTO::Wrapper& dto)
{
	// ѩ���㷨����id
	SnowFlake c3(1, 3);
	dto->id = to_string(c3.nextId());
	// ��װDO����
	FamilysituationDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonId, personid, Id, id, Name, name, Relationship, frelationship, Doctype, doctype, \
		Identification, identification, Gender, gender, Dob, dob, Age, age, Workplace, workplace, Job, job, \
		Politicalstatus, politicalstatus, Testament, testament, Ice, ice);
	// ִ���������
	FamilysituationDAO dao;
	return dao.insert(data);
}

bool FamilysituationService::updateData(const FamilysituationDTO::Wrapper& dto)
{
	// ��װDO����
	FamilysituationDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonId, personid, Id, id, Name, name, Relationship, frelationship, Doctype, doctype, \
		Identification, identification, Gender, gender, Dob, dob, Age, age, Workplace, workplace, Job, job, \
		Politicalstatus, politicalstatus, Testament, testament, Ice, ice);
	// ִ�������޸�
	FamilysituationDAO dao;
	return dao.update(data) == 1;
}

bool FamilysituationService::removeData(const FamilysituationDTO::Wrapper& dto)
{
	// ��װDO����
	FamilysituationDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonId, personid, Id, id);
	FamilysituationDAO dao;
	return dao.deleteById(data) == 1;
}
