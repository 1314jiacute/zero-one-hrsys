#ifndef _Import_Assign_Info_CONTROLLER_
#define _Import_Assign_Info_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "domain/dto/assignInfo/ImportAssignInfoDTO.h"
#include "domain/vo/assignInfo/ImportAssignInfoVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) // 0

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class ImportAssignInfoController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ImportAssignInfoController);
	// 3 ����ӿ�
public:
	// [����] ����һ�����ļ��ϴ��ӿ�
	ENDPOINT(API_M_POST, "/upload-assignInfo", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		/* ����multipart���� */
		auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
		/* ����multipart��ȡ�� */
		multipart::Reader multipartReader(multipartContainer.get());
		/* ���ö�ȡ����ȡ���ֶ� */
		multipartReader.setPartReader("id", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("assign", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("type", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("organize", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("depart", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("job", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("post", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("start-time", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("end-time", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		/* ���ö�ȡ����ȡ�ļ����ļ� */
		multipartReader.setPartReader("file", multipart::createFilePartReader("public/static/file/test.png"));
		/* ��ȡ�������е����� */
		request->transferBody(&multipartReader);
		/* ��ӡpart���� */
		OATPP_LOGD("Multipart", "parts_count=%d", multipartContainer->count());
		/* ��ȡ������ */
		auto id = multipartContainer->getNamedPart("id");
		auto assign = multipartContainer->getNamedPart("assign");
		auto Etype = multipartContainer->getNamedPart("Etype");
		auto organize = multipartContainer->getNamedPart("organize");
		auto depart = multipartContainer->getNamedPart("depart");
		auto job = multipartContainer->getNamedPart("job");
		auto post = multipartContainer->getNamedPart("post");
		auto startTime = multipartContainer->getNamedPart("startTime");
		auto endTime = multipartContainer->getNamedPart("endTime");
		/* ���Ա������Ƿ���ȷ */
		OATPP_ASSERT_HTTP(id, Status::CODE_400,  "id is null");
		OATPP_ASSERT_HTTP(assign, Status::CODE_400, "assign is null");
		OATPP_ASSERT_HTTP(Etype, Status::CODE_400, "Etype is null");
		OATPP_ASSERT_HTTP(organize, Status::CODE_400, "organize is null");
		OATPP_ASSERT_HTTP(depart, Status::CODE_400, "depart is null");
		OATPP_ASSERT_HTTP(job, Status::CODE_400, "job is null");
		OATPP_ASSERT_HTTP(post, Status::CODE_400, "post is null");
		OATPP_ASSERT_HTTP(startTime, Status::CODE_400, "startTime is null");
		OATPP_ASSERT_HTTP(endTime, Status::CODE_400, "endTime is null");
		/* ��ӡӦ������ */
		OATPP_LOGD("Multipart", "id='%s'", id->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "assign='%s'", assign->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "Etype='%s'", Etype->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "organize='%s'", organize->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "depart='%s'", depart->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "job='%s'", job->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "post='%s'", post->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "startTime='%s'", startTime->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "endTime='%s'", endTime->getPayload()->getInMemoryData()->c_str());
		/* ��ȡ�ļ����� */
		auto filePart = multipartContainer->getNamedPart("file");
		/* �����ļ��Ƿ��ȡ�� */
		OATPP_ASSERT_HTTP(filePart, Status::CODE_400, "file is null");
		/* ��ӡ�ļ����� */
		OATPP_LOGD("Multipart", "file='%s'", filePart->getFilename()->c_str());
		/* ��ӦOK */
		return createResponse(Status::CODE_200, "OK");
	}
private:
	ImportAssignInfoJsonVO::Wrapper execImportAssignInfo(const ImportAssignInfoDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_Import_Assign_Info_CONTROLLER_