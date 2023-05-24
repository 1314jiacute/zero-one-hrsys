#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/24 19:36:34

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
#ifndef _ORGLISTDTO_H_
#define _ORGLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��֯�б�DTO����ģ��
 * �����ˣ�Andrew
 */
class OrgListDTO : public oatpp::DTO
{
	DTO_INIT(OrgListDTO, DTO);
	// ��֯ID
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// ��֯����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {

	}
	// ����ʱ��
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// ������
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// ����ʱ��
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// ������
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// ��֯����
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// ��֯���
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// ��֯������
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// ��֯����
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// ��֯��������
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// ��֯����OU����֯ID
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// ��������
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// ������׼
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// �ϼ���֯ID
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// ��λ
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// �ϻ�����ID
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
};

class OrgListPageDTO : public PageDTO<OrgListDTO::Wrapper>
{
	DTO_INIT(OrgListPageDTO, PageDTO<OrgListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ORGLISTDTO_H_