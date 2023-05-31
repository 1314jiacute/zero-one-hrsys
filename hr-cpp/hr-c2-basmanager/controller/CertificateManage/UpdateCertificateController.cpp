
/**
 *  ֤����� ���� ֤����Ϣ ���� ��ѯ������ָ��֤�� ���� ������
 */
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "UpdateCertificateController.h"
#include "../../service/CertificateManage/SpercificCertificateService.h"

StringJsonVO::Wrapper UpdateCertificateController::execUpdateSpercificCertificate(const SpercificCertificateDTO::Wrapper& dto)
{
	{
		// ���巵�����ݶ���
		auto jvo = StringJsonVO::createShared();
		// ����У��
		if (dto->PIMVOCATIONALID.getValue("").empty())
		{
			jvo->init(String("PIMVOCATIONALID must be not null"), RS_PARAMS_INVALID);
			return jvo;
		}
		// ����һ��Service
		SpercificCertificateService service;
		// ִ��������
		if (service.updateData(dto)) {
			jvo->success(dto->PIMVOCATIONALID);
		}
		else
		{
			jvo->fail(dto->PIMVOCATIONALID);
		}
		// ��Ӧ���
		return jvo;
	}
}

SpercificCertificateJsonVO::Wrapper UpdateCertificateController::execGetSpercificCertificate(const SpercificCertificateQuery::Wrapper& query)
{
	// ����һ��JsonVO����
	auto vo = SpercificCertificateJsonVO::createShared();
	// ����һ����ҳ����
	SpercificCertificateService service;
	auto result = service.querySpercificCertificate(query);

	vo->success(result);
	// ��Ӧ���
	return vo;
}