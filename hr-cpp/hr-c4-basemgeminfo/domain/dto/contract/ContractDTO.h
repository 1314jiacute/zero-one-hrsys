#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/14 21:51:11

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
#ifndef _CONTRACTDTO_H_
#define _CONTRACTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* ���嵥����ͬ��Ϣ�������
*/
class ContractDTO : public oatpp::DTO
{
	DTO_INIT(ContractDTO, DTO);
	// Ա�����
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// Ա������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// Ա��������λ
	DTO_FIELD(String, unit);
	DTO_FIELD_INFO(unit) {
		info->description = ZH_WORDS_GETTER("contract.unit");
	}
	// Ա��״̬
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("contract.state");
	}
	// Ա��������λʱ��
	DTO_FIELD(String, unitTime);
	DTO_FIELD_INFO(unitTime) {
		info->description = ZH_WORDS_GETTER("contract.unitTime");
	}
	// ��ͬ���
	DTO_FIELD(String, contractID);
	DTO_FIELD_INFO(contractID) {
		info->description = ZH_WORDS_GETTER("contract.contractID");
	}
	// ��ͬǩ����λ
	DTO_FIELD(String, contractUnit);
	DTO_FIELD_INFO(contractUnit) {
		info->description = ZH_WORDS_GETTER("contract.contractUnit");
	}
	// ��ͬ���
	DTO_FIELD(String, contractCategory);
	DTO_FIELD_INFO(contractCategory) {
		info->description = ZH_WORDS_GETTER("contract.contractCategory");
	}
	// ��ͬ����
	DTO_FIELD(String, contractType);
	DTO_FIELD_INFO(contractType) {
		info->description = ZH_WORDS_GETTER("contract.contractType");
	}
	// ��ͬ��ʼ����
	DTO_FIELD(String, startDate);
	DTO_FIELD_INFO(startDate) {
		info->description = ZH_WORDS_GETTER("contract.startDate");
	}
	// ��ͬ��������
	DTO_FIELD(String, endDate);
	DTO_FIELD_INFO(endDate) {
		info->description = ZH_WORDS_GETTER("contract.endDate");
	}
	// ��ͬ״̬
	DTO_FIELD(String, contractStatus);
	DTO_FIELD_INFO(contractStatus) {
		info->description = ZH_WORDS_GETTER("contract.contractStatus");
	}
	// ��ͬʣ������
	DTO_FIELD(String, remaining);
	DTO_FIELD_INFO(remaining) {
		info->description = ZH_WORDS_GETTER("contract.remaining");
	}
	// ��ͬ���õ���ʱ��
	DTO_FIELD(String, trialExpiration);
	DTO_FIELD_INFO(trialExpiration) {
		info->description = ZH_WORDS_GETTER("contract.trialExpiration");
	}
};

/**
 * �����ҳ��ͬ��Ϣ�������
 */
class ContractPageDTO : public PageDTO<ContractDTO::Wrapper>
{
	DTO_INIT(ContractPageDTO, PageDTO<ContractDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CONTRACTDTO_H_