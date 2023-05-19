/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/08 21:19:56

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
#include "stdafx.h"
#include "SciResultController.h"
//��ѯ
SciResultPageJsonVO::Wrapper SciResultController::execQueryTest(const SciResultQuery::Wrapper& query)
{
	// ������Ӧ����
	auto vo = SciResultPageJsonVO::createShared();
	// ������ҳ����
	auto pdto = SciResultPageDTO::createShared();
	pdto->addData(SciResultDTO::createShared("1", "zs"));
	pdto->addData(SciResultDTO::createShared("2", "ls"));
	// ��Ӧ���
	vo->success(pdto);
	return vo;
}


//����
Uint64JsonVO::Wrapper SciResultController::execAddSciResult(const AddSciResultDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo1 = Uint64JsonVO::createShared();
	jvo1->success(1);
	return jvo1;
}


//ɾ��
Uint64JsonVO::Wrapper SciResultController::execDelSciResult(const DelSciResultDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	jvo->success(1);
	return jvo;
}
//����
StringJsonVO::Wrapper SciResultController::execIntoSciResult(const String fileBody, const String suffix)
{
	auto jvo = StringJsonVO::createShared();
				return jvo;
}





