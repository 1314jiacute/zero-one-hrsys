#pragma once
#ifndef _PATENTINFO_DO_
#define _PATENTINFO_DO_
#include "../DoInclude.h"

/**
 * ר�����ݿ�ʵ����
 */
class PatentinfoDO
{
    //ZLH:ר����
    CC_SYNTHESIZE(string, ZLH, ZLH);
    //UPDATEDATE : ����ʱ��
    CC_SYNTHESIZE(string, UPDATEDATE, UPDATEDATE);
    //PIMPATENTID : ר����Ϣ����
    CC_SYNTHESIZE(string, PIMPATENTID, PIMPATENTID);
    //ZLHQSJ : ר����ȡʱ��
    CC_SYNTHESIZE(string, ZLHQSJ, ZLHQSJ);
    //PIMPATENTNAME : ר������
    CC_SYNTHESIZE(string, PIMPATENTNAME, PIMPATENTNAME);
    //UPDATEMAN : ������
    CC_SYNTHESIZE(string, UPDATEMAN, UPDATEMAN);
    //CREATEMAN : ������
    CC_SYNTHESIZE(string, CREATEMAN, CREATEMAN);
    //CREATEDATE : ����ʱ��
    CC_SYNTHESIZE(string, CREATEDATE, CREATEDATE);
    //ZLPZGB : ר����׼����
    CC_SYNTHESIZE(string, ZLPZGB, ZLPZGB);
    //PIMPERSONID : ��Ա��Ϣ��ʶ
    CC_SYNTHESIZE(string, PIMPERSONID, PIMPERSONID);
    //JLSS : ��¼����
    CC_SYNTHESIZE(string, JLSS, JLSS);
    //JLSPZT : ����״̬
    CC_SYNTHESIZE(string, JLSPZT, JLSPZT);
    //JLGLBH : ��¼������
    CC_SYNTHESIZE(string, JLGLBH, JLGLBH);
    //JLCZZ : ��¼������
    CC_SYNTHESIZE(string, JLCZZ, JLCZZ);
    //ENCLOLURE : ����
    CC_SYNTHESIZE(string, ENCLOLURE, ENCLOLURE);
    //REASON : �ܾ�ԭ��
    CC_SYNTHESIZE(string, REASON, REASON);
public:
    PatentinfoDO() {

        ZLH = "";
        UPDATEDATE = "";
        PIMPATENTID = "";
        ZLHQSJ = "";
        PIMPATENTNAME = "";
        UPDATEMAN = "";
        CREATEMAN = "";
        CREATEDATE = "";
        ZLPZGB = "";
        PIMPERSONID = "";
        JLSS = "";
        JLSPZT = "";
        JLGLBH = "";
        JLCZZ = "";
        ENCLOLURE = "";
        REASON = "";
    }
};

#endif // !_SAMPLE_DO_


