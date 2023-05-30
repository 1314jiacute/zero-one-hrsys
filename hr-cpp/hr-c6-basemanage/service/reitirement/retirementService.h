#pragma once
#ifndef _RETIREMENTSERVICE_H_
#define _RETIREMENTSERVICE_H_

#include <list>
#include "domain/vo/RetirementVo/RetirementVo.h"
#include "domain/query/RetirementQuery/RetirementQuery.h"
#include "domain/dto/retirement/RetiremetDto.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class retirementService
{
public:
	// ��ҳ��ѯ��������
	RetirementPageDTO::Wrapper listAll(const RetirementQuery_gan::Wrapper& query);
	/*
	// ��������
	uint64_t saveData(const RetirementDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const RetirementDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
	*/
};

#endif // !_RETIREMENTSERVICE_H_
