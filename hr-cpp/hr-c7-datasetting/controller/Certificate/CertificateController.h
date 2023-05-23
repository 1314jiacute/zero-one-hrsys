#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/22 8:32:17

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
#ifndef _CERTIFICATECONTROLLER_H_
#define _CERTIFICATECONTROLLER_H_
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/Certificate/CertificateDTO.h"
#include "domain/query/Certificate/CertificateQuery.h"
#include "domain/vo/Certificate/CertificateVO.h"
#include OATPP_CODEGEN_BEGIN(ApiController) 

class CertificateController :public oatpp::web::server::api::ApiController
{
	// 2 ����������������
	API_ACCESS_DECLARE(CertificateController);
public://����ӿ�
	// 3 ����ӿ�����
	ENDPOINT_INFO(queryCertificate)
	{
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("certificate.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(CertificateJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("certificate.field.certificateName");
		info->queryParams["name"].addExample("default", String("shi gong yuan"));
		info->queryParams["name"].required = false;
	}
	ENDPOINT(API_M_GET, "/Certificate/query", queryCertificate, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, CertificateQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryCertificate(query));
	}
	// ��������֤������
	ENDPOINT_INFO(addCertificate) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("certificate.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		
	}
	// ���������ӿڴ���
	ENDPOINT(API_M_POST, "/Certificate/add", addCertificate, BODY_DTO(CertificateDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddCertificate(dto));
	}
	ENDPOINT_INFO(delCertificate) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("certificate.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		
	}
	// ��������ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/Certificate/delete", delCertificate, BODY_DTO(CertificateDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execDelCertificate(dto));
	}
	//�޸�ָ��֤������(�����޸�)
	ENDPOINT_INFO(modifyCertificate) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("certificate.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		
	}
	ENDPOINT(API_M_PUT, "/Certificate/modify", modifyCertificate, BODY_DTO(CertificateDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyCertificate(dto));
	}
private:
	// 5 ����ӿڵ�ִ�к���
	CertificatePageJsonVO::Wrapper execQueryCertificate(const CertificateQuery::Wrapper& query); //��ҳ��ѯ
	Uint64JsonVO::Wrapper execAddCertificate(const CertificateDTO::Wrapper& dto); //������λ֤������
	Uint64JsonVO::Wrapper execDelCertificate(const CertificateDTO::Wrapper& dto); //ɾ����λ֤������
	Uint64JsonVO::Wrapper execModifyCertificate(const CertificateDTO::Wrapper& dto); //�޸ĸ�λ֤������
};
#include OATPP_CODEGEN_END(ApiController)
#endif // !_CERTIFICATECONTROLLER_H_