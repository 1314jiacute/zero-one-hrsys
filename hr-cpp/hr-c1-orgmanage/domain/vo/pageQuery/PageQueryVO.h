#pragma once
#ifndef _PAGEQUERYVO_H_
#define _PAGEQUERYVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/pageQuery/PageQueryDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����б�VO����ģ��
 * �����ˣ�Andrew
 */
class PageQueryVO : public JsonVO<PageQueryDTO::Wrapper>
{
	DTO_INIT(PageQueryVO, JsonVO<PageQueryDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PAGEQUERYVO_H_