#include "stdafx.h"
#include "ArchivesController.h"

ArchivesJsonVO::Wrapper ArchivesController::execQuerySpecifiedArchivesInfo(const ArchivesQuery::Wrapper& dto, const PayloadDTO& payload)
{
	// Service
	// ��Ӧ���
	auto jvo = ArchivesJsonVO::createShared();
	return jvo;
}

Uint64JsonVO::Wrapper ArchivesController::execAddArchivesInfo(const ArchivesDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// ��ЧֵУ��
	if (dto->archivesNo->empty() || dto->managementUnits->empty() || dto->YGBH->empty() || 
		dto->DABGD->empty() || dto->archivesCenterName->empty() || dto->YGBH->empty()   || 
		dto->PimPersonName->empty() || dto->ygzt->empty() || dto->ORMORGName->empty()   || dto->DAZT->empty() )
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// Service
	return jvo;
}

Uint64JsonVO::Wrapper ArchivesController::execRemoveArchivesInfo(const ArchivesDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->archivesNo)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// Service
	return jvo;
}

ArchivesPageJsonVO::Wrapper ArchivesController::execQueryArchivesinfo(const ArchivesQuery::Wrapper& query)
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