#pragma once
#ifndef _CERTIFICATE_INFORMATION_DTO_H_
#define _CERTIFICATE_INFORMATION_DTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ͬ��ѯ������������
 */
class CertificateInformationDTO : public oatpp::DTO
{
public:
	CertificateInformationDTO() {};
	CertificateInformationDTO(String id, String name) :id(id), name(name) {};

	DTO_INIT(CertificateInformationDTO, DTO);
	// Ա�����
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// Ա������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// ��֯ ormorgname
	DTO_FIELD(String, ormorgname);
	DTO_FIELD_INFO(ormorgname) {
		info->description = ZH_WORDS_GETTER("certificateinformation.field.ormorgname");
	}
	// Ա��״̬
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("certificateinformation.field.state");
	}
    //zgzsbh: ֤����
	DTO_FIELD(String, zgzsbh);
	DTO_FIELD_INFO(zgzsbh) {
		info->description = ZH_WORDS_GETTER("certificateinformation.field.zgzsbh");
	}
	// pimvocationalname: ֤������
	DTO_FIELD(String, pimvocationalname);
	DTO_FIELD_INFO(pimvocationalname) {
		info->description = ZH_WORDS_GETTER("certificateinformation.field.pimvocationalname");
	}
	//zslx: ֤������
	DTO_FIELD(String, zslx);
	DTO_FIELD_INFO(zslx) {
		info->description = ZH_WORDS_GETTER("certificateinformation.field.zslx");
	}
	//zghqrq: ǩ������
	DTO_FIELD(String, zghqrq);
	DTO_FIELD_INFO(zghqrq) {
		info->description = ZH_WORDS_GETTER("certificateinformation.field.zghqrq");
	}
	//zgsydw: ǩ������
	DTO_FIELD(String, zgsydw);
	DTO_FIELD_INFO(zgsydw) {
		info->description = ZH_WORDS_GETTER("certificateinformation.field.zgsydw");
	}
	//fzyxq: ��֤��Ч��
	DTO_FIELD(String, fzyxq);
	DTO_FIELD_INFO(fzyxq) {
		info->description = ZH_WORDS_GETTER("certificateinformation.field.fzyxq");
	}
	
};

/**
 * ��ͬ��ѯ��ҳ������������
 */
class CertificateInformationPageDTO : public PageDTO<CertificateInformationDTO::Wrapper>
{
	DTO_INIT(CertificateInformationPageDTO, PageDTO<CertificateInformationDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif
