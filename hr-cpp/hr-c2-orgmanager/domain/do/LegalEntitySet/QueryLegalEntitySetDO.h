#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/30 22:50:50

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
#ifndef _QUERYLEGALENTITYSETDO_H_
#define _QUERYLEGALENTITYSETDO_H_

#include "../DoInclude.h"

/* ���������������ݿ��t_contractsignorg, t_srforg, t_ormsignorgʵ��--����֯����-��������-�����������ã�--TripleGold */

class QueryLegalEntitySetDO
{
	// ǩԼ���嵥λ��ʶ
	CC_SYNTHESIZE(string, id, Id);
	// ����λ����
	CC_SYNTHESIZE(string, orgName, OrgName);
	// Ĭ��ǩԼ����
	CC_SYNTHESIZE(string, defa, Defa);
	// ������
	CC_SYNTHESIZE(string, updateman, Updateman);
	// ������
	CC_SYNTHESIZE(string, createman, Createman);
	// ����ʱ��
	CC_SYNTHESIZE(string, createdate, CreateDate);
	// ����ʱ��
	CC_SYNTHESIZE(string, updatedate, Updatedate);
	// ���������ʶt_srforg
	CC_SYNTHESIZE(string, lemIdSrf, LEMIdSrf);
	// ���������ʶt_ormsignorg
	CC_SYNTHESIZE(string, lemId, LEMId);
	// ������������
	CC_SYNTHESIZE(string, lemName, LEMName);
public:
	QueryLegalEntitySetDO() {
		id = "";
		orgName = "";
		lemName = "";
		defa = "";
	};
	QueryLegalEntitySetDO(std::vector<std::string> vec) {
		int i = 0;
		setOrgName(vec[i++]);
		setLEMName(vec[i++]);
		setDefa(vec[i++]);
	}
};

#endif // !_QUERYLEGALENTITYSETDO_H_