/*
֤�����-��ҳ��ѯ֤���б�--pine
*/
#include "stdafx.h"
#include "CheckCerListDAO.h"
#include "CheckCerListMapper.h"
#include <sstream>

//�������������꣬�����ظ�����
#define CERLIST_TERAM_PARSE(query, sql) \
SqlParams params; \
sql << " WHERE 1=1"; \
if (query->nameOfPAndV) { \
    sql << " AND t2.pimperSonName=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->nameOfPAndV.getValue("")); \
} \
if (query->nameOfPAndV) { \
    sql << " OR t1.pimVocationalName=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->nameOfPAndV.getValue("")); \
} \
if (query->ygbh) { \
    sql << " AND t1.ygbh = ?"; \
    SQLPARAMS_PUSH(params, "i", uint64_t, query->ygbh.getValue(0)); \
} \
if (query->pimperSonName) { \
    sql << " AND t2.pimperSonName=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->pimperSonName.getValue("")); \
} \
if (query->pimVocationalName) { \
    sql << " AND t1.pimVocationalName=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->pimVocationalName.getValue("")); \
}

uint64_t CheckCerListDAO::count(const CheckCerListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) \
			FROM t_pimvocational t1\
			LEFT JOIN t_pimperson t2\
			ON t1.PIMPERSONID = t2.PIMPERSONID";
	CERLIST_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<CertificateDO> CheckCerListDAO::selectWithPage(const CheckCerListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT \
			t1.ygbh,\
			t2.pimperSonName,\
			t2.ygzt,\
			t2.zz,\
			t1.pimvocationalid,\
			t1.bcardNumber,\
			t1.pimVocationalName,\
			t1.zslx,\
			t1.zghqrq,\
			t1.zgsydw,\
			t1.zcdw,\
			t1.sxrq,\
			t1.fzyxq\
			FROM\
			t_pimvocational t1\
			LEFT JOIN t_pimperson t2 ON t1.PIMPERSONID = t2.PIMPERSONID";

	CERLIST_TERAM_PARSE(query, sql);

	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;

	ChechCerListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<CertificateDO, ChechCerListMapper>(sqlStr, mapper, params);
}

/*
֤��Ψһ��ʶ��PIMVOCATIONALID
֤����Ϣ��t_pimvocational t1
��Ա��Ϣ��t_pimperson t2

*/

