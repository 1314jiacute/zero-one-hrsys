/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/05/25 22:04:02

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
#include "EmployeeInformationDAO.h"
#include "EmployeeInformationMapper.h"
#include <sstream>


//�������������꣬�����ظ�����
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->id) { \
	sql << " AND `id`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \
if (query->age) { \
	sql << " AND age=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
}

// ͳ����������
uint64_t EmployeeInformationDAO::count(const EmployeeInformationPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM sample";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
// ��ҳ��ѯ����
std::list<EmployeeInformationPageDO> EmployeeInformationDAO::selectWithPage(const EmployeeInformationPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM sample";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	EmployeeInformationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<EmployeeInformationPageDO, EmployeeInformationMapper>(sqlStr, mapper, params);
}
// ͨ��������ѯ����
std::list<EmployeeInformationPageDO> EmployeeInformationDAO::selectByName(const string& name)
{
	string sql = "SELECT * FROM sample WHERE `name` LIKE CONCAT('%',?,'%')";
	EmployeeInformationMapper mapper;
	return sqlSession->executeQuery<EmployeeInformationPageDO, EmployeeInformationMapper>(sql, mapper, "%s", name);
}
// ��������
uint64_t EmployeeInformationDAO::insert(const EmployeeInformationPageDO& iObj)
{

	string sql= "INSERT INTO `sample` (`name`,`age`,`id`,`organize`,`depart`,`job`,`post`,`idMum`,`birthday`,`phone`,`state`,) VALUES (?, ?, ?)";
	return sqlSession->executeInsert(sql,"%s&i%s%s%s%s%s%s%s%s%s",iObj.getName(),iObj.getAge(),iObj.getId(),iObj.getOrganize(),iObj.getDepart(),iObj.getJob(), iObj.getPost(),iObj.getIdMum(),iObj.getBirthday(),iObj.getPhone(),iObj.getState());
}
