#include "stdafx.h"
#include "MilitaryService.h"
#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include "../../dao/military/MilitaryDAO.h"

#define DO_TO_VECTOR(f) \
ss.clear(); \
ss<<sub.get##f(); \
row.push_back(ss.str()); \
ss.str("");

MilitaryDTO::Wrapper MilitaryService::listDetail(const MilitaryDetailQuery::Wrapper& query)
{
	// �������ض���
	//auto lists = MilitaryDTO::createShared();
	MilitaryDAO dao;
	auto lists = dao.selectDetail(query);
	auto dto = MilitaryDTO::createShared();
	if (!lists.empty()) {
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, lists.front(), UPDATEDATE, _UPDATEDATE, PIMARMYCADRESNAME, _PIMARMYCADRESNAME, FJ, _FJ, CREATEDATE, _CREATEDATE, UPDATEMAN, _UPDATEMAN, ENABLE, _ENABLE, PIMARMYCADRESID, _PIMARMYCADRESID, CREATEMAN, _CREATEMAN, PIMPERSONID, _PIMPERSONID, FSSJ, _FSSJ, JLSS, _JLSS, JLSPZT, _JLSPZT, JLGLBH, _JLGLBH, JLCZZ, _JLCZZ, TROOPTYPE, _TROOPTYPE, LEVELTYPE, _LEVELTYPE, REASON, _REASON);
	}
	return dto;
}

bool MilitaryService::updateData(const MilitaryDTO::Wrapper& dto)
{
	// ��װDO����
	MilitaryDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, _UPDATEDATE, UPDATEDATE, _PIMARMYCADRESNAME, PIMARMYCADRESNAME, _FJ, FJ, _CREATEDATE, CREATEDATE, _UPDATEMAN, UPDATEMAN, _ENABLE, ENABLE, _PIMARMYCADRESID, PIMARMYCADRESID, _CREATEMAN, CREATEMAN, _PIMPERSONID, PIMPERSONID, _FSSJ, FSSJ, _JLSS, JLSS, _JLSPZT, JLSPZT, _JLGLBH, JLGLBH, _JLCZZ, JLCZZ, _TROOPTYPE, TROOPTYPE, _LEVELTYPE, LEVELTYPE, _REASON, REASON);
	// ִ�������޸�
	MilitaryDAO dao;
	return dao.update(data) == 1;
}

string MilitaryService::download(const MilitaryDownloadQuery::Wrapper& query)
{
	vector<vector<string>> data;
	list<MilitaryDO> result = MilitaryDAO().selectWithPage(query);
	data.push_back({
		CharsetConvertHepler::ansiToUtf8("����ʱ��") ,
		CharsetConvertHepler::ansiToUtf8("��ת�ɲ�����") ,
		CharsetConvertHepler::ansiToUtf8("����") ,
		CharsetConvertHepler::ansiToUtf8("����ʱ��") ,
		CharsetConvertHepler::ansiToUtf8("������") ,
		CharsetConvertHepler::ansiToUtf8("ENABLE") ,
		CharsetConvertHepler::ansiToUtf8("��ת�ɲ���ʶ") ,
		CharsetConvertHepler::ansiToUtf8("������") ,
		CharsetConvertHepler::ansiToUtf8("��Ա��Ϣ��ʶ") ,
		CharsetConvertHepler::ansiToUtf8("����ʱ��") ,
		CharsetConvertHepler::ansiToUtf8("��¼����") ,
		CharsetConvertHepler::ansiToUtf8("����״̬") ,
		CharsetConvertHepler::ansiToUtf8("��¼������") ,
		CharsetConvertHepler::ansiToUtf8("��¼������") ,
		CharsetConvertHepler::ansiToUtf8("����") ,
		CharsetConvertHepler::ansiToUtf8("����") ,
		CharsetConvertHepler::ansiToUtf8("�ܾ�ԭ��")
	});
	for (MilitaryDO sub : result)
	{
		vector<string> row;
		stringstream ss;
		DO_TO_VECTOR(_UPDATEDATE);
		DO_TO_VECTOR(_PIMARMYCADRESNAME);
		DO_TO_VECTOR(_FJ);
		DO_TO_VECTOR(_CREATEDATE);
		DO_TO_VECTOR(_UPDATEMAN);
		DO_TO_VECTOR(_ENABLE);
		DO_TO_VECTOR(_PIMARMYCADRESID);
		DO_TO_VECTOR(_CREATEMAN);
		DO_TO_VECTOR(_PIMPERSONID);
		DO_TO_VECTOR(_FSSJ);
		DO_TO_VECTOR(_JLSS);
		DO_TO_VECTOR(_JLSPZT);
		DO_TO_VECTOR(_JLGLBH);
		DO_TO_VECTOR(_JLCZZ);
		DO_TO_VECTOR(_TROOPTYPE);
		DO_TO_VECTOR(_LEVELTYPE);
		DO_TO_VECTOR(_REASON);
		data.push_back(row);
	}
	stringstream ss;
	ss << "./temp/excel/" << chrono::system_clock::now().time_since_epoch().count() << ".xlsx";
	string fileName = ss.str();
	string sheetName = CharsetConvertHepler::ansiToUtf8("���ݱ�1");
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);
#ifdef LINUX
	//����ͻ��˶���
	FastDfsClient client("conf/client.conf");
#else
	//����ͻ��˶���
	FastDfsClient client("8.130.87.15");
#endif
	//�ϴ�excel���
	string filedName = client.uploadFile(fileName);
	cout << "upload fieldname is : " << filedName << endl;
	//ɾ���ϴ����ļ�
	//cout << "delete file result is : " << client.deleteFile(filedName) << endl;
	return filedName;
}
