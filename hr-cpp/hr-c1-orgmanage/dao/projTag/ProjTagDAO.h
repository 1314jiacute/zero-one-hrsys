#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/23 17:06:40

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
#ifndef _PROJTAGDAO_H_
#define _PROJTAGDAO_H_
#include "BaseDAO.h"
#include "domain/do/projTag/ProjTagDO.h"
#include "domain/do/projTag/OrgListDO.h"
#include "domain/query/projTag/OrgListQuery.h"
#include "domain/query/projTag/PageProjTagQuery.h"

/**
 * ��Ŀ��ǩDAOʵ��
 */
class ProjTagDAO : public BaseDAO
{
public:
	/**
	 * ��Ŀ��ǩ - ������Ŀ��ǩDAOʵ��
	 * �����ˣ�Զ��
	 */
	uint64_t insert(const ProjTagDO& iObj);
	/**
	 * ��Ŀ��ǩ - ��ҳ��ѯ��֯�б�DAOʵ��
	 * ���ܣ���ѯ��֯�б��������ݷ�ҳ
	 * �����ˣ�Andrew
	 */
	std::list<OrgListDO> selectOrgList(const OrgListQuery::Wrapper& query);
	/**
	 * ��Ŀ��ǩ - ��ҳ��ѯ��֯�б�DAOʵ��
	 * ���ܣ�������������
	 * �����ˣ�Andrew
	 */
	uint64_t count(const OrgListQuery::Wrapper& query);
	/**
	 * ��Ŀ��ǩ - �޸���Ŀ��ǩDAOʵ��
	 * ���ܣ�����ָ����Ŀ��ǩΨһ��ʶ������Ŀ��ǩ����
	 * �����ˣ�Andrew
	 */
	bool updateProjTag(const ProjTagDO& data);
	/**
	 * ��Ŀ��ǩ - ��ҳ��ѯ��Ŀ��ǩ�б�DAOʵ��
	 * ���ܣ�������������
	 * �����ˣ����֮��
	 */
	uint64_t count(const PageProjTagQuery::Wrapper& query);
	/**
	 * ��Ŀ��ǩ - ��ҳ��ѯ��Ŀ��ǩ�б�DAOʵ��
	 * ���ܣ���ѯ��Ŀ��ǩ�б��������ݷ�ҳ
	 * �����ˣ����֮��
	 */
	std::list<ProjTagDO> selectProjTag(const PageProjTagQuery::Wrapper& query);
};

#endif // !_PROJTAGDAO_H_