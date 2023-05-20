#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/13 19:46:51

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
#ifndef _JOBCATEGORYQUERY_H_
#define _JOBCATEGORYQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class JobCategoryQuery : public PageQuery
{
	DTO_INIT(JobCategoryQuery, PageQuery);


	DTO_FIELD(String,job);
	DTO_FIELD_INFO(job) {
		info->description = ZH_WORDS_GETTER("common.file.job");
	}

};

#include OATPP_CODEGEN_END(DTO)

#endif 