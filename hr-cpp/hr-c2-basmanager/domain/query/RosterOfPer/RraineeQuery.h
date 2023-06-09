#pragma once
#ifndef _RRAINEE_QUERY_
#define _RRAINEE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  �������� ���� ��Ա������ ���� ��ϰԱ��   ����Cpt
 */
class RraineeQuery: public PageQuery
{
	DTO_INIT(RraineeQuery, PageQuery);
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("RosterOfPer.field.ygbh");
	}
	// Ա������
	DTO_FIELD(String, pcmjxszzkhjgjlname);
	DTO_FIELD_INFO(pcmjxszzkhjgjlname) {
		info->description = ZH_WORDS_GETTER("RosterOfPer.field.pcmjxszzkhjgjlname");
	}
	// ��֯
	DTO_FIELD(String, zz);
	DTO_FIELD_INFO(zz) {
		info->description = ZH_WORDS_GETTER("RosterOfPer.field.zz");
	}
	// ����
	DTO_FIELD(String, bm);
	DTO_FIELD_INFO(bm) {
		info->description = ZH_WORDS_GETTER("RosterOfPer.field.bm");
	}
	//ְ��/
	DTO_FIELD(String, zw);
	DTO_FIELD_INFO(zw) {
		info->description = ZH_WORDS_GETTER("RosterOfPer.field.zw");
	}
	//��λ
	DTO_FIELD(String, gw);
	DTO_FIELD_INFO(gw) {
		info->description = ZH_WORDS_GETTER("RosterOfPer.field.gw");
	}
	//��ϰ���ޣ��£�
	DTO_FIELD(String, duration);
	DTO_FIELD_INFO(duration) {
		info->description = ZH_WORDS_GETTER("RosterOfPer.field.duration");
	}
	//������λʱ��
	DTO_FIELD(String, ksrq);
	DTO_FIELD_INFO(ksrq) {
		info->description = ZH_WORDS_GETTER("RosterOfPer.field.ksrq");
	}
	//��ϰ����ʱ��
	DTO_FIELD(String, jsrq);
	DTO_FIELD_INFO(jsrq) {
		info->description = ZH_WORDS_GETTER("RosterOfPer.field.jsrq");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RRAINEE_QUERY_