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
#ifndef _FORMER_EMPLOYEES_DO_
#define _FORMER_EMPLOYEES_DO_
#include "../DoInclude.h"

/**
 * ��ְԱ�����ݿ�ʵ����
 */
class FormerEmployeesDO
{
	// Ա��������Ϣ��ID,ͬԱ��ID
	CC_SYNTHESIZE(uint64_t, ygbh, ygbh);
	// ����
	CC_SYNTHESIZE(string, pimperSonName, pimperSonName);
	// �Ա�
	CC_SYNTHESIZE(string, sex, sex);
	// �ֻ�����
	CC_SYNTHESIZE(string, lxdh, lxdh);
	// ��������
	CC_SYNTHESIZE(string, csrq, csrq);
	// ��֯
	CC_SYNTHESIZE(string, organizationName, organizationName);
	// ����
	CC_SYNTHESIZE(string, bm, bm);
	// ְ��
	CC_SYNTHESIZE(string, rank, rank);
	// ͨѶ��ַ
	CC_SYNTHESIZE(string, postalAddress, postalAddress);
	// ��ͥ��ϵ��
	CC_SYNTHESIZE(string, jtlxr, jtlxr);
	// ��ͥ��ϵ�˵绰
	CC_SYNTHESIZE(string, jtlxrdh, jtlxrdh);
	
public:
	FormerEmployeesDO() {}
};

#endif // !_FPRMERRMPLOYEES_DO_
