#pragma once
#ifndef _Add_Assign_CONTROLLER_
#define _Add_Assign_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "domain/dto/assignInfo/AddAssignInfoDTO.h"
#include "domain/vo/assignInfo/AddAssignInfoVO.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class AddAssignInfoController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(AddAssignInfoController);
	// 3 ����ӿ�
public:

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addAssignInfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("employee.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AddAssignInfoJsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/add-assign", addAssignInfo, BODY_DTO(AddAssignInfoDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddAssignInfo(dto));
	}

private:
	// 3.3 ��ʾ��������
	AddAssignInfoJsonVO::Wrapper execAddAssignInfo(const AddAssignInfoDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _Add_Assign_CONTROLLER_