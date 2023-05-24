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
#ifndef _COMMONROSTEROFPER_DO_
#define _COMMONROSTEROFPER_DO_
#include "../DoInclude.h"

/**
 * ��Ա�����ṫ��DO--(��Ա������)--luoluo
 */
class CommonRosterOfPerDO
{
	// ��ְ��ϢID���������������������
	CC_SYNTHESIZE(uint64_t, leavingAnalysis_ID, leavingAnalysis_ID);
	// Ա��������Ϣ��ID,ͬԱ��ID
	CC_SYNTHESIZE(uint64_t, pimperSonName, pimperSonName);
	//Ա������
	CC_SYNTHESIZE(string, name, name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, sex);
	// ����
	CC_SYNTHESIZE(string, nj, nj);
	//Ա����š�����
	CC_SYNTHESIZE(string, ygbh, ygbh);
	// ��֯
	CC_SYNTHESIZE(string, organizationName, organizationName);
	// ����
	CC_SYNTHESIZE(string, bm, bm);
	// ְ��
	CC_SYNTHESIZE(string, rank, rank);
	// ��λ
	CC_SYNTHESIZE(string, gw, gw);
	//�ֻ�����
	CC_SYNTHESIZE(string, lxdh, lxdh);
	// ��ͥ��ϵ��
	CC_SYNTHESIZE(string, jtlxr, jtlxr);
	// ��ͥ��ϵ�˵绰
	CC_SYNTHESIZE(string, jtlxrdh, jtlxrdh);
	
public:
	CommonRosterOfPerDO() {
		
	}
};

#endif // !_COMMONROSTEROFPER_DO_
