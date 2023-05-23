
#include "stdafx.h"
#include "CheckCerListController.h"
//#include "../../service/sample/SampleService.h"

CheckCerListPageJsonVO::Wrapper CheckCerListController::execQueryCheckCerList(const PageQuery::Wrapper& query)
{
	//������Ӧ����
	auto vo = CheckCerListPageJsonVO::createShared();
	//������ҳ����
	auto pdto = CheckCerListPageDTO::createShared();
	pdto->addData(CheckCerListDTO::createShared(1, "zs"));
	pdto->addData(CheckCerListDTO::createShared(2, "ls"));
	//��Ӧ���
	vo->success(pdto);
	return vo;
}
