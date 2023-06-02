#pragma once
/*
* ������������--ɾ����������(֧������ɾ��)--pine
*/
#ifndef  _DELETE_LEGAL_ENTITY_MAPPER_
#define  _DELETE_LEGAL_ENTITY_MAPPER_

#include "Mapper.h"
#include "../../domain/do/LegalEntitySet/LegalEntitySetDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class DeleteLegalEntityMapper : public Mapper<LegalEntitySetDO>
{
public:
	LegalEntitySetDO mapper(ResultSet* resultSet) const override
	{
		LegalEntitySetDO data;
		data.setORMSIGNORGNAME(resultSet->getString(1));//this
		data.setCONTRACTSIGNORGNAME(resultSet->getString(2));//Ҫ�����ѯ//this
		data.setISDEFAULTSIGNORG(resultSet->getUInt64(3));//this

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