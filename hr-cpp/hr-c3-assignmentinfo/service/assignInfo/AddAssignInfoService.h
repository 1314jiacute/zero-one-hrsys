#pragma once
#ifndef _Add_Assign_Info_SERVICE_
#define _Add_Assign_Info_SERVICE_
#include <list>
#include "domain/vo/assignInfo/AddAssignInfoVO.h"
#include "domain/dto/assignInfo/AddAssignInfoDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class AddAssignInfoService
{
public:
	// ��ҳ��ѯ��������
	// ��������
	uint64_t saveData(const AddAssignInfoDTO::Wrapper& dto);
};

#endif // !_Add_Assign_Info_SERVICE_