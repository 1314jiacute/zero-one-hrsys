/*
* ������������--ɾ����������(֧������ɾ��)--pine
*/
#include "stdafx.h"
#include "DeleteLegalEntityController.h"
#include "../../service/LegalEntitySet/DeleteLegalEntityService.h"


StringJsonVO::Wrapper DeleteLegalEntityController::execDeleteLegalEntity(const DeleteLegalEntityDTO::Wrapper& dto)
{

	auto jvo = StringJsonVO::createShared();

	int length = dto->ormsignorgid->size();
	if (length <= 0 || !dto->ormsignorgid) {
		jvo->init(string("param null"), RS_PARAMS_INVALID);
		return jvo;
	}

	for (auto it = dto->ormsignorgid->begin(); it != dto->ormsignorgid->end(); ++it)
	{
		if ((*it)->size() != 36) {//���жϱ�Ÿ�ʽ�Ƿ����//��һ���ŵ��ַ�����Ϊ32
			jvo->init(string("param err"), RS_PARAMS_INVALID);
			return jvo;
		}
	}

	stringstream str;
	for (auto it = dto->ormsignorgid->begin(); it != dto->ormsignorgid->end(); ++it) str << (*it).getValue("") << " ";

	if (DeleteLegalEntityService().removeData(dto)) jvo->success(str.str());
	else jvo->fail(str.str());

	return jvo;
}