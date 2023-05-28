/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/23 17:01:55

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
#include "ProjTagService.h"
#include "domain/do/projTag/ProjTagDO.h"
#include "dao/projTag/ProjTagDAO.h"
#include "SimpleDateTimeFormat.h"
#include "ExcelComponent.h"
#include "domain/vo/projTag/ImportTagVO.h"
// �ļ���DO��
#define FILE_TO_DO(target, src, f1, f2) target.set##f1(src##f2);
#define INDEX(x, y) [x][y]
#define ZO_STAR_FILE_TO_DO(target, src, ...) \
ZO_STAR_EXPAND(ZO_STAR_PASTE(target, src, FILE_TO_DO, __VA_ARGS__))


uint64_t ProjTagService::saveData(const ProjTagDTO::Wrapper& dto)
{
	// ��װDO����
	ProjTagDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, 
		Id, ormxmbqid,
		TagName, ormxmbqname,
		Creator, createman,
		CreateTime, createdate,
		Updater, updateman,
		UpdateTime, updatedate,
		OrgId, ormorgid
	);
	
	// ִ�в������
	ProjTagDAO dao;
	return dao.insert(data);

}

OrgListPageDTO::Wrapper ProjTagService::listOrgList(const OrgListQuery::Wrapper& query)
{
	// �������ض���
	auto dto = OrgListPageDTO::createShared();
	dto->pageIndex = query->pageIndex;
	dto->pageSize = query->pageSize;

	// ��ȡ��ѯ������
	ProjTagDAO dao;
	uint64_t cnt = dao.count(query);
	if (cnt <= 0)
	{
		return dto;
	}

	// ��ҳ��ѯ����
	dto->total = cnt;
	dto->calcPages();
	list<OrgListDO> res = dao.selectOrgList(query);
	// ��DOת��DTO
	for (OrgListDO item : res)
	{
		auto to_dto = OrgListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(to_dto, item, regionSubsidy, RegionSubsidy, flag, Flag, createby, CreateTime, updater, Updater, updateTime, UpdateTime, erpOrgId, ErpOrgId, belongRegion, BelongRegion, legalEntity, LegalEntity, levelCode, LevelCode, orgCode, OrgCode, orgId, OrgId, orgName, OrgName, porgId, PorgId, shortname, Shortname, belongou, Belongou, sign, Sign, orgAddrCode, OrgAddrCode, orgAddrOne, OrgAddrOne, orgAddrTwo, OrgAddrTwo, orgCreateTime, OrgCreateTime, name, Name, orgType, OrgType, correspondou, Correspondou);
		dto->addData(to_dto);
	}
	return dto;
}

bool ProjTagService::updateProjTag(const ModifyTagDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ��װDO����
	ProjTagDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, OrgId, orgId, TagName, tagName);
	data.setUpdater(payload.getUsername());
	data.setUpdateTime(SimpleDateTimeFormat::format());
	// TODO: ����dao�������ݿ�
	ProjTagDAO dao;
	return dao.updateProjTag(data);
}

ImportTagVO::Wrapper ProjTagService::addMultiTag(const ImportTagDTO::Wrapper& dto, const PayloadDTO& payload)
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
	list<ProjTagDO> all;
	for (int i = 1; i < data.size(); i++)
	{
		ProjTagDO tmp;
		ZO_STAR_FILE_TO_DO(tmp, data, 
			Id, INDEX(i, hash["ORMXMBQID"]),
			TagName, INDEX(i, hash["ORMXMBQNAME"]),
			OrgId, INDEX(i, hash["ORMORGID"])
		);

		tmp.setUpdateTime(day);
		tmp.setCreateTime(day);
		tmp.setUpdater(name);
		tmp.setCreator(name);
		all.push_back(tmp);
	}

	// ����DAO�������ݿ�
	ProjTagDAO dao;
	auto res = dao.insertMultiTag(all);

	// �������ض���
	auto vo = ImportTagVO::createShared();
	if (res.size())
	{
		for (auto item : res)
			vo->newId->push_back(item);
	}

	return vo;
}

std::string ProjTagService::exportProjTag(const ExportProjTagQuery::Wrapper& query)
{
	// TODO: ����DAO��ѯ��������

	// TODO: ��װ���ݵ�Excel�ļ�

	// TODO: �ϴ���FastDFS�ļ�������

	// TODO: �����������Ӳ�����
	return "";
}
