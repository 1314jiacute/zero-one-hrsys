#pragma once
#ifndef _TITLEDTO_H_
#define _TITLEDTO_H_
#include "../../GlobalInclude.h"
#include "ApiHelper.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ�����޸�ְ��Ŀ¼��Ϣ�Ĵ������
 */
class TitleDTO : public oatpp::DTO
{
public:
	TitleDTO() {};
	DTO_INIT(TitleDTO, DTO);


	//�����
	DTO_FIELD(Int32, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("Title.field.id");
	}
	//ְ�ƴ���
	DTO_FIELD(String, num);
	DTO_FIELD_INFO(num) {
		info->description = ZH_WORDS_GETTER("Title.field.num");
		//ְ��Ŀ¼����

	}API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("Title.field.name"));
	//ְ��Ŀ¼����
	API_DTO_FIELD_DEFAULT(String, dtype, ZH_WORDS_GETTER("Title.field.dtype"));
	//ְ������
	API_DTO_FIELD_DEFAULT(String, Ttype, ZH_WORDS_GETTER("Title.field.type"));
};

/**
 * ����һ��ְ��Ŀ¼��Ϣ��ҳ�������
 */
class TitlePageDTO : public PageDTO<TitleDTO::Wrapper>
{
	DTO_INIT(TitlePageDTO, PageDTO<TitleDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _TITLEDTO_H_
