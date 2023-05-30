#pragma once
/*
��Ա������-��������Ա-��ҳ��ѯԱ���б�--pine
*/
#ifndef _CHECK_RETIRES_DTO_
#define _CHECK_RETIRES_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class CheckRetiresListDTO : public oatpp::DTO
{
public:
	//�޲ι���
	CheckRetiresListDTO() {};
	//�вι���
	//CheckRetiresListDTO(UInt64 id, String name, Int32 age, String sex) {};
	//CheckRetiresListDTO(UInt64 id, String name) :id(id), name(name) {};
	DTO_INIT(CheckRetiresListDTO, DTO);
	// Ա�����
	DTO_FIELD(UInt64, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.ygbh");
	}
	// Ա������
	DTO_FIELD(String, pimpersonname);
	DTO_FIELD_INFO(pimpersonname) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.pimpersonname");
	}
};

/**
 * ʾ����ҳ�������
 */
class CheckRetiresListPageDTO : public PageDTO<CheckRetiresListDTO::Wrapper>
{
	DTO_INIT(CheckRetiresListPageDTO, PageDTO<CheckRetiresListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // 