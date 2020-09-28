/*************************************************************************
	> File Name: Calculate.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月19日 星期三 10时29分35秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

struct Item
{
    char op = '\0';
    int number = 0;

    Item() {}
    Item(char theOp) :op{ theOp } {}
};

void Run(stack<Item>& items)
{
    auto second = items.top();
    items.pop();
    auto& first = items.top().number;
    switch (second.op)
    {
    case '+':
        first += second.number;
        break;
    case '-':
        first -= second.number;
        break;
    case '*':
        first *= second.number;
        break;
    case '/':
        first /= second.number;
        break;
    }
}

int Pop(stack<Item>& items)
{
    while (items.top().op != '\0')
    {
        Run(items);
    }
    auto number = items.top().number;
    items.pop();
    return number;
}

void Push(stack<Item>& items, int number)
{
    items.top().number = number;
    switch (items.top().op)
    {
    case '*':case '/':
        Run(items);
    }
}

int Calculate(string text)
{
    stringstream ss(text);
    stack<Item> items;
    items.push({});

    while (true)
    {
        char op = ss.peek();
        switch (op)
        {
        case '(':
            /*1*/
            items.push({});
            break;
        case ')':
            Push(items, Pop(items));
            break;
        case '+':case '-':case '*':case '/':
            items.push({op});
            break;
        }

        if (isdigit(op))
        {
            int number;
            ss >> number;
            Push(items, number);
        }
        else if (ss.eof())
        {
            return Pop(items);
        }
        else
        {
            ss.ignore();
        }
    }
}

int main()
{
    cout << Calculate("1") << endl;
    cout << Calculate("1+2") << endl;
    cout << Calculate("1+2*3+4") << endl;
    cout << Calculate("(11+22)*(33+44)") << endl;
    return 0;
}
