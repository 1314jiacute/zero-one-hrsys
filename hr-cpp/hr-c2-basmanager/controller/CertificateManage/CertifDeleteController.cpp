/*
��֤�����-֤����Ϣ-ɾ��֤�飨֧������ɾ������--����
*/
#include "stdafx.h"
#include "CertifDeleteController.h"
//#include "../../service/sample/SampleService.h"


Uint64JsonVO::Wrapper CertifDeleteController::execRemoveCertif(const RemoveCertifDTO::Wrapper& dto)
{
	
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	/*
	// ����У��
	if (!dto->id || dto->id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	SampleService service;
	// ִ������ɾ��
	if (service.removeData(dto->id.getValue(0))) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// ��Ӧ���
	*/
	return jvo;
}