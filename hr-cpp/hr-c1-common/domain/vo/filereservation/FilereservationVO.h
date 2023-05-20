#pragma once

#ifndef _FILERESERVATION_VO_
#define _FILERESERVATION_VO_

#include "../../GlobalInclude.h"
#include "../../dto/sample/SampleDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����״̬��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class FilereservationJsonVO : public JsonVO<SampleDTO::Wrapper> {
	DTO_INIT(FilereservationJsonVO, JsonVO<SampleDTO::Wrapper>);
};

/**
 * ����״̬��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class FilereservationPageJsonVO : public JsonVO<SamplePageDTO::Wrapper> {
	DTO_INIT(FilereservationPageJsonVO, JsonVO<SamplePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FILERESERVATION_VO_