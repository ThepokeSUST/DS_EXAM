#include <iostream>
#include <vector>
using namespace std;

class Stack
{

public:
    vector<int> vec;
    int top1;
    int top2;
    int size;
    Stack(int n)
    {
        vec.resize(n);
        top1 = -1;
        top2 = n;
        size = n;
    }

    void push1(int ele)
    {
        if (top1 + 1 == top2)
            return;

        top1++;
        vec[top1] = ele;
        return;
    }
    void push2(int ele)
    {

        if (top2 - 1 == top1)
            return;

        top2--;
        vec[top2] = ele;
        return;
    }
    int gettop1()
    {
        if (top1 == -1)
            return -1;
        return vec[top1];
    }
    int gettop2()
    {
        if (top2 == size)
            return -1;

        return vec[top2];
    }

    void pop1()
    {
        if (top1 == -1)
            return;
        top1--;
        return;
    }
    void pop2()
    {
        if (top2 == size)
            return;

        top2++;
        return;
    }
};

int main()
{
    Stack s(5);
    s.push1(4);
    s.push1(7);
    s.push2(9);
    cout << s.gettop1() << endl
         << s.gettop2() << endl;
    s.pop1();
    cout << s.gettop1() << endl
         << s.gettop2() << endl;
    s.pop2();
    cout << s.gettop1() << endl
         << s.gettop2();
}