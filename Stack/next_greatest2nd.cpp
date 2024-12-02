#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreatest(vector<int> &vec)
{

    int n = vec.size() - 1;
    vector<int> res(n + 1, -1);
    stack<int> st;
    for (int i = n; i >= 0; i--)
    {
        while (!st.empty() && vec[st.top()] < vec[i])
        {
            //  res[i]= vec[st.top()];
            st.pop();
        }
        if (!st.empty() && vec[st.top()] > vec[i])
        {
            res[i] = vec[st.top()];
        }
        st.push(i);
    }

    return res;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 3, 2, 5, 5};
    vector<int> res = nextGreatest(vec);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << res[i] << " ";
    }
}