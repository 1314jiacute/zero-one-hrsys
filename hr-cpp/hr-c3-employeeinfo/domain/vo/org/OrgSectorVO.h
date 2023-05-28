#pragma once

#ifndef _Org_Sector_VO_
#define _Org_Sector_VO_

#include "../../GlobalInclude.h"
#include "../../dto/org/OrgSectorDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��ʾ���˵���ʾJsonVO����������Ӧ��ǰ��
 */
class OrgSectorVO : public JsonVO<OrgSectorPageDTO::Wrapper>
{
	DTO_INIT(OrgSectorVO, JsonVO<OrgSectorPageDTO::Wrapper>);
public:
	// �ڹ��캯����ʵ����data�б�
	OrgSectorVO() {
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_Org_Sector_VO_