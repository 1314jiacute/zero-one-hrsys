#pragma once
#ifndef _Delete_Assign_Info_CONTROLLER_
#define _Delete_Assign_Info_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/assignInfo/DeleteAssignInfoDTO.h"
#include "domain/vo/assignInfo/DeleteAssignInfoVO.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class DeleteAssignInfoController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(DeleteAssignInfoController);
	// 3 ����ӿ�
public:
	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(deleteAssignInfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("employee.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/delete-assignInfo", deleteAssignInfo, BODY_DTO(DeleteAssignInfoDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execDeleteAssignInfo(dto));
	}
private:
	// 3.3 ��ʾɾ������
	Uint64JsonVO::Wrapper execDeleteAssignInfo(const DeleteAssignInfoDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_Delete_Assign_Info_CONTROLLER_