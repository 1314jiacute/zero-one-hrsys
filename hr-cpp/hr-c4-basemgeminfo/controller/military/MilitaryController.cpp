#include "stdafx.h"
#include "MilitaryController.h"
#include "../../service/military/MilitaryService.h"

MilitaryJsonVO::Wrapper MilitaryController::execQueryMilitary(const MilitaryDetailQuery::Wrapper& query) {
	// ����һ��Service
	MilitaryService service;
	// ��ѯ����
	auto result = service.listDetail(query);
	// ��Ӧ���
	auto jvo = MilitaryJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper MilitaryController::execModifyMilitary(const MilitaryDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (dto->PIMARMYCADRESID.getValue("").empty())
	{
		jvo->init(String("PIMARMYCADRESID must be not null"), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	MilitaryService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->PIMARMYCADRESID);
	}
	else
	{
		jvo->fail(dto->PIMARMYCADRESID);
	}
	// ��Ӧ���
	return jvo;
}

StringJsonVO::Wrapper MilitaryController::execDownloadMilitary(const MilitaryDownloadQuery::Wrapper& query)
{
	// ������Ӧ����
	auto vo = StringJsonVO::createShared();
	// ��Ӧ���
	vo->success("Download-Link");
	return vo;
}
