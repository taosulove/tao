#include <iostream>
#include <cstring>
using namespace std;
struct Birthday
{
	int year;
	int month;
	int day;
};
struct Contact
{
	char name[20];
	char phone[12];
	Birthday birthday;
	int age;
};
struct Node
{
	Contact data;
	Node* next;
};
void menu()
{
	cout << "1.添加联系人" << endl;
	cout<<"2.显示所有联系人" << endl;
	cout << "3.按姓名查找联系人" << endl;
	cout << "4.按姓名删除联系人" << endl;
	cout << "5.修改联系人信息" << endl;
	cout << "6.退出" << endl;
	cout << "请选择功能(1-6):";
}
void addContact(Node*& head)
{
	Node* newNode = new Node;
	newNode->next = nullptr;
	cout << "请输入姓名:";
	cin >> newNode->data.name;
	cout << "请输入电话:";
	cin >> newNode->data.phone;
	cout << "请输入生日(年 月 日):";
	cin >> newNode->data.birthday.year >> newNode->data.birthday.month >> newNode->data.birthday.day;
	cout << "请输入年龄:";
	cin >> newNode->data.age;
	newNode->next = head;

  if (head == nullptr)
  {
	head = newNode;
  }
  else
  {
	Node* p = head;
	while (p->next != nullptr)
	{
		p = p->next;
	}
	p->next = newNode;
  }
  cout << "联系人添加成功!" << endl;
}
void showAll(Node* head)
{
	if (head == nullptr)
	{
		cout << "通讯录为空!" << endl;
		return;
	}
	Node* p = head;
	int num = 1;
	while (p != nullptr)
	{
		cout << "姓名:" << p->data.name << endl;
		cout << "电话:" << p->data.phone << endl;
		cout << "生日:" << p->data.birthday.year << "年" << p->data.birthday.month << "月" << p->data.birthday.day << "日" << endl;
		cout << "年龄:" << p->data.age << endl;
		cout << "-------------------------" << endl;
		p = p->next;
		num++;
	}
}
Node* findContact(Node* head, char* findName)
{
	Node* p = head;
	while (p != nullptr&&strcmp(p->data.name, findName) != 0)
	{
	    p = p->next;
	}
	return p;
}
void deleteContact(Node*& head, char delName[])
{
	if (head == nullptr)
	{
		cout << "通讯录为空,无法删除!" << endl;
		return;
	}
	Node* p = head;
	Node* pre = nullptr;
	while (p != nullptr && strcmp(p->data.name, delName) != 0)
	{
		pre = p;
		p = p->next;
	}
	if (p == nullptr)
	{
		cout << "未找到联系人!" << endl;
		return;
	}
	if (pre == nullptr)
	{
		head = head->next;
	}
	else
	{
		pre->next = p->next;
	}
	delete p;
	cout << "联系人删除成功!" << endl;
}
void modifyContact(Node* head, char modName[])
{
	Node* target = findContact(head, modName);
	if (target == nullptr)
	{
		cout << "未找到联系人!" << endl;
		return;
	}
	cout << "请输入新的电话:";
	cin >> target->data.phone;
	cout << "请输入新的生日(年 月 日):";
	cin >> target->data.birthday.year >> target->data.birthday.month >> target->data.birthday.day;
	cout << "请输入新的年龄:";
	cin >> target->data.age;
	cout << "联系人信息修改成功!" << endl;
}
void freeList(Node*& head)
{
	Node* p = head;
	while (p != nullptr)
	{
		Node* temp = p;
		p = p->next;
		delete temp;
	}
	head = nullptr;
}	
int main()
{ 
	Node *head = nullptr;
	int choice;
	char nameBuf[50];
	while (true)
	{
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			addContact(head);
			break;
		case 2:
			showAll(head);
			break;
		case 3:
			cout << "请输入要查找的姓名:";
			cin >> nameBuf;
			if (findContact(head, nameBuf) != nullptr)
			{
				cout << "联系人存在!" << endl;
			}
			else
			{
				cout << "未找到联系人!" << endl;
			}
			break;
		case 4:
			cout << "请输入要删除的姓名:";
			cin >> nameBuf;
			deleteContact(head, nameBuf);
			break;
		case 5:
			cout << "请输入要修改的姓名:";
			cin >> nameBuf;
			modifyContact(head, nameBuf);
			break;
		case 6:
			freeList(head);
			cout << "退出程序!" << endl;
			return 0;
		default:
			cout << "无效的选择,请重新输入!" << endl;
		}
		cout << "-------------------------" << endl;
	}
	return 0;
}