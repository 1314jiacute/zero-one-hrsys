#include "stdafx.h"
#include "LanguageCompetenceController.h"
#include "../../service/Language/LanguageService.h"

/**
 * ʵ������������ɾ���ģ��
 * �����ˣ���
 */
LanguagePageJsonVO::Wrapper LanguageCompetenceController::execQueryLanguage(const LanguagePageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	LanguageService service;
	//��ѯ����
	auto result = service.listAll(query);
	//��Ӧ���
	auto jvo = LanguagePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//auto jvo = StringJsonVO::createShared();
	//jvo->success("query language competence success");
	//return jvo;
}

LanguageJsonVO::Wrapper LanguageCompetenceController::execQueryOneLanguage(const LanguageQuery::Wrapper& query, const PayloadDTO& payload)
{
	//����һ��Service
	LanguageService service;
	//��ѯ����
	auto result = service.queryOneData(query);
	//��Ӧ���
	auto jvo = LanguageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	/*auto jvo = StringJsonVO::createShared();
	jvo->success("query language competence success");
	return jvo;*/
}

Uint64JsonVO::Wrapper LanguageCompetenceController::execAddLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//����һ���������ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->personID || !dto->languageType || !dto->languageLevel) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//��ЧֵУ��
	if (dto->languageType->empty() || dto->languageLevel->empty()) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	LanguageService service;
	// ִ����������
	uint64_t count = service.saveData(dto);
	if (count > 0) {
		jvo->success(UInt64(count));
	}
	else
	{
		jvo->fail(UInt64(count));
	}
	//��Ӧ���
	return jvo;
}
//StringJsonVO::Wrapper LanguageCompetenceController::execAddLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload) 
//{
//	auto jvo = StringJsonVO::createShared();
//	jvo->success("add language competence success");
//	return jvo;
//
//}

BooleanJsonVO::Wrapper LanguageCompetenceController::execDeleteLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//����һ�����ض���
	auto jvo = BooleanJsonVO::createShared();
	// ����У��
	if (!dto->personID)
	{
		jvo->init(false, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	LanguageService service;
	// ִ������ɾ��
	if (service.removeData(dto->personID.getValue(0),dto->languageType.getValue(0))) {
		jvo->success(true);
	}
	else
	{
		jvo->fail(false);
	}
	// ��Ӧ���
	return jvo;
}
//StringJsonVO::Wrapper LanguageCompetenceController::execDeleteLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
//{
//	auto jvo = StringJsonVO::createShared();
//	jvo->success("remove language competence success");
//	return jvo;
//}

BooleanJsonVO::Wrapper LanguageCompetenceController::execUpdateLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//����һ�����ض���
	auto jvo = BooleanJsonVO::createShared();
	//����У��
	if (!dto->personID) {
		jvo->init(false, RS_PARAMS_INVALID);
		return jvo;
	}
	//����һ��Service
	LanguageService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(true);
	}
	else
	{
		jvo->fail(false);
	}
	// ��Ӧ���
	return jvo;
}
//StringJsonVO::Wrapper LanguageCompetenceController::execUpdateLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
//{
//	auto jvo = StringJsonVO::createShared();
//	jvo->success("update language competence success");
//	return jvo;
//}