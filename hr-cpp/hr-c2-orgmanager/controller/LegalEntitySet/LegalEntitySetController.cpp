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
	// ����У��
	// �ǿ�У��
	//if (!dto->ormsignorgid || !dto->ormsignorgname || !dto->contractsignorgname) {
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	//// ��ЧֵУ��
	//if (!dto->ormsignorgid || !dto->ormsignorgname || !dto->contractsignorgname )
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	
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

Uint64JsonVO::Wrapper LegalEntitySetController::execModifyLegalEntitySet(const LegalEntitySetDTO::Wrapper& dto) {
	//// ���巵�����ݶ���
	//auto jvo = Uint64JsonVO::createShared();
	//// ����У��
	//if (!dto->id )
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	//// ����һ��Service
	//LegalEntitySetService service;
	//// ִ�������޸�
	//if (service.updateData(dto)) {
	//	jvo->success(dto->id);
	//}
	//else
	//{
	//	jvo->fail(dto->id);
	//}
	//// ��Ӧ���
	//return jvo;
	return Uint64JsonVO::createShared();
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
