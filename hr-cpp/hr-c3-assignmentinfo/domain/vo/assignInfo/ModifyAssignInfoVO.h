#pragma once
#pragma once
#ifndef _Modify_Assign_VO_
#define _Modify_Assign_VO_

#include "../../GlobalInclude.h"
#include "../../dto/assignInfo/ModifyAssignInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ModifyAssignInfoJsonVO : public JsonVO<ModifyAssignInfoDTO::Wrapper> {
	DTO_INIT(ModifyAssignInfoJsonVO, JsonVO<ModifyAssignInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !Modify_Assign_VO_