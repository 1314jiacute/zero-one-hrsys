#include "stdafx.h"
#include "AddTagController.h"
#include <iostream>
#include "service/projTag/ProjTagService.h"
#include "SimpleDateTimeFormat.h"
Uint64JsonVO::Wrapper AddTagController::execAddProjTag(const ProjTagDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = Uint64JsonVO::createShared();

	// У��dto����
	// ����У��
	// ������Ŀ��ǩ��ʶ�Ƿ�Ϊ��
	if (!dto->ormorgid || !dto->ormorgid)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	
	// ��ЧֵУ��
	

	// ��ȡpayload�ֶ�
	dto->createman = payload.getUsername();
	dto->updateman = payload.getUsername();
	dto->createdate = SimpleDateTimeFormat::format();
	dto->updatedate = dto->createdate;
	
	// ����һ��service
	ProjTagService service;

	// ִ���������� 
	uint64_t id = service.saveData(dto);

	//��Ӧ���
	jvo->success(UInt64(id));

	return jvo;
}

Uint64JsonVO::Wrapper AddTagController::execAddProjTag(const ProjTagDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();

	// У��dto����


	// ִ����������
	//uint64_t id = service.saveData(dto);

	//��Ӧ���
	jvo->success(UInt64(155149));

	return jvo;
}
