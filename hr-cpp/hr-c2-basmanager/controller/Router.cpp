/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/03 14:58:34

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
#include "Router.h"
#include "ApiHelper.h"
#include "RosterOfPer/FormerEmployeesController.h"
#include "CertificateManage/UpdateCertificateController.h"
//pine
#include "controller/CertificateManage/CheckCerListController.h"
#include "controller/CertificateManage/CreateNewCerController.h"
#include "controller/RosterOfPer/CheckRetiresListController.h"
#include "controller/RosterOfPer/ExportRetireesController.h"

#include "RosterOfPer/EmployeePageController.h"
#include "CertificateManage/CertifDeleteController.h"
#include "CertificateManage/ExportCertifController.h"
#include "RosterOfPer/ExportEmployeeController.h"
#include "controller/RosterOfPer/RraineeController.h"

//����controller����ͷ�ļ�
#include "controller/RosterOfPer/TemporaryStaffController.h"
#include "controller/CertificateManage/EmployeeInfoController.h"
#include "controller/CertificateManage/CertificateTypeController.h"

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
	ROUTER_SIMPLE_BIND(FormerEmployeesController);
	ROUTER_SIMPLE_BIND(UpdateCertificateController);	
	ROUTER_SIMPLE_BIND(RraineeController);  // ��ϰԱ�� swaggerЧ������
	ROUTER_SIMPLE_BIND(TempStaffController);//��ְ��ԱswaggerЧ������
	ROUTER_SIMPLE_BIND(EmployeeInfoController);//��Ա��Ϣ��ѯswaggerЧ������
	ROUTER_SIMPLE_BIND(CertificateTypeController); //֤�����Ͳ�ѯswaggerЧ������
	ROUTER_SIMPLE_BIND(CheckCerListController);
	ROUTER_SIMPLE_BIND(CreateNewCerController);
	ROUTER_SIMPLE_BIND(CheckRetiresListController);
	ROUTER_SIMPLE_BIND(ExportRetireesController);
	ROUTER_SIMPLE_BIND(EmployeePageController); //����Ա������ - ��Ա������ - ��ҳ��ѯԱ�����ݣ�--����
	ROUTER_SIMPLE_BIND(CertifDeleteController); //��֤����� - ֤����Ϣ - ɾ��֤�飩--����
	ROUTER_SIMPLE_BIND(ExportCertifController); //��֤����� - ֤����Ϣ - ����֤�飩--����
	ROUTER_SIMPLE_BIND(ExportEmployeeController);//����Ա������ - ��Ա������ - ����Ա����������ҳ��ǰ����ɣ���--����
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

