#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _CREATE_NEW_CER_DTO_
#define _CREATE_NEW_CER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class CreateNewCerDTO : public oatpp::DTO
{
public:
	//�޲ι���
	CreateNewCerDTO() {};
	//�вι���
	//CreateNewCerDTO(UInt64 id, String name, Int32 age, String sex) {};
	//CreateNewCerDTO(UInt64 id, String name) :id(id), name(name) {};
	DTO_INIT(CreateNewCerDTO, DTO);
	// Ա�����
	DTO_FIELD(UInt64, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("cermanage.field.ygbh");
	}
	// ֤������
	DTO_FIELD(String, pimVocationalName);
	DTO_FIELD_INFO(pimVocationalName) {
		info->description = ZH_WORDS_GETTER("cermanage.field.pimVocationalName");
	}
};

/**
 * ʾ����ҳ�������
 */
class CreateNewCerPageDTO : public PageDTO<CreateNewCerDTO::Wrapper>
{
	DTO_INIT(CreateNewCerPageDTO, PageDTO<CreateNewCerDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // 