#pragma once
/*
* ������������--ɾ����������(֧������ɾ��)--pine
*/
#ifndef _DELETE_LEGAL_ENTITY_CONTROLLER_
#define _DELETE_LEGAL_ENTITY_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"

#include "domain/dto/LegalEntitySet/DeleteLegalEntityDTO.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<-

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class DeleteLegalEntityController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(DeleteLegalEntityController);
	// 3 ����ӿ�
public:

	// ����ɾ���ӿ�����
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("LegalEntitySet.delete.summary"), removeLES, StringJsonVO);
	// ����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/org/remove-LES", removeLES, BODY_DTO(DeleteLegalEntityDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execDeleteLegalEntity(dto));
	}
private:
	// 3.3 ��ʾɾ������
	StringJsonVO::Wrapper execDeleteLegalEntity(const DeleteLegalEntityDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //
#endif // _CERTIFIDELETE_CONTROLLER_