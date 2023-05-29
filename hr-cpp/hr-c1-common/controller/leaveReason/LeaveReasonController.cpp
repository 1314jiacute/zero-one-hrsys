
#include "stdafx.h"
#include "LeaveReasonController.h"
#include "service/leaveReason/LeaveReasonService.h"


PullListVO::Wrapper LeaveReasonController::execQueryLeaveReason()
{
	// ���巵�����ݶ���
	auto jvo = PullListVO::createShared();
	
	LeaveReasonService service;
	auto dto = service.listAll();

	// �����ɹ���Ϣ
	jvo->success(dto);
	return jvo;
}
