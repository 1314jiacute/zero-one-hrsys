#include "stdafx.h"
#include "EmployeeInformationController.h"
//#include "../../service/EmployeeInformation/EmployeeInformationService.h"

//��ҳ��ѯԱ���б�
EmployeeInformationPageJsonVO::Wrapper EmployeeInformationController::execEmployeeInformation(const EmployeeInformationPageQuery::Wrapper& query)
{
	// ����һ��Service
	//EmployeeInformationService service;
	// ��ѯ����
	//auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = EmployeeInformationPageJsonVO::createShared();
	return jvo;

}
//����Ա����Ϣ
EmployeeInformationPageJsonVO::Wrapper EmployeeInformationController::execImportEmployeeInfo(const EmployeeInformationPageQuery::Wrapper& importInfo)
{
	// ����һ��Service
	//EmployeeInformationService service;
	// ��ѯ����
	//auto result = service.listAll(importInfo);
	// ��Ӧ���
	auto jvo = EmployeeInformationPageJsonVO::createShared();
	//jvo->success(result);
	return jvo;

}
//����Ա����Ϣ(������ҳ��ǰ�����)
EmployeeInformationPageJsonVO::Wrapper EmployeeInformationController::execExportEmployeeInfo(const EmployeeInformationPageQuery::Wrapper& exportInfo)
{
	// ����һ��Service
	//EmployeeInformationService service;
	// ��ѯ����
	//auto result = service.listAll(exportInfo);
	// ��Ӧ���
	auto jvo = EmployeeInformationPageJsonVO::createShared();
	//jvo->success(result);
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
	if (dto->id->empty() || dto->name->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	//// ����һ��Service
	//EmployeeInformationService service;
	//// ִ����������
	//uint64_t id = service.saveData(dto);
	//if (id > 0) {
	//	jvo->success(UInt64(id));
	//}
	//else
	//{
	//	jvo->fail(UInt64(id));
	//}
	//��Ӧ���
	return jvo;
}