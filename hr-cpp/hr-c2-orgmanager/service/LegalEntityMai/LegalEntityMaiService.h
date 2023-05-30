#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/20 14:36:04

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
#ifndef _LEGALENTITYMAISERVICE_H_
#define _LEGALENTITYMAISERVICE_H_
#include <list>
#include "domain/dto/LegalEntityMai/LegalEntityMaiDTO.h"
#include "domain/query/LegalEntityMai/LegalEntityMaiQuery.h"
#include "domain/dto/LegalEntityMai/LegalEntityMaiDelDTO.h"
#include "domain/dto/LegalEntityMai/LegalEntityMaiAddDTO.h"

/* ��������ά������ʵ��--����֯����-��������-��������ά����--TripleGold */
class LegalEntityMaiService
{
public:
	// ��ҳ��ѯ��������
	LegalEntityMaiPageDTO::Wrapper listAll(const LegalEntityMaiQuery::Wrapper& query);
	// �޸�����
	bool updateData(const LegalEntityMaiDTO::Wrapper& dto);
	// ��������
	uint64_t saveData(const LegalEntityMaiAddDTO::Wrapper& dto, const PayloadDTO& payload);
	// �����ļ�
	uint64_t savaBatchDataWithFile(const std::string fileName, const PayloadDTO& payload);
	// ͨ��ID����ɾ������
	bool deleteById(const LegalEntityMaiDelDTO::Wrapper& dto);
	// �����ļ�
	std::string exportFile(const LegalEntityMaiQuery::Wrapper& query);
};

#endif // !_LEGALENTITYMAISERVICE_H_