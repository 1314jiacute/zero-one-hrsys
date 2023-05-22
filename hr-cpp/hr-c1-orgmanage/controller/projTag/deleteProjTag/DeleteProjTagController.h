#pragma once
#ifndef _DELETEPROJTAGCONTROLLER_H_
#define _DELETEPROJTAGCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "domain/dto/projTag/DeleteProjTagDTO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class DeleteProjTagController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(DeleteProjTagController);
	// 3 ����ӿ�
public:
	// ɾ����������
	ENDPOINT_INFO(deleteByTagId) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("projTag.deleteProjTag");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);

	}
	ENDPOINT(API_M_DEL, "/delete-one-by-tagId/{tagId}", deleteByTagId, API_HANDLER_AUTH_PARAME, PATH(String, tagId)) {
		// ������ѯ����
		auto deleteProjTagDTO = DeleteProjTagDTO::createShared();
		deleteProjTagDTO->tagId = tagId;
		// ��Ӧ���
		API_HANDLER_RESP_VO(execDeleteByTagId(deleteProjTagDTO, authObject->getPayload()));
	}

	// ɾ����������
	ENDPOINT_INFO(deleteBatchByTagId) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("projTag.deleteProjTags");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_DEL, "/deleteBatch-one-by-tagId", deleteBatchByTagId, API_HANDLER_AUTH_PARAME, BODY_STRING(String, jsonPayload)) {
		const std::shared_ptr<ObjectMapper>& objectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
		// ������ѯ����
		auto deleteProjTagBatchDTO = DeleteProjTagBatchDTO::createShared();
		deleteProjTagBatchDTO->tagIds = objectMapper->readFromString<oatpp::List<String>>(jsonPayload);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execDeleteBatchByTagId(deleteProjTagBatchDTO, authObject->getPayload()));
	}
private:
	// ��ѯָ����λ����
	Uint64JsonVO::Wrapper execDeleteByTagId(const DeleteProjTagDTO::Wrapper& query, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execDeleteBatchByTagId(const DeleteProjTagBatchDTO::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _DELETEPROJTAGCONTROLLER_H_