#pragma once

#include "../../GlobalInclude.h"
#include "../../dto/org/ImportDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��ʾ���˵���ʾJsonVO����������Ӧ��ǰ��
 */
class ImportJsonVO : public JsonVO<ImportDTO::Wrapper>>
{
	DTO_INIT(ImportJsonVO , JsonVO<ImportDTO::Wrapper>>);
public:
	// �ڹ��캯����ʵ����data�б�
	ImportJsonVO() {
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MENUVO_H_