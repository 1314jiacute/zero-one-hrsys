#pragma once
#pragma once
#ifndef _Assign_Info_Query_Detail_VO_
#define _Assign_Info_Query_Detail_VO_

#include "../../GlobalInclude.h"
#include "../../query/assignInfo/AssignInfoQueryDetail.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class AssignInfoQueryDetailJsonVO : public JsonVO<AssignInfoQueryDetail::Wrapper> {
	DTO_INIT(AssignInfoQueryDetailJsonVO, JsonVO<AssignInfoQueryDetail::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_Assign_Info_Query_Detail_VO_