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
#ifndef _SECONDED_PERSONNEL_DO_
#define _SECONDED_PERSONNEL_DO_
#include "../DoInclude.h"

/*
 ������Ա��DO--����Ա�����ᣩ--pine
 (��Ӧ���ݿ��t_pcmydjdmx���춯�����ϸ �� t_pcmydmx���춯��ϸ)
 */
class SecondedPersonnelDO
{
	// Ա�����
	CC_SYNTHESIZE(uint64_t, ygbh, ygbh);
	// Ա������
	CC_SYNTHESIZE(string, pimPersonName, pimPersonName);
	// ԭ��֯
	CC_SYNTHESIZE(string, zz, zz);
	// ԭ����
	CC_SYNTHESIZE(string, bm, bm);
	// ԭְ��
	CC_SYNTHESIZE(string, yzw, yzw);
	// ԭ��λ
	CC_SYNTHESIZE(string, ygw, ygw);
	// ����֯
	CC_SYNTHESIZE(string, ormOrgId, ormOrgId);
	// �²���
	CC_SYNTHESIZE(string, ormOrgSectorId, ormOrgSectorId);
	// ��ְ��
	CC_SYNTHESIZE(string, ormDutyId, ormDutyId);
	// �¸�λ
	CC_SYNTHESIZE(string, ormPostId, ormPostId);
	// ���״̬���춯�����ϸ��ʶ��
	CC_SYNTHESIZE(string, pcmydjdmxId, pcmydjdmxid);
	//�����ʼʱ��
	CC_SYNTHESIZE(string, jdksrq, jdksrq);
	//�������ʱ��
	CC_SYNTHESIZE(string, jdjsrq, jdjsrq);

public:
	SecondedPersonnelDO() {
		ygbh = "0";
		pimPersonName = "";
		zz = "";
		bm = "";
		yzw = "";
		ygw = "";
		ormOrgId = "";
		ormOrgSectorId = "";
		ormDutyId = "";
		ormPostId = "";
		pcmydjdmxId = "";
		jdksrq = "";
		jdjsrq = "";
	}
};

#endif // !_SAMPLE_DO_
