#include <iostream>
#include <limits>
#include <vector>
using namespace std;
const int N = 1e5;
class stack
{

public:
    vector<int> vec;
    int size;

    stack()
    {
        size = -1;
        vec.resize(N);
    }

    void push(int ele)
    {
        size++;
        vec[size] = ele;
    }
    void pop()
    {
        if (size < 0)
            return;
        size--;
    }
    int top()
    {
        if (size < 0)
            return -1;
        return vec[size];
    }
    bool empty()
    {
        if (size < 0)
            return true;
        return false;
    }
};

int main()
{
    stack st;
    st.push(8);
    st.push(4);
    st.push(9);
    st.push(3);

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    st.push(1);
    cout << endl;
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
}