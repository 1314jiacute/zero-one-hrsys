#include "stdafx.h"
#include "J_PatentService.h"
#include "../../dao/J_patentinfo/J_PatentinfoDAO.h"

//��ѯ��������
PatentinfoDTO::Wrapper PatentService::listAll(const string& pimpatentid)
{
	// �������ض���
	PatentinfoDAO dao;
	// ��ѯ����
	list<PatentinfoDO> result = dao.selectByPIMPATENTID(pimpatentid);
	//��DOת����DTO
	auto dto = PatentinfoDTO::createShared();
	for (PatentinfoDO sub : result)
	{
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			zlh, ZLH,
			updatedate, UPDATEDATE,
			pimpatentid, PIMPATENTID,
			zlhqsj, ZLHQSJ,
			pimpatentname, PIMPATENTNAME,
			updateman, UPDATEMAN,
			createman, CREATEMAN,
			createdate, CREATEDATE,
			zlpzgb, ZLPZGB,
			pimpersonid, PIMPERSONID,
			jlss, JLSS,
			jlspzt, JLSPZT,
			jlglbh, JLGLBH,
			jlczz, JLCZZ,
			enclolure, ENCLOLURE,
			reason, REASON,

			orgid, ORGID,
			orgsectorid, ORGSECTORID,
			ormorgid, ORMORGID,
			ormorgsectorid, ORMORGSECTORID,
			pimpersonname, PIMPERSONNAME,
			ygbh, YGBH,

			enable,ENABLE
		)
	}
	return dto;
}


// �޸�����
bool PatentService::updateData(const ModifyPatentinfoDTO::Wrapper& dto)
{
	// ��װDO����
	PatentinfoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ZLH, zlh, PIMPATENTNAME, pimpatentname, ZLHQSJ, zlhqsj, ZLPZGB, zlpzgb, ENCLOLURE, enclolure, PIMPATENTID, pimpatentid,UPDATEDATE,updatedate, UPDATEMAN,updateman)
		// ִ�������޸�
		PatentinfoDAO dao;
	return dao.update(data) == 1;
}


