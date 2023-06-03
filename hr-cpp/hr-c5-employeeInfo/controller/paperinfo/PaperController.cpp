#include "stdafx.h"
#include "PaperController.h"
#include "../../service/paperinfo/PaperService.h"

//�鿴ָ��Ա��������Ϣ��ָ��������Ϣ���飩
PaperinfoJsonVO::Wrapper PaperController::execSelectByPimpaperid(const String& str)
{
	// ����һ��Service
	PaperService service;
	// ��ѯ����
	auto result = service.listAll(str);
	//������Ӧ����
	auto vo = PaperinfoJsonVO::createShared();
	vo->success(result);
	return vo;
}

////�޸�ָ��Ա��������Ϣ�������޸ģ�
Uint64JsonVO::Wrapper PaperController::execModifyByPimpaperid(const ModifyPaperinfoDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->pimpaperid)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	 //����һ��Service
	PaperService service;
	 //ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success({});
	}
	else
	{
		jvo->fail({});
	}
	//jvo->success(dto->pimpatentid);
	return jvo;
}

