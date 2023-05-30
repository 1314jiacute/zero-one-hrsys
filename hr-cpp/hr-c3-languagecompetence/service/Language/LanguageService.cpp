#include "stdafx.h"
#include "LanguageService.h"
#include "../../domain/do/Language/LanguageDO.h"
#include "../../dao/Language/LanguageDAO.h"

/**
 * ��������service��ʵ��
 * �����ˣ���
 */
LanguagePageDTO::Wrapper LanguageService::listAll(const LanguagePageQuery::Wrapper& query)
{
	//�������ض���
	auto pages = LanguagePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	//��ѯ����������
	LanguageDAO dao;
	uint64_t count = dao.countPage(query);
	if (count <= 0)
	{
		return pages;
	}

	//��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<LanguageDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (LanguageDO sub : result)
	{
		auto dto = LanguageDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, languageAbilityID, LanguageAbilityID, permission, Permission,
			gainTime, GainTime, attachment, Attachment, languageType, LanguageType, createMan, CreateMan,
			updateMan, UpdateMan, languageLevel, LanguageLevel, personID, PersonID, jlss, JLSS,
			jlglbh, JLGLBH, jlspzt, JLSPZT, jlczz, JLCZZ);
		pages->addData(dto);
	}
	return pages;
}

LanguageDTO::Wrapper LanguageService::queryOneDataById(const LanguageQuery::Wrapper& query)
{
	//�������ض���
	auto data = LanguageDTO::createShared();
	//��ѯ����������
	LanguageDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return data;
	}

	//��ȡ��ѯ����
	list<LanguageDO> result = dao.selectOneById(query->personID);
	//��DOת����DTO
	//list������
	std::list<LanguageDO>::iterator it = result.begin();
	LanguageDO sub = *it;
	ZO_STAR_DOMAIN_DO_TO_DTO(data, sub, languageAbilityID, LanguageAbilityID, permission, Permission,
		gainTime, GainTime, attachment, Attachment, languageType, LanguageType, createMan, CreateMan,
		updateMan, UpdateMan, languageLevel, LanguageLevel, personID, PersonID, jlss, JLSS,
		jlglbh, JLGLBH, jlspzt, JLSPZT, jlczz, JLCZZ);
	return data;
}

int LanguageService::saveData(const LanguageDTO::Wrapper& dto)
{
	//��װDO����
	LanguageDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, GainTime, gainTime, Attachment, attachment, LanguageType, languageType,
		CreateMan, createMan, LanguageLevel, languageLevel, PersonID, personID);

	// ִ���������
	LanguageDAO dao;
	return dao.insert(data);
}

bool LanguageService::updateData(const LanguageDTO::Wrapper& dto)
{
	//��װDO����
	LanguageDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Permission, permission, GainTime, gainTime, Attachment, attachment,
		LanguageType, languageType, UpdateMan, updateMan, LanguageLevel, languageLevel);

	//ִ�������޸�
	LanguageDAO dao;
	return dao.update(data) == 1;
}

bool LanguageService::removeData(string id, string languageType)
{
	//��װDO����
	LanguageDO data;
	//ִ������ɾ��
	LanguageDAO dao;
	return dao.deleteById(id,languageType);
}
