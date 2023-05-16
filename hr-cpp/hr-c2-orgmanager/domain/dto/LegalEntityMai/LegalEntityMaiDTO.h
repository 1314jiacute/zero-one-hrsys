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
#ifndef _LEGALENTITYMAIDTO_H_
#define _LEGALENTITYMAIDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/* ���巨���������ݴ������ */
class LegalEntityMaiDTO : public oatpp::DTO
{
public:
	LegalEntityMaiDTO() {};
	// �вι��캯��
	LegalEntityMaiDTO(String id, String updateman) : ORMSIGNORGID(id), UPDATEMAN(updateman) {};
	LegalEntityMaiDTO(String id, String updateman, String createman, String createdate, 
		String name, String updatedate, String orgcode, String shortForm) : 
		ORMSIGNORGID(id), UPDATEMAN(updateman), CREATEMAN(createman), CREATEDATE(createdate), 
		ORMSIGNORGNAME(name), UPDATEDATE(updatedate), ORGCODE(orgcode), ZZJC(shortForm){};
	DTO_INIT(LegalEntityMaiDTO, DTO);
	// ���������ʶ
	DTO_FIELD(String, ORMSIGNORGID);
	DTO_FIELD_INFO(ORMSIGNORGID) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.id");
	}
	// ������
	DTO_FIELD(String, UPDATEMAN);
	DTO_FIELD_INFO(UPDATEMAN) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.updateman");
	}
	// ������
	DTO_FIELD(String, CREATEMAN);
	DTO_FIELD_INFO(CREATEMAN) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.createman");
	}
	// ����ʱ��
	DTO_FIELD(String, CREATEDATE);
	DTO_FIELD_INFO(CREATEDATE) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.createdate");
	}
	// ������������
	DTO_FIELD(String, ORMSIGNORGNAME);
	DTO_FIELD_INFO(ORMSIGNORGNAME) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.name");
	}
	// ����ʱ��
	DTO_FIELD(String, UPDATEDATE);
	DTO_FIELD_INFO(UPDATEDATE) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.updatedate");
	}
	// ��֯���
	DTO_FIELD(String, ORGCODE);
	DTO_FIELD_INFO(ORGCODE) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.orgcode");
	}
	// ���
	DTO_FIELD(String, ZZJC);
	DTO_FIELD_INFO(ZZJC) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.short");
	}
};

/* ���巨�������ҳ������� */
class LegalEntityMaiPageDTO : public PageDTO<LegalEntityMaiDTO::Wrapper> 
{
	DTO_INIT(LegalEntityMaiPageDTO, PageDTO<LegalEntityMaiDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_LEGALENTITYMAI_H_