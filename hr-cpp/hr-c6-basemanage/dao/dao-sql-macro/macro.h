#pragma once
#ifndef _MACRO_H_
#define _MACRO_H_

// ���string�����ֶ�
// Ҫ�����ݿ��ֶα���������ֶ�һ��
#define SQLPARAMS_STRING_PUSH(SQL_field) \
if (query->SQL_field) { \
	sql << " AND `" #SQL_field "`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->SQL_field.getValue("")); \
}

// ���int�����ֶ�
// Ҫ�����ݿ��ֶα���������ֶ�һ��
#define SQLPARAMS_INT_PUSH(SQL_field)	\
if (query->SQL_field) { \
	sql << " AND `" #SQL_field "`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->SQL_field.getValue(0)); \
}

// ���double�����ֶ�
// Ҫ�����ݿ��ֶα���������ֶ�һ��
#define SQLPARAMS_FLOAT_PUSH(SQL_field)		\
if (query->SQL_field) { \
	sql << " AND `" #SQL_field "`=?"; \
	SQLPARAMS_PUSH(params, "d", double, query->SQL_field.getValue(0.0)); \
}
#endif // !_MACRO_H_