#pragma once
#pragma once
#ifndef _Assign_Info_Query_VO_
#define _Assign_Info_Query_VO_

#include "../../GlobalInclude.h"
#include "../../query/assignInfo/AssignInfoQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class AssignInfoQueryJsonVO : public JsonVO<AssignInfoQuery::Wrapper> {
	DTO_INIT(AssignInfoQueryJsonVO, JsonVO<AssignInfoQuery::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_Assign_Info_Query_VO_