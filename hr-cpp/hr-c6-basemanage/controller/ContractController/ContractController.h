#ifndef __ContractController__
#define __ContractController__

#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "../../Macros.h"
#include "domain/query/ContractQuery/ContractQuery_.h"
#include "../../domain/dto/ContractDTO/ContractDTO_.h"
#include "../../domain/vo/ContractVO/ContractVO_.h"

//�޸ĺ�ͬ�������
#define UPDATECONTRACTINFO \
info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("expenseledger_mug.filed.id");\
info->queryParams["id"].addExample("default", UInt64(114514));\
info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("expenseledger_mug.filed.name");\
info->queryParams["name"].addExample("default", String("xiaoming"));\
info->queryParams["name"].required = false;\
info->queryParams.add<String>("type").description = ZH_WORDS_GETTER("expenseledger_mug.filed.type");\
info->queryParams["type"].addExample("default", String("A"));\
info->queryParams["type"].required = false;\
info->queryParams.add<String>("variety").description = ZH_WORDS_GETTER("expenseledger_mug.filed.variety");\
info->queryParams["variety"].addExample("default", String("a"));\
info->queryParams["variety"].required = false;\
info->queryParams.add<String>("date").description = ZH_WORDS_GETTER("expenseledger_mug.filed.date");\
info->queryParams["date"].addExample("default", String("2023-05-02 19:57:59"));\
info->queryParams["date"].required = false;\
info->queryParams.add<String>("condition").description = ZH_WORDS_GETTER("expenseledger_mug.filed.condition"); \
info->queryParams["condition"].addExample("default", String("ok")); \
info->queryParams["condition"].required = false;\
info->queryParams.add<String>("department_m").description = ZH_WORDS_GETTER("expenseledger_mug.filed.department_m"); \
info->queryParams["department_m"].addExample("default", String("ok")); \
info->queryParams["department_m"].required = false;\
info->queryParams.add<String>("department_c").description = ZH_WORDS_GETTER("expenseledger_mug.filed.department_c"); \
info->queryParams["department_c"].addExample("default", String("ok")); \
info->queryParams["department_c"].required = false;\
info->queryParams.add<String>("date_end").description = ZH_WORDS_GETTER("expenseledger_mug.filed.date_end"); \
info->queryParams["date_end"].addExample("default", String("2023-05-02 19:57:59")); \
info->queryParams["date_end"].required = false;\
info->queryParams.add<String>("tip").description = ZH_WORDS_GETTER("expenseledger_mug.filed.tip"); \
info->queryParams["tip"].addExample("default", String("ok")); \
info->queryParams["tip"].required = false




//��ѯ��ͬ�������
#define QUERYCONTRACTINFO \
info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("expenseledger_mug.filed.id");\
info->queryParams["id"].addExample("default", String("114514"))


using namespace oatpp;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ContractController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ContractController);

public:
	// 3.1.1 �ӿ�����:�鿴ָ����ͬ
	ENDPOINT_INFO(queryContract) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("contract.check");
		// ���Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractJsonVO_);
		// ���������ѯ����
		QUERYCONTRACTINFO;
	}
	// 3.1.2 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/contract-management/query-contract-info", queryContract, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, ContractQuery_, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryContract(query));
	}

	//3.2.1 �ӿ�����:�޸�ָ����ͬ
	ENDPOINT_INFO(updateContract) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("contract.update");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		// ���������ѯ����
		UPDATECONTRACTINFO;
	}

	// 3.2.2 ����ӿڶ˵�
	ENDPOINT(API_M_PUT, "/contract-management/update-contract-info", updateContract, BODY_DTO(ContractDTO_::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execUpdateContract(dto));
	}

	//3.3.1 �ӿ�����:�����ͬ
	ENDPOINT_INFO(uploadContract) {
		info->summary = ZH_WORDS_GETTER("contract.upload");
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		info->queryParams["suffix"].description = ZH_WORDS_GETTER("user.file.suffix");
		info->queryParams["suffix"].addExample("png", String(".png"));
		info->queryParams["suffix"].addExample("jpg", String(".jpg"));
		info->queryParams["suffix"].addExample("txt", String(".txt"));
	}
	// 3.3.2 ����ӿڶ˵�
	// �����ļ��ϴ��˵㴦��
	ENDPOINT(API_M_POST, "/contract-management/upload-contract-info", uploadContract, BODY_STRING(String, body), QUERY(String, suffix)) {
		// ִ���ļ������߼�
		API_HANDLER_RESP_VO(execUploadContract(body, suffix));
	}

	//3.4.1 �ӿ�����:������ͬ
	ENDPOINT_INFO(downloadContract) {
		info->summary = ZH_WORDS_GETTER("contract.download");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ���������ѯ����
		info->queryParams.add<UInt8>("rows").description = ZH_WORDS_GETTER("contract.export.rows");
		info->queryParams["rows"].addExample("default", UInt8(1));
		info->queryParams["rows"].required = true;
		info->queryParams.add<String>("sequence").description = ZH_WORDS_GETTER("contract.export.sequence");
		info->queryParams["sequence"].addExample("default", String("ASC"));
		info->queryParams["sequence"].required = true;
	}
	// 3.4.2 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/contract-management/download-contract-info", downloadContract, QUERIES(QueryParams, qps)) {
		API_HANDLER_QUERY_PARAM(query, ContractDownloadQuery, qps);
		API_HANDLER_RESP_VO(execDownloadContract(query));
	}




private:
	//��ͬ��ѯ
	ContractJsonVO_::Wrapper execQueryContract(const ContractQuery_::Wrapper& query);
	//�޸ĺ�ͬ
	Uint64JsonVO::Wrapper execUpdateContract(const ContractDTO_::Wrapper& dto);
	//�����ͬ
	StringJsonVO::Wrapper execUploadContract(const String& fileBody, const String& suffix);
	//������ͬ
	StringJsonVO::Wrapper execDownloadContract(const ContractDownloadQuery::Wrapper& query);
};
// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif 
