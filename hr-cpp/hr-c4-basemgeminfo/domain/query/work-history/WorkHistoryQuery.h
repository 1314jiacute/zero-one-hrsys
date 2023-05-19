#pragma once
#ifndef _WORKHISTORY_QUERY_H_
#define _WORKHISTORY_QUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ����ѯ�û���Ϣ�����ݴ���ģ��
 */
class WorkHistoryQuery : public oatpp::DTO
{
	// �����ʼ��
	DTO_INIT(WorkHistoryQuery, DTO);
	
	//ormorgname: ������λ
	DTO_FIELD(String, ormorgname);
	DTO_FIELD_INFO(ormorgname) {
		info->description = ZH_WORDS_GETTER("workhistory.field.ormorgname");
	}
	
};

#include OATPP_CODEGEN_END(DTO)
#endif 
