#pragma once

#ifndef _PATENTINFO_SERVICE_
#define _PATENTINFO_SERVICE_
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
	PatentinfoDTO::Wrapper listAll(const string& pimpatentid);

	// �޸�����
	bool updateData(const PatentinfoDTO::Wrapper& dto);

};

#endif // !_PATENTINFO_SERVICE_
