#include "stdafx.h"
#include "ModifyAssignInfoController.h"
Uint64JsonVO::Wrapper ModifyAssignInfoController::execModifyAssignInfo(const ModifyAssignInfoDTO::Wrapper& dto)
{
	//// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	//// ����У��
	//if (!dto->id || dto->id <= 0)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
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