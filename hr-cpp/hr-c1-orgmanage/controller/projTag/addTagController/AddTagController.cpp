#include "stdafx.h"
#include "AddTagController.h"
#include <iostream>
Uint64JsonVO::Wrapper AddTagController::execAddProjTag(const ProjTagDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = Uint64JsonVO::createShared();

	// У��dto����
	// ����У��
	// �ǿ�У��
	if (!dto->orgname || !dto->projecttag)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->orgname->empty() || dto->projecttag->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	
	// ��ȡpayload�ֶ�
	String payloadid =  payload.getId();
	String payloadname = payload.getUsername();
	// ִ����������
	//uint64_t id = service.saveData(dto);
	//��Ӧ���
	jvo->success(UInt64(114514));
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
