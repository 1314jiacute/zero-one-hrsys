#pragma once

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ImportQuery : public oatpp::DTO {
    DTO_INIT(ImportQuery , DTO);

    // �ļ��Ķ�����
    DTO_FILED(String, file);
};

#include OATPP_CODEGEN_END(DTO)