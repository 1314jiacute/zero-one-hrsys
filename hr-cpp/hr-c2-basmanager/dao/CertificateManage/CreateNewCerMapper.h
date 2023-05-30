#pragma once
/*
֤�����-�½�֤��--pine
*/
#ifndef  _CREATE_NEW_CER_MAPPER_
#define  _CREATE_NEW_CER_MAPPER_

#include "Mapper.h"
#include "../../domain/do/CertificateManage/CertificateDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class CreateNewCerMapper : public Mapper<CertificateDO>
{
public:
	CertificateDO mapper(ResultSet* resultSet) const override
	{
		CertificateDO data;
		data.setYgbh(resultSet->getUInt64(1));//this
		data.setPimVocationalName(resultSet->getString(2));//this


		//data.setYgzt(resultSet->getString(3));
		//data.setOrganizationName(resultSet->getString(3));
		//data.setZgzsbh(resultSet->getString(5));
		//data.setBcardNumber(resultSet->getString(6));	
		//data.setZslx(resultSet->getString(8));
		//data.setZghqrq(resultSet->getString(9));
		//data.setZcdw(resultSet->getString(10));
		//data.setZgsydw(resultSet->getString(11));
		//data.setFzyxq(resultSet->getString(12));
		//data.setSxrq(resultSet->getString(13));
		return data;
	}
};
/*
*get�����ǲ鵽�ķ��������ı������,Ҫ��ʵ�ʵ��������Ӧ���У�����ֻ����Ҫ���������
*/


/*
SampleMapper��������ǽ�ResultSet�����е�����ӳ�䵽SampleDO�����С�ResultSetͨ�����ڱ�ʾ�����ݿ��м������Ľ������
mapper��������һ��ResultSet*��������ָ��ResultSet�����ָ�룬������һ��SampleDO����
��mapper�����У����ȴ���һ��SampleDO����data��Ȼ��ͨ������resultSet����ĸ��ַ�������getUInt64��getString��getInt��
��ȡ������еľ������ݣ���ʹ��data�������Ӧsetter��������setId��setName��setSex��setAge�����������õ�SampleDO�����С�
��󣬽����õ�SampleDO���󷵻ء�
��δ���չʾ��һ�ֳ���������ӳ��ģʽ�����ڽ����ݿ��ѯ���ӳ�䵽�Զ�������ݶ����С�
*/
#endif // !_SAMPLE_MAPPER_