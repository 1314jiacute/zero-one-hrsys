#pragma once

#include "../../GlobalInclude.h"
#include "../../dto/org/OrgDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��ʾ���˵���ʾJsonVO����������Ӧ��ǰ��
 */
class OrgJsonVO : public JsonVO<PageOrg::Wrapper>>
{
	DTO_INIT(OrgJsonVO, JsonVO<PageOrg::Wrapper>>);
public:
	// �ڹ��캯����ʵ����data�б�
	OrgJsonVO() {
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MENUVO_H_