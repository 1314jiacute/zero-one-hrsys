#include "stdafx.h"
#include "ExportLanguage.h"

/**
 * ���������ļ�����ʵ��
 * �����ˣ���
 */
StringJsonVO::Wrapper ExportLanguageController::execDownloadLanguage()
{
	auto jvo = StringJsonVO::createShared();
	jvo->success("download language competence success");
	return jvo;
}
