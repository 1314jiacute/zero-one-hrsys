#pragma once
#ifndef _AUDITSTATUSSERVICE_H_
#define _AUDITSTATUSSERVICE_H_

#include "domain/dto/pullList/PullListDTO.h"

/**
 * ������������б����ʵ��
 * �����ˣ����֮��
 */
class AuditStatusService
{
public:
	// ��ѯ��������б�
	PullListDTO::Wrapper listAll();
};

#endif // !_AUDITSTATUSSERVICE_H_