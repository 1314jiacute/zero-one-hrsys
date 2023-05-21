#pragma once
#ifndef _PAPER_QUERY_
#define _PAPER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������Ϣ��ҳ��ѯ����
 */
class PaperQuery : public PageQuery
{
	DTO_INIT(PaperQuery, PageQuery);
	// Ա�����
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("paperinfo.field.pimpersonid");
	}
	//// ������
	//DTO_FIELD(String, cbs);
	//DTO_FIELD_INFO(cbs) {
	//	info->description = ZH_WORDS_GETTER("paperinfo.field.cbs");
	//}
	//// ����ʱ��
	//DTO_FIELD(String, fbsj);
	//DTO_FIELD_INFO(fbsj) {
	//	info->description = ZH_WORDS_GETTER("paperinfo.field.fbsj");
	//}
	//// ��������
	//DTO_FIELD(String, kwqs);
	//DTO_FIELD_INFO(kwqs) {
	//	info->description = ZH_WORDS_GETTER("paperinfo.field.kwqs");
	//}
	//// ����
	//DTO_FIELD(String, fj);
	//DTO_FIELD_INFO(fj) {
	//	info->description = ZH_WORDS_GETTER("paperinfo.field.fj");
	//}
	//// ���������������е�����
	//DTO_FIELD(Int32, grzlwzzzdpm);
	//DTO_FIELD_INFO(grzlwzzzdpm) {
	//	info->description = ZH_WORDS_GETTER("paperinfo.field.grzlwzzzdpm");
	//}
	//// ��������
	//DTO_FIELD(String, kwmc);
	//DTO_FIELD_INFO(kwmc) {
	//	info->description = ZH_WORDS_GETTER("paperinfo.field.kwmc");
	//}
	//// ��������
	//DTO_FIELD(String, pimpapername);
	//DTO_FIELD_INFO(pimpapername) {
	//	info->description = ZH_WORDS_GETTER("paperinfo.field.pimpapername");
	//}
};

#include OATPP_CODEGEN_END(DTO)
#endif