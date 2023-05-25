
#include "stdafx.h"
#include "Router.h"
#include "ApiHelper.h"
#include "controller/CertificateManage/CheckCerListController.h"
#include "controller/CertificateManage/CreateNewCerController.h"
#include "controller/RosterOfPer/CheckRetiresListController.h"
#include "controller/RosterOfPer/ExportRetireesController.h"

#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
//#include "sample/SampleController.h"
#include "uselib/ws/WSController.h"
#endif

// ��������˹ر�Swagger�ĵ���
#ifdef CLOSE_SWAGGER_DOC
// �򻯰󶨿������궨��
#define ROUTER_SIMPLE_BIND(__CLASS__) \
router->addController(__CLASS__::createShared())
#else
// �򻯰󶨿������궨��
#define ROUTER_SIMPLE_BIND(__CLASS__) \
BIND_CONTROLLER(docEndpoints, router, __CLASS__)
#endif

Router::Router(Endpoints* docEndpoints, HttpRouter* router)
{
	this->docEndpoints = docEndpoints;
	this->router = router;
}

void Router::initRouter()
{
#ifdef HTTP_SERVER_DEMO
	createSampleRouter();
#endif

	//#TIP :ϵͳ��չ·�ɶ��壬д���������
	ROUTER_SIMPLE_BIND(CheckCerListController);//��ҳ��ѯ֤���б�--(֤�����-��ҳ��ѯ֤���б�)--pine
	ROUTER_SIMPLE_BIND(CreateNewCerController);//�½�֤��--(֤�����-�½�֤��)--pine
	ROUTER_SIMPLE_BIND(CheckRetiresListController);//��Ա������-��������Ա��-��ҳ��ѯԱ���б�--pine
	ROUTER_SIMPLE_BIND(ExportRetireesController); //��Ա������ - ��������Ա�� - ����Ա����--pine
}

#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	// ��ʾ��������
	ROUTER_SIMPLE_BIND(SampleController);
	// ���û�������
	ROUTER_SIMPLE_BIND(UserController);

	// ��WebSocket������
	router->addController(WSContorller::createShared());
}
#endif
