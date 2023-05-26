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
EmployeeInformationPageJsonVO::Wrapper EmployeeInformationController::execExportEmployeeInfo(const EmployeeInformationPageQuery::Wrapper& exportInfo)
{
	// ����һ��JsonVO����
	auto vo = EmployeeInformationPageJsonVO::createShared();
	// ����һ����ҳ����
	auto page = EmployeeInformationPageDTO::createShared();
	page->pageIndex = exportInfo->pageIndex;
	page->pageSize = exportInfo->pageSize;
	page->total = 20;
	page->calcPages();

	// ģ������ҳ����
	int64_t start = (page->pageIndex.getValue(1) - 1) * page->pageSize.getValue(1);
	int64_t end = start + page->pageSize.getValue(1);
	// �߽�ֵֵ����
	if (start >= page->total.getValue(0) || start < 0) {
		vo->fail(page);
		return vo;
	}
	if (end > page->total.getValue(0)) end = page->total.getValue(0);
	// ѭ�����ɲ�������
	for (int64_t i = start; i < end; i++)
	{
		auto user = EmployeeInformationDTO::createShared();
		user->name = exportInfo->name;
		user->age = exportInfo->age;
		user->id = exportInfo->id;
		user->organize = exportInfo->organize;
		user->depart = exportInfo->depart;
		user->job = exportInfo->job;
		user->post = exportInfo->post;
		user->idMum = exportInfo->idMum;
		user->birthday = exportInfo->birthday;
		user->phone = exportInfo->phone;
		user->state = exportInfo->state;
		page->addData(user);
	}
	vo->success(page);
	return vo;

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