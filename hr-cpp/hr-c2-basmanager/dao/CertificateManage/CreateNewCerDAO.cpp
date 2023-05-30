/*
֤�����-�½�֤��--pine
*/
#include "stdafx.h"
#include "CreateNewCerDAO.h"
#include "CreateNewCerMapper.h"
#include <sstream>


uint64_t CreateNewCerDAO::insert(const CertificateDO& iObj)
{
	string sql = "INSERT INTO `t_pimvocational` (`PIMVOCATIONALID`, `ygbh`, `pimVocationalName`) VALUES (?, ?, ?);";
	return sqlSession->executeInsert(sql, "%s%i%s", iObj.getPimvocationalid(), iObj.getYgbh(), iObj.getPimVocationalName());
}
