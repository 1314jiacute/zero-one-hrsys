#include "stdafx.h"
#include "CertificateInformationController.h"
#include "../../service/certificate-information/CertificateInformationService.h"
CertificateInformationPageJsonVO::Wrapper CertificateInformationController::execQuerySample(constCertificateInformationQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	CertificateInformationService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = CertificateInformationPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}