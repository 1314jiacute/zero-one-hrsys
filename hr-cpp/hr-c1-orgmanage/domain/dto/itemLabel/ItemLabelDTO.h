#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/13 19:52:05

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
#ifndef _ITEMLABELDTO_H_
#define _ITEMLABELDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���Թ��ܴ�����������
 */
class ItemLabelDTO : public oatpp::DTO
{
public:
	ItemLabelDTO() {};
	ItemLabelDTO(String id, String itemlabel,String name,Int64 xh,String createtime,String updatatime, String ormorgid):
		id(id),name(name),xh(xh),createtime(createtime), updatatime(updatatime), itemlabel(itemlabel), ormorgid(ormorgid) {};

	DTO_INIT(ItemLabelDTO, DTO);

	// ��Ŀ���
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.id");
	}
	// ������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.name");
	}
	//�����
	DTO_FIELD(Int64,xh);
	DTO_FIELD_INFO(xh) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.xh");
	}
	//����ʱ��
	 DTO_FIELD(String,createtime);
	DTO_FIELD_INFO(createtime) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.createtime");
	}
	//����ʱ��
	DTO_FIELD(String,updatatime);
	DTO_FIELD_INFO(updatatime) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.uptime");
	}
	// ��Ŀ��ǩ
	DTO_FIELD(String,itemlabel);
	DTO_FIELD_INFO(itemlabel) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.label");
	}
	//��֯ID
	DTO_FIELD(String,ormorgid);
	DTO_FIELD_INFO(ormorgid) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.ormorgid");
	}
};

/**
 * ���Թ��ܷ�ҳ������������
 */
class ItemLabelPageDTO : public PageDTO<ItemLabelDTO::Wrapper>
{
	DTO_INIT(ItemLabelPageDTO, PageDTO<ItemLabelDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_TESTDTO_H_
