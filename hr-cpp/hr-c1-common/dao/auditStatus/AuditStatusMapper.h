#pragma once
#ifndef _AUDITSTATUSMAPPER_H_
#define _AUDITSTATUSMAPPER_H_

#include "Mapper.h"
#include "domain/do/auditStatus/AuditStatusDO.h"

/**
 * ���״̬�����б����ݿ��ֶ�ƥ��ӳ��
 * �����ˣ����֮��
 */
class AuditStatusMapper : public Mapper<AuditStatusDO>
{
public:
	AuditStatusDO mapper(ResultSet* result) const override
	{
		AuditStatusDO data;
		data.setAuditStatus(result->getString(1));
		return data;
	}
};

#endif // !_AUDITSTATUSMAPPER_H_