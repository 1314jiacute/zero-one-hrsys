#include "stdafx.h"
#include "ProbationaryEmployeeController.h"
#include "../../service/RosterOfPer/ProbationaryEmployeeService.h"

ProbationaryEmployeePageJsonVO::Wrapper ProbationaryEmployeeController::execQueryProbationaryEmployee(const ProbationaryEmployeeQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	ProbationaryEmployeeService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ProbationaryEmployeePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

ProbationaryEmployeePageJsonVO::Wrapper ProbationaryEmployeeController::execListProbationaryEmployee(const ProbationaryEmployeeQuery::Wrapper& query, const PayloadDTO& payload)
{
	auto jvo = ProbationaryEmployeePageJsonVO::createShared();

	return jvo;
}