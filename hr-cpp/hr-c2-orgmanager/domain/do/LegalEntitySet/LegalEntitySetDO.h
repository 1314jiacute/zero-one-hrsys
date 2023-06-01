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
	// ���������ʶ
	CC_SYNTHESIZE(string, ormsignorgid, ORMSIGNORGID);
	// ������������   �� �� t_ormsignorg 
	CC_SYNTHESIZE(string, ormsignorgname, ORMSIGNORGNAME);
	// ǩԼ���嵥λ���� t_contractsignorg
	CC_SYNTHESIZE(string, contractsignorgname, CONTRACTSIGNORGNAME);
	// Ĭ��ǩԼ����  t_contractsignorg
	CC_SYNTHESIZE(string, isdefaultsignorg, ISDEFAULTSIGNORG);
	LegalEntitySetDO() {
		ormsignorgid = "";
		ormsignorgname = "";
		contractsignorgname = "";
		isdefaultsignorg = "";
	};
	LegalEntitySetDO(std::vector<std::string> vec) {
		int i = 0;
		setORMSIGNORGNAME(vec[i++]);
		setCONTRACTSIGNORGNAME(vec[i++]);
		setISDEFAULTSIGNORG(vec[i++]);
	}
	LegalEntitySetDO(string ormsignorgid, string ormsignorgname, string contractsignorgname, string isdefaultsignorg) {
		this->ormsignorgid = ormsignorgid;
		this->ormsignorgname = ormsignorgname;
		this->contractsignorgname = contractsignorgname;
		this->isdefaultsignorg = isdefaultsignorg;
	}
};
#endif // !_LEGALENTITYSET_DO_
