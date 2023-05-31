#pragma once

#ifndef _T_PIMPATENT_SERVICE_
#define _T_PIMPATENT_SERVICE_
#include <list>
#include "domain/vo/patentinfo/PatentinfoVO.h"
#include "domain/query/patentinfo/PatentinfoQuery.h"
#include "domain/dto/patentinfo/PatentinfoDTO.h"
#include "domain/dto/patentinfo/DelPatentDTO.h"

/**
 * ������Ϣ����ʵ��
 */
class patentinfoService
{
public:
	// ��ҳ��ѯ��������
	PatentinfoPageDTO::Wrapper listAll(const PatentinfoQuery::Wrapper& query);


	// ��������
	uint64_t saveData(const PatentinfoDTO::Wrapper& dto);
	
	// ͨ��IDɾ������ ֧������ɾ��
	//bool removeData(string id);
	bool removeData(const DelPatentDTO::Wrapper& dto);


	// ��ѯ����ID
	uint64_t selectPaperID(const PatentinfoDTO::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_

