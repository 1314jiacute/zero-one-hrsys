#pragma once
#ifndef _JOBLEVELTYPELISTDAO_H_
#define _JOBLEVELTYPELISTDAO_H_

#include "BaseDAO.h"
#include "domain/do/jobLevelTypeList/JobLevelTypeDO.h"

class JobLevelTypeListDAO : public BaseDAO
{
public:
	// ��ѯ����
	list<JobLevelTypeDO> listAll();
};

#endif // !_JOBLEVELTYPELISTDAO_H_