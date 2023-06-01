#pragma once

#include "stdafx.h"
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#ifndef _RETIREMENTQUERY_H_
#define _RETIREMENTQUERY_H_


#include OATPP_CODEGEN_BEGIN(DTO)


class RetirementQuery_gan :public PageQuery {
	DTO_INIT(RetirementQuery_gan, PageQuery);
	// ��ѯ�ĵ�һ��������Ա�����
	// Ա��id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.number");
	}
	DTO_FIELD(String, name);
	// ��ѯ�ĵڶ���������Ա������
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.name");
	}
	DTO_FIELD(String, idcard);
	// ��ѯ�ĵڶ���������Ա�����֤
	DTO_FIELD_INFO(idcard) {
		info->description = "zheng jian hao ma";
	}
	DTO_FIELD(String, organization);
	// ��֯
	DTO_FIELD_INFO(organization) {
		info->description = "zu zhi";
	}
	DTO_FIELD(String, department);
	// ����
	DTO_FIELD_INFO(department) {
		info->description = "bu men";
	}
};

#include OATPP_CODEGEN_END(DTO)



#endif // !_RETIREMENTQUERY_H_
