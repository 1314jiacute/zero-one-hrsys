#include "stdafx.h"
#include "LanguageService.h"
#include "../../domain/do/Language/LanguageDO.h"

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




	return pages;
}

LanguageDTO::Wrapper LanguageService::queryOneData(const LanguageQuery::Wrapper& query)
{
	//�������ض���
	auto data = LanguageDTO::createShared();




	return data;
}

uint64_t LanguageService::saveData(const LanguageDTO::Wrapper& dto)
{
	//��װDO����
	LanguageDO data;


	return 1;
}

bool LanguageService::updateData(const LanguageDTO::Wrapper& dto)
{
	//��װDO����
	LanguageDO data;


	return true;
}

bool LanguageService::removeData(string id, string languageType)
{
	//��װDO����
	LanguageDO data;


	return true;
}
