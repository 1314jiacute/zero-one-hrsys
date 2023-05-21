#pragma once
#ifndef _Modify_Assign_Info_DTO_
#define _Modify_Assign_Info_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �޸�ָ��Ա��������Ϣ
 */
	class ModifyAssignInfoDTO : public oatpp::DTO
{
	DTO_INIT(ModifyAssignInfoDTO, DTO);
	//���
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("employee.field.id");
	}
	// ����(�������η���)
	DTO_FIELD(String, assign);
	DTO_FIELD_INFO(assign) {
		info->description = ZH_WORDS_GETTER("employee.field.assign");
	}
	// ����
	DTO_FIELD(String, Etype);
	DTO_FIELD_INFO(Etype) {
		info->description = ZH_WORDS_GETTER("employee.field.Etype");
	}
	// ��֯
	DTO_FIELD(String, organize);
	DTO_FIELD_INFO(organize) {
		info->description = ZH_WORDS_GETTER("employee.field.organize");
	}
	// ����
	DTO_FIELD(String, depart);
	DTO_FIELD_INFO(depart) {
		info->description = ZH_WORDS_GETTER("employee.field.depart");
	}
	// ְ��
	DTO_FIELD(String, job);
	DTO_FIELD_INFO(job) {
		info->description = ZH_WORDS_GETTER("employee.field.job");
	}
	// ��λ
	DTO_FIELD(String, post);
	DTO_FIELD_INFO(post) {
		info->description = ZH_WORDS_GETTER("employee.field.post");
	}
	// ��ְ��ʼʱ��
	DTO_FIELD(String, startTime);
	DTO_FIELD_INFO(startTime) {
		info->description = ZH_WORDS_GETTER("employee.field.startTime");
	}
	// ��ְ����ʱ��
	DTO_FIELD(String, endTime);
	DTO_FIELD_INFO(endTime) {
		info->description = ZH_WORDS_GETTER("employee.field.endTime");
	}
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_Modify_Assign_Info_DTO_