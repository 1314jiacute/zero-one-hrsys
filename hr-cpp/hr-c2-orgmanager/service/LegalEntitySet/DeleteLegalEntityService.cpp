/*
* ������������--ɾ����������(֧������ɾ��)--pine
*/
#include "stdafx.h"
#include "DeleteLegalEntityService.h"
#include "../../dao/LegalEntitySet/DeleteLegalEntityDAO.h"

bool DeleteLegalEntityService::removeData(const DeleteLegalEntityDTO::Wrapper& dto)
{
	DeleteLegalEntityDAO dao;
	for (auto it = dto->ormsignorgid->begin(); it != dto->ormsignorgid->end(); ++it)
	{
		//*it��String���͵Ķ���deleteById��Ҫ����string�Ĳ�������
		dao.update1((*it).getValue(""));
		dao.update2((*it).getValue(""));
		dao.update3((*it).getValue(""));
		dao.deleteById((*it).getValue(""));
	}
	return true;
}


