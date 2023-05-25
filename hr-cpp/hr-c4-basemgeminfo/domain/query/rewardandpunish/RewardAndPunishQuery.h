#pragma once
#ifndef _REWARDANDPUNISHQUERY_H_
#define _REWARDANDPUNISHQUERY_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class RewardAndPunishViewQuery : public oatpp::DTO
{
	DTO_INIT(RewardAndPunishViewQuery, DTO);

	// �����ͷ���ʶ��������
	DTO_FIELD(String, PIMREWARDPUNISHMENTID);
	DTO_FIELD_INFO(PIMREWARDPUNISHMENTID) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.PIMREWARDPUNISHMENTID");
	}
};

class RewardAndPunishDownloadQuery : public oatpp::DTO
{
	DTO_INIT(RewardAndPunishDownloadQuery, DTO);

	// ��Ա��Ϣ��ʶ
	DTO_FIELD(String, PIMPERSONID);
	DTO_FIELD_INFO(PIMPERSONID) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.PIMPERSONID");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif
