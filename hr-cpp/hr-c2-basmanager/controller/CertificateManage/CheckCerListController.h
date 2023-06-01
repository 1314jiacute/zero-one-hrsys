#pragma once

#ifndef _CHECK_CER_CONTROLLER_
#define _CHECK_CER_CONTROLLER_

#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/CertificateManage/CheckCerListQuery.h"
#include "domain/dto/CertificateManage/CheckCerListDTO.h"
#include "domain/vo/CertificateManage/CheckCerListVO.h"
/*������δ�õ�*/
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
* ��ҳ��ѯ֤���б�--(֤�����-��ҳ��ѯ֤���б�)--pine
 */
class CheckCerListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(CheckCerListController);

public://  ����ӿڣ�����ӿ�������ӿڶ˵㣩
	// 3���������ӿ�����
	ENDPOINT_INFO(queryCheckCerList) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("cermanage.get.checklist");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(CheckCerListPageJsonVO);
		//�����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		//���������ѯ������required��ʾ�Ƿ����
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("cermanage.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = false;
		info->queryParams.add<String>("sex").description = ZH_WORDS_GETTER("cermanage.field.sex");
		info->queryParams["sex"].addExample("default", String("N"));
		info->queryParams["sex"].required = false;
	}
	//4 ���������ӿڴ���
	ENDPOINT(API_M_GET, "/bas/query-CerList", queryCheckCerList, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		API_HANDLER_QUERY_PARAM(query, CheckCerListQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryCheckCerList(query));
	}

private://����ִ�к���
	// ��ҳ��ѯ����
	CheckCerListPageJsonVO::Wrapper execQueryCheckCerList(const PageQuery::Wrapper& query);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController)
#endif // _CheckCerList_CONTROLLER_