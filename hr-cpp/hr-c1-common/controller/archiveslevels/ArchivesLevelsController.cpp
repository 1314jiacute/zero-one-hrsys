#include "stdafx.h"
#include "ArchivesLevelsController.h"

ArchivesListVO::Wrapper ArchivesLevelsController::execQueryArchivesLevels() {
	auto dto = ArchivesLevelsListDTO::createShared();
	auto vo = ArchivesListVO::createShared();

	auto upLevels = ArchivesLevelsDTO::createShared("�ϲ�");
	auto midLevels = ArchivesLevelsDTO::createShared("�в�");
	auto downLevels = ArchivesLevelsDTO::createShared("�²�");

	dto->levelsList->push_back(upLevels);
	dto->levelsList->push_back(midLevels);
	dto->levelsList->push_back(downLevels);

	return vo;
}