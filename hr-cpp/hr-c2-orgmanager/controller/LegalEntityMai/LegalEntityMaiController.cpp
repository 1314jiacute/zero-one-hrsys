#include "stdafx.h"
#include "LegalEntityMaiController.h"
#include "service/LegalEntityMai/LegalEntityMaiService.h"


//LegalEntityMaiPageJsonVO::Wrapper LegalEntityMaiController::execQueryLEM(const LegalEntityMaiQuery::Wrapper& query)
//{
//	// ����һ��Service
//	LegalEntityMaiService service;
//	// ��ѯ����
//	auto result = service.listAll(query);
//	// ��Ӧ���
//	auto jvo = LegalEntityMaiPageJsonVO::createShared();
//	jvo->success(result);
//	return jvo;
//}

//Uint64JsonVO::Wrapper LegalEntityMaiController::execUpdateLEM(const LegalEntityMaiDTO::Wrapper& dto)
//{
//	// ���巵�����ݶ���
//	auto jvo = Uint64JsonVO::createShared();
//	// ����У��
//	if (dto->ORMSIGNORGID == "") {
//
//	}
//
//}

Uint64JsonVO::Wrapper LegalEntityMaiController::execAddLEM(const LegalEntityMaiDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper LegalEntityMaiController::execRemoveLEM(const LegalEntityMaiDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ��Ӧ���
	return jvo;
}

BooleanJsonVO::Wrapper LegalEntityMaiController::execImportLEM(const LegalEntityMaiDTO::Wrapper& dto)
{
	return BooleanJsonVO::createShared();
}

BooleanJsonVO::Wrapper LegalEntityMaiController::execExportLEM(const LegalEntityMaiQuery::Wrapper& query)
{
	return BooleanJsonVO::createShared();
}

