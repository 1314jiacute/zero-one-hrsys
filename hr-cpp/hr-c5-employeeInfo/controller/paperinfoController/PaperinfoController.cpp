#include "stdafx.h"
#include "PaperinfoController.h"
#include "../../service/paperinfo/PaperinfoService.h"

PaperPageJsonVO::Wrapper PaperinfoController::execQueryPaperinfo(const PaperQuery::Wrapper& query)
{
	// ����һ��Service
	PaperinfoService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = PaperPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper PaperinfoController::execModifyPaperinfo(const PaperDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	return jvo;
}


Uint64JsonVO::Wrapper PaperinfoController::execAddPaperinfo(const PaperDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->fbsj || !dto->cbs || !dto->kwqs || !dto->fj
		|| !dto->grzlwzzzdpm || !dto->kwmc || !dto->pimpapername)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->fbsj->empty() || dto->cbs->empty() || dto->kwqs <= 0 ||
		dto->fj->empty() || dto->grzlwzzzdpm <= 0 || dto->kwmc->empty() ||
		dto->pimpapername->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	PaperinfoService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;

}

Uint64JsonVO::Wrapper PaperinfoController::execRemovePaperinfo(const PaperDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->fbsj || !dto->cbs || !dto->kwqs || !dto->fj
		|| !dto->grzlwzzzdpm || !dto->kwmc || !dto->pimpapername)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->fbsj->empty() || dto->cbs->empty() || dto->kwqs <= 0 ||
		dto->fj->empty() || dto->grzlwzzzdpm <= 0 || dto->kwmc->empty() ||
		dto->pimpapername->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	PaperinfoService service;
	// ��ȡ����id
	uint64_t id = service.selectPaperID(dto);
	// ִ������ɾ��
	if (service.removeData(id)) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	// ��Ӧ���
	return jvo;
}