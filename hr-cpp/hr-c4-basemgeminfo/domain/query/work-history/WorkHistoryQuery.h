#pragma once
#ifndef _WORKHISTORY_QUERY_H_
#define _WORKHISTORY_QUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ����ѯ�û���Ϣ�����ݴ���ģ��
 */
class WorkHistoryQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(WorkHistoryQuery, PageQuery);
	//rzkssj: ��ְ��ʼʱ��
	DTO_FIELD(String, rzkssj);
	DTO_FIELD_INFO(rzkssj) {
		info->description = ZH_WORDS_GETTER("use.field.rzkssj");
	}
	//rzjssj: ��ְ����ʱ��
	DTO_FIELD(String, rzjssj);
	DTO_FIELD_INFO(rzjssj) {
		info->description = ZH_WORDS_GETTER("use.field.rzjssj");
	}
	//ormorgname: ������λ
	DTO_FIELD(String, ormorgname);
	DTO_FIELD_INFO(ormorgname) {
		info->description = ZH_WORDS_GETTER("use.field.ormorgname");
	}
	//ormdutyname: ְ��
	DTO_FIELD(String, ormdutyname);
	DTO_FIELD_INFO(ormdutyname) {
		info->description = ZH_WORDS_GETTER("use.field.ormdutyname");
	}
	//ormpostname: ��λ
	DTO_FIELD(String, ormpostname);
	DTO_FIELD_INFO(ormpostname) {
		info->description = ZH_WORDS_GETTER("use.field.ormpostname");
	}
	//cfplx: ��ְ�������
	DTO_FIELD(String, cfplx);
	DTO_FIELD_INFO(cfplx) {
		info->description = ZH_WORDS_GETTER("use.field.cfplx");
	}
	//enable: �Ƿ���Ҫ����
	DTO_FIELD(String, enable);
	DTO_FIELD_INFO(enable) {
		info->description = ZH_WORDS_GETTER("use.field.enable");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif 
