#include "stdafx.h"
#include "DeleteAssignInfoController.h"
Uint64JsonVO::Wrapper DeleteAssignInfoController::execDeleteAssignInfo(const DeleteAssignInfoDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	//// ����У��
	//if (!dto->id || dto->id <= 0)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
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