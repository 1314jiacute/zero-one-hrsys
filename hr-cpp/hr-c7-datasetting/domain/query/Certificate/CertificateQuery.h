#pragma once
#ifndef _CERTIFICATEQUERY_H_
#define _CERTIFICATEQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CertificateQuery :public PageQuery
{
	DTO_INIT(CertificateQuery, PageQuery);
	//�����
	API_DTO_FIELD_DEFAULT(String, seialno, ZH_WORDS_GETTER("certificate.field.seialno"));
	//��λ����֤��
	API_DTO_FIELD_DEFAULT(String, pimqualtypename, ZH_WORDS_GETTER("certificate.field.pimqualtypename"));
};

#include OATPP_CODEGEN_END(DTO)
#endif