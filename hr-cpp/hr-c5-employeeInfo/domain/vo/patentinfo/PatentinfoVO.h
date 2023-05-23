#ifndef _SAMPLE_VO_
#define _SAMPLE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/patentinfo/patentinfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)



/**
 * ר����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PatentinfoJsonVO : public JsonVO<PatentinfoDTO::Wrapper> {
	DTO_INIT(PatentinfoJsonVO, JsonVO<PatentinfoDTO::Wrapper>);
};




/**
 * ר����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */ 
class PatentinfoPageJsonVO : public JsonVO<PatentinfoPageDTO::Wrapper> {
	DTO_INIT(PatentinfoPageJsonVO, JsonVO<PatentinfoPageDTO::Wrapper>);
};





#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_