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

uint64_t LegalEntitySetService::saveData(const LegalEntitySetDTO::Wrapper& dto)
{
	// ��װDO����
	LegalEntitySetDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ORMSIGNORGID, ormsignorgid, ORMSIGNORGNAME, ormsignorgname, CONTRACTSIGNORGNAME, contractsignorgname)
		// ִ���������
		LegalEntitySetDAO dao;
	return dao.insert(data);
}

bool LegalEntitySetService::updateData(const LegalEntitySetDTO::Wrapper& dto)
{
	// ��װDO����
	LegalEntitySetDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
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
