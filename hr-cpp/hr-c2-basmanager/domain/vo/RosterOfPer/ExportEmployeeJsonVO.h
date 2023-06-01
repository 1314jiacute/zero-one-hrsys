#pragma once
/*
����Ա������-��Ա������-����Ա����������ҳ��ǰ����ɣ���--luoluo
*/
#ifndef _EXPORTEMPLOYEE_VO_
#define _EXPORTEMPLOYEE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/RosterOfPer/ExportEmployeeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ExportEmployeeJsonVO : public JsonVO<ExportEmployeeDTO::Wrapper> {
	DTO_INIT(ExportEmployeeJsonVO, JsonVO<ExportEmployeeDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ExportEmployeePageJsonVO : public JsonVO<ExportEmployeePageDTO::Wrapper> {
	DTO_INIT(ExportEmployeePageJsonVO, JsonVO<ExportEmployeePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EXPORTEMPLOYEE_VO_