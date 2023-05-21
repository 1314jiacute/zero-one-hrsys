
#include "stdafx.h"
#include "CreateNewCerController.h"
//#include "../../service/sample/SampleService.h"

Uint64JsonVO::Wrapper CreateNewCerController::execAddNewCer(const CreateNewCerDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->age || !dto->name || !dto->sex)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}


	// ִ����������
	uint64_t id = 999;
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}