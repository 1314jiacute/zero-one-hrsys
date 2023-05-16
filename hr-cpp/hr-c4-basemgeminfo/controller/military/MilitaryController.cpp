#include "stdafx.h"
#include "MilitaryController.h"

MilitaryJsonVO::Wrapper MilitaryController::execQueryMilitary(const MilitaryDetailQuery::Wrapper& query) {
	// ������Ӧ����
	auto vo = MilitaryJsonVO::createShared();
	// ��Ӧ���
	vo->success(MilitaryDTO::Wrapper::createShared());
	return vo;
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
