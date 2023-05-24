#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xubuxi
 @Date: 2023/05/25 0:52:24

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
#ifndef _ARCHIVESLEVELSDO_H_
#define _ARCHIVESLEVELSDO_H_
#include "../DoInclude.h"
class ArchivesLevelsDO
{
	//����ʱ��
	CC_SYNTHESIZE(string, createdate, Createdate);
	//������
	CC_SYNTHESIZE(string, createman, Createman);
	//���������
	CC_SYNTHESIZE(string, pcmawardswonsname, Pcmawardswonsname);
	//�������ʶ
	CC_SYNTHESIZE(string, pcmawardswonsid, Pcmawardswonsid);
	//������
	CC_SYNTHESIZE(string, updateman, Updateman);
	//����ʱ��
	CC_SYNTHESIZE(string, updatedate, Updatedate);
	//������
	CC_SYNTHESIZE(string, awardname, Awardname);
	//�񽱵ȼ�
	CC_SYNTHESIZE(string, awardlevel, Awardlevel);
	//�����
	CC_SYNTHESIZE(string, awarddescription, Awarddescription);
	//��ʱ��
	CC_SYNTHESIZE(string, awardtime, Awardtime);
	//ӦƸ��ID
	CC_SYNTHESIZE(string, pcmprofileid, Pcmprofileid);
	//��������
	CC_SYNTHESIZE(string, judgeorg, Judgeorg);
	//�汾ʱ��
	CC_SYNTHESIZE(string, bbsj, Bbsj);
	//�Ƿ���Ч
	CC_SYNTHESIZE(string, flag, Flag);

public:
	ArchivesLevelsDO() {
		createdate = "";
		createman = "";
		pcmawardswonsname = "";
		pcmawardswonsid = "";
		updateman = "";
		updatedate = "";
		awardname = "";
		awardlevel = "";
		awarddescription = "";
		awardtime = "";
		pcmprofileid = "";
		judgeorg = "";
		bbsj = "";
		flag = "";
	}
};

#endif // !_ARCHIVESLEVELSDO_H_