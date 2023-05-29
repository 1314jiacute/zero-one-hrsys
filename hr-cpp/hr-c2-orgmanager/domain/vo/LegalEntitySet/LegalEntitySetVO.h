#pragma once
#pragma once
#ifndef _LEGALERNAMEPULLDOWNLIST_VO_
#define _LEGALERNAMEPULLDOWNLIST_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/LegalEntitySet/LegalEntitySetDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class LegalEntitySetJsonVO : public JsonVO<LegalEntitySetDTO::Wrapper> {
	DTO_INIT(LegalEntitySetJsonVO, JsonVO<LegalEntitySetDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class LegalEntitySetPageJsonVO : public JsonVO<LegalEntitySetPageDTO::Wrapper> {
	DTO_INIT(LegalEntitySetPageJsonVO, JsonVO<LegalEntitySetPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LEGALERNAMEPULLDOWNLIST_VO_