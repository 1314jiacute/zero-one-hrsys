#include "stdafx.h"
#include "AddTagController.h"

Uint64JsonVO::Wrapper AddTagController::execAddProjTag(const ProjTagDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();

	// У��dto����
	

	
	// ִ����������
	//uint64_t id = service.saveData(dto);
	// idӦ�����ݿ����ҵ�������ֶ�
	uint64_t id = 1;
	//��Ӧ���
	jvo->success(UInt64(id));
	return jvo;
}
