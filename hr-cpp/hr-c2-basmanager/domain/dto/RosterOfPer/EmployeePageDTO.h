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
/*
����Ա������-��Ա������-��ҳ��ѯԱ���б�--����
*/
#ifndef _EMPLOYEE_PAGE_DTO_
#define _EMPLOYEE_PAGE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ʾ���������
 */
class EmployeeDTO : public oatpp::DTO
{
	DTO_INIT(EmployeeDTO, DTO);
	// Ա������
	DTO_FIELD(String, EMPLOYEENAME);
	DTO_FIELD_INFO(EMPLOYEENAME) {
		info->description = ZH_WORDS_GETTER("employee.field.employeename");
	}
	// Ա�����
	DTO_FIELD(String, EMPLOYEEID);
	DTO_FIELD_INFO(EMPLOYEEID) {
		info->description = ZH_WORDS_GETTER("employee.field.employeeid");
	}
};
/**
 * ʾ����ҳ�������
 */
class EmployeePageDTO : public PageDTO<EmployeeDTO::Wrapper>
{
	DTO_INIT(EmployeePageDTO, PageDTO<EmployeeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
