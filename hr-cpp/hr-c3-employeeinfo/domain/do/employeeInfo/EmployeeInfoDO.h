#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/05/23 19:17:19

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
#ifndef _EMPLOYEEINFODO_H_
#define _EMPLOYEEINFODO_H_
#include "../DoInclude.h"
/* *
* Ա����ϢDO
* ִ���ˣ�Detachment
*/
class EmployeeInfoDO
{
protected:
	CC_SYNTHESIZE(string, name, Name)
public:
	EmployeeInfoDO() {
		name = "";
	}
};

#endif // !_EMPLOYEEINFODO_H_