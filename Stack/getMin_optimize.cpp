#include <iostream>
#include <stack>

using namespace std;

class solution
{

    stack<int> st;
    int nele = 101;

public:
    void push(int ele)
    {
        if (st.empty())
        {
            st.push(ele * nele + ele);
        }
        else
        {
            int prevmin = st.top() % nele;
            st.push(ele * nele + (min(ele, prevmin)));
        }
    }

    int pop()
    {

        if (st.empty())
            return -1;

        int ele = st.top() / nele;
        st.pop();
        return ele;
    }

    int minimumEle()
    {

        if (st.empty())
            return -1;

        return st.top() % nele;
    }
};

// this code oly work if input range was given......
// suppose range 0 to 100......
int main()
{
    solution s;
    s.push(9);
    s.push(0);
    cout << s.minimumEle();
    cout << endl;
    cout << s.pop();
    cout << endl;
    cout << s.minimumEle();
}