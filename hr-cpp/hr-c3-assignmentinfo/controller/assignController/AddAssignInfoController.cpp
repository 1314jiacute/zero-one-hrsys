#include "stdafx.h"
#include "AddAssignInfoController.h"
//#include "../../service/assignInfo/AddAssignInfoService.h"


AddAssignInfoJsonVO::Wrapper AddAssignInfoController::execAddAssignInfo(const AddAssignInfoDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = AddAssignInfoJsonVO::createShared();
	// ����У��
	// �ǿ�У��
	//if (!dto->id || !dto->assign || !dto->organize || !dto->depart || !dto->job || !dto->post || !dto->start_time || !dto->end_time)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	//// ��ЧֵУ��
	//if (dto->id->empty())
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}

	//// ����һ��Service
	//AddAssignInfoService service;
	//// ִ����������
	//uint64_t id = service.saveData(dto);
	//if (id > 0) {
	//	jvo->success(UInt64(id));
	//}
	//else
	//{
	//	jvo->fail(UInt64(id));
	//}
	//��Ӧ���
	return jvo;
}

