#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _CERTIFICATE_DO_
#define _CERTIFICATE_DO_
#include "../DoInclude.h"

class CertificateDO
{
	/**
	 * ֤��������ݿ�ʵ����
	 */
	 // Ա��������Ϣ��ID,ͬԱ��ID
	CC_SYNTHESIZE(uint64_t, ygbh, Ygbh);
	// ֤������Ա������ģ�����ң�
	CC_SYNTHESIZE(string, nameOfPAndV, NameOfPAndV);
	// ����
	CC_SYNTHESIZE(string, pimperSonName, PimperSonName);
	// Ա��״̬ 
	CC_SYNTHESIZE(string, ygzt, Ygzt);
	// ��֯   t_srforg ��Ҫ���������ȡ��֯����
	CC_SYNTHESIZE(string, zz, ZZ);
	// ֤����
	CC_SYNTHESIZE(string, pimvocationalid, Pimvocationalid);
	// һ������B֤���
	CC_SYNTHESIZE(string, bcardNumber, BcardNumber);
	// ֤������
	CC_SYNTHESIZE(string, pimVocationalName, PimVocationalName);
	// ֤������
	CC_SYNTHESIZE(string, zslx, Zslx);
	// ǩ������
	CC_SYNTHESIZE(string, zghqrq, Zghqrq);
	// ǩ������
	CC_SYNTHESIZE(string, zgsydw, Zgsydw);
	// ע�ᵥλ
	CC_SYNTHESIZE(string, zcdw, Zcdw);
	// ��֤��Ч��
	CC_SYNTHESIZE(string, fzyxq, Fzyxq);
	// ʧЧ����
	CC_SYNTHESIZE(string, sxrq, Sxrq);
	/*�½�֤�����������ֶ�*/
	//�������
	CC_SYNTHESIZE(string, nsqk, NSQK);
	// ʹ�����
	CC_SYNTHESIZE(string, syqk, SYQK);
	// ������
	CC_SYNTHESIZE(string, alteration, ALTERATION);

	// ֤��ʣ������ ����û��
	//////////////////////////////////////////////////////////////
	// ����Ϊ��ǰ����ʾ�ֶ�
	// ��Ա��Ϣ��ʶ FOREIGN KEY (`PIMPERSONID`) REFERENCES `t_pimperson` (`PIMPERSONID`),
	CC_SYNTHESIZE(string, pimPersonID, pimPersonID);
	// ��֯��ʶ FOREIGN KEY (`ORMORGID`) REFERENCES `t_srforg` (`ORGID`),
	CC_SYNTHESIZE(string, ORMORGID, ORMORGID);


public:
	CertificateDO() {
		ygbh = 0;
		nameOfPAndV = "";
		pimperSonName = "";
		ygzt = "";
		zz = "";
		pimvocationalid = "";
		bcardNumber = "";
		pimVocationalName = "";
		zslx = "";
		zghqrq = "";
		zgsydw = "";
		zcdw = "";
		fzyxq = "";
		sxrq = "";
	}
};

#endif // !_FPRMERRMPLOYEES_DO_