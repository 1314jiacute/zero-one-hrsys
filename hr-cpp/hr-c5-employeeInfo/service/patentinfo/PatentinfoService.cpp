#include "stdafx.h"
#include "PatentinfoService.h"
#include "../../dao/patentinfo/PatentinfoDAO.h"

//��ѯ��������
PatentinfoDTO::Wrapper PatentinfoService::listAll(const string& pimpatentid)
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
			reason, REASON)
	}
	return dto;
}


// �޸�����
bool PatentinfoService::updateData(const PatentinfoDTO::Wrapper& dto)
{
	// ��װDO����
	PatentinfoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ZLH, zlh, PIMPATENTNAME, pimpatentname, ZLHQSJ, zlhqsj, ZLPZGB, zlpzgb, ENCLOLURE, enclolure, PIMPATENTID, pimpatentid)
		// ִ�������޸�
		PatentinfoDAO dao;
	return dao.update(data) == 1;
}


