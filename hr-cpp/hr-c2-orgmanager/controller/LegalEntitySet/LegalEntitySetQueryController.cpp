#include "stdafx.h"
#include "LegalEntitySetQueryController.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include <iostream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include "FastDfsClient.h"
#include "tree/TreeUtil.h"
#include "service/LegalEntitySet/LegalEntitySetService.h"


/* �����������ÿ���������ʵ��--����֯����-��������-�����������ã�--TripleGold */

LegalEntitySetQueryPageJsonVO::Wrapper LegalEntitySetQueryController::execQueryLES(const LegalEntitySetQuery::Wrapper& query)
{
	// ����һ��Service
	LegalEntitySetService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = LegalEntitySetQueryPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
