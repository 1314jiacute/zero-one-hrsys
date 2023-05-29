#pragma once
#ifndef _UPDATELEGALERSETINGMESSAGE_VO_
#define _UPDATELEGALERSETINGMESSAGE_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/LegalEntitySet/UpdateLegalerSetingMessageDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class UpdateLegalerSetingMessageJsonVO : public JsonVO<UpdateLegalerSetingMessageDTO::Wrapper> {
	DTO_INIT(UpdateLegalerSetingMessageJsonVO, JsonVO<UpdateLegalerSetingMessageDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class UpdateLegalerSetingMessagePageJsonVO : public JsonVO<UpdateLegalerSetingMessagePageDTO::Wrapper> {
	DTO_INIT(UpdateLegalerSetingMessagePageJsonVO, JsonVO<UpdateLegalerSetingMessagePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UPDATELEGALERSETINGMESSAGE_VO_