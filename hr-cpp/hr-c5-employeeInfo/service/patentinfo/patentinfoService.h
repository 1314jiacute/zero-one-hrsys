#pragma once

#ifndef _PAPERINFO_SERVICE_
#define _PAPERINFO_SERVICE_
#include <list>
#include "domain/vo/patentinfo/PatentinfoVO.h"
#include "domain/query/patentinfo/PatentinfoQuery.h"
#include "domain/dto/patentinfo/PatentinfoDTO.h"

/**
 * ������Ϣ����ʵ��
 */
class PaperinfoService
{
public:
	// ��ҳ��ѯ��������
	PatentinfoPageDTO::Wrapper listAll(const PatentinfoQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const PatentinfoDTO::Wrapper& dto);
	
	// ͨ��IDɾ������
	bool removeData(string id);
	// ��ѯ����ID
	uint64_t selectPaperID(const PatentinfoDTO::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_

