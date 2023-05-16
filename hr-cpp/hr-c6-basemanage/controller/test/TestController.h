#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/08 21:23:08

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
#ifndef _TESTCONTROLLER_H_
#define _TESTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/sample/SampleQuery.h"
#include "domain/vo/sample/SampleVO.h"
#include "domain/dto/sample/ContractDTO.h"
#include "domain/query/PageQuery.h"
#include "../arch-demo/Macros.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "oatpp/codegen/api_controller/base_define.hpp"
#include "ApiHelper.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController) // 0

/**
 * ���Կ�����
 */
class FindController : public oatpp::web::server::api::ApiController // 1
{
	// 2 ����������������
	API_ACCESS_DECLARE(FindController);
public: // ����ӿ�
	// 3 ����ӿ�����
	ENDPOINT_INFO(queryTest) {
		// ����ӿڱ���
		info->summary = API_INIT_CONTRACT_DESC;
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
	}
	 //4 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/contract", queryTest, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, PageQuery, qps);		
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryContract(query));
	}
	ENDPOINT_INFO(queryTest1) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("contract.get.summary");
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PERSON_PARAMS();
	}
	ENDPOINT(API_M_GET, "/person", queryTest1, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, PageQuery_person, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryPerson(query));
	}
		////�����������������������
		//info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("contract.field.name");
		//info->queryParams["name"].addExample("default", String("li ming"));
		//info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("contract.field.id");
		//info->queryParams["id"].addExample("default", String("1"));
		//info->queryParams.add<String>("type").description = ZH_WORDS_GETTER("contract.field.type");
		//info->queryParams["type"].addExample("default", String("the first type"));
		//info->queryParams.add<String>("variety").description = ZH_WORDS_GETTER("contract.field.variety");
		//info->queryParams["variety"].addExample("default", String("the first variety"));
		//info->queryParams.add<String>("date").description = ZH_WORDS_GETTER("contract.field.date");
		//info->queryParams["date"].addExample("default", String("2023/5/16"));
		//info->queryParams.add<String>("condition").description = ZH_WORDS_GETTER("contract.field.condition");
		//info->queryParams["condition"].addExample("default", String("on"));
		//info->queryParams.add<String>("department_m").description = ZH_WORDS_GETTER("contract.field.department_m");
		//info->queryParams["department_m"].addExample("default", String("on"));
		//info->queryParams["department_m"].required = false;
		//info->queryParams.add<String>("department_c").description = ZH_WORDS_GETTER("contract.field.department_c");
		//info->queryParams["department_c"].addExample("default", String(""));
		//info->queryParams["department_c"].required = false;
		//info->queryParams.add<String>("date_end").description = ZH_WORDS_GETTER("contract.field.date_end");
		//info->queryParams["date_end"].addExample("default", String(""));
		//info->queryParams["date_end"].required = false;
		//info->queryParams.add<String>("tip").description = ZH_WORDS_GETTER("contract.field.tip");
		//info->queryParams["tip"].addExample("default", String(""));
		//info->queryParams["tip"].required = false;
		// 
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addSample) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("sample.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/contract", addSample, BODY_DTO(ContractDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddContract(dto));
	}
	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeSample) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("sample.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/contract", removeSample, BODY_DTO(ContractDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemoveContract(dto));
	}

private: // ����ӿ�ִ�к���
	// 5 ����ӿڵ�ִ�к���
	StringJsonVO::Wrapper execQueryContract(const PageQuery::Wrapper& query);
	StringJsonVO::Wrapper execQueryPerson(const PageQuery_person::Wrapper& query);
	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddContract(const ContractDTO::Wrapper& dto);
	// 3.3 ��ʾɾ������
	Uint64JsonVO::Wrapper execRemoveContract(const ContractDTO::Wrapper& dto);
};


#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_TESTCONTROLLER_H_