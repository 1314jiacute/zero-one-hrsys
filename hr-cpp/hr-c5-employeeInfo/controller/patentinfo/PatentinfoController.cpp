#include "stdafx.h"
#include "PatentinfoController.h"
#include "../../service/patentinfo/PatentService.h"

PatentinfoJsonVO::Wrapper PatentinfoController::execQueryPatentinfo(const String& str)
{
	// ����һ��Service
	PatentService service;
	// ��ѯ����
	auto result = service.listAll(str);
	//������Ӧ����
	auto vo = PatentinfoJsonVO::createShared();
	vo->success(result);
	return vo;
}

PatentinfoPageJsonVO::Wrapper PatentinfoController::execQueryPagePatent(const PatentinfoQuery::Wrapper& query)
{
	// ������Ӧ����
	auto vo = PatentinfoPageJsonVO::createShared();
	// ������ҳ����
	auto pdto = PatentinfoPageDTO::createShared();
	pdto->addData(PatentinfoDTO::createShared("1", "page1"));
	pdto->addData(PatentinfoDTO::createShared("2", "page2"));
	// ��Ӧ���
	vo->success(pdto);
	return vo;
}


Uint64JsonVO::Wrapper PatentinfoController::execModifyPatentinfo(const ModifyPatentinfoDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->pimpatentid)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	PatentService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success({});
	}
	else
	{
		jvo->fail({});
	}
	//jvo->success(dto->pimpatentid);
	return jvo;
}


Uint64JsonVO::Wrapper PatentinfoController::execAddPatent(const PatentinfoDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->pimpersonid)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->pimpersonid->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper PatentinfoController::execRemovePatent(const PatentinfoDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->pimpersonid->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��Ӧ���
	return jvo;
}

