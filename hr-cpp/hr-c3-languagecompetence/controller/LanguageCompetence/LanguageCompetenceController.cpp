#include "stdafx.h"
#include "LanguageCompetenceController.h"
#include "../../service/Language/LanguageService.h"

StringJsonVO::Wrapper LanguageCompetenceController::execQueryLanguage(const LanguagePageQuery::Wrapper& query, const PayloadDTO& payload)
{
	//// ����һ��Service
	//LanguageService service;
	////��ѯ����
	//auto result = service.listAll(query);
	////��Ӧ���
	//auto jvo = StringJsonVO::createShared();
	//jvo->success(result);
	//return jvo;
	auto jvo = StringJsonVO::createShared();
	jvo->success("query language competence success");
	return jvo;
}

StringJsonVO::Wrapper LanguageCompetenceController::execQueryOneLanguage(const LanguageQuery::Wrapper& query, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	jvo->success("query language competence success");
	return jvo;
}

//Uint64JsonVO::Wrapper LanguageCompetenceController::execAddLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
//{
//	//����һ���������ݶ���
//	auto jvo = Uint64JsonVO::createShared();
//	// ����У��
//	// �ǿ�У��
//	if (!dto->id || !dto->languageType || !dto->languageLevel) {
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	//��ЧֵУ��
//	if (dto->id < 1 || dto->languageType->empty() || dto->languageLevel->empty()) {
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// ����һ��Service
//	LanguageService service;
//	// ִ����������
//	uint64_t id = service.saveData(dto);
//	if (id > 0) {
//		jvo->success(UInt64(id));
//	}
//	else
//	{
//		jvo->fail(UInt64(id));
//	}
//	//��Ӧ���
//	return jvo;
//}
StringJsonVO::Wrapper LanguageCompetenceController::execAddLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload) 
{
	auto jvo = StringJsonVO::createShared();
	jvo->success("add language competence success");
	return jvo;

}

//Uint64JsonVO::Wrapper LanguageCompetenceController::execDeleteLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
//{
//	//����һ�����ض���
//	auto jvo = Uint64JsonVO::createShared();
//	// ����У��
//	if (!dto->id || dto->id < 1)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// ����һ��Service
//	LanguageService service;
//	// ִ������ɾ��
//	if (service.removeData(dto->id.getValue(0))) {
//		jvo->success(dto->id);
//	}
//	else
//	{
//		jvo->fail(dto->id);
//	}
//	// ��Ӧ���
//	return jvo;
//}
StringJsonVO::Wrapper LanguageCompetenceController::execDeleteLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	jvo->success("remove language competence success");
	return jvo;
}

//Uint64JsonVO::Wrapper LanguageCompetenceController::execUpdateLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
//{
//	//����һ�����ض���
//	auto jvo = Uint64JsonVO::createShared();
//	//����У��
//	if (!dto->id || dto->id < 1) {
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	//����һ��Service
//	LanguageService service;
//	// ִ�������޸�
//	if (service.updateData(dto)) {
//		jvo->success(dto->id);
//	}
//	else
//	{
//		jvo->fail(dto->id);
//	}
//	// ��Ӧ���
//	return jvo;
//}
StringJsonVO::Wrapper LanguageCompetenceController::execUpdateLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	jvo->success("update language competence success");
	return jvo;
}