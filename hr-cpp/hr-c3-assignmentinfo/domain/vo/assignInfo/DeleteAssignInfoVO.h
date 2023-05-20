#pragma once
#ifndef _Delete_Assign_VO_
#define _Delete_Assign_VO_

#include "../../GlobalInclude.h"
#include "../../dto/assignInfo/DeleteAssignInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class DeleteAssignInfoJsonVO : public JsonVO<DeleteAssignInfoDTO::Wrapper> {
	DTO_INIT(DeleteAssignInfoJsonVO, JsonVO<DeleteAssignInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !Delete_Assign_VO_