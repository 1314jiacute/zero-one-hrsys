#include "stdafx.h"
#include "AssignInfoService.h"
#include "../../dao/assignInfoDAO/AssignInfoDAO.h"
#include"../lib-common/include/SnowFlake.h"
AssignInfoPageDTO::Wrapper AssignInfoService::listAll(const AssignInfoQuery::Wrapper& query)
{
	//// �������ض���
	auto pages = AssignInfoPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	AssignInfoDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	//// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<AssignInfoDO> result = dao.selectWithPage(query);
	//// ��DOת����DTO
	for (AssignInfoDO sub : result)
	{
		auto dto = AssignInfoDTO::createShared();
		 	//	dto->id = sub.getId();
		 	//	dto->assign = sub.getAssign();
		 	//	dto->etype = sub.getEtype();
		 	//	dto->organize = sub.getOrganize();
				//dto->depart = sub.getDepart();
				//dto->job = sub.getJob();
				//dto->post= sub.getPost();
				//dto->startTime = sub.getStartTime();
				//dto->endTime = sub.getEndTime();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,assignId,AssignId ,id, Id,assign,Assign,assignState,AssignState,etype,Etype,organize,Organize,depart,Depart,job,Job,post,Post,startTime,StartTime,endTime,EndTime)
			pages->addData(dto);
	}
	return pages;
}

uint64_t AssignInfoService::saveData(const AssignInfoDTO::Wrapper& dto)
{
	//ѩ���㷨
	SnowFlake c3_assign(1, 3);
	// ��װDO����
	AssignInfoDO data;
	data.setAssignId(to_string(c3_assign.nextId()));
	 //	data.setId(dto->id.getValue(""));
	 //	data.setAssign(dto->assign.getValue(""));
	 //	data.setEtype(dto->etype.getValue(""));
		//data.setOrganize(dto->organize.getValue(""));
		//data.setDepart(dto->depart.getValue(""));
		//data.setJob(dto->job.getValue(""));
		//data.setPost(dto->post.getValue(""));
		//data.setStartTime(dto->startTime.getValue(""));
		//data.setEndTime(dto->endTime.getValue(""));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id,id,Assign,assign,AssignState,assignState,Etype,etype,Organize,organize,Depart,depart,Job,job,Post,post,StartTime,startTime,EndTime,endTime)
		// ִ���������
		AssignInfoDAO dao;
	return dao.insert(data);
}

bool AssignInfoService::updateData(const AssignInfoDTO::Wrapper& dto)
{
	// ��װDO����
	AssignInfoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, AssignId,assignId,Assign, assign,AssignState,assignState, Etype, etype, Organize, organize, Depart, depart, Job, job, Post, post, StartTime, startTime, EndTime, endTime,Id,id)
		// ִ�������޸�
		AssignInfoDAO dao;
	return dao.update(data) == 1;
}

bool AssignInfoService::removeData(string assignId)
{
	AssignInfoDAO dao;
	return dao.deleteById(assignId) == 1;
}

AssignInfoDTO::Wrapper AssignInfoService::QueryDetail(const AssignInfoDTO::Wrapper& dto)
{
	//// �������ض���
	//auto page = AssignInfoDTO::createShared();

	//// ��DOת����DTO
	AssignInfoDAO dao;
	list<AssignInfoDO> result = dao.selectById(dto->assignId);
	for (AssignInfoDO sub : result) {
		//	dto->id = sub.getId();
		//	dto->assign = sub.getAssign();
		//	dto->etype = sub.getEtype();
		//	dto->organize = sub.getOrganize();
			//dto->depart = sub.getDepart();
			//dto->job = sub.getJob();
			//dto->post= sub.getPost();
			//dto->startTime = sub.getStartTime();
			//dto->endTime = sub.getEndTime();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,assignId,AssignId ,id, Id, assign, Assign,assignState,AssignState, etype, Etype, organize, Organize, depart, Depart, job, Job, post, Post, startTime, StartTime, endTime, EndTime)
	}
		return dto;
}