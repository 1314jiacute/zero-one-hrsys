#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/24 23:15:37

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

#ifndef _PROBATIONARY_EMPLOYEE_DO_H_
#define _PROBATIONARY_EMPLOYEE_DO_H_

#include "../DoInclude.h"

/* ����Ա�����ݿ�ʵ�� */
/* ���ݱ�t_pimperson  t_pcmsgqmgr */
class ProbationaryEmployeeDO
{	
	
	// Ա�����
	CC_SYNTHESIZE(string, YGBH, YGBH);
	// Ա������
	CC_SYNTHESIZE(string, PIMPERSONNAME, PIMPERSONNAME);
	// ��֯
	CC_SYNTHESIZE(string, ORMORGNAME, ORMORGNAME);
	// ����
	CC_SYNTHESIZE(string, ORMORGSECTORNAME, ORMORGSECTORNAME);
	// ְ��
	CC_SYNTHESIZE(string, ZW, ZW);
	// ��λ
	CC_SYNTHESIZE(string, ORMPOSTNAME, ORMPOSTNAME);
	// ��ְʱ��
	CC_SYNTHESIZE(string, RZSJ, RZSJ);
	// ���õ���ʱ�� 
	CC_SYNTHESIZE(string, SYDQ, SYDQ);
	// ����Ϊ��ѯʹ�ã���ǰ�˴���
	// ��Ա��Ϣ��ʶ  REFERENCES `t_pimperson`
	CC_SYNTHESIZE(string, pimPersonId, pimPersonId);
	// �Ը��ڹ����ʶ PRIMARY KEY
	CC_SYNTHESIZE(string, PCMSGQMGRID, PCMSGQMGRID);

public:
	ProbationaryEmployeeDO() {};
	// �вι��캯��
	ProbationaryEmployeeDO(string id, string name, string zz, string bm, string zw, string gw, string rzsj, string time)
		: YGBH(id)
		, PIMPERSONNAME(name)
		, ORMORGNAME(zz)
		, ORMORGSECTORNAME(bm)
		, ZW(zw)
		, ORMPOSTNAME(gw)
		, RZSJ(rzsj)
		, SYDQ(time)
		, pimPersonId(pimPersonId)
		, PCMSGQMGRID(PCMSGQMGRID)
	{}
};

#endif // !_DO_H_