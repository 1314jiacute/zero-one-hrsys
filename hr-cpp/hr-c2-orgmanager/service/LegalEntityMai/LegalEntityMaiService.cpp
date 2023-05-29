#include "stdafx.h"
#include "LegalEntityMaiService.h"
#include "dao/LegalEntityMai/LegalEntityMaiDAO.h"
#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"

/* ��������ά��Service�����ʵ��--����֯����-��������-��������ά����--TripleGold */
LegalEntityMaiPageDTO::Wrapper LegalEntityMaiService::listAll(const LegalEntityMaiQuery::Wrapper& query)
{
	// �������ض���
	auto pages = LegalEntityMaiPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	LegalEntityMaiDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<OrmsignorgDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (OrmsignorgDO sub : result)
	{
		auto dto = LegalEntityMaiDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ORMSIGNORGID, Id, ORMSIGNORGNAME, Name,ORGCODE, Code);
		/*ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ORMSIGNORGID, ORMSIGNORGID,
			UPDATEMAN, UPDATEMAN, CREATEMAN, CREATEMAN,
			CREATEDATE, CREATEDATE, ORMSIGNORGNAME, ORMSIGNORGNAME,
			UPDATEDATE, UPDATEDATE, ORGCODE, ORGCODE, ZZJC, ZZJC);*/
		pages->addData(dto);
	}
	return pages;
}

bool LegalEntityMaiService::updateData(const LegalEntityMaiDTO::Wrapper& dto)
{
	// ��װDO����
	OrmsignorgDO data;
	/*data.setId(dto->ORMSIGNORGID.getValue(""));
	data.setName(dto->ORMSIGNORGNAME.getValue(""));
	data.setCode(dto->ORGCODE.getValue(""));*/
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, ORMSIGNORGID, Name, ORMSIGNORGNAME, Code, ORGCODE);
	// ִ���������
	LegalEntityMaiDAO dao;
	return dao.update(data) == 1;
}

uint64_t LegalEntityMaiService::saveData(const LegalEntityMaiDTO::Wrapper& dto)
{
	// ��װDO����
	OrmsignorgDO data;
	/*data.setName(dto->ORMSIGNORGNAME.getValue(""));
	data.setCode(dto->ORGCODE.getValue(""));*/
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, ORMSIGNORGID, Name, ORMSIGNORGNAME, Code, ORGCODE);
	// ִ���������
	LegalEntityMaiDAO dao;
	return dao.insert(data);
}

bool LegalEntityMaiService::removeData(string id)
{
	LegalEntityMaiDAO dao;
	return dao.deleteById(id) == 1;
}

//bool LegalEntityMaiService::importFile()
//{
//	return true;
//}
//

std::string LegalEntityMaiService::exportFile(const LegalEntityMaiQuery::Wrapper& query)
{
	// ������������
	LegalEntityMaiDAO dao;
	// ��������ѯ��������
	uint64_t cnt = dao.count(query);
	if (cnt > 5000) {
		query->pageSize = 5000;
	}
	else {
		query->pageSize = cnt;
	}
	// �õ���ѯ���
	list<OrmsignorgDO> res = dao.selectWithPage(query);
	
	
	std::vector<std::vector<std::string>> data;
	// ����Excel��ͷ
	std::vector<std::string> row;
	row.push_back("����������֯");
	row.push_back("��֯���");
	// ���ݲ�ѯ�������Excel����
	for (auto info : res)
	{
		row.clear();
		row.push_back(info.getName());
		row.push_back(info.getCode());
		data.push_back(row);
	}

	// ���屣������λ�ú�ҳǩ����
	std::string fileName = "./public/excel/LegalEntityMai.xlsx";
	// ע�⣺��Ϊxlnt���ܴ洢��utf8������ַ���������������Ҫת������
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("���������");

	// ���浽�ļ�
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);
	// ���ļ��ж�ȡ
	auto readData = excel.readIntoVector(fileName, sheetName);
	for (auto row : readData)
	{
		for (auto cellVal : row)
		{
			// ע�⣺����ʹ���˱���ת����Ŀ����Ϊ���ڿ���̨��ӡ��ʾ�����룬����ǽ�����д�����ݿ⣬��ô�Ͳ���Ҫ�ٽ��б���ת����
			cout << CharsetConvertHepler::utf8ToAnsi(cellVal) << ",";
		}
		cout << endl;
	}

	// �ϴ��ļ���FastDfs
#ifdef LINUX
//����ͻ��˶���
	FastDfsClient client("conf/client.conf");
#else
	//����ͻ��˶���
	FastDfsClient client("192.168.241.128");
#endif
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldName is: " << fieldName << std::endl;
	remove(fileName.c_str());
	// ��������·��
	std::string url;
	url = "http://192.168.241.128:8888/" + fileName;
	return url;
}

