#include "stdafx.h"
#include "PimarmycadresController.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "FastDfsClient.h"



PimarmycadresFindVO::Wrapper PimarmycadresController::execQueryPimarmycadres(const PimarmycadresPageQuery::Wrapper& query)
{
	auto vo = PimarmycadresFindVO::createShared();

	auto pdto = PimarmycadresFindPageDTO::createShared();

	vo->success(pdto);

	return vo;

}

Uint64JsonVO::Wrapper PimarmycadresController::execAddPimarmycadres(const AddPimarmycadresDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();

	if (!dto->level || !dto->form || !dto->occurtime || !dto->pimid) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	jvo->success(1);

	return jvo;
}

Uint64JsonVO::Wrapper PimarmycadresController::execDelPimarmycadres(const DelPimarmycadresDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();

	int length = dto->deleteById->size();

	if (length <= 0 || !dto->pimid)
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

StringJsonVO::Wrapper PimarmycadresController::execIntoPimarmycadres(const String body, const String suffix)
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
	body.saveToFile(fileName.c_str());


	// ���浽�ļ�
	ExcelComponent excel;

	auto jvo = StringJsonVO::createShared();
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("��ת�ɲ�");
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


