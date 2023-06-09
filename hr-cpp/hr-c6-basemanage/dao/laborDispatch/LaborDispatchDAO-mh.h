#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: mengHuan
 @Date: 2023/05/25 21:09:52

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
#ifndef _LABORDISPATCHDAO_H_
#define _LABORDISPATCHDAO_H_

#include "BaseDAO.h"
#include "domain/query/LaborDispatch/LaborDispatchQuery.h"
#include "domain/do/laborDispatch/LaborDispatchDO.h"
#include <string>

class LaborDispatchDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count_ld(const LaborDispatchQuery::Wrapper& query);
	//��ҳ��ѯ����
	list<LaborDispatchDO> selectWrithPage_Query(const LaborDispatchQuery::Wrapper& query);
	//��������
	uint64_t insert_ld(const LaborDispatchDO& iobj);
	// ͨ��IDɾ������
	int deleteById_ld(string id);
	//��ѯ��������
	list<LaborDispatchDO> selectWrithPage_Export(const LaborDispatchQuery::Wrapper& query);
};

#endif // !_LABORDISPATCHDAO_H_