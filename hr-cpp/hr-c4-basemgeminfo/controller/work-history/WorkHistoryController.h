#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/15 11:14:40

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
#ifndef _WORKHISTORYCONTROLLER_H_
#define _WORKHISTORYCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "domain/query/work-history/WorkHistoryPageQuery.h"
#include "domain/vo/work-history/WorkHistoryFindVO.h"
#include "domain/dto/work-history/AddWorkHistoryDTO.h"
using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)

class WorkHistoryController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(WorkHistoryController);
public: // ����ӿ�
	//  �����ѯ�ӿ�����
	ENDPOINT_INFO(queryWorkHistory) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("workhistory.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(WorkHistoryFindVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("sample.field.pimpersonid");
		info->queryParams["pimpersonid"].addExample("default", String("6611212223"));
		info->queryParams["pimpersonid"].required = false;
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/workhistory", queryWorkHistory, QUERIES(QueryParams, qps)) {
		//������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, WorkHistoryPageQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryWorkHistory(query));
	}

	// ���������ӿ�����
	ENDPOINT_INFO(addWorkHistory) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("WorkHistory.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ���������ӿڴ���
	ENDPOINT(API_M_POST, "/workhistory", addWorkHistory, BODY_DTO(AddWorkHistoryDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddWorkHistory(dto));
	}

private: // ����ӿ�ִ�к���
	WorkHistoryFindVO::Wrapper execQueryWorkHistory(const WorkHistoryPageQuery::Wrapper& query);

	Uint64JsonVO::Wrapper execAddWorkHistory(const AddWorkHistoryDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_WORKHISTORYCONTROLLER_H_