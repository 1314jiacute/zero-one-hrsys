#include "stdafx.h"
#include "PimarmycadresService.h"
#include "dao/pimarmycadres/PimarmycadresDAO.h"
#include "domain/do/pimarmycadres/DelPimarmycadresDO.h"
#include "domain/do/pimarmycadres/AddPimarmycadresDO.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "domain/do/pimarmycadres/PimarmycadresIntoDO.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"
#include "FastDfsClient.h"


uint64_t PimarmycadresService::saveManyData(const std::string fileName, const oatpp::String& pimpersonid, const oatpp::String& createName)
{
	FastDfsClient client("8.130.87.15");

	string name;
	if (!fileName.empty())
	{
		std::string path = "";
		name = client.downloadFile(fileName,&path );
		std::cout << "download savepath is : " << name << std::endl;
	}

	// ���浽�ļ�
	ExcelComponent excel;

	std::string sheetName = CharsetConvertHepler::ansiToUtf8("��ת�ɲ���");
	// ���ļ��ж�ȡ
	auto readData = excel.readIntoVector(name, sheetName);

	PimarmycadresDAO dao;

	SnowFlake sf(0, 31);

	bool tem = true;
	for (auto row : readData)
	{

		//�ж��ļ����Ƿ�������
		for (int j = 0; j < row.size(); ++j)
		{
			if (row[j].empty())
			{
				return -1;
			}
			std::cout << CharsetConvertHepler::utf8ToAnsi(row[j]) << "   ";
		}

		std::cout << endl;
		if (tem)
		{
			tem = false;
			continue;
		}
		AddPimarmycadresDO data(row);
		//ѩ���㷨����id
		data.setpIMARMYCADRESID(to_string(sf.nextId()));

		data.setpIMID(pimpersonid);
		//����ʱ��
		SimpleDateTimeFormat times;
		data.setcREATEDATE(times.format());
		data.setuPDATEDATE(times.format());
		data.setcREATEMAN(createName);
		data.setuPDATEMAN(createName);

		//��������
		dao.insert(data);

	}
	return uint64_t(1);

}

PimarmycadresDTO::Wrapper PimarmycadresService::listDetail(const PimarmycadresQuery::Wrapper& query)
{
	// �������ض���
	//auto lists = MilitaryDTO::createShared();
	PimarmycadresDAO dao;
	auto lists = dao.selectDetail(query);
	auto dto = PimarmycadresDTO::createShared();
	if (!lists.empty()) {
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, lists.front(), pimid, pIMID, 
			form, fORM, 
			level, lEVEL, 
			occurtime, oCCURTIME, 
			annexPath, aNNEXPATH);
	}
	return dto;
}

bool PimarmycadresService::updateData(const PimarmycadresDTO::Wrapper& dto)
{
	// ��װDO����
	PimarmycadresDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Pimid,pimid);
	// ִ�������޸�
	PimarmycadresDAO dao;
	return dao.update(data) == 1;
}


PimarmycadresFindPageDTO::Wrapper PimarmycadresService::listAll(const PimarmycadresPageQuery::Wrapper& query)
{
	// �������ض���
	auto pages = PimarmycadresFindPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	PimarmycadresDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<PimarmycadresFindDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (PimarmycadresFindDO sub : result)
	{
		auto dto = PimarmycadresFindDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, pimid, pIMID,
			form, fORM,
			level, lEVEL,
			occurtime,oCCURTIME,
			annexPath, aNNEXPATH);

		pages->addData(dto);
		dto.getPtr().get()->annexPath;
	}
	

	return pages;
}

uint64_t PimarmycadresService::saveData(const AddPimarmycadresDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ��װDO����
	AddPimarmycadresDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, pIMID,pimid,
		fORM,form,
		lEVEL,level,
		oCCURTIME,occurtime,
		aNNEXPATH,annexPath,
		pIMARMYCADRESID,pimarmycadresid)
		// ִ���������
		PimarmycadresDAO dao;
	SnowFlake sf(1, 4);
	SimpleDateTimeFormat times;
	data.setpIMARMYCADRESID(to_string(sf.nextId()));

	data.setcREATEMAN(payload.getUsername());
	data.setuPDATEMAN(payload.getUsername());
	data.setcREATEDATE(times.format());
	data.setuPDATEDATE(times.format());

		
	return dao.insert(data);
}


bool PimarmycadresService::removeData(const DelPimarmycadresDTO::Wrapper& dto)
{
	PimarmycadresDAO dao;
	std::string pimpersonid = dto->pimid;
	for (auto it = dto->deleteById->begin(); it != dto->deleteById->end(); ++it)
	{
		dao.deleteById(pimpersonid, *it);
	}
	return true;
}


