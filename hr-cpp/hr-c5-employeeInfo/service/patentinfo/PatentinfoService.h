#pragma once

#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "domain/vo/patentinfo/PatentinfoVO.h"
#include "domain/query/patentinfo/PatentinfoQuery.h"
#include "domain/dto/patentinfo/PatentinfoDTO.h"



/**
 * ר������ʵ��
 */
class PatentinfoService
{
public:
	// ��ѯ��������
	PatentinfoDTO::Wrapper listAll(const PatentinfoQuery::Wrapper& query);

	// �޸�����
	//bool updateData(const PatentinfoDTO::Wrapper& dto);

};

#endif // !_SAMPLE_SERVICE_
