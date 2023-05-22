#pragma once
#ifndef MEMBER_DTO
#define MEMBER_DTO
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
	// ��λ
	DTO_FIELD(String, gw);
	DTO_FIELD_INFO(gw) {
		info->description = ZH_WORDS_GETTER("member.field.gw");
	}
	// ֤������
	DTO_FIELD(String, zjhm);
	DTO_FIELD_INFO(zjhm) {
		info->description = ZH_WORDS_GETTER("member.field.zjhm");
	}
	// ��������
	DTO_FIELD(String, csrq);
	DTO_FIELD_INFO(csrq) {
		info->description = ZH_WORDS_GETTER("member.field.csrq");
	}
	// ���
	DTO_FIELD(String, nj);
	DTO_FIELD_INFO(nj) {
		info->description = ZH_WORDS_GETTER("member.field.nj");
	}
	// ��ϵ�绰
	DTO_FIELD(String, lxdh);
	DTO_FIELD_INFO(lxdh) {
		info->description = ZH_WORDS_GETTER("member.field.lxdh");
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