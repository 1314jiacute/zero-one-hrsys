#pragma once
#ifndef _EXPORTEMPLOYEE_CONTROLLER_
#define _EXPORTEMPLOYEE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/do/RosterOfPer/ExportEmployeeDO.h"
#include "domain/dto/RosterOfPer/ExportEmployeeDTO.h"
#include "domain/vo/RosterOfPer/ExportEmployeeVO.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
//#include "ApiHelper.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ExportEmployeeController : public oatpp::web::server::api::ApiController {
	
API_ACCESS_DECLARE(ExportEmployeeController); // 2 ����������������
public:
	// 3.1 �����ѯ�ӿ�����
	//ENDPOINT_INFO(queryExportEmployee) {
	//	// ����ӿڱ���
	//	info->summary = ZH_WORDS_GETTER("ExportEmployee.get.summary");
	//	// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
	//	API_DEF_ADD_AUTH();
	//	// ������Ӧ������ʽ
	//	API_DEF_ADD_RSP_JSON_WRAPPER(ExportEmployeePageJsonVO);
	//	// �����ҳ��������
	//	API_DEF_ADD_PAGE_PARAMS();
	//	// ������������������
	//	info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("ExportEmployee.field.name");
	//	info->queryParams["name"].addExample("default", String("li ming"));
	//	info->queryParams["name"].required = false;
	//	info->queryParams.add<String>("sex").description = ZH_WORDS_GETTER("ExportEmployee.field.sex");
	//	info->queryParams["sex"].addExample("default", String("N"));
	//	info->queryParams["sex"].required = false;
	//}
	//// 3.2 �����ѯ�ӿڴ���
	//ENDPOINT(API_M_GET, "/ExportEmployee", queryExportEmployee, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
	//	// ������ѯ����
	//	API_HANDLER_QUERY_PARAM(userQuery, ExportEmployeeQuery, queryParams);
	//	// ��Ӧ���
	//	API_HANDLER_RESP_VO(execQueryExportEmployee(userQuery, authObject->getPayload()));
	//}
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addExportEmployee) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("ExportEmployee.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/ExportEmployee", addExportEmployee, BODY_DTO(ExportEmployeeDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddExportEmployee(dto));
	}
	// 3.1 �����޸Ľӿ�����
	ENDPOINT_INFO(modifyExportEmployee) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("ExportEmployee.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/ExportEmployee", modifyExportEmployee, BODY_DTO(ExportEmployeeDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyExportEmployee(dto));
	}
	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeExportEmployee) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("ExportEmployee.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/ExportEmployee", removeExportEmployee, BODY_DTO(ExportEmployeeDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemoveExportEmployee(dto));
	}

	// [����] ����һ�����ļ��ϴ��ӿ�
	ENDPOINT(API_M_POST, "/upload", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		/* ����multipart���� */
		auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
		/* ����multipart��ȡ�� */
		multipart::Reader multipartReader(multipartContainer.get());
		/* ���ö�ȡ����ȡ���ֶ�3*/
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
private: 
	//// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddExportEmployee(const ExportEmployeeDTO::Wrapper& dto);
	//// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyExportEmployee(const ExportEmployeeDTO::Wrapper& dto);
	// //3.3 ��ʾɾ������
	Uint64JsonVO::Wrapper execRemoveExportEmployee(const ExportEmployeeDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _EXPORTEMPLOYEE_CONTROLLER_