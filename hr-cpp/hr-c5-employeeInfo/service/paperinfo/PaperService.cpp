
#include "stdafx.h"
#include "PaperService.h"
#include "../../dao/paperinfo/PaperinfoDAO.h"



// ��ѯָ��������Ϣ����
PaperinfoDTO::Wrapper PaperService::listAll(const string& st)
{
	// �������ض���
	PaperinfoDAO dao;
	//��ѯ����
	list<PaperinfoDO> result = dao.selectBypimpaperid(st);
	//��DOת����DTO
	auto dto = PaperinfoDTO::createShared();
	for (PaperinfoDO sub : result)
	{
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			grzlwzzzdpm, GRZLWZZZDPM,
			updateman, UPDATEMAN,
			pimpaperid, PIMPAPERID,
			createdate, CREATEDATE,
			updatedate, UPDATEDATE,
			createman, CREATEMAN,
			fbsj, FBSJ,
			pimpapername, PIMPAPERNAME,
			cbshkwmc, CBSHKWMC,
			pimpersonid, PIMPERSONID,
			fj, FJ,
			jlspzt, JLSPZT,
			jlglbh, JLGLBH,
			jlczz, JLCZZ,
			jlss, JLSS,
			cbs, CBS,
			kwmc, KWMC,
			kwqs, KWQS,
			reason, REASON )
	}
	return dto;
}

// �޸�����
bool PaperService::updateData(const PaperinfoDTO::Wrapper& dto)
{
	// ��װDO����
	PaperinfoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PIMPAPERNAME, pimpapername, CBS, cbs, KWMC, kwmc, KWQS, kwqs, FBSJ, fbsj, GRZLWZZZDPM, grzlwzzzdpm, FJ, fj, PIMPAPERID, pimpaperid)
		// ִ�������޸�
		PaperinfoDAO dao;
	return dao.update(data) == 1;
}


