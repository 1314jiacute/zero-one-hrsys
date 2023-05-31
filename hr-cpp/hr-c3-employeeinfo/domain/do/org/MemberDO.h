#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: J1senn
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
#ifndef _MEMBER_DO_
#define _MEMBER_DO_
#include "../DoInclude.h"

class MemberDO
{
    // Ա�����
	CC_SYNTHESIZE(string, ygbh, YGBH);
    // Ա������
	CC_SYNTHESIZE(string, pimpersonname, PimPersonID);
    // ��֯
	CC_SYNTHESIZE(string, ormorgname, OrmOrgName);
    // ����
	CC_SYNTHESIZE(string, ormorgsectorname, OrmOrgSectorName);
    // ְ��
	CC_SYNTHESIZE(string, zw, ZW);
	// ��λ
	CC_SYNTHESIZE(string, gw, GW);
	// ֤������
	CC_SYNTHESIZE(string, zjhm, ZJHM);
	// ��������
	CC_SYNTHESIZE(string, csrq, CSRQ);
	// ���
	CC_SYNTHESIZE(string, nj, NJ);
	// ��ϵ�绰
	CC_SYNTHESIZE(string, lxdh, LXDH);
public:
	MemberDO() {
        ygbh = "";
        pimpersonname = "";
        ormorgname = "";
        ormorgsectorname = "";
        zw = "";
        gw = "";
        zjhm = "";
        csrq = "";
        nj = "";
        lxdh = "";
    }

};

#endif // !_MEMBER_DO_