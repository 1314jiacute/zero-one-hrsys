#pragma once
#ifndef _FILESTATUS_VO_
#define _FILESTATUS_VO_

#include "../../GlobalInclude.h"
#include "../../dto/sample/SampleDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����״̬��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class FilestatusJsonVO : public JsonVO<SampleDTO::Wrapper> {
	DTO_INIT(FilestatusJsonVO, JsonVO<SampleDTO::Wrapper>);
};

/**
 * ����״̬��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class FilestatusPageJsonVO : public JsonVO<SamplePageDTO::Wrapper> {
	DTO_INIT(FilestatusPageJsonVO, JsonVO<SamplePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FILESTATUS_VO_