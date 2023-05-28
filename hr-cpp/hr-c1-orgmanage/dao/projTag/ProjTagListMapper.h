#pragma once
#ifndef _PROJTAGLISTMAPPER_H_
#define _PROJTAGLISTMAPPER_H_

#include "Mapper.h"
#include "domain/do/projTag/ProjTagDO.h"

/**
 * ��Ŀ��ǩ�б��ֶ�ƥ��ӳ��
 * �����ˣ����֮��
 */
class ProjTagListMapper : public Mapper<ProjTagDO>
{
public:
	ProjTagDO mapper(ResultSet* resultSet) const override
	{
		ProjTagDO data;

		data.setId(resultSet->getString(1));
		data.setCreator(resultSet->getString(2));
		data.setTagName(resultSet->getString(3));
		data.setUpdater(resultSet->getString(4));
		data.setCreateTime(resultSet->getString(5));
		data.setUpdateTime(resultSet->getString(6));
		data.setOrgId(resultSet->getString(7));

		return data;
	}
};

#endif // !_PROJTAGLISTMAPPER_H_