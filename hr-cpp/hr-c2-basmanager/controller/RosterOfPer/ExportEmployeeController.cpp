#include "stdafx.h"
#include "ExportEmployeeController.h"
//#include "../../service/ExportEmployee/ExportEmployeeService.h"

//ExportEmployeePageJsonVO::Wrapper ExportEmployeeController::execQueryExportEmployee(const ExportEmployeeQuery::Wrapper& query, const PayloadDTO& payload)
//{
//	// ����һ��Service
//	ExportEmployeeService service;
//	// ��ѯ����
//	auto result = service.listAll(query);
//	// ��Ӧ���
//	auto jvo = ExportEmployeePageJsonVO::createShared();
//	jvo->success(result);
//	return jvo;
//}

Uint64JsonVO::Wrapper ExportEmployeeController::execAddExportEmployee(const ExportEmployeeDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	return jvo;
}

Uint64JsonVO::Wrapper ExportEmployeeController::execModifyExportEmployee(const ExportEmployeeDTO::Wrapper& dto)
{
	//// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	return jvo;
}

Uint64JsonVO::Wrapper ExportEmployeeController::execRemoveExportEmployee(const ExportEmployeeDTO::Wrapper& dto)
{
	//// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	return jvo;
}

//BooleanJsonVO::Wrapper ExportEmployeeController::execImportLEM(const ExportEmployeeDTO::Wrapper& dto)
//{
//	return BooleanJsonVO::createShared();
//}

//BooleanJsonVO::Wrapper ExportEmployeeController::execExportLEM(const ExportEmployeeQuery::Wrapper& legalEntityMaiQuery)
//{
//	return BooleanJsonVO::createShared();
//}
