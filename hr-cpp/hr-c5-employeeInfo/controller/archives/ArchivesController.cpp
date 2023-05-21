#include "stdafx.h"
#include "ArchivesController.h"

ArchivesPageJsonVO::Wrapper ArchivesController::execQueryArchivesinfo(const PageQuery::Wrapper& query)
{
	// ������Ӧ����
	auto vo = ArchivesPageJsonVO::createShared();
	// ������ҳ����
	auto pdto = ArchivesPageDTO::createShared();
	pdto->addData(ArchivesDTO::createShared());
	pdto->addData(ArchivesDTO::createShared());
	// ��Ӧ���
	vo->success(pdto);
	return vo;
}