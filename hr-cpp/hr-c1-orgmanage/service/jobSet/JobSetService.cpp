
#include "stdafx.h"
#include "JobSetService.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "SqlSession.h"
#include "TransactionManager.h"
#include "domain/do/postSet/PostDetailDO.h"
#include "dao/jobSet/JobSetDAO.h"
std::list<string> JobSetService::saveMultiJob(const ImportJobDTO::Wrapper& dto)
{
	
	// Excel���
	std::string fileName = dto->filePath;
	std::string sheetName = dto->sheetName;
	ExcelComponent excel;
	
	// ������ļ��ж�ȡ������
	auto data = excel.readIntoVector(fileName, sheetName);

	// �жϵ�ǰ���ݹ�ģ�ܷ�һ�ε���
	

	// �������ݵĻ���
	list<PostDetailDO> dataList;
	for (auto row : data)
	{
		// ����һ����λ����DO����PostDetailDO
		PostDetailDO dataSingle;
		int i = 0;
		for (auto cellval : row)
		{	
			// �����ֱ�Ӷ�Ӧ��ĳһ�У�д��
			switch (i) {
			case 0:
				dataSingle.setOrmPostId(cellval);
				break;
			case 1:
				dataSingle.setOrgId(cellval);
				break;
			case 2: 
				dataSingle.setOrmOrgName(cellval);
				break;
			case 3:
				dataSingle.setGwfl(cellval);
				break;
			case 4:
				dataSingle.setIsConfidential(cellval);
				break;
			case 5:
				dataSingle.setPostNature(cellval);
				break;
			case 6:
				dataSingle.setIsKeyPostion(cellval);
				break;
			case 7:
				dataSingle.setStartStopSign(cellval);
				break;
			}
			i++;
		}
		dataList.push_back(dataSingle);
	}

	JobSetDAO dao;
	return dao.insertMultiData(dataList);
}
