#include "stdafx.h"
#include "pimpaperController.h"

PimpaperPageJsonVO::Wrapper PimpaperController::execQueryPimpaper(const PimpaperQuery::Wrapper& query)
{
	// ������Ӧ����
	auto vo = PimpaperPageJsonVO::createShared();
	// ������ҳ����
	auto pdto = PimpaperPageDTO::createShared();
	pdto->addData(PimpaperDTO::createShared(1, "page1"));
	pdto->addData(PimpaperDTO::createShared(2, "page2"));
	// ��Ӧ���
	vo->success(pdto);
	return vo;
}

Uint64JsonVO::Wrapper PimpaperController::execAddPimpaper(const PimpaperDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->ygbh || !dto->pimpersonname)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->ygbh < 0 || dto->pimpersonname->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper PimpaperController::execRemovePimpaper(const PimpaperDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->ygbh || dto->ygbh <= 0 || !dto->pimpersonname || dto->pimpersonname->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��Ӧ���
	return jvo;
}
