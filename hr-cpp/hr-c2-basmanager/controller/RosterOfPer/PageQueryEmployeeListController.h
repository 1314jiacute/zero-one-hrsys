#pragma once
#ifndef _PAGEQUERYEMPLOYEELIST_CONTROLLER_
#define _PAGEQUERYEMPLOYEELIST_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/do/RosterOfPer/PageQueryEmployeeListDO.h"
#include "domain/dto/RosterOfPer/PageQueryEmployeeListDTO.h"
#include "domain/vo/RosterOfPer/PageQueryEmployeeListVO.h"
#include "domain/query/RosterOfPer/PageQueryEmployeeListQuery.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

namespace multipart = oatpp::web::mime::multipart;

class PageQueryEmployeeListController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(PageQueryEmployeeListController); // 2 ����������������
public:

	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryPageQueryEmployeeList) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("sample.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(PageQueryEmployeeListPageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		/*info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("sample.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = false;
		info->queryParams.add<String>("sex").description = ZH_WORDS_GETTER("sample.field.sex");
		info->queryParams["sex"].addExample("default", String("N"));
		info->queryParams["sex"].required = false;*/
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/PageQueryEmployeeList-query", queryPageQueryEmployeeList, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, PageQueryEmployeeListQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execPageQueryEmployeeList(userQuery, authObject->getPayload()));
	} 

	//// 3.1 �������ӽӿ�����
	//ENDPOINT_INFO(addPageQueryEmployeeList) {
	//	// ����ӿڱ���
	//	info->summary = ZH_WORDS_GETTER("LegalEntitySet.post.summary");
	//	// ������Ӧ������ʽ
	//	API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	//}
	//// 3.2 ���������ӿڴ���
	//ENDPOINT(API_M_POST, "/PageQueryEmployeeList", addPageQueryEmployeeList, BODY_DTO(PageQueryEmployeeListDTO::Wrapper, dto)) {
	//	// ��Ӧ���
	//	API_HANDLER_RESP_VO(execAddPageQueryEmployeeList(dto));
	//}
	
	//// 3.1 �����޸Ľӿ�����
	//ENDPOINT_INFO(modifyPageQueryEmployeeList) {
	//	// ����ӿڱ���
	//	info->summary = ZH_WORDS_GETTER("LegalEntitySet.put.summary");
	//	// ������Ӧ������ʽ
	//	API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	//}
	//// 3.2 �����޸Ľӿڴ���
	//ENDPOINT(API_M_PUT, "/PageQueryEmployeeList", modifyPageQueryEmployeeList, BODY_DTO(PageQueryEmployeeListDTO::Wrapper, dto)) {
	//	// ��Ӧ���
	//	API_HANDLER_RESP_VO(execModifyPageQueryEmployeeList(dto));
	//}

	//// 3.1 ����ɾ���ӿ�����
	//ENDPOINT_INFO(removePageQueryEmployeeList) {
		//	// ����ӿڱ���
		//	info->summary = ZH_WORDS_GETTER("LegalEntitySet.delete.summary" );
		//	// ������Ӧ������ʽ
		//	API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		//}
		//// 3.2 ����ɾ���ӿڴ���
		//ENDPOINT(API_M_DEL, "/PageQueryEmployeeList", removePageQueryEmployeeList, BODY_DTO(PageQueryEmployeeListDTO::Wrapper, dto)) {
		//	// ��Ӧ���
		//	API_HANDLER_RESP_VO(execRemovePageQueryEmployeeList(dto));
		//}


	//	// ����ӿڱ���
	//	info->summary = ZH_WORDS_GETTER("LegalEntitySet.import.summary");
	//	// ������Ӧ������ʽ
	//	API_DEF_ADD_RSP_JSON_WRAPPER(BooleanJsonVO);
	//}
	//ENDPOINT(API_M_POST, "/ImportLEM", importLEM, BODY_DTO(PageQueryEmployeeListDTO::Wrapper, dto)) {
	//	// ��Ӧ���
	//	API_HANDLER_RESP_VO(execImportLEM(dto));
	//}
	//// �ļ�����
	//ENDPOINT_INFO(importLEM) {


	// �ļ�����
	//ENDPOINT_INFO(exportLEM) {
	//	// ����ӿڱ���
	//	info->summary = ZH_WORDS_GETTER("LegalEntitySet.export.summary");
	//	// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
	//	API_DEF_ADD_AUTH();
	//	// ������Ӧ������ʽ
	//	API_DEF_ADD_RSP_JSON_WRAPPER(BooleanJsonVO);
	//	// �����ҳ��������
	//	API_DEF_ADD_PAGE_PARAMS();
	//	// ����������ѯ��������
	//	info->queryParams.add<String>("ORMSIGNORGID").description = ZH_WORDS_GETTER("LegalEntitySet.field.id");
	//	info->queryParams["ORMSIGNORGID"].addExample("default", String("11F28C41-1D50-4503-B925-D86D1F70A1D2"));
	//	info->queryParams.add<String>("UPDATEMAN").description = ZH_WORDS_GETTER("LegalEntitySet.field.updateman");
	//	info->queryParams["UPDATEMAN"].addExample("default", String("guest"));
	//	info->queryParams.add<String>("CREATEMAN").description = ZH_WORDS_GETTER("LegalEntityM	ai.field.createman");
	//	info->queryParams["CREATEMAN"].addExample("default", String("1944DE89-8E28-4D10-812C-CAEEAAE8A927"));
	//	info->queryParams.add<String>("CREATEDATE").description = ZH_WORDS_GETTER("LegalEntitySet.field.createdate");
	//	info->queryParams["CREATEDATE"].addExample("default", String("2019-09-10 20:45:00"));
	//	info->queryParams.add<String>("ORMSIGNORGNAME").description = ZH_WORDS_GETTER("LegalEntitySet.field.name");
	//	info->queryParams["ORMSIGNORGNAME"].addExample("default", String(ZH_WORDS_GETTER("LegalEntitySet.sample.name")));
	//	info->queryParams.add<String>("UPDATEDATE").description = ZH_WORDS_GETTER("LegalEntitySet.field.updatedate");
	//	info->queryParams["UPDATEDATE"].addExample("default", String("2020-05-29 10:49:53"));
	//	info->queryParams.add<String>("ORGCODE").description = ZH_WORDS_GETTER("LegalEntitySet.field.orgcode");
	//	info->queryParams["ORGCODE"].addExample("default", String("104"));
	//}
	//ENDPOINT(API_M_GET, "/ExportLEM", exportLEM, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
	//	// ������ѯ����
	//	API_HANDLER_QUERY_PARAM(legalEntityMaiQuery, LegalEntityMaiQuery, queryParams);
	//	// ��Ӧ���
	//	API_HANDLER_RESP_VO(execExportLEM(legalEntityMaiQuery));
	//}


private:
	//3.3 ��ʾ��ҳ��ѯ����
	PageQueryEmployeeListPageJsonVO::Wrapper execPageQueryEmployeeList(const PageQueryEmployeeListQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 ��ʾ��������
	//Uint64JsonVO::Wrapper execAddPageQueryEmployeeList(const PageQueryEmployeeListDTO::Wrapper& dto);
	//// 3.3 ��ʾ�޸�����
	//Uint64JsonVO::Wrapper execModifyPageQueryEmployeeList(const PageQueryEmployeeListDTO::Wrapper& dto);
	// //3.3 ��ʾɾ������
	//Uint64JsonVO::Wrapper execRemovePageQueryEmployeeList(const PageQueryEmployeeListDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PAGEQUERYEMPLOYEELIST_CONTROLLER_