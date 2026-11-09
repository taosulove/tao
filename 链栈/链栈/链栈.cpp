#include <iostream>
using namespace std;

typedef int DataType;
struct LinkStack
{
	DataType data;
	LinkStack* next;
};
// 初始化空链栈：返回栈顶指针
LinkStack* initLinkStack()
{
	return nullptr;
}
//判断栈是否为空
bool StackEmpty(LinkStack* top)
{
	return top == nullptr;
}
//入栈
bool Push(LinkStack*& top, DataType val)
{
	LinkStack* newNode = new LinkStack;
	if (!newNode)
		return false;
	newNode->data = val;
	newNode->next = top;
	top = newNode;
	return true;
}
//出栈
bool Pop(LinkStack*& top, DataType& val)
{
	if (StackEmpty(top))
		return false;
	LinkStack* p = top;
	top = top->next;
	val = p->data;
	delete p;
	return true;
}
//获取栈顶元素
bool GetTop(LinkStack* top, DataType& val)
{
	if (StackEmpty(top))
		return false;
	val = top->data;
	return true;
}
int main()
{
	LinkStack* st = initLinkStack();
	int x;
	Push(st, 10);
	Push(st, 20);
	GetTop(st, x);
	cout << "栈顶: " << x << endl;
	Pop(st, x);
	cout << "弹出: " << x << endl;
	if (StackEmpty(st))
	{
		cout << "栈为空" << endl;
	}
	else
	{
		cout << "栈不为空" << endl;
	}
	return 0;
}
