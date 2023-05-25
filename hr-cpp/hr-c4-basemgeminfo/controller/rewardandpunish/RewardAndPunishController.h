#pragma once
#ifndef _REWARDANDPUNISHCONTROLLER_H_
#define _REWARDANDPUNISHCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/rewardandpunish/RewardAndPunishQuery.h"
#include "domain/vo/rewardandpunish/RewardAndPunishVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class RewardAndPunishController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(RewardAndPunishController);
public: // ����ӿ�
	//�鿴ָ��Ա�������Ϣ(ָ��������Ϣ����)
	ENDPOINT_INFO(queryRewardAndPunish) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("rewardandpunish.get.summary");
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(RewardAndPunishJsonVO);
		// ���������ѯ����
		info->queryParams.add<String>("PIMARMYCADRESID").description = ZH_WORDS_GETTER("rewardandpunish.PIMARMYCADRESID");
		info->queryParams["PIMARMYCADRESID"].addExample("default", String("QWER-ASFD"));
	}
	ENDPOINT(API_M_GET, "/rewardandpunish", queryRewardAndPunish, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, RewardAndPunishViewQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryRewardAndPunish(query));
	}
	//�޸�ָ��������Ϣ(�����޸�)
	ENDPOINT_INFO(modifyRewardAndPunish) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("RewardAndPunish.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_PUT, "/rewardandpunish", modifyRewardAndPunish, BODY_DTO(RewardAndPunishDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyRewardAndPunish(dto));
	}
	//����ָ��Ա��������Ϣ(������ҳ��ǰ�����)
	ENDPOINT_INFO(downloadRewardAndPunish) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("rewardandpunish.download.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ���������ѯ����	
		info->queryParams.add<String>("PIMPERSONID").description = ZH_WORDS_GETTER("rewardandpunish.PIMPERSONID");
		info->queryParams["PIMPERSONID"].addExample("default", String("0000-QWDE"));
	}
	ENDPOINT(API_M_POST, "/rewardandpunish", downloadRewardAndPunish, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, RewardAndPunishDownloadQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execDownloadRewardAndPunish(query));
	}
private: // ����ӿ�ִ�к���
	RewardAndPunishJsonVO::Wrapper execQueryRewardAndPunish(const RewardAndPunishViewQuery::Wrapper& query);
	Uint64JsonVO::Wrapper execModifyRewardAndPunish(const RewardAndPunishDTO::Wrapper& dto);
	StringJsonVO::Wrapper execDownloadRewardAndPunish(const RewardAndPunishDownloadQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif