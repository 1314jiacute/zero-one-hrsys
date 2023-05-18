#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/18 8:59:52

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
#ifndef _WORKHISTORYFINDPAGEDO_H_
#define _WORKHISTORYFINDPAGEDO_H_


#include "../DoInclude.h"

class WorkHIstoryFindDO
{
	//��ְ��ʼʱ��
	CC_SYNTHESIZE(std::string, RZKSSJ, rZKSSJ);

	//��ְ����ʱ��
	CC_SYNTHESIZE(std::string, RZJSSJ, rZJSSJ);

	//������λ
	CC_SYNTHESIZE(std::string, ORMORGNAME, oRMORGNAME);

	//����
	CC_SYNTHESIZE(std::string, BM, bM);

	//ְλ
	CC_SYNTHESIZE(std::string, ZW, zW);

	//��λ
	CC_SYNTHESIZE(std::string, GW, gW);

	//��ְ�������
	CC_SYNTHESIZE(std::string, CFPLX, cFPLX);

	//�Ƿ���Ҫ����
	CC_SYNTHESIZE(std::string, EXPERIENCE, eXPERIENCE);



};

#endif // !_WORKHISTORYFINDPAGEDO_H_