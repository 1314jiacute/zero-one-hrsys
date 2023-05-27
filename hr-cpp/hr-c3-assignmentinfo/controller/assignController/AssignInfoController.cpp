#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ahao
 @Date: 2023/5/22 14:58:43

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
#include "AssignInfoController.h"
#include "../../service/assignInfo/AssignInfoQueryService.h"
Uint64JsonVO::Wrapper AssignInfoController::execAddAssignInfo(const AddAssignInfoDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->id || !dto->assign || !dto->organize || !dto->depart || !dto->job || !dto->post || !dto->startTime || !dto->endTime)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->id->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	//// ����һ��Service
	//AddAssignInfoService service;
	//// ִ����������
	//uint64_t id = service.saveData(dto);
	//if (id > 0) {
	//	jvo->success(UInt64(id));
	//}
	//else
	//{
	//	jvo->fail(UInt64(id));
	//}
	//��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper AssignInfoController::execDeleteAssignInfo(const DeleteAssignInfoDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	//// ����У��
	if (!dto->id)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//// ����һ��Service
	//SampleService service;
	//// ִ������ɾ��
	//if (service.removeData(dto->id.getValue(0))) {
	//	jvo->success(dto->id);
	//}
	//else
	//{
	//	jvo->fail(dto->id);
	//}
	//// ��Ӧ���
	return jvo;
}

//���벻��Ҫдexec����
//ImportAssignInfoJsonVO::Wrapper AssignInfoController::execImportAssignInfo(const ImportAssignInfoDTO::Wrapper& dto)
//{
//	// ���巵�����ݶ���
//	auto jvo = ImportAssignInfoJsonVO::createShared();
//	return jvo;     
//}

Uint64JsonVO::Wrapper AssignInfoController::execModifyAssignInfo(const ModifyAssignInfoDTO::Wrapper& dto)
{
	//// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	//// ����У��
	if (!dto->id)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//// ����һ��Service
	//SampleService service;
	//// ִ�������޸�
	//if (service.updateData(dto)) {
	//	jvo->success(dto->id);
	//}
	//else
	//{
	//	jvo->fail(dto->id);
	//}
	//// ��Ӧ���
	return jvo;
}

AssignInfoQueryJsonVO::Wrapper AssignInfoController::execAssignQuery(const AssignInfoQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	AssignInfoQueryService service;
	//// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = AssignInfoQueryJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

AssignInfoQueryDetailJsonVO::Wrapper AssignInfoController::execAssignQueryDetail(const AssignInfoQueryDetail::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = AssignInfoQueryDetailJsonVO::createShared();
	return jvo;
}