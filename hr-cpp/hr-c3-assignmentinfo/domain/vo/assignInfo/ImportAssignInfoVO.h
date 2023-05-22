#pragma once
#pragma once
#ifndef _Import_Assign_VO_
#define _Import_Assign_VO_

#include "../../GlobalInclude.h"
#include "../../dto/assignInfo/ImportAssignInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ImportAssignInfoJsonVO : public JsonVO<ImportAssignInfoDTO::Wrapper> {
	DTO_INIT(ImportAssignInfoJsonVO, JsonVO<ImportAssignInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !Import_Assign_VO_