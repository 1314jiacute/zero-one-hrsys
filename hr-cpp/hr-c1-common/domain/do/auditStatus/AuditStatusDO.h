#pragma once
#ifndef _AUDITSTATUSDO_H_
#define _AUDITSTATUSDO_H_

#include "../DoInclude.h"

/**
 * ���״̬�����б�DO
 * �����ˣ����֮��
 */
class AuditStatusDO
{
	// ����������
	CC_SYNTHESIZE(string, auditStatus, AuditStatus);
	// ������ֵ
	CC_SYNTHESIZE(string, code, Code);
public:
	AuditStatusDO()
	{
		code = "";
		auditStatus = "";
	}

	AuditStatusDO(string code_, string level_)
	{
		code = code_;
		auditStatus = level_;
	}
};

#endif // !_AUDITSTATUSDO_H_