#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/20 11:40:01

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
#ifndef _PIMARMYCADRESCONTROLLER_H_
#define _PIMARMYCADRESCONTROLLER_H_


#include "domain/vo/BaseJsonVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "domain/query/Pimarmycadres/PimarmycadresPageQuery.h"
#include "domain/vo/Pimarmycadres/PimarmycadresVO.h"
#include "domain/dto/Pimarmycadres/AddPimarmycadresDTO.h"
#include "domain/dto/Pimarmycadres/DelPimarmycadresDTO.h"
#include "oatpp-swagger/Model.hpp"
#include "oatpp-swagger/Types.hpp"
#include <openssl/md5.h>
#include <boost/throw_exception.hpp>
#include <boost/throw_exception.hpp>

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)

class PimarmycadresController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(PimarmycadresController);
public: // ����ӿ�
	//  �����ѯ�ӿ�����
	ENDPOINT_INFO(queryWorkHistory) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("pimarmycadres.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(PimarmycadresFindVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("pimid").description = ZH_WORDS_GETTER("Pimarmycadres.field.pimid");
		info->queryParams["pimid"].addExample("default", String("6611212223"));
		info->queryParams["pimid"].required = false;
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/Pimarmycadres/select", queryWorkHistory, QUERIES(QueryParams, qps)) {
		//������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, PimarmycadresPageQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryPimarmycadres(query));
	}

	// ���������ӿ�����
	ENDPOINT_INFO(addPimarmycadres) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("pimarmycadres.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ���������ӿڴ���
	ENDPOINT(API_M_POST, "/Pimarmycadres/add", addPimarmycadres, BODY_DTO(AddPimarmycadresDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddPimarmycadres(dto));
	}

	// ��������ɾ���ӿ�����
	ENDPOINT_INFO(delWorkHistory) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("pimarmycadres.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ��������ɾ���ӿڴ���
	ENDPOINT(API_M_POST, "/Pimarmycadres/delete", delWorkHistory, BODY_DTO(DelPimarmycadresDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execDelPimarmycadres(dto));
	}

	// ����һ�����ļ�����ӿ�
	ENDPOINT_INFO(postFile) {
		info->summary = ZH_WORDS_GETTER("pimarmycadres.file.summary");
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		info->queryParams["suffix"].description = ZH_WORDS_GETTER("pimarmycadres.file.suffix");
		info->queryParams["suffix"].addExample("xlsx", String(".xlsx"));
	}
	// �����ļ��ϴ��˵㴦��
	ENDPOINT(API_M_POST, "/pimarmycadres/file", postFile, BODY_STRING(String, body), QUERY(String, suffix)) {
		// ִ���ļ������߼�
		API_HANDLER_RESP_VO(execIntoPimarmycadres(body, suffix));
	}

	//�ļ������ӿ�
	/*ENDPOINT_INFO(exportPimarmycadres) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("pimarmycadres.export.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������//
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("workhistory.field.pimpersonid");
		info->queryParams["pimpersonid"].addExample("default", String("6611212223"));
		info->queryParams["pimpersonid"].required = false;
	}*/

	// �����ѯ�ӿڴ���
	//ENDPOINT(API_M_GET, "/pimarmycadres/export", exportPimarmycadres, QUERIES(QueryParams, qps)) {
		//������������������������ģ�Ͷ���
		//API_HANDLER_QUERY_PARAM(query, WorkHistoryExportQuery, qps);
		// ��Ӧ���
		//API_HANDLER_RESP_VO(execExportWorkHistory(query));
	//}


private:

	// �����ҳ��ѯִ�к���
	PimarmycadresFindVO::Wrapper execQueryPimarmycadres(const PimarmycadresPageQuery::Wrapper& query);

	//��������ִ�к���
	Uint64JsonVO::Wrapper execAddPimarmycadres(const AddPimarmycadresDTO::Wrapper& dto);

	//����ɾ��ִ�к���
	Uint64JsonVO::Wrapper execDelPimarmycadres(const DelPimarmycadresDTO::Wrapper& dto);

	//���嵼��ִ�к���
	StringJsonVO::Wrapper execIntoPimarmycadres(const String body, const String suffix);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_PIMARMYCADRESCONTROLLER_H_