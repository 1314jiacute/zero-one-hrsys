#include "stdafx.h"
#include "JobTitleInformationController.h"
#include "../../service/certificate-information/JobTitleInformationService.h"
JobTitleInformationPageJsonVO::Wrapper JobTitleInformationController::execQuerySample(const JobTitleInformationQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	JobTitleInformationService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = JobTitleInformationPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}




