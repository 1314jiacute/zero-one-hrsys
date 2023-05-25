#include "stdafx.h"
#include "RewardAndPunishController.h"

RewardAndPunishJsonVO::Wrapper RewardAndPunishController::execQueryRewardAndPunish(const RewardAndPunishViewQuery::Wrapper& query) {
	// ������Ӧ����
	auto vo = RewardAndPunishJsonVO::createShared();
	// ��Ӧ���
	vo->success(RewardAndPunishDTO::Wrapper::createShared());
	return vo;
}

Uint64JsonVO::Wrapper RewardAndPunishController::execModifyRewardAndPunish(const RewardAndPunishDTO::Wrapper& dto)
{
	// ������Ӧ����
	auto vo = Uint64JsonVO::createShared();
	// ��Ӧ���
	vo->success(2);
	return vo;
}

StringJsonVO::Wrapper RewardAndPunishController::execDownloadRewardAndPunish(const RewardAndPunishDownloadQuery::Wrapper& query)
{
	// ������Ӧ����
	auto vo = StringJsonVO::createShared();
	// ��Ӧ���
	vo->success("Download-Link");
	return vo;
}