
#include "stdafx.h"
#include "DismissReasonController.h"

PullListVO::Wrapper DismissReasonController::execQueryDismissReason()
{
	// ���巵�����ݶ���
	auto jvo = PullListVO::createShared();

	// ����һ��Service
	DismissReasonService service;

	// ִ�в�ѯ
	auto result = service.listAll();

	// �����ɹ���Ϣ
	jvo->success(result);
	return jvo;
}
