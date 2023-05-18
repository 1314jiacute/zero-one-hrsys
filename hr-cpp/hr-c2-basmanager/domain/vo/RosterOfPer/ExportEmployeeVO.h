#pragma once
#ifndef _EXPORTEMPLOYEE_VO_
#define _EXPORTEMPLOYEE_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/RosterOfPer/ExportEmployeeDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ExportEmployeeVO : public JsonVO<ExportEmployeeDTO::Wrapper> {
	DTO_INIT(ExportEmployeeVO, JsonVO<ExportEmployeeDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ExportEmployeePageJsonVO : public JsonVO<ExportEmployeeDTO::Wrapper> {
	DTO_INIT(ExportEmployeePageJsonVO, JsonVO<ExportEmployeeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EXPORTEMPLOYEE_VO_