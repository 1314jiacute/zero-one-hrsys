#pragma once

#ifndef _CREATE_NEW_CER_VO_
#define _CREATE_NEW_CER_VO_

#include "../../GlobalInclude.h"
#include "../../dto/CertificateManage/CreateNewCerDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class CreateNewCerJsonVO : public JsonVO<CreateNewCerDTO::Wrapper> {
	DTO_INIT(CreateNewCerJsonVO, JsonVO<CreateNewCerDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class CreateNewCerPageJsonVO : public JsonVO<CreateNewCerPageDTO::Wrapper> {
	DTO_INIT(CreateNewCerPageJsonVO, JsonVO<CreateNewCerPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 