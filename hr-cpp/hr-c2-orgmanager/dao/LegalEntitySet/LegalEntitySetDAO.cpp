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

uint64_t LegalEntitySetDAO::count(const LegalEntitySetQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM sample";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<LegalEntitySetDO> LegalEntitySetDAO::selectWithPage(const LegalEntitySetQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM sample";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	LegalEntitySetMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<LegalEntitySetDO, LegalEntitySetMapper>(sqlStr, mapper, params);
}

uint64_t LegalEntitySetDAO::insert(const LegalEntitySetDO& iObj)
{
	string sql = "INSERT INTO `sample` (`name`, `sex`, `age`) VALUES (?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%i", iObj.getORMSIGNORGNAME(), iObj.getCONTRACTSIGNORGNAME(), iObj.getISDEFAULTSIGNORG());
}

//int LegalEntitySetDAO::update(const LegalEntitySetDO& uObj)
//{
//	string sql = "UPDATE `sample` SET `name`=?, `sex`=?, `age`=? WHERE `id`=?";
//	return sqlSession->executeUpdate(sql, "%s%s%i%ull", uObj.getORMSIGNORGNAME(), uObj.getCONTRACTSIGNORGNAME(), uObj.getISDEFAULTSIGNORG(), uObj.getId());
//}
