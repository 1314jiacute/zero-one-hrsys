#pragma once

#include "stdafx.h"
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#ifndef _RETIREMENTQUERY_H_
#define _RETIREMENTQUERY_H_


#include OATPP_CODEGEN_BEGIN(DTO)


class RetirementQuery :public PageQuery {
	DTO_INIT(RetirementQuery, PageQuery);
	// ��ѯ�ĵ�һ��������Ա�����
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.number");
	}
	DTO_FIELD(String, name);
	// ��ѯ�ĵڶ���������Ա������
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.name");
	}
	DTO_FIELD(String, idCard);
	// ��ѯ�ĵ�����������֤������
	DTO_FIELD_INFO(IDcard) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.idcard");
	}
	DTO_FIELD(String, organization);
	// ��ѯ�ĵ��ĸ���������֯
	DTO_FIELD_INFO(organization) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.organization");
	}
	DTO_FIELD(String, department);
	// ��ѯ�ĵ��������������
	DTO_FIELD_INFO(department) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.department");
	}
};

#include OATPP_CODEGEN_END(DTO)



#endif // !_RETIREMENTQUERY_H_
