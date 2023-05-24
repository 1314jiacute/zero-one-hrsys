#include "stdafx.h"
#include "PaperinfoController.h"

PaperPageJsonVO::Wrapper PaperinfoController::execQueryPaperinfo(const PageQuery::Wrapper& query)
{
	// ������Ӧ����
	auto vo = PaperPageJsonVO::createShared();
	// ������ҳ����
	auto pdto = PaperPageDTO::createShared();
	pdto->addData(PaperDTO::createShared());
	pdto->addData(PaperDTO::createShared());
	// ��Ӧ���
	vo->success(pdto);
	return vo;
}

Uint64JsonVO::Wrapper PaperinfoController::execModifyPaperinfo(const PaperDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	return jvo;
}
