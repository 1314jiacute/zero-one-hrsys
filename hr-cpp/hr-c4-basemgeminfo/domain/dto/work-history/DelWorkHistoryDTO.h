#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/15 16:18:49

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
#ifndef _DELWORKHISTORYDTO_H_
#define _DELWORKHISTORYDTO_H_
#define DTO_INIT_(type, field, name) DTO_FIELD(type, field); \
DTO_FIELD_INFO(field) { \
	info->description = ZH_WORDS_GETTER(name); \
}


#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DelWorkHistoryIdDTO : public oatpp::DTO
{
	DTO_INIT(DelWorkHistoryIdDTO, DTO);

	//����������ʶ
	DTO_INIT_(String, pimworkhistoryid, "delworkhistorydto.field.pimworkhistoryid")
};

class DelWorkHistoryDTO : public PageDTO<DelWorkHistoryIdDTO::Wrapper>
{
	DTO_INIT(DelWorkHistoryDTO, PageDTO<DelWorkHistoryIdDTO::Wrapper>);

	//��Ա��Ϣid
	DTO_INIT_(String, pimpersonid, "delworkhistorydto.field.pimpersonid")

};


#include OATPP_CODEGEN_END(DTO)

#endif // !_DELWORKHISTORYDTO_H_