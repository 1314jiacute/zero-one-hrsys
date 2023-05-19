#pragma once
#ifndef _FILESTATUS_VO_
#define _FILESTATUS_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/pullList/PullListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����״̬�����б���ʾJsonVO��������Ӧ���ͻ��˵�Json����
 * �����ˣ�Զ��
 */
class FilestatusJsonVO : public JsonVO<PullListDTO::Wrapper> {
	DTO_INIT(FilestatusJsonVO, JsonVO<PullListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FILESTATUS_VO_