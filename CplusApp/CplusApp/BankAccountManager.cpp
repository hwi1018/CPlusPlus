
#include "Customer.h"

using namespace BEHAVIOR;
using namespace std;

void ShowMenu(void);
int SelectMenu(int index);
void MakeBankAccount(void);
void DepositMoney(void);
void WithdrawalMoney(void);
void PrintTotalAccount(void);

Account* customer[100]; //�����Ҵ� �ʿ�
int cusNum = 0;

int main(int argc, char* argv[])
{
	int num = 0;
	int retNum = 0;

	while (retNum != -1)
	{
		ShowMenu();
		cout << "����: ";cin >> num;

		cout << "\n";
		retNum = SelectMenu(num); // �޴� ����
		cout << "\n";
	}

	return 0;
}

void ShowMenu(void)
{
	cout << "-----" << "Menu" << "-----" << "\n";
	cout << "1. ���°���" << "\n";
	cout << "2. �� ��" << "\n";
	cout << "3. �� ��" << "\n";
	cout << "4. �������� ��ü ���" << "\n";
	cout << "5. ���α׷� ����" << "\n";
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

	cout << "[���°���]" << "\n";
	cout << "����ID: "; cin >> bankID;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> money;

	customer[cusNum] = new Account(bankID, money, name);
	cusNum++;
}

void DepositMoney()
{
	int bankID;
	int money;

	cout << "[��  ��]" << "\n";
	cout << "����ID: "; cin >> bankID;
	cout << "�Աݾ�: "; cin >> money;
	
	for (int i = 0; i < cusNum; i++)
	{
		if (customer[i]->GetID() == bankID)
		{
			customer[i]->DepositMoney(money);
		}
	}
	cout << "�ԱݿϷ�" << "\n";
}

void WithdrawalMoney()
{
	int bankID;
	int money;

	cout << "[��  ��]" << "\n";
	cout << "����ID: "; cin >> bankID;
	cout << "��ݾ�: "; cin >> money;

	for (int i = 0; i < cusNum; i++)
	{
		if (customer[i]->GetID() == bankID)
		{
			if(customer[i]->WithdrawalMoney(money) != -1)
			{
				cout << "��ݿϷ�" << "\n";
			}
			else 
			{
				cout << "����ϱ� ���� �ܾ��� �����մϴ�." << "\n";
				cout << "�ٽ� �õ����ּ���!." << "\n";
				return; //������� ���ϱ� ������ return;
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
