#include "stdafx.h"
#include "PaperinfoController.h"
#include "../../service/paperinfo/PaperinfoService.h"

StringJsonVO::Wrapper PaperinfoController::execQueryPaperinfo(const PageQuery::Wrapper& query)
{
	// ����һ��Service
	PaperinfoService service;
	// ��ѯ����
	auto result = service.listByPimpersonId(query);
	// ��Ӧ���
	auto jvo = PaperPageJsonVO::createShared();
	jvo->success(result);
	return jvo;

	//auto vo = StringJsonVO::createShared();
	//vo->success("test query success");
	//return vo;
}
