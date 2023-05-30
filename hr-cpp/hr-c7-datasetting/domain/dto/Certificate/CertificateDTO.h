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
	CertificateDTO(String seialno, String pimqualtypename) :seialno(seialno), pimqualtypename(pimqualtypename) {};
	DTO_INIT(CertificateDTO, DTO);
	//�����
	API_DTO_FIELD_DEFAULT(String, seialno, ZH_WORDS_GETTER("certificate.field.seialno"));
	//��λ����֤��
	API_DTO_FIELD_DEFAULT(String, pimqualtypename, ZH_WORDS_GETTER("certificate.field.pimqualtypename"));
	
	
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