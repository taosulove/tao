#include <iostream>
#include <string>
using namespace std;

// 链栈结点
typedef char ElemType;
struct LinkStack
{
    ElemType data;
    LinkStack* next;
};

LinkStack* InitStack()
{
    return nullptr;
}

bool StackEmpty(LinkStack* top)
{
    return top == nullptr;
}

bool Push(LinkStack*& top, ElemType val)
{
    LinkStack* newNode = new LinkStack;
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    return true;
}

bool Pop(LinkStack*& top, ElemType& val)
{
    if (StackEmpty(top)) return false;
    LinkStack* p = top;
    val = p->data;
    top = top->next;
    delete p;
    return true;
}

bool GetTop(LinkStack* top, ElemType& val)
{
    if (StackEmpty(top)) return false;
    val = top->data;
    return true;
}

bool isValid(string s)
{
    LinkStack* st = InitStack();
    char ch;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            Push(st, c);
        }
        else
        {
            if (StackEmpty(st)) return false;
            GetTop(st, ch);
            if ((c == ')' && ch == '(') || (c == ']' && ch == '[') || (c == '}' && ch == '{'))
            {
                Pop(st, ch);
            }
            else
            {
                return false;
            }
        }
    }
    return StackEmpty(st);
}

int main()
{
    cout << "===== 链栈测试 =====" << endl;
    LinkStack* st = InitStack();
    char tmp;
    Push(st, '5');
    Push(st, '9');
    GetTop(st, tmp);
    cout << "栈顶：" << tmp << endl;
    Pop(st, tmp);
    cout << "弹出：" << tmp << endl;

    cout << "\n===== 括号匹配 =====" << endl;
    string a = "{[()]}";
    string b = "{[(])}";
    cout << boolalpha;
    cout << a << " : " << isValid(a) << endl;
    cout << b << " : " << isValid(b) << endl;
    return 0;
}
