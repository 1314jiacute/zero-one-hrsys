#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/17 16:37:51

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
#ifndef _POSTQUERY_CONTROLLER_
#define _POSTQUERY_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/postSet/PostDetailQuery.h"
#include "domain/dto/postSet/PostDetailDTO.h"
#include "domain/vo/postSet/PostDetailVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��λ���� - ��ѯָ����λ���������
 * ����ֵ : PostDetailPageJsonVO - ����һ����ҳ��λ��ѯ�б�
 * ������ : rice
 */
class PostQueryController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(PostQueryController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryByQuerySort) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("orgmanage.controller.postQuery");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(PostDetailPageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("queryPostName").description = u8"��ѯ��λ";
		info->queryParams["queryPostName"].addExample("default", String(u8"���¹����"));
		info->queryParams["queryPostName"].required = true;
		info->queryParams.add<String>("sortTypeAndMethod").description = u8"��������Լ��������";
		info->queryParams["sortTypeAndMethod"].addExample("default", String(u8"xh,ASC"));
		info->queryParams["sortTypeAndMethod"].required = true;
		API_DEF_ADD_AUTH();
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, PATH_TO_JOBSET("/query-by-query-sort"), queryByQuerySort, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(postDetailQuery, PostDetailQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryByQuerySort(postDetailQuery));
	}
	
private:
	// ��ѯָ����λ����
	PostDetailPageJsonVO::Wrapper execQueryByQuerySort(const PostDetailQuery::Wrapper& postDetailQuery);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _POSTQUERY_CONTROLLER_