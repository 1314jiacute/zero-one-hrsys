#include "stdafx.h"
#include "FamilysituationController.h"
#include "../../service/familysituation/FamilysituationService.h"

//FamilysituationPageJsonVO::Wrapper FamilysituationController::execQueryByFamilysituation(const FamilysituationQuery::Wrapper& query, const PayloadDTO& payload)
//{
//	// ����һ��Service
//	FamilysituationService service;
//	/**************Service***************/
//	//������
//	/**************Service***************/
//
//}
//
//Uint64JsonVO::Wrapper FamilysituationController::execAddFamilysituation(const FamilysituationDTO::Wrapper& dto)
//{
//	// ���巵�����ݶ���
//	auto jvo = Uint64JsonVO::createShared();
//	// ����У��
//	// �ǿ�У��
//	if (!dto->frelationship || !dto->name)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// ��ЧֵУ��
//	if (dto->name->empty())
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// ����һ��Service
//	FamilysituationService service;
//	/**************Service***************/
//	//������
//	/**************Service***************/
//	return jvo;
//}
//
//Uint64JsonVO::Wrapper FamilysituationController::execModifyFamilysituation(const FamilysituationDTO::Wrapper& dto)
//{
//	// ���巵�����ݶ���
//	auto jvo = Uint64JsonVO::createShared();
//	// ����У��
//	// �ǿ�У��
//	if (!dto->frelationship || !dto->name)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// ��ЧֵУ��
//	if (dto->name->empty())
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	/**************Service***************/
//	//������
//	/**************Service***************/
//	return jvo;
//}
//
//Uint64JsonVO::Wrapper FamilysituationController::execDeleteFamilysituation(const FamilysituationDTO::Wrapper& dto)
//{
//	// ���巵�����ݶ���
//	auto jvo = Uint64JsonVO::createShared();
//	// ����У��
//	// �ǿ�У��
//	if (!dto->frelationship || !dto->name)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// ��ЧֵУ��
//	if (dto->name->empty())
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	/**************Service***************/
//	//������
//	/**************Service***************/
//	return jvo;
//}
//
