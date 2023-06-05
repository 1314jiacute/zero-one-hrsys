#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ahao
 @Date: 2023/5/22 14:58:43

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
#ifndef _ASSIGN_CONTROLLER_
#define _ASSiGN_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/assignInfo/AssignInfoDTO.h"
#include "domain/vo/assignInfo/AssignInfoVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "domain/query/assignInfo/AssignInfoQuery.h"
#include "domain/query/PageQuery.h"
#include "domain/query/assignInfo/AssignInfoQueryDetail.h"
#include "domain/query/assignInfo/AssignExportQuery.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

/*
	判断string是否为自然数
*/

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 控制器，供员工分配信息使用
 */
class AssignInfoController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(AssignInfoController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(assignQuery) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("employee.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AssignInfoPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		info->queryParams.add<String>("assignId").description = ZH_WORDS_GETTER("employee.t_pimperson.assignId");
		info->queryParams["assignId"].addExample("default", String(""));
		info->queryParams["assignId"].required = false;
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("employee.t_pimperson.id");
		info->queryParams["id"].addExample("default", String("F943C793-520E-46FA-8F6F-5EF08AC1F770"));
		info->queryParams["id"].required = false;
		info->queryParams.add<String>("startTime").description = ZH_WORDS_GETTER("employee.t_pimperson.startTime");
		info->queryParams["startTime"].addExample("default", String(""));
		info->queryParams["startTime"].required = false;
		info->queryParams.add<String>("endTime").description = ZH_WORDS_GETTER("employee.t_pimperson.endTime");
		info->queryParams["endTime"].addExample("default", String(""));
		info->queryParams["endTime"].required = false;
	}
	ENDPOINT(API_M_GET, "/c3-assign-info/query", assignQuery, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, AssignInfoQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execAssignQuery(userQuery, authObject->getPayload()));
	}
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addAssignInfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("employee.post.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/c3-assign-info/add", addAssignInfo, API_HANDLER_AUTH_PARAME, BODY_DTO(AssignInfoDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddAssignInfo(dto,authObject->getPayload()));
	}
	// 3.1 定义删除接口描述
	ENDPOINT_INFO(deleteAssignInfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("employee.delete.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		//API_DEF_ADD_QUERY_PARAMS(String, "assignId", ZH_WORDS_GETTER("employee.t_pimperson.assignId"), "", true);
	}
	// 3.2 定义删除接口处理
	ENDPOINT(API_M_DEL, "/c3-assign-info/delete", deleteAssignInfo, API_HANDLER_AUTH_PARAME, BODY_DTO(AssignInfoDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execDeleteAssignInfo(dto));
	}
	// 3.1 定义修改接口描述
	ENDPOINT_INFO(modifyAssignInfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("employee.put.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义修改接口处理
	ENDPOINT(API_M_PUT, "/c3-assign-info/modify", modifyAssignInfo, API_HANDLER_AUTH_PARAME,BODY_DTO(AssignInfoDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyAssignInfo(dto,authObject->getPayload()));
	}
	// [其他] 定义一个单文件上传接口
	ENDPOINT_INFO(importAssignInfo) {
		info->summary = ZH_WORDS_GETTER("employee.post.upload");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/c3-assign-info/upload", importAssignInfo, API_HANDLER_AUTH_PARAME, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
			/* 创建multipart容器 */
			auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
			/* 创建multipart读取器 */
			multipart::Reader multipartReader(multipartContainer.get());
			/* 配置读取器读取表单字段 */
			multipartReader.setPartReader("assignId", multipart::createInMemoryPartReader(-1 /* max-data-size */));
			multipartReader.setPartReader("id", multipart::createInMemoryPartReader(-1 /* max-data-size */));
			multipartReader.setPartReader("assign", multipart::createInMemoryPartReader(-1 /* max-data-size */));
			multipartReader.setPartReader("assignState", multipart::createInMemoryPartReader(-1 /* max-data-size */));
			multipartReader.setPartReader("etype", multipart::createInMemoryPartReader(-1 /* max-data-size */));
			multipartReader.setPartReader("organize", multipart::createInMemoryPartReader(-1 /* max-data-size */));
			multipartReader.setPartReader("depart", multipart::createInMemoryPartReader(-1 /* max-data-size */));
			multipartReader.setPartReader("job", multipart::createInMemoryPartReader(-1 /* max-data-size */));
			multipartReader.setPartReader("post", multipart::createInMemoryPartReader(-1 /* max-data-size */));
			multipartReader.setPartReader("startTime", multipart::createInMemoryPartReader(-1 /* max-data-size */));
			multipartReader.setPartReader("endTime", multipart::createInMemoryPartReader(-1 /* max-data-size */));
			multipartReader.setPartReader("createMan", multipart::createInMemoryPartReader(-1 /* max-data-size */));
			multipartReader.setPartReader("createDate", multipart::createInMemoryPartReader(-1 /* max-data-size */));
			multipartReader.setPartReader("updateMan", multipart::createInMemoryPartReader(-1 /* max-data-size */));
			multipartReader.setPartReader("updateDate", multipart::createInMemoryPartReader(-1 /* max-data-size */));
			/* 配置读取器读取文件到文件 */
			multipartReader.setPartReader("file", multipart::createFilePartReader("public/static/file/test.png"));
			/* 读取请求体中的数据 */
			request->transferBody(&multipartReader);
			/* 打印part数量 */
			OATPP_LOGD("Multipart", "parts_count=%d", multipartContainer->count());
			/* 获取表单数据 */
			auto assignId = multipartContainer->getNamedPart("assignId");
			auto id = multipartContainer->getNamedPart("id");
			auto assign = multipartContainer->getNamedPart("assign");
			auto assignState = multipartContainer->getNamedPart("assignState");
			auto etype = multipartContainer->getNamedPart("etype");
			auto organize = multipartContainer->getNamedPart("organize");
			auto depart = multipartContainer->getNamedPart("depart");
			auto job = multipartContainer->getNamedPart("job");
			auto post = multipartContainer->getNamedPart("post");
			auto startTime = multipartContainer->getNamedPart("startTime");
			auto endTime = multipartContainer->getNamedPart("endTime");
			auto createMan = multipartContainer->getNamedPart("createMan");
			auto createDate = multipartContainer->getNamedPart("createDate");
			auto updateMan = multipartContainer->getNamedPart("updateMan");
			auto updateDate = multipartContainer->getNamedPart("updateDate");
			/* 断言表单数据是否正确 */
			OATPP_ASSERT_HTTP(assignId, Status::CODE_400, "assignId is null");
			OATPP_ASSERT_HTTP(id, Status::CODE_400, "id is null");
			OATPP_ASSERT_HTTP(assign, Status::CODE_400, "assign is null");
			OATPP_ASSERT_HTTP(assignState, Status::CODE_400, "assignState is null");
			OATPP_ASSERT_HTTP(etype, Status::CODE_400, "etype is null");
			OATPP_ASSERT_HTTP(organize, Status::CODE_400, "organize is null");
			OATPP_ASSERT_HTTP(depart, Status::CODE_400, "depart is null");
			OATPP_ASSERT_HTTP(job, Status::CODE_400, "job is null");
			OATPP_ASSERT_HTTP(post, Status::CODE_400, "post is null");
			OATPP_ASSERT_HTTP(startTime, Status::CODE_400, "startTime is null");
			OATPP_ASSERT_HTTP(endTime, Status::CODE_400, "endTime is null");
			OATPP_ASSERT_HTTP(createMan, Status::CODE_400, "createMan is null");
			OATPP_ASSERT_HTTP(createDate, Status::CODE_400, "createDate is null");
			OATPP_ASSERT_HTTP(updateMan, Status::CODE_400, "updateMan is null");
			OATPP_ASSERT_HTTP(updateDate, Status::CODE_400, "updateDate is null");
			/* 打印应表单数据 */
			OATPP_LOGD("Multipart", "assignId='%s'", assignId->getPayload()->getInMemoryData()->c_str());
			OATPP_LOGD("Multipart", "id='%s'", id->getPayload()->getInMemoryData()->c_str());
			OATPP_LOGD("Multipart", "assign='%s'", assign->getPayload()->getInMemoryData()->c_str());
			OATPP_LOGD("Multipart", "assignState='%s'", assignState->getPayload()->getInMemoryData()->c_str());
			OATPP_LOGD("Multipart", "etype='%s'", etype->getPayload()->getInMemoryData()->c_str());
			OATPP_LOGD("Multipart", "organize='%s'", organize->getPayload()->getInMemoryData()->c_str());
			OATPP_LOGD("Multipart", "depart='%s'", depart->getPayload()->getInMemoryData()->c_str());
			OATPP_LOGD("Multipart", "job='%s'", job->getPayload()->getInMemoryData()->c_str());
			OATPP_LOGD("Multipart", "post='%s'", post->getPayload()->getInMemoryData()->c_str());
			OATPP_LOGD("Multipart", "startTime='%s'", startTime->getPayload()->getInMemoryData()->c_str());
			OATPP_LOGD("Multipart", "endTime='%s'", endTime->getPayload()->getInMemoryData()->c_str());
			OATPP_LOGD("Multipart", "createMan='%s'", createMan->getPayload()->getInMemoryData()->c_str());
			OATPP_LOGD("Multipart", "createDate='%s'", createDate->getPayload()->getInMemoryData()->c_str());
			OATPP_LOGD("Multipart", "updateMan='%s'", updateMan->getPayload()->getInMemoryData()->c_str());
			OATPP_LOGD("Multipart", "updateDate='%s'", updateDate->getPayload()->getInMemoryData()->c_str());
			/* 获取文件部分 */
			auto filePart = multipartContainer->getNamedPart("file");
			/* 断言文件是否获取到 */
			OATPP_ASSERT_HTTP(filePart, Status::CODE_400, "file is null");
			/* 打印文件名称 */
			OATPP_LOGD("Multipart", "file='%s'", filePart->getFilename()->c_str());
			/* 响应OK */
			return createResponse(Status::CODE_200, "OK");
	}

	// 3.1 定义查询接口描述
	ENDPOINT_INFO(assignQueryDetail) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("employee.get.detail");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AssignInfoJsonVO);
		//详细查询分配信息不需要分页
		// 定义分页参数描述
		//API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		info->queryParams.add<String>("assignId").description = ZH_WORDS_GETTER("employee.t_pimperson.assignId");
		info->queryParams["assignId"].addExample("default", String("E3D4260E-D2D6-4884-A6BE-FF6547BDF229"));
		info->queryParams["assignId"].required = true;
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/c3-assign-info/query-detail", assignQueryDetail, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, AssignInfoQueryDetail, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execAssignQueryDetail(userQuery, authObject->getPayload()));
	}

	ENDPOINT_INFO(exportAssignInfo) {
		info->summary = ZH_WORDS_GETTER("export.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("employee.field.id");
		info->queryParams["id"].addExample("default", String("0000001"));
		info->queryParams["id"].required = true;
	}
	ENDPOINT(API_M_GET, "/export-assign-info", exportAssignInfo, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		API_HANDLER_QUERY_PARAM(query, AssignExportQuery, qps);
		API_HANDLER_RESP_VO(execExportAssign(query));
	}

private:
	// 3.3 演示新增数据
	StringJsonVO::Wrapper execAddAssignInfo(const AssignInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execDeleteAssignInfo(const AssignInfoDTO::Wrapper& dto);
	//ImportAssignInfoJsonVO::Wrapper execImportAssignInfo(const ImportAssignInfoDTO::Wrapper& dto);
	AssignInfoPageJsonVO::Wrapper execAssignQuery(const AssignInfoQuery::Wrapper& query, const PayloadDTO& payload);
	AssignInfoJsonVO::Wrapper execAssignQueryDetail(const AssignInfoQueryDetail::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execModifyAssignInfo(const AssignInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execExportAssign(const AssignExportQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _ASSIGN_CONTROLLER_