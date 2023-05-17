#include "stdafx.h"
#include "MilitaryService.h"
#include "../../dao/military/MilitaryDAO.h"

MilitaryDTO::Wrapper MilitaryService::listDetail(const MilitaryDetailQuery::Wrapper& query)
{
	// �������ض���
	//auto lists = MilitaryDTO::createShared();
	MilitaryDAO dao;
	auto lists = dao.selectDetail(query);
	auto dto = MilitaryDTO::createShared();
	if (!lists.empty()) {
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, lists.front(), UPDATEDATE, _UPDATEDATE, PIMARMYCADRESNAME, _PIMARMYCADRESNAME, FJ, _FJ, CREATEDATE, _CREATEDATE, UPDATEMAN, _UPDATEMAN, ENABLE, _ENABLE, PIMARMYCADRESID, _PIMARMYCADRESID, CREATEMAN, _CREATEMAN, PIMPERSONID, _PIMPERSONID, FSSJ, _FSSJ, JLSS, _JLSS, JLSPZT, _JLSPZT, JLGLBH, _JLGLBH, JLCZZ, _JLCZZ, TROOPTYPE, _TROOPTYPE, LEVELTYPE, _LEVELTYPE, REASON, _REASON);
	}
	return dto;
}

bool MilitaryService::updateData(const MilitaryDTO::Wrapper& dto)
{
	// ��װDO����
	MilitaryDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, _UPDATEDATE, UPDATEDATE, _PIMARMYCADRESNAME, PIMARMYCADRESNAME, _FJ, FJ, _CREATEDATE, CREATEDATE, _UPDATEMAN, UPDATEMAN, _ENABLE, ENABLE, _PIMARMYCADRESID, PIMARMYCADRESID, _CREATEMAN, CREATEMAN, _PIMPERSONID, PIMPERSONID, _FSSJ, FSSJ, _JLSS, JLSS, _JLSPZT, JLSPZT, _JLGLBH, JLGLBH, _JLCZZ, JLCZZ, _TROOPTYPE, TROOPTYPE, _LEVELTYPE, LEVELTYPE, _REASON, REASON);
	// ִ�������޸�
	MilitaryDAO dao;
	return dao.update(data) == 1;
}