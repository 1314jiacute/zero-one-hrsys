#pragma once
#ifndef _RRAINEE_DO_
#define _RRAINEE_DO_
#include "../DoInclude.h"

/**
 *  �������� ���� ��Ա������ ���� ��ϰԱ��ʵ����  ����Cpt
 */
class ExportEmployeeDO {
	// Ա�����
	CC_SYNTHESIZE(string, ygbh, ygbh);
	// Ա������            
	CC_SYNTHESIZE(string, pcmjxszzkhjgjlname, pcmjxszzkhjgjlname);
	// ��֯
	CC_SYNTHESIZE(string, zz, zz);
	// ����
	CC_SYNTHESIZE(string, bm, bm);
	// ְ��
	CC_SYNTHESIZE(string, zw, zw);
	// ��λ
	CC_SYNTHESIZE(string, gw, gw);
	// ��ϰ���ޣ��£�
	CC_SYNTHESIZE(string, duration, duration);  
	// ������λʱ��
	CC_SYNTHESIZE(string, ksrq, ksrq); 
	// ��ϰ����ʱ��
	CC_SYNTHESIZE(string, jsrq, jsrq);  
public:
	ExportEmployeeDO() {
	
	}
};

#endif // !_RRAINEE_DO_
