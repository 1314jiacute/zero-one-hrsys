#include "stdafx.h"
#include "MilitaryController.h"

MilitaryJsonVO::Wrapper MilitaryController::execQueryMilitary(const MilitaryQuery::Wrapper& query) {
	// ������Ӧ����
	auto vo = MilitaryJsonVO::createShared();
	// ��Ӧ���
	vo->success(MilitaryDTO::Wrapper::createShared());
	return vo;
}