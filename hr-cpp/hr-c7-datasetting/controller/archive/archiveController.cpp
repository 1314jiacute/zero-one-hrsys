#include "stdafx.h"
#include "ArchiveController.h"

// ��ҳ��ѯ����
ArchivePageJsonVO::Wrapper ArchiveController::execQueryArchive(const ArchiveQuery::Wrapper& query, const PayloadDTO& payload)
{
    // ������Ӧ����
    auto vo = ArchivePageJsonVO::createShared();
    // ������ҳ����
    auto pdto = ArchivePageDTO::createShared();
    // ��Ӧ���
    vo->success(pdto);
    return vo;
}

// ��������
Uint64JsonVO::Wrapper ArchiveController::execAddArchive(const ArchiveDTO::Wrapper& dto)
{
    // ���巵�����ݶ���
    auto jvo = Uint64JsonVO::createShared();
   
    // ��Ӧ���
    jvo->success(1);
    return jvo;
}
// �޸�����
Uint64JsonVO::Wrapper ArchiveController::execModifyArchive(const ArchiveDTO::Wrapper& dto)
{
    // ������Ӧ����
    auto vo = Uint64JsonVO::createShared();
    // ��Ӧ���
    vo->success(1);
    return vo;
}

// ɾ������
Uint64JsonVO::Wrapper ArchiveController::execRemoveArchive(const ArchiveDTO::Wrapper& dto)
{
    // ������Ӧ����
    auto vo = Uint64JsonVO::createShared();
    
    // ��Ӧ���
    vo->success(1);
    return vo;
}