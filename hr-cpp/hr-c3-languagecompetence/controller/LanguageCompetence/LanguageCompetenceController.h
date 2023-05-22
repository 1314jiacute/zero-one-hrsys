#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: jun
 @Date: 2023/05/18 23:03:24

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
#ifndef _LANGUAGECOMPETENCECONTROLLER_H_
#define _LANGUAGECOMPETENCECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/Language/LanguageQuery.h"
#include "domain/dto/Language/LanguageDTO.h"
#include "domain/vo/Language/LanguageVO.h"
#include "domain/query/LanguagePage/LanguagePageQuery.h"
#include "domain/dto/ImportLanguage/ImportLanguageDTO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)

class LanguageCompetenceController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(LanguageCompetenceController);
public: // ����ӿ�
	// �����ҳ��ѯ�ӿ�����
	ENDPOINT_INFO(queryLanguage) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("language.get.summarys");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("sample.field.id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sample.field.name"), "li ming", false);
	}
	//�����ҳ��ѯ�ӿڴ���
	//API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/user/query-langugae", queryLanguage, LanguagePageQuery, execQueryLanguage(query, authObject->getPayload()));
	ENDPOINT(API_M_GET, "/user/query-langugae", queryLanguage, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		//������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, LanguagePageQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryLanguage(userQuery, authObject->getPayload()));
	}
	// �����ѯ�ӿ�����
	ENDPOINT_INFO(queryOneLanguage) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("language.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ������������������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("sample.field.id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sample.field.name"), "li ming", false);
	}
	//�����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/user/query-one-langugae", queryOneLanguage, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		//������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, LanguageQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryOneLanguage(userQuery, authObject->getPayload()));
	}
	//���������ӿ�����
	ENDPOINT_INFO(addLanguage) {
		//����ӿڱ���
		info->summary = ZH_WORDS_GETTER("language.post.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		//API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	//���������ӿڴ���
	ENDPOINT(API_M_POST, "/user/add-language", addLanguage, API_HANDLER_AUTH_PARAME, BODY_DTO(LanguageDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddLanguage(dto, authObject->getPayload()));
	}
	//����ɾ���ӿ�����
	ENDPOINT_INFO(deleteLanguage) {
		//����ӿڱ���
		info->summary = ZH_WORDS_GETTER("language.delete.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		//API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	//����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/user/delete-language", deleteLanguage, API_HANDLER_AUTH_PARAME, BODY_DTO(LanguageDTO::Wrapper, dto)) {
		//��Ӧ���
		API_HANDLER_RESP_VO(execDeleteLanguage(dto, authObject->getPayload()));
	}
	//�����޸Ľӿ�����
	ENDPOINT_INFO(updateLanguage) {
		//����ӿڱ���
		info->summary = ZH_WORDS_GETTER("language.put.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		//API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	//�����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/user/update-language", updateLanguage, API_HANDLER_AUTH_PARAME, BODY_DTO(LanguageDTO::Wrapper, dto)) {
		//��Ӧ���
		API_HANDLER_RESP_VO(execUpdateLanguage(dto, authObject->getPayload()));
	}
	//����һ�����ļ��ϴ��ӿ�����
	ENDPOINT_INFO(uploadFile)
	{
		//����ӿڱ���
		info->summary = ZH_WORDS_GETTER("language.post.file");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		//API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ������������������
		API_DEF_ADD_QUERY_PARAMS(String, "url", ZH_WORDS_GETTER("user.file.url"), "", true);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("sample.field.id"), 1, false);
	};
	//����һ�����ļ��ϴ��ӿڴ���
	ENDPOINT(API_M_POST, "/user/upload-language", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		/* ����multipart���� */
		auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
		/* ����multipart��ȡ�� */
		multipart::Reader multipartReader(multipartContainer.get());
		/* ���ö�ȡ����ȡ���ֶ� */
		multipartReader.setPartReader("languagetype", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("languagelevel", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		/* ���ö�ȡ����ȡ�ļ����ļ� */
		multipartReader.setPartReader("file", multipart::createFilePartReader("public/static/file/test.png"));
		/* ��ȡ�������е����� */
		request->transferBody(&multipartReader);
		/* ��ӡpart���� */
		OATPP_LOGD("Multipart", "parts_count=%d", multipartContainer->count());
		/* ��ȡ������ */
		auto type = multipartContainer->getNamedPart("languagetype");
		auto level = multipartContainer->getNamedPart("languagelevel");
		/* ���Ա������Ƿ���ȷ */
		OATPP_ASSERT_HTTP(type, Status::CODE_400, "LanguageType is null");
		OATPP_ASSERT_HTTP(level, Status::CODE_400, "LanguageLevel is null");
		/* ��ӡӦ������ */
		OATPP_LOGD("Multipart", "LanguageType='%s'", type->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "LanguageLevel='%s'", level->getPayload()->getInMemoryData()->c_str());
		/* ��ȡ�ļ����� */
		auto filePart = multipartContainer->getNamedPart("file");
		/* �����ļ��Ƿ��ȡ�� */
		OATPP_ASSERT_HTTP(filePart, Status::CODE_400, "file is null");
		/* ��ӡ�ļ����� */
		OATPP_LOGD("Multipart", "file='%s'", filePart->getFilename()->c_str());
		/* ��ӦOK */
		return createResponse(Status::CODE_200, "OK");
	}
private: // ����ӿ�ִ�к���
	//�����ҳ��ѯ�ӿ�ִ�к���
	StringJsonVO::Wrapper execQueryLanguage(const LanguagePageQuery::Wrapper& query, const PayloadDTO& payload);
	//�����ѯ�ӿڽӿ�ִ�к���
	StringJsonVO::Wrapper execQueryOneLanguage(const LanguageQuery::Wrapper& query, const PayloadDTO& payload);
	//���������ӿ�ִ�к���
	//Uint64JsonVO::Wrapper execAddLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execAddLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload);
	//����ɾ���ӿ�ִ�к���
	//Uint64JsonVO::Wrapper execDeleteLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execDeleteLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload);
	//�����޸Ľӿ�ִ�к���
	//Uint64JsonVO::Wrapper execUpdateLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execUpdateLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_LANGUAGECOMPETENCECONTROLLER_H_