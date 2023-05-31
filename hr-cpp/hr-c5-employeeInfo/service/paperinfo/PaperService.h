#pragma once

#ifndef _PAPER_SERVICE_
#define _PAPER_SERVICE_
#include <list>
#include "domain/vo/paperinfo/PaperVO.h"
#include "domain/query/paperinfo/PaperQuery.h"
#include "domain/dto/paperinfo/PaperDTO.h"

/**
 * ������Ϣ����ʵ��
 */
class PaperService
{
public:
	// ��ѯָ��������Ϣ����
	PaperDTO::Wrapper listAll(const string& st);
	// �޸�����
	bool updateData(const PaperDTO::Wrapper& dto);
};

#endif // !_PAPER_SERVICE_

