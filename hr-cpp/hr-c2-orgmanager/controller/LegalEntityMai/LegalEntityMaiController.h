#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/16 14:48:37

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
#ifndef _LEGALENTITYMAICONTROLLER_H_
#define _LEGALENTITYMAICONTROLLER_H_

#include "domain/query/LegalEntityMai/LegalEntityMaiQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/LegalEntityMai/LegalEntityMaiVO.h"

using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController)

/* ��������ά����������*/
class LegalEntityMaiController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(LegalEntityMaiController);
public: // ����ӿ�
	// �����ѯ����������Ϣ�ӿڶ˵�����
	ENDPOINT_INFO(queryLegalEntityMai) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("LegalEntityMai.query.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON(LegalEntityMaiPageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		info->queryParams.add<String>("ORMSIGNORGID").description = ZH_WORDS_GETTER("LegalEntityMai.field.id");
		info->queryParams["ORMSIGNORGID"].addExample("default", String("1"));
	}
	// �����ѯ����������Ϣ�ӿڶ˵㴦��
	ENDPOINT(API_M_GET, "/LegalEntityMai", queryLegalEntityMai, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(legalEntityMaiQuery, LegalEntityMaiQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(executeQueryById(legalEntityMaiQuery));
	}
private: // ����ӿ�ִ�к���
	// ͨ��id��ѯ
	LegalEntityMaiPageJsonVO::Wrapper executeQueryById(const LegalEntityMaiQuery::Wrapper& legalEntityMaiQuery);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_LEGALENTITYMAICONTROLLER_H_