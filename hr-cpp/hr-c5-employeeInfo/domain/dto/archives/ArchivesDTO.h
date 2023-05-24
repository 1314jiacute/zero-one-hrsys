#pragma once
#ifndef _ARCHIVES_DTO_
#define _ARCHIVES_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������Ϣ�������
 */
class ArchivesDTO : public oatpp::DTO
{
public:
	ArchivesDTO() {}
	DTO_INIT(ArchivesDTO, DTO);

	// ������ţ�
	DTO_FIELD(String, archivesNo);
	DTO_FIELD_INFO(archivesNo) {
		info->description = ZH_WORDS_GETTER("archives.field.archivesNo");
	}

	// ����λ��
	DTO_FIELD(String, managementUnits);
	DTO_FIELD_INFO(managementUnits) {
		info->description = ZH_WORDS_GETTER("archives.field.managementUnits");
	}

	// �������ܵأ�
	DTO_FIELD(String, DABGD);
	DTO_FIELD_INFO(DABGD) {
		info->description = ZH_WORDS_GETTER("archives.field.DABGD");
	}

	// �����ң�
	DTO_FIELD(String, archivesCenterName);
	DTO_FIELD_INFO(archivesCenterName) {
		info->description = ZH_WORDS_GETTER("archives.field.archivesCenterName");
	}

	// Ա����ţ�
	DTO_FIELD(String, YGBH);
	DTO_FIELD_INFO(YGBH) {
		info->description = ZH_WORDS_GETTER("archives.field.YGBH");
	}

	// Ա��������
	DTO_FIELD(String, PimPersonName);
	DTO_FIELD_INFO(PimPersonName) {
		info->description = ZH_WORDS_GETTER("archives.field.PimPersonName");
	}

	// Ա��״̬
	DTO_FIELD(String, ygzt);
	DTO_FIELD_INFO(ygzt) {
		info->description = ZH_WORDS_GETTER("archives.field.ygzt");
	}

	// ������λ��
	DTO_FIELD(String, ORMORGName);
	DTO_FIELD_INFO(ORMORGName) {
		info->description = ZH_WORDS_GETTER("archives.field.ORMORGName");
	}

	// ����״̬��
	DTO_FIELD(String, DAZT);
	DTO_FIELD_INFO(DAZT) {
		info->description = ZH_WORDS_GETTER("archives.field.DAZT");
	}
};

/**
 * ������Ϣ��ҳ�������
 */
class ArchivesPageDTO : public PageDTO<ArchivesDTO::Wrapper>
{
	DTO_INIT(ArchivesPageDTO, PageDTO<ArchivesDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif