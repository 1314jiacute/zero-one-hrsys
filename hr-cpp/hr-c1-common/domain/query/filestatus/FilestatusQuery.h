#pragma once


#ifndef _FILESATATUSQUERY_H_
#define _FILESATATUSQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ѯ�û���Ϣ�����ݴ���ģ��
 */
class FilestatusQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(FilestatusQuery, PageQuery);
	//// �ǳ�
	//DTO_FIELD(String, nickname);
	//DTO_FIELD_INFO(nickname) {
	//	info->description = ZH_WORDS_GETTER("use.field.nickname");
	//}
	// ��ѯ��ʱ���ǲ���ֻ��Ҫ��
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_