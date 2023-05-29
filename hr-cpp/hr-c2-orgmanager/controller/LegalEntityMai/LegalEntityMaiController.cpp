#include "stdafx.h"
#include "LegalEntityMaiController.h"
#include "service/LegalEntityMai/LegalEntityMaiService.h"

/* ��������ά������������ʵ��--����֯����-��������-��������ά����--TripleGold */

LegalEntityMaiPageJsonVO::Wrapper LegalEntityMaiController::execQueryLEM(const LegalEntityMaiQuery::Wrapper& query)
{
	// ����һ��Service
	LegalEntityMaiService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = LegalEntityMaiPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper LegalEntityMaiController::execUpdateLEM(const LegalEntityMaiDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->ORMSIGNORGID || dto->ORMSIGNORGID == "") {
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	LegalEntityMaiService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->ORMSIGNORGID);
	}
	else {
		jvo->fail(dto->ORMSIGNORGID);
	}
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper LegalEntityMaiController::execAddLEM(const LegalEntityMaiDTO::Wrapper& dto)
{
	/*oatpp::List<Uint64JsonVO::Wrapper> jvoList;
	int size = dtoList->size();
	for (auto it = dtoList->begin(); it != dtoList->end(); it++) {*/
		// ���巵�����ݶ���
		auto jvo = Uint64JsonVO::createShared();
		/*auto dto = *it;*/
		/* ����У�� */
		// �ǿռ���
		if (!dto->ORMSIGNORGNAME || !dto->ORGCODE) {
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
		// ��Чֵ����
		if (dto->ORMSIGNORGNAME->empty() || dto->ORGCODE->empty()) {
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}

		// ����һ��Service
		LegalEntityMaiService service;
		// ִ����������
		uint64_t id = service.saveData(dto);
		if (id > 0) {
			jvo->success(UInt64(id));
		}
		else {
			jvo->fail(UInt64(id));
		}
		//jvoList.push_back(jvo);
	//}
	// ��Ӧ���
		return jvo;
}

StringJsonVO::Wrapper LegalEntityMaiController::execRemoveLEM(const LegalEntityMaiDTO::Wrapper& dto)
{
	/*std::list<StringJsonVO::Wrapper> jvoList;
	for (auto dto : dtoList) {*/
		// ���巵�����ݶ���
		auto jvo = StringJsonVO::createShared();
		// ����У��
		if (!dto->ORMSIGNORGID || dto->ORMSIGNORGID == "") {
			jvo->init(String(-1), RS_PARAMS_INVALID);
			return jvo;
		}
		// ����һ��Service
		LegalEntityMaiService service;
		// ִ������ɾ��
		if (service.removeData(dto->ORMSIGNORGID.getValue(""))) {
			jvo->success(dto->ORMSIGNORGID);
		}
		else {
			jvo->fail(dto->ORMSIGNORGID);
		}
	//}
	// ��Ӧ���
	return jvo;
}

StringJsonVO::Wrapper LegalEntityMaiController::execImportLEM(const LegalEntityMaiDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ��Ӧ���
	return jvo;
}

StringJsonVO::Wrapper LegalEntityMaiController::execExportLEM(const LegalEntityMaiQuery::Wrapper& query)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����һ��Service
	LegalEntityMaiService service;
	// ִ���ļ�����
	std::string fileName = service.exportFile(query);
	if (fileName.empty()) {
		jvo->fail("fail to export");
	}
	else {
		jvo->success(fileName);
	}
	// ��Ӧ���
	return jvo;
}

