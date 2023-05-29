#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/16 14:20:46

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _LEGALENTITYMAI_ADD_DTO_H_
#define _LEGALENTITYMAI_ADD_DTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/* ������������ά����������DTO--����֯����-��������-��������ά����--TripleGold */
class LegalEntityMaiAddDTO : public oatpp::DTO
{
public:
	LegalEntityMaiAddDTO() {};
	// �вι��캯��
	LegalEntityMaiAddDTO(String name, String orgcode) : ORMSIGNORGNAME(name), ORGCODE(orgcode) {};

	DTO_INIT(LegalEntityMaiAddDTO, DTO);
	// ������������
	DTO_FIELD(String, ORMSIGNORGNAME);
	DTO_FIELD_INFO(ORMSIGNORGNAME) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.name");
	}
	// ��֯���
	DTO_FIELD(String, ORGCODE);
	DTO_FIELD_INFO(ORGCODE) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.orgcode");
	}

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LEGALENTITYMAI_ADD_DTO_H_