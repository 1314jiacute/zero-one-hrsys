#pragma once
#ifndef _SAMPLE_VO_
#define _SAMPLE_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/RosterOfPer/PageQueryEmployeeListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PageQueryEmployeeListJsonVO : public JsonVO<PageQueryEmployeeListDTO::Wrapper> {
	DTO_INIT(PageQueryEmployeeListJsonVO, JsonVO<PageQueryEmployeeListDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PageQueryEmployeeListPageJsonVO : public JsonVO<PageQueryEmployeeListDTO::Wrapper> {
	DTO_INIT(PageQueryEmployeeListPageJsonVO, JsonVO<PageQueryEmployeeListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_