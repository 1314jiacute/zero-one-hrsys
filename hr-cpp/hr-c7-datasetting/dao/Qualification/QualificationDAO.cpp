#include "stdafx.h"
#include "QualificationDAO.h"
#include "QualificationMapper.h"
#include <sstream>

//�������������꣬�����ظ�����
#define QUALIFICATION_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->pimqualmajorid) { \
	sql << " AND `pimqualmajorid`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pimqualmajorid.getValue("")); \
} \
if (query->qualevel) { \
	sql << " AND `qualevel`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->qualevel.getValue("")); \
} \
if (query->pimqualmajorname) { \
	sql << " AND pimqualmajorname=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pimqualmajorname.getValue("")); \
} \
if (query->quamajor) { \
	sql << " AND quamajor=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->quamajor.getValue("")); \
}\

uint64_t QualificationDAO::count(const QualificationQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM Qualification";
	QUALIFICATION_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<QualificationDO> QualificationDAO::selectWithPage(const QualificationQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM Qualification";
	QUALIFICATION_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	QualificationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<QualificationDO, QualificationMapper>(sqlStr, mapper, params);
}

std::list<QualificationDO> QualificationDAO::selectByName(const string& name)
{
	string sql = "SELECT * FROM Qualification WHERE `pimqualmajorname` LIKE CONCAT('%',?,'%')";
	QualificationMapper mapper;
	return sqlSession->executeQuery<QualificationDO, QualificationMapper>(sql, mapper, "%s", name);
}

uint64_t QualificationDAO::insert(const QualificationDO& iObj)
{
	string sql = "INSERT INTO `Qualification` (`pimqualmajorid`, `qualevel`, `pimqualmajorname`, `quamajor`) VALUES (?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s", iObj.getpimQualMajorId(), iObj.getquaMajor(), iObj.getpimQualMajorName(), iObj.getquaMajor());
}

int QualificationDAO::update(const QualificationDO& uObj)
{
	string sql = "UPDATE `Qualification` SET `qualevel`=?, `pimqualmajorname`=? ,`quamajor`=? WHERE `pimqualmajorid`= ? ";
	return sqlSession->executeUpdate(sql, "%s%s%s", uObj.getquaMajor(), uObj.getpimQualMajorName(), uObj.getquaMajor(), uObj.getpimQualMajorId());
}

int QualificationDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `Qualification` WHERE `pimqualmajorid`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}