#include "stdafx.h"
#include "LoanedPerPageService.h"
#include "../../dao/RosterOfPer/LoanedPerDAO.h"
#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include <cstdio>
/*
����Ա������-�����Ա����)--luoluo
*/
LoanedPerPageDTO::Wrapper LoanedPerPageService::listAll(const LoanedPerPageQuery::Wrapper& query)
{
	// �������ض���
	auto pages = LoanedPerPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	LoanedPerDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<SecondedPersonnelDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (SecondedPersonnelDO sub : result)
	{
		auto dto = LoanedPerDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, PIMDISTIRBUTIONID, PIMDISTIRBUTIONID, idAndName, idAndName, ygbh, ygbh, pimPersonName, pimPersonName, zz, zz, bm, bm, yzw, yzw,
			ygw, ygw, ormName, ormName, ormOrgSectorName, ormOrgSectorName, ormDutyName, ormDutyName, ormPostName, ormPostName,
			pcmydjdmxId, pcmydjdmxId, jdksrq, jdksrq, jdjsrq, jdjsrq);
		pages->addData(dto);
	}
	return pages;
}

std::string LoanedPerPageService::exportData(const LoanedPerPageQuery::Wrapper& query)
{
	//��ѯ���ݲ�����page�Ĵ�С��
	LoanedPerDAO dao;
	uint64_t count = dao.count(query);
	if (count > 5000) query->pageSize = 5000;
	else query->pageSize = count;
	query->pageIndex = 1;
	list<SecondedPersonnelDO> result = dao.selectWithPage(query);

	//����excel����
	std::vector<std::vector<std::string>> datas;
	//����excel��ͷ
	std::vector<std::string> head_datas;
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("Ա�����"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("Ա������"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("ԭ��֯"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("ԭ����"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("ԭְ��"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("ԭ��λ"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("����֯"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("�²���"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("��ְ��"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("�¸�λ"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("���״̬"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("�����ʼʱ��"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("�������ʱ��"));
	datas.push_back(head_datas);

	//�������
	for (auto data : result) {
		std::vector<std::string> row;
		row.push_back(data.getygbh());
		row.push_back(data.getpimPersonName());
		row.push_back(data.getzz());
		row.push_back(data.getbm());
		row.push_back(data.getyzw());
		row.push_back(data.getygw());
		row.push_back(data.getormName());
		row.push_back(data.getormOrgSectorName());
		row.push_back(data.getormDutyName());
		row.push_back(data.getormPostName());
		row.push_back(data.getpcmydjdmxId());
		row.push_back(data.getjdksrq());
		row.push_back(data.getjdjsrq());
		datas.push_back(row);
	}

	//�����ļ�����ҳǩ����
	std::string fileName = "./LoanedPerExport.xlsx";
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("���Ա����");
	// ���浽�ļ�
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, datas);

	// �ϴ�FastDFS�ļ�������
#ifdef LINUX
	//����ͻ��˶���
	FastDfsClient client("conf/client.conf", 3);
#else
	//����ͻ��˶���
	FastDfsClient client("8.130.87.15");
#endif
	//�ϴ��ļ�
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;
	remove(fileName.c_str());
	std::stringstream ss;
	ss << "http://8.130.87.15:8888/" << fieldName;
	return ss.str();
}
