#include "stdafx.h"
#include "PatentinfoService.h"
#include "../../dao/patentinfo/PatentinfoDAO.h"

//��ѯ��������
PatentinfoDTO::Wrapper PatentinfoService::listAll(const PatentinfoQuery::Wrapper& query)
{
	// �������ض���
	auto pages = PatentinfoDTO::createShared();
	//pages->pageIndex = query->pageIndex;
	//pages->pageSize = query->pageSize;

	// ��ѯ����������
	PatentinfoDAO dao;
	/*uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}*/

	// ��ҳ��ѯ����
	//pages->total = count;
	//pages->calcPages();
	list<PatentinfoDO> result = dao.selectByPIMPATENTID(query);
	//��DOת����DTO
	for (PatentinfoDO sub : result)
	{
		auto dto = PatentinfoDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, zlh, ZLH,
			updatedate, UPDATEDATE,
			pimpatentid, PIMPATENTID,
			zlhqsj, ZLHQSJ,
			pimpatentname, PIMPATENTNAME,
			updateman, UPDATEMAN,
			createman, CREATEMAN,
			createdate, CREATEDATE,
			zlpzgb, ZLPZGB,
			pimpersonid, PIMPERSONID,
			jlss, JLSS,
			jlspzt, JLSPZT,
			jlglbh, JLGLBH,
			jlczz, JLCZZ,
			enclolure, ENCLOLURE,
			reason, REASON)
			//pages->addData(dto);

	}
	return pages;
}


// //��������
//uint64_t SampleService::saveData(const SampleDTO::Wrapper& dto)
//{
//	// ��װDO����
//	SampleDO data;
//	// 	data.setName(dto->name.getValue(""));
//	// 	data.setSex(dto->sex.getValue(""));
//	// 	data.setAge(dto->age.getValue(1));
//	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age)
//		// ִ���������
//		SampleDAO dao;
//	return dao.insert(data);
//}

// �޸�����
bool PatentinfoService::updateData(const PatentinfoDTO::Wrapper& dto)
{
	// ��װDO����
	PatentinfoDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ZLH, zlh,
										UPDATEDATE, updatedate,
										PIMPATENTID, pimpatentid,
										ZLHQSJ, zlhqsj,
										PIMPATENTNAME, pimpatentname,
										UPDATEMAN, updateman,
										CREATEMAN, createman,
										CREATEDATE, createdate,
										ZLPZGB, zlpzgb,
										PIMPERSONID, pimpersonid,
										JLSS, jlss,
										JLSPZT, jlspzt,
										JLGLBH, jlglbh,
										JLCZZ, jlczz,
										ENCLOLURE, enclolure,
										REASON, reason)
		// ִ�������޸�
		PatentinfoDAO dao;
	return dao.update(data) == 1;
}



// ͨ��IDɾ������
//bool SampleService::removeData(uint64_t id)
//{
//	SampleDAO dao;
//	return dao.deleteById(id) == 1;
//}
