#pragma once
#ifndef _CONTRACTCONTROLLER_H_
#define _CONTRACTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/ContractType/ContractTypeQuery.h"
#include "domain/vo/ContractType/ContractTypeVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) // 0

/**
 * ��ͬ��ѯ������
 */
class ContractController : public oatpp::web::server::api::ApiController // 1
{
	// 2 ����������������
	API_ACCESS_DECLARE(ContractController);
public: // ����ӿ�
	// 3 ����ӿ�����
	ENDPOINT_INFO(queryContract) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("contractType.get.summary");
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractTypePageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ���������ѯ����
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("sample.field.name");
		info->queryParams["name"].addExample("default", String("t**"));
		info->queryParams["name"].required = false;
	}
	// 4 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/contract", queryContract, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, ContractTypeQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryContractType(query));
	}
	// ���������ӿ�����
	ENDPOINT_INFO(addContractType) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("contractType.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractTypeJsonVO);
	}
	// ���������ӿڴ���
	ENDPOINT(API_M_POST, "/contract", addContractType, BODY_DTO(ContractTypeDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddContractType(dto));
	}
	// �����޸Ľӿ�����
	ENDPOINT_INFO(modifyContractType) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("contractType.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractTypeJsonVO);
	}
	// �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/contract", modifyContractType, BODY_DTO(ContractTypeDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyContractType(dto));
	}
	// ����ɾ���ӿ�����
	ENDPOINT_INFO(removeContractType) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("contractType.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractTypeJsonVO);
	}
	// 3.2 ����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/contract", removeContractType, BODY_DTO(ContractTypeDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemoveContractType(dto));
	}
private: // ����ӿ�ִ�к���
	// 5 ����ӿڵ�ִ�к���
	//ContractTypePageJsonVO::Wrapper ContractController::execQueryContractType(const ContractTypeQuery::Wrapper & query)
	ContractTypePageJsonVO::Wrapper execQueryContractType(const ContractTypeQuery::Wrapper& query);
	Uint64JsonVO::Wrapper execAddContractType(const ContractTypeDTO::Wrapper& dto);
	Uint64JsonVO::Wrapper execModifyContractType(const ContractTypeDTO::Wrapper& dto);
	Uint64JsonVO::Wrapper execRemoveContractType(const ContractTypeDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_CONTRACTCONTROLLER_H_