#include "stdafx.h"
#include "JobUpdateController.h"
#include "service/jobSet/jobUpdateService/JobUpdateService.h"
#include "SimpleDateTimeFormat.h"

JobUpdateJsonVO::Wrapper JobUpdateController::execUpdateJobinfo(const JobUpdateDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = JobUpdateJsonVO::createShared();
	dto->updateMan = payload.getUsername();
	dto->updateDate== SimpleDateTimeFormat::format();
	JobUpdateService service;
	if (service.uodateJobInfo(dto)) {
		jvo->success(dto);
	}
	else {
		jvo->fail(dto);
	}
	// ��Ӧ���
	return jvo;
}