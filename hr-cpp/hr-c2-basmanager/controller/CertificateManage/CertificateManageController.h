#ifndef _CERTIFICATEMANAGE_CONTROLLER_
#define _CERTIFICATEMANAGE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/sample/SampleQuery.h"
#include "domain/dto/sample/SampleDTO.h"
#include "domain/vo/sample/SampleVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ֤����������
 */

class CertificateManageController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(CertificateManageController);
};