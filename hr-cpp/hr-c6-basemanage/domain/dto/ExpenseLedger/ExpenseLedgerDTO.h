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

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����̨�˴������
 */
class ExpenseLedgerDTO : public oatpp::DTO
{
	DTO_INIT(ExpenseLedgerDTO, DTO);

	// ����̨������
	DTO_FIELD(String, PIMEXPACCOUNTNAME);
	DTO_FIELD_INFO(PIMEXPACCOUNTNAME) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.PIMEXPACCOUNTNAME");
	}
	// ����̨�˱�ʶ
	DTO_FIELD(String, PIMEXPACCOUNTID);
	DTO_FIELD_INFO(PIMEXPACCOUNTID) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.PIMEXPACCOUNTID");
	}
	// ������
	DTO_FIELD(String, UPDATEMAN);
	DTO_FIELD_INFO(UPDATEMAN) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.UPDATEMAN");
	}
	// ����ʱ��
	DTO_FIELD(String, CREATEDATE);
	DTO_FIELD_INFO(CREATEDATE) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.CREATEDATE");
	}
	// ������
	DTO_FIELD(String, CREATEMAN);
	DTO_FIELD_INFO(CREATEMAN) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.CREATEMAN");
	}
	// ����ʱ��
	DTO_FIELD(String, UPDATEDATE);
	DTO_FIELD_INFO(UPDATEDATE) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.UPDATEDATE");
	}
	// �������
	DTO_FIELD(String, FYLB);
	DTO_FIELD_INFO(FYLB) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.FYLB");
	}
	// ���ý��
	DTO_FIELD(String, FYJE);
	DTO_FIELD_INFO(FYJE) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.FYJE");
	}
	// ��������
	DTO_FIELD(String, FFRS);
	DTO_FIELD_INFO(FFRS) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.FFRS");
	}
	// ����ʱ��
	DTO_FIELD(String, FFSJ);
	DTO_FIELD_INFO(FFSJ) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.FFSJ");
	}
	// ���ñ�׼
	DTO_FIELD(String, FFYBZ);
	DTO_FIELD_INFO(FFYBZ) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.FFYBZ");
	}
	// ��ע
	DTO_FIELD(String, BZ);
	DTO_FIELD_INFO(BZ) {
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