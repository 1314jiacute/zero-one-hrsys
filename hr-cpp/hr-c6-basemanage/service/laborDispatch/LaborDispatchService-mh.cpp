/*
 Copyright Zero One Star. All rights reserved.

 @Author: mengHuan
 @Date: 2023/05/25 21:08:20

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
#include "LaborDispatchService-mh.h"
#include "domain/do/laborDispatch/LaborDispatchDO.h"
#include "dao/laborDispatch/LaborDispatchDAO-mh.h"
#include "domain/dto/LaborDispatch/LaborDispatchDTO.h"
#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
#include "../hr-sample/Macros.h"
#include "FastDfsClient.h"


#define DO_TO_VECTOR(f) \
ss.clear(); \
ss << sub.get##f(); \
row.push_back(ss.str()); \
ss.str("");


LaborDispatchPageDTO::Wrapper LaborDispatchService::listAll_ld(const LaborDispatchQuery::Wrapper& query)
{
	//�������ض���
	auto pages = LaborDispatchPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	//��ѯ����������
	LaborDispatchDAO dao;
	uint64_t count = dao.count_ld(query);
	if (count <= 0)
	{
		return pages;
	}
	//��ҳ��������
	pages->total = count;
	pages->calcPages();
	list<LaborDispatchDO> result = dao.selectWrithPage_Query(query);
	//��DOת����DTO
	for (LaborDispatchDO sub : result)
	{
		auto dto = LaborDispatchDTO::createShared();
		dto->id = sub.getId();
		dto->name = sub.getName();
		dto->unit = sub.getUnit();
		dto->lxdz = sub.getLxdz();
		dto->lxfs = sub.getLxfs();
		dto->lxr = sub.getLxr();
		dto->legalperson = sub.getLegalperson();
		dto->regcapital = sub.getRegcapital();
		dto->updatedate = sub.getUpdatedate();
		pages->addData(dto);
	}
	return pages;
}

uint64_t LaborDispatchService::saveData_ld(const LaborDispatchModifyDTO::Wrapper& dto)
{
	//��װDO����
	LaborDispatchDO data;
	data.setName(dto->name.getValue(""));
	data.setUnit(dto->unit.getValue(""));
	data.setLxdz(dto->lxdz.getValue(""));
	data.setLxr(dto->lxdz.getValue(""));
	data.setLxfs(dto->lxfs.getValue(""));
	data.setLegalperson(dto->legalperson.getValue(""));
	data.setRegcapital(dto->regcapital.getValue(""));
	data.setGsjj(dto->gsjj.getValue(""));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,Name, name, Unit, unit, Lxdz, lxdz, Lxr, lxr, Lxfs, lxfs, Legalperson, legalperson, Regcapital, regcapital, Gsjj, gsjj)
	//ִ���������
	LaborDispatchDAO dao;
	return dao.insert_ld(data);
}

bool LaborDispatchService::removeData_ld(string id)
{
	LaborDispatchDAO dao;
	return dao.deleteById_ld(id) == 1;
}

std::string LaborDispatchService::LaborDispatchExport_ld(const LaborDispatchQuery::Wrapper& query)
{
	vector<vector<string>> data;
	LaborDispatchDAO dao;
	list<LaborDispatchDO> result =dao.selectWrithPage_Export(query);
	data.push_back({
		ZH_WORDS_GETTER("ldcompany.field.PIMLABOURCAMPANYNAME"),
		ZH_WORDS_GETTER("ldcompany.field.ORGNAME"),
		ZH_WORDS_GETTER("ldcompany.field.LXDZ"),
		ZH_WORDS_GETTER("ldcompany.field.LXR"),
		ZH_WORDS_GETTER("ldcompany.field.LXFS"),
		ZH_WORDS_GETTER("ldcompany.field.REGCAPITAL"),
		ZH_WORDS_GETTER("ldcompany.field.LEGALPEROSN"),
		ZH_WORDS_GETTER("ldcompany.field.UPDATEDATE")
		});
	stringstream ss;
	for (LaborDispatchDO sub : result) {
		vector<string> row;
		DO_TO_VECTOR(Name);
		DO_TO_VECTOR(Unit);
		DO_TO_VECTOR(Lxdz);
		DO_TO_VECTOR(Lxr);
		DO_TO_VECTOR(Lxfs);
		DO_TO_VECTOR(Regcapital);
		DO_TO_VECTOR(Legalperson);
		DO_TO_VECTOR(Updatedate);
		data.push_back(row);
	}
	ss << "./tmp/excel" << chrono::system_clock::now().time_since_epoch().count() << ".xlsx";
	string fileName = ss.str();
	string sheetName = CharsetConvertHepler::ansiToUtf8("sheet1");
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);

#ifdef LINUX
	//����ͻ��˶���
	FastDfsClient client("conf/client.conf");
#else
	//����ͻ��˶���
	FastDfsClient client("8.130.87.15");
#endif // LINUX
	//�ϴ�excel���
	string filedName = client.uploadFile(fileName);
	//ɾ����������ʱ�ļ�
	remove(fileName.c_str());
	//��������·��
	string filepath = "8.130.87.15:8888/" + filedName;
	return filepath;
}
