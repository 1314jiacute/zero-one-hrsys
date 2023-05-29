#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/18 22:06:12

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
#ifndef _T_ORMSIGNORGDO_H_
#define _T_ORMSIGNORGDO_H_

#include "../DoInclude.h"

/* ��������ά�����ݿ��t_ormsignorgʵ��--����֯����-��������-��������ά����--TripleGold */

class OrmsignorgDO
{
	// ���������ʶ
	CC_SYNTHESIZE(string, id, Id);
	// ������������
	CC_SYNTHESIZE(string, name, Name);
	// ��֯���
	CC_SYNTHESIZE(string, orgcode, Code);

	//// ���������ʶ
	//CC_SYNTHESIZE(string, id, ORMSIGNORGID);
	//// ������
	//CC_SYNTHESIZE(string, updateman, UPDATEMAN);
	//// ������
	//CC_SYNTHESIZE(string, createman, CREATEMAN);
	//// ����ʱ��
	//CC_SYNTHESIZE(string, createdate, CREATEDATE);
	//// ������������
	//CC_SYNTHESIZE(string, name, ORMSIGNORGNAME);
	//// ����ʱ��
	//CC_SYNTHESIZE(string, updatedate, UPDATEDATE);
	//// ��֯���
	//CC_SYNTHESIZE(string, orgcode, ORGCODE);
	//// ���
	//CC_SYNTHESIZE(string, shortForm, ZZJC);
public:
	OrmsignorgDO() {
		id = "";
		name = "";
		orgcode = "";
	}
	OrmsignorgDO(std::vector<std::string> vec)
	{
		int i = 0;
		setName(vec[i++]);
		setCode(vec[i++]);
	}
	/*OrmsignorgDO(string id, string updateman, string createman, string createdate,
		string name, string updatedate, string orgcode, string shortForm) {
		this->id = id;
		this->updateman = updateman;
		this->createman = createman;
		this->createdate = createdate;
		this->name = name;
		this->updatedate = updatedate;
		this->orgcode = orgcode;
		this->shortForm = shortForm;
	}*/
};
#endif // !_T_ORMSIGNORGDO_H_