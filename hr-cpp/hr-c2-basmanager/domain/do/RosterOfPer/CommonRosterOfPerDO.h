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
	//Ա�����
	CC_SYNTHESIZE(string, YGBH, YGBH);
	//Ա������
	CC_SYNTHESIZE(string, PIMPERSONNAME, PIMPERSONNAME);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(string, NJ, NJ);
	// ��֯
	CC_SYNTHESIZE(string, ORGANIZATION_NAME, ORGANIZATION_NAME);
	// ����
	CC_SYNTHESIZE(string, BM, BM);
	// ְ��
	CC_SYNTHESIZE(string, RANK, RANK);
	// ��λ
	CC_SYNTHESIZE(string, GW, GW);
	//�ֻ�����
	CC_SYNTHESIZE(string, LXDH, LXDH);
	// ��ͥ��ϵ��
	CC_SYNTHESIZE(string, JTLXR, JTLXR);
	// ��ͥ��ϵ�˵绰
	CC_SYNTHESIZE(string, JTLXRDH, JTLXRDH);
	
public:
	CommonRosterOfPerDO() {

	}
};

#endif // !_COMMONROSTEROFPER_DO_
