#include "stdafx.h"
#include "PatentinfoController.h"
#include "service/patentinfo/patentinfoService.h"

PatentinfoJsonVO::Wrapper PatentinfoController::execQueryPatentinfo(const PatentinfoQuery::Wrapper& query)
{
	// ������Ӧ����
	auto vo = PatentinfoJsonVO::createShared();
	// ������ҳ����
	//auto pdto = PatentinfoPageDTO::createShared();
	//pdto->addData(PatentinfoDTO::createShared(/*oatpp::data::mapping::type::DTO::String(1), "ר��1����"*/));
	//pdto->addData(PatentinfoDTO::createShared(/*oatpp::data::mapping::type::DTO::String(2), "ר��2����"*/));
	//pdto->addData(PatentDTO::createShared(1, "zs"));
	//pdto->addData(PatentDTO::createShared(2, "ls"));
	// ��Ӧ���
	vo->success({});
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


Uint64JsonVO::Wrapper PatentinfoController::execModifyPatentinfo(const PatentinfoDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	return jvo;
}


Uint64JsonVO::Wrapper PatentinfoController::execAddPatent(const AddPatentDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->zlh || !dto->pimpatentname || !dto->zlhqsj || !dto->zlpzgb)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

}

//����idɾ��ר����Ϣ
Uint64JsonVO::Wrapper PatentinfoController::execRemovePatent(const List<String>& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	int length = dto->size();
	if (length <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	for (auto it = dto->begin(); it != dto->end(); ++it)
	{
		if (!(*it))
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
	}
	
	PatentinfoService service;
	if (service.removeData(dto))
	{
		jvo->success(1);
	}
	else
	{
		jvo->fail(1);
	}
	return jvo;

}

