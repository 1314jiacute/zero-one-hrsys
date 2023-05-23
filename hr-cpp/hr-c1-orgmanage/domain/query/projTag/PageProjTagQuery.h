#pragma once
#ifndef _PAGEPROJTAGQUERY_H_
#define _PAGEPROJTAGQUERY_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������Ŀ��ǩQuery����ģ��
 * �����ˣ�Andrew
 */
class PageProjTagQuery : public oatpp::DTO
{
	DTO_INIT(PageProjTagQuery, DTO);
	DTO_FIELD_INFO(size) {
		info->description = ZH_WORDS_GETTER("projTag.pageQuery.size");
	}
	DTO_FIELD(UInt8, size);
	DTO_FIELD_INFO(page) {
		info->description = ZH_WORDS_GETTER("projTag.pageQuery.page");
	}
	DTO_FIELD(UInt8, page);
	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("projTag.pageQuery.sort");
	}
	DTO_FIELD(String, sort);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PAGEPROJTAGQUERY_H_