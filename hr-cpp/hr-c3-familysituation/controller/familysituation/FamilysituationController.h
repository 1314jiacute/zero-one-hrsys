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
#include "domain/query/familysituation/FamilysituationQuery.h"

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
 		API_DEF_ADD_RSP_JSON_WRAPPER(FamilySituationPageJsonVO);
 		// �����ҳ��������
 		API_DEF_ADD_PAGE_PARAMS();
		info->queryParams.add<String>("id").description = "ID";
		info->queryParams["id"].addExample("default", String("1"));
		info->queryParams.add<String>("frelationship").description = ZH_WORDS_GETTER("familysituation.field.relationship");
		info->queryParams["frelationship"].addExample("default", String(ZH_WORDS_GETTER("familysituation.description.dadson")));
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("familysituation.field.name");
		info->queryParams["name"].addExample("default", String("Marvin"));
		info->queryParams.add<String>("gender").description = ZH_WORDS_GETTER("familysituation.field.gender");
		info->queryParams["gender"].addExample("default", String("Male"));
		info->queryParams["gender"].required = false;
		info->queryParams.add<UInt64>("age").description = ZH_WORDS_GETTER("familysituation.field.age");
		info->queryParams["age"].addExample("default", UInt64(1));
		info->queryParams["age"].required = false;
		info->queryParams.add<String>("workplace").description = ZH_WORDS_GETTER("familysituation.field.workplace");
		info->queryParams["workplace"].addExample("default", String("home"));
		info->queryParams["workplace"].required = false;
		info->queryParams.add<String>("job").description = ZH_WORDS_GETTER("familysituation.field.job");
		info->queryParams["job"].addExample("default", String("teacher"));
		info->queryParams["job"].required = false;
		info->queryParams.add<String>("politicalstatus").description = ZH_WORDS_GETTER("familysituation.field.politicalstatus");
		info->queryParams["politicalstatus"].addExample("default", String("xx"));
		info->queryParams["politicalstatus"].required = false;
		info->queryParams.add<String>("identification").description = ZH_WORDS_GETTER("familysituation.field.identification");
		info->queryParams["identification"].addExample("default", String("46126132513251251X"));
		info->queryParams["identification"].required = false;
		info->queryParams.add<String>("dob").description = ZH_WORDS_GETTER("familysituation.field.dob");
		info->queryParams["dob"].addExample("default", String("1998/06/25"));
		info->queryParams["dob"].required = false;
		info->queryParams.add<UInt8>("testament").description = ZH_WORDS_GETTER("familysituation.field.testament");
		info->queryParams["testament"].addExample("default", UInt8(1));
		info->queryParams["testament"].required = false;
		info->queryParams.add<UInt8>("ice").description = ZH_WORDS_GETTER("familysituation.field.ice");
		info->queryParams["ice"].addExample("default", UInt8(1));
		info->queryParams["ice"].required = false;
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
 		info->queryParams.add<String>("id").description = "ID";
 		info->queryParams["id"].addExample("default", String("1"));
 		info->queryParams.add<String>("frelationship").description = ZH_WORDS_GETTER("familysituation.field.relationship");
 		info->queryParams["frelationship"].addExample("default", String(ZH_WORDS_GETTER("familysituation.description.dadson")));
		info->queryParams["gender"].required = false;
 		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("familysituation.field.name");
 		info->queryParams["name"].addExample("default", String("Marvin"));
		info->queryParams["gender"].required = false;
 		info->queryParams.add<String>("gender").description = ZH_WORDS_GETTER("familysituation.field.gender");
 		info->queryParams["gender"].addExample("default", String("Male"));
 		info->queryParams["gender"].required = false;
 		info->queryParams.add<UInt64>("age").description = ZH_WORDS_GETTER("familysituation.field.age");
 		info->queryParams["age"].addExample("default", UInt64(1));
 		info->queryParams["age"].required = false;
 		info->queryParams.add<String>("workplace").description = ZH_WORDS_GETTER("familysituation.field.workplace");
 		info->queryParams["workplace"].addExample("default", String("home"));
 		info->queryParams["workplace"].required = false;
 		info->queryParams.add<String>("job").description = ZH_WORDS_GETTER("familysituation.field.job");
 		info->queryParams["job"].addExample("default", String("teacher"));
 		info->queryParams["job"].required = false;
 		info->queryParams.add<String>("politicalstatus").description = ZH_WORDS_GETTER("familysituation.field.politicalstatus");
 		info->queryParams["politicalstatus"].addExample("default", String("xx"));
 		info->queryParams["politicalstatus"].required = false;
 		info->queryParams.add<String>("identification").description = ZH_WORDS_GETTER("familysituation.field.identification");
 		info->queryParams["identification"].addExample("default", String("46126132513251251X"));
 		info->queryParams["identification"].required = false;
 		info->queryParams.add<String>("dob").description = ZH_WORDS_GETTER("familysituation.field.dob");
 		info->queryParams["dob"].addExample("default", String("1998/06/25"));
 		info->queryParams["dob"].required = false;
 		info->queryParams.add<UInt8>("testament").description = ZH_WORDS_GETTER("familysituation.field.testament");
 		info->queryParams["testament"].addExample("default", UInt8(1));
 		info->queryParams["testament"].required = false;
 		info->queryParams.add<UInt8>("ice").description = ZH_WORDS_GETTER("familysituation.field.ice");
 		info->queryParams["ice"].addExample("default", UInt8(1));
 		info->queryParams["ice"].required = false;
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
		info->queryParams.add<String>("frelationship").description = ZH_WORDS_GETTER("familysituation.field.relationship");
		info->queryParams["frelationship"].addExample("default", String(ZH_WORDS_GETTER("familysituation.description.dadson")));
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("familysituation.field.name");
		info->queryParams["name"].addExample("default", String("Marvin"));
		info->queryParams.add<String>("gender").description = ZH_WORDS_GETTER("familysituation.field.gender");
		info->queryParams["gender"].addExample("default", String("Male"));
		info->queryParams["gender"].required = false;
		info->queryParams.add<UInt64>("age").description = ZH_WORDS_GETTER("familysituation.field.age");
		info->queryParams["age"].addExample("default", UInt64(1));
		info->queryParams["age"].required = false;
		info->queryParams.add<String>("workplace").description = ZH_WORDS_GETTER("familysituation.field.workplace");
		info->queryParams["workplace"].addExample("default", String("home"));
		info->queryParams["workplace"].required = false;
		info->queryParams.add<String>("job").description = ZH_WORDS_GETTER("familysituation.field.job");
		info->queryParams["job"].addExample("default", String("teacher"));
		info->queryParams["job"].required = false;
		info->queryParams.add<String>("politicalstatus").description = ZH_WORDS_GETTER("familysituation.field.politicalstatus");
		info->queryParams["politicalstatus"].addExample("default", String("xx"));
		info->queryParams["politicalstatus"].required = false;
		info->queryParams.add<String>("identification").description = ZH_WORDS_GETTER("familysituation.field.identification");
		info->queryParams["identification"].addExample("default", String("46126132513251251X"));
		info->queryParams["identification"].required = false;
		info->queryParams.add<String>("dob").description = ZH_WORDS_GETTER("familysituation.field.dob");
		info->queryParams["dob"].addExample("default", String("1998/06/25"));
		info->queryParams["dob"].required = false;
		info->queryParams.add<UInt8>("testament").description = ZH_WORDS_GETTER("familysituation.field.testament");
		info->queryParams["testament"].addExample("default", UInt8(1));
		info->queryParams["testament"].required = false;
		info->queryParams.add<UInt8>("ice").description = ZH_WORDS_GETTER("familysituation.field.ice");
		info->queryParams["ice"].addExample("default", UInt8(1));
		info->queryParams["ice"].required = false;
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
		info->queryParams.add<String>("frelationship").description = ZH_WORDS_GETTER("familysituation.field.relationship");
		info->queryParams["frelationship"].addExample("default", String(ZH_WORDS_GETTER("familysituation.description.dadson")));
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("familysituation.field.name");
		info->queryParams["name"].addExample("default", String("Marvin"));
		info->queryParams.add<String>("gender").description = ZH_WORDS_GETTER("familysituation.field.gender");
		info->queryParams["gender"].addExample("default", String("Male"));
		info->queryParams["gender"].required = false;
		info->queryParams.add<UInt64>("age").description = ZH_WORDS_GETTER("familysituation.field.age");
		info->queryParams["age"].addExample("default", UInt64(1));
		info->queryParams["age"].required = false;
		info->queryParams.add<String>("workplace").description = ZH_WORDS_GETTER("familysituation.field.workplace");
		info->queryParams["workplace"].addExample("default", String("home"));
		info->queryParams["workplace"].required = false;
		info->queryParams.add<String>("job").description = ZH_WORDS_GETTER("familysituation.field.job");
		info->queryParams["job"].addExample("default", String("teacher"));
		info->queryParams["job"].required = false;
		info->queryParams.add<String>("politicalstatus").description = ZH_WORDS_GETTER("familysituation.field.politicalstatus");
		info->queryParams["politicalstatus"].addExample("default", String("xx"));
		info->queryParams["politicalstatus"].required = false;
		info->queryParams.add<String>("identification").description = ZH_WORDS_GETTER("familysituation.field.identification");
		info->queryParams["identification"].addExample("default", String("46126132513251251X"));
		info->queryParams["identification"].required = false;
		info->queryParams.add<String>("dob").description = ZH_WORDS_GETTER("familysituation.field.dob");
		info->queryParams["dob"].addExample("default", String("1998/06/25"));
		info->queryParams["dob"].required = false;
		info->queryParams.add<UInt8>("testament").description = ZH_WORDS_GETTER("familysituation.field.testament");
		info->queryParams["testament"].addExample("default", UInt8(1));
		info->queryParams["testament"].required = false;
		info->queryParams.add<UInt8>("ice").description = ZH_WORDS_GETTER("familysituation.field.ice");
		info->queryParams["ice"].addExample("default", UInt8(1));
		info->queryParams["ice"].required = false;
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
		info->queryParams.add<String>("frelationship").description = ZH_WORDS_GETTER("familysituation.field.relationship");
		info->queryParams["frelationship"].addExample("default", String(ZH_WORDS_GETTER("familysituation.description.dadson")));
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("familysituation.field.name");
		info->queryParams["name"].addExample("default", String("Marvin"));
		info->queryParams.add<String>("gender").description = ZH_WORDS_GETTER("familysituation.field.gender");
		info->queryParams["gender"].addExample("default", String("Male"));
		info->queryParams["gender"].required = false;
		info->queryParams.add<UInt64>("age").description = ZH_WORDS_GETTER("familysituation.field.age");
		info->queryParams["age"].addExample("default", UInt64(1));
		info->queryParams["age"].required = false;
		info->queryParams.add<String>("workplace").description = ZH_WORDS_GETTER("familysituation.field.workplace");
		info->queryParams["workplace"].addExample("default", String("home"));
		info->queryParams["workplace"].required = false;
		info->queryParams.add<String>("job").description = ZH_WORDS_GETTER("familysituation.field.job");
		info->queryParams["job"].addExample("default", String("teacher"));
		info->queryParams["job"].required = false;
		info->queryParams.add<String>("politicalstatus").description = ZH_WORDS_GETTER("familysituation.field.politicalstatus");
		info->queryParams["politicalstatus"].addExample("default", String("xx"));
		info->queryParams["politicalstatus"].required = false;
		info->queryParams.add<String>("identification").description = ZH_WORDS_GETTER("familysituation.field.identification");
		info->queryParams["identification"].addExample("default", String("46126132513251251X"));
		info->queryParams["identification"].required = false;
		info->queryParams.add<String>("dob").description = ZH_WORDS_GETTER("familysituation.field.dob");
		info->queryParams["dob"].addExample("default", String("1998/06/25"));
		info->queryParams["dob"].required = false;
		info->queryParams.add<UInt8>("testament").description = ZH_WORDS_GETTER("familysituation.field.testament");
		info->queryParams["testament"].addExample("default", UInt8(1));
		info->queryParams["testament"].required = false;
		info->queryParams.add<UInt8>("ice").description = ZH_WORDS_GETTER("familysituation.field.ice");
		info->queryParams["ice"].addExample("default", UInt8(1));
		info->queryParams["ice"].required = false;
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
	//ENDPOINT(API_M_POST, "/import-by-Familysituation", importFile, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
	//	/* ����multipart���� */
	//	auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
	//	/* ����multipart��ȡ�� */
	//	multipart::Reader multipartReader(multipartContainer.get());
	//	/* ���ö�ȡ����ȡ���ֶ� */
	//	multipartReader.setPartReader("frelationship", multipart::createInMemoryPartReader(-1 /* max-data-size */));
	//	multipartReader.setPartReader("name", multipart::createInMemoryPartReader(-1 /* max-data-size */));
	//	multipartReader.setPartReader("gender", multipart::createInMemoryPartReader(-1 /* max-data-size */));
	//	multipartReader.setPartReader("age", multipart::createInMemoryPartReader(-1 /* max-data-size */));
	//	multipartReader.setPartReader("workplace", multipart::createInMemoryPartReader(-1 /* max-data-size */));
	//	multipartReader.setPartReader("job", multipart::createInMemoryPartReader(-1 /* max-data-size */));
	//	multipartReader.setPartReader("politicalstatus", multipart::createInMemoryPartReader(-1 /* max-data-size */));
	//	multipartReader.setPartReader("identification", multipart::createInMemoryPartReader(-1 /* max-data-size */));
	//	multipartReader.setPartReader("dob", multipart::createInMemoryPartReader(-1 /* max-data-size */));
	//	multipartReader.setPartReader("testament", multipart::createInMemoryPartReader(-1 /* max-data-size */));
	//	multipartReader.setPartReader("ice", multipart::createInMemoryPartReader(-1 /* max-data-size */));
	//	/* ���ö�ȡ����ȡ�ļ����ļ� */
	//	String filePath = "public/static/file/";
	//	filePath->append(SimpleDateTimeFormat::format("%Y-%m-%d_%H-%M-%S_"));
	//	filePath->append("FamilySituation.xlsx");
	//	multipartReader.setPartReader("file", multipart::createFilePartReader(filePath));
	//	/* ��ȡ�������е����� */
	//	request->transferBody(&multipartReader);
	//	/* ��ӡpart���� */
	//	OATPP_LOGD("Multipart", "parts_count=%d", multipartContainer->count());
	//	/* ��ȡ������ */
	//	auto frelationship = multipartContainer->getNamedPart("relationship");
	//	auto name = multipartContainer->getNamedPart("familyName");
	//	/* ���Ա������Ƿ���ȷ */
	//	OATPP_ASSERT_HTTP(frelationship, Status::CODE_400, "relationship is null");
	//	OATPP_ASSERT_HTTP(name, Status::CODE_400, "familyName is null");
	//	/* ��ȡ�ļ����� */
	//	auto filePart = multipartContainer->getNamedPart("file");
	//	/* �����ļ��Ƿ��ȡ�� */
	//	OATPP_ASSERT_HTTP(filePart, Status::CODE_400, "file is null");
	//	/* ��ӡ�ļ����� */
	//	OATPP_LOGD("Multipart", "file='%s'", filePart->getFilename()->c_str());
	//	/* ��ӦOK */
	//	return createResponse(Status::CODE_200, "OK");
	//}

	// ���嵼���ӿ�����
	ENDPOINT_INFO(exportFamilysituation)
	{
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("familysituation.export.summary");
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("sample.field.id");
		info->queryParams["id"].addExample("default", String("0000001"));
		info->queryParams["id"].required = true;
	}
	// ���嵼���ӿڴ���
	ENDPOINT(API_M_GET, "/export-by-family-situation", exportFamilysituation, QUERIES(QueryParams, qps))
	{
		// ��Ӧ���
		API_HANDLER_QUERY_PARAM(query, FamilysituationQuery, qps);
		API_HANDLER_RESP_VO(execExportFamilysituation(query));
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
	StringJsonVO::Wrapper executeImportFamilysituation(const String& fileBody, const String& suffix);
	// ����������Ӧ
	StringJsonVO::Wrapper execExportFamilysituation(const FamilysituationQuery::Wrapper & query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FAMILYSITUATIONCONTROLLER_H_