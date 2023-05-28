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
	CertificateDTO(Int32 certificateId, String certificateName) :certificateId(certificateId), certificateName(certificateName) {};
	DTO_INIT(CertificateDTO, DTO);
	//�����
	API_DTO_FIELD_DEFAULT(Int32, certificateId, ZH_WORDS_GETTER("certificate.field.id"));
	//��λ֤��
	API_DTO_FIELD_DEFAULT(String, certificateName, ZH_WORDS_GETTER("certificate.field.certificateName"));
	
	
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