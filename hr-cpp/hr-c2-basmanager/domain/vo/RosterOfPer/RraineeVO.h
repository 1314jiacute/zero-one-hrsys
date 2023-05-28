#pragma once
#ifndef _RRAINEE_VO_
#define _RRAINEE_VO_
#include "../../GlobalInclude.h"
#include "domain/dto/RosterOfPer/RraineeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  �������� ���� ��Ա������ ���� ��ϰԱ��   ����Cpt
 */
/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class RraineeJsonVO : public JsonVO<RraineeDTO::Wrapper> {
	DTO_INIT(RraineeJsonVO, JsonVO<RraineeDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
	class RraineePageJsonVO : public JsonVO<RraineeDTO::Wrapper> {
		DTO_INIT(RraineePageJsonVO, JsonVO<RraineeDTO::Wrapper>);
	};

#include OATPP_CODEGEN_END(DTO)

#endif // !_RRAINEE_VO_