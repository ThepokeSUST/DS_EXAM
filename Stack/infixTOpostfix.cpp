#include <iostream>
#include <stack>

using namespace std;

int power(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    //  else if(ch=='*' || '÷')
    if (ch == '*' || ch == '.')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return 0;
}
string post(string str)
{
    stack<char> st;
    string res = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            res += str[i];
        else if (str[i] == '(')
            st.push(str[i]);
        else if (str[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            if (st.empty())
                st.push(str[i]);

            else
            {
                if (power(str[i]) > power(st.top()))
                {
                    st.push(str[i]);
                }
                else
                {
                    res += st.top();
                    st.pop();
                }
            }
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}

int main()
{
    // cout << "Hello World!" << endl;
    string str;
    cin >> str;
    string res = post(str);
    cout << res;
    return 0;
}