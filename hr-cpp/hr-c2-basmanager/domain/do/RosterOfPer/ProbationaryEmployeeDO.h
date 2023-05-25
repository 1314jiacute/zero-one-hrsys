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
#ifndef _DO_H_
#define _DO_H_

#include "../DoInclude.h"

/* ����Ա�����ݿ�ʵ�� */
/* ���ݱ�t_pimperson */
class ProbationaryEmployeeDO
{	
	// Ա�����
	CC_SYNTHESIZE(string, id, YGBH);
	// Ա������
	CC_SYNTHESIZE(string, name, PIMPERSONNAME);
	// ��֯
	CC_SYNTHESIZE(string, zz, ZZ);
	// ����
	CC_SYNTHESIZE(string, bm, BM);
	// ְ��
	CC_SYNTHESIZE(string, zw, ZW);
	// ��λ
	CC_SYNTHESIZE(string, gw, GW);
	// ��ְʱ��
	CC_SYNTHESIZE(string, rzsj, RZSJ);
	// ���õ���ʱ�� 
	CC_SYNTHESIZE(string, time, SYDQ);
public:
	ProbationaryEmployeeDO() {};
	// �вι��캯��
	ProbationaryEmployeeDO(string id, string name, string zz, string bm, string zw, string gw, string rzsj, string time)
		: id(id)
		, name(name)
		, zz(zz)
		, bm(bm)
		, zw(zw)
		, gw(gw)
		, rzsj(rzsj)
		, time(time)
	{}
};

#endif // !_DO_H_