#pragma once
#ifndef _Auditstatus_VO_
#define _Auditstatus_VO_

#include "../../GlobalInclude.h"
#include "../../dto/pullList/PullListDTO.h"
#include <domain/vo/BaseJsonVO.h>

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����б�VO����ģ��
 * �����ˣ�fengchu
 */
class PullListVO : public JsonVO<PullListDTO::Wrapper> {
	DTO_INIT(PullListVO, JsonVO<PullListDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_Auditstatus_VO_