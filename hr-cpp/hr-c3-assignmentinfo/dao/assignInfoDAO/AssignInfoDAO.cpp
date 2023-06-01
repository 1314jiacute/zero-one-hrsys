/*
 Copyright Zero One Star. All rights reserved.

 @Author: ahao
 @Date: 2023/5/26 14:26:52

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "AssignInfoDAO.h"
#include "AssignInfoMapper.h"
#include <sstream>

//�������������꣬�����ظ�����
#define ASSIGNINFO_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->assignId) { \
	sql << " AND PIMDISTIRBUTIONID=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->assignId.getValue("")); \
} \
if (query->id) { \
	sql << " AND PIMPERSONID=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \
if (query->assign) { \
	sql << " AND FPLX=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->assign.getValue("")); \
} \
if (query->assignState) { \
	sql << " AND FPZT=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->assignState.getValue("")); \
} \
if (query->etype) { \
	sql << " AND CFPLX=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->etype.getValue("")); \
} \
if (query->organize) { \
	sql << " AND ORMORGNAME=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->organize.getValue("")); \
}\
if (query->depart) { \
	sql << " AND ORMORGSECTORNAME=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->depart.getValue("")); \
}\
if (query->job) { \
	sql << " AND ORMDUTYNAME=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->job.getValue("")); \
}\
if (query->post) { \
	sql << " AND ORMPOSTNAME=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->post.getValue("")); \
}\
if (query->startTime) { \
	sql << " AND RZKSSJ=?"; \
	SQLPARAMS_PUSH(params, "s",std::string , query->startTime.getValue("")); \
}\
if (query->endTime) { \
	sql << " AND RZJSSJ=?"; \
	SQLPARAMS_PUSH(params, "s",std::string , query->endTime.getValue("")); \
}

uint64_t AssignInfoDAO::count(const AssignInfoQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimdistirbution";
	ASSIGNINFO_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<AssignInfoDO> AssignInfoDAO::selectWithPage(const AssignInfoQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM t_pimdistirbution";
	ASSIGNINFO_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	AssignInfoMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<AssignInfoDO, AssignInfoMapper>(sqlStr, mapper, params);
}

std::list<AssignInfoDO> AssignInfoDAO::selectById(const string& id)
{
	string sql = "SELECT * FROM t_pimdistirbution WHERE PIMPERSONID LIKE CONCAT('%',?,'%')";
	AssignInfoMapper mapper;
	return sqlSession->executeQuery<AssignInfoDO, AssignInfoMapper>(sql, mapper, "%s", id);
}

uint64_t AssignInfoDAO::insert(const AssignInfoDO& iObj)
{
	string sql = "INSERT INTO t_pimdistirbution (PIMDISTIRBUTIONID,PIMPERSONID,FPLX,FPZT,CFPLX,ORMORGNAME,ORMORGSECTORNAME,ORMDUTYNAME,ORMPOSTNAME,RZKSSJ,RZJSSJ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s",iObj.getAssignId(), iObj.getId(), iObj.getAssign(),iObj.getAssignState() ,iObj.getEtype(),iObj.getOrganize(),iObj.getDepart(),iObj.getJob(),iObj.getPost(),iObj.getStartTime(),iObj.getEndTime());
}

int AssignInfoDAO::update(const AssignInfoDO& uObj)
{
	string sql = "UPDATE t_pimdistirbution SET PIMDISTIRBUTIONID=?,FPLX=?,FPZT=?, CFPLX=?, ORMORGNAME=?,ORMORGSECTORNAME=?,ORMDUTYNAME=?,ORMPOSTNAME=?,RZKSSJ=?,RZJSSJ=? WHERE PIMPERSONID=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s", uObj.getAssignId(),uObj.getAssign(), uObj.getAssignState(),uObj.getEtype(), uObj.getOrganize(), uObj.getDepart(), uObj.getJob(), uObj.getPost(), uObj.getStartTime(), uObj.getEndTime(),uObj.getId());
}

int AssignInfoDAO::deleteById(string assignId)
{
	string sql = "DELETE FROM t_pimdistirbution WHERE PIMDISTIRBUTIONID=?";
	return sqlSession->executeUpdate(sql, "%s", assignId);
}