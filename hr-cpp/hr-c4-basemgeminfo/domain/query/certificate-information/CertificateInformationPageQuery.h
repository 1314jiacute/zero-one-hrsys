#pragma once
#ifndef _CERTIFICATE_INFORMATION_PAGEQUERY_H_
#define _CERTIFICATE_INFORMATION_PAGEQUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class CertificateInformationPageQuery : public PageQuery
{
	DTO_INIT(CertificateInformationPageQuery, PageQuery);
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
		info->description = ZH_WORDS_GETTER("jobtitleinformation.field.ormorgname");
	}
	// Ա��״̬
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("jobtitleinformation.field.state");
	}
	//zgzsbh: ֤����
	DTO_FIELD(String, zgzsbh);
	DTO_FIELD_INFO(zgzsbh) {
		info->description = ZH_WORDS_GETTER("sample.field.zgzsbh");
	}
	//pimvocationalname: ֤������
	DTO_FIELD(String, pimvocationalname);
	DTO_FIELD_INFO(pimvocationalname) {
		info->description = ZH_WORDS_GETTER("sample.field.pimvocationalname");
	}
	// zslx: ֤������
	DTO_FIELD(String, zslx);
	DTO_FIELD_INFO(zslx) {
		info->description = ZH_WORDS_GETTER("sample.field.zslx");
	}
	// zghqrq: ǩ������
	DTO_FIELD(String, zghqrq);
	DTO_FIELD_INFO(zghqrq) {
		info->description = ZH_WORDS_GETTER("sample.field.zghqrq");
	}
	// zgsydw: ǩ������
	DTO_FIELD(String, zgsydw);
	DTO_FIELD_INFO(zgsydw) {
		info->description = ZH_WORDS_GETTER("sample.field.zgsydw");
	}
	// fzyxq: ��֤��Ч��
	DTO_FIELD(String, fzyxq);
	DTO_FIELD_INFO(fzyxq) {
		info->description = ZH_WORDS_GETTER("sample.field.fzyxq");
	}
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // 