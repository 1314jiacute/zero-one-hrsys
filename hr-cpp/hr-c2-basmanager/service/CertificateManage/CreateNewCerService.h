#pragma once
/*
֤�����-�½�֤��--pine
*/
#ifndef _CREATE_NEW_CER_SERVICE_
#define _CREATE_NEW_CER_SERVICE_
#include <list>
#include "domain/query/CertificateManage/CreateNewCerQuery.h"
#include "domain/dto/CertificateManage/CreateNewCerDTO.h"
#include "domain/vo/CertificateManage/CreateNewCerVO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class CreateNewCerService
{
public:
	// ��������
	uint64_t saveData(const CreateNewCerDTO::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_

