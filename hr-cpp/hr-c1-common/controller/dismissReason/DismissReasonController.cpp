
#include "stdafx.h"
#include "DismissReasonController.h"
#include "uselib/pullListRedis/UseLibRedis.h"

PullListVO::Wrapper DismissReasonController::execQueryDismissReason()
{
	// ���巵�����ݶ���
	auto jvo = PullListVO::createShared();
	auto dto = PullListDTO::createShared();
	std::string tableName = "dismiss-reason-pull-list";
	std::unordered_map<std::string, std::string> dismissReasonList;
	UseLibRedis redisExm;
	std::unordered_map<std::string, std::string> redisResult = redisExm.queryRedis(tableName);
	if (redisResult.empty()) { // ����Ϊ��
		// ����һ��Service
		DismissReasonService service;
		// ִ�в�ѯ
		dto = service.listAll();
		// ���뻺��
		for (auto subptr = dto->pullList->begin(); subptr != dto->pullList->end(); subptr++) {
			dismissReasonList.insert(std::make_pair(std::to_string(*subptr->get()->key), *subptr->get()->val));
		}
		redisExm.updateRedisWithTable(dismissReasonList, tableName);
	}
	else // ����������
	{
		dismissReasonList = redisExm.queryRedis(tableName);
		for (auto sub : dismissReasonList) {
			dto->pullList->push_back(ItemDTO::createShared(std::stoi(sub.first), sub.second));
		}
	}

	// �����ɹ���Ϣ
	jvo->success(dto);
	return jvo;
}
