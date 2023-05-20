#ifndef _Query_Assign_CONTROLLER_
#define _Query_Assign_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "domain/query/assignInfo/AssignInfoQuery.h"
#include "domain/query/PageQuery.h"
#include "domain/vo/assignInfo/AssignInfoQueryVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) // 0

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class QueryAssignController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(QueryAssignController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(assignQuery) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("employee.get.sumary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AssignInfoQueryJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("employee.field.id");
		info->queryParams["id"].addExample("default", String("114514"));
		info->queryParams["id"].required = false;
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/sample", assignQuery, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, AssignInfoQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAssignQuery(userQuery, authObject->getPayload()));
	}
	//// 3.1 ���������ӿ�����
	//ENDPOINT_INFO(addSample) {
	//	// ����ӿڱ���
	//	info->summary = ZH_WORDS_GETTER("sample.post.summary");
	//	// ������Ӧ������ʽ
	//	API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	//}
	//// 3.2 ���������ӿڴ���
	//ENDPOINT(API_M_POST, "/sample", addSample, BODY_DTO(SampleDTO::Wrapper, dto)) {
	//	// ��Ӧ���
	//	API_HANDLER_RESP_VO(execAddSample(dto));
	//}
	//// 3.1 �����޸Ľӿ�����
	//ENDPOINT_INFO(modifySample) {
	//	// ����ӿڱ���
	//	info->summary = ZH_WORDS_GETTER("sample.put.summary");
	//	// ������Ӧ������ʽ
	//	API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	//}
	//// 3.2 �����޸Ľӿڴ���
	//ENDPOINT(API_M_PUT, "/sample", modifySample, BODY_DTO(SampleDTO::Wrapper, dto)) {
	//	// ��Ӧ���
	//	API_HANDLER_RESP_VO(execModifySample(dto));
	//}
	//// 3.1 ����ɾ���ӿ�����
	//ENDPOINT_INFO(removeSample) {
	//	// ����ӿڱ���
	//	info->summary = ZH_WORDS_GETTER("sample.delete.summary");
	//	// ������Ӧ������ʽ
	//	API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	//}
	//// 3.2 ����ɾ���ӿڴ���
	//ENDPOINT(API_M_DEL, "/sample", removeSample, BODY_DTO(SampleDTO::Wrapper, dto)) {
	//	// ��Ӧ���
	//	API_HANDLER_RESP_VO(execRemoveSample(dto));
	//}

	//// [����] ����һ�����ļ��ϴ��ӿ�
	//ENDPOINT(API_M_POST, "/upload", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
	//	/* ����multipart���� */
	//	auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
	//	/* ����multipart��ȡ�� */
	//	multipart::Reader multipartReader(multipartContainer.get());
	//	/* ���ö�ȡ����ȡ���ֶ� */
	//	multipartReader.setPartReader("nickname", multipart::createInMemoryPartReader(-1 /* max-data-size */));
	//	multipartReader.setPartReader("age", multipart::createInMemoryPartReader(-1 /* max-data-size */));
	//	/* ���ö�ȡ����ȡ�ļ����ļ� */
	//	multipartReader.setPartReader("file", multipart::createFilePartReader("public/static/file/test.png"));
	//	/* ��ȡ�������е����� */
	//	request->transferBody(&multipartReader);
	//	/* ��ӡpart���� */
	//	OATPP_LOGD("Multipart", "parts_count=%d", multipartContainer->count());
	//	/* ��ȡ������ */
	//	auto nickname = multipartContainer->getNamedPart("nickname");
	//	auto age = multipartContainer->getNamedPart("age");
	//	/* ���Ա������Ƿ���ȷ */
	//	OATPP_ASSERT_HTTP(nickname, Status::CODE_400, "nickname is null");
	//	OATPP_ASSERT_HTTP(age, Status::CODE_400, "age is null");
	//	/* ��ӡӦ������ */
	//	OATPP_LOGD("Multipart", "nickname='%s'", nickname->getPayload()->getInMemoryData()->c_str());
	//	OATPP_LOGD("Multipart", "age='%s'", age->getPayload()->getInMemoryData()->c_str());
	//	/* ��ȡ�ļ����� */
	//	auto filePart = multipartContainer->getNamedPart("file");
	//	/* �����ļ��Ƿ��ȡ�� */
	//	OATPP_ASSERT_HTTP(filePart, Status::CODE_400, "file is null");
	//	/* ��ӡ�ļ����� */
	//	OATPP_LOGD("Multipart", "file='%s'", filePart->getFilename()->c_str());
	//	/* ��ӦOK */
	//	return createResponse(Status::CODE_200, "OK");
	//}
	//// [����] ����һ�����ļ��ϴ��ӿ�
	//ENDPOINT(API_M_POST, "/upload-more", uploadFileMore, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
	//	/* ����multipart���� */
	//	auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
	//	/* ����multipart��ȡ�� */
	//	multipart::Reader multipartReader(multipartContainer.get());
	//	/* ���ö�ȡ����ȡ�ļ����ļ� */
	//	multipartReader.setPartReader("file0", multipart::createFilePartReader("public/static/file/test1.png"));
	//	multipartReader.setPartReader("file1", multipart::createFilePartReader("public/static/file/test2.png"));
	//	/* ��ȡ�������е����� */
	//	request->transferBody(&multipartReader);
	//	/* ��ȡ�ļ����� */
	//	auto file0 = multipartContainer->getNamedPart("file0");
	//	auto file1 = multipartContainer->getNamedPart("file1");
	//	/* �����ļ��Ƿ��ȡ�� */
	//	OATPP_ASSERT_HTTP(file0, Status::CODE_400, "file0 is null");
	//	OATPP_ASSERT_HTTP(file1, Status::CODE_400, "file1 is null");
	//	/* ��ӦOK */
	//	return createResponse(Status::CODE_200, "OK");
	//}
private:
	// 3.3 ��ʾ��ҳ��ѯ����
	AssignInfoQueryJsonVO::Wrapper execAssignQuery(const AssignInfoQuery::Wrapper& query, const PayloadDTO& payload);
	//// 3.3 ��ʾ��������
	//Uint64JsonVO::Wrapper execAddSample(const SampleDTO::Wrapper& dto);
	//// 3.3 ��ʾ�޸�����
	//Uint64JsonVO::Wrapper execModifySample(const SampleDTO::Wrapper& dto);
	//// 3.3 ��ʾɾ������
	//Uint64JsonVO::Wrapper execRemoveSample(const SampleDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_