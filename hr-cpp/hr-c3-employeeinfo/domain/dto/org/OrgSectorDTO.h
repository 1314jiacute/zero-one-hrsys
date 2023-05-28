#pragma once
#ifndef _ORG_SECTOR_DTO_
#define _ORG_SECTOR_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class OrgSectorDTO : public oatpp::DTO
{
	DTO_INIT(OrgSectorDTO, DTO);
    // ��������
	DTO_FIELD(String, orgsectorname);
	DTO_FIELD_INFO(orgsectorname) {
		info->description = ZH_WORDS_GETTER("orgsector.field.orgname");
	}
    // ����id
	DTO_FIELD(String, orgsectorid);
	DTO_FIELD_INFO(orgsectorid) {
		info->description = ZH_WORDS_GETTER("orgsector.field.orgsectorid");
	}
    // ��֯����
	DTO_FIELD(String, orgname);
	DTO_FIELD_INFO(orgname) {
		info->description = ZH_WORDS_GETTER("orgsector.field.orgname");
	}
    // ��֯id
	DTO_FIELD(String, orgid);
	DTO_FIELD_INFO(orgid) {
		info->description = ZH_WORDS_GETTER("orgsector.field.orgid");
	}
    // // ����֯����
	// DTO_FIELD(Int32, porgname);
	// DTO_FIELD_INFO(porgname) {
	// 	info->description = ZH_WORDS_GETTER("org.field.porgname");
	// }
    // // ����֯id
	// DTO_FIELD(String, porgid);
	// DTO_FIELD_INFO(porgid) {
	// 	info->description = ZH_WORDS_GETTER("org.field.porgid");
	// }
};

/**
 * ʾ����ҳ�������
 */
class OrgSectorPageDTO : public PageDTO<OrgSectorDTO::Wrapper> 
{
	DTO_INIT(OrgSectorPageDTO, PageDTO<OrgSectorDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_Org_Sector_DTO_