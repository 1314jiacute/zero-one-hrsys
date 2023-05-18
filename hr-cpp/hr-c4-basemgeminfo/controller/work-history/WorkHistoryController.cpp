#include "stdafx.h"
#include "WorkHistoryController.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "FastDfsClient.h"
#include "service/work-history/WorkHistoryService.h"


WorkHistoryFindVO::Wrapper WorkHistoryController::execQueryWorkHistory(const WorkHistoryPageQuery::Wrapper& query)
{
	auto vo = WorkHistoryFindVO::createShared();

	auto pdto = WorkHistoryFindPageDTO::createShared();

	WorkHistoryService service;

	pdto = service.listAll(query);

	vo->success(pdto);

	return vo;
	
}

Uint64JsonVO::Wrapper WorkHistoryController::execAddWorkHistory(const AddWorkHistoryDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();

	if (!dto->bm || !dto->gw || !dto->experience || !dto->pimpersonid || !dto->rzjssj || \
		!dto->rzkssj || !dto->ormorgname || !dto->zw || !dto->cfplx || !dto->pimworkhistoryid)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	jvo->success(1);

	return jvo;
}

Uint64JsonVO::Wrapper WorkHistoryController::execDelWorkHistory(const DelWorkHistoryDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();

	int length = dto->deleteById->size();

	if (length <= 0 || !dto->pimpersonid)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	else
	{
		for (auto it = dto->deleteById->begin(); it != dto->deleteById->end(); ++it)
		{
			if (!(*it))
			{
				jvo->init(UInt64(-1), RS_PARAMS_INVALID);
				return jvo;
			}
		}
	}

	jvo->success(1);

	return jvo;

}

StringJsonVO::Wrapper WorkHistoryController::execIntoWorkHistory(const String fileBody, const String suffix)
{
	// ����ʱ�������һ����ʱ�ļ�����
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
	ss << suffix.getValue("");

	// ��ʱ�ļ�����
	std::string fileName = ss.str();
	// �����ļ�����ʱĿ¼
	fileBody.saveToFile(fileName.c_str());


	// ���浽�ļ�
	ExcelComponent excel;

	auto jvo = StringJsonVO::createShared();
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("��������");
	// ���ļ��ж�ȡ
	auto readData = excel.readIntoVector(fileName, sheetName);
	for (auto row : readData)
	{
		//�ж��ļ����Ƿ�������
		for (int j = 0; j < row.size(); ++j)
		{
			if (row[j].empty())
			{
				jvo->fail("�ļ�������");
				return jvo;
			}
			cout << CharsetConvertHepler::utf8ToAnsi(row[j]) << "   ";
		}
		cout << endl;


		//������ݵ�dto��



	}

	//ִ������߼�



	jvo->success("�ļ�����ɹ�");
	return jvo;
}

StringJsonVO::Wrapper WorkHistoryController::execExportWorkHistory(const WorkHistoryExportQuery::Wrapper& query)
{
	auto vo = StringJsonVO::createShared();

	// ������������(ʵ���ǰ����ݿ�����ݷŽ���)
	vector<vector<std::string>> data;
	stringstream ss1;
	for (int i = 1; i <= 10; i++)
	{
		vector<std::string> row;
		for (int j = 1; j <= 5; j++)
		{
			ss1.clear();
			// ע�⣺��Ϊxlnt���ܴ洢��utf8������ַ���������������Ҫת������
			ss1
				<< CharsetConvertHepler::ansiToUtf8("��Ԫ�����꣺(") << i
				<< CharsetConvertHepler::ansiToUtf8(",") << j << ")";
			row.push_back(ss1.str());
			ss1.str("");
		}
		data.push_back(row);
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
	ss << ".csv";

	std::string fileName = ss.str();
	// ע�⣺��Ϊxlnt���ܴ洢��utf8������ַ���������������Ҫת������
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("����������");

	// ���浽�ļ�
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);

	//�����Ƿ�������
	// ���ļ��ж�ȡ
	auto readData = excel.readIntoVector(fileName, sheetName);
	for (auto row : readData)
	{
		//�ж��ļ����Ƿ�������
		for (int j = 0; j < row.size(); ++j)
		{
			cout << CharsetConvertHepler::utf8ToAnsi(row[j]) << "   ";
		}
		cout << endl;
	}

	// �ļ�����
	//std::string fileName = ss.str();
	// �����ļ���Ŀ¼
	//String fileBody;
	//fileBody.saveToFile(fileName.c_str());

	
	// �����ϴ���FastDFS�ļ�������
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
	vo->success(u8"�����ɹ�");
	return vo;
}

