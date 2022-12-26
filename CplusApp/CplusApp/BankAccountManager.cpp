
#include <iostream>

using namespace std;

void ShowMenu(void);
int SelectMenu(int index);
void MakeBankAccount(void);
void DepositMoney(void);
void WithdrawalMoney(void);
void PrintTotalAccount(void);

enum{
	CREATE = 1,
	DEPOSIT,
	WITHDRAWAL,
	PRINTTOTAL,
	EXIT
};

typedef struct {
	int id;
	char name[20];
	int money;
}ACCOUNT;

ACCOUNT customer[100];
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

	customer[cusNum].id = bankID;
	strcpy(customer[cusNum].name, name);
	customer[cusNum].money = money;
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
		if (customer[i].id == bankID)
		{
			customer[i].money += money;
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
		if (customer[i].id == bankID)
		{
			if (customer[i].money >= money)
			{
				customer[i].money -= money;

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
		cout << "����ID: " << customer[i].id << "\n";
		cout << "�̸�: " << customer[i].name << "\n";
		cout << "�� ��: " << customer[i].money << "\n";
		cout << "\n";
	}
}
