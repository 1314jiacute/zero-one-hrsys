#include "stdafx.h"
#include "Macros.h"
#include "JobLevelTypeListService.h"
#include "uselib/pullListRedis/UseLibRedis.h"
#include "dao/jobLevelTypeList/JobLevelTypeListDAO.h"

PullListDTO::Wrapper JobLevelTypeListService::listAll()
{
	// �������ض���
	auto res = PullListDTO::createShared();

	// TODO: ��ѯ����
	// �ӻ����л�ȡְ�Ƶȼ��б�
	auto hash = UseLibRedis::queryRedis("job-level-type");

	auto dto = PullListDTO::createShared();
	// ���Ϊ�������dao��ѯ���ݿ�
	if (hash.empty())
	{
		// TODO: ����dao��ѯ���ݿ�
		JobLevelTypeListDAO dao;
		auto res = dao.listAll();

		// ��װ��DTO����
		for (auto item : res)
		{
			string code = item.getCode();
			dto->pullList->push_back(ItemDTO::createShared(atoi(code.c_str()), item.getJobLevel()));
		}

		// TODO: ����ȡ�����ݸ��µ�Redis����
		UseLibRedis::updateRedis("job-level-type", dao.getMapList());
	}
	// ������װ�������ݵ�DTO
	else
	{
		for (auto item : hash)
		{
			int code = atoi(item.first.c_str());
			dto->pullList->push_back(ItemDTO::createShared(code, item.second));
		}
	}
	return dto;
}
