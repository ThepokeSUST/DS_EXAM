#include <iostream>
#include <limits>
#include <list>
using namespace std;

class stack
{

    list<int> ls;

public:
    int size;
    stack()
    {
        this->size = 0;
    }
    void push(int);
    void pop();
    int top();
    bool empty();
};

void stack::push(int ele)
{

    ls.push_front(ele);
    size++;
}

void stack::pop()
{
    if (size == 0)
        return;
    ls.pop_front();
    size--;
}

int stack::top()
{
    if (size == 0)
        // if i user "return INT_MIN" it does not work......why?
        return 0;
    return *ls.begin();
}
bool stack::empty()
{
    return size == 0;
}

int main()
{
    stack s;
    s.push(8);
    s.push(9);
    s.push(90);
    s.push(10);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}