#include "stdafx.h"
#include "JobTitleInformationDAO.h"
#include "JobTitleInformationMapper.h"
#include <sstream>
//�������������꣬�����ظ�����
#define JOBTITLE_INFORMATION_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->professoranalysis_name) { \
	sql << " AND `PIMPERSONNAME`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->professoranalysis_name.getValue("")); \
}

uint64_t JobTitleInformationDAO::count(const JobTitleInformationPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `bis_professoranalysis_t`  ";
	JOBTITLE_INFORMATION_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<JobTitleInformationDO> JobTitleInformationDAO::selectWithPage(const JobTitleInformationPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT professoranalysis_name,credentials_num,professor_grades,major,zchqrq,reviewbody,lssuingagency,employtime,enable FROM `bis_professoranalysis_t`  ";
	JOBTITLE_INFORMATION_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	JobTitleInformationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<JobTitleInformationDO, JobTitleInformationMapper>(sqlStr, mapper, params);
}