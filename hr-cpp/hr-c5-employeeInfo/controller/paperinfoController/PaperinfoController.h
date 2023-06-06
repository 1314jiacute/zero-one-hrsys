#pragma once

#ifndef _PAPERINFO_CONTROLLER_
#define _PAPERINFO_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/paperinfo/PaperQuery.h"
#include "domain/vo/paperinfo/PaperVO.h"

/*
	������Ϣ������
*/


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) 

class PaperinfoController : public oatpp::web::server::api::ApiController
{
	//  ����������������
	API_ACCESS_DECLARE(PaperinfoController);
public: // ����ӿ�
	// �����ҳ��ѯָ��Ա��������Ϣ�ӿ�����
	ENDPOINT_INFO(queryPaperinfo) {
		//����ӿڱ���
		info->summary = ZH_WORDS_GETTER("paperinfo.get.summary");
		//������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(PaperPageJsonVO);
		//�����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("paperinfo.field.pimpersonid");
		info->queryParams["pimpersonid"].addExample("default", String("10001"));
		info->queryParams["pimpersonid"].required = true;
	}
	// ����ӿڶ˵㴦��
	ENDPOINT(API_M_GET, "/employee-info/query-paperinfo-by-pimpersonid", queryPaperinfo, QUERIES(QueryParams, qps)) {
		//������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, PaperQuery, qps);
		//��Ӧ���
		API_HANDLER_RESP_VO(execQueryPaperinfo(query));
	}

	//  �����޸Ľӿ�����
	ENDPOINT_INFO(modifyPaperinfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("paperinfo.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	//  �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/employee-info/modify-paperinfo", modifyPaperinfo, BODY_DTO(PaperDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyPaperinfo(dto));
	}

	//  ���������ӿ�����
	ENDPOINT_INFO(addPaperinfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("paperinfo.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}

	//  ���������ӿڴ���
	ENDPOINT(API_M_POST, "/employee-info/add-paperinfo", addPaperinfo, BODY_DTO(PaperDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddPaperinfo(dto));
	}

	//  ����ɾ���ӿ�����
	ENDPOINT_INFO(removePimpaper) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("paperinfo.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	//  ����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/employee-info/remove-paperinfo", removePimpaper, BODY_DTO(PaperDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemovePaperinfo(dto));
	}

private: // ����ӿ�ִ�к���
	// ��ҳ��ѯ������Ϣ
	PaperPageJsonVO::Wrapper execQueryPaperinfo(const PaperQuery::Wrapper& query);

	// �޸�������Ϣ
	Uint64JsonVO::Wrapper execModifyPaperinfo(const PaperDTO::Wrapper& dto);

	// ���������Ϣ
	Uint64JsonVO::Wrapper execAddPaperinfo(const PaperDTO::Wrapper& dto);

	// ɾ��������Ϣ
	Uint64JsonVO::Wrapper execRemovePaperinfo(const PaperDTO::Wrapper& dto);
};


// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) // 0
#endif 