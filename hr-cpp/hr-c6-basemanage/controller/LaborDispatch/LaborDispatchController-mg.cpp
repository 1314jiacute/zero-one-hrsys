/*
 Copyright Muggle. All rights reserved.

 @Author: Muggle
 @Date: 2023/05/19 23:25:03

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
#include "LaborDispatchController-mg.h"
#include "../../service/laborDispatch/LaborDispatchService-mg.h"

LaborDispatchJsonMVO::Wrapper LaborDispatchMController::execQueryLaborDispatch(const LaborDispatchMQuery::Wrapper& query)
{
	// ����Service
	LaborDispatchMService service;
	// serviceִ�в���������
	auto result = service.ListAll(query);
	// ��Ӧ���
	auto vo = LaborDispatchJsonMVO::createShared();
	vo->success(result);
	return vo;
}

StringJsonVO::Wrapper LaborDispatchMController::execModifyLaborDispatch(const LaborDispatchDTO::Wrapper& dto)
{
	auto jvo = StringJsonVO::createShared();

	if (!dto->id)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		cout << "wrong"<< endl;
		return jvo;
	}
	LaborDispatchMService service;
	if (service.updateData(dto))
	{
		jvo->success(dto->id);
		cout << "success" << endl;
	} 
	else
	{
		jvo->fail(dto->id);
		cout << "wrong2" << endl;
	}
	return jvo;
}
