#pragma once
#ifndef _AUDITSTATUSDAO_H_
#define _AUDITSTATUSDAO_H_

#include "BaseDAO.h"
#include "domain/do/auditStatus/AuditStatusDO.h"

class AuditStatusDAO : public BaseDAO
{
private:
	// ���״̬��Ӧ��ϣ��
	unordered_map<string, string> auditStatus = {
		{"10", u8"�����"},
		{"20", u8"�����"},
		{"30", u8"���ͨ��"},
		{"40", u8"���δͨ��"}
	};
public:
	// ��ѯ����
	list<AuditStatusDO> listAll();
	// ���������б�
	unordered_map<string, string> getMapList();
};

#endif // !_AUDITSTATUSDAO_H_