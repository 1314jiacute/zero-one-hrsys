#include "stdafx.h"
#include "TitleController.h"

// ��ҳ��ѯ����
TitlePageJsonVO::Wrapper TitleController::execQueryTitle(const TitleQuery::Wrapper& query, const PayloadDTO& payload)
{
    // ������Ӧ����
    auto vo = TitlePageJsonVO::createShared();
    // ������ҳ����
    auto pdto = TitlePageDTO::createShared();
    // ��Ӧ���
    vo->success(pdto);
    return vo;
}

// ��������
Uint64JsonVO::Wrapper TitleController::execAddTitle(const TitleDTO::Wrapper& dto)
{
    // ���巵�����ݶ���
    auto jvo = Uint64JsonVO::createShared();

    // ��Ӧ���
    jvo->success(1);
    return jvo;
}

// �޸�����
Uint64JsonVO::Wrapper TitleController::execModifyTitle(const TitleDTO::Wrapper& dto)
{
    // ������Ӧ����
    auto vo = Uint64JsonVO::createShared();


    // ��Ӧ���
    vo->success(1);
    return vo;
}

// ɾ������
Uint64JsonVO::Wrapper TitleController::execRemoveTitle(const TitleDTO::Wrapper& dto)
{
    // ������Ӧ����
    auto vo = Uint64JsonVO::createShared();

    // ��Ӧ���
    vo->success(1);
    return vo;
}