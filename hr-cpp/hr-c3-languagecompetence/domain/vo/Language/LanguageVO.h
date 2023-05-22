#pragma once
#ifndef _LANGUAGE_VO_
#define _LANGUAGE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/Language/LanguageDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class LanguageJsonVO : public JsonVO<LanguageDTO::Wrapper> {
	DTO_INIT(LanguageJsonVO, JsonVO<LanguageDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class LanguagePageJsonVO : public JsonVO<LanguagePageDTO::Wrapper> {
	DTO_INIT(LanguagePageJsonVO, JsonVO<LanguagePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LANGUAGE_VO_