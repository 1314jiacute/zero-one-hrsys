#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/16 14:48:37

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
#ifndef _LEGALENTITYMAICONTROLLER_H_
#define _LEGALENTITYMAICONTROLLER_H_

#include "domain/query/LegalEntityMai/LegalEntityMaiQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/LegalEntityMai/LegalEntityMaiDTO.h"
#include "domain/vo/LegalEntityMai/LegalEntityMaiVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController)
namespace multipart = oatpp::web::mime::multipart;

/* ��������ά����������*/
class LegalEntityMaiController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(LegalEntityMaiController);
public: // ����ӿ�
	// �����ѯ����������Ϣ�ӿ�����
	ENDPOINT_INFO(queryLEM) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("LegalEntityMai.query.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(LegalEntityMaiPageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		info->queryParams.add<String>("ORMSIGNORGID").description = ZH_WORDS_GETTER("LegalEntityMai.field.id");
		info->queryParams["ORMSIGNORGID"].addExample("default", String("11F28C41-1D50-4503-B925-D86D1F70A1D2"));
		info->queryParams.add<String>("UPDATEMAN").description = ZH_WORDS_GETTER("LegalEntityMai.field.updateman");
		info->queryParams["UPDATEMAN"].addExample("default", String("guest"));
		info->queryParams.add<String>("CREATEMAN").description = ZH_WORDS_GETTER("LegalEntityMai.field.createman");
		info->queryParams["CREATEMAN"].addExample("default", String("1944DE89-8E28-4D10-812C-CAEEAAE8A927"));
		info->queryParams.add<String>("CREATEDATE").description = ZH_WORDS_GETTER("LegalEntityMai.field.createdate");
		info->queryParams["CREATEDATE"].addExample("default", String("2019-09-10 20:45:00"));
		info->queryParams.add<String>("ORMSIGNORGNAME").description = ZH_WORDS_GETTER("LegalEntityMai.field.name");
		info->queryParams["ORMSIGNORGNAME"].addExample("default", String(ZH_WORDS_GETTER("LegalEntityMai.sample.name")));
		info->queryParams.add<String>("UPDATEDATE").description = ZH_WORDS_GETTER("LegalEntityMai.field.updatedate");
		info->queryParams["UPDATEDATE"].addExample("default", String("2020-05-29 10:49:53"));
		info->queryParams.add<String>("ORGCODE").description = ZH_WORDS_GETTER("LegalEntityMai.field.orgcode");
		info->queryParams["ORGCODE"].addExample("default", String("104"));
	}
	// �����ѯ����������Ϣ�ӿڴ���
	ENDPOINT(API_M_GET, "/QueryLEM", queryLEM, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(legalEntityMaiQuery, LegalEntityMaiQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryLEM(legalEntityMaiQuery));
	}

	// ������·���������Ϣ�ӿ�����
	ENDPOINT_INFO(updateLEM) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("LegalEntityMai.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ������·���������Ϣ�ӿڴ���
	ENDPOINT(API_M_PUT, "/UpdateLEM", updateLEM, BODY_DTO(LegalEntityMaiDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execUpdateLEM(dto));
	}

	// ����������������ӿ�����
	ENDPOINT_INFO(addLEM) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("LegalEntityMai.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/AddLEM", addLEM, BODY_DTO(LegalEntityMaiDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddLEM(dto));
	}

	// ����ɾ����������ӿ�����
	ENDPOINT_INFO(removeLEM) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("LegalEntityMai.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_DEL, "/RemoveLEM", removeLEM, BODY_DTO(LegalEntityMaiDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemoveLEM(dto));
	}

	// �ļ�����
	// [����] ����һ�����ļ��ϴ��ӿ�
	ENDPOINT(API_M_POST, "/upload", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		/* ����multipart���� */
		auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
		/* ����multipart��ȡ�� */
		multipart::Reader multipartReader(multipartContainer.get());
		/* ���ö�ȡ����ȡ���ֶ� */
		multipartReader.setPartReader("nickname", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("age", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		/* ���ö�ȡ����ȡ�ļ����ļ� */
		multipartReader.setPartReader("file", multipart::createFilePartReader("public/static/file/test.png"));
		/* ��ȡ�������е����� */
		request->transferBody(&multipartReader);
		/* ��ӡpart���� */
		OATPP_LOGD("Multipart", "parts_count=%d", multipartContainer->count());
		/* ��ȡ������ */
		auto nickname = multipartContainer->getNamedPart("nickname");
		auto age = multipartContainer->getNamedPart("age");
		/* ���Ա������Ƿ���ȷ */
		OATPP_ASSERT_HTTP(nickname, Status::CODE_400, "nickname is null");
		OATPP_ASSERT_HTTP(age, Status::CODE_400, "age is null");
		/* ��ӡӦ������ */
		OATPP_LOGD("Multipart", "nickname='%s'", nickname->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "age='%s'", age->getPayload()->getInMemoryData()->c_str());
		/* ��ȡ�ļ����� */
		auto filePart = multipartContainer->getNamedPart("file");
		/* �����ļ��Ƿ��ȡ�� */
		OATPP_ASSERT_HTTP(filePart, Status::CODE_400, "file is null");
		/* ��ӡ�ļ����� */
		OATPP_LOGD("Multipart", "file='%s'", filePart->getFilename()->c_str());
		/* ��ӦOK */
		return createResponse(Status::CODE_200, "OK");
	}
	// [����] ����һ�����ļ��ϴ��ӿ�
	ENDPOINT(API_M_POST, "/upload-more", uploadFileMore, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		/* ����multipart���� */
		auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
		/* ����multipart��ȡ�� */
		multipart::Reader multipartReader(multipartContainer.get());
		/* ���ö�ȡ����ȡ�ļ����ļ� */
		multipartReader.setPartReader("file0", multipart::createFilePartReader("public/static/file/test1.png"));
		multipartReader.setPartReader("file1", multipart::createFilePartReader("public/static/file/test2.png"));
		/* ��ȡ�������е����� */
		request->transferBody(&multipartReader);
		/* ��ȡ�ļ����� */
		auto file0 = multipartContainer->getNamedPart("file0");
		auto file1 = multipartContainer->getNamedPart("file1");
		/* �����ļ��Ƿ��ȡ�� */
		OATPP_ASSERT_HTTP(file0, Status::CODE_400, "file0 is null");
		OATPP_ASSERT_HTTP(file1, Status::CODE_400, "file1 is null");
		/* ��ӦOK */
		return createResponse(Status::CODE_200, "OK");
	}
private: // ����ӿ�ִ�к���
	// ��ҳ��ѯ����
	LegalEntityMaiPageJsonVO::Wrapper execQueryLEM(const LegalEntityMaiQuery::Wrapper& legalEntityMaiQuery);
	// ��������
	Uint64JsonVO::Wrapper execUpdateLEM(const LegalEntityMaiDTO::Wrapper& dto);
	// ��������
	Uint64JsonVO::Wrapper execAddLEM(const LegalEntityMaiDTO::Wrapper& dto);
	// ɾ������
	Uint64JsonVO::Wrapper execRemoveLEM(const LegalEntityMaiDTO::Wrapper& dto);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_LEGALENTITYMAICONTROLLER_H_