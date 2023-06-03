#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ahao
 @Date: 2023/5/22 14:58:43

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
#ifndef _ASSIGN_INFO_QUERY
#define _ASSIGN_INFO_QUERY


#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include "domain/dto/assignInfo/AssignInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����ָ��Ա��������Ϣ
 */
class AssignInfoQuery : public PageQuery
{
	DTO_INIT(AssignInfoQuery, PageQuery);
	//������Ϣ��ʶ
	API_DTO_FIELD_DEFAULT(String, assignId, ZH_WORDS_GETTER("employee.t_pimperson.assignId"));
	//���
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("employee.field.id"));
	// ����(�������η���)
	API_DTO_FIELD_DEFAULT(String, assign, ZH_WORDS_GETTER("employee.field.assign"));
	//����״̬
	API_DTO_FIELD_DEFAULT(String, assignState, ZH_WORDS_GETTER("employee.t_pimperson.assignState"));
	// ����
	API_DTO_FIELD_DEFAULT(String, etype, ZH_WORDS_GETTER("employee.field.etype"));
	// ��֯
	API_DTO_FIELD_DEFAULT(String, organize, ZH_WORDS_GETTER("employee.field.organize"));
	// ����
	API_DTO_FIELD_DEFAULT(String, depart, ZH_WORDS_GETTER("employee.field.depart"));
	// ְ��
	API_DTO_FIELD_DEFAULT(String, job, ZH_WORDS_GETTER("employee.field.job"));
	// ��λ
	API_DTO_FIELD_DEFAULT(String, post, ZH_WORDS_GETTER("employee.field.post"));
	// ��ְ��ʼʱ��
	API_DTO_FIELD_DEFAULT(String, startTime, ZH_WORDS_GETTER("employee.field.startTime"));
	// ��ְ����ʱ��
	API_DTO_FIELD_DEFAULT(String, endTime, ZH_WORDS_GETTER("employee.field.endTime"));
	//������
	API_DTO_FIELD_DEFAULT(String, createMan, ZH_WORDS_GETTER("employee.t_pimperson.createMan"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, createDate, ZH_WORDS_GETTER("employee.t_pimperson.createDate"));
	//������
	API_DTO_FIELD_DEFAULT(String, updateMan, ZH_WORDS_GETTER("employee.t_pimperson.updateMan"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, updateDate, ZH_WORDS_GETTER("employee.t_pimperson.updateDate"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ASSIGN_INFO_QUERY