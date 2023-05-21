#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/


#ifndef _AwardLevelCONTROLLER_H_
#define _AwardLevelCONTROLLER_H_
#include "ServerInfo.h"
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/awardLevel/AwardLevelQuery.h"
#include "domain/vo/awardLevel/AwardLevelVO.h"
#include "Macros.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class AwardLevelController : public oatpp::web::server::api::ApiController // 1
{
	// 2 ����������������
	API_ACCESS_DECLARE(AwardLevelController);
public: // ����ӿ�
	// 3 ����ӿ�����
	ENDPOINT_INFO(queryAwardLevel) {
		// ����ӿڱ���
		info->summary = "award query";
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(AwardLevelPageJsonVO);
		// �����ҳ��ѯ��������
		info->queryParams.add<String>("createTime").description = ZH_WORDS_GETTER("common.dto.createtime");
		info->queryParams["createTime"].addExample("default", String("2019-09-01 14:53:58"));
		info->queryParams["createTime"].required = false;

		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("common.dto.name");
		info->queryParams["name"].addExample("default", String("310111198710101234"));
		info->queryParams["name"].required = false;

		info->queryParams.add<String>("awardCription").description = ZH_WORDS_GETTER("common.dto.awardCription");
		info->queryParams["awardCription"].addExample("default", String("NULL"));
		info->queryParams["awardCription"].required = false;

		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("common.dto.id");
		info->queryParams["id"].addExample("default", String("04BD20DD-6D90-4E69-AD68-F8CDEAAC566B"));
		info->queryParams["id"].required = false;

		info->queryParams.add<String>("updataName").description = ZH_WORDS_GETTER("common.dto.updataName");
		info->queryParams["updataName"].addExample("default", String("310111198710101234"));
		info->queryParams["updataName"].required = false;

		info->queryParams.add<String>("updataTime").description = ZH_WORDS_GETTER("common.dto.uptime");
		info->queryParams["updataTime"].addExample("default", String("2019-09-01 14:53:58"));
		info->queryParams["updataTime"].required = false;

		info->queryParams.add<String>("awardName").description = ZH_WORDS_GETTER("common.dto.awardName");
		info->queryParams["awardName"].addExample("default", String("test"));
		info->queryParams["awardName"].required = false;

		info->queryParams.add<String>("level").description = ZH_WORDS_GETTER("common.dto.level");
		info->queryParams["level"].addExample("default", String("90"));
		info->queryParams["level"].required = false;

		info->queryParams.add<String>("pcmAwardName").description = ZH_WORDS_GETTER("common.dto.pcmAwardName");
		info->queryParams["pcmAwardName"].addExample("default", String("NULL"));
		info->queryParams["pcmAwardName"].required = false;
		
		info->queryParams.add<String>("awardTime").description = ZH_WORDS_GETTER("common.dto.awardTime");
		info->queryParams["awardTime"].addExample("default", String("2019-09-09 00:00:00"));
		info->queryParams["awardTime"].required = false;

		info->queryParams.add<String>("prmID").description = ZH_WORDS_GETTER("common.dto.prmID");
		info->queryParams["prmID"].addExample("default", String("039FC740-E340-4931-BF42-D2F38F81C4C6"));
		info->queryParams["prmID"].required = false;

		info->queryParams.add<String>("judGeorp").description = ZH_WORDS_GETTER("common.dto.judGeorp");
		info->queryParams["judGeorp"].addExample("default", String("test"));
		info->queryParams["judGeorp"].required = false;

		info->queryParams.add<String>("bbSj").description = ZH_WORDS_GETTER("common.dto.bbSj");
		info->queryParams["bbSj"].addExample("default", String("2019-10-31 00:00:00"));
		info->queryParams["bbSj"].required = false;
		
		info->queryParams.add<String>("flag").description = ZH_WORDS_GETTER("common.dto.flag");
		info->queryParams["flag"].addExample("default", String("1"));
		info->queryParams["flag"].required = false;
	}
	// 4 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/test", queryAwardLevel, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query,	AwardLevelQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryAwardLevel(query));
	}
private: // ����ӿ�ִ�к���
	// 5 ����ӿڵ�ִ�к���
	AwardLevelPageJsonVO::Wrapper execQueryAwardLevel(const AwardLevelQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_TESTCONTROLLER_H_