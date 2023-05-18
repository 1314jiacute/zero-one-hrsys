#pragma once
#ifndef _LEGALERNAMEPULLDOWNLIST_VO_
#define _LEGALERNAMEPULLDOWNLIST_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/LegalEntitySet/LegalerNamePullDownListDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class LegalerNamePullDownListJsonVO : public JsonVO<LegalerNamePullDownListDTO::Wrapper> {
	DTO_INIT(LegalerNamePullDownListJsonVO, JsonVO<LegalerNamePullDownListDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class LegalerNamePullDownListPageJsonVO : public JsonVO<LegalerNamePullDownListDTO::Wrapper> {
	DTO_INIT(LegalerNamePullDownListPageJsonVO, JsonVO<LegalerNamePullDownListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LEGALERNAMEPULLDOWNLIST_VO_