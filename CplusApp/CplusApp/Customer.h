#pragma once
#include <cstring>
#include <iostream>

namespace BEHAVIOR
{
	enum {
		CREATE = 1,
		DEPOSIT,
		WITHDRAWAL,
		PRINTTOTAL,
		EXIT
	};
}

class Account
{
private:
	int id;
	char* name;
	int balance;

public:
	Account(int id, int money, char* name);
	~Account();
	int GetID(void) const;
	void DepositMoney(int money);
	int WithdrawalMoney(int money);
	void PrintAccount(void);
};