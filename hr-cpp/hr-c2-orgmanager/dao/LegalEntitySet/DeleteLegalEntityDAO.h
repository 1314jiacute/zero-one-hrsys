#pragma once
/*
* ������������--ɾ����������(֧������ɾ��)--pine
*/
#ifndef _DELETE_LEGAL_ENTITY_DAO_
#define _DELETE_LEGAL_ENTITY_DAO_
#include "BaseDAO.h"
#include "../../domain/do/LegalEntitySet/LegalEntitySetDO.h"
#include "../../domain/query/LegalEntitySet/DeleteLegalEntityQuery.h"


class DeleteLegalEntityDAO : public BaseDAO
{
public:
	//�����ӱ�����Ϊ��
	int update1(string id);
	int update2(string id);
	int update3(string id);
	// ͨ��IDɾ������  
	int deleteById(string id);

};
#endif // !_SAMPLE_DAO_
