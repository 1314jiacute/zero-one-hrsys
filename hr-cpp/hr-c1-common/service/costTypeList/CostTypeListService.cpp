#include "stdafx.h"
#include "Macros.h"
#include "CostTypeListService.h"
#include "uselib/pullListRedis/UseLibRedis.h"
#include "dao/costTypeList/CostTypeListDAO.h"

PullListDTO::Wrapper CostTypeListService::listAll()
{
	// �������ض���
	auto res = PullListDTO::createShared();

	// TODO: ��ѯ����
	// �ӻ����л�ȡ��������б�
	auto hash = UseLibRedis::queryRedis("cost-type");

	auto dto = PullListDTO::createShared();
	// ���Ϊ�������dao��ѯ���ݿ�
	if (hash.empty())
	{
		// TODO: ����dao��ѯ���ݿ�
		CostTypeListDAO dao;
		auto res = dao.listAll();

		// ��װ��DTO����
		for (auto item : res)
		{
			string code = item.getCode();
			dto->pullList->push_back(ItemDTO::createShared(atoi(code.c_str()), item.getCostType()));
		}

		if (res.size())
			// TODO: ����ȡ�����ݸ��µ�Redis����
			UseLibRedis::updateRedis("cost-type", dao.getMapList());
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
