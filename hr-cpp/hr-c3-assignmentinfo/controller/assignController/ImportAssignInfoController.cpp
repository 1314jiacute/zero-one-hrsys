#include "stdafx.h"
#include "ImportAssignInfoController.h"
ImportAssignInfoJsonVO::Wrapper ImportAssignInfoController::execImportAssignInfo(const ImportAssignInfoDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = ImportAssignInfoJsonVO::createShared();
	return jvo;
}