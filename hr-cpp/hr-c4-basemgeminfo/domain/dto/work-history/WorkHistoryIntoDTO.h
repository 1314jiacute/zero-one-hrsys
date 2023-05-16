#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/16 10:12:44

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
#ifndef _WORKHISTORYINTODTO_H_
#define _WORKHISTORYINTODTO_H_
#define DTO_INIT_(type, field, name) DTO_FIELD(type, field); \
DTO_FIELD_INFO(field) { \
	info->description = ZH_WORDS_GETTER(name); \
}


#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class WorkHistoryDTO : public oatpp::DTO
{
	DTO_INIT(WorkHistoryDTO, DTO);


	////1��ְ��ʼʱ��
	DTO_INIT_(String, servebegintime, "addworkhistorydto.field.servebegintime")


	//2��ְ����ʱ��
	DTO_INIT_(String, serveendtime, "addworkhistorydto.field.serveendtime")

	//3������λ
	DTO_INIT_(String, workunit, "addworkhistorydto.field.workunit")

	//4����
	DTO_INIT_(String, bm, "addworkhistorydto.field.bm")

	//5ְ��
	DTO_INIT_(String, zw, "addworkhistorydto.field.zw")

	//6��λ
	DTO_INIT_(String, gw, "addworkhistorydto.field.gw")

	//7ְ��
	DTO_INIT_(String, ormrankid, "addworkhistorydto.field.ormrankid")

};


class WorkHistoryIntoDTO : public oatpp::DTO
{
	DTO_INIT(WorkHistoryIntoDTO, DTO);

	//��������list
	DTO_FIELD(List<WorkHistoryDTO>, listworkhistory) = {};
	DTO_FIELD_INFO(listworkhistory) {
		info->description = ZH_WORDS_GETTER("addworkhistorydto.field.listworkhistory");
	}

	//8��Ա��Ϣid
	DTO_INIT_(String, pimpersonid, "addworkhistorydto.field.pimpersonid")
	
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_WORKHISTORYINTODTO_H_