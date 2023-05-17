#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/17 10:17:22

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
#ifndef _PROFCERTS_DTO_
#define _PROFCERTS_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ִ(ְ)ҵ�ʸ�֤�������б��ѯDTO
 */
class ProfCertsDTO : public oatpp::DTO
{
	DTO_INIT(ProfCertsDTO, DTO);
	// ִҵ�ʸ�רҵ����
	DTO_FIELD(String, pimQualMajorId);
	// ִҵ�ʸ�
	DTO_FIELD(String, pimQualMajorName);
	// ������
	DTO_FIELD(String, createMan);
	// ����ʱ��
	DTO_FIELD(String, createDate);
	// ENABLE
	DTO_FIELD(UInt64, enable);
	// ������
	DTO_FIELD(String, upDateMan);
	// ����ʱ��
	DTO_FIELD(String, upDateDate);
	// ִҵ�ʸ�����ʶ
	DTO_FIELD(String, pimQualTypeId);
	// ��֯��ʶ
	DTO_FIELD(String, ormOrgId);
	// ִҵ�ʸ����
	DTO_FIELD(String, professionalType);
	// רҵ����ְ��
	DTO_FIELD(String, zyjszw);
	// ����
	DTO_FIELD(String, quaLevel);
	// רҵ
	DTO_FIELD(String, quaMajor);
	// ��λ����
	DTO_FIELD(String, gwlx);
	// ��λ����
	DTO_FIELD(String, gwType);
	// ��λ����
	DTO_FIELD(String, gwzs);

};

/**
 * ִ(ְ)ҵ�ʸ�֤�������б��ҳ��ѯDTO
 */
class ProfCertsPageDTO : public PageDTO<ProfCertsDTO::Wrapper>
{
	DTO_INIT(ProfCertsPageDTO, PageDTO<ProfCertsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_