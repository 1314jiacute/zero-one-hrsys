/*
 Copyright Muggle. All rights reserved.

 @Author: Muggle
 @Date: 2023/05/26 23:20:04

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _EXPENSELEDGER_DTO_
#define _EXPENSELEDGER_DTO_
#include "../../GlobalInclude.h"
#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����̨�˴������
 */
class ExpenseLedgerDTO : public oatpp::DTO
{
	DTO_INIT(ExpenseLedgerDTO, DTO);

	// ����̨������
	DTO_FIELD(String, pimexpaccountname);
	DTO_FIELD_INFO(pimexpaccountname) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.PIMEXPACCOUNTNAME");
	}
	// ����̨�˱�ʶ
	DTO_FIELD(String, pimexpaccountid);
	DTO_FIELD_INFO(pimexpaccountid) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.PIMEXPACCOUNTID");
	}
	// ������
	DTO_FIELD(String, updateman);
	DTO_FIELD_INFO(updateman) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.UPDATEMAN");
	}
	// ����ʱ��
	DTO_FIELD(String, createdate);
	DTO_FIELD_INFO(createdate) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.CREATEDATE");
	}
	// ������
	DTO_FIELD(String, createman);
	DTO_FIELD_INFO(createman) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.CREATEMAN");
	}
	// ����ʱ��
	DTO_FIELD(String, updatedate);
	DTO_FIELD_INFO(updatedate) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.UPDATEDATE");
	}
	// �������
	DTO_FIELD(String, fylb);
	DTO_FIELD_INFO(fylb) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.FYLB");
	}
	// ���ý��
	DTO_FIELD(Float32, fyje);
	DTO_FIELD_INFO(fyje) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.FYJE");
	}
	// ��������
	DTO_FIELD(Int32, ffrs);
	DTO_FIELD_INFO(ffrs) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.FFRS");
	}
	// ����ʱ��
	DTO_FIELD(String, ffsj);
	DTO_FIELD_INFO(ffsj) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.FFSJ");
	}
	// ���ñ�׼
	DTO_FIELD(String, ffybz);
	DTO_FIELD_INFO(ffybz) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.FFYBZ");
	}
	// ��ע
	DTO_FIELD(String, bz);
	DTO_FIELD_INFO(bz) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.BZ");
	}
};
/**
 * ����̨�˷�ҳ�������
 */
class ExpenseLedgerPageDTO : public PageDTO< ExpenseLedgerDTO::Wrapper>
{
	DTO_INIT(ExpenseLedgerPageDTO, PageDTO< ExpenseLedgerDTO::Wrapper>);
};
#endif