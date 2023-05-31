#pragma once
#ifndef _LEGALENTITYSETSERVICE_SERVICE_
#define _LEGALENTITYSETSERVICE_SERVICE_
#include "domain/dto/LegalEntitySet/ImportLeagalPerSettingDTO.h"
#include <list>
#include "domain/vo/LegalEntitySet/LegalEntitySetVO.h"
#include "domain/dto/LegalEntitySet/LegalEntitySetDTO.h"
#include "domain/query/LegalEntitySet/LegalEntitySetQuery.h"
#include "domain/do/LegalEntitySet/LegalEntitySetDO.h"
/*
��֯���� ������������ ���� ������������  -- cpt

�����������������б� `LegalEntitySetPullDownList`

����ָ������������Ϣ  `UpdateLegalerSettingMessage`

������������ `LegalEntitySet`

�����������ã�֧������������** `LegalEntitySet`
*/
/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class LegalEntitySetService
{
public:
	// ��ҳ��ѯ��������
	LegalEntitySetPageDTO::Wrapper listAll(const LegalEntitySetQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const LegalEntitySetDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const LegalEntitySetDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};


#endif // !_LEGALENTITYSETSERVICE_SERVICE_