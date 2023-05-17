#pragma once

#include "../../GlobalInclude.h"
#include "../../dto/org/OrgSectorDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��ʾ���˵���ʾJsonVO����������Ӧ��ǰ��
 */
class OrgSectorVO : public JsonVO<PageOrgSector::Wrapper>>
{
	DTO_INIT(OrgSectorVO, JsonVO<PageOrgSector::Wrapper>>);
public:
	// �ڹ��캯����ʵ����data�б�
	OrgSectorVO() {
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MENUVO_H_