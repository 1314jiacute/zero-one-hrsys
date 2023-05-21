#ifndef _Modify_Assign_Info_CONTROLLER_
#define _Modify_Assign_Info_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/assignInfo/ModifyAssignInfoDTO.h"
#include "domain/vo/assignInfo/ModifyAssignInfoVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) // 0


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class ModifyAssignInfoController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ModifyAssignInfoController);
	// 3 ����ӿ�
public:
	// 3.1 �����޸Ľӿ�����
	ENDPOINT_INFO(modifyAssignInfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("employee.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/modify-assignInfo", modifyAssignInfo, BODY_DTO(ModifyAssignInfoDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyAssignInfo(dto));
	}

private:
	//// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyAssignInfo(const ModifyAssignInfoDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_Modify_Assign_Info_CONTROLLER_