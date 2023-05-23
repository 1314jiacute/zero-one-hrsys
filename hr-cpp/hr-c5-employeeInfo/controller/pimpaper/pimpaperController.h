
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: tml
 @Date: 2022/10/25 0:27:04

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
#ifndef _PIMPAPER_CONTROLLER_
#define _PIMPAPER_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/pimpaper/PimpaperQuery.h"
#include "domain/dto/pimpaper/PimpaperDTO.h"
#include "domain/vo/pimpaper/PimpaperVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class PimpaperController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(PimpaperController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(pimpaperQuery) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("pimpaper.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(PimpaperPageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		//Ա������
		info->queryParams.add<String>("pimpersonname").description = ZH_WORDS_GETTER("pimpaper.field.pimpersonname");
		info->queryParams["pimpersonname"].addExample("default", String("LiHua"));
		//Ա�����
		info->queryParams.add<String>("ygbh").description = ZH_WORDS_GETTER("pimpaper.field.ygbh");
		info->queryParams["ygbh"].addExample("default", String("1234"));
		//֤������
		info->queryParams.add<String>("zjhm").description = ZH_WORDS_GETTER("pimpaper.field.zjhm");
		info->queryParams["zjhm"].addExample("default", String("12345"));
		info->queryParams["zjhm"].required = false;
		//��֯
		info->queryParams.add<String>("zzdzs").description = ZH_WORDS_GETTER("pimpaper.field.zzdzs");
		info->queryParams["zzdzs"].addExample("default", String("HuaWeiZhongBu"));
		info->queryParams["zzdzs"].required = false;
		//����
		info->queryParams.add<String>("ormorgsectorname").description = ZH_WORDS_GETTER("pimpaper.field.ormorgsectorname");
		info->queryParams["ormorgsectorname"].addExample("default", String("Development department"));
		info->queryParams["ormorgsectorname"].required = false;
		//Ա��״̬
		info->queryParams.add<String>("ygzt").description = ZH_WORDS_GETTER("pimpaper.field.ygzt");
		info->queryParams["ygzt"].addExample("default", String("working"));
		info->queryParams["ygzt"].required = false;
		//�ڸ�״̬
		info->queryParams.add<String>("zgzt").description = ZH_WORDS_GETTER("pimpaper.field.zgzt");
		info->queryParams["zgzt"].addExample("default", String("yes"));
		info->queryParams["zgzt"].required = false;
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/employee-info/pimpaper", pimpaperQuery, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(query, PimpaperQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryPimpaper(query));
	}

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addPimpaper) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("pimpaper.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/employee-info/add-pimpaper", addPimpaper, BODY_DTO(PimpaperDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddPimpaper(dto));
	}

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removePimpaper) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("pimpaper.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/employee-info/remove-pimpaper", removePimpaper, BODY_DTO(PimpaperDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemovePimpaper(dto));
	}
private:
	// 3.3 ��ʾ��ҳ��ѯ����
	PimpaperPageJsonVO::Wrapper execQueryPimpaper(const PimpaperQuery::Wrapper& query);
	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddPimpaper(const PimpaperDTO::Wrapper& dto);
	// 3.3 ��ʾɾ������
	Uint64JsonVO::Wrapper execRemovePimpaper(const PimpaperDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PIMPAPER_CONTROLLER_