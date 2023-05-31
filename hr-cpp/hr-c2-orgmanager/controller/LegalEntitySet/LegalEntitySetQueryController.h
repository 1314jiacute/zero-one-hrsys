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
#ifndef _LEGALENTITYSETCONTROLLER_H_
#define _LEGALENTITYSETCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "ExcelComponent.h"
#include "oatpp-swagger/Types.hpp"
#include "domain/query/LegalEntitySet/LegalEntitySetQuery.h"
#include "domain/vo/LegalEntitySet/LegalEntitySetVO.h"

using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController)
namespace multipart = oatpp::web::mime::multipart;

/* �����������ÿ��������--����֯����-��������-�����������ã�--TripleGold */
class LegalEntitySetQueryController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(LegalEntitySetQueryController);
public: // ����ӿ�
	// �����ѯ����������Ϣ�ӿ�����
	ENDPOINT_INFO(queryLES) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.query.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(LegalEntitySetQueryPageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		info->queryParams.add<String>("ORGNAME").description = ZH_WORDS_GETTER("LegalEntitySet.field.name");
		info->queryParams["ORGNAME"].addExample("default", String(ZH_WORDS_GETTER("LegalEntitySet.sample.name")));
		info->queryParams["ORGNAME"].required = false;
		info->queryParams.add<String>("ORMSIGNORGNAME").description = ZH_WORDS_GETTER("LegalEntityMai.field.name");
		info->queryParams["ORMSIGNORGNAME"].addExample("default", String(ZH_WORDS_GETTER("LegalEntityMai.sample.name")));
		info->queryParams["ORMSIGNORGNAME"].required = false;
	}
	// �����ѯ����������Ϣ�ӿڴ���
	ENDPOINT(API_M_GET, "/org/query-LES", queryLES, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(legalEntitySetQuery, LegalEntitySetQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryLES(legalEntitySetQuery));
	}

private: // ����ӿ�ִ�к���
	// ��ҳ��ѯ����
	LegalEntitySetQueryPageJsonVO::Wrapper execQueryLES(const LegalEntitySetQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_LEGALENTITYSETCONTROLLER_H_