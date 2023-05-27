
#include "stdafx.h"
#include "JobSetDAO.h"


std::list<string> JobSetDAO::insertMultiData(const list<PostDetailDO>& dataList)
{
	std::list<string> ret;
	// ��ʼ����
	sqlSession->beginTransaction();
	
	// ��ͷ��ʼ�������������б��м����κ�һ��ʧ�ܣ��ͳ���
	for (auto it = dataList.begin(); it != dataList.end(); it++) {
		string sql = "INSERT INTO `t_ormpost` \
				(`ORMPOSTID`, `ORMORGID`,`ORMPOSTNAME`, `GWFL`, `ISCONFIDENTIAL`, `POSTNATURE`, `ISKEYPOSTION`, `STARTSTOPSIGN`)\
				VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
		// �ɹ�����������id
		// ʧ�ܣ�����0
		int singleRet = sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s", \
			(*it).getOrmPostId(), (*it).getOrgId(), \
			(*it).getOrmOrgName(), (*it).getGwfl(), (*it).getIsConfidential(), (*it).getPostNature(),\
			(*it).getIsKeyPostion(), (*it).getStartStopSign());
		ret.push_back(std::to_string(singleRet));
		// ���ִ��ʧ�ܣ��ع�
		// �ɹ������
		/*if (singleRet == 0) {
			sqlSession->rollbackTransaction();
			return ret;
		}*/
	}

	// �ύ����
	sqlSession->commitTransaction();
	return ret;
}

