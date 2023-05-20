#ifndef JOBTITLEYDTO_H
#define JOBTITLEYDTO_H
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ְ��DTO
 */
class JobTitleInfoDTO : public oatpp::DTO
{
	DTO_INIT(JobTitleInfoDTO, DTO);
	
	// Ա������
	DTO_FIELD(String, employee_name);
	DTO_FIELD_INFO(employee_name) {
		info->description = ZH_WORDS_GETTER("jobtitle.field.employee_name");
	}
	// ��֯����
	DTO_FIELD(String, org_name);
	DTO_FIELD_INFO(org_name) {
		info->description = ZH_WORDS_GETTER("jobtitle.field.org_name");
	}
	// ְ������
	DTO_FIELD(String, jobtitle_name);
	DTO_FIELD_INFO(jobtitle_name) {
		info->description = ZH_WORDS_GETTER("jobtitle.field.jobtitle_name");
	}
	// ְ�Ƶȼ�
	DTO_FIELD(String, professor_grades);
	DTO_FIELD_INFO(professor_grades) {
		info->description = ZH_WORDS_GETTER("jobtitle.field.professor_grades");
	}
	// ��ȡ����
	DTO_FIELD(String, get_time);
	DTO_FIELD_INFO(get_time) {
		info->description = ZH_WORDS_GETTER("jobtitle.field.get_time");
	}
	// רҵ���
	DTO_FIELD(String, professional_cate);
	DTO_FIELD_INFO(professional_cate) {
		info->description = ZH_WORDS_GETTER("jobtitle.field.professional_cate");
	}
};
#endif