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
#ifndef _RETIRED_EMPLPYEES_DO_
#define _RETIRED_EMPLPYEES_DO_
#include "../DoInclude.h"

/*
 ������Ա��DO--����Ա�����ᣩ--pine
 (��Ӧ���ݿ��t_pcmydjdmx���춯�����ϸ �� t_pcmydmx���춯��ϸ)
 */
class RetiredEmployeesDO
{
	// Ա�����
	CC_SYNTHESIZE(uint64_t, ygbh, ygbh);
	// Ա������
	CC_SYNTHESIZE(string, name, name);
	// �Ա�
	CC_SYNTHESIZE(string, xb, xb);
	// ����
	CC_SYNTHESIZE(string, nj, nj);
	// ͨѶ��ַ
	CC_SYNTHESIZE(string, address, address);
	// ���ݵ�
	CC_SYNTHESIZE(string, retiPlace, retiPlace);
	// ��ͥ��ϵ��
	CC_SYNTHESIZE(string, jtlxr, jtlxr);
	// ��ͥ��ϵ�˵绰
	CC_SYNTHESIZE(string, jtlxrdh, jtlxrdh);
	// ��֯
	CC_SYNTHESIZE(string, zz, zz);
	// ����
	CC_SYNTHESIZE(string, bm, bm);
	// ְ��
	CC_SYNTHESIZE(string, rank, rank);
	//����ǰְ��
	CC_SYNTHESIZE(string, yzw, yzw);
	//����ǰ��λ
	CC_SYNTHESIZE(string, ygw, ygw);
	//����ʱ��
	CC_SYNTHESIZE(string, txdq, txdq);
	//ʵ������ʱ��
	CC_SYNTHESIZE(string, sjtxrq, sjtxrq);
	//�ֻ�����
	CC_SYNTHESIZE(string, lxdh, lxdh);
	//���������Ͻ��
	CC_SYNTHESIZE(string, spdylje, spdylje);
public:
	RetiredEmployeesDO() {
		ygbh = "0";
		name = "";
		xb = "";
		nj = "-1";
		address = "";
		retiPlace = "";
		jtlxr = "";
		jtlxrdh = "";
		zz = "";
		bm = "";
		rank = "";
		yzw = "";
		ygw = "";
		txdq = "";
		sjtxrq = "";
		lxdh = "";
		spdylje = "";

	}
};

#endif // !_SAMPLE_DO_
