#pragma once
#ifndef _QUALIFICATIONDTO_H_
#define _QUALIFICATIONDTO_H_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/*
  ֤���ѯ������������
*/

class QualificationDTO : public oatpp::DTO
{
public:
	QualificationDTO() {};
	DTO_INIT(QualificationDTO, DTO);
	//ִҵ�ʸ�����
	API_DTO_FIELD_DEFAULT(String, qualificationName, ZH_WORDS_GETTER("qualification.field.qualificationName"));
	//����
	API_DTO_FIELD_DEFAULT(String, rank, ZH_WORDS_GETTER("qualification.field.rank"));
	//ִҵ�ʸ�
	API_DTO_FIELD_DEFAULT(String, practicingqualification, ZH_WORDS_GETTER("qualification.field.practicingqualification"));
	//רҵ
	API_DTO_FIELD_DEFAULT(String, profession, ZH_WORDS_GETTER("qualification.field.profession"));

};
/*
  ֤���ѯ��ҳ������������
*/
class QualificationPageDTO : public PageDTO<QualificationDTO::Wrapper>
{
	DTO_INIT(QualificationPageDTO, PageDTO<QualificationDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif //!_qualificationDTO_H_