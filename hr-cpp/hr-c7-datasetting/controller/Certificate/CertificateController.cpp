#include "stdafx.h"
#include "CertificateController.h"

CertificatePageJsonVO::Wrapper CertificateController::execQueryCertificate(const CertificateQuery::Wrapper& query)
{
	auto vo = CertificatePageJsonVO::createShared();
	// ������ҳ����
	auto pdto = CertificatePageDTO::createShared();
	pdto->addData(CertificateDTO::createShared("1", "zs"));
	pdto->addData(CertificateDTO::createShared("2", "ls"));
	// ��Ӧ���
	vo->success(pdto);
	return vo;
}

Uint64JsonVO::Wrapper CertificateController::execAddCertificate(const CertificateDTO::Wrapper& dto)
{
	// ������Ӧ����
	auto vo = Uint64JsonVO::createShared();
	// ��Ӧ���
	vo->success(2);
	return vo;
}
Uint64JsonVO::Wrapper CertificateController::execDelCertificate(const CertificateDTO::Wrapper& dto)
{
	auto vo = Uint64JsonVO::createShared();
	// ��Ӧ���
	vo->success(2);
	return vo;
}
Uint64JsonVO::Wrapper CertificateController::execModifyCertificate(const CertificateDTO::Wrapper& dto)
{
	auto vo = Uint64JsonVO::createShared();
	// ��Ӧ���
	vo->success(2);
	return vo;
}
