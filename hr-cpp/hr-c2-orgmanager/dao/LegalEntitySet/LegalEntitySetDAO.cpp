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
	sql << " AND `ORMSIGNORGNAME`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ormsignorgname.getValue("")); \
} \
if (query->contractsignorgname) { \
	sql << " AND CONTRACTSIGNORGNAME=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->contractsignorgname.getValue("")); \
} \
if (query->isdefaultsignorg) { \
	sql << " AND ISDEFAULTSIGNORG=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->isdefaultsignorg.getValue("")); \
}

uint64_t LegalEntitySetDAO::legalerNamePullDownList(const LegalEntitySetQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT ormsignorgname"
		<< " FROM t_contractsignorg"
		<< " INNER JOIN t_ormsignorg ON t_contractsignorg.ORMSIGNORGID = t_ormsignorg.ORMSIGNORGID";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}



uint64_t LegalEntitySetDAO::insert(const LegalEntitySetDO& iObj)
{
	string sql = "INSERT INTO `t_contractsignorg` (`t_contractsignorg.ORMSIGNORGID`, `t_contractsignorg.CONTRACTSIGNORGNAME`, `t_ormsignorg.ORMSIGNORGNAME`, `t_contractsignorg.ISDEFAULTSIGNORG`) VALUES (?, ?, ?, ?) SELECT t_contractsignorg.ORMSIGNORGID, t_contractsignorg.CONTRACTSIGNORGNAME, t_ormsignorg.ORMSIGNORGNAME, t_contractsignorg.ISDEFAULTSIGNORG FROM t_contractsignorg INNER JOIN t_ormsignorg ON t_contractsignorg.ORMSIGNORGID = t_ormsignorg.ORMSIGNORGID";
	return sqlSession->executeInsert(sql, "%s%s%s%s",iObj.getORMSIGNORGID(), iObj.getORMSIGNORGNAME(), iObj.getCONTRACTSIGNORGNAME(), iObj.getISDEFAULTSIGNORG());
}

int LegalEntitySetDAO::update(const LegalEntitySetDO& uObj)
{
	string sql = "UPDATE `t_contractsignorg` SET `ORMSIGNORGNAME`=?, `CONTRACTSIGNORGNAME`=?, `ISDEFAULTSIGNORG`=? WHERE `getORMSIGNORGID`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s", uObj.getORMSIGNORGNAME(), uObj.getCONTRACTSIGNORGNAME(), uObj.getISDEFAULTSIGNORG(), uObj.getORMSIGNORGID());
}


/* -------------------------------------------�����������ò�ѯ����--TripleGold ----------------------------------------------------------*/
uint64_t LegalEntitySetDAO::count(const LegalEntitySetQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*)"
		<< " FROM t_contractsignorg"
		<< " INNER JOIN t_ormsignorg ON t_contractsignorg.ORMSIGNORGID = t_ormsignorg.ORMSIGNORGID";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<LegalEntitySetDO> LegalEntitySetDAO::selectWithPage(const LegalEntitySetQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT t_contractsignorg.ORMSIGNORGID, t_contractsignorg.CONTRACTSIGNORGNAME, t_ormsignorg.ORMSIGNORGNAME, t_contractsignorg.ISDEFAULTSIGNORG"
		<< " FROM t_contractsignorg "
		<< " INNER JOIN t_ormsignorg ON t_contractsignorg.ORMSIGNORGID = t_ormsignorg.ORMSIGNORGID";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	LegalEntitySetMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<LegalEntitySetDO, LegalEntitySetMapper>(sqlStr, mapper, params);
}
