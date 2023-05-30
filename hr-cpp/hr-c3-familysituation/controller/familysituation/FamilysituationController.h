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

// ����ģ��
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/familysituation/FamilysituationQuery.h"
#include "domain/dto/familysituation/FamilysituationDTO.h"
#include "domain/dto/familysituation/ImportfamilysituationDTO.h"
#include "domain/vo/familysituation/FamilysituationVO.h"

// API����
#include "ApiHelper.h"
#include "SimpleDateTimeFormat.h"
#include "CharsetConvertHepler.h"

// �ļ��ϴ�
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

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
 		API_DEF_ADD_RSP_JSON_WRAPPER(FamilysituationPageJsonVO);
 		// �����ҳ��������
 		API_DEF_ADD_PAGE_PARAMS();
		info->queryParams.add<String>("personid").description = ZH_WORDS_GETTER("familysituation.field.personid");
		info->queryParams["personid"].addExample("default", String("1"));
 	}
 	// �����ѯ�ӿڴ���
 	ENDPOINT(API_M_GET, "/query-by-family-situation", queryFamilysituation, QUERIES(QueryParams, queryParams))
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
 		info->queryParams.add<String>("personid").description = ZH_WORDS_GETTER("familysituation.field.personid");
 		info->queryParams["personid"].addExample("default", String("1"));
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("familysituation.field.id");
		info->queryParams["id"].addExample("default", String(1));
 	}
 	// �����ѯָ����ͥ����ӿڴ���
 	ENDPOINT(API_M_GET, "/queryOne-by-family-situation", queryOneFamilysituation, QUERIES(QueryParams, queryParams))
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
	ENDPOINT(API_M_POST, "/add-by-family-situation", addFamilysituation, BODY_DTO(FamilysituationDTO::Wrapper, dto))
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
	ENDPOINT(API_M_PUT, "/modify-by-family-situation", modifyFamilysituation, BODY_DTO(FamilysituationDTO::Wrapper, dto))
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
	ENDPOINT(API_M_DEL, "/remove-by-family-situation", removeFamilysituation, BODY_DTO(FamilysituationDTO::Wrapper, dto))
	{
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemoveFamilysituation(dto));
	}
	// ���嵼��ӿ�����
	ENDPOINT_INFO(importFile)
	{
		info->summary = ZH_WORDS_GETTER("familysituation.import-file.summary");
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		info->queryParams["suffix"].description = ZH_WORDS_GETTER("familysituation.import-file.suffix");
		info->queryParams["suffix"].addExample("xlsx", String(".xlsx"));
	}
	// ���嵼��ӿڴ���
	ENDPOINT(API_M_POST, "/import-by-family-situation", importFile, BODY_STRING(String, body), QUERY(String, suffix))
	{
		// ִ���ļ�����ͽ����߼�
		API_HANDLER_RESP_VO(executeImportFamilysituation(body, suffix));
	}
	
	// ���嵼���ӿ�����
	ENDPOINT_INFO(exportFamilysituation)
	{
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("familysituation.export.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		info->queryParams["url"].description = ZH_WORDS_GETTER("familysituation.export-file.summary");
		info->queryParams["url"].addExample("xlsx", String(".xlsx"));
	}
	// ���嵼���ӿڴ���
	ENDPOINT(API_M_GET, "/export-by-family-situation", exportFamilysituation, QUERY(String, url))
	{
		// ��Ӧ���
		API_HANDLER_RESP_VO(execExportFamilysituation(url));
	}

private: // ����ӿ�ִ�к���
	// ��ѯ������Ӧ
	FamilysituationPageJsonVO::Wrapper execQueryByFamilysituation(const FamilysituationQuery::Wrapper& query);
	// ָ����ѯ������Ӧ
	FamilysituationJsonVO::Wrapper execOneQueryFamilysituation(const FamilysituationQuery::Wrapper& query);
	// ���������Ӧ
	Uint64JsonVO::Wrapper execAddFamilysituation(const FamilysituationDTO::Wrapper& dto);
	// �޸�������Ӧ
	Uint64JsonVO::Wrapper execModifyFamilysituation(const FamilysituationDTO::Wrapper& dto);
	// ɾ��������Ӧ
	Uint64JsonVO::Wrapper execRemoveFamilysituation(const FamilysituationDTO::Wrapper& dto);
	// ����������Ӧ
	StringJsonVO::Wrapper executeImportFamilysituation(const String& fileBody, const String& suffix);
	// ����������Ӧ
	StringJsonVO::Wrapper execExportFamilysituation(const String& url);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FAMILYSITUATIONCONTROLLER_H_