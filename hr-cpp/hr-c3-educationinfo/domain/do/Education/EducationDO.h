/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/24 16:04:19
*/
#ifndef _EDUCATIONDO_H_
#define _EDUCATIONDO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class EducationDO
{	
	// ������Ϣ��ʶ �����
	CC_SYNTHESIZE(string, PIMEDUCATIONID, FunPIMEDUCATIONID);

	// ѧ��
	CC_SYNTHESIZE(string, XL, FunXL);

	// ��ѧʱ��
	CC_SYNTHESIZE(uint64_t, QSSJ, FunQSSJ);
	
	// ��ҵʱ��
	CC_SYNTHESIZE(uint64_t, JSSJ, FunJSSJ);

	// ��ҵԺУ
	CC_SYNTHESIZE(string, BYYX, FunBYYX);

	// һ��ѧ��
	CC_SYNTHESIZE(string, XKML, FunXKML);

	// ��ѧרҵ
	CC_SYNTHESIZE(string, SXZY, FunSXZY);


	// ѧϰ��ʽ
	CC_SYNTHESIZE(string, XLLX, FunXLLX);

	// ѧУ����
	CC_SYNTHESIZE(string, XXXZ, FunXXXZ);

	// �Ƿ��һѧ��
	CC_SYNTHESIZE(int16_t, SFDYXL, FunSFDYXL);


	//�Ƿ����ѧ��
	CC_SYNTHESIZE(int16_t, SFZGXL, FunSFZGXL);

	// ��ҵ֤
	CC_SYNTHESIZE(string, BTZ, FunBTZ);
	
	// ѧλ֤
	CC_SYNTHESIZE(string, XWZ, FunXWZ);
	
	// ѧ����֤
	CC_SYNTHESIZE(string, XLCX, FunXLCX);

	// ��������
	CC_SYNTHESIZE(string, FJ, FunFJ);
public:
	EducationDO() {
		PIMEDUCATIONID = "";
		XL = "";
		QSSJ = 2000 - 01 - 01;
		JSSJ = 2000 - 01 - 01;
		BYYX = "";
		XKML = "";
		SXZY = "";
		XLLX = "";
		XXXZ = "";
		SFDYXL = 2000 - 01 - 01;
		BTZ = "";
		XWZ = "";
		XLCX = "";
		FJ = "";

	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EDUCATIONDO_H_#pragma once
