
#include "stdafx.h"
#include "DismissReasonController.h"
#include "service/dismissReason/DismissReasonService.h"

PullListVO::Wrapper DismissReasonController::execQueryDismissReason()
{
	// ���巵�����ݶ���
	auto jvo = PullListVO::createShared();
	DismissReasonService service;
	auto dto = service.listAll();
	// �����ɹ���Ϣ
	jvo->success(dto);
	return jvo;
}
