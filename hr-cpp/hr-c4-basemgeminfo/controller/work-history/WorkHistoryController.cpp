#include "stdafx.h"
#include "WorkHistoryController.h"
#include "../../service/work-history/WorkHistoryService.h"

WorkHistoryJsonVO::Wrapper WorkHistoryController::execQueryWorkHistory(const WorkHistoryQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	WorkHistoryService service;
	// ��ѯ����
	auto result = service.listDetail(query);
	// ��Ӧ���
	auto jvo = WorkHistoryJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
StringJsonVO::Wrapper WorkHistoryController::execModifyWorkHistory(const WorkHistoryDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (dto->rzkssj.getValue("").empty())
	{
		jvo->init(String("Rzkssj must be not null"), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	WorkHistoryService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->rzkssj);
		/*jvo->success(dto->rzjssj);
		jvo->success(dto->ormorgname);
		jvo->success(dto->ormdutyname);
		jvo->success(dto->ormpostname);
		jvo->success(dto->cfplx);
		jvo->success(dto->enable);*/
	}
	else
	{
		jvo->fail(dto->rzkssj);
		/*jvo->fail(dto->rzjssj);
		jvo->fail(dto->ormorgname);
		jvo->fail(dto->ormdutyname);
		jvo->fail(dto->ormpostname);
		jvo->fail(dto->cfplx);
		jvo->fail(dto->enable);*/
	}
	// ��Ӧ���
	return jvo;
}