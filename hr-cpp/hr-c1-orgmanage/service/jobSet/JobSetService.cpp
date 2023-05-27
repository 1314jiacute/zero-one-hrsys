/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/27 7:25:35

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
#include "JobSetService.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
#include "domain/do/postSet/PostDetailDO.h"
#include "dao/jobSet/JobSetDAO.h"

// �ļ���DO��
#define FILE_TO_DO(target, src, f1, f2) target.set##f1(src##f2);
#define INDEX(x, y) [x][y]
#define ZO_STAR_FILE_TO_DO(target, src, ...) \
ZO_STAR_EXPAND(ZO_STAR_PASTE(target, src, FILE_TO_DO, __VA_ARGS__))

ImportJobVO::Wrapper JobSetService::addMultiJob(const ImportJobDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ����Excel����
	ExcelComponent excel;
	// ���ļ����ݶ�ȡ����
	auto data = excel.readIntoVector(std::string(dto->filePath), std::string(dto->sheetName));

	// �����ֶ�����ӳ��
	unordered_map<string, int> hash;
	for (int i = 0; i < data[0].size(); i++)
	{
		hash[data[0][i]] = i;
	}
	
	string name = payload.getUsername();
	string day = SimpleDateTimeFormat::format();
	// �ļ����ݵ�DO
	list<PostDetailDO> all;
	for (int i = 1; i < data.size(); i++)
	{
		PostDetailDO tmp;
		ZO_STAR_FILE_TO_DO(tmp, data, OrmPostId, INDEX(i, hash["ORMPOSTID"]),
			OrmPostName, INDEX(i, hash["ORMPOSTNAME"]),
			OrmOrgId, INDEX(i, hash["ORMORGID"]),
			GwType, INDEX(i, hash["GWTYPE"]),
			Gwfl, INDEX(i, hash["GWFL"]),
			IsConfidential, INDEX(i, hash["ISCONFIDENTIAL"]),
			IsTemp, INDEX(i, hash["ISTEMP"]),
			IsKeyPostion, INDEX(i, hash["ISKEYPOSTION"]),
			PostNature, INDEX(i, hash["POSTNATURE"]),
			StartStopSign, INDEX(i, hash["STARTSTOPSIGN"])
		);

		tmp.setUpdateDate(day);
		tmp.setCreateDate(day);
		tmp.setUpdateMan(name);
		tmp.setCreateMan(name);
		all.push_back(tmp);
	}

	// ����DAO�������ݿ�
	JobSetDAO dao;
	auto res = dao.insertMultiJob(all);
	
	// �������ض���
	auto vo = ImportJobVO::createShared();
	if (res.size())
	{ 
		for (auto item : res)
			vo->newId->push_back(item);
	}

	return vo;
}
