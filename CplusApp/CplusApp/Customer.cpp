
#include "Customer.h"

using namespace std;

Account::Account(int id, int money, char* name)
{
	this->id = id;
	this->balance = money;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Account::~Account()
{
	delete[]name;
}

int Account::GetID(void) const
{
	return this->id;
}

void Account::DepositMoney(int money)
{
	balance += money;
}

int Account::WithdrawalMoney(int money)
{
	if (balance < money)
	{
		return -1;
	}

	balance -= money;

	return balance;

}

void Account::PrintAccount(void)
{
	cout << "����ID: " << this->id << "\n";
	cout << "�̸�: " << this->name << "\n";
	cout << "�� ��: " << this->balance << "\n";
}




