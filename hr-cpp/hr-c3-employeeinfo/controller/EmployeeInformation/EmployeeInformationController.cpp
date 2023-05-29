#include "stdafx.h"
#include "EmployeeInformationController.h"
#include "service/EmployeeInformation/EmployeeInformationServicer.h"

//��ҳ��ѯԱ���б�
EmployeeInformationPageJsonVO::Wrapper EmployeeInformationController::execEmployeeInformation(const EmployeeInformationPageQuery::Wrapper& query)
{
	// ����һ��Service
	EmployeeInformationServicer service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = EmployeeInformationPageJsonVO::createShared();
	jvo->success(result);
	return jvo;

}
//����Ա����Ϣ
Uint64JsonVO::Wrapper EmployeeInformationController::execImportEmployeeInfo(const EmployeeInformationDTO::Wrapper& importInfo)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!importInfo->id || !importInfo->name)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (importInfo->id->empty() || importInfo->name->empty() || importInfo->age < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	EmployeeInformationServicer service;
	// ִ����������
	uint64_t id = service.saveData(importInfo);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;

}
//����Ա����Ϣ(������ҳ��ǰ�����)
StringJsonVO::Wrapper EmployeeInformationController::execExportEmployeeInfo(const EmployeeExportQuery::Wrapper& query)
{
	auto jvo = StringJsonVO::createShared();
	// ����һ��Service
	EmployeeInformationServicer service;
	//// ��ѯ����
	// auto result = service.exportData(query);
	// if (!result.empty()) {
	// 	jvo->success(result);
	// } else {
	// 	jvo->fail("export fail");
	// }
	return jvo;
}

//����Ա����Ϣ 
Uint64JsonVO::Wrapper EmployeeInformationController::execAddEmployee(const EmployeeInformationDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->id || !dto->name)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->id->empty() || dto->name->empty()|| dto->age < 0 )
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	EmployeeInformationServicer service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}