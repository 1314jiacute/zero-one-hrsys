/*
��֤�����-֤����Ϣ-ɾ��֤�飨֧������ɾ������--����
*/
#include "stdafx.h"
#include "CertifDeleteController.h"
#include "../../service/CertificateManage/DeleteCertifService.h"


StringJsonVO::Wrapper CertifDeleteController::execRemoveCertif(const RemoveCertifDTO::Wrapper& dto)
{
	
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->id)
	{
		jvo->init(string("param err"), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	DeleteCertifService service;
	// ִ������ɾ��
	if (service.removeData(dto->id.getValue(""))) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// ��Ӧ���
	return jvo;
}