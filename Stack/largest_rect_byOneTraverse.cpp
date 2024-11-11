#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int largestRect(vector<int> &vec)
{

    int n = vec.size();
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && vec[st.top()] > vec[i])
        {
            int top = vec[st.top()];
            st.pop();
            if (st.empty())
            {
                int newans = i * top;
                if (newans > ans)
                    ans = newans;
            }
            else
            {

                int pre = st.top();
                int newans = i - pre - 1;
                newans = newans * top;
                if (newans > ans)
                    ans = newans;
            }
        }
        st.push(i);
    }

    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (st.empty())
        {
            ans = max(ans, vec[top] * (n));
        }
        else
            ans = max(ans, vec[top] * (n - st.top() - 1));
    }

    return ans;
}
int main()
{
    vector<int> vec = {2, 3, 4, 2, 6, 5, 4, 5, 3};
    cout << largestRect(vec);
}