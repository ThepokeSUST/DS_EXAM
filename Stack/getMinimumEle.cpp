#include <iostream>
#include <stack>

using namespace std;

class solution
{

    stack<int> st;
    stack<int> mn;

public:
    void push(int ele)
    {

        if (st.empty())
        {
            st.push(ele);
            mn.push(ele);
        }
        else
        {
            st.push(ele);
            mn.push(min(ele, mn.top()));
        }
    }

    int pop()
    {
        if (st.empty())
            return -1;

        int t = st.top();
        st.pop();
        mn.pop();
        return t;
    }

    int minimumELe()
    {
        if (st.empty())
            return -1;

        return mn.top();
    }
};

int main()
{
    solution s;
    s.push(9);
    s.push(0);
    cout << s.minimumELe();
    cout << endl;
    cout << s.pop();
    cout << s.minimumELe();
}