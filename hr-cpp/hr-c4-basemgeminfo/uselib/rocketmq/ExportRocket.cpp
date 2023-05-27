#include "stdafx.h"
#include "ExportRocket.h"
#include "service/work-history/WorkHistoryService.h"



void ExportRocket::init()
{
	this->client = nullptr;
	this->cb = nullptr;
}

ExportRocket::~ExportRocket()
{
	if (client)
	{
		client->unsubscribe();
	}
}

void ExportRocket::testRocket(const WorkHistoryExportQuery::Wrapper& query)
{
	// �����ͻ���
	client = make_shared<RocketClient>("192.168.80.129:9876");
	// ����������Ϣ�ص�
	cb = make_shared<RocketClient::RSendCallback>([](SendStatus staus)
		{
			std::cout << "RSendCallback send status: " << staus << endl;
		});

	// ���Կ�������
	client->subscribe("export");
	client->addListener(this);

	RC_PUBLISH_OBJ_MSG_ASYNC(client, "export", query, NULL);

}

std::string ExportRocket::receiveMessage(std::string payload)
{
	RC_RECEIVER_MSG_CONVERT(query, WorkHistoryExportQuery, payload);


	WorkHistoryService service;
	return service.exportData(query);
}
