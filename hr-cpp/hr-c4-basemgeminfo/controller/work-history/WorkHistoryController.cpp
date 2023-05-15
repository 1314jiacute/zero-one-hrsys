#include "stdafx.h"
#include "WorkHistoryController.h"
#include "../../service/work-history/WorkHistoryService.h"

WorkHistoryVO::Wrapper WorkHistoryController::execQueryWorkHistory(const WorkHistoryQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	WorkHistoryService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = WorkHistoryVO::createShared();
	jvo->success(result);
	return jvo;
}
Uint64JsonVO::Wrapper WorkHistoryController::execModifyWorkHistory(const WorkHistoryDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->rzkssj || !dto->rzjssj|| !dto->ormorgname || !dto->ormdutyname || !dto->ormpostname || !dto->cfplx||!dto->enable)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	SampleService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->rzkssj);
		jvo->success(dto->rzjssj);
		jvo->success(dto->ormorgname);
		jvo->success(dto->ormdutyname);
		jvo->success(dto->ormpostname);
		jvo->success(dto->cfplx);
		jvo->success(dto->enable);
	}
	else
	{
		jvo->fail(dto->rzkssj);
		jvo->fail(dto->rzjssj);
		jvo->fail(dto->ormorgname);
		jvo->fail(dto->ormdutyname);
		jvo->fail(dto->ormpostname);
		jvo->fail(dto->cfplx);
		jvo->fail(dto->enable);
	}
	// ��Ӧ���
	return jvo;
}