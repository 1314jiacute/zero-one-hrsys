#pragma once
#ifndef _ARCHIVES_DO_
#define _ARCHIVES_DO_
#include "../DoInclude.h"

/**
* ������Ϣʵ����
*/
class ArchivesDO
{
	// �������
	CC_SYNTHESIZE(string, archivesNo, ArchivesNo);
	// ����λ
	CC_SYNTHESIZE(string, managementUnits, ManagementUnits);
	// �������ܵ�
	CC_SYNTHESIZE(string, DABGD);
	// ������
	CC_SYNTHESIZE(string, archivesCenterName, ArchivesCenterName);
	// Ա�����
	CC_SYNTHESIZE(string, YGBH);
	// Ա������
	CC_SYNTHESIZE(string, pimPersonName, PimPersonName);
	// Ա��״̬
	CC_SYNTHESIZE(string, ygzt);
	// ������λ
	CC_SYNTHESIZE(string, ORMORGName);
	// ����״̬
	CC_SYNTHESIZE(string, DAZT);
public:
	ArchivesDO() {
		archivesNo = "";
		managementUnits = "";
		DABGD = "";
		archivesCenterName = "";
		YGBH = "";
		pimPersonName = "";
		ygzt = "";
		ORMORGName = "";
		DAZT = "";
	}
};
#endif // !_ARCHIVES_DO_
