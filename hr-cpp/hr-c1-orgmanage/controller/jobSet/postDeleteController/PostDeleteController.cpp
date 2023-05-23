/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/17 18:55:41

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
#include "PostDeleteController.h"
//#include "../../service/sample/SampleService.h"

Uint64JsonVO::Wrapper PostDeleteController::execDeleteByOrmPostId(const PostDeleteDTO::Wrapper& postDeleteDTO, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!postDeleteDTO->ormPostId)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	return jvo;
}

Uint64JsonVO::Wrapper PostDeleteController::exeDeleteBatchByOrmPostId(const PostDeleteBatchDTO::Wrapper& postDeleteBatchDTO, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!postDeleteBatchDTO->ormPostIds)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	return Uint64JsonVO::Wrapper();
}
