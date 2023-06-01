#pragma once
#ifndef _PAPERINFO_DAO_
#define _PAPERINFO_DAO_
#include "BaseDAO.h"
#include "../../domain/query//paperinfo/PaperQuery.h"
#include "../../domain/do/paperinfo/paperinfo.h"

/**
 * ���ı����ݿ����ʵ��
 */
class PaperinfoDAO : public BaseDAO
{
public:

	// ͨ��������Ϣ�����ѯ����
	list<PaperinfoDO> selectBypimpaperid(const string& st);
	// �޸�����
	int update(const PaperinfoDO& uObj);

};
#endif // !_PAPERINFO_DAO_