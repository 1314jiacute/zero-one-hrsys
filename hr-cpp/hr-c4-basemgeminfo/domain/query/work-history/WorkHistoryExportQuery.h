#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/17 8:53:26

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
#ifndef _WORKHISTORYEXPORTQUERY_H_
#define _WORKHISTORYEXPORTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)



class WorkHistoryExportQuery : public PageQuery
{
	DTO_INIT(WorkHistoryExportQuery, PageQuery);


	//��ְ��ʼʱ��
	DTO_FIELD(String, servebegintime);
	DTO_FIELD_INFO(servebegintime) {
		info->description = ZH_WORDS_GETTER("workhistory.field.servebegintime");
	}


	//��ְ����ʱ��
	DTO_FIELD(String, serveendtime);
	DTO_FIELD_INFO(serveendtime) {
		info->description = ZH_WORDS_GETTER("workhistory.field.serveendtime");
	}

	//������λ
	DTO_FIELD(String, workunit);
	DTO_FIELD_INFO(workunit) {
		info->description = ZH_WORDS_GETTER("workhistory.field.workunit");
	}

	//����
	DTO_FIELD(String, bm);
	DTO_FIELD_INFO(bm) {
		info->description = ZH_WORDS_GETTER("workhistory.field.BM");
	}

	//ְ��
	DTO_FIELD(String, zw);
	DTO_FIELD_INFO(zw) {
		info->description = ZH_WORDS_GETTER("workhistory.field.zw");
	}

	//��λ
	DTO_FIELD(String, gw);
	DTO_FIELD_INFO(gw) {
		info->description = ZH_WORDS_GETTER("workhistory.field.gw");
	}

	//ְ��
	DTO_FIELD(String, ormrankid);
	DTO_FIELD_INFO(ormrankid) {
		info->description = ZH_WORDS_GETTER("workhistory.field.ormrankid");
	}

	//��Ա��Ϣid
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("workhistory.field.pimpersionid");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_WORKHISTORYEXPORTQUERY_H_