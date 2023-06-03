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
#include "../../service/assignInfo/AssignInfoService.h"


StringJsonVO::Wrapper AssignInfoController::execAddAssignInfo(const AssignInfoDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->assignId)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	AssignInfoService service;
	// ִ����������
	auto id = service.saveData(dto,payload);
	if (id > 0) {
		jvo->success(String(id));
	}
	else
	{
		jvo->fail(String(id));
	}
	//��Ӧ���
	return jvo;
}

StringJsonVO::Wrapper AssignInfoController::execDeleteAssignInfo(const AssignInfoDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	//// ����У��
	if (!dto->assignId)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	AssignInfoService service;
	auto id = service.removeData(dto->assignId.getValue(""));
	// ִ������ɾ��
	if (id > 0) {
		jvo->success(String(id));
	}
	else
	{
		jvo->fail(String(id));
	}
	// ��Ӧ���
	return jvo;
}

//���벻��Ҫдexec����
//ImportAssignInfoJsonVO::Wrapper AssignInfoController::execImportAssignInfo(const ImportAssignInfoDTO::Wrapper& dto)
//{
//	// ���巵�����ݶ���
//	auto jvo = ImportAssignInfoJsonVO::createShared();
//	return jvo;     
//}

StringJsonVO::Wrapper AssignInfoController::execModifyAssignInfo(const AssignInfoDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	//// ����У��
	if (!dto->assignId)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	AssignInfoService service;
	auto id = service.updateData(dto,payload);
	// ִ�������޸�
	if (id > 0) {
		jvo->success(String(id));
	}
	else
	{
		jvo->fail(String(id));
	}
	// ��Ӧ���
	return jvo;
}

AssignInfoPageJsonVO::Wrapper AssignInfoController::execAssignQuery(const AssignInfoQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	AssignInfoService service;
	//// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = AssignInfoPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

AssignInfoJsonVO::Wrapper AssignInfoController::execAssignQueryDetail(const AssignInfoQueryDetail::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = AssignInfoJsonVO::createShared();

	//// ����һ��Service
	AssignInfoService service;
	////// ��ѯ����
	auto result = service.QueryDetail(dto);
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper AssignInfoController::execExportAssign(const AssignExportQuery::Wrapper& query) {
	auto jvo = StringJsonVO::createShared();
	// ����һ��Service
	AssignInfoService service;
	//// ��ѯ����
	auto result = service.exportData(query);
	if (!result.empty()) {
		jvo->success(result);
	} else {
		jvo->fail("export fail");
	}
	return jvo;
}