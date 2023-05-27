#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: jun
 @Date: 2023/05/21 1:24:39

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
#ifndef _LANGUAGE_SERVICE_
#define _LANGUAGE_SERVICE_
#include <list>
#include "domain/query/Language/LanguageQuery.h"
#include "domain/dto/Language/LanguageDTO.h"
#include "domain/query/LanguagePage/LanguagePageQuery.h"
#include "domain/dto/ImportLanguage/ImportLanguageDTO.h"

/**
 * ����������ط���ʵ��
 * �����ˣ���
 */
class LanguageService 
{
public:
	// ��ҳ��ѯ��������
	LanguagePageDTO::Wrapper listAll(const LanguagePageQuery::Wrapper& query);
	//��ѯ��������
	LanguageDTO::Wrapper queryOneData(const LanguageQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const LanguageDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const LanguageDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(string id, string languageType);
};
#endif // !_LANGUAGE_SERVICE_