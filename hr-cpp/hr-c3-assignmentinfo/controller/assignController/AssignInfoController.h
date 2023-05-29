#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ahao
 @Date: 2023/5/22 14:58:43

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
#ifndef _ASSIGN_CONTROLLER_
#define _ASSiGN_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/assignInfo/AssignInfoDTO.h"
#include "domain/vo/assignInfo/AssignInfoVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "domain/query/assignInfo/AssignInfoQuery.h"
#include "domain/query/PageQuery.h"
#include "domain/query/assignInfo/AssignInfoQueryDetail.h"
#include "domain/query/assignInfo/AssignExportQuery.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

/*
	�ж�string�Ƿ�Ϊ��Ȼ��
*/
bool isNum(string str1);

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ����������Ա��������Ϣʹ��
 */
class AssignInfoController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(AssignInfoController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(assignQuery) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("employee.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AssignInfoPageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("employee.field.id");
		info->queryParams["id"].addExample("default", String("114514"));
		info->queryParams["id"].required = true;
	}
	ENDPOINT(API_M_GET, "/query-assign-info", assignQuery, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, AssignInfoQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAssignQuery(userQuery));
	}
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addAssignInfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("employee.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/add-assign-info", addAssignInfo, BODY_DTO(AssignInfoDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddAssignInfo(dto));
	}
	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(deleteAssignInfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("employee.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/delete-assign-info", deleteAssignInfo, BODY_DTO(AssignInfoDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execDeleteAssignInfo(dto));
	}
	// 3.1 �����޸Ľӿ�����
	ENDPOINT_INFO(modifyAssignInfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("employee.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/modify-assign-info", modifyAssignInfo, BODY_DTO(AssignInfoDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyAssignInfo(dto));
	}
	// [����] ����һ�����ļ��ϴ��ӿ�
	ENDPOINT_INFO(importAssignInfo) {
		info->summary = ZH_WORDS_GETTER("employee.post.upload");
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
		ENDPOINT(API_M_POST, "/upload-assign-info", importAssignInfo, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
			/* ����multipart���� */
			auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
			/* ����multipart��ȡ�� */
			multipart::Reader multipartReader(multipartContainer.get());
			/* ���ö�ȡ����ȡ���ֶ� */
			multipartReader.setPartReader("id", multipart::createInMemoryPartReader(-1 /* max-data-size */));
			multipartReader.setPartReader("assign", multipart::createInMemoryPartReader(-1 /* max-data-size */));
			multipartReader.setPartReader("type", multipart::createInMemoryPartReader(-1 /* max-data-size */));
			multipartReader.setPartReader("organize", multipart::createInMemoryPartReader(-1 /* max-data-size */));
			multipartReader.setPartReader("depart", multipart::createInMemoryPartReader(-1 /* max-data-size */));
			multipartReader.setPartReader("job", multipart::createInMemoryPartReader(-1 /* max-data-size */));
			multipartReader.setPartReader("post", multipart::createInMemoryPartReader(-1 /* max-data-size */));
			multipartReader.setPartReader("startTime", multipart::createInMemoryPartReader(-1 /* max-data-size */));
			multipartReader.setPartReader("endTime", multipart::createInMemoryPartReader(-1 /* max-data-size */));
			/* ���ö�ȡ����ȡ�ļ����ļ� */
			multipartReader.setPartReader("file", multipart::createFilePartReader("public/static/file/test.png"));
			/* ��ȡ�������е����� */
			request->transferBody(&multipartReader);
			/* ��ӡpart���� */
			OATPP_LOGD("Multipart", "parts_count=%d", multipartContainer->count());
			/* ��ȡ������ */
			auto id = multipartContainer->getNamedPart("id");
			auto assign = multipartContainer->getNamedPart("assign");
			auto etype = multipartContainer->getNamedPart("etype");
			auto organize = multipartContainer->getNamedPart("organize");
			auto depart = multipartContainer->getNamedPart("depart");
			auto job = multipartContainer->getNamedPart("job");
			auto post = multipartContainer->getNamedPart("post");
			auto startTime = multipartContainer->getNamedPart("startTime");
			auto endTime = multipartContainer->getNamedPart("endTime");
			/* ���Ա������Ƿ���ȷ */
			OATPP_ASSERT_HTTP(id, Status::CODE_400, "id is null");
			OATPP_ASSERT_HTTP(assign, Status::CODE_400, "assign is null");
			OATPP_ASSERT_HTTP(etype, Status::CODE_400, "etype is null");
			OATPP_ASSERT_HTTP(organize, Status::CODE_400, "organize is null");
			OATPP_ASSERT_HTTP(depart, Status::CODE_400, "depart is null");
			OATPP_ASSERT_HTTP(job, Status::CODE_400, "job is null");
			OATPP_ASSERT_HTTP(post, Status::CODE_400, "post is null");
			OATPP_ASSERT_HTTP(startTime, Status::CODE_400, "startTime is null");
			OATPP_ASSERT_HTTP(endTime, Status::CODE_400, "endTime is null");
			/* ��ӡӦ������ */
			OATPP_LOGD("Multipart", "id='%s'", id->getPayload()->getInMemoryData()->c_str());
			OATPP_LOGD("Multipart", "assign='%s'", assign->getPayload()->getInMemoryData()->c_str());
			OATPP_LOGD("Multipart", "etype='%s'", etype->getPayload()->getInMemoryData()->c_str());
			OATPP_LOGD("Multipart", "organize='%s'", organize->getPayload()->getInMemoryData()->c_str());
			OATPP_LOGD("Multipart", "depart='%s'", depart->getPayload()->getInMemoryData()->c_str());
			OATPP_LOGD("Multipart", "job='%s'", job->getPayload()->getInMemoryData()->c_str());
			OATPP_LOGD("Multipart", "post='%s'", post->getPayload()->getInMemoryData()->c_str());
			OATPP_LOGD("Multipart", "startTime='%s'", startTime->getPayload()->getInMemoryData()->c_str());
			OATPP_LOGD("Multipart", "endTime='%s'", endTime->getPayload()->getInMemoryData()->c_str());
			/* ��ȡ�ļ����� */
			auto filePart = multipartContainer->getNamedPart("file");
			/* �����ļ��Ƿ��ȡ�� */
			OATPP_ASSERT_HTTP(filePart, Status::CODE_400, "file is null");
			/* ��ӡ�ļ����� */
			OATPP_LOGD("Multipart", "file='%s'", filePart->getFilename()->c_str());
			/* ��ӦOK */
			return createResponse(Status::CODE_200, "OK");
		}

	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(assignQueryDetail) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("employee.get.detail");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AssignInfoJsonVO);
		//��ϸ��ѯ������Ϣ����Ҫ��ҳ
		//// �����ҳ��������
		//API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("employee.field.id");
		info->queryParams["id"].addExample("default", String("114514"));
		info->queryParams["id"].required = true;
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/query-assign-info-detail", assignQueryDetail, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, AssignInfoQueryDetail, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAssignQueryDetail(userQuery, authObject->getPayload()));
	}

	ENDPOINT_INFO(exportAssignInfo) {
		info->summary = ZH_WORDS_GETTER("export.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("employee.field.id");
		info->queryParams["id"].addExample("default", String("0000001"));
		info->queryParams["id"].required = true;
	}
	ENDPOINT(API_M_GET, "/export-assign-info", exportAssignInfo, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		API_HANDLER_QUERY_PARAM(query, AssignExportQuery, qps);
		API_HANDLER_RESP_VO(execExportAssign(query));
	}

private:
	// 3.3 ��ʾ��������
	StringJsonVO::Wrapper execAddAssignInfo(const AssignInfoDTO::Wrapper& dto);
	StringJsonVO::Wrapper execDeleteAssignInfo(const AssignInfoDTO::Wrapper& dto);
	//ImportAssignInfoJsonVO::Wrapper execImportAssignInfo(const ImportAssignInfoDTO::Wrapper& dto);
	AssignInfoPageJsonVO::Wrapper execAssignQuery(const AssignInfoQuery::Wrapper& query);
	AssignInfoJsonVO::Wrapper execAssignQueryDetail(const AssignInfoQueryDetail::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execModifyAssignInfo(const AssignInfoDTO::Wrapper& dto);
	StringJsonVO::Wrapper execExportAssign(const AssignExportQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _ASSIGN_CONTROLLER_