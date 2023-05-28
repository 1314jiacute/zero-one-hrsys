#pragma once
#ifndef _JOBLEVELMAPPER_H_
#define _JOBLEVELMAPPER_H_

#include "Mapper.h"
#include "domain/do/jobLevelTypeList/JobLevelTypeDO.h"

/**
 * ְ�Ƶȼ����������б����ݿ��ֶ�ƥ��ӳ��
 * �����ˣ����֮��
 */
class JobLevelMapper : public Mapper<JobLevelTypeDO>
{
public:
	JobLevelTypeDO mapper(ResultSet* result) const override
	{
		JobLevelTypeDO data;
		data.setJobLevel(result->getString(1));
		return data;
	}
};

#endif // !_JOBLEVELMAPPER_H_