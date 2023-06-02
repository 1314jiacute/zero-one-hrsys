#pragma once
#ifndef _LEGALENTITYSETSERVICE_SERVICE_
#define _LEGALENTITYSETSERVICE_SERVICE_
#include "domain/dto/LegalEntitySet/ImportLeagalPerSettingDTO.h"
#include <list>
#include "domain/vo/LegalEntitySet/LegalEntitySetVO.h"
#include "domain/dto/LegalEntitySet/LegalEntitySetDTO.h"
#include "domain/query/LegalEntitySet/LegalEntitySetQuery.h"
#include "domain/do/LegalEntitySet/LegalEntitySetDO.h"
//#include "domain/dto/LegalEntitySet/LegalEntitySetQueryDTO.h"
/*
��֯���� ������������ ���� ������������  -- cpt

�����������������б� `LegalEntitySetPullDownList`

����ָ������������Ϣ  `UpdateLegalerSettingMessage`

������������ `LegalEntitySet`

�����������ã�֧������������** `LegalEntitySet`
*/
class LegalEntitySetService
{
public:
	// ��ҳ��ѯ��������
	LegalEntitySetQueryPageDTO::Wrapper listAll(const LegalEntitySetQuery::Wrapper& query);
	// ��������
	uint64_t insertData(const LegalEntitySetDTO::Wrapper& dto, const PayloadDTO& payload);
	// �޸�����
	bool updateData(const LegalEntitySetDTO::Wrapper& dto );
	// ͨ��IDɾ������
	//bool removeData(uint64_t id);
	LegalEntitySetPullDownDTO::Wrapper legalEntityPulldownList();
};
#endif // !_LEGALENTITYSETSERVICE_SERVICE_