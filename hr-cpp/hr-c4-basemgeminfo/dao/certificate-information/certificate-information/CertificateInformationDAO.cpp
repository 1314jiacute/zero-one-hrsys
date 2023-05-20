#include "stdafx.h"
#include "CertificateInformationDAO.h"
#include "CertificateInformationMapper.h"
#include <sstream>
//�������������꣬�����ظ�����
#define CERTIFACATE_INFORMATION_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->pimvocationalname) { \
	sql << " AND `PIMPERSONNAME`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pimvocationalname.getValue("")); \
}
//ͳ��֤��ļ�¼��
uint64_t CertificateInformationDAO::count(const CertificateInformationPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `t_pimvocational`  ";
	CERTIFACATE_INFORMATION_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
//֤���ҳ��ѯ����
list<CertificateInformationDO> CertificateInformationDAO::selectWithPage(const CertificateInformationPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT zgzsbh,pimvocationalname,zslx,zghqrq,zgsydw,fzyxq FROM `t_pimvocational`  ";
	CERTIFACATE_INFORMATION_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	CertificateInformationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<CertificateInformationDO, CertificateInformationMapper>(sqlStr, mapper, params);
}