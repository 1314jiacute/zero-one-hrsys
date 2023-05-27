/*
 Copyright Muggle. All rights reserved.

 @Author: Muggle
 @Date: 2023/05/19 23:24:02

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
#pragma once
#ifndef _LD_M_CONTROLLER_
#define _LD_M_CONTROLLER_

#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/LaborDispatch/LaborDispatchQuery-mg.h"
#include "domain/dto/LaborDispatch/LaborDispatchDTO-mg.h"
#include "domain/dto/LaborDispatch/LaborDispatchDTO.h"
#include "domain/vo/muggle/LaborDispatchJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class LaborDispatchMController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(LaborDispatchMController);
public:
	// ���ݹ�˾���Ʋ�ѯָ����˾��Ϣ
	ENDPOINT_INFO(queryLaborDispatch) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("labordispatch_mug.get.summary");
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_RSP_JSON_WRAPPER(LaborDispatchMDTO);
		
		// ���������������
		info->queryParams.add<String>("corporateName").description = ZH_WORDS_GETTER("labordispatch_mug.field.corporatename");
		info->queryParams["corporateName"].addExample("default", String("PDD"));
		info->queryParams["corporateName"].required = false;
	}

	ENDPOINT(API_M_GET, "/contract-management/query-by-corporate-name", queryLaborDispatch,QUERIES(QueryParams, queryParams)) {
		API_HANDLER_QUERY_PARAM(query, LaborDispatchMQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryLaborDispatch(query));
	}

	// �޸�ָ����˾��Ϣ
	ENDPOINT_INFO(modifyLaborDispatch) {
		info->summary = ZH_WORDS_GETTER("labordispatch_mug.modify.summary");
		//info->queryParams.add<String>("corporateName").description = ZH_WORDS_GETTER("ldcompany.field.PIMLABOURCAMPANYNAME");
		info->queryParams.add<String>("PIMLABOURCAMPANYNAME").description = ZH_WORDS_GETTER("ldcompany.field.PIMLABOURCAMPANYNAME");
		info->queryParams["corporateName"].required = true;
		info->queryParams.add<String>("contactAddress").description = ZH_WORDS_GETTER("ldcompany.field.LXDZ");
		info->queryParams["contactAddress"].required = false;
		info->queryParams.add<String>("contactNumber").description = ZH_WORDS_GETTER("ldcompany.field.LXFS");
		info->queryParams["contactNumber"].required = false;
		info->queryParams.add<String>("contactPerson").description = ZH_WORDS_GETTER("ldcompany.field.LXR");
		info->queryParams["contactPerson"].required = false;
		info->queryParams.add<String>("legalPerson").description = ZH_WORDS_GETTER("ldcompany.field.LEGALPERSON");
		info->queryParams["legalPerson"].required = false;
		info->queryParams.add<String>("registeredPrincipal").description = ZH_WORDS_GETTER("ldcompany.field.REGCAPITAL");
		info->queryParams["registeredPrincipal"].required = false;
		info->queryParams.add<String>("corporateIntroduction").description = ZH_WORDS_GETTER("ldcompany.field.GSJJ");
		info->queryParams["corporateIntroduction"].required = false;
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}

	ENDPOINT(API_M_PUT, "/contract-management/modify-labor-dispatch-corporate", modifyLaborDispatch, BODY_DTO(LaborDispatchDTO::Wrapper, dto)) {
		API_HANDLER_RESP_VO(execModifyLaborDispatch(dto));
	}
private:
	LaborDispatchJsonMVO::Wrapper execQueryLaborDispatch(const LaborDispatchMQuery::Wrapper& query);


	StringJsonVO::Wrapper execModifyLaborDispatch(const LaborDispatchDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_LD_M_CONTROLLER_
