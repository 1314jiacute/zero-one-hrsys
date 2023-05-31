#pragma once

#ifndef _LEGALENTITYSET_VO_
#define _LEGALENTITYSET_VO_

/*
*��	�������á��������������� ����  cpt

�����������������б� `LegalerNamePullDownList`

����ָ������������Ϣ  `UpdateLegalerSettingMessage`

������������ `ExportLegalerSeting`

�����������ã�֧������������** `AddLegalerSeting`
*/


#include "../../GlobalInclude.h"
#include "domain/dto/LegalEntitySet/LegalEntitySetDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class LegalEntitySetJsonVO : public JsonVO<LegalEntitySetDTO::Wrapper> {
	DTO_INIT(LegalEntitySetJsonVO, JsonVO<LegalEntitySetDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class LegalEntitySetPageJsonVO : public JsonVO<LegalEntitySetPageDTO::Wrapper> {
	DTO_INIT(LegalEntitySetPageJsonVO, JsonVO<LegalEntitySetPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LEGALENTITYSET_VO_