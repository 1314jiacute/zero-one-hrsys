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
#include "domain/query/contract/ContractQuery.h"
#include "domain/query/person/PersonQuery.h"
#include "domain/dto/contract/ContractDTO.h"
#include "domain/vo/contract/ContractVO.h"
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
public: 
	// 3.1 �����ѯ��ͬ�ӿ�����
	ENDPOINT_INFO(queryContract) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("contract.get.summary");
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
	}
	 //3.2 �����ѯ��ͬ�ӿڶ˵�
	ENDPOINT(API_M_GET, "/query-contract", queryContract, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, ContractQuery, qps);		
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryContract(query));
	}
	//3.1 �����ѯ������Ϣ�ӿ�����
	ENDPOINT_INFO(queryPerson) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("person.get.summary");
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PERSON_PARAMS();
	}
	//3.2 �����ѯ������Ϣ�ӿڴ���
	ENDPOINT(API_M_GET, "/query-person", queryPerson, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, PersonQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryPerson(query));
	}
	// 3.1 ����������ͬ�ӿ�����
	ENDPOINT_INFO(addContract) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("contract.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ����������ͬ�ӿڴ���
	ENDPOINT(API_M_POST, "/add-contract", addContract, BODY_DTO(ContractDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddContract(dto));
	}
	// 3.1 ����ɾ����ͬ�ӿ�����
	ENDPOINT_INFO(removeContract) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("contract.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ����ɾ����ͬ�ӿڴ���
	ENDPOINT(API_M_DEL, "/remove-contract", removeContract, BODY_DTO(ContractDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemoveContract(dto));
	}

private: // ����ӿ�ִ�к���

	// 3.3 ��ʾ��ѯ��ͬ��Ϣ
	StringJsonVO::Wrapper execQueryContract(const ContractQuery::Wrapper& query);
	// 3.3 ��ʾ��ѯ������Ϣ
	StringJsonVO::Wrapper execQueryPerson(const PersonQuery::Wrapper& query);
	// 3.3 ��ʾ������ͬ����
	Uint64JsonVO::Wrapper execAddContract(const ContractDTO::Wrapper& dto);
	// 3.3 ��ʾɾ����ͬ����
	Uint64JsonVO::Wrapper execRemoveContract(const ContractDTO::Wrapper& dto);
};


#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_TESTCONTROLLER_H_