#pragma once

#ifndef JOBTITLEYVO_H_
#define JOBTITLEYVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/JobTitleInfo/JobTitleInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������Ӧ���ͻ��˵�Json���󣬹���ְ����Ϣ
 */
class JobTitleInfoJsonVO : public JsonVO<JobTitleInfoDTO::Wrapper> {
	DTO_INIT(JobTitleInfoJsonVO, JsonVO<JobTitleInfoDTO::Wrapper>);
};

class ExportJobTitleJsonVO : public JsonVO<Vector<JobTitleInfoDTO::Wrapper>> {
	DTO_INIT(ExportJobTitleJsonVO, JsonVO<Vector<JobTitleInfoDTO::Wrapper>>)
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_