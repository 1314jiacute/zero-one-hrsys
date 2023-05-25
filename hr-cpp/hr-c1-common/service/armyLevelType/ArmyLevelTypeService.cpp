/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/23 19:26:11

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
#include "stdafx.h"
#include "ArmyLevelTypeService.h"
#include "uselib/pullListRedis/UseLibRedis.h"
#include "dao/armyLevelType/ArmyLevelTypeDAO.h"

PullListDTO::Wrapper ArmyLevelTypeService::listAll()
{
	// �������ض���
	auto res = PullListDTO::createShared();

	// TODO: ��ѯ����
	// �ӻ����л�ȡ��ת�б�
	auto hash = UseLibRedis::queryRedis("army-level-type");

	auto dto = PullListDTO::createShared();
	// ���Ϊ�������dao��ѯ���ݿ�
	if (hash.empty())
	{
		// TODO: ����dao��ѯ���ݿ�
		ArmyLevelTypeDAO dao;
	}
	// ������װ�������ݵ�DTO
	else
	{
		for (auto item : hash)
		{
			int code = atoi(item.first.c_str());
			dto->pullList->push_back(ItemDTO::createShared(code, item.second));
		}
	}
	return dto;
}

