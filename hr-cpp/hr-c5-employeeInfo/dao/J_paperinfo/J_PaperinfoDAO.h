#pragma once
#ifndef _J_PAPERINFO_DAO_
#define _J_PAPERINFO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/J_paperinfo/J_paperinfoDO.h"

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