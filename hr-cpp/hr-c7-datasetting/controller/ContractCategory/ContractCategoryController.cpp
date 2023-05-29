#include "stdafx.h"
#include "ContractCategoryController.h"

ContractCategoryPageJsonVO::Wrapper ContractCategoryController::execQueryContractCategory(const ContractCategoryQuery::Wrapper& query)
{
	// ��Ӧ���
	// ������Ӧ����
	auto jvo = ContractCategoryPageJsonVO::createShared();
	// ������ҳ����
	auto pdto = ContractCategoryPageDTO::createShared();
	pdto->addData(ContractCategoryDTO::createShared("1", "zs"));
	pdto->addData(ContractCategoryDTO::createShared("2", "ls"));
	jvo->success(pdto);
	return jvo;
}

Uint64JsonVO::Wrapper ContractCategoryController::execAddContractCategory(const ContractCategoryDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();


	//��Ӧ���
	jvo->success(1);
	return jvo;
}

Uint64JsonVO::Wrapper ContractCategoryController::execModifyContractCategory(const ContractCategoryDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();


	// ��Ӧ���
	jvo->success(1);
	return jvo;
}

Uint64JsonVO::Wrapper ContractCategoryController::execRemoveContractCategory(const ContractCategoryDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();


	// ��Ӧ���
	jvo->success(1);
	return jvo;
}
