#pragma once
#ifndef _CERTIFICATEDO_H_
#define _CERTIFICATEDO_H_

#include "../DoInclude.h"
/**
 * ��λ����֤����Ϣʵ��
 */
class CertificateDO
{
	// �����
	CC_SYNTHESIZE(string, seialno, seialNo);
	// ��λ����֤��
	CC_SYNTHESIZE(string, pimqualtypename, pimQualTypeName);
public:
	CertificateDO() 
	{
		seialno = "";
		pimqualtypename = "";
	}
	//�ֱ�Ϊ����ţ���λ����֤��
	CertificateDO(string seialno, string pimqualtypename)
	{
		this->seialno = seialno;
		this->pimqualtypename = pimqualtypename;
	}
};

#endif