#include "stdafx.h"
#include "RraineeController.h"

RraineePageJsonVO::Wrapper RraineeController::execRraineeQuery(const RraineeQuery::Wrapper& query, const PayloadDTO& payload){
	return RraineePageJsonVO::Wrapper();
}

RraineePageJsonVO::Wrapper RraineeController::execRraineeExport(const RraineeQuery::Wrapper& query, const PayloadDTO& payload) {
	return RraineePageJsonVO::Wrapper();
}

//Uint64JsonVO::Wrapper Rrainee::execAddRrainee(const RraineeDTO::Wrapper& dto) {
//	// ���巵�����ݶ���
//	auto jvo = Uint64JsonVO::createShared();
//	// ����У��
//	// �ǿ�У��
//	if (!dto->age || !dto->name || !dto->sex)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// ��ЧֵУ��
//	if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//
//	// ����һ��Service
//	RraineeService service;
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
//
//Uint64JsonVO::Wrapper Rrainee::execModifyRrainee(const RraineeDTO::Wrapper& dto) {
//	// ���巵�����ݶ���
//	auto jvo = Uint64JsonVO::createShared();
//	// ����У��
//	if (!dto->id || dto->id <= 0)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// ����һ��Service
//	RraineeService service;
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
//
//Uint64JsonVO::Wrapper Rrainee::execRemoveRrainee(const RraineeDTO::Wrapper& dto) {
//	// ���巵�����ݶ���
//	auto jvo = Uint64JsonVO::createShared();
//	// ����У��
//	if (!dto->id || dto->id <= 0)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// ����һ��Service
//	RraineeService service;
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
//
