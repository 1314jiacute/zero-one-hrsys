#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/17 20:24:15

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
#ifndef _FILERESERVATIONCONTROLLER_H_
#define _FILERESERVATIONCONTROLLER_H_

#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/filereservation/FilereservationVO.h"
#include "domain/query/filereservation/FilereservationQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class FilereservationController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(FilereservationController);
public: // ����ӿ�
	ENDPOINT_INFO(queryFileReservation) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("filereservation.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(FilereservationJsonVO);
		// �����ҳ��������
		//API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		/*info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("sample.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = false;
		info->queryParams.add<String>("sex").description = ZH_WORDS_GETTER("sample.field.sex");
		info->queryParams["sex"].addExample("default", String("N"));
		info->queryParams["sex"].required = false;*/
	}
	ENDPOINT(API_M_GET, "/file-reservation", queryFileReservation, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(filereservationQuery, FileReservationQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryFileStatus(filereservationQuery, authObject->getPayload()));
	}
private: // ����ӿ�ִ�к���
	FilereservationJsonVO::Wrapper execQueryFileStatus(const FileReservationQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FILERESERVATIONCONTROLLER_H_