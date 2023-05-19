#pragma once
#ifndef _SCIENTIFICCONTROLLER_H_
#define _SCIENTIFICCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/scientific/ScientificQuery.h"
#include "domain/vo/scientific/ScientificVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ScientificController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ScientificController);
public: // ����ӿ�
	//�鿴ָ��Ա�����гɹ�(ָ�����гɹ�����)
	ENDPOINT_INFO(queryScientific) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("scientific.get.summary");
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(ScientificJsonVO);
		// ���������ѯ����
		info->queryParams.add<String>("PIMARMYCADRESID").description = ZH_WORDS_GETTER("scientific.PIMARMYCADRESID");
		info->queryParams["PIMARMYCADRESID"].addExample("default", String("QWER-ASFD"));
	}
	ENDPOINT(API_M_GET, "/scientific", queryScientific, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, ScientificViewQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryScientific(query));
	}
	//�޸�ָ�����гɹ�(�����޸�)
	ENDPOINT_INFO(modifyScientific) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("scientific.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_PUT, "/scientific", modifyScientific, BODY_DTO(ScientificDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyScientific(dto));
	}
	//����ָ��Ա�����гɹ�(������ҳ��ǰ�����)
	ENDPOINT_INFO(downloadScientific) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("scientific.download.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ���������ѯ����
		info->queryParams.add<String>("PIMPERSONID").description = ZH_WORDS_GETTER("scientific.PIMPERSONID");
		info->queryParams["PIMPERSONID"].addExample("default", String("0000-QWDE"));
	}
	ENDPOINT(API_M_POST, "/scientific", downloadScientific, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, ScientificDownloadQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execDownloadScientific(query));
	}
private: // ����ӿ�ִ�к���
	ScientificJsonVO::Wrapper execQueryScientific(const ScientificViewQuery::Wrapper& query);
	Uint64JsonVO::Wrapper execModifyScientific(const ScientificDTO::Wrapper& dto);
	StringJsonVO::Wrapper execDownloadScientific(const ScientificDownloadQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_SCIENTIFICCONTROLLER_H_