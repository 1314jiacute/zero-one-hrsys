#include "stdafx.h"
#include "ContractController.h"
#include "service/akieService/ContractInfoService.h"
#include "FastDfsClient.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
ContractJsonVO_::Wrapper ContractController::execQueryContract(const ContractQuery_::Wrapper& query)
{
	// ������Ӧ����
	auto vo = ContractJsonVO_::createShared();

	auto data = ContractDTO_::createShared();
	// �ǿ�У��
	if (!query->id)
	{
		vo->init(data, RS_PARAMS_INVALID);
		return vo;
	}
	ContractInfoService service;

	auto dto = service.listContract(query);

	// ��Ӧ���
	vo->success(dto);
	return vo;
}

Uint64JsonVO::Wrapper ContractController::execUpdateContract(const ContractDTO_::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// �ǿ�У��
	if (!dto->id || !dto->name || !dto->type || !dto->variety || !dto->date || !dto->condition || !dto->department_m || !dto->department_c || !dto->date_end)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//����service����
	ContractInfoService service;

	// ִ�������޸�
	if (service.updateContract(dto)) {
		jvo->success(1);
	}
	else
	{
		jvo->fail(1);
	}
	return jvo;
}

StringJsonVO::Wrapper ContractController::execUploadContract(const String& fileBody, const String& suffix)
{
	// ����ʱ�������һ����ʱ�ļ�����
	std::stringstream ss;
	ss << "public/static/file/";

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

	//��ȡexcel
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("Sheet1");
	ExcelComponent excel;
	auto readData = excel.readIntoVector(fileName, sheetName);

	//����dto
	auto dto = ContractDTO_::createShared();
	//����service
	ContractInfoService service;
	//��ʾexcel����
	for (auto row : readData)
	{
		for (auto cellVal : row)
		{
			// ע�⣺����ʹ���˱���ת����Ŀ����Ϊ���ڿ���̨��ӡ��ʾ�����룬����ǽ�����д�����ݿ⣬��ô�Ͳ���Ҫ�ٽ��б���ת����
			cout << CharsetConvertHepler::utf8ToAnsi(cellVal) << ",";
		}
		cout << endl;
		dto->name = row[0];
		string tmp = row[1];
		dto->id = tmp.c_str();
		dto->type = row[2];
		dto->variety = row[3];
		dto->date = row[4];
		dto->condition = row[5];
		dto->department_m = row[6];
		dto->department_c = row[7];
		dto->date_end = row[8];
		dto->tip = row[9];
		service.saveData(dto);
	}

	auto vo = StringJsonVO::createShared();
	vo->success(String(ss.str().c_str()));

	return vo;
}



StringJsonVO::Wrapper ContractController::execDownloadContract(const ContractDownloadQuery::Wrapper& query)
{
	auto vo = StringJsonVO::createShared();


	// У��
	if (query->sequence->empty() || query->sequence != "ASC" && query->sequence != "DESC")
	{
		vo->init("error(contact akie)", RS_PARAMS_INVALID);
		return vo;
	}

	// ���5000��
	if (query->rows > 5000)
		query->rows = 5000;

	//����service����
	ContractInfoService service;
	string url = service.downloadContract(query);

	std::cout << url;
	//�ж�url�Ƿ�Ϊ��
	if (url.empty())
		vo->fail(url);
	else
		vo->success(url);
	return vo;
}
