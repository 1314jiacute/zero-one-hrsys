#pragma once

#ifndef _Member_Json_VO_
#define _Member_Json_VO_

#include "../../GlobalInclude.h"
#include "../../dto/org/MemberDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��ʾ���˵���ʾJsonVO����������Ӧ��ǰ��
 *///PageMember
class MemberJsonVO : public JsonVO<MemberDTO::Wrapper >
{
	DTO_INIT(MemberJsonVO, JsonVO<MemberDTO::Wrapper >);
public:
	// �ڹ��캯����ʵ����data�б�
	MemberJsonVO() {
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_Member_Json_VO_