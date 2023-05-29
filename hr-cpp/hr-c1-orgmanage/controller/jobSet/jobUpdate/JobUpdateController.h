//2023��5��21��
//��λ������Ϣ
//���ߣ���Ƥ�����
#pragma once
#ifndef _JOB_UPDATE_CONTROLLER_
#define _JOB_UPDATE_CONTROLLER_

#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "domain/vo/BaseJsonVO.h"
#include "../../../domain/dto/jobUpdate/JobUpdateDTO.h"
#include "../../../domain/vo/jobUpdate/JobUpdateVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class JobUpdateController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(JobUpdateController);
public:
	ENDPOINT_INFO(updatejobinfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("job.set.update");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(JobUpdateJsonVO);
	}
	ENDPOINT(API_M_PUT, PATH_TO_JOBSET("/update-job"), updatejobinfo, BODY_DTO(JobUpdateDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execUpdateJobinfo(dto));
	}
private:
	JobUpdateJsonVO::Wrapper execUpdateJobinfo(const JobUpdateDTO::Wrapper& dto);
};


#include OATPP_CODEGEN_END(ApiController)
#endif // !_