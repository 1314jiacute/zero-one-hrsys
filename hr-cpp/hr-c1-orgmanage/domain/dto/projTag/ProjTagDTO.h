#pragma once
 /*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/19 15:02:24

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
#ifndef _PROJTAGDTO_H_
#define _PROJTAGDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ��Ŀ��ǩ��Ϣ
 * �����ˣ�Զ��
 */
class ProjTagDTO : public oatpp::DTO
{
	DTO_INIT(ProjTagDTO, DTO);
	
	// �������
	DTO_FIELD(String, orgname);
	DTO_FIELD_INFO(orgname) {
		info->description = ZH_WORDS_GETTER("projTag.field.orgname");
	}
	// ��Ŀ��ǩ
	DTO_FIELD(String, projecttag);
	DTO_FIELD_INFO(projecttag) {
		info->description = ZH_WORDS_GETTER("projTag.field.projecttag");
	}
	// ������
	DTO_FIELD(String, creater);
	DTO_FIELD_INFO(creater) {
		info->description = ZH_WORDS_GETTER("projTag.field.creater");
	}
	// ����ʱ��
	DTO_FIELD(String, creattime);
	DTO_FIELD_INFO(creattime) {
		info->description = ZH_WORDS_GETTER("projTag.field.creattime");
	}
	// ������
	DTO_FIELD(String, updater);
	DTO_FIELD_INFO(updater) {
		info->description = ZH_WORDS_GETTER("projTag.field.updater");
	}
	// ����ʱ��
	DTO_FIELD(String, updatetime);
	DTO_FIELD_INFO(updatetime) {
		info->description = ZH_WORDS_GETTER("projTag.field.updatetime");
	}
};
class ProjTagPageDTO : public PageDTO<ProjTagDTO::Wrapper>
{
	DTO_INIT(ProjTagPageDTO, PageDTO<ProjTagDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_PROJTAGDTO_H_