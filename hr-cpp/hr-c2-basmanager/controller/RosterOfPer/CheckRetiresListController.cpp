
#include "stdafx.h"
#include "CheckRetiresListController.h"
//#include "../../service/sample/SampleService.h"

CheckRetiresListPageJsonVO::Wrapper CheckRetiresListController::execQueryCheckRetiresList(const PageQuery::Wrapper& query)
{
	//������Ӧ����
	auto vo = CheckRetiresListPageJsonVO::createShared();
	//������ҳ����
	auto pdto = CheckRetiresListPageDTO::createShared();
	pdto->addData(CheckRetiresListDTO::createShared(3, "zs"));
	pdto->addData(CheckRetiresListDTO::createShared(4, "ls"));
	//��Ӧ���
	vo->success(pdto);
	return vo;
}
