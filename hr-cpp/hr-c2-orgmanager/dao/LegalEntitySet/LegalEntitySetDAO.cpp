#include "stdafx.h"
#include "LegalEntitySetDAO.h"
#include "LegalEntitySetMapper.h"
#include <sstream>

/* ������������DAO����--����֯����-��������-�����������ã�--TripleGold */
//�������������꣬�����ظ�����
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql <<" WHERE 1=1"; \
if (query->ORGNAME) { \
	sql << " AND `ORGNAME`= ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ORGNAME.getValue("")); \
} \
if (query->ORMSIGNORGNAME) { \
	sql << " AND `ORMSIGNORGNAME`= ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ORMSIGNORGNAME.getValue("")); \
} \

uint64_t LegalEntitySetDAO::count(const LegalEntitySetQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_contractsignorg tcs"
		<< " JOIN t_srforg tsf ON tcs.SIGNORGID = tsf.COMPANYFLAG"
		<< " JOIN t_ormsignorg tos ON tcs.ORMSIGNORGID = tos.ORMSIGNORGID";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<QueryLegalEntitySetDO> LegalEntitySetDAO::selectWithPage(const LegalEntitySetQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT tcs.CONTRACTSIGNORGID, tsf.ORGNAME, tos.ORMSIGNORGNAME, tcs.ISDEFAULTSIGNORG"
		<< " FROM t_contractsignorg tcs"
		<< " JOIN t_srforg tsf ON tcs.SIGNORGID = tsf.COMPANYFLAG"
		<< " JOIN t_ormsignorg tos ON tcs.ORMSIGNORGID = tos.ORMSIGNORGID";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	LegalEntitySetMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<QueryLegalEntitySetDO, LegalEntitySetMapper>(sqlStr, mapper, params);
}
