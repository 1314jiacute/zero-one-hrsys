#include "stdafx.h"
#include "AddTagController.h"
#include <iostream>
Uint64JsonVO::Wrapper AddTagController::execAddProjTag(const ProjTagDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = Uint64JsonVO::createShared();

	// У��dto����
	// ����У��
	// �ǿ�У��
	if (!dto->ormxmbqname || !dto->ormorgid)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ��Чֵ����
	

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
	String id = "11";
	//��Ӧ���
	jvo->success(atoi(id->c_str()));
	return jvo;
}

Uint64JsonVO::Wrapper AddTagController::execAddProjTag(const ProjTagDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();

	// У��dto����


	// ִ����������
	//uint64_t id = service.saveData(dto);
	// idӦ�����ݿ����ҵ�������ֶ�
	String id = "11";
	//��Ӧ���
	jvo->success(atoi(id->c_str()));
	return jvo;
}
