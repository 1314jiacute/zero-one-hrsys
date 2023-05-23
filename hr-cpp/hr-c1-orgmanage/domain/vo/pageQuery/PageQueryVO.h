#pragma once
#ifndef _PAGEQUERYVO_H_
#define _PAGEQUERYVO_H_

#include "../../GlobalInclude.h"
// #include "../../dto/pageQuery/PageQueryDTO.h"
#include "../../query/projTag/PageProjTagQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����б�VO����ģ��
 * �����ˣ�Andrew
 */
class PageQueryVO : public JsonVO<PageProjTagQuery::Wrapper>
{
	DTO_INIT(PageQueryVO, JsonVO<PageProjTagQuery::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PAGEQUERYVO_H_