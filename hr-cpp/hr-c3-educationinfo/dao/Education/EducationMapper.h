/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/29 10:38:26
*/
#ifndef _EDUCATIONMAPPER_H_
#define _EDUCATIONMAPPER_H_
#include "BaseDAO.h"
#include "Mapper.h"
#include "domain/do/Education/EducationDO.h"

class EducationMapper : public Mapper<EducationDO>
{
public:
	EducationDO mapper(ResultSet* resultSet) const override
	{
		EducationDO data;
		data.setFunPIMEDUCATIONID(resultSet->getString(1));	// ������Ϣ��ʶ �����
		data.setFunXL(resultSet->getString(2));	// ѧ��
		data.setFunQSSJ(resultSet->getUInt64(3));	// ��ѧʱ��
		data.setFunJSSJ(resultSet->getUInt64(4));	// ��ҵʱ��
		data.setFunBYYX(resultSet->getString(5));	// ��ҵԺУ
		data.setFunXKML(resultSet->getString(6));	// 	// һ��ѧ��
		data.setFunSXZY(resultSet->getString(7));		// ��ѧרҵ
		data.setFunXLLX(resultSet->getString(8));	// ѧϰ��ʽ
		data.setFunXXXZ(resultSet->getString(9));	// ѧУ����
		data.setFunSFDYXL(resultSet->getUInt64(10));		// �Ƿ��һѧ��
		data.setFunSFZGXL(resultSet->getUInt64(11));		//�Ƿ����ѧ��
		data.setFunBTZ(resultSet->getString(12));		// ��ҵ֤
		data.setFunXWZ(resultSet->getString(13));		// ѧλ֤
		data.setFunXLCX(resultSet->getString(14));		// ѧ����֤
		data.setFunFJ(resultSet->getString(15));// ��������




		
		return data;
	}
};

#endif // !_EDUCATIONMAPPER_H_#pragma once

