#pragma once
#ifndef _QUALIFICATIONDO_H_
#define _QUALIFICATIONDO_H_

#include "../DoInclude.h"
/**
 * ִҵ�ʸ�֤����Ϣʵ��
 */
class QualificationDO
{
	// ����
	CC_SYNTHESIZE(string, qualevel, quaLevel);
	// ִҵ�ʸ�
	CC_SYNTHESIZE(string, pimqualmajorname, pimQualMajorName);
	// רҵ
	CC_SYNTHESIZE(string, quamajor, quaMajor);
public:
	QualificationDO() 
	{
		qualevel = "";
		pimqualmajorname = "";
		quamajor = "";
	}
	//�ֱ�Ϊ����ִҵ�ʸ�רҵ
	QualificationDO(string qualevel, string pimqualmajorname, string quamajor)
	{
		this->qualevel = qualevel;
		this->pimqualmajorname = pimqualmajorname;
		this->quamajor = quamajor;
	}
};

#endif