#include "stdafx.h"
#include "MilitaryController.h"
#include "../../service/military/MilitaryService.h"

MilitaryJsonVO::Wrapper MilitaryController::execQueryMilitary(const MilitaryDetailQuery::Wrapper& query) {
	// ����һ��Service
	MilitaryService service;
	// ��ѯ����
	auto result = service.listDetail(query);
	// ��Ӧ���
	auto jvo = MilitaryJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper MilitaryController::execModifyMilitary(const MilitaryDTO::Wrapper& dto)
{
	// ������Ӧ����
	auto vo = Uint64JsonVO::createShared();
	// ��Ӧ���
	vo->success(1);
	return vo;
}

StringJsonVO::Wrapper MilitaryController::execDownloadMilitary(const MilitaryDownloadQuery::Wrapper& query)
{
	// ������Ӧ����
	auto vo = StringJsonVO::createShared();
	// ��Ӧ���
	vo->success("Download-Link");
	return vo;
}
