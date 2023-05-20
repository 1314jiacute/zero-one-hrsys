#include "stdafx.h"
#include "QueryAssignController.h"
#include "../../service/assignInfo/AssignInfoQueryService.h"

AssignInfoQueryJsonVO::Wrapper QueryAssignController::execAssignQuery(const AssignInfoQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	AssignInfoQueryService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = AssignInfoQueryJsonVO::createShared();
	jvo->success(result);
	return jvo;
}