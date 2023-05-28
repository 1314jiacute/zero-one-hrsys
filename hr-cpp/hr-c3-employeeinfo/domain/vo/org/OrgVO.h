#pragma once

#ifndef _ORG_VO_
#define _ORG_VO_
#include "../../GlobalInclude.h"
#include "../../dto/org/OrgDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��ʾ���˵���ʾJsonVO����������Ӧ��ǰ��
 */
class OrgJsonVO : public JsonVO<OrgPageDTO::Wrapper>
{
	DTO_INIT(OrgJsonVO, JsonVO<OrgPageDTO::Wrapper>);
public:
	// �ڹ��캯����ʵ����data�б�
	OrgJsonVO() {
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ORG_VO_