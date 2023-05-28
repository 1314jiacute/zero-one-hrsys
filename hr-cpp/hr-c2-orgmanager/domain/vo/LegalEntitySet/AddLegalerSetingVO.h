#pragma once
/*
*���������á��������������á������������������� (����ҳ����ǰ�����) --cpt
*/

#ifndef _ADDLEGALERSETTING_VO_
#define _ADDLEGALERSETTING_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/LegalEntitySet/AddLegalerSetingDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class AddLegalerSetingJsoonVO : public JsonVO<AddLegalerSetingDTO::Wrapper> {
	DTO_INIT(AddLegalerSetingJsoonVO, JsonVO<AddLegalerSetingDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class AddLegalerSetingPageJsonVO : public JsonVO<AddLegalerSetingDTO::Wrapper> {
	DTO_INIT(AddLegalerSetingPageJsonVO, JsonVO<AddLegalerSetingDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ADDLEGALERSETTING_VO_