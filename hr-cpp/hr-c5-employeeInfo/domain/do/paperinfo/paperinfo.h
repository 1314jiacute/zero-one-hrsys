#pragma once
#ifndef _PAPERINFO_DO_
#define _PAPERINFO_DO_
#include "../DoInclude.h"

/**
 * ר�����ݿ�ʵ����
 */
class PaperinfoDO
{
    //GRZLWZZZDPM:���������������е�����
    CC_SYNTHESIZE(string, grzlwzzzdpm, GRZLWZZZDPM);
	//UPDATEMAN:������
	CC_SYNTHESIZE(string, updateman, UPDATEMAN);
	//PIMPAPERID:������Ϣ��ʶ
	CC_SYNTHESIZE(string, pimpaperid, PIMPAPERID);
	//CREATEDATE:����ʱ��
	CC_SYNTHESIZE(string, createdate, CREATEDATE);
	//UPDATEDATE:����ʱ��
	CC_SYNTHESIZE(string, updatedate, UPDATEDATE);
	//CREATEMAN:������
	CC_SYNTHESIZE(string, createman, CREATEMAN);
	//FBSJ:����ʱ��
	CC_SYNTHESIZE(string, fbsj, FBSJ);
	//PIMPAPERNAME:��������
	CC_SYNTHESIZE(string, pimpapername, PIMPAPERNAME);
	//CBSHKWMC:�������������
	CC_SYNTHESIZE(string, cbshkwmc, CBSHKWMC);
	//PIMPERSONID:��Ա��Ϣ��ʶ
	CC_SYNTHESIZE(string, pimpersonid, PIMPERSONID);
	//FJ:����
	CC_SYNTHESIZE(string, fj, FJ);
	//JLSPZT:����״̬
	CC_SYNTHESIZE(string, jlspzt, JLSPZT);
	//JLGLBH:��¼������
	CC_SYNTHESIZE(string, jlglbh, JLGLBH);
	//JLCZZ:��¼������
	CC_SYNTHESIZE(string, jlczz, JLCZZ);
	//JLSS:��¼����
	CC_SYNTHESIZE(string, jlss, JLSS);
	//CBS:������
	CC_SYNTHESIZE(string, cbs, CBS);
	//KWMC:��������
	CC_SYNTHESIZE(string, kwmc, KWMC);
	//KWQS:��������
	CC_SYNTHESIZE(string, kwqs, KWQS);
	//REASON:�ܾ�ԭ��
	CC_SYNTHESIZE(string, reason, REASON);
public:
    PaperinfoDO() {

		grzlwzzzdpm = "";
		updateman = "";
		pimpaperid = "";
		createdate = "";
		updatedate = "";
		createman = "";
		fbsj = "";
		pimpapername = "";
		cbshkwmc = "";
		pimpersonid = "";
		fj = "";
		jlspzt = "";
		jlglbh = "";
		jlczz = "";
		jlss = "";
		cbs = "";
		kwmc = "";
		kwqs = "";
		reason = "";
 
    }
};

#endif // !_SAMPLE_DO_


