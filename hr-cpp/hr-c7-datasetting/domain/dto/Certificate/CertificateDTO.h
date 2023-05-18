#pragma once
#ifndef _CERTIFICATEDTO_H_
#define _CERTIFICATEDTO_H_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/*
  ֤���ѯ������������
*/

class CertificateDTO : public oatpp::DTO
{
public:
	CertificateDTO(){};
	DTO_INIT(CertificateDTO, DTO);
	//Ա�����
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("certificate.field.id"));
	//Ա������
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("certificate.field.name"));
	//Ա��״̬
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("certificate.field.state"));
	//��֯
	API_DTO_FIELD_DEFAULT(String, organization, ZH_WORDS_GETTER("certificate.field.organization"));
	//֤����
	API_DTO_FIELD_DEFAULT(String, certificateNumber, ZH_WORDS_GETTER("certificate.field.certificateNumber"));
	//һ������B֤���
	API_DTO_FIELD_DEFAULT(String, certificateNubmerB, ZH_WORDS_GETTER("certificate.field.certificateNubmerB"));
	//֤������
	API_DTO_FIELD_DEFAULT(String, certificateName, ZH_WORDS_GETTER("certificate.field.certificateName"));
	//֤������
	API_DTO_FIELD_DEFAULT(String, certificateType, ZH_WORDS_GETTER("certificate.field.certificateType"));
};
/*
  ֤���ѯ��ҳ������������
*/
class CertificatePageDTO : public PageDTO<CertificateDTO::Wrapper>
{
	DTO_INIT(CertificatePageDTO, PageDTO<CertificateDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif //!_CERTIFICATEDTO_H_