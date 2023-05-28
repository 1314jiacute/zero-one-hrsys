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
#include "CharsetConvertHepler.h"

/**
 * ��ְԱ�����ݿ�ʵ����
 */
class FormerEmployeesDO
{
	// Ա��������Ϣ��ID,ͬԱ��ID
	CC_SYNTHESIZE(string, ygbh, ygbh);
	// ����
	CC_SYNTHESIZE(string, pimPersonName, pimPersonName);
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

	// ����Ϊ��ǰ����ʾ�ֶ�
	// t_pcmydlzmx�������춯��ְ��ϸ��ʶ
	CC_SYNTHESIZE(string, pcmydlzmxId, pcmydlzmxId);
	// FOREIGN KEY t_pimperson ��Ա��Ϣ��ʶ
	CC_SYNTHESIZE(string, lzmtrId, lzmtrId);

public:
	FormerEmployeesDO() {};
	std::vector<std::string> FormerEmployeestoVector()
	{
		std::vector<std::string> vec { this->getygbh(),\
			this->getpimPersonName(), this->getsex(), this->getlxdh(),\
			this->getcsrq(), this->getorganizationName(), this->getbm(),\
			this->getrank(), this->getpostalAddress(), this->getjtlxr(), this->getjtlxrdh() };
		
		return vec;
	}
};

#endif // !_FPRMERRMPLOYEES_DO_
