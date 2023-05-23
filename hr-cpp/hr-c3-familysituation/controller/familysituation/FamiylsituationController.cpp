#include "stdafx.h"
#include "FastDfsClient.h"
#include "FamilysituationController.h"

// ��ҳ��ѯ��Ӧ
FamilySituationPageJsonVO::Wrapper FamilysituationController::execQueryByFamilysituation(const FamilysituationQuery::Wrapper& query)
{
	auto vo = FamilySituationPageJsonVO::createShared();
	//������
	return vo;
}

// ָ����ѯ��Ӧ
FamilysituationJsonVO::Wrapper FamilysituationController::execOneQueryFamilysituation(const FamilysituationQuery::Wrapper& query)
{
	auto vo = FamilysituationJsonVO::createShared();
	//������
	return vo;
}


// �����Ӧ
StringJsonVO::Wrapper FamilysituationController::execAddFamilysituation(const FamilysituationDTO::Wrapper& dto)
{
	auto vo = StringJsonVO::createShared();
	vo->success("add success");
	return vo;
}

// �޸���Ӧ
StringJsonVO::Wrapper FamilysituationController::execModifyFamilysituation(const FamilysituationDTO::Wrapper& dto)
{
	auto vo = StringJsonVO::createShared();
	vo->success(dto->name);
	return vo;
}

// ɾ����Ӧ
StringJsonVO::Wrapper FamilysituationController::execRemoveFamilysituation(const FamilysituationDTO::Wrapper& dto)
{
	auto vo = StringJsonVO::createShared();
	vo->success(dto->name);
	return vo;
}

// ������Ӧ
StringJsonVO::Wrapper FamilysituationController::executeImportFamilysituation(const String& fileBody, const String& suffix)
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

//	// �����ϴ���FastDFS�ļ�������
//#ifdef LINUX
//	//����ͻ��˶���
//	FastDfsClient client("conf/client.conf", 3);
//#else
//	//����ͻ��˶���
//	FastDfsClient client("192.168.52.133");
//#endif
//	std::string fieldName = client.uploadFile(fileName);
//	std::cout << "upload fieldname is : " << fieldName << std::endl;
//	ss.str("");
//	ss.clear();
//	ss << "http://192.168.52.133:8888/" << fieldName;

	// excel�����߼�����ʱ����д��
	
	// ������Ӧ����
	auto vo = StringJsonVO::createShared();
	vo->success(String("cool"));
	return vo;
}


// ������Ӧ
StringJsonVO::Wrapper FamilysituationController::execExportFamilysituation(const String& url)
{
	auto vo = StringJsonVO::createShared();
	//������ ����һ����ַ
	return vo;
}

