#include "stdafx.h"
#include "DeclareListController.h"
#include "../../service/declare/DeclareService.h"


DeclareListJsonVO::Wrapper DeclareListController::execQueryDeclare(const DeclareQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	DeclareService service;
	// ��ѯ����
	auto result = service.declareAll(query);
	// ��Ӧ���
	auto jvo = DeclareListJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
