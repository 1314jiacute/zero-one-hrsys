#pragma once
#ifndef _ARCHIVEVO_H_
#define _ARCHIVEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/archive/archiveDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����������Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */
class archiveJsonVO : public JsonVO<archiveDTO::Wrapper>
{
	DTO_INIT(archiveJsonVO, JsonVO<archiveDTO::Wrapper>);
};

/**
 * ����һ����������Ϣ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class archivePageJsonVO : public JsonVO<archivePageDTO::Wrapper>
{
	DTO_INIT(archivePageJsonVO, JsonVO<archivePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif