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
#include "domain/query/familysituation/FamilysituationQuery.h"
#include "domain/dto/familysituation/FamilysituationDTO.h"
#include "domain/dto/familysituation/ImportfamilysituationDTO.h"
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
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(FamilySituationPageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/query-by-Familysituation", queryFamilysituation, QUERIES(QueryParams, queryParams))
	{
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(familysituationQuery, FamilysituationQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryByFamilysituation(familysituationQuery));

	}
	// �����ѯָ����ͥ����ӿ�����
	ENDPOINT_INFO(queryOneFamilysituation)
	{
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("familysituation.getone.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(FamilysituationJsonVO);
		info->queryParams.add<String>("id").description = "ID";
		info->queryParams["id"].addExample("default", String("1"));
	}
	// �����ѯָ����ͥ����ӿڴ���
	ENDPOINT(API_M_GET, "/query-by-OneFamilysituation", queryOneFamilysituation, QUERIES(QueryParams, queryParams))
	{
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(oneQuery, FamilysituationQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execOneQueryFamilysituation(oneQuery));
	}
	// ������Ӽ�ͥ����ӿ�����
	ENDPOINT_INFO(addFamilysituation)
	{
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("familysituation.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);

	}
	// ������ӽӿڴ���
	ENDPOINT(API_M_POST, "/add-by-Familysituation", addFamilysituation, BODY_DTO(FamilysituationDTO::Wrapper, dto))
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
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/modify-by-Familysituation", modifyFamilysituation, BODY_DTO(FamilysituationDTO::Wrapper, dto))
	{
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyFamilysituation(dto));
	}
	// ����ɾ���ӿ�����
	ENDPOINT_INFO(removeFamilysituation)
	{
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("familysituation.del.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// ����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/remove-by-Familysituation", removeFamilysituation, BODY_DTO(FamilysituationDTO::Wrapper, dto))
	{
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemoveFamilysituation(dto));
	}
	// ���嵼��ӿ�����
	ENDPOINT_INFO(importFamilysituation)
	{
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("familysituation.import.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// ���嵼��ӿڴ���
	ENDPOINT(API_M_POST, "/import-by-Familysituation", importFamilysituation, BODY_DTO(ImportfamilysituationDTO::Wrapper, dto))
	{
		// ��Ӧ���
		API_HANDLER_RESP_VO(execImportFamilysituation(dto));
	}
	// ���嵼���ӿ�����
	ENDPOINT_INFO(exportFamilysituation)
	{
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("familysituation.export.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(FamilysituationJsonVO);
	}
	// ���嵼���ӿڴ���
	ENDPOINT(API_M_GET, "/export-by-Familysituation", exportFamilysituation, BODY_DTO(ImportfamilysituationDTO::Wrapper, dto))
	{
		// ��Ӧ���
		API_HANDLER_RESP_VO(execExportFamilysituation(dto));
	}

private: // ����ӿ�ִ�к���
	// ��ѯ������Ӧ
	FamilySituationPageJsonVO::Wrapper execQueryByFamilysituation(const FamilysituationQuery::Wrapper& query);
	// ָ����ѯ������Ӧ
	FamilysituationJsonVO::Wrapper execOneQueryFamilysituation(const FamilysituationQuery::Wrapper& query);
	// ���������Ӧ
	StringJsonVO::Wrapper execAddFamilysituation(const FamilysituationDTO::Wrapper& dto);
	// �޸�������Ӧ
	StringJsonVO::Wrapper execModifyFamilysituation(const FamilysituationDTO::Wrapper& dto);
	// ɾ��������Ӧ
	StringJsonVO::Wrapper execRemoveFamilysituation(const FamilysituationDTO::Wrapper& dto);
	// ����������Ӧ
	StringJsonVO::Wrapper execImportFamilysituation(const ImportfamilysituationDTO::Wrapper& dto);
	// ����������Ӧ
	FamilysituationJsonVO::Wrapper execExportFamilysituation(const ImportfamilysituationDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FAMILYSITUATIONCONTROLLER_H_