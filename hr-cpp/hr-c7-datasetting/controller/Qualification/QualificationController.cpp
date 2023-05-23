#include "stdafx.h"
#include "QualificationController.h"

// ��ҳ��ѯ����
QualificationPageJsonVO::Wrapper QualificationController::execQueryQualification(const QualificationQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ������Ӧ����
	auto vo = QualificationPageJsonVO::createShared();
	// ������ҳ����
	auto pdto = QualificationPageDTO::createShared();
	// ��Ӧ���
	vo->success(pdto);
	return vo;
}

// ��������
Uint64JsonVO::Wrapper QualificationController::execAddQualification(const QualificationDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();

	// ��Ӧ���
	jvo->success(1);
	return jvo;
}

// �޸�����
Uint64JsonVO::Wrapper QualificationController::execModifyQualification(const QualificationDTO::Wrapper& dto)
{
	// ������Ӧ����
	auto vo = Uint64JsonVO::createShared();


	// ��Ӧ���
	vo->success(1);
	return vo;
}

// ɾ������
Uint64JsonVO::Wrapper QualificationController::execRemoveQualification(const QualificationDTO::Wrapper& dto)
{
	// ������Ӧ����
	auto vo = Uint64JsonVO::createShared();

	// ��Ӧ���
	vo->success(1);
	return vo;
}