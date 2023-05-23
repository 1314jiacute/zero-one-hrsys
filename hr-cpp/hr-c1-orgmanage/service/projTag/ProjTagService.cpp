
#include "stdafx.h"
#include "ProjTagService.h"
#include "domain/do/projTag/ProjTagDO.h"
#include "dao/projTag/ProjTagDAO.h"
uint64_t ProjTagService::saveData(const ProjTagDTO::Wrapper& dto)
{
	// ��װDO����
	ProjTagDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, 
		Id, ormxmbqid,
		TagName, ormxmbqname,
		Creator, createman,
		CreateTime, createdate,
		Updater, updateman,
		UpdateTime, updatedate,
		OrgId, ormorgid
	);
	
	// ִ�в������
	ProjTagDAO dao;
	return dao.insert(data);

}
