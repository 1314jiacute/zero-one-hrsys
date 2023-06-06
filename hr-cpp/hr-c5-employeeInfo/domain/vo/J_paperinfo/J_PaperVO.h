#pragma once
#ifndef _J_PAPER_VO_
#define _J_PAPER_VO_

#include "../../GlobalInclude.h"
#include "../../dto/J_paperinfo/J_PaperinfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������Ϣ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PaperJsonVO : public JsonVO<PaperinfoDTO::Wrapper> {
	DTO_INIT(PaperJsonVO, JsonVO<PaperinfoDTO::Wrapper>);
};

class PaperinfoJsonVO : public JsonVO<PaperinfoDTO::Wrapper> {
	DTO_INIT(PaperinfoJsonVO, JsonVO<PaperinfoDTO::Wrapper>);
};



/**
 * ������Ϣ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PaperPageJsonVO : public JsonVO<PaperinfoPageDTO::Wrapper> {
	DTO_INIT(PaperPageJsonVO, JsonVO<PaperinfoPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 