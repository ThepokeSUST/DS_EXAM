#include <iostream>
#include <stack>
using namespace std;

bool check(string str)
{
    stack<char> st;

    for (int i = 0; i < str.size(); i++)
    {

        if (str[i] == '(')
        {
            st.push(str[i]);
        }
        else
        {
            if (st.empty())
                return false;

            st.pop();
        }
    }

    return st.empty();
}

int main()
{

    string str;
    cin >> str;
    cout << check(str);
}