/*
 Copyright Muggle. All rights reserved.

 @Author: Muggle
 @Date: 2023/05/19 23:27:39

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
#pragma once
#ifndef _LD_M_DTO_
#define _LD_M_DTO_
#include "../../GlobalInclude.h"
#include "domain/vo/JsonVO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class LaborDispatchMDTO : public oatpp::DTO
{
	DTO_INIT(LaborDispatchMDTO, DTO);
	/**
	 * ��˾����
	 */
	DTO_FIELD(String, corporateName);
	DTO_FIELD_INFO(corporateName) {
		info->description = ZH_WORDS_GETTER("labordispatch_mug.field.corporatename");
	}
	/**
	 * ��˾��ַ
	 */
	DTO_FIELD(String, corporateAddress);
	DTO_FIELD_INFO(corporateAddress) {
		info->description = ZH_WORDS_GETTER("labordispatch_mug.field.corporateaddress");
	}
	/**
	 * ��˾��ϵ��
	 */
	DTO_FIELD(String, corporateContact);
	DTO_FIELD_INFO(corporateContact) {
		info->description = ZH_WORDS_GETTER("labordispatch_mug.field.corporatecontact");
	}
	/**
	 * ��˾��ϵ�绰
	 */
	DTO_FIELD(String, corporateNumber);
	DTO_FIELD_INFO(corporateNumber) {
		info->description = ZH_WORDS_GETTER("labordispatch_mug.field.corporatenumber");
	}
};

class LaborDispatchUpdateDTO : public oatpp::DTO
{
	DTO_INIT(LaborDispatchUpdateDTO, DTO);
	//������ǲ��˾��������
	DTO_FIELD(String, corporateName);
	DTO_FIELD_INFO(corporateName) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.PIMLABOURCAMPANYNAME");
	}
	//��ϵ��ַ
	DTO_FIELD(String, contactAddress);
	DTO_FIELD_INFO(contactAddress) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.LXDZ");
	}
	//��ϵ��ʽ
	DTO_FIELD(String, contactNumber);
	DTO_FIELD_INFO(contactNumber) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.LXFS");
	}
	//��ϵ��
	DTO_FIELD(String, contactPerson);
	DTO_FIELD_INFO(contactPerson) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.LXR");
	}
	//��˾���
	DTO_FIELD(String, introduction);
	DTO_FIELD_INFO(introduction) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.GSJJ");
	}
	//ע�᱾��
	DTO_FIELD(String, registerdCapital);
	DTO_FIELD_INFO(registerdCapital) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.REGCAPITAL");
	}
	//����
	DTO_FIELD(String, legalPerson);
	DTO_FIELD_INFO(legalPerson) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.LEGALPERSON");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_LD_M_QUERY_