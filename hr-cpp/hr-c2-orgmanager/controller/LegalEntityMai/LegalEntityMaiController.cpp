#include "stdafx.h"
#include "LegalEntityMaiController.h"


LegalEntityMaiPageJsonVO::Wrapper LegalEntityMaiController::executeQueryById(const LegalEntityMaiQuery::Wrapper& legalEntityMaiQuery)
{
	// ����һ��JsonVO����
	auto vo = LegalEntityMaiPageJsonVO::createShared();
	// ����һ����ҳ����
	auto pageDTO = LegalEntityMaiPageDTO::createShared();
	pageDTO->addData(LegalEntityMaiDTO::createShared("1", "zs"));
	pageDTO->addData(LegalEntityMaiDTO::createShared("2", "ls"));
	// ��Ӧ���
	vo->success(pageDTO);
	return vo;
}

