//2023��5��27��
//���ߣ���Ƥ�����
//�걨�б��DAO��д���ˣ��½���ʱ��������û������ݿ���鲻�ˣ�
#pragma once
#ifndef _DECLARE_TYPE_LIST_DAO_
#define _DECLARE_TYPE_LIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/declareType/DeclareTypeDO.h"

class DeclareTypeListDAO
{
public:
	list<DeclareTypeDO> getDeclareTypeList();
};

#endif // !_DECLARE_TYPE_LIST_DAO_


