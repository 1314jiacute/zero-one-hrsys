#pragma once

#include "../../GlobalInclude.h"
#include "../../dto/org/MemberDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��ʾ���˵���ʾJsonVO����������Ӧ��ǰ��
 */
class MemberJsonVO : public JsonVO<PageMember::Wrapper>>
{
	DTO_INIT(MemberJsonVO, JsonVO<PageMember::Wrapper>>);
public:
	// �ڹ��캯����ʵ����data�б�
	MemberJsonVO() {
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MENUVO_H_