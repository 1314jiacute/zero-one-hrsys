#pragma once


#ifndef _PAPERINFO_DTO_
#define _PAPERINFO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ר����Ϣ�������
 */
class PaperinfoDTO : public oatpp::DTO
{

public:
    PaperinfoDTO() {};

    DTO_INIT(PaperinfoDTO, DTO);


	//GRZLWZZZDPM:���������������е�����
	DTO_FIELD(String, grzlwzzzdpm);
	DTO_FIELD_INFO(grzlwzzzdpm) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.grzlwzzzdpm");
	}
	//UPDATEMAN:������
	DTO_FIELD(String, updateman);
	DTO_FIELD_INFO(updateman) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.updateman");
	}
	//PIMPAPERID:������Ϣ��ʶ
	DTO_FIELD(String, pimpaperid);
	DTO_FIELD_INFO(pimpaperid) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.pimpaperid");
	}
	//CREATEDATE:����ʱ��
	DTO_FIELD(String, createdate);
	DTO_FIELD_INFO(createdate) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.createdate");
	}
	//UPDATEDATE:����ʱ��
	DTO_FIELD(String, updatedate);
	DTO_FIELD_INFO(updatedate) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.updatedate");
	}
	//CREATEMAN:������
	DTO_FIELD(String, createman);
	DTO_FIELD_INFO(createman) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.createman");
	}
	//FBSJ:����ʱ��
	DTO_FIELD(String, fbsj);
	DTO_FIELD_INFO(fbsj) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.fbsj");
	}
	//PIMPAPERNAME:��������
	DTO_FIELD(String, pimpapername);
	DTO_FIELD_INFO(pimpapername) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.pimpapername");
	}
	//CBSHKWMC:�������������
	DTO_FIELD(String, cbshkwmc);
	DTO_FIELD_INFO(cbshkwmc) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.cbshkwmc");
	}
	//PIMPERSONID:��Ա��Ϣ��ʶ
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.pimpersonid");
	}
	//FJ:����
	DTO_FIELD(String, fj);
	DTO_FIELD_INFO(fj) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.fj");
	}
	//JLSPZT:����״̬
	DTO_FIELD(String, jlspzt);
	DTO_FIELD_INFO(jlspzt) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.jlspzt");
	}
	//JLGLBH:��¼������
	DTO_FIELD(String, jlglbh);
	DTO_FIELD_INFO(jlglbh) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.jlglbh");
	}
	//JLCZZ:��¼������
	DTO_FIELD(String, jlczz);
	DTO_FIELD_INFO(jlczz) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.jlczz");
	}
	//JLSS:��¼����
	DTO_FIELD(String, jlss);
	DTO_FIELD_INFO(jlss) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.jlss");
	}
	//CBS:������
	DTO_FIELD(String, cbs);
	DTO_FIELD_INFO(cbs) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.cbs");
	}
	//KWMC:��������
	DTO_FIELD(String, kwmc);
	DTO_FIELD_INFO(kwmc) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.kwmc");
	}
	//KWQS:��������
	DTO_FIELD(String, kwqs);
	DTO_FIELD_INFO(kwqs) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.kwqs");
	}
	//REASON:�ܾ�ԭ��
	DTO_FIELD(String, reason);
	DTO_FIELD_INFO(reason) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.reason");
	}


};

/**
 * ��ҳ�������
 */
class PaperinfoPageDTO : public PageDTO<PaperinfoDTO::Wrapper>
{
    DTO_INIT(PaperinfoPageDTO, PageDTO<PaperinfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
