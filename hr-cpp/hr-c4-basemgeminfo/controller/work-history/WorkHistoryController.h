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
	ENDPOINT(API_M_POST, "/workhistory/upload", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		/* ����multipart���� */
		auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
		/* ����multipart��ȡ�� */
		multipart::Reader multipartReader(multipartContainer.get());
		/* ���ö�ȡ����ȡ���ֶ� */
		multipartReader.setPartReader("servebegintime", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("serveendtime", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("workunit", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("bm", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("zw", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("gw", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("ormrankid", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("pimpersionid", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		/* ���ö�ȡ����ȡ�ļ����ļ� */
		multipartReader.setPartReader("file", multipart::createFilePartReader("public/static/file/test.png"));
		/* ��ȡ�������е����� */
		request->transferBody(&multipartReader);
		/* ��ӡpart���� */
		OATPP_LOGD("Multipart", "parts_count=%d", multipartContainer->count());
		/* ��ȡ������ */
		auto servebegintime = multipartContainer->getNamedPart("servebegintime");
		auto serveendtime = multipartContainer->getNamedPart("serveendtime");
		auto workunit = multipartContainer->getNamedPart("workunit");
		auto bm = multipartContainer->getNamedPart("bm");
		auto zw = multipartContainer->getNamedPart("zw");
		auto gw = multipartContainer->getNamedPart("gw");
		auto ormrankid = multipartContainer->getNamedPart("ormrankid");
		auto pimpersionid = multipartContainer->getNamedPart("pimpersionid");
		/* ���Ա������Ƿ���ȷ */
		OATPP_ASSERT_HTTP(servebegintime, Status::CODE_400, "servebegintime is null");
		OATPP_ASSERT_HTTP(serveendtime, Status::CODE_400, "serveendtime is null");
		OATPP_ASSERT_HTTP(workunit, Status::CODE_400, "workunit is null");
		OATPP_ASSERT_HTTP(bm, Status::CODE_400, "bm is null");
		OATPP_ASSERT_HTTP(zw, Status::CODE_400, "zw is null");
		OATPP_ASSERT_HTTP(gw, Status::CODE_400, "gw is null");
		OATPP_ASSERT_HTTP(ormrankid, Status::CODE_400, "ormrankid is null");
		OATPP_ASSERT_HTTP(pimpersionid, Status::CODE_400, "pimpersionid is null");
		/* ��ӡӦ������ */
		OATPP_LOGD("Multipart", "servebegintime='%s'", servebegintime->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "serveendtime='%s'", serveendtime->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "workunit='%s'", workunit->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "bm='%s'", bm->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "zw='%s'", zw->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "gw='%s'", gw->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "ormrankid='%s'", ormrankid->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "pimpersionid='%s'", pimpersionid->getPayload()->getInMemoryData()->c_str());
		/* ��ȡ�ļ����� */
		auto filePart = multipartContainer->getNamedPart("file");
		/* �����ļ��Ƿ��ȡ�� */
		OATPP_ASSERT_HTTP(filePart, Status::CODE_400, "file is null");
		/* ��ӡ�ļ����� */
		OATPP_LOGD("Multipart", "file='%s'", filePart->getFilename()->c_str());
		/* ��ӦOK */
		return createResponse(Status::CODE_200, "OK");
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
	StringJsonVO::Wrapper execExportWorkHistory(const WorkHistoryExportQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_WORKHISTORYCONTROLLER_H_