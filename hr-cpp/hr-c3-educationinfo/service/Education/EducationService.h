/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/29 10:01:46
*/
#ifndef _EDUCATIONSERVICE_H_
#define _EDUCATIONSERVICE_H_

#include "domain/dto/Education/EducationDTO.h"
#include "domain/query/EducationPage/EducationPageQuery.h"
#include "domain/query/EducationSingle/EducationSingleQuery.h"
#include "domain/dto/EducationDelete/EducationDeleteDTO.h"

class EducationService 
{
public:
	/**
	 * ��ҳ��ѯָ��Ա��������Ϣ
	 * �����ˣ�chen jun
	 */
	EducationPageDTO::Wrapper listEducationPage(const EducationPageQuery::Wrapper& query);
	/**
	 * ������ѯָ��Ա��������Ϣ
	 * �����ˣ�chen jun
	 */
	EducationSingleDTO::Wrapper listEducationSingle(const EducationSingleQuery::Wrapper& query);
	/**
	 * ���ָ��Ա��������Ϣ
	 * �����ˣ�chen jun
	 */
	uint64_t saveEducation(const EducationSingleDTO::Wrapper& dto);
	/**
	 * �޸�
	 * �����ˣ�Chen jun
	 */
	bool updateEducation(const EducationSingleDTO::Wrapper& dto);
	/**
	* ɾ������
	* ������ : Chen jun
	*/
	bool removeEducation(string id);
	/**
	* ɾ������
	* ������ : Chen jun
	*/
	bool removeEducationNotSingle(const EducationDeleteNotSingleDTO::Wrapper& dto);
};



#endif // !_EDUCATIONSERVICE_H_#pragma once



