#include "stdafx.h"
#include "LegalEntitySetController.h"

#include "service/LegalEntitySet/LegalEntitySetService.h"
/*
��֯���� ������������ ���� ������������  -- cpt

�����������������б� `LegalEntitySetPullDownList`

����ָ������������Ϣ  `UpdateLegalerSettingMessage`

������������ `LegalEntitySet`

�����������ã�֧������������** `LegalEntitySet`
*/ 
Uint64JsonVO::Wrapper LegalEntitySetController::execAddLegalEntitySet(const LegalEntitySetDTO::Wrapper& dto) {
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����һ��Service
	LegalEntitySetService service;
	// ִ����������
	uint64_t id = service.insertData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else {
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}

LegalEntitySetPageJsonVO::Wrapper LegalEntitySetController::execExportLegalEntitySet(const LegalEntitySetQuery::Wrapper& query, const PayloadDTO& payload) {
	return LegalEntitySetPageJsonVO::Wrapper();
}


// �����������������б��ѯ
LegalEntitySetPullDownJsonVO::Wrapper LegalEntitySetController::execLegalEntitySetPullDownList() {
	auto vo = LegalEntitySetPullDownJsonVO::createShared();
	LegalEntitySetService service;
	auto dto = service.legalEntityPulldownList();
	vo->success(dto);
	return vo;
}

StringJsonVO::Wrapper LegalEntitySetController::execModifyLegalEntitySet(const LegalEntitySetDTO::Wrapper& dto) {
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->ormsignorgid || dto->ormsignorgid == "") {
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	LegalEntitySetService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->ormsignorgid);
	}
	else {
		jvo->fail(dto->ormsignorgid);
	}
	// ��Ӧ���
	return jvo;
}

/*---------------------------------- �����������ÿ���������ʵ��--����֯����-��������-�����������ã�--TripleGold -------------------------------*/

LegalEntitySetPageJsonVO::Wrapper LegalEntitySetController::execQueryLES(const LegalEntitySetQuery::Wrapper& query)
{
	// ����һ��Service
	LegalEntitySetService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = LegalEntitySetPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
