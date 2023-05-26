#pragma once

#ifndef _PAPERINFO_SERVICE_
#define _PAPERINFO_SERVICE_
#include <list>
#include "domain/vo/paperinfo/PaperVO.h"
#include "domain/query/paperinfo/PaperQuery.h"
#include "domain/dto/paperinfo/PaperDTO.h"

/**
 * ������Ϣ����ʵ��
 */
class PaperinfoService
{
public:
	// ��ҳ��ѯ��������
	PaperDTO::Wrapper listAll(const PaperQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const PaperDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const PaperDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_

