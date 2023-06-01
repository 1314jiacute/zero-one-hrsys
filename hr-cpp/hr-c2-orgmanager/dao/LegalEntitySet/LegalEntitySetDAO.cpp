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
if (query->contractsignorgname) { \
	sql << " AND `CONTRACTSIGNORGNAME`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->contractsignorgname.getValue("")); \
} \
if (query->ormorgid) { \
	sql << " AND ORMORGID=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ormorgid.getValue("")); \
} \
if (query->isdefaultsignorg) { \
	sql << " AND ISDEFAULTSIGNORG=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->isdefaultsignorg.getValue("")); \
}

//std::list<LegalEntitySetDO> LegalEntitySetDAO::legalerNamePullDownList() {
//	string sql = "SELECT `ormsignorgname` FROM `t_ormsignorg`";
//	LegalEntitySetPullDownListMapper mapper;
//	return sqlSession->executeQuery<LegalEntitySetDO, LegalEntitySetPullDownListMapper>(sql, mapper);
//}

//uint64_t LegalEntitySetDAO::insert1(const LegalEntitySetDO& iObj) {
//	string sql = "INSERT IGNORE INTO `t_ormsignorg` (`ORMSIGNORGNAME`, ) VALUES (?)";
//	return sqlSession->executeInsert(sql, "%s", iObj.getORMSIGNORGNAME());
//}
//
//uint64_t LegalEntitySetDAO::insert2(const LegalEntitySetDO& iObj) {
//	string sql = "INSERT INTO `t_contractsignorg` ( `CONTRACTSIGNORGNAME`, `ISDEFAULTSIGNORG`) VALUES ( ?,?)";
//	return sqlSession->executeInsert(sql, "%s%i",iObj.getCONTRACTSIGNORGNAME(),iObj.getISDEFAULTSIGNORG());
//}
//
//int LegalEntitySetDAO::update1(const LegalEntitySetDO& uObj) {
//	string sql = "UPDATE t_ormsignorg SET  ORMSIGNORGNAME=? WHERE ORMSIGNORGID=?";
//	return sqlSession->executeUpdate(sql, "%s%s", uObj.getORMSIGNORGNAME(), uObj.getORMSIGNORGID());
//}
//
//int LegalEntitySetDAO::update2(const LegalEntitySetDO& uObj) {
//	string sql = "UPDATE t_contractsignorg SET CONTRACTSIGNORGNAME=?, ISDEFAULTSIGNORG=? WHERE CONTRACTSIGNORGID=?";
//	return sqlSession->executeUpdate(sql, "%s%s%s", uObj.getCONTRACTSIGNORGNAME(), uObj.getISDEFAULTSIGNORG(), uObj.getCONTRACTSIGNORGID());
//}


/* -------------------------------------------�����������ò�ѯ����--TripleGold ----------------------------------------------------------*/
uint64_t LegalEntitySetDAO::count(const LegalEntitySetQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_contractsignorg";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<LegalEntitySetDO> LegalEntitySetDAO::selectWithPage(const LegalEntitySetQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT ORMSIGNORGID, ORMORGID, SIGNORGID, ISDEFAULTSIGNORG FROM t_contractsignorg";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	LegalEntitySetMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<LegalEntitySetDO, LegalEntitySetMapper>(sqlStr, mapper, params);
}
