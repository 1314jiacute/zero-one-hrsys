#pragma once
#ifndef _JOBLEVELTYPELISTSERVICE_H_
#define _JOBLEVELTYPELISTSERVICE_H_

#include "domain/dto/pullList/PullListDTO.h"

/**
 * ְ�Ƶȼ������б����ʵ��
 * �����ˣ����֮��
 */
class JobLevelTypeListService
{
public:
	// ��ѯְ�Ƶȼ��б�
	PullListDTO::Wrapper listAll();
};

#endif // !_JOBLEVELTYPELISTSERVICE_H_