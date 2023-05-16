#include "stdafx.h"//cpp�ļ���һ���µ���Ԥ�����ͷ
#include "TestController.h"
#include "../arch-demo/service/sample/SampleService.h"
#include "domain/dto/sample/ContractDTO.h"
StringJsonVO::Wrapper FindController::execQueryContract(const PageQuery::Wrapper& query)
{
	auto vo = StringJsonVO::createShared();
	vo	->success("contract get success");
	return vo; 
}

StringJsonVO::Wrapper FindController::execQueryPerson(const PageQuery_person::Wrapper& query)
{
	auto vo = StringJsonVO::createShared();
	vo->success("person information get success");
	return vo;
}

//Uint64JsonVO::Wrapper FindController::execAddSample(const SampleDTO::Wrapper& dto)
//{
//	// ���巵�����ݶ���
//	auto jvo = Uint64JsonVO::createShared();
//	// ����У��
//	// �ǿ�У��
//	if (!dto->age || !dto->name || !dto->sex)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// ��ЧֵУ��
//	if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//
//	// ����һ��Service
//	SampleService service;
//	// ִ����������
//	uint64_t id = service.saveData(dto);
//	if (id > 0) {
//		jvo->success(UInt64(id));
//	}
//	else
//	{
//		jvo->fail(UInt64(id));
//	}
//	//��Ӧ���
//	return jvo;
//}

Uint64JsonVO::Wrapper FindController::execAddContract(const ContractDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	//if (!dto->age || !dto->name || !dto->sex)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	//// ��ЧֵУ��
	//if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	return jvo;

	//// ����һ��Service
	//SampleService service;
	//// ִ����������
	//uint64_t id = service.saveData(dto);
	//if (id > 0) {
	//	jvo->success(UInt64(id));
	//}
	//else
	//{
	//	jvo->fail(UInt64(id));
	//}
	////��Ӧ���
	//return jvo;
}

Uint64JsonVO::Wrapper FindController::execRemoveContract(const ContractDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	//// ����У��
	//if (!dto->id || dto->id <= 0)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	//// ����һ��Service
	//SampleService service;
	//// ִ������ɾ��
	//if (service.removeData(dto->id.getValue(0))) {
	//	jvo->success(dto->id);
	//}
	//else
	//{
	//	jvo->fail(dto->id);
	//}
	//// ��Ӧ���
	return jvo;
}

//StringJsonVO::Wrapper Person_FindController::execQueryPerson(const PageQuery::Wrapper& query)
//{
//	auto vo = StringJsonVO::createShared();
//	vo->success("person information get success");
//	return vo;
//}
