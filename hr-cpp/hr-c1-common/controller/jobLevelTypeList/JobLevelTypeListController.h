#pragma once
#ifndef _JOBLEVELTYPELISTCONTROLLER_H_
#define _JOBLEVELTYPELISTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "domain/vo/pullList/PullListVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class JobLevelTypeListController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(JobLevelTypeListController);
public: // ����ӿ�
	ENDPOINT_INFO(queryJobLevelType) {
		info->summary = ZH_WORDS_GETTER("common.controller.jobLevelType");
		API_DEF_ADD_RSP_JSON_WRAPPER(PullListVO);
	}

	ENDPOINT(API_M_GET, PATH_TO_PULLIST("/job-level-type"), queryJobLevelType) {
		API_HANDLER_RESP_VO(execQueryJobLevelType());
	}
private: // ����ӿ�ִ�к���
	PullListVO::Wrapper execQueryJobLevelType();
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_JOBLEVELTYPELISTCONTROLLER_H_