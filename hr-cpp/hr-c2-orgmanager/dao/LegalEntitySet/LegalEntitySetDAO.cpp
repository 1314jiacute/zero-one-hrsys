#include "stdafx.h"
#include "LegalEntitySetDAO.h"
#include "LegalEntitySetMapper.h"
#include <sstream>
/*
��֯���� ������������ ���� ������������  -- cpt

�����������������б� `LegalEntitySetPullDownList`

����ָ������������Ϣ  `UpdateLegalerSettingMessage`

������������ `LegalEntitySet`

�����������ã�֧������������** `LegalEntitySet`
*/ 

//�������������꣬�����ظ�����
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->ormsignorgname) { \
	sql << " AND `ormsignorgname`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ormsignorgname.getValue("")); \
} \
if (query->contractsignorgname) { \
	sql << " AND contractsignorgname=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->contractsignorgname.getValue("")); \
} \
if (query->isdefaultsignorg) { \
	sql << " AND isdefaultsignorg=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->isdefaultsignorg.getValue(0)); \
}

std::list<LegalEntitySetDO> LegalEntitySetDAO::legalerNamePullDownList(const string& name)
{
	string sql = "SELECT * FROM sample WHERE `name` LIKE CONCAT('%',?,'%')";
	LegalEntitySetMapper mapper;
	return sqlSession->executeQuery<LegalEntitySetDO, LegalEntitySetMapper>(sql, mapper, "%s", name);
}

uint64_t LegalEntitySetDAO::insert(const LegalEntitySetDO& iObj)
{
	string sql = "INSERT INTO `t_contractsignorg` (`ORMSIGNORGID`, /*`ORMSIGNORGNAME`,*/ `CONTRACTSIGNORGNAME`, `ISDEFAULTSIGNORG`) VALUES (?, ��, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%i",iObj.getORMSIGNORGID(), /*iObj.getORMSIGNORGNAME(),*/ iObj.getCONTRACTSIGNORGNAME(), iObj.getISDEFAULTSIGNORG());
}

int LegalEntitySetDAO::update(const LegalEntitySetDO& uObj)
{
	string sql = "UPDATE `t_contractsignorg` SET `ORMSIGNORGNAME`=?, `CONTRACTSIGNORGNAME`=?, `ISDEFAULTSIGNORG`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%i%s", uObj.getORMSIGNORGNAME(), uObj.getCONTRACTSIGNORGNAME(), uObj.getISDEFAULTSIGNORG(), uObj.getORMSIGNORGID());
}
