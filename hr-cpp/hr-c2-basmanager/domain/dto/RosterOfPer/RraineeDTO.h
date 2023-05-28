#pragma once
#ifndef _RRAINEE_DTO_
#define _RRAINEE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  �������� ���� ��Ա������ ���� ��ϰԱ��  ����Cpt
 */
class RraineeDTO : public oatpp::DTO {
	DTO_INIT(RraineeDTO, DTO);
	// Ա�����
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("RosterOfPer.field.ygbh");
	}
	// Ա������
	DTO_FIELD(String, pcmjxszzkhjgjlname);
	DTO_FIELD_INFO(pcmjxszzkhjgjlname) {
		info->description = ZH_WORDS_GETTER("RosterOfPer.field.pcmjxszzkhjgjlname");
	}
};

/**
 * ʾ����ҳ�������
 */
class RraineePageDTO: public PageDTO<RraineeDTO::Wrapper> {
	DTO_INIT(RraineePageDTO, PageDTO<RraineeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RRAINEE_DTO_