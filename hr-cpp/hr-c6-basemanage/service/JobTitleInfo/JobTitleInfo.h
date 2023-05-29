#pragma once
#ifndef _JOBTITLE_INFO_H_
#define _JOBTITLE_INFO_H_
#include "domain/vo/JobTitleInfo/JobTitleInfoVO.h"
#include "domain/do/JobTitle/JobTitleDo.h"
#include "domain/dto/JobTitleInfo/JobTitleInfoDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class JobTitleInfoService
{
public:
	// ��ѯ����ְ����Ϣ
	exportJobTitleInfoDTO::Wrapper listAllJobTitle(const JobTitleInfoDTO::Wrapper& query);
	// ��ѯָ��������ϸ
	JobTitleInfoDTO::Wrapper queryDataDetail(const JobTitleInfoDTO::Wrapper& query);
	// �޸�����
	bool updateData(const JobTitleInfoDTO::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_