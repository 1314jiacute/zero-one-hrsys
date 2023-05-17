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
#ifndef _SciResultCONTROLLER_H_
#define _SciResultCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/SciResult/SciResultQuery.h"
#include "domain/vo/SciResult/SciResultVO.h"
#include "domain/dto/SciResult/DelSciResultDTO.h"
#include "domain/dto/SciResult/SciResultDTO.h"
#include "domain/dto/SciResult/AddSciResultDTO.h"
#include "domain/dto/SciResult/IntoSciResultDTO.h"
#include <oatpp-swagger/Types.hpp>
#include OATPP_CODEGEN_BEGIN(ApiController) // 0

/**
 * ��ѯ������
 */
class SciResultController : public oatpp::web::server::api::ApiController // 1
{
	// 2 ����������������
	API_ACCESS_DECLARE(SciResultController);
public: // ����ӿ�
	// 3 ����ӿ�����
	ENDPOINT_INFO(querySciResult) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("sample.get.summary");
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(SciResultPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ���������ѯ����
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("sample.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = false;
	}
	// 4 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/SciResult", querySciResult, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, SciResultQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryTest(query));
	}

	//����ָ��Ա�����гɹ�(��������)
	ENDPOINT_INFO(AddSciResult) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("sample.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/SciResult/add", AddSciResult, BODY_DTO(AddSciResultDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddSciResult(dto));
	}


	// ɾ��Ա�����гɹ�(֧������ɾ��)
	ENDPOINT_INFO(DelSciResult) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("sample.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ��������ɾ���ӿڴ���
	ENDPOINT(API_M_POST, "/SciResult/del", DelSciResult, BODY_DTO(DelSciResultDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execDelSciResult(dto));
	}

	//����ָ��Ա�����гɹ�
	ENDPOINT_INFO(postFile) {
		info->summary = ZH_WORDS_GETTER("Into.fileinto");
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		info->queryParams["suffix"].description = ZH_WORDS_GETTER("sciresult.file.suffix");
		info->queryParams["suffix"].addExample("xlsx", String(".xlsx"));
	}
	// �����ļ��ϴ��˵㴦��
	ENDPOINT(API_M_POST, "/sciresult/file", postFile, BODY_STRING(String, body), QUERY(String, suffix)) {
		// ִ���ļ������߼�
		API_HANDLER_RESP_VO(execIntoSciResult(body, suffix));
	}






private: // ����ӿ�ִ�к���
	// 5 ����ӿڵ�ִ�к���
	//�����ѯִ�к���
	SciResultPageJsonVO::Wrapper execQueryTest(const SciResultQuery::Wrapper& query);
	//�����������к���
	Uint64JsonVO::Wrapper execAddSciResult(const AddSciResultDTO::Wrapper& dto);
	//����ɾ��ִ�к���
	Uint64JsonVO::Wrapper execDelSciResult(const DelSciResultDTO::Wrapper& dto);
	//���嵼��ִ�к���
	StringJsonVO::Wrapper execIntoSciResult(const String body, const String suffix);
};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_CONTRACTCONTROLLER_H_