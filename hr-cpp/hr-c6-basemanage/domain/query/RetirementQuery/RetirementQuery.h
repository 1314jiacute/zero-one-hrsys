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
	DTO_FIELD(String, sex);
	// Ա���Ա�
	DTO_FIELD_INFO(sex) {
		info->description = "xing bie ";
	}
	DTO_FIELD(String, age);
	// Ա������
	DTO_FIELD_INFO(age) {
		info->description = "nian ling ";
	}
	DTO_FIELD(String, mailing_address);
	// Ա��ͨѶ��ַ
	DTO_FIELD_INFO(mailing_address) {
		info->description = "di zhi ";
	}
	DTO_FIELD(String, retire_address);
	// Ա�����ݵ�
	DTO_FIELD_INFO(retire_address) {
		info->description = "tui xiu di ";
	}
	DTO_FIELD(String, Family_contact);
	// Ա����ͥ��ϵ��
	DTO_FIELD_INFO(Family_contact) {
		info->description = "jia ting lian xi ren ";
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
	DTO_FIELD(String, rank);
	// ְ��
	DTO_FIELD_INFO(rank) {
		info->description = "zhi ji";
	}
	DTO_FIELD(String, before_retire_rank);
	// ����ǰְ��
	DTO_FIELD_INFO(before_retire_rank) {
		info->description = "tui xiu qian zhi wu";
	}
	DTO_FIELD(String, before_retire_post);
	// ����ǰ��λ
	DTO_FIELD_INFO(before_retire_post) {
		info->description = "tui xiu qian gang wei";
	}
	DTO_FIELD(String, retire_time);
	// ����ʱ��
	DTO_FIELD_INFO(retire_time) {
		info->description = "tui xiu shi jian";
	}
	DTO_FIELD(String, read_retire_time);
	// ʵ������ʱ��
	DTO_FIELD_INFO(read_retire_time) {
		info->description = "shi ji tui xiu shi jian";
	}
	DTO_FIELD(String, tel);
	// �ֻ�����
	DTO_FIELD_INFO(tel) {
		info->description = "dian hua hao ma";
	}
	DTO_FIELD(String, Approved_pension_amount);
	// ���������Ͻ��
	DTO_FIELD_INFO(Approved_pension_amount) {
		info->description = "shen pi yang lao jin e";
	}
};

#include OATPP_CODEGEN_END(DTO)



#endif // !_RETIREMENTQUERY_H_
