#include "stdafx.h"
#include "DeleteProjTagController.h"
#include "service/projTag/deleteProjTagService/DeleteProjTagService.h"

StringJsonVO::Wrapper DeleteProjTagController::execDeleteByTagId(const DeleteProjTagDTO::Wrapper& deleteProjTagDTO, const PayloadDTO& payload)
{
	auto vo = StringJsonVO::createShared();
	// ����У��
	if (!deleteProjTagDTO->tagId)
	{
		vo->init(String(""), RS_PARAMS_INVALID);
		return vo;
	}
	DeleteProjTagService deleteProjTagService;

	// ִ������ɾ��
	if (deleteProjTagService.removeData(deleteProjTagDTO->tagId)) {
		vo->success(deleteProjTagDTO->tagId);
	}
	else
	{
		vo->fail(deleteProjTagDTO->tagId);
	}
	return vo;
}

DeleteProjTagBatchVO::Wrapper DeleteProjTagController::execDeleteBatchByTagId(const DeleteProjTagBatchDTO::Wrapper& deleteProjTagBatchDTO, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto vo = DeleteProjTagBatchVO::createShared();
	// ����У��
	if (!deleteProjTagBatchDTO->tagIds)
	{
		vo->init(deleteProjTagBatchDTO, RS_PARAMS_INVALID);
		return vo;
	}
	DeleteProjTagService postDeleteService;

	// ִ������ɾ��
	if (postDeleteService.removeBatchData(deleteProjTagBatchDTO)) {
		vo->success(deleteProjTagBatchDTO);
	}
	else
	{
		vo->fail(deleteProjTagBatchDTO);
	}
	return vo;
}