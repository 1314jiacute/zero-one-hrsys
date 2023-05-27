#pragma once
#ifndef _PAPERINFO_DAO_
#define _PAPERINFO_DAO_
#include "BaseDAO.h"
#include "../../domain/do//paperinfo/t_pimpaperDO.h"
#include "../../domain/query//paperinfo/PaperQuery.h"

/**
 * ���ı����ݿ����ʵ��
 */
class PaperinfoDAO : public BaseDAO
{
public:

	// ͨ��������Ϣ�����ѯ����
	list<t_pimpaperDO> selectBypimpaperid(const PaperQuery::Wrapper& query);

	// �޸�����
	int update(const t_pimpaperDO& uObj);

};
#endif // !_SAMPLE_DAO_