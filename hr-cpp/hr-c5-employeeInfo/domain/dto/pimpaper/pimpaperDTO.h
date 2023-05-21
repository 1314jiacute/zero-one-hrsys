#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ��ï��
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
#ifndef _PIMPAPER_DTO_
#define _PIMPAPER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class PimpaperDTO : public oatpp::DTO
{
public:
	PimpaperDTO() {}
	PimpaperDTO(UInt64 ygbh, String pimpersonname) : ygbh(ygbh), pimpersonname(pimpersonname) {}

	DTO_INIT(PimpaperDTO, DTO);
	
	//Ա�����
	DTO_FIELD(UInt64, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("sample.field.ygbh");
	}

	//Ա������
	DTO_FIELD(String, pimpersonname);
	DTO_FIELD_INFO(pimpersonname) {
		info->description = ZH_WORDS_GETTER("sample.field.pimpersonname");
	}

	////��������
	//DTO_FIELD(String, pimpapername);
	//DTO_FIELD_INFO(pimpapername) {
	//	info->description = ZH_WORDS_GETTER("sample.field.pimpapername");
	//}

	////������
	//DTO_FIELD(String, cbs);
	//DTO_FIELD_INFO(cbs) {
	//	info->description = ZH_WORDS_GETTER("sample.field.cbs");
	//}

	////��������
	//DTO_FIELD(String, kwmc);
	//DTO_FIELD_INFO(kwmc) {
	//	info->description = ZH_WORDS_GETTER("sample.field.kwmc");
	//}

	////��������
	//DTO_FIELD(String, gwqs);
	//DTO_FIELD_INFO(gwqs) {
	//	info->description = ZH_WORDS_GETTER("sample.field.gwqs");
	//}

	////����ʱ��
	//DTO_FIELD(String, fbsj);
	//DTO_FIELD_INFO(fbsj) {
	//	info->description = ZH_WORDS_GETTER("sample.field.fbsj");
	//}

	////���������������е�����
	//DTO_FIELD(UInt64, grzlwzzzdpm);
	//DTO_FIELD_INFO(grzlwzzzdpm) {
	//	info->description = ZH_WORDS_GETTER("sample.field.grzlwzzzdpm");
	//}

	////����
	//DTO_FIELD(String, fj);
	//DTO_FIELD_INFO(fj) {
	//	info->description = ZH_WORDS_GETTER("sample.field.fj");
	//}
};

/**
 * ��ҳ�������
 */
class PimpaperPageDTO : public PageDTO<PimpaperDTO::Wrapper>
{
	DTO_INIT(PimpaperPageDTO, PageDTO<PimpaperDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PIMPAPER_DTO_