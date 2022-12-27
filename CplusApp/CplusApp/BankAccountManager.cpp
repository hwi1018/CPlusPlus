
#include "Customer.h"

using namespace BEHAVIOR;
using namespace std;

void ShowMenu(void);
int SelectMenu(int index);
void MakeBankAccount(void);
void DepositMoney(void);
void WithdrawalMoney(void);
void PrintTotalAccount(void);

Account* customer[100]; //동적할당 필요
int cusNum = 0;

int main(int argc, char* argv[])
{
	int num = 0;
	int retNum = 0;

	while (retNum != -1)
	{
		ShowMenu();
		cout << "선택: ";cin >> num;

		cout << "\n";
		retNum = SelectMenu(num); // 메뉴 선택
		cout << "\n";
	}

	return 0;
}

void ShowMenu(void)
{
	cout << "-----" << "Menu" << "-----" << "\n";
	cout << "1. 계좌개설" << "\n";
	cout << "2. 입 금" << "\n";
	cout << "3. 출 금" << "\n";
	cout << "4. 계좌정보 전체 출력" << "\n";
	cout << "5. 프로그램 종료" << "\n";
}

int SelectMenu(int num)
{
	switch (num)
	{
	case CREATE:
		MakeBankAccount();
		break;
	case DEPOSIT:
		DepositMoney();
		break;
	case WITHDRAWAL:
		WithdrawalMoney();
		break;
	case PRINTTOTAL:
		PrintTotalAccount();
		break;
	case EXIT:
		for (int i = 0; i < cusNum; i++)
		{
			delete customer[i];
		}
		return -1;
		break;
	default:
		break;
	}
	return 0;
}

void MakeBankAccount()
{
	int bankID;
	char name[20];
	int money;

	cout << "[계좌개설]" << "\n";
	cout << "계좌ID: "; cin >> bankID;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> money;

	customer[cusNum] = new Account(bankID, money, name);
	cusNum++;
}

void DepositMoney()
{
	int bankID;
	int money;

	cout << "[입  금]" << "\n";
	cout << "계좌ID: "; cin >> bankID;
	cout << "입금액: "; cin >> money;
	
	for (int i = 0; i < cusNum; i++)
	{
		if (customer[i]->GetID() == bankID)
		{
			customer[i]->DepositMoney(money);
		}
	}
	cout << "입금완료" << "\n";
}

void WithdrawalMoney()
{
	int bankID;
	int money;

	cout << "[출  금]" << "\n";
	cout << "계좌ID: "; cin >> bankID;
	cout << "출금액: "; cin >> money;

	for (int i = 0; i < cusNum; i++)
	{
		if (customer[i]->GetID() == bankID)
		{
			if(customer[i]->WithdrawalMoney(money) != -1)
			{
				cout << "출금완료" << "\n";
			}
			else 
			{
				cout << "출금하기 위한 잔액이 부족합니다." << "\n";
				cout << "다시 시도해주세요!." << "\n";
				return; //출금하지 못하기 때문에 return;
			}

		}
	}
}

void PrintTotalAccount()
{
	for (int i = 0; i < cusNum; i++)
	{
		customer[i]->PrintAccount();
		cout << "\n";
	}
}
