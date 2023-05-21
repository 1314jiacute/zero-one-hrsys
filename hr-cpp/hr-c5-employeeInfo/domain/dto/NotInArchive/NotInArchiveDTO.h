#pragma once
#ifndef _NOT_IN_ARCHIVE_DTO_
#define _NOT_IN_ARCHIVE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//�������������
class NotInArchiveDTO : public oatpp::DTO {
	DTO_INIT(NotInArchiveDTO, DTO);
	//�������
	DTO_FIELD(String, dabh);
	DTO_FIELD_INFO(dabh) {
		info->description = ZH_WORDS_GETTER("archive.dto.dabh");
	}
	//����λ
 	DTO_FIELD(String, gldw);
	DTO_FIELD_INFO(gldw) {
		info->description = ZH_WORDS_GETTER("archive.dto.gldw");
	}
	//�������ܵ�
	DTO_FIELD(String, bgd);
	DTO_FIELD_INFO(bgd) {
		info->description = ZH_WORDS_GETTER("archive.dto.dabgd");
	}
	//������
	DTO_FIELD(String, archivescentername);
	DTO_FIELD_INFO(archivescentername) {
		info->description = ZH_WORDS_GETTER("archive.dto.archivescentername");
	}
	//����״̬
	DTO_FIELD(String, dastate);
	DTO_FIELD_INFO(dastate) {
		info->description = ZH_WORDS_GETTER("archive.dto.dastate");
	}
	//Ա�����
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("archive.dto.ygbh");
	}
	//Ա������
	DTO_FIELD(String, pimpersonname);
	DTO_FIELD_INFO(pimpersonname) {
		info->description = ZH_WORDS_GETTER("archive.dto.pimpersonname");
	}
	//������
	DTO_FIELD(String, operat);
	DTO_FIELD_INFO(operat) {
		info->description = ZH_WORDS_GETTER("archive.dto.operat");
	}
};
//���������ҳ�������
class NotInArchivePageDTO : public PageDTO<NotInArchiveDTO::Wrapper>
{
	DTO_INIT(NotInArchivePageDTO, PageDTO<NotInArchiveDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_NOT_IN_ARCHIVE_DTO_