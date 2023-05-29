#pragma once
#ifndef _EXPORTLEGALERSETTING_VO_
#define _EXPORTLEGALERSETTING_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/LegalEntitySet/ExportLegalerSetingDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ExportLegalerSetingJsoonVO : public JsonVO<ExportLegalerSetingDTO::Wrapper> {
	DTO_INIT(ExportLegalerSetingJsoonVO, JsonVO<ExportLegalerSetingDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ExportLegalerSetingPageJsonVO : public JsonVO<ExportLegalerSetingPageDTO::Wrapper> {
	DTO_INIT(ExportLegalerSetingPageJsonVO, JsonVO<ExportLegalerSetingPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EXPORTLEGALERSETTING_VO_