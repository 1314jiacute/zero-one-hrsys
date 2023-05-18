#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/05/17 20:01:54

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _EMPLOYEEINFODTO_H_
#define _EMPLOYEEINFODTO_H_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//�޸ľ���Ա����Ϣ
class EmployeeInfoDTO : public oatpp::DTO
{
	DTO_INIT(EmployeeInfoDTO, DTO);
	//Ա�����
	DTO_FIELD(UInt64, empid);
	DTO_FIELD_INFO(empid) {
		info->description = ZH_WORDS_GETTER("employee.field.id");
		info->required = true;
	}
	//Ա������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("employee.field.name");
		info->required = true;
	}
	//֤������
	DTO_FIELD(String, idtype);
	DTO_FIELD_INFO(idtype) {
		info->description = ZH_WORDS_GETTER("employee.field.idtype");
		info->required = true;
	}
	//֤������
	DTO_FIELD(Int32, idnum);
	DTO_FIELD_INFO(idnum) {
		info->description = ZH_WORDS_GETTER("employee.field.idnum");
		info->required = true;
	}
	//��������
	DTO_FIELD(String, bthdate);
	DTO_FIELD_INFO(bthdate) {
		info->description = ZH_WORDS_GETTER("employee.field.birthday");
	}
	// ����
	DTO_FIELD(Int32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("employee.field.age");
	}
	// �Ա�
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("employee.field.sex");
	}
	//Ѫ��
	API_DTO_FIELD_DEFAULT(String, blood, ZH_WORDS_GETTER("employee.field.blood"));
	// ����
	DTO_FIELD(String, nation);
	DTO_FIELD_INFO(nation) {
		info->description = ZH_WORDS_GETTER("employee.field.nation");
	}
	//��������
	API_DTO_FIELD_DEFAULT(String, residentType, ZH_WORDS_GETTER("employee.field.residentType"));
	// ����
	DTO_FIELD(String, native);
	DTO_FIELD_INFO(native) {
		info->description = ZH_WORDS_GETTER("employee.field.native");
	}
	//�������ڵ�
	API_DTO_FIELD_DEFAULT(String, residentPlace, ZH_WORDS_GETTER("employee.field.residentPlace"));
	// ������ַ
	API_DTO_FIELD_DEFAULT(String, residentLocate, ZH_WORDS_GETTER("employee.field.residentLocate"));
	// ������ַ
	API_DTO_FIELD_DEFAULT(String, birthPlace, ZH_WORDS_GETTER("employee.field.birthPlace"));
	// ͨѶ��ַ
	API_DTO_FIELD_DEFAULT(String, comPlace, ZH_WORDS_GETTER("employee.field.comPlace"));
	// �ж�����Ů֤
	API_DTO_FIELD_DEFAULT(Boolean, onlyCredit, ZH_WORDS_GETTER("employee.field.onlyCredit"));
	// �����س�
	API_DTO_FIELD_DEFAULT(String, hobby, ZH_WORDS_GETTER("employee.field.hobby"));
	// ����״��
	API_DTO_FIELD_DEFAULT(String, health, ZH_WORDS_GETTER("employee.field.health"));
	// ����״��
	DTO_FIELD(String, marriage);
	DTO_FIELD_INFO(marriage) {
		info->description = ZH_WORDS_GETTER("employee.field.marriage");
	}
	// ������ò
	DTO_FIELD(String, politic);
	DTO_FIELD_INFO(politic) {
		info->description = ZH_WORDS_GETTER("employee.field.politic");
	}
	// ְ��
	DTO_FIELD(String, rank);
	DTO_FIELD_INFO(rank) {
		info->description = ZH_WORDS_GETTER("employee.field.rank");
	}
	// �μӹ���ʱ��
	DTO_FIELD(String, workTime);
	DTO_FIELD_INFO(workTime) {
		info->description = ZH_WORDS_GETTER("employee.field.workTime");
	}
	// ������λʱ��
	DTO_FIELD(String, inTime);
	DTO_FIELD_INFO(inTime) {
		info->description = ZH_WORDS_GETTER("employee.field.inTime");
	}
	// ��������
	DTO_FIELD(String, email);
	DTO_FIELD_INFO(email) {
		info->description = ZH_WORDS_GETTER("employee.field.email");
	}
	// ����ְ��
	DTO_FIELD(String, techTitle);
	DTO_FIELD_INFO(techTitle) {
		info->description = ZH_WORDS_GETTER("employee.field.techTitle");
	}
	// ���ѧ��
	DTO_FIELD(String, acaCredit);
	DTO_FIELD_INFO(acaCredit) {
		info->description = ZH_WORDS_GETTER("employee.field.acaCredit");
	}
	// ��һѧ��
	DTO_FIELD(String, firAcaCredit);
	DTO_FIELD_INFO(firAcaCredit) {
		info->description = ZH_WORDS_GETTER("employee.field.firAcaCredit");
	}
	// ִҵ֤��
	DTO_FIELD(String, pracCertificate);
	DTO_FIELD_INFO(pracCertificate) {
		info->description = ZH_WORDS_GETTER("employee.field.pracCertificate");
	}
	// ��Ƭ·��
	DTO_FIELD(String, photo);
	DTO_FIELD_INFO(photo) {
		info->description = ZH_WORDS_GETTER("employee.field.photo");
	}
	//�ֻ�����
	DTO_FIELD(String, phone);
	DTO_FIELD_INFO(phone) {
		info->description = ZH_WORDS_GETTER("employee.field.phone");
		info->required = true;
	}
	//Ա��״̬
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("employee.field.state");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EMPLOYEEINFODTO_H_