#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xubuxi
 @Date: 2023/05/19 21:18:10

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
#ifndef _HTLX_CONTROLLER_
#define _HTLX_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/HTLX_pimcontracttype/HtlxDTO.h"
#include "domain/vo/HTLX_pimcontracttype/HtlxVO.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(ApiController)
/*
��ͬ��������б������
*/
class HtlxController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(HtlxController);
public: // ����ӿ�
	ENDPOINT_INFO(modifyHtlx) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("htlx.pull-list.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_PUT, "/htlx/pull-list", modifyHtlx, BODY_DTO(HtlxDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyHtlx(dto));
	}
	
private: // ����ӿ�ִ�к���
	Uint64JsonVO::Wrapper execModifyHtlx(const HtlxDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_HTLX_CONTROLLER_