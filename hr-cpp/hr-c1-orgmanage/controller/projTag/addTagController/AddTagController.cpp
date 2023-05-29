#include "stdafx.h"
#include "AddTagController.h"
#include <iostream>
#include "service/projTag/ProjTagService.h"
#include "SimpleDateTimeFormat.h"
StringJsonVO::Wrapper AddTagController::execAddProjTag(const ProjTagDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();

	// У��dto����
	// ����У��
	// ������֯��ʶ�Ƿ�Ϊ��
	if (!dto->ormorgid)
	{
		jvo->init("-1", RS_PARAMS_INVALID);
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
	// ִ�гɹ��󷵻���Ŀ��ǩidֵ
	String id = service.saveData(dto);

	//��Ӧ���
	if (id != "-1")
	{
		jvo->init(id, RS_SUCCESS);
	}
	else
	{
		jvo->init(id, RS_FAIL);
	}
	return jvo;
}
