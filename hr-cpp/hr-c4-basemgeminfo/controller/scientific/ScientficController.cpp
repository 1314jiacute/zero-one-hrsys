#include "stdafx.h"
#include "ScientificController.h"

ScientificJsonVO::Wrapper ScientificController::execQueryScientific(const ScientificViewQuery::Wrapper& query) {
	// ������Ӧ����
	auto vo = ScientificJsonVO::createShared();
	// ��Ӧ���
	vo->success(ScientificDTO::Wrapper::createShared());
	return vo;
}

Uint64JsonVO::Wrapper ScientificController::execModifyScientific(const ScientificDTO::Wrapper& dto)
{
	// ������Ӧ����
	auto vo = Uint64JsonVO::createShared();
	// ��Ӧ���
	vo->success(2);
	return vo;
}

StringJsonVO::Wrapper ScientificController::execDownloadScientific(const ScientificDownloadQuery::Wrapper& query)
{
	// ������Ӧ����
	auto vo = StringJsonVO::createShared();
	// ��Ӧ���
	vo->success("Download-Link");
	return vo;
}