//�����Ҳ㼶�����б���ΪMySQLû�ж�Ӧ�ı�����ֱ���ƽ�ȥ��
//���ߣ���Ƥ�����
//2023��5��26��
#include "stdafx.h"
#include "ArchivesLevelsDAO.h"

list<ArchivesLevelDO> ArchivesLevelsDAO::getArchivesLevels() {
	list<ArchivesLevelDO> lists={};
	ArchivesLevelDO a, b ,c;

	a.setArchiveslevel("�ϲ�");
	lists.push_back(a);

	b.setArchiveslevel("�в�");
	lists.push_back(b);

	c.setArchiveslevel("�²�");
	lists.push_back(c);

	return lists;
}

