#pragma once

#ifndef _FILERESERVATION_VO_
#define _FILERESERVATION_VO_

#include "../../GlobalInclude.h"

#include "domain/dto/pullList/PullListDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �������ܵ������б���ʾJsonVO��������Ӧ���ͻ��˵�Json����
 * �����ˣ�Զ��
 */
class FilereservationJsonVO : public JsonVO<PullListDTO::Wrapper> {
	DTO_INIT(FilereservationJsonVO, JsonVO<PullListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FILERESERVATION_VO_