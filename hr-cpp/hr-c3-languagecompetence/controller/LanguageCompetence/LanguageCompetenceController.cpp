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
}

LanguageJsonVO::Wrapper LanguageCompetenceController::execQueryOneLanguage(const LanguageQuery::Wrapper& query, const PayloadDTO& payload)
{
	//����һ��Service
	LanguageService service;
	//��ѯ����
	auto result = service.queryOneDataById(query);
	//��Ӧ���
	auto jvo = LanguageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Int32JsonVO::Wrapper LanguageCompetenceController::execAddLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//����һ���������ݶ���
	auto jvo = Int32JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->personID || !dto->languageType || !dto->languageLevel) {
		jvo->init(Int32(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//��ЧֵУ��
	if (dto->personID->empty() || dto->languageType->empty() || dto->languageLevel->empty()) {
		jvo->init(Int32(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	LanguageService service;
	// ִ����������
	int count = service.saveData(dto);
	if (count > 0) {
		jvo->success(Int32(count));
	}
	else
	{
		jvo->fail(Int32(count));
	}
	//��Ӧ���
	return jvo;
}

BooleanJsonVO::Wrapper LanguageCompetenceController::execDeleteLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//����һ�����ض���
	auto jvo = BooleanJsonVO::createShared();
	// ����У��
	if (!dto->languageAbilityID)
	{
		jvo->init(false, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	LanguageService service;
	// ִ������ɾ��
	if (service.removeData(dto->languageAbilityID.getValue({}))) {
		jvo->success(true);
	}
	else
	{
		jvo->fail(false);
	}
	// ��Ӧ���
	return jvo;
}

BooleanJsonVO::Wrapper LanguageCompetenceController::execUpdateLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//����һ�����ض���
	auto jvo = BooleanJsonVO::createShared();
	//����У��
	if (!dto->languageAbilityID) {
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
