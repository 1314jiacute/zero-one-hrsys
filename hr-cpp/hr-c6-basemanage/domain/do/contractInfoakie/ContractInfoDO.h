#ifndef _CONTRACTINFODO_
#define _CONTRACTINFODO_
#include "../DoInclude.h"
#include "../hr-sample/Macros.h"
class ContractInfoDO
{
	// 1Ա�����t_pimperson.YGBH
	CC_SYNTHESIZE(string, id, Id);
	// 2Ա������t_pimperson.PIMPERSONNAME
	CC_SYNTHESIZE(string, name, Name);
	//3��ͬ���t_pimcontract.HTLX
	CC_SYNTHESIZE(string, type, Type);
	//4��ͬ����t_pimcontract.CONTRACTTYPE
	CC_SYNTHESIZE(string, variety, Variety);
	//5��ʼ����t_pimcontract.QSRQ
	CC_SYNTHESIZE(string, date, Date);
	//6��ͬ״̬t_pimcontract.HTZT
	CC_SYNTHESIZE(string, condition, Condition);
	//7Ա��������λt_pimcontract.ORMORGNAME
	CC_SYNTHESIZE(string, department_m, Department_m);
	//8��ͬǩ����λt_pimcontract.LEGALORG
	CC_SYNTHESIZE(string, department_c, Department_c);
	//9���õ���ʱ��t_pimcontract.SYDQSJ
	CC_SYNTHESIZE(string, try_end, Try_end);
	//10��עt_pimcontract.DEMO
	CC_SYNTHESIZE(string, tip, Tip);
	//11Ա����Ϣ��ʶt_pimcontract.PIMCONTRACTID (key)
	CC_SYNTHESIZE(string, infoid, Infoid);
	//12��ͬ��������t_pimcontract.JSRQ
	CC_SYNTHESIZE(string, date_end, Date_end);
	//13��ͬ���t_pimcontract.HTBH
	CC_SYNTHESIZE(string, contract_num, Contract_num);
	//14Ա��״̬t_pimperson.YGZT
	CC_SYNTHESIZE(string, emp_condition, Emp_condition);
public:
	ContractInfoDO() {
		id = "";
		name = "";
		type = "";
		variety = "";
		date = "";
		condition = "";
		department_m = "";
		department_c = "";
		try_end = "";
		tip = "";
		infoid = "";
		date_end = "";
		contract_num = "";
		emp_condition = "";
	}
};





#endif