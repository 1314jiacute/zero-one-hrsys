#pragma once
#ifndef _JOBLEVELTYPELISTDAO_H_
#define _JOBLEVELTYPELISTDAO_H_

#include "BaseDAO.h"
#include "domain/do/jobLevelTypeList/JobLevelTypeDO.h"

class JobLevelTypeListDAO : public BaseDAO
{
private:
	// ְ�Ƶȼ���Ӧ��ϣ��
	unordered_map<string, string> jobLevel = {
		{"30", u8"���߼�"},
		{"20", u8"�߼�"},
		{"10", u8"�м�"},
		{"5", u8"����"}
	};
public:
	// ��ѯ����
	list<JobLevelTypeDO> listAll();
	// ���������б�
	unordered_map<string, string> getMapList();
};

#endif // !_JOBLEVELTYPELISTDAO_H_