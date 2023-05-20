/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/18 9:45:52
*/
#ifndef _EDUCATIOCONTROLLER_H_
#define _EDUCATIONCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "SimpleDateTimeFormat.h"
#include "domain/query/EducationPage/EducationPageQuery.h"
#include "domain/query/EducationSingle/EducationSingleQuery.h"
#include "domain/query/EducationExport/EducationExportQuery.h"
#include "domain/dto/Education/EducationDTO.h"
#include "domain/dto/EducationDelete/EducationDeleteDTO.h"
#include "domain/dto/EducationImport/EducationImportDTO.h"
#include "domain/vo/Education/EducationJsonVO.h"
#include "domain/vo/EducationImport/EducationImportVO.h"
#include "charsetconvertHepler.h"



//�ļ��ϴ�
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"


using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;
#include OATPP_CODEGEN_BEGIN(ApiController)

class EducationController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(EducationController);
public: // �ӿ�
	// ����1 ��ҳ��ѯָ������Ա���Ľ�����Ϣ���ӿ�����
	ENDPOINT_INFO(gueryEducationPage) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("gueryEducationPage");//�����ֵ�zh-dict.yaml
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		//API_DEF_ADD_RSP_JSON_WRAPPER(EducationPageJsonVO);
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������������Ա��������ѯ
		info->queryParams.add<String>("pimpersonname").description = ZH_WORDS_GETTER("gueryEducationPage");
		info->queryParams["pimpersonname"].addExample("default", String("Chen Jun"));
		info->queryParams["pimpersonname"].required = false;
		info->queryParams.add<String>("sort").description = ZH_WORDS_GETTER("t_pimperson.sort");
		info->queryParams["sort"].addExample("default", String("asc"));
		info->queryParams["sort"].required = false;
	}
	// ����1 ��ҳ��ѯָ������Ա���Ľ�����Ϣ���ӿڴ���
	ENDPOINT(API_M_GET, "/education/guery-Education-Page", gueryEducationPage, API_HANDLER_AUTH_PARAME,  QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(educationQuery, EducationPageQuery, queryParams);//��queryParamsת��ΪGetEducationPageQuery ����ΪeducationQuery
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryEducationPage(educationQuery, authObject->getPayload()));
	}
	// ����2 ������ѯָ������Ա���Ľ�����Ϣ���ӿ�����
	ENDPOINT_INFO(queryEducationSingle) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("queryEducationSingle");//�����ֵ�zh-dict.yaml
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(EducationPageJsonVO);
		//API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ������������������������Ա��������ѯ
		info->queryParams.add<String>("pimpersonname").description = ZH_WORDS_GETTER("getEducationPageQuery");
		info->queryParams["pimpersonname"].addExample("default", String("ChenJun"));
	}
	// ����2 ������ѯָ������Ա���Ľ�����Ϣ���ӿڴ���
	ENDPOINT(API_M_GET, "/education/query-Education-Single", queryEducationSingle, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(educationSingle, EducationSingleQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryEducationSingle(educationSingle, authObject->getPayload()));
	}
	// ����3 ��������ָ������Ա���Ľ�����Ϣ���ӿ�����
	ENDPOINT_INFO(addEducationSingle) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("addEducationSingle");
		// ������Ӧ������ʽ
		//API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// ����3 ��������ָ������Ա���Ľ�����Ϣ���ӿڴ���
	ENDPOINT(API_M_POST, "/education/add-Education-Single", addEducationSingle, BODY_DTO(EducationSingleDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddEducationSingle(dto));
	}

	// ����4 �����޸�ָ������Ա���Ľ�����Ϣ���ӿ�����
	ENDPOINT_INFO(modifyEducationSingle) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("modifyEducationSingle");
		// ������Ӧ������ʽ
		//API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// ����4 �޸�ָ������Ա���Ľ�����Ϣ���ӿڴ���
	ENDPOINT(API_M_PUT, "/education/modify-Education-Single", modifyEducationSingle, BODY_DTO(EducationSingleDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyEducationSingle(dto));
	}
	

	
	// ����5 ɾ��ָ������Ա���Ľ�����Ϣ���ӿ�����
	ENDPOINT_INFO(removeEducation) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("removeEducation");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		//API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// ����5 ɾ��ָ������Ա���Ľ�����Ϣ���ӿڴ���
	ENDPOINT(API_M_DEL, "/education/remove-Education-Single", removeEducation, BODY_DTO(String, deleteId)) {
		auto dto = EducationDeleteSingleDTO::createShared();
		dto->deleteId = deleteId;
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemoveEducation(dto));
	}


	// ����6 ����ɾ��ָ������Ա���Ľ�����Ϣ���ӿ�����
	ENDPOINT_INFO(removeEducationNotSingle) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("removeEducationNotSingle");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		//API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// ����6 ����ɾ��ָ������Ա���Ľ�����Ϣ���ӿڴ���
	ENDPOINT(API_M_DEL, "/education/remove-Education-Not-Single", removeEducationNotSingle, BODY_STRING(String, jsonPayload)) {
		const std::shared_ptr<ObjectMapper>& objectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
		// ������ѯ����
		auto dto = EducationDeleteNotSingleDTO::createShared();
		dto->deleteIds = objectMapper->readFromString<oatpp::List<String>>(jsonPayload);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemoveEducationNotSingle(dto));
	}

	// ����7 �����ļ��ϴ�������Ϣ���ӿ�����
		//* ����ǰ������������ݱ������ļ���ʽ������ļ������浽����
		//* ʹ�ñ���ļ��е�����ִ����������������������װ������id��List��Ϣ
	ENDPOINT_INFO(importEducation) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("importEducation.summary");
		// ����Ĭ����Ȩ����
		//API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(EudacationImportJsonVO);
		//API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����ҳ��������
		info->queryParams.add<String>("/Education/file-type").description = ZH_WORDS_GETTER("importEducation.fileType");
		info->queryParams["fileType"].addExample("default", String("xlsx"));
		info->queryParams["fileType"].required = false;
		info->queryParams.add<String>("/Education/sheet-name").description = ZH_WORDS_GETTER("importEducation.sheetName");
		info->queryParams["sheetName"].addExample("default", String("Sheet1"));
		info->queryParams["sheetName"].required = true;
		info->queryParams.add<String>("/Education/file").description = ZH_WORDS_GETTER("importEducation.file");
		info->queryParams["file"].required = true;
	}
	// ����7 �����ļ��ϴ�������Ϣ���ӿڴ���
	ENDPOINT(API_M_POST, "/education/upload-Education", importEducation,REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		/* ����multipart���� */
		auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
		/* ����multipart��ȡ�� */
		multipart::Reader multipartReader(multipartContainer.get());
		/* ���ö�ȡ����ȡ���ֶ� */
		multipartReader.setPartReader("fileType", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("sheetName", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		/* ���ö�ȡ����ȡ�ļ����ļ� */
		String filePath = "public/static/file/";
		filePath->append(SimpleDateTimeFormat::format("%Y-%m-%d_%H-%M-%S_"));
		filePath->append("JobSet.xlsx");
		multipartReader.setPartReader("file", multipart::createFilePartReader(filePath));

		/* ��ȡ�������е����� */
		request->transferBody(&multipartReader);
		if (multipartContainer->count() != 3)
		{
			/* ��ӡpart���� */
			OATPP_LOGD("Multipart", "parts_count=%d", multipartContainer->count());
			return createResponse(Status::CODE_400, "error in params");
		}

		/* ��ȡ������ */
		auto type = multipartContainer->getNamedPart("fileType");
		auto sheet = multipartContainer->getNamedPart("sheetName");
		/* ���Ա������Ƿ���ȷ */
		OATPP_ASSERT_HTTP(type, Status::CODE_400, "fileType is null");
		OATPP_ASSERT_HTTP(sheet, Status::CODE_400, "sheetName is null");

		string fileType = CharsetConvertHepler::utf8ToAnsi(type->getPayload()->getInMemoryData()->c_str());
		string sheetName = CharsetConvertHepler::utf8ToAnsi(sheet->getPayload()->getInMemoryData()->c_str());
		if (fileType != "csv" && fileType != "xls" && fileType != "xlsx" && sheetName != "")
		{
			return createResponse(Status::CODE_400, "error in params");
		}

		/* ��ȡ�ļ����� */
		auto filePart = multipartContainer->getNamedPart("file");
		/* �����ļ��Ƿ��ȡ�� */
		OATPP_ASSERT_HTTP(filePart, Status::CODE_400, "file upload error");
		/* ��ӡ�ļ����� */
		OATPP_LOGD("Multipart", "file='%s'", filePart->getFilename()->c_str());

		auto dto = EducationImportDTO::createShared(String(fileType), String(sheetName), filePath);
		
		// ��Ӧ���
		API_HANDLER_RESP_VO(execImportEducation(dto));
	}


	//����8 ����������Ϣ�ļ�
		/* ����ǰ�����󲢽��������ֶΣ��������ݲ�ѯ�����5000����
		* �Բ�ѯ�������ݷ�װ�ɱ���ļ����ϴ�fastdfs�ļ�������
		* ����ֵ��StringJsonVO - ����һ������url�ַ���
		* �����ˣ�Andrew
		*/
	//����8 ����������Ϣ�ļ� �ӿ�����
	ENDPOINT_INFO(exportEducation) {
		info->summary = ZH_WORDS_GETTER("export.summary");
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		info->queryParams.add<UInt8>("rows").description = ZH_WORDS_GETTER("export.rows");
		info->queryParams["rows"].addExample("default", UInt8(1));
		info->queryParams["rows"].required = true;
		info->queryParams.add<String>("sequence").description = ZH_WORDS_GETTER("export.sequence");
		info->queryParams["sequence"].addExample("default", String("ASC"));
		info->queryParams["sequence"].required = true;
	}
	//����8 ����������Ϣ�ļ� �ӿڴ���
	ENDPOINT(API_M_GET, "/education/export-Eudaction", exportEducation, QUERIES(QueryParams, qps)) {
		API_HANDLER_QUERY_PARAM(query, EducationExportQuery, qps);
		API_HANDLER_RESP_VO(execExportEducation(query));
	}


private: // �ӿ�ִ�к���
	// ����1 ��ҳ��ѯָ������Ա���Ľ�����Ϣ���ӿ�ִ�к���
	EducationPageJsonVO::Wrapper execQueryEducationPage(const EducationPageQuery::Wrapper& query, const PayloadDTO& payload);
	// ����2 ������ѯָ������Ա���Ľ�����Ϣ���ӿ�ִ�к���
	EducationSingleJsonVO::Wrapper execQueryEducationSingle(const EducationSingleQuery::Wrapper& query, const PayloadDTO& payload);
	// ����3 ��������ָ������Ա���Ľ�����Ϣ���ӿ�ִ�к���
	StringJsonVO::Wrapper execAddEducationSingle(const EducationSingleDTO::Wrapper& dto);
	// ����4 �޸�ָ������Ա���Ľ�����Ϣ���ӿ�ִ�к���
	StringJsonVO::Wrapper execModifyEducationSingle(const EducationSingleDTO::Wrapper& dto);
	// ����5 ɾ��ָ������Ա���Ľ�����Ϣ���ӿ�ִ�к���
	Uint64JsonVO::Wrapper execRemoveEducation(const EducationDeleteSingleDTO::Wrapper& dto);
	// ����6 ����ɾ��ָ������Ա���Ľ�����Ϣ���ӿ�ִ�к���
	Uint64JsonVO::Wrapper execRemoveEducationNotSingle(const EducationDeleteNotSingleDTO::Wrapper& dto);
	// ����7 �����ļ��ϴ�������Ϣ���ӿ�ִ�к���
	EudacationImportJsonVO::Wrapper execImportEducation(const EducationImportDTO::Wrapper& dto);
	//����8 ����������Ϣ�ļ�:  �ӿ�ִ�к���
	StringJsonVO::Wrapper execExportEducation(const EducationExportQuery::Wrapper& query);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_GETEDUCATIONPAGECONTROLLER_H_


