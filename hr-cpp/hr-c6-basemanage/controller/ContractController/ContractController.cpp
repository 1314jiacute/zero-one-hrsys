#include "stdafx.h"
#include "ContractController.h"
#include "service/akieService/ContractInfoService.h"
#include "FastDfsClient.h"
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

	ContractInfoService service;

	// ִ�������޸�
	if (service.updateContract(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
		//cout << 1 << endl;
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

	// �����ϴ���FastDFS�ļ�������
#ifdef LINUX
	//����ͻ��˶���
	FastDfsClient client("conf/client.conf", 3);
#else
	//����ͻ��˶���
	FastDfsClient client("8.130.87.15");
#endif
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;
	ss.str("");
	ss.clear();
	ss << "8.130.87.15:8888/" << fieldName;
	// ������Ӧ����
	auto vo = StringJsonVO::createShared();
	vo->success(String(ss.str().c_str()));
	return vo;
}











StringJsonVO::Wrapper ContractController::execDownloadContract(const ContractDownloadQuery::Wrapper& query)
{
	auto vo = StringJsonVO::createShared();

	// TODO: ����service��ȡ�����ļ���������



	// У��
	if (query->sequence != "ASC" && query->sequence != "DESC")
	{
		vo->init("error(please contact akie)", RS_PARAMS_INVALID);
		return vo;
	}

	vo->success("url/download");
	return vo;
}
