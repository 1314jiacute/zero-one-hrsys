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
	// ��ְ��ϢID���������������������
	CC_SYNTHESIZE(uint64_t, LEAVINGANALYSIS_ID, LEAVINGANALYSIS_ID);
	// Ա��������Ϣ��ID,ͬԱ��ID
	CC_SYNTHESIZE(uint64_t, PIMPERSONNAME, PIMPERSONNAME);
	// ����
	CC_SYNTHESIZE(string, EMPLOYEENAME, EMPLOYEENAME);
	// �Ա�
	CC_SYNTHESIZE(string, XB, XB);
	// �ֻ�����
	CC_SYNTHESIZE(string, LXDH, LXDH);
	// ��������
	CC_SYNTHESIZE(int, CSRQ, CSRQ);
	// ��֯
	CC_SYNTHESIZE(string, ORGANIZATION_NAME, ORGANIZATION_NAME);
	// ����
	CC_SYNTHESIZE(string, BM, BM);
	// ְ��
	CC_SYNTHESIZE(string, RANK, RANK);
	// ͨѶ��ַ
	CC_SYNTHESIZE(string, POSTALADDRESS, POSTALADDRESS);
	// ��ͥ��ϵ��
	CC_SYNTHESIZE(string, JTLXR, JTLXR);
	// ��ͥ��ϵ�˵绰
	CC_SYNTHESIZE(string, JTLXRDH, JTLXRDH);
	
public:
	FormerEmployeesDO() {}
};

#endif // !_FPRMERRMPLOYEES_DO_
