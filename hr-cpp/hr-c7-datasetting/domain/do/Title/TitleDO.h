#pragma once
#ifndef _TITLEDO_H_
#define _TITLEDO_H_

#include "../DoInclude.h"
/**
 * ְ��Ŀ¼��Ϣʵ��
 */
class TitleDO
{

	CC_SYNTHESIZE(string, id, Id);
	CC_SYNTHESIZE(string, name, Name);

public:
	TitleDO() {}
	TitleDO(string Id,string Name) 
	{
		this->id = Id;
		this->name = Name;
		// ����Ը�����Ҫ�����������
	}
};

#endif