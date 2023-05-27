#include "stdafx.h"
#include "WorkHistoryService.h"
#include "dao/work-history/WorkHistoryDAO.h"
#include "domain/do/work-history/DelWorkHistoryDO.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "domain/do/work-history/WorkHistoryIntoDO.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"
#include "FastDfsClient.h"

WorkHistoryDTO::Wrapper WorkHistoryService::listDetail(const WorkHistoryQuery::Wrapper& query)
{
	// �������ض���
	//auto lists = MilitaryDTO::createShared();
	WorkHistoryDAO dao;
	auto lists = dao.selectDetail(query);
	auto dto = WorkHistoryDTO::createShared();
	if (!lists.empty()) {
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, lists.front(), rzkssj, Rzkssj,rzjssj, Rzjssj, ormorgname, Ormorgname, ormdutyname, Ormdutyname, ormpostname, Ormpostname, cfplx, Cfplx, enable,Enable);
	}
	return dto;
}

bool WorkHistoryService::updateData(const WorkHistoryDTO::Wrapper& dto)
{
	// ��װDO����
	WorkHistoryDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Rzkssj, rzkssj, Rzjssj, rzjssj, Ormorgname, ormorgname, Ormdutyname, ormdutyname, Ormpostname, ormpostname, Cfplx, cfplx, Enable, enable);
	// ִ�������޸�
	WorkHistoryDAO dao;
	return dao.update(data) == 1;
}


WorkHistoryFindPageDTO::Wrapper WorkHistoryService::listAll(const WorkHistoryPageQuery::Wrapper& query)
{
	// �������ض���
	auto pages = WorkHistoryFindPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	WorkHistoryDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<WorkHistoryFindDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (WorkHistoryFindDO sub : result)
	{
		auto dto = WorkHistoryFindDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, rzkssj, rZKSSJ, rzjssj, rZJSSJ, \
			ormorgname, oRMORGNAME, ormorgsectorname, oRMORGSECTORNAME, \
			ormdutyname, oRMDUTYNAME, ormpostname, oRMPOSTNAME, cfplx, cFPLX, \
			experience, eXPERIENCE, pimworkhistoryid, pIMWORKHISTORYID, pimpersonid, pIMPERSONID);
		pages->addData(dto);

	}
	return pages;
}

uint64_t WorkHistoryService::saveData(const AddWorkHistoryDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ��װDO����
	SimpleDateTimeFormat times;
	AddWorkHistoryDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, rZKSSJ, rzkssj, \
		rZJSSJ, rzjssj, oRMORGNAME, ormorgname, oRMORGSECTORNAME, \
		ormorgsectorname, oRMDUTYNAME, ormdutyname, oRMPOSTNAME, \
		ormpostname, cFPLX, cfplx, eXPERIENCE, experience, \
		pIMWORKHISTORYID, pimworkhistoryid, pIMPERSONID, pimpersonid);
		// ִ���������


	data.setcREATEMAN(payload.getUsername());
	data.setuPDATEMAN(payload.getUsername());
	data.setcREATEDATE(times.format());
	data.setuPDATEDATE(times.format());


	WorkHistoryDAO dao;
	return dao.insert(data);
}

bool WorkHistoryService::removeData(const DelWorkHistoryDTO::Wrapper& dto)
{
	/*// ��װDO����
	DelWorkHistoryDO data;


	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, pIMPERSONID, pimpersonid);*/

	WorkHistoryDAO dao;
	std::string pimpersonid = dto->pimpersonid;
	for (auto it = dto->deleteById->begin(); it != dto->deleteById->end(); ++it)
	{
		dao.deleteById(pimpersonid, *it);
	}
	return true;
}

uint64_t WorkHistoryService::saveManyData(const std::string fileName, const String& pimpersonid, const String& createName)
{

	FastDfsClient client("192.168.80.129");

	string name;
	if (!fileName.empty())
	{
		std::string path = "public/static/Excel/";
		name = client.downloadFile(fileName, &path);
		std::cout << "download savepath is : " << name << std::endl;
	}

	// ���浽�ļ�
	ExcelComponent excel;

	std::string sheetName = CharsetConvertHepler::ansiToUtf8("����������");
	// ���ļ��ж�ȡ
	auto readData = excel.readIntoVector(name, sheetName);

	WorkHistoryDAO dao;
	
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
		AddWorkHistoryDO data(row);
		//ѩ���㷨��������id
		data.setpIMWORKHISTORYID(to_string(sf.nextId()));

		//�ж���˭�Ĺ�������
		data.setpIMPERSONID(pimpersonid);

		//����ʱ��
		SimpleDateTimeFormat times;
		data.setcREATEDATE(times.format());
		data.setuPDATEDATE(times.format());
		data.setcREATEMAN(createName);
		data.setuPDATEMAN(createName);

		//��������
		dao.insert(data);

	}

}

std::string WorkHistoryService::exportData(const WorkHistoryExportQuery::Wrapper& query)
{

	// ������������(ʵ���ǰ����ݿ�����ݷŽ���)


	WorkHistoryDAO dao;
	auto listData = dao.selectAllData(query);
	std::vector<std::vector<std::string>> datas;
	//������ͷ
	std::vector<std::string> rowHead;
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("��ְ��ʼʱ��"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("��ְ����ʱ��"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("������λ"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("����"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("ְ��"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("��λ"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("��ְ�������"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("�Ƿ���Ҫ����"));
	datas.push_back(rowHead);


	//�������ݵ�Excel��
	for (auto row : listData)
	{
		std::vector<std::string> vecStr(row.WorkHistoryToVector());
		datas.push_back(vecStr);
	}

	std::stringstream ss;
	ss << "public/static/Excel/";

	// ����ʱ���
	auto now = std::chrono::system_clock::now();
	auto tm_t = std::chrono::system_clock::to_time_t(now);
	ss << std::put_time(std::localtime(&tm_t), "%Y%m%d%H%M%S");
	// ��ȡ����
	auto tSeconds = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
	auto tMilli = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
	auto ms = tMilli - tSeconds;
	ss << std::setfill('0') << std::setw(3) << ms.count();
	// ƴ�Ӻ�׺��
	ss << ".xlsx";

	std::string fileName = ss.str();
	// ע�⣺��Ϊxlnt���ܴ洢��utf8������ַ���������������Ҫת������
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("����������");

	// ���浽�ļ�
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, datas);

	//�����Ƿ�������
	// ���ļ��ж�ȡ
	//auto readData = excel.readIntoVector(fileName, sheetName);
	//for (auto row : readData)
	//{
	//	//�ж��ļ����Ƿ�������
	//	for (int j = 0; j < row.size(); ++j)
	//	{
	//		cout << CharsetConvertHepler::utf8ToAnsi(row[j]) << "   ";
	//	}
	//	cout << endl;
	//}

	// �ļ�����
	//std::string fileName = ss.str();
	// �����ļ���Ŀ¼
	//String fileBody;
	//fileBody.saveToFile(fileName.c_str());


	// �ϴ���FastDFS�ļ�������
#ifdef LINUX
	//����ͻ��˶���
	FastDfsClient client("conf/client.conf", 3);
#else
	//����ͻ��˶���
	FastDfsClient client("192.168.80.129");
#endif
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;
	ss.str("");
	ss.clear();
	ss << "http://192.168.80.129:8888/" << fieldName;


	cout << ss.str() << endl;

	return ss.str();
}
