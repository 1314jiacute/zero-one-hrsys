#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/15 11:14:40

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
#ifndef _WORKHISTORYCONTROLLER_H_
#define _WORKHISTORYCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "domain/query/work-history/WorkHistoryPageQuery.h"
#include "domain/vo/work-history/WorkHistoryFindVO.h"
#include "domain/dto/work-history/AddWorkHistoryDTO.h"
#include "domain/dto/work-history/DelWorkHistoryDTO.h"
#include "domain/vo/work-history/WorkHistoryExportVO.h"
#include "domain/query/work-history/WorkHistoryExportQuery.h"
#include "oatpp-swagger/Model.hpp"
#include "oatpp-swagger/Types.hpp"
using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)

class WorkHistoryController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(WorkHistoryController);
public: // ����ӿ�
	//  �����ѯ�ӿ�����
	ENDPOINT_INFO(queryWorkHistory) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("workhistory.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(WorkHistoryFindVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("workhistory.field.pimpersonid");
		info->queryParams["pimpersonid"].addExample("default", String("6611212223"));
		info->queryParams["pimpersonid"].required = false;
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/workhistory/select", queryWorkHistory, QUERIES(QueryParams, qps)) {
		//������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, WorkHistoryPageQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryWorkHistory(query));
	}

	// ���������ӿ�����
	ENDPOINT_INFO(addWorkHistory) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("workhistory.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ���������ӿڴ���
	ENDPOINT(API_M_POST, "/workhistory/add", addWorkHistory, BODY_DTO(AddWorkHistoryDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddWorkHistory(dto));
	}

	// ��������ɾ���ӿ�����
	ENDPOINT_INFO(delWorkHistory) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("workhistory.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ��������ɾ���ӿڴ���
	ENDPOINT(API_M_POST, "/workhistory/delete", delWorkHistory, BODY_DTO(DelWorkHistoryDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execDelWorkHistory(dto));
	}

	// ����һ�����ļ�����ӿ�
	ENDPOINT_INFO(postFile) {
		info->summary = ZH_WORDS_GETTER("workhistory.file.summary");
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		info->queryParams["suffix"].description = ZH_WORDS_GETTER("workhistory.file.suffix");
		info->queryParams["suffix"].addExample("xlsx", String(".xlsx"));
	}
	// �����ļ��ϴ��˵㴦��
	ENDPOINT(API_M_POST, "/workhistory/file", postFile, BODY_STRING(String, body), QUERY(String, suffix)) {
		// ִ���ļ������߼�
		API_HANDLER_RESP_VO(execIntoWorkHistory(body, suffix));
	}

	//�ļ������ӿ�
	ENDPOINT_INFO(exportWorkHistory) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("workhistory.export.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("workhistory.field.pimpersonid");
		info->queryParams["pimpersonid"].addExample("default", String("6611212223"));
		info->queryParams["pimpersonid"].required = false;
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/workhistory/export", exportWorkHistory, QUERIES(QueryParams, qps)) {
		//������������������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, WorkHistoryExportQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execExportWorkHistory(query));
	}


private: 
	
	// �����ҳ��ѯִ�к���
	WorkHistoryFindVO::Wrapper execQueryWorkHistory(const WorkHistoryPageQuery::Wrapper& query);

	//��������ִ�к���
	Uint64JsonVO::Wrapper execAddWorkHistory(const AddWorkHistoryDTO::Wrapper& dto);

	//����ɾ��ִ�к���
	Uint64JsonVO::Wrapper execDelWorkHistory(const DelWorkHistoryDTO::Wrapper& dto);

	//���嵼��ִ�к���
	StringJsonVO::Wrapper execIntoWorkHistory(const String body, const String suffix);

	//���嵼��ִ�к���
	StringJsonVO::Wrapper execExportWorkHistory(const WorkHistoryExportQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_WORKHISTORYCONTROLLER_H_