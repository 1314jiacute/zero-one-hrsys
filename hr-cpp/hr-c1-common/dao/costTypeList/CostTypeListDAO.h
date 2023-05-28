#pragma once
#ifndef _COSTTYPELISTDAO_H_
#define _COSTTYPELISTDAO_H_

#include "BaseDAO.h"
#include "domain/do/costTypeList/CostType.h"

class CostTypeListDAO : public BaseDAO
{
private:
	// ְ�Ƶȼ���Ӧ��ϣ��
	unordered_map<string, string> costType = {
		{"10", u8"�ϸɲ����"},
		{"20", u8"����"},
		{"30", u8"��ҵЧ�潱��"},
		{"40", u8"����"},
		{"50", u8"ҽ�Ʒ�"},
		{"60", u8"�������ã���ע��ϸ��"}
	};
public:
	// ��ѯ����
	list<CostTypeDO> listAll();
	// ���������б�
	unordered_map<string, string> getMapList();
};

#endif // !_COSTTYPELISTDAO_H_