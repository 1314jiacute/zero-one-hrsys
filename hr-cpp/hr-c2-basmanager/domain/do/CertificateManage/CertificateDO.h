#pragma once
//֤��������ݿ�ʵ����

#ifndef _CERTIFICATE_DO_
#define _CERTIFICATE_DO_
#include "../DoInclude.h"

/**
 * ֤��������ݿ�ʵ����
 */
class CertificateDO 
{
	// Ա��������Ϣ��ID,ͬԱ��ID
	CC_SYNTHESIZE(uint64_t, ygbh, ygbh);
	// ����
	CC_SYNTHESIZE(string, pimperSonName, pimperSonName);
	// Ա��״̬ 
	CC_SYNTHESIZE(string, ygzt, ygzt);
	// ��֯   t_srforg ��Ҫ���������ȡ��֯����
	CC_SYNTHESIZE(string, organizationName, organizationName);
	// ֤����
	CC_SYNTHESIZE(string, zgzsbh, zgzsbh);
	// һ������B֤���
	CC_SYNTHESIZE(string, bcardNumber, bcardNumber);
	// ֤������
	CC_SYNTHESIZE(string, pimVocationalName, pimVocationalName);
	// ֤������
	CC_SYNTHESIZE(string, zslx, zslx);
	// ǩ������
	CC_SYNTHESIZE(string, zghqrq, zghqrq);
	// ǩ������
	CC_SYNTHESIZE(string, zgsydw, zgsydw);
	// ע�ᵥλ
	CC_SYNTHESIZE(string, zcdw, zcdw);
	// ��֤��Ч��
	CC_SYNTHESIZE(string, fzyxq, fzyxq);
	// ʧЧ����
	CC_SYNTHESIZE(string, sxrq, sxrq);
	// ֤��ʣ������ ����û��
	//////////////////////////////////////////////////////////////
	// ����Ϊ��ǰ����ʾ�ֶ�
	// ��Ա��Ϣ��ʶ FOREIGN KEY (`PIMPERSONID`) REFERENCES `t_pimperson` (`PIMPERSONID`),
	CC_SYNTHESIZE(string, pimPersonID, pimPersonID);
	// ��֯��ʶ FOREIGN KEY (`ORMORGID`) REFERENCES `t_srforg` (`ORGID`),
	CC_SYNTHESIZE(string, ORMORGID, ORMORGID);
public:
	CertificateDO() {	}
};

#endif 