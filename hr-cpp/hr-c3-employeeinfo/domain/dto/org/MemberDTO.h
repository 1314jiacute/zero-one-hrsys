#pragma once

#ifndef _Member_DTO_
#define _Member_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class MemberDTO : public oatpp::DTO
{
	DTO_INIT(MemberDTO, DTO);
    // Ա�����
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("member.field.ygbh");
	}
    // Ա������
	DTO_FIELD(String, pimpersonname);
	DTO_FIELD_INFO(pimpersonname) {
		info->description = ZH_WORDS_GETTER("member.field.pimpersonname");
	}
    // ��֯
	DTO_FIELD(String, ormorgname);
	DTO_FIELD_INFO(ormorgname) {
		info->description = ZH_WORDS_GETTER("member.field.ormorgname");
	}
    // ����
	DTO_FIELD(String, ormorgsectorname);
	DTO_FIELD_INFO(ormorgsectorname) {
		info->description = ZH_WORDS_GETTER("member.field.ormorgsectorname");
	}
    // ְ��
	DTO_FIELD(String, zw);
	DTO_FIELD_INFO(zw) {
		info->description = ZH_WORDS_GETTER("member.field.zw");
	}
};

/**
 * ʾ����ҳ�������
 */
class PageMember : public PageDTO<MemberDTO::Wrapper> 
{
	DTO_INIT(PageMember, PageDTO<MemberDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_Member_DTO_