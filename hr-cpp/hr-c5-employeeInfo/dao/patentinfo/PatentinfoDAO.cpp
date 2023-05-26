#include "stdafx.h"
#include "PatentinfoDAO.h"
#include "PatentinfoMapper.h"
#include <sstream>



// �鿴ָ��Ա��ר����Ϣ��ָ��ר����Ϣ���飩
std::list<PatentinfoDO> PatentinfoDAO::selectByPIMPATENTID(const PatentinfoQuery::Wrapper& query)
{


	//string sql = "SELECT * FROM t_pimpatent WHERE `PIMPATENTID` LIKE CONCAT('%',?,'%')";
	//PatentinfoMapper mapper;
	//return sqlSession->executeQuery<PatentinfoDO, PatentinfoMapper>(sql, mapper, "%s", PIMPATENTID);


	stringstream sql;
	sql << "SELECT * FROM t_pimpatent";
	SqlParams params;
	sql << " WHERE 1=1";
	sql << " AND `pimpatentid` LIKE CONCAT('%',?,'%')";
	SQLPARAMS_PUSH(params, "s", std::string, query->pimpatentid.getValue(""));
	PatentinfoMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PatentinfoDO, PatentinfoMapper>(sqlStr, mapper, params);



}


// �޸�����
//int PatentinfoDAO::update(const PatentinfoDO& uObj)
//{
//	string sql = "UPDATE `patentinfo` SET `name`=?, `sex`=?, `age`=? WHERE `PIMPATENTID`=?";
//	return sqlSession->executeUpdate(sql, "%s%s%i%ull", uObj.getName(), uObj.getSex(), uObj.getAge(), uObj.getId());
//}

