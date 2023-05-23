#include "stdafx.h"
#include "ContractController.h"
//#include"../../service/contract/ContractService.h"

ContractTypePageJsonVO::Wrapper ContractController::execQueryContractType(const ContractTypeQuery::Wrapper& query)
{
	//// ����һ��Service
	//ContractService service;
	//// ��ѯ����
	//auto result = service.listAll(query);
	// ��Ӧ���
	// ������Ӧ����
	auto jvo = ContractTypePageJsonVO::createShared();
	// ������ҳ����
	auto pdto = ContractTypePageDTO::createShared();
	pdto->addData(ContractTypeDTO::createShared("1", "zs"));
	pdto->addData(ContractTypeDTO::createShared("2", "ls"));
	//jvo->success(result);
	jvo->success(pdto);
	return jvo;
}

Uint64JsonVO::Wrapper ContractController::execAddContractType(const ContractTypeDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��&�ǿ�У�� ���ж�ֵ(|| !dto->department || !dto->stat)

	//if (!dto->id || !dto->name || !dto->contractId || !dto->contract_type) {
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	//// ��ЧֵУ��
	//if (stoi(dto->id) < 0 || dto->name->empty() || dto->contractId->empty() || dto->contract_type->empty()) {
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}

	//// ����һ��Service
	//ContractService service;
	//// ��������
	//uint64_t id = service.saveData(dto);
	//if (id > 0) {
	//	jvo->success(UInt64(id));
	//}
	//else
	//{
	//	jvo->fail(UInt64(id));
	//}
	//��Ӧ���
	jvo->success(1);
	return jvo;
}

Uint64JsonVO::Wrapper ContractController::execModifyContractType(const ContractTypeDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��

	/*if (!dto->id || stoi(dto->id) <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}*/

	//// ����һ��Service
	//ContractService service;
	//// ִ�������޸�
	//if (service.updateData(dto)) {
	//	jvo->success(dto->id);
	//}
	//else
	//{
	//	jvo->fail(dto->id);
	//}
	// ��Ӧ���
	jvo->success(1);
	return jvo;
}

Uint64JsonVO::Wrapper ContractController::execRemoveContractType(const ContractTypeDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��

	/*if (!dto->id || stoi(dto->id) <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}*/

	//// ����һ��Service
	//ContractService service;
	//// ִ������ɾ��
	//if (service.removeData(stoull(dto->id))) {
	//	jvo->success(dto->id);
	//}
	//else
	//{
	//	jvo->fail(dto->id);
	//}
	//// ��Ӧ���
	jvo->success(1);
	return jvo;
}
