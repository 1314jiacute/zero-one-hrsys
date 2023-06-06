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
	int id = service.saveData(dto);
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
	if (!dto->pimpaperid) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	List<String> ids = dto->pimpaperid;
	String id = "";
	for (auto p = ids->begin(); p != ids->end(); p++) {
		id = *p;
		if (id->empty()) {
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
	}

	// ����һ��Service
	PaperinfoService service;
	int cnt = 0;
	// ִ������ɾ��
	for (auto p = ids->begin(); p != ids->end(); p++) {
		id = *p;
		if (service.removeData(id)) {
			cnt++;
		}
	}

	// ��Ӧ���
	if (cnt > 0) {
		jvo->success(UInt64(cnt));
	}
	else
	{
		jvo->fail(UInt64(cnt));
	}
	return jvo;
}