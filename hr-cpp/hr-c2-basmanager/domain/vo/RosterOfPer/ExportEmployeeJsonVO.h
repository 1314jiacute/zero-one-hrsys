#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:34:14

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
#ifndef _EXPORTEMPLOYEE_VO_
#define _EXPORTEMPLOYEE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/RosterOfPer/ExportEmployeeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ExportEmployeeJsonVO : public JsonVO<ExportEmployeeDTO::Wrapper> {
	DTO_INIT(ExportEmployeeJsonVO, JsonVO<ExportEmployeeDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ExportEmployeePageJsonVO : public JsonVO<ExportEmployeePageDTO::Wrapper> {
	DTO_INIT(ExportEmployeePageJsonVO, JsonVO<ExportEmployeePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EXPORTEMPLOYEE_VO_