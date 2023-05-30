#pragma once
#ifndef _QUALIFICATIONQUERY_H_
#define _QUALIFICATIONQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class QualificationQuery :public PageQuery
{
	DTO_INIT(QualificationQuery, PageQuery);
	//����
	API_DTO_FIELD_DEFAULT(String, qualevel, ZH_WORDS_GETTER("qualification.field.qualevel"));
	//ִҵ�ʸ�
	API_DTO_FIELD_DEFAULT(String, pimqualmajorname, ZH_WORDS_GETTER("qualification.field.pimqualmajorname"));
	//רҵ
	API_DTO_FIELD_DEFAULT(String, quamajor, ZH_WORDS_GETTER("qualification.field.quamajor"));
};

#include OATPP_CODEGEN_END(DTO)
#endif