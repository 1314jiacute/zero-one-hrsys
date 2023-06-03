/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/05/25 15:38:37

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
#include "EmployeeInformationServicer.h"
#include "dao/EmployeeInformation/EmployeeInformationDAO.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"
#include "CustomerAuthorizeHandler.h"

// ��ҳ��ѯ��������
EmployeeInformationPageDTO::Wrapper EmployeeInformationServicer::listAll(const EmployeeInformationPageQuery::Wrapper& query)
{
	// �������ض���
	auto pages = EmployeeInformationPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	EmployeeInformationDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<EmployeeInformationPageDO> result = dao.selectWithPage(query);
	
	// ��DOת����DTO
	for (EmployeeInformationPageDO sub : result)
	{
		auto dto = EmployeeInformationDTO::createShared();
		//// ����
		//dto->name = sub.getName();
		//// ����
		//dto->age = sub.getAge();
		////���
		//dto->id = sub.getId();
		////��֯
		//dto->organize = sub.getOrganize();
		////����
		//dto->depart = sub.getDepart();
		////ְ��
		//dto->job = sub.getJob();
		////��λ
		//dto->post = sub.getPost();
		////֤����
		//dto->idMum = sub.getIdMum();
		////��������
		//dto->birthday = sub.getBirthday();
		////�ֻ�����
		//dto->phone = sub.getPhone();
		////Ա��״̬
		//dto->state = sub.getState();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, age, Age, id, Id, organize, Organize, depart, Depart, job, Job, post, Post, idMum, IdMum, birthday, Birthday, phone, Phone, state, State);
		pages->addData(dto);

	}
	return pages;
}
//����Ա����Ϣ
uint64_t EmployeeInformationServicer::saveData(const EmployeeInformationDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ��װDO����
	EmployeeInformationPageDO data;
	//// ����
	//data.setName(dto->name.getValue(""));
	//// ����
	//data.setAge(dto->age.getValue(1));
	////���
	//data.setId(dto->id.getValue(""));
	////��֯
	//data.setOrganize(dto->organize.getValue(""));
	////����
	//data.setDepart(dto->depart.getValue(""));
	////ְ��
	//data.setJob(dto->job.getValue(""));
	////��λ
	//data.setPost(dto->post.getValue(""));
	////֤����
	//data.setIdMum(dto->idMum.getValue(""));
	////��������
	//data.setBirthday(dto->birthday.getValue(""));
	////�ֻ�����
	//data.setPhone(dto->phone.getValue(""));
	////Ա��״̬
	//data.setState(dto->state.getValue(""));

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonId, personId, CreateMan, createMan, CreateDate, createDate,\
	Name, name, Age, age, Id, id, Organize, organize, Depart, depart, Job, job, Post, post, IdMum, idMum, Birthday, birthday, Phone, phone, State, state);

	// ��������
	SnowFlake sf(1, 3);//ѩ���㷨
	data.setPersonId(to_string(sf.nextId()));
	//������
	data.setCreateMan(payload.getId());
	//����ʱ��
	SimpleDateTimeFormat sdtf;//��ȡ��ǰʱ���ʽ�ַ���
	data.setCreateDate(sdtf.format());

	// ��Ҫ�ٷ��������ɵ�����
	data.setName(dto->name);
	data.setAge(dto->age);
	data.setId(dto->id);
	data.setOrganize(dto->organize);
	data.setDepart(dto->depart);
	data.setJob(dto->job);
	data.setPost(dto->post);
	data.setIdMum(dto->idMum);
	data.setBirthday(dto->birthday);
	data.setPhone(dto->phone);
	data.setState(dto->state);
	// ִ���������
	EmployeeInformationDAO dao;
	return dao.insert(data);
}

