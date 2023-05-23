#pragma once
#pragma once
#ifndef _Add_Assign_VO_
#define _Add_Assign_VO_

#include "../../GlobalInclude.h"
#include "../../dto/assignInfo/AddAssignInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class AddAssignInfoJsonVO : public JsonVO<AddAssignInfoDTO::Wrapper> {
	DTO_INIT(AddAssignInfoJsonVO, JsonVO<AddAssignInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !Add_Assign_VO_