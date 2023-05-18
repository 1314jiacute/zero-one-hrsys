#pragma once
/**
*  ��Ա��Ϣ��ѯ������������ʹ��
*/
#ifndef _CERTIFICATETYPE_DTO_
#define _CERTIFICATETYPE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
* ֤�����Ͳ�ѯ�������
*/
class CertificateTypeDTO : public oatpp::DTO
{
	DTO_INIT(CertificateTypeDTO, DTO);
	//֤������
	DTO_FIELD(String, certype);
	DTO_FIELD_INFO(certype) {
		info->description = ZH_WORDS_GETTER("EmpInfo.field.name");
	}

};


/**
 * ֤�����ͷ�ҳ�������
 */
class  CertificateTypePageDTO : public PageDTO< CertificateTypeDTO::Wrapper>
{
	DTO_INIT(CertificateTypePageDTO, PageDTO< CertificateTypeDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_CERTIFICATETYPE_DTO_