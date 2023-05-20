#pragma once
#pragma once
#ifndef _TITLEDTO_H_
#define _TITLEDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ�����޸�ְ��Ŀ¼��Ϣ�Ĵ������
 */
class TitleDTO : public oatpp::DTO
{
	DTO_INIT(TitleDTO, DTO);
	
	
};

/**
 * ����һ��ְ��Ŀ¼��Ϣ��ҳ�������
 */
class TitlePageDTO : public PageDTO<TitleDTO::Wrapper>
{
	DTO_INIT(TitlePageDTO, PageDTO<TitleDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _TITLEDTO_H_