#pragma once
/*
֤�����-��ҳ��ѯ֤���б�--pine
*/
#ifndef  _CHECH_CER_LIST_MAPPER_
#define  _CHECH_CER_LIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/CertificateManage/CertificateDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class CertificateMapper : public Mapper<CertificateDO>
{
public:
	CertificateDO mapper(ResultSet* resultSet) const override
	{
		CertificateDO data;
		//data.setId(resultSet->getUInt64(1));
		//data.setName(resultSet->getString(2));
		//data.setSex(resultSet->getString(3));
		//data.setAge(resultSet->getString(4));
		//data.setOrganization(resultSet->getString(5));
		//data.setDepartment(resultSet->getString(6));
		//data.setRank(resultSet->getString(7));
		//data.setMail_address(resultSet->getString(8));
		//data.setFamily_contact(resultSet->getString(9));
		//data.setFamily_contact_nuimber(resultSet->getString(10));
		return data;
	}
};

/*
SampleMapper��������ǽ�ResultSet�����е�����ӳ�䵽SampleDO�����С�ResultSetͨ�����ڱ�ʾ�����ݿ��м������Ľ������
mapper��������һ��ResultSet*��������ָ��ResultSet�����ָ�룬������һ��SampleDO����
��mapper�����У����ȴ���һ��SampleDO����data��Ȼ��ͨ������resultSet����ĸ��ַ�������getUInt64��getString��getInt��
��ȡ������еľ������ݣ���ʹ��data�������Ӧsetter��������setId��setName��setSex��setAge�����������õ�SampleDO�����С�
��󣬽����õ�SampleDO���󷵻ء�
��δ���չʾ��һ�ֳ���������ӳ��ģʽ�����ڽ����ݿ��ѯ���ӳ�䵽�Զ�������ݶ����С�
*/
#endif // !_SAMPLE_MAPPER_