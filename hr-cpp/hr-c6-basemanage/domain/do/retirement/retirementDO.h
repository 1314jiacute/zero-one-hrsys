#pragma once
#ifndef _RETIREMENTDO_H_
#define _RETIREMENTDO_H_
#include "../DoInclude.h"
#include "../hr-sample/Macros.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class retirementDO
{
	// Ա�����
	CC_SYNTHESIZE(string, id, Id);
	// Ա������
	CC_SYNTHESIZE(string, name, Name);
	// Ա���Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// Ա������
	CC_SYNTHESIZE(string, age, Age);
	// Ա��ͨѶ��ַ
	CC_SYNTHESIZE(string, mailing_address, Mailing_address);
	// Ա�����ݵ�ַ
	CC_SYNTHESIZE(string, retire_address, Retire_address);
	// Ա����ͥ��ϵ��
	CC_SYNTHESIZE(string, Family_contact, Family_Contact);
	// Ա����֯
	CC_SYNTHESIZE(string, organization, Organization);
	// Ա������
	CC_SYNTHESIZE(string, department, Department);
	// Ա��ְ��
	CC_SYNTHESIZE(string, rank, Rank);
	// Ա������ǰְ��
	CC_SYNTHESIZE(string, before_retire_rank, Before_retire_rank);
	// Ա������ǰ��λ
	CC_SYNTHESIZE(string, before_retire_post, Before_retire_post);
	// Ա������ʱ��
	CC_SYNTHESIZE(string, retire_time, Retire_time);
	// Ա��ʵ������ʱ��
	CC_SYNTHESIZE(string, read_retire_time, Read_retire_time);
	// Ա���绰
	CC_SYNTHESIZE(string, tel, Tel);
	// Ա�����Ͻ��
	CC_SYNTHESIZE(string, Approved_pension_amount, Approved_Pension_amount);
public:
	retirementDO() {
	}
};

#endif // !_RETIREMENTDO_H_
