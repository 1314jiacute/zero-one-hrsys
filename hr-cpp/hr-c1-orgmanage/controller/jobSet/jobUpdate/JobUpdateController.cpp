#include "stdafx.h"
#include "JobUpdateController.h"

JobUpdateJsonVO::Wrapper JobUpdateController::execUpdateJobinfo(const JobUpdateDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = JobUpdateJsonVO::createShared();
	// ����У��
	if (!dto->index || dto->index <= 0)
	{
		jvo->init(UInt32(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	jvo->success(dto->index);
	
	// ��Ӧ���
	return jvo;
}