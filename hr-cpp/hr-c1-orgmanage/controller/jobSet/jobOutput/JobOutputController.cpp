#include "stdafx.h"
#include "JobOutputController.h"

StringJsonVO::Wrapper JobOutputController::execDownloadJobinfo(const PostDetailQuery::Wrapper& query) {
	auto vo = StringJsonVO::createShared();
	//������service
	vo->success("url/download");
	return vo;
}