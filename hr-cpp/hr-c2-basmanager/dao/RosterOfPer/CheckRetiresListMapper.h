#pragma once
/*
��Ա������-��������Ա-��ҳ��ѯԱ���б�--pine
*/
#ifndef  _CHECK_RETIRES_LIST_MAPPER_
#define  _CHECK_RETIRES_LIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/RosterOfPer/RetiredEmployeesDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class CheckRetiresListMapper : public Mapper<RetiredEmployeesDO>
{
public:
	RetiredEmployeesDO mapper(ResultSet* resultSet) const override
	{
		RetiredEmployeesDO data;
		data.setygbh(resultSet->getUInt64(1));//this
		data.setpimpersonname(resultSet->getString(2));//this


		return data;
	}
};
#endif // !_SAMPLE_MAPPER_