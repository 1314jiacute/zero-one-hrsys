
#include "stdafx.h"
#include "LeaveReasonController.h"
#include "service/leaveReason/LeaveReasonService.h"
PullListVO::Wrapper LeaveReasonController::execQueryLeaveReason()
{
	// ���巵�����ݶ���
	auto jvo = PullListVO::createShared();

	// ����һ��Service
	LeaveReasonService service;

	// ִ�в�ѯ
	auto result = service.listAll();

	// �����ɹ���Ϣ
	jvo->success(result);
	return jvo;
}
