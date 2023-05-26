#pragma once
#ifndef _COSTTYPEMAPPER_H_
#define _COSTTYPEMAPPER_H_

#include "Mapper.h"
#include "domain/do/costTypeList/CostType.h"

/**
 * ������������б����ݿ��ֶ�ƥ��ӳ��
 * �����ˣ����֮��
 */
class CostTypeMapper : public Mapper<CostTypeDO>
{
public:
	CostTypeDO mapper(ResultSet* result) const override
	{
		CostTypeDO data;
		data.setCostType(result->getString(1));
		return data;
	}
};

#endif // !_COSTTYPEMAPPER_H_