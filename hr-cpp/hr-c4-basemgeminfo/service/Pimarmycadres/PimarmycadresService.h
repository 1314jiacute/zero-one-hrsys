#pragma once
/*
 Copyright Zero One Star. All rights reserved.
#include "domain/vo/work-history/ModWorkHistoryVO.h"
#include "domain/vo/work-history/WorkHistoryVO.h"
#include "domain/query/work-history/WorkHistoryQuery.h"
#include "domain/dto/work-history/ModWorkHistoryDTO.h"
#include "domain/dto/work-history/WorkHistoryDTO.h"
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _PIMARMYCADRESSERVICE_H_
#define _PIMARMYCADRESSERVICE_H_

#include "domain/dto/Pimarmycadres/PimarmycadresFindDTO.h"
#include "domain/dto/Pimarmycadres/AddPimarmycadresDTO.h"
#include "domain/dto/Pimarmycadres/DelPimarmycadresDTO.h"
#include "domain/query/Pimarmycadres/PimarmycadresPageQuery.h"
#include "domain/dto/Pimarmycadres/PimarmycadresIntoDTO.h"
#include "domain/query/Pimarmycadres/PimarmycadresQuery.h"
#include"D:\big��Ŀ\zero-one-hrsys\hr-cpp\lib-oatpp\include\oatpp\web\server\api\ApiController.hpp"
#include"../lib-oatpp/include/oatpp/web/server/api/ApiController.hpp"
#include <oatpp/web/client/ApiClient.hpp>
#include <oatpp/web/client/ApiClient.hpp>
class PimarmycadresService
{
public:
	// ��ҳ��ѯ��������	
	PimarmycadresFindPageDTO::Wrapper listAll(const PimarmycadresPageQuery::Wrapper& query);

	// ����һ������
	uint64_t saveData(const AddPimarmycadresDTO::Wrapper& dto);


	//ɾ������(֧������ɾ��)
	bool removeData(const DelPimarmycadresDTO::Wrapper& dto);


	//ִ�е��루�������������ݣ�
	uint64_t saveManyData(const oatpp::String& fileBody, const oatpp::String& suffix, const oatpp:: String& pimpersonid);

	//�б���ϸ
	PimarmycadresDTO::Wrapper listDetail(const PimarmycadresQuery::Wrapper& query);

	bool updateData(const PimarmycadresDTO::Wrapper& dto);
};

#endif 