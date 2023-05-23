#pragma once
#ifndef _LANGUAGE_SERVICE_
#define _LANGUAGE_SERVICE_
#include <list>
#include "domain/query/Language/LanguageQuery.h"
#include "domain/dto/Language/LanguageDTO.h"
#include "domain/dto/ImportLanguage/ImportLanguageDTO.h"

/**
 * ����������ط���ʵ��
 */
class LanguageService 
{
public:
	// ��ҳ��ѯ��������
	LanguagePageDTO::Wrapper listAll(const LanguageQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const LanguageDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const LanguageDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};
#endif // !_LANGUAGE_SERVICE_