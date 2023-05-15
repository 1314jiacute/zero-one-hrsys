#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/15 21:03:55

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
#ifndef _MILITARYCONTROLLER_H_
#define _MILITARYCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/military/MilitaryQuery.h"
#include "domain/vo/military/MilitaryVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class MilitaryController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(MilitaryController);
public: // ����ӿ�

	ENDPOINT_INFO(queryMilitary) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("military.get.summary");
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(MilitaryJsonVO);
		// ���������ѯ����
		info->queryParams.add<String>("PIMARMYCADRESID").description = ZH_WORDS_GETTER("military.PIMARMYCADRESID");
		info->queryParams["PIMARMYCADRESID"].addExample("default", String("QWER-ASFD"));
	}
	ENDPOINT(API_M_GET, "/military", queryMilitary, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, MilitaryQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryMilitary(query));
	}

	ENDPOINT_INFO(modifyMilitary) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("military.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/military", modifyMilitary, BODY_DTO(MilitaryDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyMilitary(dto));
	}
private: // ����ӿ�ִ�к���
	MilitaryJsonVO::Wrapper execQueryMilitary(const MilitaryQuery::Wrapper& query);
	Uint64JsonVO::Wrapper execModifyMilitary(const MilitaryDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_MILITARYCONTROLLER_H_