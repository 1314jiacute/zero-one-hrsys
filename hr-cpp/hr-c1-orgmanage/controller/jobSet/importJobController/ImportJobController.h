﻿#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/16 18:28:33

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
#ifndef _IMPORTJOBCONTROLLER_H_
#define _IMPORTJOBCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "SimpleDateTimeFormat.h"
#include "ServerInfo.h"
#include "Macros.h"

// 文件上传
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "domain/dto/jobSet/ImportJobDTO.h"
#include "CharsetConvertHepler.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 岗位设置 - 导入岗位
 * 负责人：Andrew
 */
class ImportJobController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ImportJobController);
public: // 定义接口
	ENDPOINT_INFO(importJob) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("jobSet.import.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(NoDataJsonVO);
		// 定义分页参数描述
		info->queryParams.add<String>("fileType").description = ZH_WORDS_GETTER("jobSet.import.fileType");
		info->queryParams["fileType"].addExample("default", String("xlsx"));
		info->queryParams["fileType"].required = false;
		info->queryParams.add<String>("sheetName").description = ZH_WORDS_GETTER("jobSet.import.sheetName");
		info->queryParams["sheetName"].addExample("default", String("Sheet1"));
		info->queryParams["sheetName"].required = true;
		info->queryParams.add<String>("file").description = ZH_WORDS_GETTER("jobSet.import.file");
		info->queryParams["file"].required = true;
	}

	ENDPOINT(API_M_POST, "/import-job", importJob, /*API_HANDLER_AUTH_PARAME, */REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		/* 创建multipart容器 */
		auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
		/* 创建multipart读取器 */
		multipart::Reader multipartReader(multipartContainer.get());
		/* 配置读取器读取表单字段 */
		multipartReader.setPartReader("fileType", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("sheetName", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		/* 配置读取器读取文件到文件 */
		String filePath = "public/static/file/";
		filePath->append(SimpleDateTimeFormat::format("%Y-%m-%d_%H-%M-%S_"));
		filePath->append("JobSet.xlsx");
		multipartReader.setPartReader("file", multipart::createFilePartReader(filePath));

		/* 读取请求体中的数据 */
		request->transferBody(&multipartReader);
		if (multipartContainer->count() != 3)
		{
			/* 打印part数量 */
			OATPP_LOGD("Multipart", "parts_count=%d", multipartContainer->count());
			return createResponse(Status::CODE_400, "error in params");
		}

		/* 获取表单数据 */
		auto type = multipartContainer->getNamedPart("fileType");
		auto sheet = multipartContainer->getNamedPart("sheetName");
		/* 断言表单数据是否正确 */
		OATPP_ASSERT_HTTP(type, Status::CODE_400, "fileType is null");
		OATPP_ASSERT_HTTP(sheet, Status::CODE_400, "sheetName is null");

		string fileType = CharsetConvertHepler::utf8ToAnsi(type->getPayload()->getInMemoryData()->c_str());
		string sheetName = CharsetConvertHepler::utf8ToAnsi(sheet->getPayload()->getInMemoryData()->c_str());
		if (fileType != "csv" && fileType != "xls" && fileType != "xlsx" && sheetName != "")
		{
			return createResponse(Status::CODE_400, "error in params");
		}

		/* 获取文件部分 */
		auto filePart = multipartContainer->getNamedPart("file");
		/* 断言文件是否获取到 */
		OATPP_ASSERT_HTTP(filePart, Status::CODE_400, "file upload error");
		/* 打印文件名称 */
		OATPP_LOGD("Multipart", "file='%s'", filePart->getFilename()->c_str());

		auto dto = ImportJobDTO::createShared(String(fileType), String(sheetName), filePath);
		// 响应结果
		API_HANDLER_RESP_VO(execImportJob(dto/*, authObject->getPayload()*/));
	}
private: // 定义接口执行函数
	NoDataJsonVO::Wrapper execImportJob(const ImportJobDTO::Wrapper& dto/*, const PayloadDTO& payload*/);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_IMPORTJOBCONTROLLER_H_