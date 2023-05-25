#pragma once
#ifndef _REWARDANDPUNISHDTO_H_
#define _REWARDANDPUNISHDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class RewardAndPunishDTO : public oatpp::DTO {
	DTO_INIT(RewardAndPunishDTO, DTO);

	//����ʱ��
	DTO_FIELD(String, createdate);
	DTO_FIELD_INFO(createdate) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.createdate");
	}

	//����ʱ��
	DTO_FIELD(String, updatedate);
	DTO_FIELD_INFO(updatedate) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.updatedate");
	}

	//��������
	DTO_FIELD(String, pimrewardpunishmentname);
	DTO_FIELD_INFO(pimrewardpunishmentname) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.pimrewardpunishmentname");
	}

	//������
	DTO_FIELD(String, updateman);
	DTO_FIELD_INFO(updateman) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.updateman");
	}

	//������
	DTO_FIELD(String, createman);
	DTO_FIELD_INFO(createman) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.createman");
	}

	//���ͼ���
	DTO_FIELD(String, jcjb);
	DTO_FIELD_INFO(jcjb) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.jcjb");
	}

	//����ʱ��
	DTO_FIELD(String, jclx);
	DTO_FIELD_INFO(jclx) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.jclx");
	}

	//��ע
	DTO_FIELD(String, bz);
	DTO_FIELD_INFO(bz) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.bz");
	}

	//���赥λ
	DTO_FIELD(String, department);
	DTO_FIELD_INFO(department) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.department");
	}

};


#include OATPP_CODEGEN_END(DTO)
#endif