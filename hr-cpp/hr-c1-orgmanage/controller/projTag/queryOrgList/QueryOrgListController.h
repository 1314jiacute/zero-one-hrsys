#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/24 17:58:45

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
#ifndef _QUERYORGLISTCONTROLLER_H_
#define _QUERYORGLISTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "ApiHelper.h"
#include "domain/query/projTag/OrgListQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * ��ҳ��ѯ��֯�б������
 * �����ˣ�Andrew
 * ��Ӧ���ݱ�
 */
class QueryOrgListController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(QueryOrgListController);
public: // ����ӿ�
	ENDPOINT_INFO(queryOrgList) {
		info->summary = ZH_WORDS_GETTER("projTag.orgList.summary");
		API_DEF_ADD_RSP_JSON_WRAPPER();
		API_DEF_ADD_PAGE_PARAMS();

	}

	ENDPOINT(API_M_GET, PATH_TO_PROJTAG("/query-org-page"), queryOrgList, QUERIES(QueryParams,qps)) {
		API_HANDLER_QUERY_PARAM(query, OrgListQuery, qps);
		API_HANDLER_RESP_VO(execQueryOrgList(query));
	}
private: // ����ӿ�ִ�к���
	void execQueryOrgList(const OrgListQuery::Wrapper &query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_QUERYORGLISTCONTROLLER_H_