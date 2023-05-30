/*
֤�����-�½�֤��--pine
*/
#include "stdafx.h"
#include "SnowFlake.h"
#include "CreateNewCerService.h"
#include "../../dao/CertificateManage/CreateNewCerDAO.h"

uint64_t CreateNewCerService::saveData(const CreateNewCerDTO::Wrapper& dto)
{
	// ��װDO����
	CertificateDO data;

	
	data.setYgbh(dto->ygbh.getValue(0));
	data.setPimVocationalName(dto->pimVocationalName.getValue(""));
	//ѩ���㷨����Ψһ��ʶID
	SnowFlake f2(1, 2);
	data.setPimvocationalid(to_string(f2.nextId()));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Ygbh, ygbh, PimVocationalName, pimVocationalName)
	// ִ���������
	CreateNewCerDAO dao;
	return dao.insert(data);
}

