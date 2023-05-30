/*
��Ա������-��������Ա-��ҳ��ѯԱ���б�--pine
*/
#include "stdafx.h"
#include "CheckRetiresListDAO.h"
#include "CheckRetiresListMapper.h"
#include <sstream>

//�������������꣬�����ظ�����
#define CERLIST_TERAM_PARSE(query, sql) \
SqlParams params; \
sql << " WHERE 1=1"; \
if (query->ygbh) { \
    sql << " AND CAST(ygbh AS CHAR) LIKE CONCAT('%', ?, '%')"; \
    SQLPARAMS_PUSH(params, "i", uint64_t, query->ygbh.getValue(0)); \
} \
if (query->pimpersonname) { \
    sql << " AND pimpersonname = ?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->pimpersonname.getValue("")); \
}
//֧��ģ����ѯ
uint64_t CheckRetiresListDAO::count(const CheckRetiresListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimperson ";

	CERLIST_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<RetiredEmployeesDO> CheckRetiresListDAO::selectWithPage(const CheckRetiresListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT ygbh, pimpersonname FROM t_pimperson ";

	CERLIST_TERAM_PARSE(query, sql);

	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;

	CheckRetiresListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<RetiredEmployeesDO, CheckRetiresListMapper>(sqlStr, mapper, params);
}

std::list<RetiredEmployeesDO> CheckRetiresListDAO::selectByYgbh(const string& ygbh)
{
	string sql = "SELECT * FROM t_pimperson WHERE `ygbh` LIKE CONCAT('%',?,'%')";
	CheckRetiresListMapper mapper;
	return sqlSession->executeQuery<RetiredEmployeesDO, CheckRetiresListMapper>(sql, mapper, "%s", ygbh);
}
