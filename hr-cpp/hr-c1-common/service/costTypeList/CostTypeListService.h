#pragma once
#ifndef _COSTTYPELISTSERVICE_H_
#define _COSTTYPELISTSERVICE_H_

#include "domain/dto/pullList/PullListDTO.h"

/**
 * ������������б����ʵ��
 * �����ˣ����֮��
 */
class CostTypeListService
{
public:
	// ��ѯ��������б�
	PullListDTO::Wrapper listAll();
};

#endif // !_COSTTYPELISTSERVICE_H_