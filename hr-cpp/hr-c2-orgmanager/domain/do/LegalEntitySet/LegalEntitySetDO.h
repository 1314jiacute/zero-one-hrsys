#pragma once
/*
��֯���� ������������ ���� ������������  -- cpt

�����������������б� `LegalEntitySetPullDownList`

����ָ������������Ϣ  `UpdateLegalerSettingMessage`

������������ `LegalEntitySet`

�����������ã�֧������������** `LegalEntitySet`
*/

#ifndef _LEGALENTITYSET_DO_
#define _LEGALENTITYSET_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class LegalEntitySetDO {
	public:
	// ������������   �� �� t_ormsignorg 
	CC_SYNTHESIZE(string, ormsignorgname, ORMSIGNORGNAME);
	// ǩԼ���嵥λ���� t_contractsignorg
	CC_SYNTHESIZE(string, contractsignorgname, CONTRACTSIGNORGNAME);
	// Ĭ��ǩԼ����  t_contractsignorg
	CC_SYNTHESIZE(int, isdefaultsignorg, ISDEFAULTSIGNORG);
	LegalEntitySetDO() {
	}
	LegalEntitySetDO(string ormsignorgname, string contractsignorgname, int isdefaultsignorg) {
		this->ormsignorgname = ormsignorgname;
		this->contractsignorgname = contractsignorgname;
		this->isdefaultsignorg = isdefaultsignorg;
	}
};
#endif // !_LEGALENTITYSET_DO_
