#include "stdafx.h"
#include "AssignInfoService.h"
#include "../../dao/assignInfoDAO/AssignInfoDAO.h"

AssignInfoPageDTO::Wrapper AssignInfoService::listAll(const AssignInfoQuery::Wrapper& query)
{
	//// �������ض���
	auto pages = AssignInfoPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	//// ��ѯ����������
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
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id,assign,Assign,etype,Etype,organize,Organize,depart,Depart,job,Job,post,Post,startTime,StartTime,endTime,EndTime)
			pages->addData(dto);
	}
	return pages;
}

uint64_t AssignInfoService::saveData(const AssignInfoDTO::Wrapper& dto)
{
	// ��װDO����
	AssignInfoDO data;
	 //	data.setId(dto->id.getValue(""));
	 //	data.setAssign(dto->assign.getValue(""));
	 //	data.setEtype(dto->etype.getValue(""));
		//data.setOrganize(dto->organize.getValue(""));
		//data.setDepart(dto->depart.getValue(""));
		//data.setJob(dto->job.getValue(""));
		//data.setPost(dto->post.getValue(""));
		//data.setStartTime(dto->startTime.getValue(""));
		//data.setEndTime(dto->endTime.getValue(""));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id,id,Assign,assign,Etype,etype,Organize,organize,Depart,depart,Job,job,Post,post,StartTime,startTime,EndTime,endTime)
		// ִ���������
		AssignInfoDAO dao;
	return dao.insert(data);
}

bool AssignInfoService::updateData(const AssignInfoDTO::Wrapper& dto)
{
	// ��װDO����
	AssignInfoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Assign, assign, Etype, etype, Organize, organize, Depart, depart, Job, job, Post, post, StartTime, startTime, EndTime, endTime,Id,id)
		// ִ�������޸�
		AssignInfoDAO dao;
	return dao.update(data) == 1;
}

bool AssignInfoService::removeData(string id)
{
	AssignInfoDAO dao;
	return dao.deleteById(id) == 1;
}

AssignInfoDTO::Wrapper AssignInfoService::QueryDetail(const AssignInfoDTO::Wrapper& dto)
{
	//// �������ض���
	//auto page = AssignInfoDTO::createShared();

	//// ��DOת����DTO
	AssignInfoDAO dao;
	list<AssignInfoDO> result = dao.selectById(dto->id);
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
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, assign, Assign, etype, Etype, organize, Organize, depart, Depart, job, Job, post, Post, startTime, StartTime, endTime, EndTime)
	}
		return dto;
}