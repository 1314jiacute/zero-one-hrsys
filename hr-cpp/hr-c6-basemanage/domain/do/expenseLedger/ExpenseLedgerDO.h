/*
 Copyright Muggle. All rights reserved.

 @Author: Muggle
 @Date: 2023/05/27 0:21:35

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
#pragma once
#ifndef _EXPENSELEDGER_DO_
#define _EXPENSELEDGER_DO_
#include "../DoInclude.h"

class ExpenseLedgerDO
{
	//����̨������
	CC_SYNTHESIZE(string, name, Name);
	//����̨�˱�ʶ
	CC_SYNTHESIZE(string, id, Id);
	//������
	CC_SYNTHESIZE(string, updateman, Updateman);
	//����ʱ��
	CC_SYNTHESIZE(string, createdate, Createdate);
	//������
	CC_SYNTHESIZE(string, createman, Createman);
	//����ʱ��
	CC_SYNTHESIZE(string, updatedate, Updatedate);

	//�������
	CC_SYNTHESIZE(string, fylb, Fylb);
	//���ý��
	CC_SYNTHESIZE(double, fyje, Fyje);
	//��������
	CC_SYNTHESIZE(int, ffrs, Ffrs);
	//����ʱ��
	CC_SYNTHESIZE(string, ffsj, Ffsj);
	//���ñ�׼
	CC_SYNTHESIZE(string, fybz, Fybz);
	//��ע
	CC_SYNTHESIZE(string, bz, Bz);
public:
	ExpenseLedgerDO() {
		name = "";
		id = "";
		createdate = "";
		createman = "";
		updateman = "";
		updatedate = "";

		fylb = "";
		fyje = 0;
		ffrs = 0;
		ffsj = "";
		fybz = "";
		bz = "";

	}
};
#endif