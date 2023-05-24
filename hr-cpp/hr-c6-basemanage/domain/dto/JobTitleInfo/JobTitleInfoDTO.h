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
	
	// Ա�����
	DTO_FIELD(UInt32, employee_id);
	DTO_FIELD_INFO(employee_id) {
		info->description = ZH_WORDS_GETTER("jobtitle.field.employee_id");
	}

	// ֤����
	DTO_FIELD(UInt32, certificate_id);
	DTO_FIELD_INFO(certificate_id) {
		info->description = ZH_WORDS_GETTER("jobtitle.field.certificate_id");
	}

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
	// רҵ����
	DTO_FIELD(String, professional_name);
	DTO_FIELD_INFO(professional_name) {
		info->description = ZH_WORDS_GETTER("jobtitle.field.professional_name");
	}
	// ǩ������
	DTO_FIELD(String, issuing_authority);
	DTO_FIELD_INFO(issuing_authority) {
		info->description = ZH_WORDS_GETTER("jobtitle.field.issuing_authority");
	}
	// ����λ
	DTO_FIELD(String, judging_unit);
	DTO_FIELD_INFO(judging_unit) {
		info->description = ZH_WORDS_GETTER("jobtitle.field.judging_unit");
	}
	// �Ƿ����ְ��
	DTO_FIELD(Boolean, b_highest_professional_title);
	DTO_FIELD_INFO(b_highest_professional_title) {
		info->description = ZH_WORDS_GETTER("jobtitle.field.b_highest_professional_title");
	}
};
#endif