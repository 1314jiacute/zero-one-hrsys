#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/17 16:45:32

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
#ifndef _POSTDETAIL_DTO_
#define _POSTDETAIL_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��λ�������
 */
class PostDetailDTO : public oatpp::DTO
{
	DTO_INIT(PostDetailDTO, DTO);
	// ��λ����ʶ
	DTO_FIELD(String, ormPostId);
	DTO_FIELD_INFO(ormPostId) {
		info->description = ZH_WORDS_GETTER("��λ����ʶ");
	}
	// ��λ������
	DTO_FIELD(String, ormPostName);
	DTO_FIELD_INFO(ormPostName) {
		info->description = ZH_WORDS_GETTER("��λ������");
	}
	// ������
	DTO_FIELD(String, createMan);
	DTO_FIELD_INFO(createMan) {
		info->description = ZH_WORDS_GETTER("������");
	}
	// ����ʱ��
	DTO_FIELD(String, updateDate);
	DTO_FIELD_INFO(updateDate) {
		info->description = ZH_WORDS_GETTER("����ʱ��");
	}
	// ������
	DTO_FIELD(String, updateMan);
	DTO_FIELD_INFO(updateMan) {
		info->description = ZH_WORDS_GETTER("������");
	}
	// ����ʱ��
	DTO_FIELD(String, createDate);
	DTO_FIELD_INFO(createDate) {
		info->description = ZH_WORDS_GETTER("����ʱ��");
	}
	// ������
	DTO_FIELD(UInt64, xh);
	DTO_FIELD_INFO(xh) {
		info->description = ZH_WORDS_GETTER("������");
	}
	// �ڲ���֯������ʶ
	DTO_FIELD(String, orgId);
	DTO_FIELD_INFO(orgId) {
		info->description = ZH_WORDS_GETTER("�ڲ���֯������ʶ");
	}
	// ��֪��
	DTO_FIELD(UInt64, lgnx);
	DTO_FIELD_INFO(lgnx) {
		info->description = ZH_WORDS_GETTER("lgnx");
	}
	// ��֪��
	DTO_FIELD(UInt64, qzlgnx);
	DTO_FIELD_INFO(qzlgnx) {
		info->description = ZH_WORDS_GETTER("qzlgnx");
	}
	// ��λ����
	DTO_FIELD(String, gwType);
	DTO_FIELD_INFO(gwType) {
		info->description = ZH_WORDS_GETTER("��λ����");
	}
	// ��λ����
	DTO_FIELD(String, gwfl);
	DTO_FIELD_INFO(gwfl) {
		info->description = ZH_WORDS_GETTER("��λ����");
	}
	// �Ƿ��ܸ�
	DTO_FIELD(String, isConfidential);
	DTO_FIELD_INFO(isConfidential) {
		info->description = ZH_WORDS_GETTER("�Ƿ��ܸ�");
	}
	// �Ƿ���ʱ����
	DTO_FIELD(String, isTemp);
	DTO_FIELD_INFO(isTemp) {
		info->description = ZH_WORDS_GETTER("�Ƿ���ʱ����");
	}
	// ���齻������
	DTO_FIELD(UInt64, nx);
	DTO_FIELD_INFO(nx) {
		info->description = ZH_WORDS_GETTER("���齻������");
	}
	// ���뽻������
	DTO_FIELD(UInt64, bxjlnx);
	DTO_FIELD_INFO(bxjlnx) {
		info->description = ZH_WORDS_GETTER("���뽻������");
	}
	// �Ƿ�ؼ���λ
	DTO_FIELD(String, isKeyPostion);
	DTO_FIELD_INFO(isKeyPostion) {
		info->description = ZH_WORDS_GETTER("�Ƿ�ؼ���λ");
	}
	// ��λ����
	DTO_FIELD(String, postNature);
	DTO_FIELD_INFO(postNature) {
		info->description = ZH_WORDS_GETTER("��λ����");
	}
	// ���ñ�ʶ
	DTO_FIELD(String, startStopSign);
	DTO_FIELD_INFO(startStopSign) {
		info->description = ZH_WORDS_GETTER("���ñ�ʶ");
	}
	// �ⲿ��֯������ʶ
	DTO_FIELD(String, ormOrgId);
	DTO_FIELD_INFO(ormOrgId) {
		info->description = ZH_WORDS_GETTER("�ⲿ��֯������ʶ");
	}
	// ��֯��������(���ݿ���ΪORGNAME,��������Ϊormorgname)
	DTO_FIELD(String, ormOrgName);
	DTO_FIELD_INFO(ormOrgName) {
		info->description = ZH_WORDS_GETTER("��֯��������");
	}
};

/**
 * ��λ�����ҳ�������
 */
class PostDetailPageDTO : public PageDTO<PostDetailDTO::Wrapper>
{
	DTO_INIT(PostDetailPageDTO, PageDTO<PostDetailDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_POSTDETAIL_DTO_