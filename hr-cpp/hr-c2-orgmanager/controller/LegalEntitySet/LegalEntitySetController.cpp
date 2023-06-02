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
Uint64JsonVO::Wrapper LegalEntitySetController::execAddLegalEntitySet(const List<LegalEntitySetDTO::Wrapper> & dto, const PayloadDTO& payload) {
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	int length = dto->size();

	// ��Ӧ���
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

//LegalEntitySetQueryPageJsonVO::Wrapper LegalEntitySetController::execQueryLES(const LegalEntitySetQuery::Wrapper& query)
//{
//	// ����һ��Service
//	LegalEntitySetService service;
//	// ��ѯ����
//	auto result = service.listAll(query);
//	// ��Ӧ���
//	auto jvo = LegalEntitySetQueryPageJsonVO::createShared();
//	jvo->success(result);
//	return jvo;
//}
