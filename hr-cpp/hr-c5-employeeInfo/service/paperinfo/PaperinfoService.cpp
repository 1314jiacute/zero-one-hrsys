
#include "stdafx.h"
#include "PaperinfoService.h"
#include "../../dao/paperinfo/t_pimpaperDAO.h"

PaperPageDTO::Wrapper PaperinfoService::listByPimpersonId(const PaperQuery::Wrapper& query)
{
	// �������ض���
	auto pages = PaperPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	t_pimpaperDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<SampleDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (SampleDO sub : result)
	{
		auto dto = SampleDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, sex, Sex, age, Age)
			pages->addData(dto);

	}
	return pages;
}

uint64_t SampleService::saveData(const SampleDTO::Wrapper& dto)
{
	// ��װDO����
	SampleDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age)
		// ִ���������
		SampleDAO dao;
	return dao.insert(data);
}

bool SampleService::updateData(const SampleDTO::Wrapper& dto)
{
	// ��װDO����
	SampleDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age, Id, id)
		// ִ�������޸�
		SampleDAO dao;
	return dao.update(data) == 1;
}

bool SampleService::removeData(uint64_t id)
{
	SampleDAO dao;
	return dao.deleteById(id) == 1;
}
