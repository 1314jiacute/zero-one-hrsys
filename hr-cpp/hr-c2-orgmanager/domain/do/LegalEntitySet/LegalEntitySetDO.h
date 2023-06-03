#pragma once

/*
*��	�������á��������������� ����  cpt

�����������������б� `LegalerNamePullDownList`

����ָ������������Ϣ  `UpdateLegalerSettingMessage`

������������ `ExportLegalerSeting`

�����������ã�֧������������** `AddLegalerSeting`
*/

#ifndef _LEGALENTITYSET_DO_
#define _LEGALENTITYSET_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class LegalEntitySetDO {
	//���������ʶ
	CC_SYNTHESIZE(string, ormsignorgid, ORMSIGNORGID);
	// ������������   �� �� t_ormsignorg 
	CC_SYNTHESIZE(string, ormsignorgname, ORMSIGNORGNAME);
	// ǩԼ���嵥λ���� t_contractsignorg
	CC_SYNTHESIZE(string, contractsignorgname, CONTRACTSIGNORGNAME);
	// Ĭ��ǩԼ����  t_contractsignorg
	CC_SYNTHESIZE(int, isdefaultsignorg, ISDEFAULTSIGNORG);


public:
	LegalEntitySetDO() {
	}
	LegalEntitySetDO(string ormsignorgid, string ormsignorgname, string contractsignorgname, int isdefaultsignorg) {
		this->ormsignorgid = ormsignorgid;
		this->ormsignorgname = ormsignorgname;
		this->contractsignorgname = contractsignorgname;
		this->isdefaultsignorg = isdefaultsignorg;
	}
};
#endif // !_LEGALENTITYSET_DO_