#include "stdafx.h"
#include "AddTagController.h"
#include <iostream>
Uint64JsonVO::Wrapper AddTagController::execAddProjTag(const ProjTagDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = Uint64JsonVO::createShared();

	// У��dto����
	// ����У��
	// �ǿ�У��
	if (!dto->sortid || !dto->orgname || !dto->projecttag)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->sortid < 0 || dto->orgname->empty() || dto->projecttag->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	//SampleService service;
	//// ִ����������
	//uint64_t id = service.saveData(dto);
	//// ��ȡpayload�ֶ�
	//String payloadid =  payload.getId();
	//String payloadname = payload.getUsername();
	// ִ����������
	//uint64_t id = service.saveData(dto);
	// idӦ�����ݿ����ҵ�������ֶ�
	uint64_t id = dto->sortid;
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
	// idӦ�����ݿ����ҵ�������ֶ�
	uint64_t id = dto->sortid;
	//��Ӧ���
	jvo->success(UInt64(id));
	return jvo;
}
