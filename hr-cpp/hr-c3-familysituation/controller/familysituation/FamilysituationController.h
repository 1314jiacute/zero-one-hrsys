#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Marvin
 @Date: 2023/05/18 19:52:51

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
#ifndef _FAMILYSITUATIONCONTROLLER_H_
#define _FAMILYSITUATIONCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/PageQuery.h"
#include "domain/query/familysituation/FamilysituationQuery.h"
#include "domain/vo/familysituation/FamilysituationVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * ��ͥ���������
 **/
class FamilysituationController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(FamilysituationController);
public: // ����ӿ�
	// �����ѯ����
	ENDPOINT_INFO(queryFamilysituation)
	{
		//�������
		info->summary = ZH_WORDS_GETTER("familysituation.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(FamilysituationPageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("frelationship").description = ZH_WORDS_GETTER("familysituation.field.relationship");
		info->queryParams["frelationship"].addExample("default", String(ZH_WORDS_GETTER("familysituation.field.relationship.dadson")));
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("familysituation.field.name");
		info->queryParams["name"].addExample("default", String("Marvin"));
		// ������
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/query-by-Familysituation", queryFamilysituation, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams))
	{
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(familysituationQuery, FamilysituationQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryByFamilysituation(familysituationQuery, authObject->getPayload()));
	}
	// ������Ӽ�ͥ����ӿ�����
	ENDPOINT_INFO(addFamilysituation)
	{
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("familysituation.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ������ӽӿڴ���
	ENDPOINT(API_M_POST, "/query-by-Familysituation", addFamilysituation, BODY_DTO(FamilysituationDTO::Wrapper, dto))
	{
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddFamilysituation(dto));
	}
	// �����޸Ľӿ�����
	ENDPOINT_INFO(modifyFamilysituation)
	{
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("familysituation.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/query-by-Familysituation", modifyFamilysituation, BODY_DTO(FamilysituationDTO::Wrapper, dto))
	{
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyFamilysituation(dto));
	}
	// ����ɾ���ӿ�����
	ENDPOINT_INFO(deleteFamilysituation)
	{
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("familysituation.del.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ����ɾ���ӿڴ���
	ENDPOINT(API_M_PUT, "/delete-by-Familysituation", deleteFamilysituation, BODY_DTO(FamilysituationDTO::Wrapper, dto))
	{
		// ��Ӧ���
		API_HANDLER_RESP_VO(execDeleteFamilysituation(dto));
	}
	
private: // ����ӿ�ִ�к���
	// ��ҳ��ѯ��Ӧ
	FamilysituationPageJsonVO::Wrapper execQueryByFamilysituation(const FamilysituationQuery::Wrapper& query, const PayloadDTO& payload);
	// ���������Ӧ
	Uint64JsonVO::Wrapper execAddFamilysituation(const FamilysituationDTO::Wrapper& dto);
	// �޸�������Ӧ
	Uint64JsonVO::Wrapper execModifyFamilysituation(const FamilysituationDTO::Wrapper& dto);
	// ɾ��������Ӧ
	Uint64JsonVO::Wrapper execDeleteFamilysituation(const FamilysituationDTO::Wrapper& dto);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FAMILYSITUATIONCONTROLLER_H_