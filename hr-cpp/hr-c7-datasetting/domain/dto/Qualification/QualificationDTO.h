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
	//����
	API_DTO_FIELD_DEFAULT(String, qualevel, ZH_WORDS_GETTER("qualification.field.qualevel"));
	//ִҵ�ʸ�
	API_DTO_FIELD_DEFAULT(String, pimqualmajorname, ZH_WORDS_GETTER("qualification.field.pimqualmajorname"));
	//רҵ
	API_DTO_FIELD_DEFAULT(String, quamajor, ZH_WORDS_GETTER("qualification.field.quamajor"));

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