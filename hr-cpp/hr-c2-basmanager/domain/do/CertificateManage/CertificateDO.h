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

//�����ļ�ͬ����������ͻ����ʱ�ϲ���һ����
class CertificateDO
{
/**
 * ��ְԱ�����ݿ�ʵ����--pine
 */
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(string, age, Age);
	// ��֯
	CC_SYNTHESIZE(string, organization, Organization);
	// ����
	CC_SYNTHESIZE(string, department, Department);
	// ְ��
	CC_SYNTHESIZE(string, rank, Rank);
	// ͨѶ��ַ
	CC_SYNTHESIZE(string, mail_address, Mail_address);
	// ��ͥ��ϵ��
	CC_SYNTHESIZE(string, family_contact, Family_contact);
	// ��ͥ��ϵ�˵绰
	CC_SYNTHESIZE(string, family_contact_number, Family_contact_nuimber);
/**
 * ֤��������ݿ�ʵ����
 */
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
	CertificateDO() {
		id = 0;
		name = "";
		sex = "";
		age = -1;
		organization = "";
		department = "";
		rank = "";
		mail_address = "";
		family_contact = "";
		family_contact_number = "";
	}
};

#endif // !_FPRMERRMPLOYEES_DO_